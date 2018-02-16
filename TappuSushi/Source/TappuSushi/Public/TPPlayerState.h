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

	UFUNCTION(BlueprintCallable, Category = Player)
	void AddScore(int32 Points);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
	int32 PlayerScore;

	UFUNCTION(BlueprintCallable, Category = Player)
	void AddTurn();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Player)
	int32 GetTurn() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
	int32 CurrentTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	int32 MaxTurns;

	UFUNCTION(BlueprintCallable, Category = Player)
	void TakeLives();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Player)
	int32 Lives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	int32 MaxLives;
};
