// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectPPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "ProjectPCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Actors/Charactor/TestPawn.h"
#include "../Source/ProjectP/Subsystem/GameInstanceSubsystem/EventGameInstanceSubsystem.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AProjectPPlayerController::AProjectPPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AProjectPPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	UEventGameInstanceSubsystem* EventGameInstanceSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UEventGameInstanceSubsystem>();
	EventGameInstanceSubsystem->BeginAsset();
	EventGameInstanceSubsystem->BeginSource();
	EventGameInstanceSubsystem->BeginWidget();

}

void AProjectPPlayerController::CalculateCursorToWorld()
{
	// 마우스 커서 기준 설정
	float MouseX, MouseY;
	if (GetMousePosition(MouseX, MouseY))
	{
		FVector WorldLocation, WorldDirection;
		if (DeprojectScreenPositionToWorld(MouseX, MouseY, WorldLocation, WorldDirection))
		{
			FVector Start = WorldLocation;
			FVector End = Start + WorldDirection * 10000.f;

			FHitResult HitResult;
			GetWorld()->LineTraceSingleByChannel
			(
				HitResult,
				Start,
				End,
				ECC_Visibility,
				FCollisionQueryParams()
			);

			if (HitResult.bBlockingHit)
			{	
				UE_LOG(LogTemp, Warning, TEXT("%s"), *HitResult.Location.ToString());
				FRotator Rotator = FRotator::ZeroRotator;
				FActorSpawnParameters SpawnParams;
				ATestPawn* Actor = GetWorld()->SpawnActor<ATestPawn>(ATestPawn::StaticClass(), HitResult.Location, Rotator, SpawnParams);
				if (Actor)
				{
					Actor->StaticMeshComponent->GetStaticMesh();
					//Actor->StaticMeshComponent->SetStaticMesh(ATset->GetStaticMesh());
				}
			}
		}
	}
}

void AProjectPPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &AProjectPPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AProjectPPlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &AProjectPPlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &AProjectPPlayerController::OnSetDestinationReleased);

		// Setup touch input events
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this, &AProjectPPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this, &AProjectPPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this, &AProjectPPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this, &AProjectPPlayerController::OnTouchReleased);

		EnhancedInputComponent->BindAction(SetTestKey, ETriggerEvent::Started, this, &AProjectPPlayerController::TestSpawn);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AProjectPPlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void AProjectPPlayerController::OnSetDestinationTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}


}

void AProjectPPlayerController::OnSetDestinationReleased()
{
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void AProjectPPlayerController::OnTouchTriggered()
{
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void AProjectPPlayerController::OnTouchReleased()
{
	bIsTouch = false;
	OnSetDestinationReleased();
}

void AProjectPPlayerController::TestSpawn()
{
	CalculateCursorToWorld();

}
