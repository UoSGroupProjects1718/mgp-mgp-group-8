// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushiSpawner.h"
#include "TPSushi.h"
#include "Components/BillboardComponent.h"

ATPSushiSpawner::ATPSushiSpawner()
{
	BillboardComp = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComp"));
	BillboardComp->SetupAttachment(GetRootComponent());
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
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<ATPSushi>(SushiClasses[i], GetActorTransform(), SpawnParams);
	}
}

