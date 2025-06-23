// Fill out your copyright notice in the Description page of Project Settings.


#include "U1Object.h"

// Sets default values
AU1Object::AU1Object()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AU1Object::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AU1Object::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

