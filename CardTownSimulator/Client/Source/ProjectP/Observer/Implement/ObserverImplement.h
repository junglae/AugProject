// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/ObserverInterface.h"
#include "ObserverImplement.generated.h"

UCLASS()
class PROJECTP_API AObserverImplement : public AActor, public IObserverInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObserverImplement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Updata();
	virtual void AddSubscribe(AObserverImplement* InSubscribe);
	virtual void DeleteSubscribe(AObserverImplement* InSubscribe);


private:
	TArray<AObserverImplement*> SubscribeArray;

};
