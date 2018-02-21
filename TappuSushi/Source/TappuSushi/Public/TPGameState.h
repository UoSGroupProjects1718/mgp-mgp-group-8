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

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/** Switch player each turn. */
	UFUNCTION(BlueprintCallable, Category = Game)
	void SwitchPlayer();

	/** Add a round when both players have completed their turns. */
	UFUNCTION(BlueprintCallable, Category = Game)
	void AddRound();

	/** Called when the game is over. */
	UFUNCTION(BlueprintCallable, Category = Game)
	void GameOver();

	/** Called when the game restarts. */
	UFUNCTION(BlueprintCallable, Category = Game)
	void GameRestart();
	
protected:
	/** The current number of rounds the game has. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Game)
	int32 Rounds;

	/** The maximum number of rounds the game has. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Game)
	int32 MaxRounds;

	/** An internal boolean to control player switching. */
	UPROPERTY(Transient)
	bool bSwitchPlayer;

	/** Check to see if the game is won. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Game)
	bool bIsGameWon;

	FTimerHandle TurnHandle;
};
