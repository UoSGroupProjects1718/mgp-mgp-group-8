// Fill out your copyright notice in the Description page of Project Settings.

#include "TPCameraActor.h"
#include "TPPlayerController.h"
#include "Kismet/GameplayStatics.h"

ATPCameraActor::ATPCameraActor()
{

}

void ATPCameraActor::BeginPlay()
{
	Super::BeginPlay();

	ATPPlayerController* Player1 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (Player1)
	{
		Player1->SetViewTargetWithBlend(this);
	}

	ATPPlayerController* Player2 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1));
	if (Player2)
	{
		Player2->SetViewTargetWithBlend(this);
	}
}
