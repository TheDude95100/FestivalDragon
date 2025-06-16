// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraActor.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CurrentState = EGameState::Festival;
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	SetGameState(EGameState::Festival);
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameManager::SetGameState(EGameState NewState){
	if(CurrentState != NewState)
	{
		CurrentState = NewState;
		UE_LOG(LogTemp,Log, TEXT("Game state changed to: %s"), * UEnum::GetValueAsString(CurrentState));

		for (const FCameraSetup& Setup : CameraSetups)
		{
				if (Setup.GameState == CurrentState && Setup.CameraActor)
				{
					APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
					if (PC)
					{
						PC->SetViewTarget(Setup.CameraActor);
						UE_LOG(LogTemp, Log, TEXT("Switched to camera for state: %s"), *UEnum::GetValueAsString(CurrentState));
					}
					break;
				}
		}
		switch (CurrentState)
		{
		case EGameState::Festival:
			//reset cam et état du joueur pour l'exploration
			break;
		case EGameState::ShootingRange:
			//lance le mini-jeu
			break;
		default:
			break;
		}
	}
}

void AGameManager::StartShootingRange()
{
	SetGameState(EGameState::ShootingRange);
}

void AGameManager::EndShootingRange()
{
	// Traitement fin de jeu
	SetGameState(EGameState::Festival);
}