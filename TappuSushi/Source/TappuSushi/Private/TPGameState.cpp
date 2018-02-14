// Fill out your copyright notice in the Description page of Project Settings.

#include "TPGameState.h"
#include "TPPlayerController.h"
#include "TPPlayerState.h"
#include "Kismet/GameplayStatics.h"

ATPGameState::ATPGameState()
{

}

void ATPGameState::AddRound()
{
	int32 RoundCheck;

	// Only add a round if both players have taken both of their turns
	ATPPlayerController* Player1 = Cast<ATPPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (Player1)
	{
		ATPPlayerState* Player1State = Cast<ATPPlayerState>(Player1->PlayerState);
	}
}
