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
	UPROPERTY(BlueprintReadWrite)
	int CurrentAmmoCount;
	UPROPERTY(BlueprintReadWrite)
	int MaxClipCount;
	UPROPERTY(BlueprintReadWrite)
	int AmmoCount;
	UPROPERTY(BlueprintReadWrite)
	float Damage;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> Position;

public:	
	// Sets default values for this actor's properties
	ALightGunShooter_GunBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Mechanics")
	void Reload();
};
