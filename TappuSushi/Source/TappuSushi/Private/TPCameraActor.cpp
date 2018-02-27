// Fill out your copyright notice in the Description page of Project Settings.

#include "TPCameraActor.h"
#include "TPPlayerController.h"
#include "Camera/CameraComponent.h"
#include "kismet/GameplayStatics.h"

ATPCameraActor::ATPCameraActor()
{
	GetCameraComponent()->ProjectionMode = ECameraProjectionMode::Orthographic;
}

void ATPCameraActor::BeginPlay()
{
	Super::BeginPlay();

	ATPPlayerController* Player1 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (Player1)
	{
		Player1->SetViewTarget(this);
	}

	ATPPlayerController* Player2 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1));
	if (Player2)
	{
		Player2->SetViewTarget(this);
	}
}
