// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PARKOURING_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Moving Platform") // Direction and Magnitude Vector
	FVector PlatformVelocity = FVector(0, 0, 200);

	UPROPERTY(VisibleAnywhere, Category = "Moving Platform") // Distance from original (start) point
	double PlatformDistance = -1;

	UPROPERTY(EDitAnywhere, Category = "Moving Platform") // Direction change after this distance
	double AllowedDistance = 500;

	FVector CurrentLocation;
	FVector StartLocation;
};
