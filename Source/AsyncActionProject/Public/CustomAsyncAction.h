// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "CustomAsyncAction.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOOnDelayFinished, FString, Sample);

UCLASS()
class ASYNCACTIONPROJECT_API UCustomAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = true, WorldContext = "WorldContextObject"))
	static UCustomAsyncAction* ATypeOfDelay(UObject* WorldContextObject, float Delay1, float Delay2);

	UPROPERTY(BlueprintAssignable)
	FOOnDelayFinished OnDelayFinished;
	
	UPROPERTY(BlueprintAssignable)
	FOOnDelayFinished OnDelayFinished1;

	virtual void Activate() override;

	void StartTheDelay1();
	void StartTheDelay2();

private:

	UPROPERTY()
	UObject* m_WorldContextObject;

	float m_Delay1, m_Delay2;

	
	
};
