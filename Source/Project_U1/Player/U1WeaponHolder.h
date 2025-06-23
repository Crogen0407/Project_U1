// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "U1WeaponHolder.generated.h"
  
UCLASS()
class PROJECT_U1_API AU1WeaponHolder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AU1WeaponHolder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = SkeletalMeshComponent)
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
};
