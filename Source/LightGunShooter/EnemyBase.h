// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LightGunShooter_GunBase.h"
#include "LightGunShooterPlayer.h"
#include "EnemyBase.generated.h"


UCLASS()
class LIGHTGUNSHOOTER_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();
	AEnemyBase(bool HealthBased, bool DropAmmo);

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
		float Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int HitHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int Hits;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float AttackChance;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<FString, int> Drops;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<int, FString> DropPosition;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		uint8 DropNum;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool CanDropAmmo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool HealthBased;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float FireHitChance;

public:
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
		void TakeDamageTest(float damage);
	UFUNCTION(BlueprintPure, Category = "Mechanics")
		bool IsDead();
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
		bool TakeDamageAndDie(float damage);
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
		void RefillPlayerAmmo(ALightGunShooterPlayer* PlayerCharacter);
};
