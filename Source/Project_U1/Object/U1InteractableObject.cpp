#include "U1InteractableObject.h"
#include "Components/SphereComponent.h"

AU1InteractableObject::AU1InteractableObject()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetSphereRadius(100.f);
	SphereComponent->SetEnableGravity(false);

	SphereComponent->SetCollisionObjectType(ECC_GameTraceChannel1);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Block);
	SphereComponent->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);

	SphereComponent->SetupAttachment(RootComponent);
	SphereComponent->SetShouldUpdatePhysicsVolume(true);
	SphereComponent->SetCanEverAffectNavigation(false);
	SphereComponent->bDynamicObstacle = true;

	RootComponent = SphereComponent;

	// Overlap 이벤트 바인딩
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AU1InteractableObject::OnOverlapBegin);
}

void AU1InteractableObject::Interact(AU1Player* Player)
{
}

void AU1InteractableObject::OnSelected(bool IsBegin)
{
}

void AU1InteractableObject::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}
