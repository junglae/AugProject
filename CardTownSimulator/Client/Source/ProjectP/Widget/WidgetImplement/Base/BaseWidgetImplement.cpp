// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWidgetImplement.h"
#include "../../../Actors/Handling/AssetTablePrimaryDataAssetHandle/AssetPrimaryHandler.h"
#include "../../../Observer/Implement/ObserverImplement.h"

void UBaseWidgetImplement::Activation()
{
	ObserverImplement->Updata_Widget(this);
}

void UBaseWidgetImplement::NativeConstruct()
{
	Super::NativeConstruct();
	InitWidget();

}


void UBaseWidgetImplement::InitWidget()
{

	ObserverImplement = AObserverImplement::GetInstance();
	ObserverImplement->AddSubscribe_Widget(this);

}
