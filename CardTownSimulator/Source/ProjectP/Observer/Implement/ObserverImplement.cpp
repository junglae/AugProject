// Fill out your copyright notice in the Description page of Project Settings.


#include "ObserverImplement.h"
#include "../SubscribeList/SubscribeList.h"
#include "../../Widget/WidgetImplement/Base/BaseWidgetImplement.h"

// Sets default values
AObserverImplement::AObserverImplement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObserverImplement::BeginPlay()
{
	Super::BeginPlay();
	GetInstance();
	
}

void AObserverImplement::BeginDestroy()
{
	Super::BeginDestroy();
	if (Instance != nullptr)
	{
		Instance = nullptr;
	}
}

// Called every frame
void AObserverImplement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObserverImplement::Updata()
{
	for (AObserverImplement* InActor : SubscribeArray)
	{
		// @TODO 구독자 전체 업데이트 내용 작성
		InActor->Updata();
	}
}

void AObserverImplement::AddSubscribe(AObserverImplement* InSubscribe)
{
	SubscribeArray.Add(InSubscribe);
}

void AObserverImplement::DeleteSubscribe(AObserverImplement* InSubscribe)
{
	int32 Index = SubscribeArray.IndexOfByKey(InSubscribe);
	if (Index != NULL)
	{
		SubscribeArray.RemoveAt(Index);
	}
}

void AObserverImplement::Updata_Widget(UUserWidget* InSubscribe)
{
	UBaseWidgetImplement* BaseWidget = Cast<UBaseWidgetImplement>(InSubscribe);

	BaseWidget->Passive();

}

void AObserverImplement::AddSubscribe_Widget(UUserWidget* InSubscribe)
{
	SubscribeArray_Widget.Add(InSubscribe);
}

void AObserverImplement::DeleteSubscribe_Widget(UUserWidget* InSubscribe)
{
	if (!SubscribeArray_Widget.Contains(InSubscribe))
	{
		return;
	}
	int32 Index = SubscribeArray_Widget.IndexOfByKey(InSubscribe);
	SubscribeArray_Widget.RemoveAt(Index);
}



