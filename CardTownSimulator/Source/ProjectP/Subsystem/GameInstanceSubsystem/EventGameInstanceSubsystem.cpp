// Fill out your copyright notice in the Description page of Project Settings.


#include "EventGameInstanceSubsystem.h"
#include "Engine/AssetManager.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"

#include "../../Actors/PointPosition/PointPositionActor.h"
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
	//UAssetManager& Manager = UAssetManager::Get();

	//TArray<FPrimaryAssetId> Assets;
	////하드 코딩된 부분 뺄수 있는지 확인하기
	//Manager.GetPrimaryAssetIdList(TEXT("AssetTablePrimaryDataAsset"), Assets);

	//int32 AccessIdx = 0;
	//FSoftObjectPtr AssetPtr(Manager.GetPrimaryAssetPath(Assets[AccessIdx]));
	//if (AssetPtr.IsPending())
	//{
	//	AssetPtr.LoadSynchronous();
	//}
	//ItemPrimaryData = Cast<UAssetTablePrimaryDataAsset>(AssetPtr.Get());


	//if (ItemPrimaryData)
	//{
	//	AssetRowNames = ItemPrimaryData->AssetDatatable->GetRowNames();
	//	SourceNames = ItemPrimaryData->SourceDatatable->GetRowNames();
	//	WidgetNames = ItemPrimaryData->WidgetDatatable->GetRowNames();
	//	BuildingNames = ItemPrimaryData->BuildingDatatable->GetRowNames();
	//}

	/*BeginAsset();
	BeginSource();
	BeginWidget();
	BeginBulidingData();*/

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

FSourceDataTableRow* UEventGameInstanceSubsystem::SearchSourceDataTable(FName InName)
{
	SourceTable = ItemPrimaryData->SourceDatatable->FindRow<FSourceDataTableRow>(InName, TEXT(""));
	return SourceTable;
}

void UEventGameInstanceSubsystem::Active_Implementation()
{
	CreateSource();

}

void UEventGameInstanceSubsystem::CreateSource()
{

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}
	GetPositionActorArray(World);

	if (FoundActor.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorArray"));
		return;
	}
	FSourceDataTableRow* SourceDataTableRow = GetSourceDataTable();
	if (!SourceDataTableRow)
	{
		return;
	}
	TSubclassOf<AActor> ActortoSpawn = SourceDataTableRow->ActorToSpawn;
	if (!ActortoSpawn)
	{
		return;
	}

	int32 RandomInt = FMath::RandRange(0, FoundActor.Num() - 1);
	if (RandomInt <= -1)
	{
		return;
	}
	// 함수 불러오기 테스트


	FVector Location = FoundActor[RandomInt]->GetActorLocation();
	FRotator Rotation = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AActor* Actor = World->SpawnActor<AActor>(ActortoSpawn, Location, Rotation, SpawnParameters);
	MoveActor(Actor);
	FoundActor.RemoveAt(RandomInt);
}

void UEventGameInstanceSubsystem::CreateSource(FSourceDataTableRow* SourceDataTableRow, APointPositionActor* InActor)
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}
	GetPositionActorArray(World);

	if (FoundActor.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorArray"));
		return;
	}
	if (!SourceDataTableRow)
	{
		return;
	}
	TSubclassOf<AActor> ActortoSpawn = SourceDataTableRow->ActorToSpawn;
	if (!ActortoSpawn)
	{
		return;
	}

	/*int32 RandomInt = FMath::RandRange(0, FoundActor.Num() - 1);
	if (RandomInt <= -1)
	{
		return;
	}*/
	

	FVector Location = InActor->GetActorLocation(); //FoundActor[RandomInt]->GetActorLocation();
	FRotator Rotation = FRotator::ZeroRotator;
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AActor* Actor = World->SpawnActor<AActor>(ActortoSpawn, Location, Rotation, SpawnParameters);
	BuildingActor.Add(Actor);
}

