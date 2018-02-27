// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPGameMode.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATPGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sounds)
	USoundBase* GameMusic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UMG)
	TSubclassOf<UUserWidget> TutorialWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UMG)
	TSubclassOf<UUserWidget> LossWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UMG)
	TSubclassOf<UUserWidget> WinWidget;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};
