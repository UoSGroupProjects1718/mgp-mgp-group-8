// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TPSushiSpawner.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPSushiSpawner : public APawn
{
	GENERATED_BODY()
	
public:	
	ATPSushiSpawner();

private:
	/** A Dummy root component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprite, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRootComp;

	/** A Sprite to represent our spawner in the level. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprite, meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* SpawnSprite;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void TriggerClick();

	UFUNCTION()
	void TraceForSpawner(const FVector Start, const FVector& End);

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	class ATPSushiSpawner* SpawnerFocus;

	/** Handle the spawner being clicked */
	UFUNCTION()
	void SpawnerClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	/** Handle the spawn being touched */
	UFUNCTION()
	void OnFingerPressed(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	/** Handle touch events */
	UFUNCTION()
	void HandleClicked();

	/** Spawn Sushi called touch event. */
	UFUNCTION(BlueprintCallable, Category = Actor)
	void SpawnSushi();
	
	/** The Sushi class to spawn. */
	UPROPERTY(EditAnywhere, NoClear, BlueprintReadWrite, Category = Actor)
	TArray<TSubclassOf<class ATPSushi>> SushiClasses;
};
