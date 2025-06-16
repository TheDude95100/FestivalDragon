// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetMover.generated.h"

UCLASS()
class FESTIVALGAME_API ATargetMover : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetMover();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InitTarget(const FVector& InStart, const FVector& InEnd, float InSpeed, bool bInIsBandit);
	void OnHit();

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* Collision;

	FVector StartLocation;
	FVector EndLocation;
	float MoveSpeed;
	float CurrentAlpha;

	bool bIsBandit;

};
