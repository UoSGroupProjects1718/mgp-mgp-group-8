// Fill out your copyright notice in the Description page of Project Settings.

#include "TPPawn.h"
#include "TPPlayerController.h"
#include "TPSushi.h"
#include "TPSushiSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

ATPPawn::ATPPawn()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bDrawDebugHelpers = true;
}

void ATPPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ATPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ATPPlayerController* PlayerOne = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		if (UCameraComponent* PlayerCamera = PlayerOne->GetViewTarget()->FindComponentByClass<UCameraComponent>())
		{

		}
	}

	if (ATPPlayerController* PlayerTwo = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1)))
	{
		if (UCameraComponent* PlayerCamera = PlayerTwo->GetViewTarget()->FindComponentByClass<UCameraComponent>())
		{

		}
	}
}

void ATPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("TriggerClick", EInputEvent::IE_Pressed, this, &ATPPawn::TriggerClick);
}

void ATPPawn::CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult)
{

}

void ATPPawn::TriggerClick()
{

}

void ATPPawn::TraceForObjects(const FVector Start, const FVector& End)
{
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	if (bDrawDebugHelpers)
	{
		DrawDebugLine(GetWorld(), Start, HitResult.Location, FColor::Red);
		DrawDebugSolidBox(GetWorld(), HitResult.Location, FVector(20.0f), FColor::Red);
	}

	if (HitResult.Actor.IsValid())
	{
		ATPSushi* HitSushi = Cast<ATPSushi>(HitResult.Actor.Get());
		if (HitSushi)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Sushi"))
			// TODO: Calculate Score
		}

		ATPSushiSpawner* HitSpawner = Cast<ATPSushiSpawner>(HitResult.Actor.Get());
		if (HitSpawner)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Sushi Spawner"))
			// TODO: Spawn Sushi 
		}
	}
}

