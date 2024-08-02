// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interface/ObserverInterface.h"
#include "ObserverImplement.generated.h"

class UUserWidget;

UCLASS()
class PROJECTP_API AObserverImplement : public AActor, public IObserverInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	static AObserverImplement* GetInstance()
	{
		if (Instance ==nullptr)
		{
			Instance = NewObject<AObserverImplement>();
		}
		return Instance;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	AObserverImplement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Updata();
	virtual void AddSubscribe(AObserverImplement* InSubscribe);
	virtual void DeleteSubscribe(AObserverImplement* InSubscribe);

	virtual void Updata_Widget(UUserWidget* InSubscribe);
	virtual void AddSubscribe_Widget(UUserWidget* InSubscribe);
	virtual void DeleteSubscribe_Widget(UUserWidget* InSubscribe);

private:
	TArray<AObserverImplement*> SubscribeArray;
	TArray<UUserWidget*> SubscribeArray_Widget;

	static AObserverImplement* Instance;
};

AObserverImplement* AObserverImplement::Instance = nullptr;