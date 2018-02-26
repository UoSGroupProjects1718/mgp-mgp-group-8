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
	PawnCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCameraComp"));
	PawnCameraComponent->SetupAttachment(RootComponent);

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
			FVector Start = PlayerCamera->GetComponentLocation();
			FVector End = Start + (PlayerCamera->GetComponentRotation().Vector() * 8000.0f);
			TraceForObjects(Start, End);
		}
		else
		{
			FVector Start;
			FVector Dir;
			FVector End;
			PlayerOne->DeprojectMousePositionToWorld(Start, Dir);
			End = Start + (Dir * 8000.0f);
			TraceForObjects(Start, End);
		}
	}

	if (ATPPlayerController* PlayerTwo = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1)))
	{
		if (UCameraComponent* PlayerCamera = PlayerTwo->GetViewTarget()->FindComponentByClass<UCameraComponent>())
		{
			FVector Start = PlayerCamera->GetComponentLocation();
			FVector End = Start + (PlayerCamera->GetComponentRotation().Vector() * 8000.0f);
			TraceForObjects(Start, End);
		}
		else
		{
			FVector Start;
			FVector Dir;
			FVector End;
			PlayerTwo->DeprojectMousePositionToWorld(Start, Dir);
			End = Start + (Dir * 8000.0f);
			TraceForObjects(Start, End);
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
	Super::CalcCamera(DeltaTime, OutResult);
}

void ATPPawn::TriggerClick()
{
	if (TappedSushi)
	{
		// TODO: Score
	}

	if (TappedSushiSpawner)
	{
		// TODO: Spawn Sushi
	}
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
		if (TappedSushi != HitSushi)
		{
			TappedSushi = HitSushi;
			UE_LOG(LogTemp, Warning, TEXT("Hit Sushi"))
		}

		ATPSushiSpawner* HitSpawner = Cast<ATPSushiSpawner>(HitResult.Actor.Get());
		if (TappedSushiSpawner != HitSpawner)
		{
			TappedSushiSpawner = HitSpawner;
			UE_LOG(LogTemp, Warning, TEXT("Hit Sushi Spawner"))
		}
	}
}

