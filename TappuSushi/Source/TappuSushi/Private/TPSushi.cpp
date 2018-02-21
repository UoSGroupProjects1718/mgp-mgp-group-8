// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushi.h"
#include "PaperSpriteComponent.h"

ATPSushi::ATPSushi()
{
	DummyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRoot"));
	RootComponent = DummyRootComponent;

	SushiSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SushiSprite"));
	SushiSprite->SetupAttachment(DummyRootComponent);
}

void ATPSushi::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(2.5f);
}

void ATPSushi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

