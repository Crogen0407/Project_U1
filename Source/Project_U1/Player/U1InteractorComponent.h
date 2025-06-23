// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "U1InteractorComponent.generated.h"

class AU1InteractableObject;
class AU1Player;
/**
 * 
 */
UCLASS()
class PROJECT_U1_API UU1InteractorComponent : public USphereComponent
{
	GENERATED_BODY()
	
public:
	UU1InteractorComponent();
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	void Interact(AU1Player* Player);
	
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AU1InteractableObject> CurrentInterableObject;
	
};
