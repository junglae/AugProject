// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NiagaraComponent.h"
#include "SourceDataTableRow.generated.h"

/**
 * 
 */
USTRUCT()
struct PROJECTP_API FSourceDataTableRow : public FTableRowBase
{
	GENERATED_BODY()
	
	// @TODO �ڿ� ���� ���� �߰�
public:
	// ���� �ڿ� ���� 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PublicSource")
	int32 PublicSource1 = NULL;

	// ���� �ڿ� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrivateSource")
	int32 PrivateSource1 = NULL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrivateSource")
	int32 PrivateSource2 = NULL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	FName ActorType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	TSubclassOf<AActor> ActorToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	TSubclassOf<AActor> ActorToDestory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	UNiagaraSystem* NiagaraSystem = nullptr;

};
