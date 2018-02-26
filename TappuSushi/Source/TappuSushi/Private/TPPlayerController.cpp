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
}
