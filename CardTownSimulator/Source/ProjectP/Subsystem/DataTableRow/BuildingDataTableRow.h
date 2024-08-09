// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuildingDataTableRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType, Atomic)
struct PROJECTP_API FBuildingDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BuildingData")
	FText tName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BuildingData")
	TSubclassOf<AActor> aBuildingType;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BuildingData")
	//FVector vLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BuildingData")
	bool bCreate = false;
	// @TODO 건물의 기능
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BuildingData")
	//bool BuildingFunction;

};
