#include "ShootingRangePlayerController.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "GameManager.h"

void AShootingRangePlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Ajouter le contexte d'input
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (InputMapping)
            {
                Subsystem->AddMappingContext(InputMapping, 0);
            }
        }
    }

    // Binder les actions
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        if (StartRangeAction)
        {
            EnhancedInputComponent->BindAction(StartRangeAction, ETriggerEvent::Triggered, this, &AShootingRangePlayerController::OnStartRange);
        }

        if (EndRangeAction)
        {
            EnhancedInputComponent->BindAction(EndRangeAction, ETriggerEvent::Triggered, this, &AShootingRangePlayerController::OnEndRange);
        }
    }
}

void AShootingRangePlayerController::OnStartRange(const FInputActionInstance& Instance)
{
    if (AGameManager* GM = GetGameManager())
    {
        GM->StartShootingRange();
    }
}

void AShootingRangePlayerController::OnEndRange(const FInputActionInstance& Instance)
{
    if (AGameManager* GM = GetGameManager())
    {
        GM->EndShootingRange();
    }
}

AGameManager* AShootingRangePlayerController::GetGameManager()
{
    for (TActorIterator<AGameManager> It(GetWorld()); It; ++It)
    {
        return *It;
    }
    return nullptr;
}
