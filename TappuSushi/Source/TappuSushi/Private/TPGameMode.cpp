// Fill out your copyright notice in the Description page of Project Settings.

#include "TPGameMode.h"
#include "TPPlayerController.h"
#include "TPPlayerState.h"
#include "TPGameState.h"
#include "Kismet/GameplayStatics.h"

ATPGameMode::ATPGameMode()
{
	PlayerControllerClass = ATPPlayerController::StaticClass();
	PlayerStateClass = ATPPlayerState::StaticClass();
	GameStateClass = ATPGameState::StaticClass();
}

void ATPGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::CreatePlayer(this, 1);
}
