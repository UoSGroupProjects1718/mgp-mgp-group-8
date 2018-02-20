// Fill out your copyright notice in the Description page of Project Settings.

#include "TPGameState.h"
#include "TPPlayerController.h"
#include "TPPlayerState.h"
#include "Kismet/GameplayStatics.h"

ATPGameState::ATPGameState()
{
	Rounds = 0;
	MaxRounds = 10;
	bSwitchPlayer = true;
	bIsGameWon = false;
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
	// This code freezes with no errors in the debugger, great :( // Fixed by removing while loop, no while loops in timers!  
	if (bSwitchPlayer == true)
	{
		ATPPlayerController* Player1 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
		if (Player1)
		{
			UGameplayStatics::SetPlayerControllerID(Player1, 1);
			bSwitchPlayer = false;

			UE_LOG(LogTemp, Warning, TEXT("Player1"));

			// Get player 1 state and add turn
			ATPPlayerState* Player1State = Cast<ATPPlayerState>(Player1->PlayerState);
			if (Player1State)
			{
				Player1State->AddTurn();
				UE_LOG(LogTemp, Warning, TEXT("Player1 Turn: %d"), Player1State->GetTurn())
			}
		}

		// Check to see if we can add round
		AddRound();
	}
	else if(bSwitchPlayer == false)
	{
		ATPPlayerController* Player2 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 1));
		if (Player2)
		{
			UGameplayStatics::SetPlayerControllerID(Player2, 0);
			bSwitchPlayer = true;

			UE_LOG(LogTemp, Warning, TEXT("Player2"));

			// Get player 2 state and add turn
			ATPPlayerState* Player2State = Cast<ATPPlayerState>(Player2->PlayerState);
			if (Player2State)
			{
				Player2State->AddTurn();
				UE_LOG(LogTemp, Warning, TEXT("Player2 Turn: %d"), Player2State->GetTurn())
			}

			// Check to see if we can add round
			AddRound();
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
			if (Player1State->GetTurn() == Player2State->GetTurn())
			{
				if (Rounds <= MaxRounds)
				{
					Rounds++;
					UE_LOG(LogTemp, Warning, TEXT("Round: %d"), this->Rounds)
				}
			}
		}
	}
}

void ATPGameState::GameOver()
{
	GetWorldTimerManager().ClearTimer(TurnHandle);

	// TODO: Display final score widget, notify which player has one
}

void ATPGameState::GameRestart()
{
	
}
