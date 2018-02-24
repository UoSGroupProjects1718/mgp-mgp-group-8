// Fill out your copyright notice in the Description page of Project Settings.

#include "TPPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "TPSushiSpawner.h"

ATPPlayerController::ATPPlayerController()
{
	bShowMouseCursor = true;	
	bEnableClickEvents = true;	
	bEnableTouchEvents = true;
}

void ATPPlayerController::SetPawn(APawn* InPawn)
{
	AController::SetPawn(InPawn);
	TPawn = Cast<ATPSushiSpawner>(InPawn);
}

void ATPPlayerController::SwitchPawn()
{
	int32 PlayerID = GetLocalPlayer()->GetControllerId();
	if (PlayerID == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player 1 Posses Spawner"))
		Possess(TPawn);
	}
	else if(PlayerID == 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player 2 Posses Spawner"))
		Possess(TPawn);
	}
}
