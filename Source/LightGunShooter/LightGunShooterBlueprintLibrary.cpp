// Fill out your copyright notice in the Description page of Project Settings.


#include "LightGunShooterBlueprintLibrary.h"

float ULightGunShooterBlueprintLibrary::MissBulletRandomNumber(float Lower, float Higher)
{
	int choice = FMath::RandRange(0, 1);
	float deviation = 0.0f;

	switch (choice)
	{ 
	case 0:
		deviation = FMath::RandRange(Lower, Higher);
		break;
	case 1:
		Lower *= -1;
		Higher *= -1;
		deviation = FMath::RandRange(Lower, Higher);
		break;
	default:
		deviation = FMath::RandRange(Lower, Higher);
		break;
	}

	return deviation;
}