// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include <Components/SphereComponent.h>
#include "LightGunShooter_GunBase.h"
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

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8 Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CurrentGun;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, ALightGunShooter_GunBase*> Guns;

protected:
	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		class USphereComponent* Hitbox;

public:
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	bool ShootFromScreenPosition(FVector2D Position, FHitResult& Hit);
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void Refill(FString Key, int Ammo);
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	int DamageHealth(uint8 Damage);
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void AddHealth(uint8 Heal);
};
