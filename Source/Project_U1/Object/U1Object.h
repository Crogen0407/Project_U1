// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "U1Object.generated.h"

UCLASS()
class PROJECT_U1_API AU1Object : public AActor
{
	GENERATED_BODY()
	
public:	
	AU1Object();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
