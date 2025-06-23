// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Project_U1/Stat/U1StatInitializeObject.h"
#include "U1EnemyMovement.generated.h"

class AAIController;
/**
 * 
 */
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_U1_API UU1EnemyMovement : public UCharacterMovementComponent, public IU1StatInitializeObject
{
	GENERATED_BODY()

public:
	UU1EnemyMovement();

	virtual void Initialize(UU1StatComponent* StatComponent) override;
	
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDash();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dash")
	float DashableDistance = 500.f;
	
	UPROPERTY(Transient)
	APawn* OwnerPawn;

	UPROPERTY(Transient)
	AActor* TargetActor;

	UPROPERTY(Transient)
	AAIController* AIController;

	UPROPERTY(Transient)
	UU1StatComponent* CashedStatComponent;
};
