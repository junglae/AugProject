// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TotalDataTableRow.h"
#include "BaseStructDataTable.generated.h"


USTRUCT(BlueprintType, Atomic)
struct FBaseStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FAssetDataTableRow AssetDataTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSourceDataTableRow SourceDataTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FWidgetDataTableRow WidgetDataTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBuildingDataTableRow BuildingDataTableRow;

};