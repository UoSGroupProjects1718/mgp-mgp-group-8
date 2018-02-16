// Fill out your copyright notice in the Description page of Project Settings.

#include "TPHUD.h"
#include "Blueprint/UserWidget.h"

ATPHUD::ATPHUD()
{

}

void ATPHUD::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidget)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidget);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
