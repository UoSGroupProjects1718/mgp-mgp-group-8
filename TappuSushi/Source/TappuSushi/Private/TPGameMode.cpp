// Fill out your copyright notice in the Description page of Project Settings.

#include "TPGameMode.h"
#include "TPPlayerController.h"
#include "Kismet/GameplayStatics.h"

ATPGameMode::ATPGameMode()
{
	PlayerControllerClass = ATPPlayerController::StaticClass();
}

void ATPGameMode::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::CreatePlayer(this, 1);
}
