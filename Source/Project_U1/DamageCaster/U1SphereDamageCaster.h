// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "U1DamageCaster.h"
#include "Components/SphereComponent.h"
#include "U1SphereDamageCaster.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECT_U1_API UU1SphereDamageCaster : public USphereComponent, public IU1DamageCaster
{
	GENERATED_BODY()

public:
	UU1SphereDamageCaster();

private:
	UFUNCTION()
	void OnDamageAreaOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                              const FHitResult& SweepResult);
	UFUNCTION()
	void OnDamageAreaOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	virtual TArray<FHitInfo> CastDamage_Implementation(const FAttackInfo AttackInfo, bool PopupText) override;

protected:
	UPROPERTY(Transient)
	TSet<AActor*> OverlappedActors;
};