void UEventGameInstanceSubsystem::FindFunction()
{
	APlayerController* PlayerContoller = GetWorld()->GetFirstPlayerController();
	FName FunctionName = FName("Send Card Usage");
	UFunction* Function = PlayerContoller->FindFunction(FunctionName);
	if (Function)
	{
		PlayerContoller->ProcessEvent(Function, 0);
	}
}

void UEventGameInstanceSubsystem::ActorPositionSpawn(APointPositionActor* InActor)
{
	FSourceDataTableRow* SourceDataTableRow = SearchSourceDataTable(InActor->ActorType);
	CreateSource(SourceDataTableRow, InActor);
}

void UEventGameInstanceSubsystem::MoveActor(AActor* InActor)
{
	if (!InActorArray.Contains(InActor))
	{
		InActorArray.Add(InActor);
	}
	FVector OutGroundLocation;
	FVector StartLocation = InActor->GetActorLocation();
	GetGroundLoactionReverser(StartLocation, OutGroundLocation, InActor);
	UpMoveActor(StartLocation, OutGroundLocation, InActor);
}

bool UEventGameInstanceSubsystem::GetGroundLoactionReverser(FVector StartLocation, FVector& OutGroundLoaction, AActor* InActor)
{

	FHitResult HitResult;
	FVector EndLocation = StartLocation;
	EndLocation.Z += 10000.f;
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(InActor);
	
	bool bHit = InActor->GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		StartLocation, 
		EndLocation, 
		ECC_WorldStatic, 
		CollisionQueryParams);
	
	if (bHit)
	{
		OutGroundLoaction = HitResult.Location;
	}
	
	return bHit;
}

void UEventGameInstanceSubsystem::UpMoveActor(FVector StartLocation, FVector& OutGroundLoaction, AActor* InActor)
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	FVector CurrentLocation = InActor->GetActorLocation();
	float GoalSpeed = 5.f;

	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	UWorld* World = GetWorld();
	if (!TimerManager.IsTimerActive(TimerHandle))
	{
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUFunction(this, FName("UpMoveActor"), StartLocation, OutGroundLoaction, InActor);
		TimerManager.SetTimer(TimerHandle, TimerDelegate, .01f, true);
		MoveSpeed = (FMath::Abs(OutGroundLoaction.Z - CurrentLocation.Z) / GoalSpeed);
	}
	CurrentLocation.Z += MoveSpeed * DeltaTime;
	
	InActor->SetActorLocation(CurrentLocation);

	if (CurrentLocation.Z >= OutGroundLoaction.Z+ 1)
	{
		FVector OffsetLoaction = (CurrentLocation - (CurrentLocation - OutGroundLoaction)) + 5;
		InActor->SetActorLocation(OffsetLoaction);
		TimerManager.ClearTimer(TimerHandle);

		int32 ActorIndex = InActorArray.IndexOfByKey(InActor);
		InActorArray.RemoveAt(ActorIndex);

		if (!InActorArray.IsEmpty())
		{
			MoveActor(InActorArray[0]);
		}
	}
}

TArray<AActor*> UEventGameInstanceSubsystem::GetPositionActorArray(UWorld* World)
{
	if (FoundActor.IsEmpty())
	{
		UGameplayStatics::GetAllActorsOfClass(World, APointPositionActor::StaticClass(), FoundActor);

	}
	return FoundActor;
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
	//if (InClientData->bAcquisitionSource)
	//{
	//	ChangeAcquisitionSource(InClientData);
	//}
	//else
	//	return;
}

void UEventGameInstanceSubsystem::ChangeAcquisitionSource(FClientAssetDataTableRow* InClientData)
{
	//if (InClientData->AcquisitionSourceInt < 0)
	//{

	//}
	//else if (InClientData->AcquisitionSourceMax < 0)
	//{

	//}
	//else if (InClientData->AcquisitionSourcePer < 0)
	//{

	//}
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




