// Fill out your copyright notice in the Description page of Project Settings.

#include "TPPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "TPPawn.h"

ATPPlayerController::ATPPlayerController()
{
	bShowMouseCursor = true;	
	bEnableClickEvents = true;	
	bEnableTouchEvents = true;
}

void ATPPlayerController::SetPawn(APawn* InPawn)
{
	AController::SetPawn(InPawn);
	TPawn = Cast<ATPPawn>(InPawn);
}

void ATPPlayerController::SwitchPawn()
{
	int32 ID = GetLocalPlayer()->GetControllerId();
	if (ID == 0)
	{
		Possess(TPawn);
	}
	else if (ID == 1)
	{
		Possess(TPawn);
	}
}
