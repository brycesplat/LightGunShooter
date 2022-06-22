// Fill out your copyright notice in the Description page of Project Settings.


#include "LightGunShooter_GunBase.h"

// Sets default values
ALightGunShooter_GunBase::ALightGunShooter_GunBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Position.Add(FVector2D{ 0.0, 0.0 });
}

// Called when the game starts or when spawned
void ALightGunShooter_GunBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightGunShooter_GunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightGunShooter_GunBase::Reload() {
	int missing = MaxClipCount - CurrentAmmoCount;
	if (missing == 0 || AmmoCount == 0) {
		return;
	}
	else if (missing > AmmoCount) {
		CurrentAmmoCount = AmmoCount;
		AmmoCount = 0;
		return;
	}
	else {
		CurrentAmmoCount = MaxClipCount;
		AmmoCount -= missing;
		return;
	}
}