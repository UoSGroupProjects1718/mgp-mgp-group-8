// Fill out your copyright notice in the Description page of Project Settings.

#include "TPMenuGameMode.h"
#include "TPMenuPlayerController.h"
#include "Blueprint/UserWidget.h"

ATPMenuGameMode::ATPMenuGameMode()
{
	PlayerControllerClass = ATPMenuPlayerController::StaticClass();
}

void ATPMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	ShowMainMenu();
}

void ATPMenuGameMode::ShowMainMenu()
{
	if (MainMenuWidget)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidget);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
