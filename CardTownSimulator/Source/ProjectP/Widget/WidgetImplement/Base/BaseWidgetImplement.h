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

	// @TODO 매개변수 확인후 넣기
	void CreateSource_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	void DestroySource_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	void AddSoutce_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	void MinSource_CardInfo(FAssetDataTableRow InAssetDataTableRow);
	
	// @TODO 특정 건물이 지어졌고 해당 건물이 어떤 건물인지 까지 데이터를 넘겨줘야됨
	// 지었다고 끝 아님
	void CreateSource();
	void DestorySource(FBuildingDataTableRow* InSource);

	UBaseWidgetImplement* GetBaseWidgetImplement();

public:
	void EventProduction(AActor* InActor);

private:
	class AObserverImplement* ObserverImplement;
	class UEventGameInstanceSubsystem* EventGameInstanceSubsystem;
	
	TArray<AActor*> FoundActor; // 배열보단 삽입, 삭제가 좋은 트리가 좋아보이긴함

	UBaseWidgetImplement* BaseWidgetImplement;

};
