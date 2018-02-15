// Fill out your copyright notice in the Description page of Project Settings.

#include "TPMenuGameMode.h"
#include "TPMenuPlayerController.h"

ATPMenuGameMode::ATPMenuGameMode()
{
	PlayerControllerClass = ATPMenuPlayerController::StaticClass();
}

void ATPMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	ShowMainMenu_Implementation();
}

void ATPMenuGameMode::ShowMainMenu_Implementation()
{

}
