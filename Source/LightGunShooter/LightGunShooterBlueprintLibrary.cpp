// Fill out your copyright notice in the Description page of Project Settings.


#include "LightGunShooterBlueprintLibrary.h"

float ULightGunShooterBlueprintLibrary::MissBulletRandomNumber(float Pitch, float Yaw)
{
	int choice = FMath::RandRange(0, 1);
	float deviation = 0.0f;

	switch (choice)
	{ 
	case 0:
		deviation = FMath::RandRange(Pitch, Yaw);
		break;
	case 1:
		Pitch *= -1;
		Yaw *= -1;
		deviation = FMath::RandRange(Pitch, Yaw);
		break;
	default:
		deviation = FMath::RandRange(Pitch, Yaw);
		break;
	}

	return deviation;
}