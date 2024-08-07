// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AssetPrimaryHandler.generated.h"

UCLASS()
class PROJECTP_API AAssetPrimaryHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	static AAssetPrimaryHandler* GetInstance()
	{

		if (!Instance)
		{
			Instance = NewObject<AAssetPrimaryHandler>();
			Instance->AddToRoot();
		}
		return Instance;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PostInitializeComponents() override;
	AAssetPrimaryHandler() {};
	virtual void BeginDestroy()override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	int32 GetPublicSource();
	void SetPublicSource(int32 InPublicSource);

	UStaticMesh* GetStaticMesh();
	void SetStaticMesh(UStaticMesh* InAssetMesh);

	class UAssetTablePrimaryDataAsset* GetTablePrimaryData();


public:
	void BeginAsset();
	void BeginSource();
	void BeginWidget();

private:
	// 팀이 같이 보게 될 자원
	int32 PublicSource1 = 0;

	// 개인이 혼자 사용할 자원
	int32 PrivateSource1 = 0;

	UStaticMesh* AssetMesh;

	static AAssetPrimaryHandler* Instance;
	UAssetTablePrimaryDataAsset* ItemPrimaryData;

	TArray<FName> AssetRowNames;
	TArray<FName> SourceNames;
	TArray<FName> WidgetNames;
};

AAssetPrimaryHandler* AAssetPrimaryHandler::Instance = nullptr;