// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushiSpawner.h"
#include "TPSushi.h"

ATPSushiSpawner::ATPSushiSpawner()
{

}

void ATPSushiSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnSushi();
}

void ATPSushiSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATPSushiSpawner::SpawnSushi()
{
	for (int32 i = 0; i < SushiClasses.Num(); i++)
	{
		GetWorld()->SpawnActor<ATPSushi>(SushiClasses[i], GetActorLocation(), GetActorRotation());
	}
}

