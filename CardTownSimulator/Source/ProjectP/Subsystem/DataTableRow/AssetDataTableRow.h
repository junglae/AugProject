// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetDataTableRow.generated.h"

UENUM(BlueprintType)
enum class ECardCategory : uint8
{
	Job UMETA(DisplayName = "Job"),
	Common UMETA(DisplayName = "Common"),
	Special UMETA(DisplayName = "Special"),
};

UENUM(BlueprintType)
enum class EJob : uint8
{
	None UMETA(DisplayName = "None"),
	Peasant UMETA(DisplayName = "Peasant"),
	Cleric UMETA(DisplayName = "Cleric"),
	Merchant UMETA(DisplayName = "Merchant"),
	Gambler UMETA(DisplayName = "Gambler"),
};

UENUM(BlueprintType)
enum class EResource : uint8
{
	Food UMETA(DisplayName = "Food"),
	Material UMETA(DisplayName = "Material"),
	Money UMETA(DisplayName = "Money"),
};

USTRUCT(BlueprintType, Atomic)
struct PROJECTP_API FAssetDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	// @TODO 에셋으로 포함될 내용 추가
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "CardInfo")
	TSubclassOf<AActor> Class;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	FText MainDescription;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	//UTexture2D* Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	int32 Cost = NULL;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	//ECardCategory CardCategory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	int32 Rarity = NULL;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	//EJob  JobExclusive;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	//TMap<EResource, int32> Resources;


	// 여기서 부터는 클라에만 적용
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardInfo")
	FDataTableRowHandle ClientDatal;

};
