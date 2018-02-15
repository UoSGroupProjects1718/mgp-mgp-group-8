// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TPMenuGameMode.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATPMenuGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UMG)
	TSubclassOf<class UUserWidget> MainMenuWidget;
	
	UPROPERTY()
	class UUserWidget* CurrentWidget;

	UFUNCTION(BlueprintImplementableEvent)
	void ShowMainMenu();
	void ShowMainMenu_Implementation();

};
