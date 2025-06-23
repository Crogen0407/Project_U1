// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Project_U1/DamageCaster/U1Damageable.h"
#include "U1EntityBase.generated.h"

class UWidgetComponent;
class UU1HealthComponent;
class UU1StatComponent;

class UU1AttackerComponent;

UCLASS()
class PROJECT_U1_API AU1EntityBase : public ACharacter, public IU1Damageable
{
	GENERATED_BODY()

public:
	AU1EntityBase();
	
	UU1AttackerComponent* GetAttackerComponent();
	UU1StatComponent* GetStatComponent() const {return StatComponent;}
	UU1HealthComponent* GetHealthComponent() const {return HealthComponent;}
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnDie() override;
	
public:
	virtual void ApplyDamage(AActor* Attacker, int Damage) override;

	UPROPERTY(Transient)
	UU1AttackerComponent* AttackComponent;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = StatComponent)
	TObjectPtr<UU1StatComponent> StatComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = HealthComponent)
	UU1HealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = HpBarWidgetComponent)
	UWidgetComponent* HpBarWidgetComponent;
};
