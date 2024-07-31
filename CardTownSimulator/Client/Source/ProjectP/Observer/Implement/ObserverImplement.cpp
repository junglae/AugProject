// Fill out your copyright notice in the Description page of Project Settings.


#include "ObserverImplement.h"
#include "../SubscribeList/SubscribeList.h"

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
		// @TODO ������ ��ü ������Ʈ ���� �ۼ�
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
	if (Index == NULL)
	{
		SubscribeArray.RemoveAt(Index);
	}
}



