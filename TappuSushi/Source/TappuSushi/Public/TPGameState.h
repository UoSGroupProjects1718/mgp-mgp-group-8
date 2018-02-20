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

	/** Switch player each turn */
	UFUNCTION(BlueprintCallable, Category = Game)
	void SwitchPlayer();

	UFUNCTION(BlueprintCallable, Category=Game)
	void AddRound();

	UFUNCTION(BlueprintCallable Category = Game)
	void GameOver();

	UFUNCTION(BlueprintCallable, Category = Game)
	void GameRestart();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Game)
	int32 Rounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Game)
	int32 MaxRounds;

	UPROPERTY()
	bool bSwitchPlayer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Game)
	bool bIsGameWon;

	FTimerHandle TurnHandle;
};
