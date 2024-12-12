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
	UFUNCTION(BlueprintCallable, Category = "Mechanics|Extra")
	static void MissBulletRandomNumber(float Pitch, float Yaw, float Deviation, float SafeRange, float& ReturnPitch, float& ReturnYaw);

	/*
	UFUNCTION(BlueprintCallable, Category = "Mechanics|Extra")
	static void InitializeUINavigationConfig();
	*/
};
