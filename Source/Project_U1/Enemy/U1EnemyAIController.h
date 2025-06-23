// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "U1EnemyAIController.generated.h"

class AU1EntityBase;
/**
 * 
 */
UCLASS()
class PROJECT_U1_API AU1EnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
	virtual FPathFollowingRequestResult MoveTo(const FAIMoveRequest& MoveRequest, FNavPathSharedPtr* OutPath = nullptr) override;
	

protected:
	UPROPERTY(Transient)
	AU1EntityBase* OwnerEntity;	
};
