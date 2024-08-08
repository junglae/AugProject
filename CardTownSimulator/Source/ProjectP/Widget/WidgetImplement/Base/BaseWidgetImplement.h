// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "../../WidgetInterface/BaseWidgetInterface.h"

#include "BaseWidgetImplement.generated.h"

struct FAssetDataTableRow;
struct FBuildingDataTableRow;
struct FBaseStruct;

UCLASS()
class PROJECTP_API UBaseWidgetImplement : public UUserWidget, public IBaseWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "WidgetStart")
	virtual void Activation(FBaseStruct InStruct);
	UFUNCTION(BlueprintCallable, Category = "WidgetStart")
	void SpawnActor();
	UFUNCTION(BlueprintImplementableEvent, Category = "WidgetImple")
	void Passive();
	UFUNCTION(BlueprintCallable, Category = "WidgetStart")
	void NativeConstruct() override;

public:
	void InitWidget();

	// @TODO �Ű����� Ȯ���� �ֱ�
	void CreateSource_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	void DestroySource_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	void AddSoutce_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	void MinSource_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	
	// @TODO Ư�� �ǹ��� �������� �ش� �ǹ��� � �ǹ����� ���� �����͸� �Ѱ���ߵ�
	// �����ٰ� �� �ƴ�
	void CreateSource();
	void DestorySource(FBuildingDataTableRow* InSource);

	UBaseWidgetImplement* GetBaseWidgetImplement();

public:
	void EventProduction(AActor* InActor);

private:
	class AObserverImplement* ObserverImplement;
	class UEventGameInstanceSubsystem* EventGameInstanceSubsystem;
	
	TArray<AActor*> FoundActor; // �迭���� ����, ������ ���� Ʈ���� ���ƺ��̱���

	UBaseWidgetImplement* BaseWidgetImplement;

};
