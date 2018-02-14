// Fill out your copyright notice in the Description page of Project Settings.

#include "TPPlayerController.h"
#include "Kismet/GameplayStatics.h"

ATPPlayerController::ATPPlayerController()
{
	bShowMouseCursor = true;	
	bEnableClickEvents = true;	
	bEnableTouchEvents = true;

	bIsSwitched = false;
}

void ATPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Switch", IE_Pressed, this, &ATPPlayerController::SwitchPlayer);
}

void ATPPlayerController::SwitchPlayer()
{
	bIsSwitched ? UGameplayStatics::SetPlayerControllerID(this, 1) : UGameplayStatics::SetPlayerControllerID(this, 0);

	int32 PlayerID = UGameplayStatics::GetPlayerControllerID(this);
	if (PlayerID == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player 1"));
	}
	else if (PlayerID == 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player 2"));
	}
}
