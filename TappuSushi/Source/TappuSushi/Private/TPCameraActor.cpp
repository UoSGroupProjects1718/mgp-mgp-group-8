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
	ATPPlayerController* Player2 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1));
	if (Player1 && Player2)
	{
		Player1->SetViewTarget(this);
		Player2->SetViewTarget(this);
	}
}
