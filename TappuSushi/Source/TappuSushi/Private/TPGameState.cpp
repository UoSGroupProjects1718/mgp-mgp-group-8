// Fill out your copyright notice in the Description page of Project Settings.

#include "TPGameState.h"
#include "TPPlayerController.h"
#include "TPPlayerState.h"
#include "Kismet/GameplayStatics.h"

ATPGameState::ATPGameState()
{
	Rounds = 0;
	MaxRounds = 10;
}

void ATPGameState::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TurnHandle, this, &ATPGameState::SwitchPlayer, 10.0f, true);
}

void ATPGameState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (EEndPlayReason::Quit)
	{
		GetWorld()->GetTimerManager().ClearTimer(TurnHandle);
	}
}

void ATPGameState::SwitchPlayer()
{
	// Flip-flop between two players for the duration of the game
	// This code freezes with no errors in the debugger, great :(
	bool bLocalCheck = true;

	if (bLocalCheck)
	{
		ATPPlayerController* Player1 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
		if (Player1)
		{
			UGameplayStatics::SetPlayerControllerID(Player1, 1);
			bLocalCheck = false;

			UE_LOG(LogTemp, Warning, TEXT("Player1"));
		}
	}
	else
	{
		ATPPlayerController* Player2 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1));
		if (Player2)
		{
			UGameplayStatics::SetPlayerControllerID(Player2, 0);
			bLocalCheck = true;

			UE_LOG(LogTemp, Warning, TEXT("Player2"));
		}
	}
}

void ATPGameState::AddRound()
{
	// Only add a round if both players have taken both of their turns
	ATPPlayerController* Player1 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	ATPPlayerController* Player2 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1));
	if (Player1 && Player2)
	{
		ATPPlayerState* Player1State = Cast<ATPPlayerState>(Player1->PlayerState);
		ATPPlayerState* Player2State = Cast<ATPPlayerState>(Player2->PlayerState);
		if (Player1State && Player2State)
		{
			if (Player1State->CurrentTurn == Player2State->CurrentTurn)
			{
				Rounds++;
			}
		}
	}
}
