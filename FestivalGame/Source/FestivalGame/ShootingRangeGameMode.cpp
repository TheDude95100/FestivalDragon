// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingRangeGameMode.h"
#include "ShootingRangePlayerController.h"

AShootingRangeGameMode::AShootingRangeGameMode()
{
	DefaultPawnClass = nullptr; // Pas de pawn, juste la caméra qu’on contrôle manuellement
	PlayerControllerClass = AShootingRangePlayerController::StaticClass(); // Celui par défaut suffit
}