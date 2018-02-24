// Fill out your copyright notice in the Description page of Project Settings.

#include "TPPlayerState.h"
 
ATPPlayerState::ATPPlayerState()
{
	Score = 0;
	CurrentTurn = 0;
	MaxTurns = 10;
}

void ATPPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void ATPPlayerState::AddScore(int32 Points)
{
	PlayerScore += Points;
}

int32 ATPPlayerState::GetPlayerScore() const
{
	return PlayerScore;
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