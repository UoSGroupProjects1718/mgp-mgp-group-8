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

void ATPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("TriggerClick", EInputEvent::IE_Pressed, this, &ATPPlayerController::TriggerClick);
}

void ATPPlayerController::Tick(float DeltaSeconds)
{
	if (UCameraComponent* PlayerCamera = GetViewTarget()->FindComponentByClass<UCameraComponent>())
	{
		FVector Start = PlayerCamera->GetComponentLocation();
		FVector End = Start + (PlayerCamera->GetComponentRotation().Vector() * 8000.0f);
		TraceForSpawner(Start, End);
	}
	else
	{
		FVector Start;
		FVector Dir;
		FVector End;
		DeprojectMousePositionToWorld(Start, Dir);
		End = Start + (Dir * 8000.0f);
		TraceForSpawner(Start, End);
	}
}

void ATPPlayerController::TriggerClick()
{
	if (SpawnerFocus)
	{
		SpawnerFocus->HandleClicked();
	}
}

void ATPPlayerController::TraceForSpawner(const FVector Start, const FVector& End)
{
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);
	if (HitResult.Actor.IsValid())
	{
		ATPSushiSpawner* HitSpawner = Cast<ATPSushiSpawner>(HitResult.Actor.Get());
		if (SpawnerFocus != HitSpawner)
		{
			SpawnerFocus = HitSpawner;
			UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitSpawner->GetFName().ToString())
		}
		else
		{
			SpawnerFocus = nullptr;
		}
	}
}
