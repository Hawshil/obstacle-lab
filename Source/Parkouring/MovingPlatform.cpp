// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	CurrentLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	CurrentLocation += (PlatformVelocity * DeltaTime); // Deltatime to avoid frame rate dependency (same speed for every device)
	SetActorLocation(CurrentLocation);				   // Update Platform location every frame

	PlatformDistance = FVector::Dist(StartLocation, CurrentLocation); // Calculate distance from start location (irrespective of moving direction)

	if (ShouldPlatformChangeDirection())
	{
		FVector MovingDirection = PlatformVelocity.GetSafeNormal();

		// StartLocation = CurrentLocation;     // INACCURATE due to if condition (overthrow always)
		StartLocation += MovingDirection * AllowedDistance; // To make the distance zero, velocity normal * next start location
		SetActorLocation(StartLocation);

		PlatformVelocity = -PlatformVelocity; // Change direction
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	// SetActorRotation() is buggy
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformChangeDirection() const
{
	return PlatformDistance > AllowedDistance;
}