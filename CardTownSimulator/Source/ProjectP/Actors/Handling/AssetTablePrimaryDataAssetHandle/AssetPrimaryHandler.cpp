// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetPrimaryHandler.h"
#include "Engine/AssetManager.h"
#include "Blueprint/UserWidget.h"

#include "../../../Subsystem/DataTableRow/TotalDataTableRow.h"
#include "../../../Subsystem/PrimaryDataAsset/AssetTablePrimaryDataAsset.h"
#include "../../Charactor/TestPawn.h"


// Called when the game starts or when spawned
void AAssetPrimaryHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAssetPrimaryHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AAssetPrimaryHandler::GetPublicSource()
{
	return PublicSource1;
}

void AAssetPrimaryHandler::SetPublicSource(int32 InPublicSource)
{
	PublicSource1 = InPublicSource;
}

UStaticMesh* AAssetPrimaryHandler::GetStaticMesh()
{
	return AssetMesh;
}

void AAssetPrimaryHandler::SetStaticMesh(UStaticMesh* InAssetMesh)
{
	AssetMesh = InAssetMesh;
}

UAssetTablePrimaryDataAsset* AAssetPrimaryHandler::GetTablePrimaryData()
{
	return ItemPrimaryData;
}

void AAssetPrimaryHandler::BeginAsset()
{
	// 에셋관련
	FAssetDataTableRow* AssetTable = ItemPrimaryData->AssetDatatable->FindRow<FAssetDataTableRow>(AssetRowNames[0], TEXT(""));

}

void AAssetPrimaryHandler::BeginSource()
{
	// 자원 관련
	FSourceDataTableRow* SourceTable = ItemPrimaryData->SourceDatatable->FindRow<FSourceDataTableRow>(SourceNames[0], TEXT(""));


}

void AAssetPrimaryHandler::BeginWidget()
{
	// 위젯 관련
	for (size_t i = 0; i < WidgetNames.Num(); i++)
	{
		FWidgetDataTableRow* WidgettTable = ItemPrimaryData->WidgetDatatable->FindRow<FWidgetDataTableRow>(WidgetNames[i], TEXT(""));
		if (!WidgettTable)
		{
			return;
		}

		
		UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetWorld(), WidgettTable->UserWidgetData.UserWidgetData);
		if (!UserWidget)
		{
			return;
		}
		UserWidget->AddToViewport();
	}

}

void AAssetPrimaryHandler::PostInitializeComponents()
{
	//해당 참조 포인터를 묶어서 다른 곳에서 get을 통해 지속적으로 로딩할 수 있게
	// 해당 부분의 실행 및 동작은 변경할 수 있음
	// @TODO Test 코드 삭제 후 서비스 로직 작성
	PrimaryActorTick.bCanEverTick = true;

	Super::PostInitializeComponents();

	GetInstance();

	UAssetManager& Manager = UAssetManager::Get();

	TArray<FPrimaryAssetId> Assets;
	//하드 코딩된 부분 뺄수 있는지 확인하기
	Manager.GetPrimaryAssetIdList(TEXT("AssetTablePrimaryDataAsset"), Assets); 

	int32 AccessIdx = 0;
	FSoftObjectPtr AssetPtr(Manager.GetPrimaryAssetPath(Assets[AccessIdx]));
	if (AssetPtr.IsPending())
	{
		AssetPtr.LoadSynchronous();
	}
	ItemPrimaryData = Cast<UAssetTablePrimaryDataAsset>(AssetPtr.Get());


	if (ItemPrimaryData)
	{
		AssetRowNames = ItemPrimaryData->AssetDatatable->GetRowNames();
		SourceNames = ItemPrimaryData->SourceDatatable->GetRowNames();
		WidgetNames = ItemPrimaryData->WidgetDatatable->GetRowNames();
	}

	BeginAsset();
	BeginSource();
	BeginWidget();

}

void AAssetPrimaryHandler::BeginDestroy()
{
	Super::BeginDestroy();
	Instance = nullptr;
}
