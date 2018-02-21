// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPSushiSpawner.generated.h"

UCLASS()
class TAPPUSUSHI_API ATPSushiSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ATPSushiSpawner();

private:
	// Does not compile on android :(
//#if WITH_EDITORONLY_DATA
//	UPROPERTY()
//	class UBillboardComponent* BillboardComp;
//#endif

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/** Spawn Sushi called via timer. */
	UFUNCTION(BlueprintCallable, Category = Actor)
	void SpawnSushi();
	
	/** The Sushi class to spawn. */
	UPROPERTY(EditAnywhere, NoClear, BlueprintReadWrite, Category = Actor)
	TArray<TSubclassOf<class ATPSushi>> SushiClasses;

	UPROPERTY(Transient)
	class ATPSushi* SushiActor;

	FTimerHandle SpawnHandle;
};
