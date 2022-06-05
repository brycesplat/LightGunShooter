// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LightGunShooterBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTGUNSHOOTER_API ULightGunShooterBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	struct WeaponDetails
	{
		TArray<FVector2D> Modifier = {FVector2D(0.0,0.0)};
		float Damage;
		uint8 ClipSize;
		uint32 MaxAmmoCount;
		uint32 CurrentAmmoCount;
	};
};
