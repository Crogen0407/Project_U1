// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Project_U1/DamageCaster/U1DamageCaster.h"
#include "Project_U1/Entity/U1EntityBase.h"
#include "U1Projectile.generated.h"

class AU1EntityBase;
class UU1StatComponent;

UCLASS()
class PROJECT_U1_API AU1Projectile : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Initialize(AU1EntityBase* AttackOwner, const FVector& Direction, float MoveSpeed, float LifeTime, FAttackInfo AttackInfo, UU1StatComponent* StatComponent);
	
public:	
	// Sets default values for this actor's properties
	AU1Projectile();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile)
	AU1EntityBase* CachedAttackOwner;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
	FVector CachedDirection;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
	float CachedMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile)
	float CachedLifeTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile)
	FAttackInfo CachedAttackInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile)
	UU1StatComponent* CachedStatComponent;

	float LifeTimer;
};
