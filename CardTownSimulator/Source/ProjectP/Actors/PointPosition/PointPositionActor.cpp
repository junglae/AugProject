// Fill out your copyright notice in the Description page of Project Settings.


#include "PointPositionActor.h"
#include "Kismet//GameplayStatics.h"

// Sets default values
APointPositionActor::APointPositionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

// Called when the game starts or when spawned
void APointPositionActor::BeginPlay()
{
	Super::BeginPlay();
	//FindActorsPosition();

}

// Called every frame
void APointPositionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APointPositionActor::FindActorsPosition()
{

}

TArray<AActor*> APointPositionActor::GetActorPositionArray()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APointPositionActor::StaticClass(), ActorPositionArray);

	return ActorPositionArray;
}

