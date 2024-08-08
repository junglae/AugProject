// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWidgetImplement.h"
#include "Engine/DataTable.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "../../../Subsystem/DataTableRow/BaseStructDataTable.h"
#include "../../../Observer/Implement/ObserverImplement.h"
#include "../../../Subsystem/GameInstanceSubsystem/EventGameInstanceSubsystem.h"
#include "../../../Actors/PointPosition/PointPositionActor.h"

void UBaseWidgetImplement::Activation(FBaseStruct InStruct)
{

	CreateSource();
}

void UBaseWidgetImplement::SpawnActor()
{
	CreateSource();
}

void UBaseWidgetImplement::NativeConstruct()
{
	Super::NativeConstruct();
	EventGameInstanceSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UEventGameInstanceSubsystem>();
	UWorld* World = GetWorld();
	UGameplayStatics::GetAllActorsOfClass(World, APointPositionActor::StaticClass(), FoundActor);

	InitWidget();
}


void UBaseWidgetImplement::InitWidget()
{

	ObserverImplement = AObserverImplement::GetInstance();
	ObserverImplement->AddSubscribe_Widget(this);

}

void UBaseWidgetImplement::CreateSource_CardInfo(FAssetDataTableRow InAssetDataTableRow)
{

	
}

void UBaseWidgetImplement::DestroySource_CardInfo(FAssetDataTableRow InAssetDataTableRow)
{
}

void UBaseWidgetImplement::AddSoutce_CardInfo(FAssetDataTableRow InAssetDataTableRow)
{
}

void UBaseWidgetImplement::MinSource_CardInfo(FAssetDataTableRow InAssetDataTableRow)
{
}

void UBaseWidgetImplement::CreateSource()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}
	if (FoundActor.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorArray"));
		return;
	}
	FSourceDataTableRow* SourceDataTableRow = EventGameInstanceSubsystem->GetSourceDataTable();
	if (!SourceDataTableRow)
	{
		return;
	}
	TSubclassOf<AActor> ActortoSpawn = SourceDataTableRow->ActorToSpawn;
	if (!ActortoSpawn)
	{
		return;
	}

	int32 RandomInt = FMath::RandRange(0, FoundActor.Num()-1);
	if (RandomInt <= -1)
	{
		return;
	}
	// 함수 불러오기 테스트
	/*APlayerController* PlayerContoller = GetWorld()->GetFirstPlayerController();
	FName FunctionName = FName("Display Cards");
	UFunction* Function = PlayerContoller->FindFunction(FunctionName);
	if (Function)
	{
		PlayerContoller->ProcessEvent(Function, 0);
	}*/

	FVector Location = FoundActor[RandomInt]->GetActorLocation();
	FRotator Rotation = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	World->SpawnActor<AActor>(ActortoSpawn, Location, Rotation, SpawnParameters);
	FoundActor.RemoveAt(RandomInt); 

}

void UBaseWidgetImplement::DestorySource(FBuildingDataTableRow* InSource)
{
	// @TODO 선택 또는 특정 타입의 건물이 맞는지 확인하여 그 정보를 초기화
}

UBaseWidgetImplement* UBaseWidgetImplement::GetBaseWidgetImplement()
{
	return BaseWidgetImplement;
}

void UBaseWidgetImplement::EventProduction(AActor* InActor)
{

}
