// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPPlayerController.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATPPlayerController();

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;

	void SwapPlayerID(bool bSwap);

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void TriggerClick();

	UFUNCTION(BlueprintCallable, Category = Pawn)
	virtual void TraceForObjects(const FVector Start, const FVector& End);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn)
	bool bDrawDebugHelpers;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	class ATPSushi* TappedSushi;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	class ATPSushiSpawner* TappedSushiSpawner;
};
