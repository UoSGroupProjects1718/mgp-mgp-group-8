// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "TPCameraActor.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPCameraActor : public ACameraActor
{
	GENERATED_BODY()

public:
	ATPCameraActor();
	
	virtual void BeginPlay() override;
};
