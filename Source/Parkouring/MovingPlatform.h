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

	UPROPERTY(EditAnywhere)
	int32 temp = 100;

	UPROPERTY(EditAnywhere)
	int32 A = 0;

	UPROPERTY(EditAnywhere)
	int32 B = 0;

	UPROPERTY(EditAnywhere)
	int32 sum = 0;

	UPROPERTY(EditAnywhere)
	float deci = 2.5;
	

	UPROPERTY(EditAnywhere)
	bool hasGF = false;
};
