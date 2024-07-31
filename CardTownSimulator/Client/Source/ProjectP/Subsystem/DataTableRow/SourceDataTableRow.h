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
	
	// @TODO 자원 관련 내용 추가
public:
	// 공유 자원 관련 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PublicSource")
	int32 PublicSource1;

	// 개인 자원 관련
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PrivateSource")
	int32 PrivateSource1;
};
