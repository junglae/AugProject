// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "EventGameInstanceSubsystem.generated.h"

class UDataTable;
class UAssetTablePrimaryDataAsset;

struct FAssetDataTableRow;
struct FSourceDataTableRow;
struct FWidgetDataTableRow;
struct FBuildingDataTableRow;
struct FClientAssetDataTableRow;
struct FBaseStruct;


UCLASS()
class PROJECTP_API UEventGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "CallDataTable")
	void LoadDataTable(struct FBaseStruct InTableStruct);
	void Initialize(FSubsystemCollectionBase& Collection)override;
	void InitializeAssetManager();

public:
	int32 GetPublicSource();
	void SetPublicSource(int32 InPublicSource);

	UStaticMesh* GetStaticMesh();
	void SetStaticMesh(UStaticMesh* InAssetMesh);

	UAssetTablePrimaryDataAsset* GetTablePrimaryData();

	FAssetDataTableRow* GetAssetDataTable();

	FSourceDataTableRow* GetSourceDataTable();

	FWidgetDataTableRow* GetWidgetDataTable();

	void FindWidget(FString InName);

	

public:
	UFUNCTION(BlueprintCallable)
	void BeginAsset();
	UFUNCTION(BlueprintCallable)
	void BeginSource();
	UFUNCTION(BlueprintCallable)
	void BeginWidget();
	UFUNCTION(BlueprintCallable)
	void BeginBulidingData();

	FSourceDataTableRow* SearchSourceDataTable(FName InName);

	/////////////////
	UFUNCTION(BlueprintCallable, Client, Reliable)
	void Active();
	void Active_Implementation();

	UFUNCTION(BlueprintCallable)
	void CreateSource();
	void CreateSource(FSourceDataTableRow* SourceDataTableRow, class APointPositionActor* InActor);
	UFUNCTION(BlueprintCallable)
	void FindFunction();


	UFUNCTION()
	void ActorPositionSpawn(class APointPositionActor* InActor);
	UFUNCTION(BlueprintCallable)
	void MoveActor(AActor* InActor);


	bool GetGroundLoactionReverser(FVector StartLocation, FVector& OutGroundLoaction, AActor* InActor);
	UFUNCTION()
	void UpMoveActor(FVector StartLocation, FVector& OutGroundLoaction, AActor* InActor);
	TArray<AActor*> GetPositionActorArray(UWorld* World);


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJoined;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHosting;


public:
	// �з� ������
	void StartSeq(FBaseStruct InMainTable);
	FClientAssetDataTableRow* CheckState(FBaseStruct InMainTable);
	void bCheckStateAcquisitionSource(FClientAssetDataTableRow* InClientData);
	void ChangeAcquisitionSource(FClientAssetDataTableRow* InClientData);

private:

	// ����
	FAssetDataTableRow* AssetTable;
	FSourceDataTableRow* SourceTable;
	FWidgetDataTableRow* WidgettTable;
	FBuildingDataTableRow* BuildingTable;

	//

	UAssetTablePrimaryDataAsset* ItemPrimaryData;

	TArray<FName> AssetRowNames;
	TArray<FName> SourceNames;
	TArray<FName> WidgetNames;
	TArray<FName> BuildingNames;

	// ���� ���� ���� �� �ڿ�
	int32 PublicSource1 = 0;

	// ������ ȥ�� ����� �ڿ�
	int32 PrivateSource1 = 0;

	UStaticMesh* AssetMesh;

	TArray<AActor*> FoundActor; // �迭���� ����, ������ ���� Ʈ���� ���ƺ��̱���
	TArray<AActor*> BuildingActor;

	FTimerHandle TimerHandle;

	TArray<class UNiagaraComponent*> NiagaraSystemArray;
	TArray<AActor*> InActorArray;
	float MoveSpeed;

};
