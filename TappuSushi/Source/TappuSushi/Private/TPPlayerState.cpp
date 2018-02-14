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

	if (CurrentTurn == 0 && Lives == 0)
	{
		CurrentTurn = MaxTurns;
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

void ATPPlayerState::TakeLives()
{
	if (Lives <= MaxLives)
	{
		Lives--;
	}
}
