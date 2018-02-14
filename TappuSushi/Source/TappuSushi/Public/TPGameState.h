// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TPGameState.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ATPGameState();

	void AddRound();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Game)
	int32 Rounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Game)
	int32 MaxRounds;
};
