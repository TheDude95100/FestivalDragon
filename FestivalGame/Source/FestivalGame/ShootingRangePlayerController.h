// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"                 
#include "InputMappingContext.h" 
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "ShootingRangePlayerController.generated.h"

class AGameManager;

UCLASS()
class FESTIVALGAME_API AShootingRangePlayerController : public APlayerController
{
	GENERATED_BODY()
	
	protected:
		virtual void BeginPlay() override;

	private:
    void OnStartRange(const FInputActionInstance& Instance);
    void OnEndRange(const FInputActionInstance& Instance);

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* StartRangeAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputAction* EndRangeAction;

	AGameManager* GetGameManager();
};
