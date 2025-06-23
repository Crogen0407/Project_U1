#include "Stage.h"

AStage::AStage()
{
	StartPoint = CreateDefaultSubobject<USceneComponent>(TEXT("StartPoint"));
	SetRootComponent(StartPoint);
	
	PrimaryActorTick.bCanEverTick = true;
}

void AStage::BeginPlay()
{
	Super::BeginPlay();
}

void AStage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

