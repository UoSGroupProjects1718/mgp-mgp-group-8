// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TPPawn.generated.h"

UCLASS(config=Game)
class TAPPUSUSHI_API ATPPawn : public APawn
{
	GENERATED_BODY()

public:
	ATPPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult) override;
	
protected:
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
