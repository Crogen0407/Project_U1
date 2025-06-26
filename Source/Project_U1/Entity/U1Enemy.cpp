#include "U1Enemy.h"
#include "Components/CapsuleComponent.h"
#include "Project_U1/Enemy/U1EnemyAIController.h"
#include "Project_U1/Enemy/U1EnemyMovement.h"

AU1Enemy::AU1Enemy()
{
	AIControllerClass = AU1EnemyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
	// Setting capsule...
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap); // Player는 Overlap만
	GetCapsuleComponent()->SetCollisionObjectType(ECC_GameTraceChannel3);
	
	// Create static component...
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	StaticMeshComponent->SetCollisionObjectType(ECC_WorldStatic);
	
	// Setting skeletal mesh...
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetMesh()->SetCollisionObjectType(ECC_WorldStatic);

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
}
