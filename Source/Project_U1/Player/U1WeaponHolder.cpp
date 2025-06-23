// Fill out your copyright notice in the Description page of Project Settings.


#include "U1WeaponHolder.h"

// Sets default values
AU1WeaponHolder::AU1WeaponHolder()
{
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = SkeletalMeshComponent;

	SkeletalMeshComponent->SetAnimationMode(EAnimationMode::AnimationSingleNode);
}

// Called when the game starts or when spawned
void AU1WeaponHolder::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AU1WeaponHolder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

