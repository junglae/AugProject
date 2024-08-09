// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointPositionActor.generated.h"

UCLASS()
class PROJECTP_API APointPositionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointPositionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VALUE")
	class USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VALUE")
	class UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(EditAnywhere);
	FName	 ActorType;

	void SpawnPositionActor();

public:
	void FindActorsPosition();
	TArray<AActor*> GetActorPositionArray();
private:

	TArray<AActor*> ActorPositionArray;
	
};
