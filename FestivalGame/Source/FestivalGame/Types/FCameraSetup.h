// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EGameState.h"
#include "GameFramework/Actor.h"
#include "FCameraSetup.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FESTIVALGAME_API FCameraSetup{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Camera")
	EGameState GameState;

	UPROPERTY(EditAnywhere, Category="Camera")
	AActor* CameraActor;
};