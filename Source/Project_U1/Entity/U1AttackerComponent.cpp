#include "U1AttackerComponent.h"
#include "U1EntityBase.h"

// Sets default values for this component's properties
UU1AttackerComponent::UU1AttackerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UU1AttackerComponent::Initialize(UU1StatComponent* StatComponent)
{
	CashedStatComponent = StatComponent;
}

// Called every frame
void UU1AttackerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AutoAttackLogic(DeltaTime);
}

void UU1AttackerComponent::AutoAttackLogic(float DeltaTime)
{
	if (AutoAttack == false) return;
	if (IsAttacking == true)
	{
		AttackTimer += DeltaTime;
		if (AttackTimer > AttackDelay)
		{
			BeginAttack();
			AttackTimer = 0.f;
		}
	}
}

