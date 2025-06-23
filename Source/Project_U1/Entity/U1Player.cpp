#include "U1Player.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Project_U1/Player/U1InteractorComponent.h"
#include "Project_U1/Player/U1PlayerMovement.h"

AU1Player::AU1Player()
{
	// Setting capsule...
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECR_Overlap); // Enemy는 Overlap만
	GetCapsuleComponent()->SetCollisionObjectType(ECC_GameTraceChannel2);
	
	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Setting skeletal mesh...
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetMesh()->SetCollisionObjectType(ECC_WorldStatic);
	
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create weapon static component...
	WeaponStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponStaticMeshComponent"));
	WeaponStaticMeshComponent->SetupAttachment(RootComponent);
	WeaponStaticMeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	WeaponStaticMeshComponent->SetCollisionObjectType(ECC_WorldStatic);
	
	// Create interactor component...
	InteractorComponent = CreateDefaultSubobject<UU1InteractorComponent>(TEXT("InteractorComponent"));
	InteractorComponent->SetupAttachment(RootComponent);
	InteractorComponent->SetSphereRadius(100.f);

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AU1Player::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

UU1PlayerMovement* AU1Player::GetPlayerMovementComponent()
{
	if (CashedPlayerMovementComponent == nullptr)
		CashedPlayerMovementComponent = Cast<UU1PlayerMovement, UCharacterMovementComponent>(GetCharacterMovement());
	
	return CashedPlayerMovementComponent;
}


