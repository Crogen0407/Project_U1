// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "U1EntityBase.h"
#include "U1Player.generated.h"

class UU1AttackerComponent;
class UCameraComponent;
class USpringArmComponent;
class UU1PlayerMovement;
class UU1InteractorComponent;

UCLASS()
class PROJECT_U1_API AU1Player : public AU1EntityBase
{
	GENERATED_BODY()

public:
	AU1Player();

	virtual void Tick(float DeltaSeconds) override;

public:
	FORCEINLINE UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	UU1PlayerMovement* GetPlayerMovementComponent();
	UStaticMeshComponent* GetWeaponStaticMeshComponent() const
	{
		return WeaponStaticMeshComponent;
	}
	UU1InteractorComponent* GetInteractorComponent() const
	{
		return InteractorComponent;
	}

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	UU1PlayerMovement* CashedPlayerMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	UStaticMeshComponent* WeaponStaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Interaction)
	UU1InteractorComponent* InteractorComponent;
};
