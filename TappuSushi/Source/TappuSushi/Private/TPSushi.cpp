// Fill out your copyright notice in the Description page of Project Settings.

#include "TPSushi.h"
#include "TPPlayerController.h"
#include "TPPlayerState.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

ATPSushi::ATPSushi()
{
	DummyRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DummyRoot"));
	RootComponent = DummyRootComponent;

	SushiSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SushiSprite"));
	SushiSprite->SetupAttachment(DummyRootComponent);
	SushiSprite->OnClicked.AddDynamic(this, &ATPSushi::SushiClicked);
	SushiSprite->OnInputTouchBegin.AddDynamic(this, &ATPSushi::OnFingerPressed);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MoveComp"));
	MovementComponent->UpdatedComponent = SushiSprite;
}

void ATPSushi::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(2.5f);
}

void ATPSushi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATPSushi::SushiClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
	HandleClicked();
}

void ATPSushi::OnFingerPressed(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	HandleClicked();
}

void ATPSushi::HandleClicked()
{
	CalculateScore();
}

void ATPSushi::CalculateScore()
{
	UE_LOG(LogTemp, Warning, TEXT("Score"))

	// Get the currently active player
	ATPPlayerController* PlayerOne = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	ATPPlayerController* PlayerTwo = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerOne)
	{
		// Get player one's player state 
		ATPPlayerState* PlayerOneState = Cast<ATPPlayerState>(PlayerOne->PlayerState);
		PlayerOneState->AddScore(100);
	}
	else if (PlayerTwo)
	{
		ATPPlayerState* PlayerTwoState = Cast<ATPPlayerState>(PlayerTwo->PlayerState);
		PlayerTwoState->AddScore(100);
	}
}

