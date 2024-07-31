// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetDataTableRow.generated.h"



USTRUCT(BlueprintType, Atomic)
struct PROJECTP_API FAssetDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	// @TODO �������� ���Ե� ���� �߰�
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "AssetStaticMesh")
	UStaticMesh* StaticMeshData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorCategory")
	TSubclassOf<AActor> TestActor;

};
