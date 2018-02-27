// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushiSpawner.h"
#include "TPSushi.h"
#include "TPPlayerController.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

ATPSushiSpawner::ATPSushiSpawner()
{
	DummyRootComp = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRootComp"));
	RootComponent = DummyRootComp;

	SpawnSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpawnSprite"));
	SpawnSprite->SetupAttachment(DummyRootComp);
	SpawnSprite->OnClicked.AddDynamic(this, &ATPSushiSpawner::SpawnerClicked);
	SpawnSprite->OnInputTouchBegin.AddDynamic(this, &ATPSushiSpawner::OnFingerPressed);

	SpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnLoc"));
	SpawnLocation->SetupAttachment(DummyRootComp);
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
	if (SushiClasses.Num() >= 0)
	{
		GetWorld()->SpawnActor<ATPSushi>(SushiClasses[0], SpawnLocation->GetComponentLocation(), SpawnLocation->GetComponentRotation());
		UE_LOG(LogTemp, Warning, TEXT("Spawn Food"))
	}
}

