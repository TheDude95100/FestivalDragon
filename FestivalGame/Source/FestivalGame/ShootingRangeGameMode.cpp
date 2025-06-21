// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingRangeGameMode.h"
#include "ShootingRangePlayerController.h"

AShootingRangeGameMode::AShootingRangeGameMode()
{
	DefaultPawnClass = nullptr;
	PlayerControllerClass = AShootingRangePlayerController::StaticClass();
}