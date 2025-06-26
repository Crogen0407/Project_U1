// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "U1EntityBase.h"
#include "U1Enemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_U1_API AU1Enemy : public AU1EntityBase
{
	GENERATED_BODY()

public:
	AU1Enemy();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StaticMesh)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
};

