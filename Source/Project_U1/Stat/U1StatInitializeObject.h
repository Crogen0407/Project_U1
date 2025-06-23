// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "U1StatInitializeObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UU1StatInitializeObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECT_U1_API IU1StatInitializeObject
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Initialize(class UU1StatComponent* StatComponent) abstract;
};
