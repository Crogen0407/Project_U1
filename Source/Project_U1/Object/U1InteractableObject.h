// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "U1Object.h"
#include "U1InteractableObject.generated.h"

UCLASS()
class PROJECT_U1_API AU1InteractableObject : public AU1Object
{
	GENERATED_BODY()

public:
	AU1InteractableObject();
	
public:
	virtual void Interact(class AU1Player* Player);
	virtual void OnSelected(bool IsBegin);
protected:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USphereComponent> SphereComponent;
};
