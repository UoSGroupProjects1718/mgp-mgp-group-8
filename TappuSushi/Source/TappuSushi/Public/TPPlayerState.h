// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TPPlayerState.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ATPPlayerState();

	virtual void BeginPlay();

	/** Add points, to players current score. */
	UFUNCTION(BlueprintCallable, Category = Player)
	void AddScore(int32 Points);

	/** Get the player score. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Player)
	int32 GetPlayerScore() const;
	
	/** Add turns, each time we switch player. */
	UFUNCTION(BlueprintCallable, Category = Player)
	void AddTurn();

	/** Get the current player turn. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Player)
	int32 GetTurn() const;

	/** Decrement lives each time, a player misses. */
	UFUNCTION(BlueprintCallable, Category = Player)
	void TakeLives();

	/** Get the number of lives this player currently has. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Player)
	int32 GetLives() const;

protected:
	/** The players current score.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
	int32 PlayerScore;

	/** The players current turn. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
	int32 CurrentTurn;

	/** The max number of turns each player has. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	int32 MaxTurns;

	/** The player current number of lives. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
	int32 Lives;

	/** The max number of lives each player has. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	int32 MaxLives;
};
