#include "U1Portal.h"
#include "Project_U1/GameInstance/U1StageManager.h"

AU1Portal::AU1Portal()
{
}

void AU1Portal::Interact(AU1Player* Player)
{
	Super::Interact(Player);
	// TODO : 나중에 스테이지 선택 씬으로 넘어가기
	GetStageManager->OpenStage({TEXT("StageLevel")}, EStageClearReward::NONE);
}
