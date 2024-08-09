// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClientAssetDataTableRow.generated.h"


USTRUCT()
struct PROJECTP_API FClientAssetDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	// 증감수치
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//bool bAcquisitionSource; // 해당 조건 사용 여부
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//float AcquisitionSourceMin; // 랜덤 자원 획득 최소값(정수, 실수 공용)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//float AcquisitionSourceMax;// 랜덤 자원 획득 최대값(정수, 실수 공용)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//int32 AcquisitionSourceInt; // 획득 자원 정수
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//float AcquisitionSourcePer; // 획득 자원 퍼센트

	//// 확률 최소/최대치
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//bool bRandomTriggerPer;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//float RandomPerMin; // 확률 존재시 최소값
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//float RandomPerCostMax; // 확률 존재시 최대값
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//float RandomPerCostAbs; // 확률 존재시 평균값(확률이 고정됬을 때)

	//// 소모 코스트 타입
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionConst")
	//bool bConsumptionConst;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionConst")
	//int32 Costint; //소모 코스트 정수
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionConst")
	//float CostPer; // 소모 코스트 퍼센트

	//// 자원의 소모처
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetSource")
	//bool bTargetSource;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetSource")
	//FDataTableRowHandle PublicSource; // 자원 사용 대상이 공공자원
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetSource")
	//TSubclassOf<AActor> Building; // 자원 사용 대상이 건물

	//// 자원의 소모형식(기간)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool bConsumptionSource;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool ImmediatelySource; // 자원이 즉발적으로 사용
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool ConstantlySource; // 자원이 일정 기간을 거치면서 사용 또는 기간 존재
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool ecycleSourceb; // 사용 횟수 여부

	//// 턴 지속수/ 횟수
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionTurn")
	//bool bConsumptionTurn;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionTurn")
	//int32 TurnPeriod; // 자원이 장기적으로 사용될 경우 턴
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionTurn")
	//int32 CyclePeriod; // 자원의 사용 횟수


};
