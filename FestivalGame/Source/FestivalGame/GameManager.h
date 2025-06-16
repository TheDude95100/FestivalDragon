// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
   	Festival        UMETA(DisplayName = "Festival"),
    ShootingRange   UMETA(DisplayName = "Shooting Range"),
    // Ajoute les autres mini-jeux ici
};
USTRUCT(BlueprintType)
struct FCameraSetup{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Camera")
	EGameState GameState;

	UPROPERTY(EditAnywhere, Category="Camera")
	AActor* CameraActor;
};
UCLASS()
class FESTIVALGAME_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void StartShootingRange();
	void EndShootingRange();


	void ReturnToFestival();

private:
	void SetGameState(EGameState NewState);

	EGameState CurrentState;

	UPROPERTY(EditAnywhere, Category="Cameras")
	TArray<FCameraSetup> CameraSetups;

};
