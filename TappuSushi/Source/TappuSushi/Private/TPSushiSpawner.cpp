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

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ATPSushiSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void ATPSushiSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATPSushiSpawner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("TriggerClick", EInputEvent::IE_Pressed, this, &ATPSushiSpawner::TriggerClick);
}

void ATPSushiSpawner::TriggerClick()
{
	HandleClicked();
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
	UE_LOG(LogTemp, Warning, TEXT("Spawn Food"))
}

