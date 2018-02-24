// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushiSpawner.h"
#include "TPSushi.h"
#include "TPPlayerController.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

ATPSushiSpawner::ATPSushiSpawner()
{
	DummyRootComp = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRootComp"));
	RootComponent = DummyRootComp;

	SpawnSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpawnSprite"));
	SpawnSprite->SetupAttachment(DummyRootComp);
	SpawnSprite->OnClicked.AddDynamic(this, &ATPSushiSpawner::SpawnerClicked);
	SpawnSprite->OnInputTouchBegin.AddDynamic(this, &ATPSushiSpawner::OnFingerPressed);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void ATPSushiSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void ATPSushiSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ATPPlayerController* Player = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (UCameraComponent* PlayerCamera = Player->GetViewTarget()->FindComponentByClass<UCameraComponent>())
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
		Player->DeprojectMousePositionToWorld(Start, Dir);
		End = Start + (Dir * 8000.0f);
		TraceForSpawner(Start, End);
	}
}

void ATPSushiSpawner::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("TriggerClick", EInputEvent::IE_Pressed, this, &ATPSushiSpawner::TriggerClick);
}

void ATPSushiSpawner::TriggerClick()
{
	if (SpawnerFocus)
	{
		SpawnerFocus->HandleClicked();
	}
}

void ATPSushiSpawner::TraceForSpawner(const FVector Start, const FVector& End)
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

void ATPSushiSpawner::SpawnerClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
	HandleClicked();
}

void ATPSushiSpawner::OnFingerPressed(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	HandleClicked();
}

void ATPSushiSpawner::HandleClicked()
{
	SpawnSushi();
}

void ATPSushiSpawner::SpawnSushi()
{
	for (int32 i = 0; i < SushiClasses.Num(); i++)
	{
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<ATPSushi>(SushiClasses[i], GetActorTransform(), SpawnParams);
	}
}

