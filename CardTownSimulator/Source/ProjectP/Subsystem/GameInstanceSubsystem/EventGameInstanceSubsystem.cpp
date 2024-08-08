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
	//�ϵ� �ڵ��� �κ� ���� �ִ��� Ȯ���ϱ�
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
	// �ּ� �ʱ�ȭ
	AssetTable = ItemPrimaryData->AssetDatatable->FindRow<FAssetDataTableRow>(AssetRowNames[0], TEXT(""));
	check(AssetTable);
}

void UEventGameInstanceSubsystem::BeginSource()
{
	// �ڿ� �ʱ�ȭ
	SourceTable = ItemPrimaryData->SourceDatatable->FindRow<FSourceDataTableRow>(SourceNames[0], TEXT(""));
	check(AssetTable);
}

void UEventGameInstanceSubsystem::BeginWidget()
{
	// ���� �ʱ�ȭ
	for (size_t i = 0; i < WidgetNames.Num(); i++)
	{
		WidgettTable = ItemPrimaryData->WidgetDatatable->FindRow<FWidgetDataTableRow>(WidgetNames[i], TEXT(""));
		check(WidgettTable);
		if (!WidgettTable)
		{
			continue;
		}

		// ������ ���� ���� ������ ��
		// ���������� ��� �����ϰ� ���� �Ѱ��ָ� ��
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
	// �ǹ� �ʱ�ȭ
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
	//		// T@TODO ���� ����
	//		DataRow->Cost += 1;
	//	}
	//}

}




