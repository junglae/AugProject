// Fill out your copyright notice in the Description page of Project Settings.


#include "EventGameInstanceSubsystem.h"
#include "Engine/AssetManager.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h"

#include "../../Subsystem/DataTableRow/BaseStructDataTable.h"
#include "../PrimaryDataAsset/AssetTablePrimaryDataAsset.h"
#include "../../Widget/WidgetImplement/Base/BaseWidgetImplement.h"

void UEventGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	InitializeAssetManager();

	AssetTable = GetAssetDataTable();
	SourceTable = GetSourceDataTable();
	WidgettTable = GetWidgetDataTable();
}

void UEventGameInstanceSubsystem::InitializeAssetManager()
{
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
		BuildingNames = ItemPrimaryData->BuildingDatatable->GetRowNames();
	}

	BeginAsset();
	BeginSource();
	BeginWidget();
	BeginBulidingData();

}

int32 UEventGameInstanceSubsystem::GetPublicSource()
{
	return PublicSource1;
}

void UEventGameInstanceSubsystem::SetPublicSource(int32 InPublicSource)
{
	PublicSource1 = InPublicSource;
}

UStaticMesh* UEventGameInstanceSubsystem::GetStaticMesh()
{
	return AssetMesh;
}

void UEventGameInstanceSubsystem::SetStaticMesh(UStaticMesh* InAssetMesh)
{
	AssetMesh = InAssetMesh;
}

UAssetTablePrimaryDataAsset* UEventGameInstanceSubsystem::GetTablePrimaryData()
{
	return ItemPrimaryData;
}

FAssetDataTableRow* UEventGameInstanceSubsystem::GetAssetDataTable()
{
	return AssetTable;
}

FSourceDataTableRow* UEventGameInstanceSubsystem::GetSourceDataTable()
{
	return SourceTable;
}

FWidgetDataTableRow* UEventGameInstanceSubsystem::GetWidgetDataTable()
{
	return WidgettTable;
}

void UEventGameInstanceSubsystem::FindWidget(FString InName)
{
	/*FString LeftString;
	FString RightString;

	InName.Split(TEXT("_"), &LeftString, &RightString);
	FName Name = FName(LeftString);
	FWidgetDataTableRow* WidgetTable = Instance->ItemPrimaryData->WidgetDatatable->FindRow<FWidgetDataTableRow>(Name, TEXT(""));*/

}

void UEventGameInstanceSubsystem::BeginAsset()
{
	// 애셋 초기화
	AssetTable = ItemPrimaryData->AssetDatatable->FindRow<FAssetDataTableRow>(AssetRowNames[0], TEXT(""));
	check(AssetTable);
}

void UEventGameInstanceSubsystem::BeginSource()
{
	// 자원 초기화
	SourceTable = ItemPrimaryData->SourceDatatable->FindRow<FSourceDataTableRow>(SourceNames[0], TEXT(""));
	check(AssetTable);
}

void UEventGameInstanceSubsystem::BeginWidget()
{
	// 위젯 초기화
	for (size_t i = 0; i < WidgetNames.Num(); i++)
	{
		WidgettTable = ItemPrimaryData->WidgetDatatable->FindRow<FWidgetDataTableRow>(WidgetNames[i], TEXT(""));
		check(WidgettTable);
		if (!WidgettTable)
		{
			continue;
		}

		// 위젯에 대한 값을 받으면 끝
		// 옵저버에서 계속 갱신하고 값을 넘겨주면 됨
		UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetWorld(), WidgettTable->UserWidgetData.UserWidgetData);
		if (!UserWidget)
		{
			continue;
		}
		UserWidget->AddToViewport();
	}
}

void UEventGameInstanceSubsystem::BeginBulidingData()
{
	// 건물 초기화
	for (size_t i = 0; i < BuildingNames.Num(); i++)
	{
		BuildingTable = ItemPrimaryData->BuildingDatatable->FindRow<FBuildingDataTableRow>(BuildingNames[i], TEXT(""));
		check(BuildingTable);
		if (!BuildingTable)
		{
			continue;
		}
	}
}

void UEventGameInstanceSubsystem::StartSeq(FBaseStruct InMainTable)
{
	FClientAssetDataTableRow* ClientAssetDataTableRow = CheckState(InMainTable);
	bCheckStateAcquisitionSource(ClientAssetDataTableRow);
}

FClientAssetDataTableRow* UEventGameInstanceSubsystem::CheckState(FBaseStruct InMainTable)
{
	const FName RowName = InMainTable.AssetDataTableRow.ClientDatal.RowName;
	FClientAssetDataTableRow* ClientAssetDataTableRow = InMainTable.AssetDataTableRow.ClientDatal.DataTable->FindRow<FClientAssetDataTableRow>(RowName, TEXT("CheckState Fail"));
	return ClientAssetDataTableRow;
}

void UEventGameInstanceSubsystem::bCheckStateAcquisitionSource(FClientAssetDataTableRow* InClientData)
{
	if (InClientData->bAcquisitionSource)
	{
		ChangeAcquisitionSource(InClientData);
	}
	else
		return;
}

void UEventGameInstanceSubsystem::ChangeAcquisitionSource(FClientAssetDataTableRow* InClientData)
{
	if (InClientData->AcquisitionSourceInt < 0)
	{

	}
	else if (InClientData->AcquisitionSourceMax < 0)
	{

	}
	else if (InClientData->AcquisitionSourcePer < 0)
	{

	}
}



void UEventGameInstanceSubsystem::LoadDataTable(FBaseStruct InTableStruct)
{
	
	//static const FString ContextString(TEXT("GENERAL"));
	//TArray<FName> RowNames = InTableStruct->GetRowNames();

	//for (const FName& RowName : RowNames)
	//{
	//	
	//	FAssetDataTableRow* DataRow = InTableStruct-> FindRow<FAssetDataTableRow>(RowName, ContextString);
	//	if (DataRow)

	//	{
	//		// T@TODO 내부 내용
	//		DataRow->Cost += 1;
	//	}
	//}

}




