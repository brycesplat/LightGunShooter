// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LightGunShooter_GunBase.h"
#include "EnemyBase.generated.h"


UCLASS()
class LIGHTGUNSHOOTER_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

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
	bool CanDropAmmo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool healthBased;

public:
	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void TakeDamage(float damage);
};
