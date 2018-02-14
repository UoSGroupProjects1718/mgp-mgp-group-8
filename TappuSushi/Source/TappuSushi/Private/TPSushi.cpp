// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushi.h"
#include "PaperSpriteComponent.h"

ATPSushi::ATPSushi()
{
	SushiSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SushiSprite"));
	SushiSprite->SetupAttachment(RootComponent);

	CurrentLocation = SushiSprite->GetComponentLocation();
}

void ATPSushi::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(5.0f);
}

void ATPSushi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = CurrentLocation * DeltaTime;

	SushiSprite->SetWorldLocation(NewLocation);
}

