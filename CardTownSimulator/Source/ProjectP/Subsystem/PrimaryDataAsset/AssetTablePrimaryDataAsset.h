// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Datatable.h"
#include "AssetTablePrimaryDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTP_API UAssetTablePrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("AssetTablePrimaryDataAsset", GetFName());
	}
	
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* AssetDatatable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* SourceDatatable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* WidgetDatatable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* BuildingDatatable;

};
