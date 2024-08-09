// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ClientAssetDataTableRow.generated.h"


USTRUCT()
struct PROJECTP_API FClientAssetDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	// ������ġ
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//bool bAcquisitionSource; // �ش� ���� ��� ����
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//float AcquisitionSourceMin; // ���� �ڿ� ȹ�� �ּҰ�(����, �Ǽ� ����)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//float AcquisitionSourceMax;// ���� �ڿ� ȹ�� �ִ밪(����, �Ǽ� ����)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//int32 AcquisitionSourceInt; // ȹ�� �ڿ� ����
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AcquisitionSource")
	//float AcquisitionSourcePer; // ȹ�� �ڿ� �ۼ�Ʈ

	//// Ȯ�� �ּ�/�ִ�ġ
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//bool bRandomTriggerPer;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//float RandomPerMin; // Ȯ�� ����� �ּҰ�
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//float RandomPerCostMax; // Ȯ�� ����� �ִ밪
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTriggerPer")
	//float RandomPerCostAbs; // Ȯ�� ����� ��հ�(Ȯ���� �������� ��)

	//// �Ҹ� �ڽ�Ʈ Ÿ��
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionConst")
	//bool bConsumptionConst;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionConst")
	//int32 Costint; //�Ҹ� �ڽ�Ʈ ����
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionConst")
	//float CostPer; // �Ҹ� �ڽ�Ʈ �ۼ�Ʈ

	//// �ڿ��� �Ҹ�ó
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetSource")
	//bool bTargetSource;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetSource")
	//FDataTableRowHandle PublicSource; // �ڿ� ��� ����� �����ڿ�
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetSource")
	//TSubclassOf<AActor> Building; // �ڿ� ��� ����� �ǹ�

	//// �ڿ��� �Ҹ�����(�Ⱓ)
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool bConsumptionSource;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool ImmediatelySource; // �ڿ��� ��������� ���
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool ConstantlySource; // �ڿ��� ���� �Ⱓ�� ��ġ�鼭 ��� �Ǵ� �Ⱓ ����
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionSource")
	//bool ecycleSourceb; // ��� Ƚ�� ����

	//// �� ���Ӽ�/ Ƚ��
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionTurn")
	//bool bConsumptionTurn;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionTurn")
	//int32 TurnPeriod; // �ڿ��� ��������� ���� ��� ��
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConsumptionTurn")
	//int32 CyclePeriod; // �ڿ��� ��� Ƚ��


};
