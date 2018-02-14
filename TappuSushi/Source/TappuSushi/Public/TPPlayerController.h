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

	virtual void SetupInputComponent() override;

	UFUNCTION()
	void SwitchPlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Controller)
	bool bIsSwitched;
};
