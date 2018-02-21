// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPSushi.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPSushi : public AActor
{
	GENERATED_BODY()
	
public:	
	ATPSushi();

private:
	/** Our dummy root component. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprite, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRootComponent;

	/** The Sushi sprite. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprite, meta = (AllowPrivateAccess = "true"))
	class UPaperSpriteComponent* SushiSprite;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** The current velocity, used to calculate the score. */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Actor)
	float CurrentVelocity;
};
