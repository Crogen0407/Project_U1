#include "U1PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "U1InteractorComponent.h"
#include "Engine/LocalPlayer.h"
#include "Project_U1/Entity/U1AttackerComponent.h"
#include "Project_U1/Entity/U1Player.h"
#include "Project_U1/Player/U1PlayerMovement.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AU1PlayerController::AU1PlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AU1PlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	ControlledPlayer = Cast<AU1Player, ACharacter>(GetCharacter());
}

void AU1PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnLookDirection();
}

void AU1PlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AU1PlayerController::OnMove);
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &AU1PlayerController::OnDash);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AU1PlayerController::OnAttack);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AU1PlayerController::OnInteract);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AU1PlayerController::OnMove(const FInputActionValue& Value)
{
	if (ControlledPlayer == nullptr) return;
	
	MovementDirectionVector = Value.Get<FVector2D>();
	ControlledPlayer->GetPlayerMovementComponent()->Move(MovementDirectionVector);
}

void AU1PlayerController::OnLookDirection() const
{
	if (ControlledPlayer == nullptr) return;

	FHitResult HitResult;
	if (GetHitResultUnderCursor(ECC_GameTraceChannel4, false, HitResult))
	{
		FVector TargetLocation = HitResult.Location;
		ControlledPlayer->GetPlayerMovementComponent()->LookToTarget(TargetLocation);
	}
}

void AU1PlayerController::OnDash()
{
	if (ControlledPlayer == nullptr) return;
	
	FHitResult HitResult;

	if (GetHitResultUnderCursor(ECC_Visibility, false, HitResult))
	{
		FVector TargetLocation = FVector(MovementDirectionVector.X, MovementDirectionVector.Y, 0.0f);
		ControlledPlayer->GetPlayerMovementComponent()->Dash(TargetLocation);
	}
}

void AU1PlayerController::OnAttack()
{
	ControlledPlayer->GetAttackerComponent()->BeginAttack();
}

void AU1PlayerController::OnInteract()
{
	ControlledPlayer->GetInteractorComponent()->Interact(ControlledPlayer);
}

