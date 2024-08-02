// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWidgetImplement.h"
#include "../../../Actors/Handling/AssetTablePrimaryDataAssetHandle/AssetPrimaryHandler.h"

void UBaseWidgetImplement::Acdtivation()
{
}

void UBaseWidgetImplement::NativeConstruct()
{
	Super::NativeConstruct();
	InitWidget();

}

void UBaseWidgetImplement::InitWidget()
{
	AAssetPrimaryHandler* AssetPrimaryHandler = AAssetPrimaryHandler::GetInstance();
	AssetPrimaryHandler->BeginWidget();

}
