#include "U1SphereDamageCaster.h"
#include "U1Damageable.h"

UU1SphereDamageCaster::UU1SphereDamageCaster()
{
	UPrimitiveComponent::SetCollisionResponseToAllChannels(ECR_Overlap);

	OnComponentBeginOverlap.AddDynamic(this, &UU1SphereDamageCaster::OnDamageAreaOverlapBegin);
	OnComponentEndOverlap.AddDynamic(this, &UU1SphereDamageCaster::OnDamageAreaOverlapEnd);
}

void UU1SphereDamageCaster::OnDamageAreaOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
		OverlappedActors.Add(OtherActor);
}

void UU1SphereDamageCaster::OnDamageAreaOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
		OverlappedActors.Remove(OtherActor);
}

TArray<FHitInfo> UU1SphereDamageCaster::CastDamage_Implementation(const FAttackInfo AttackInfo, bool PopupText)
{
	TArray<FHitInfo> Result;

	for (AActor* Actor : OverlappedActors)
	{
		if (IsValid(Actor) && Actor->Implements<UU1Damageable>())
		{
			IU1Damageable* Damageable = Cast<IU1Damageable>(Actor);

			Damageable->ApplyDamage(GetOwner(), AttackInfo.Damage);
			Result.Add({Actor});
		}
	}

	OverlappedActors.Empty();
	return Result;
}
