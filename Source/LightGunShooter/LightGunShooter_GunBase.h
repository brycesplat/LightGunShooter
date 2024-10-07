// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightGunShooter_GunBase.generated.h"

UCLASS()
class LIGHTGUNSHOOTER_API ALightGunShooter_GunBase : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool LimitedAmmo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ChamberAmmo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool Automatic;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsRandomShots;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NumOfShots;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CurrentAmmo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxClipCount;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int ReserveAmmo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RateOfFire;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector2D> Position {FVector2D {0,0}};
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Key;

public:	
	// Sets default values for this actor's properties
	ALightGunShooter_GunBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Mechanics")
	void Reload();
	UFUNCTION(BlueprintPure, Category = "Mechanics")
	bool CheckAmmo();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mechanics")
	void FireGun();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mechanics")
	void StopFiringGun();
};
