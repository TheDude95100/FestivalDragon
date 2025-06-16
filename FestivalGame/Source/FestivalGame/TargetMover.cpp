#include "TargetMover.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

ATargetMover::ATargetMover()
{
    PrimaryActorTick.bCanEverTick = true;

    // Collision root
    Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
    RootComponent = Collision;

    // Mesh
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(RootComponent);

    // Init default values
    MoveSpeed = 1.f;
    CurrentAlpha = 0.f;
    bIsBandit = true;
}

void ATargetMover::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = GetActorLocation();
    EndLocation = StartLocation + FVector(500.f, 0.f, 0.f);
}

void ATargetMover::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    CurrentAlpha += (DeltaTime * MoveSpeed) / (EndLocation - StartLocation).Size();
    CurrentAlpha = FMath::Clamp(CurrentAlpha, 0.f, 1.f);

    FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, CurrentAlpha);
    SetActorLocation(NewLocation);
}

void ATargetMover::InitTarget(const FVector& InStart, const FVector& InEnd, float InSpeed, bool bInIsBandit)
{
    StartLocation = InStart;
    EndLocation = InEnd;
    MoveSpeed = InSpeed;
    bIsBandit = bInIsBandit;
    CurrentAlpha = 0.f;

    SetActorLocation(StartLocation);
}

void ATargetMover::OnHit()
{
    if (bIsBandit)
    {
        UE_LOG(LogTemp, Log, TEXT("Bandit touché ! +10 points"));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Shérif touché ! -10 points"));
    }

    Destroy();  // Ou joue un effet, cache la cible, etc.
}
