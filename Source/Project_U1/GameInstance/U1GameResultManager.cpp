// Fill out your copyright notice in the Description page of Project Settings.


#include "U1GameResultManager.h"

#include "Kismet/GameplayStatics.h"

FString UU1GameResultManager::GetCurrentTimeString()
{
	int Time = static_cast<int>(GetWorld()->GetTimeSeconds());
	int Second = Time % 60;
	int Minute = Time / 60;
	
	return FString::Printf(TEXT("%02d:%02d"), Minute, Second);
}

void UU1GameResultManager::GetReset()
{
	GetWorld()->TimeSeconds = 0;
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}
