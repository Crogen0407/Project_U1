#include "U1EnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "Project_U1/Entity/U1AttackerComponent.h"
#include "Project_U1/Entity/U1EntityBase.h"

void AU1EnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	this->OwnerEntity = Cast<AU1EntityBase>(GetPawn());

	if (this->OwnerEntity == nullptr)
		UE_LOG(LogTemp, Error, TEXT("OwnerEntity is null"));
}

void AU1EnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	if (OwnerEntity)
		OwnerEntity->GetAttackerComponent()->IsAttacking = true;
}

FPathFollowingRequestResult AU1EnemyAIController::MoveTo(const FAIMoveRequest& MoveRequest, FNavPathSharedPtr* OutPath)
{
	auto Result = Super::MoveTo(MoveRequest, OutPath);

	if (OwnerEntity && (Result != FPathFollowingResultFlags::AlreadyAtGoal || OwnerEntity->GetAttackerComponent()->IsAttacking))
		OwnerEntity->GetAttackerComponent()->IsAttacking = false;
	
	return Result;
}
