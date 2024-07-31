// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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
	int32 PublicSource1;

	// ���� �ڿ� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrivateSource")
	int32 PrivateSource1;
};
