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
	UFUNCTION(BlueprintPure, Category = "Mechanics|Extra")
		static float MissBulletRandomNumber(float Lower, float Higher);
};
