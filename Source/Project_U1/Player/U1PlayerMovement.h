// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Project_U1/Stat/U1StatInitializeObject.h"
#include "U1PlayerMovement.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_U1_API UU1PlayerMovement : public UCharacterMovementComponent, public IU1StatInitializeObject
{
	GENERATED_BODY()

public:
	virtual void Initialize(UU1StatComponent* StatComponent) override;;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

	void Move(FVector2D MovementVector);
	void LookToTarget(FVector TargetLocation);
	void Dash(FVector TargetLocation);
	void DashUpdate(float DeltaTime);

private:
	FVector MovementDirectionVector;
	bool CanDash;
	float DashActiveTimer = 0.f;
	float DashCooldownTimer = 0.f;
	FVector DashDirection;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DashDistance = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DashCooldownDelay = 1.f;
	
	UPROPERTY(Transient)
	UU1StatComponent* CashedStatComponent;
};
