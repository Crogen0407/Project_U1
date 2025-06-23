// Fill out your copyright notice in the Description page of Project Settings.


#include "U1HealthComponent.h"

#include "MathUtil.h"
#include "U1StatComponent.h"

// Sets default values for this component's properties
UU1HealthComponent::UU1HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UU1HealthComponent::Initialize(UU1StatComponent* StatComponent)
{
	CashedStatComponent = StatComponent;
	CurrentHealth = CashedStatComponent->GetFinalStatIntegerValue(EEntityStatType::MaxHealth);
}

float UU1HealthComponent::GetHealthPercentage() const
{
	return static_cast<float>(CurrentHealth)/CashedStatComponent->GetFinalStatIntegerValue(EEntityStatType::MaxHealth);
}

void UU1HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (PC->WasInputKeyJustPressed(EKeys::BackSpace))
		{
			UE_LOG(LogTemp, Warning, TEXT("데미지 받음! : 10"));
			UE_LOG(LogTemp, Warning, TEXT("데미지 받음! : %d"), CurrentHealth);
			ApplyDamage(nullptr, 10);
		}
	}
}

void UU1HealthComponent::ApplyDamage(AActor* Attacker, int Damage)
{
	const int MaxHealth = CashedStatComponent->GetFinalStatIntegerValue(EEntityStatType::MaxHealth);
	const int PreventHealth = CurrentHealth;
	CurrentHealth -= Damage;

	const float PreventHealthPercentage = FMathf::Clamp(static_cast<float>(PreventHealth) / MaxHealth, 0.f, 1.f);
	const float HealthPercentage = FMathf::Clamp(static_cast<float>(CurrentHealth) / MaxHealth, 0.f, 1.f);
	
	HealthChangedEvent.Broadcast(PreventHealthPercentage, HealthPercentage);
	
	if (CurrentHealth <= 0.f)
		OnDie();
}

void UU1HealthComponent::OnDie()
{
	Cast<IU1Damageable>(GetOwner())->OnDie();
	
	UE_LOG(LogTemp, Log, TEXT("죽었는데?"));
	GetOwner()->Destroy();
}

