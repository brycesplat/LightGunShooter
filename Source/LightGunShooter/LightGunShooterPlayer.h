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
	TMap<FString, ALightGunShooter_GunBase*> Guns;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int, FString> GunList;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CurrentGun;

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
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void EquipNewGun(ALightGunShooter_GunBase* NewGun);
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void EquipOldGun();
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void SwapGuns(int NewGun);
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void SwapUpGuns();
	UFUNCTION(BlueprintPure, Category = "Mechanics")
	ALightGunShooter_GunBase* GetCurrentGun();
};
