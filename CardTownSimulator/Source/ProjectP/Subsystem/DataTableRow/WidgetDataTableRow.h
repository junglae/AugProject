// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetDataTableRow.generated.h"

USTRUCT(BlueprintType)
struct PROJECTP_API FUserWidgetData
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetClass")
	TSubclassOf<UUserWidget> UserWidgetData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetClass")
	bool bVisable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WidgetClass")
	FString WidgetName;
};

USTRUCT(BlueprintType, Atomic)
struct PROJECTP_API FWidgetDataTableRow : public FTableRowBase
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AssetWidget")
	FUserWidgetData UserWidgetData;
};
