// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EGameState.generated.h"
/**
 * 
 */
UENUM(BlueprintType)
enum class EGameState : uint8
{
   	Festival        UMETA(DisplayName = "Festival"),
    ShootingRange   UMETA(DisplayName = "Shooting Range"),
};
