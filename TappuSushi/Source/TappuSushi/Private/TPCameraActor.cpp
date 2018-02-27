// Fill out your copyright notice in the Description page of Project Settings.

#include "TPCameraActor.h"
#include "TPPlayerController.h"
#include "kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"

ATPCameraActor::ATPCameraActor()
{
	GetCameraComponent()->ProjectionMode = ECameraProjectionMode::Orthographic;
	GetCameraComponent()->SetOrthoWidth(2048.0f);
}

void ATPCameraActor::BeginPlay()
{
	Super::BeginPlay();

	ATPPlayerController* PlayerController = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerController)
	{
		PlayerController->SetViewTarget(this);
	}
}
