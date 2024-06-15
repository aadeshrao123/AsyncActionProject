// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncActionProject/Public/CustomAsyncAction.h"

UCustomAsyncAction* UCustomAsyncAction::ATypeOfDelay(UObject* WorldContextObject, float Delay1, float Delay2)
{
	UCustomAsyncAction* MyClass = NewObject<UCustomAsyncAction>();
	MyClass->m_WorldContextObject = WorldContextObject;
	MyClass->m_Delay1 = Delay1;
	MyClass->m_Delay2 = Delay2;

	return MyClass;
}

void UCustomAsyncAction::Activate()
{
	Super::Activate();

	UWorld* World = GEngine->GetWorldFromContextObjectChecked(m_WorldContextObject);
	FTimerHandle TimerHandle;

	World->GetTimerManager().SetTimer(TimerHandle, this, &UCustomAsyncAction::StartTheDelay1, m_Delay1);
	FTimerHandle TimerHandle1;

	World->GetTimerManager().SetTimer(TimerHandle1, this, &UCustomAsyncAction::StartTheDelay2, m_Delay2);
}

void UCustomAsyncAction::StartTheDelay1()
{
	OnDelayFinished.Broadcast(FString("Delay1"));
}

void UCustomAsyncAction::StartTheDelay2()
{
	OnDelayFinished1.Broadcast(FString("Delay2"));

}
