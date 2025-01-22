// Fill out your copyright notice in the Description page of Project Settings.


#include "LightGunShooterBlueprintLibrary.h"
#include "Framework/Application/NavigationConfig.h"
#include "Framework/Application/SlateApplication.h"

void ULightGunShooterBlueprintLibrary::MissBulletRandomNumber(float Pitch, float Yaw, float Deviation, float SafeRange, float& ReturnPitch, float& ReturnYaw)
{
	float pitchDev = FMath::FRandRange(-Deviation, Deviation);
	ReturnPitch = Pitch + pitchDev;

	if (pitchDev >= -SafeRange && pitchDev <= SafeRange)
	{	
		int choice = FMath::RandRange(0, 1);
		switch (choice)
		{
		case 0:
			ReturnYaw = Yaw + FMath::FRandRange(-Deviation, -SafeRange);
			return;
		case 1:
			ReturnYaw = Yaw + FMath::FRandRange(SafeRange, Deviation);
			return;
			break;
		}
	}

	ReturnYaw = Yaw + FMath::FRandRange(-Deviation, Deviation);
}