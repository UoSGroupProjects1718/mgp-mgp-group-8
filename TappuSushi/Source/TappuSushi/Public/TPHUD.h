// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TPHUD.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ATPHUD();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UMG)
	TSubclassOf<class UUserWidget> HUDWidget;

	UPROPERTY(Transient)
	class UUserWidget* CurrentWidget;
};
