// Fill out your copyright notice in the Description page of Project Settings.


#include "U1PlayerMovement.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "Project_U1/Entity/U1StatComponent.h"

void UU1PlayerMovement::Initialize(UU1StatComponent* StatComponent)
{
	CashedStatComponent = StatComponent;
}

void UU1PlayerMovement::BeginPlay()
{
	Super::BeginPlay();
	bOrientRotationToMovement = false;
	DashCooldownTimer = DashCooldownDelay;
	GetPawnOwner()->bUseControllerRotationYaw = false;
}

void UU1PlayerMovement::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DashUpdate(DeltaTime);
}

void UU1PlayerMovement::Move(FVector2D MovementVector)
{
	MaxWalkSpeed = CashedStatComponent->GetFinalStatValue(EEntityStatType::MoveSpeed);
	MovementDirectionVector.X = MovementVector.X;
	MovementDirectionVector.Y = MovementVector.Y;
	AddInputVector(MovementDirectionVector, false);
}

void UU1PlayerMovement::LookToTarget(FVector TargetLocation)
{
	FVector PlayerLocation = GetPawnOwner()->GetActorLocation();
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(PlayerLocation, TargetLocation);
	LookAtRotation.Pitch = 0.0f;
	//LookAtRotation.Yaw = 0.0f;
	LookAtRotation.Roll = 0.0f;
	GetPawnOwner()->SetActorRotation(LookAtRotation);
}

void UU1PlayerMovement::Dash(FVector DashDirection)
{
	if (GetCharacterOwner() == nullptr) return;
	if (DashCooldownTimer < DashCooldownDelay) return;

	CanDash = true;
	DashActiveTimer = 0.f;
	DashCooldownTimer = 0.f;
	DashDirection.Z = 0.f;
	DashDirectionVector = DashDirection.GetSafeNormal();
}

void UU1PlayerMovement::DashUpdate(float DeltaTime)
{
	if (DashCooldownTimer < DashCooldownDelay)
		DashCooldownTimer += DeltaTime;
	
	if (CanDash && GetCharacterOwner() != nullptr)
	{
		if (CanDash && GetCharacterOwner())
		{
			DashActiveTimer += DeltaTime;

			const float DashDuration = 0.1f;
			const float DashSpeed = DashDistance / DashDuration;

			if (DashActiveTimer < DashDuration)
			{
				FVector Movement = DashDirectionVector * DashSpeed * DeltaTime;
				GetCharacterOwner()->AddActorWorldOffset(Movement, true);
			}
			else
			{
				CanDash = false;
			}
		}
	}
}