// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../../WidgetInterface/BaseWidgetInterface.h"
#include "BaseWidgetImplement.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTP_API UBaseWidgetImplement : public UUserWidget, public IBaseWidgetInterface
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "WidgetStart")
	virtual void Acdtivation();

	void NativeConstruct() override;


public:
	void InitWidget();

};
