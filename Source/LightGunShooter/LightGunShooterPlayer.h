// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include <Components/SphereComponent.h>
#include "LightGunShooterPlayer.generated.h"

UCLASS()
class LIGHTGUNSHOOTER_API ALightGunShooterPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALightGunShooterPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(BlueprintReadWrite)
	uint8 Health;

protected:
	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class USphereComponent* Hitbox;

public:
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	bool ShootFromScreenPosition(FVector2D Position, FHitResult& Hit);

};
