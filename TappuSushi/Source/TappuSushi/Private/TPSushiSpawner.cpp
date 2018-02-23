// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushiSpawner.h"
#include "TPSushi.h"
#include "PaperSpriteComponent.h"

ATPSushiSpawner::ATPSushiSpawner()
{
	DummyRootComp = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRootComp"));
	RootComponent = DummyRootComp;

	SpawnSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpawnSprite"));
	SpawnSprite->SetupAttachment(DummyRootComp);
	SpawnSprite->OnClicked.AddDynamic(this, &ATPSushiSpawner::SpawnerClicked);
	SpawnSprite->OnInputTouchBegin.AddDynamic(this, &ATPSushiSpawner::OnFingerPressed);
}

void ATPSushiSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void ATPSushiSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATPSushiSpawner::SpawnerClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
	HandleClicked();
}

void ATPSushiSpawner::OnFingerPressed(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	HandleClicked();
}

void ATPSushiSpawner::HandleClicked()
{
	SpawnSushi();
}

void ATPSushiSpawner::SpawnSushi()
{
	for (int32 i = 0; i < SushiClasses.Num(); i++)
	{
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<ATPSushi>(SushiClasses[i], GetActorTransform(), SpawnParams);
	}
}

