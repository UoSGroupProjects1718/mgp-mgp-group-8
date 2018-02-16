// Fill out your copyright notice in the Description page of Project Settings.

#include "TPPlayerState.h"
 
ATPPlayerState::ATPPlayerState()
{
	Score = 0;
	CurrentTurn = 0;
	MaxTurns = 10;
	Lives = 0;
	MaxLives = 3;
}

void ATPPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if (Lives == 0)
	{
		Lives = MaxLives;
	}
}

void ATPPlayerState::AddScore(int32 Points)
{
	PlayerScore += Points;
}

void ATPPlayerState::AddTurn()
{
	if (CurrentTurn <= MaxTurns)
	{
		CurrentTurn++;
	}
}

int32 ATPPlayerState::GetTurn() const
{
	return CurrentTurn;
}

void ATPPlayerState::TakeLives()
{
	if (Lives >= 0)
	{
		Lives--;
	}
}
