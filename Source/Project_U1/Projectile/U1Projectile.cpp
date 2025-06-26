#include "U1Projectile.h"

void AU1Projectile::Initialize(AU1EntityBase* AttackOwner, const FVector& Direction, float MoveSpeed, float LifeTime, FAttackInfo AttackInfo, UU1StatComponent
                               * StatComponent)
{
	this->CachedAttackOwner = AttackOwner;
	this->CachedDirection = Direction;
	this->CachedMoveSpeed = MoveSpeed;
	this->CachedLifeTime = LifeTime;
	this->CachedAttackInfo = AttackInfo;
	this->CachedStatComponent = StatComponent;
}

// Sets default values
AU1Projectile::AU1Projectile()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void AU1Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// C#이랑 달라서 Set과 Get를 무조건 둘 다 이용해야 함.
	SetActorLocation(GetTransform().GetLocation() + CachedDirection * DeltaTime * CachedMoveSpeed);

	LifeTimer += DeltaTime;
	if (LifeTimer > CachedLifeTime)
	{
		Destroy();
	}
}

