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
	if (!LimitedAmmo) {
		if (ChamberAmmo && CurrentAmmo > 0) {
			CurrentAmmo = MaxClipCount + 1;
			return;
		}
		CurrentAmmo = MaxClipCount;
		return;
	}

	if (ReserveAmmo <= 0) {
		return;
	}

	int missing = MaxClipCount - CurrentAmmo;
	if (missing == 0) {
		if (ChamberAmmo) {
			CurrentAmmo++;
			ReserveAmmo--;
		}
		return;
	}
	else if (missing < ReserveAmmo) {
		if (ChamberAmmo && CurrentAmmo > 0) {
			CurrentAmmo = MaxClipCount + 1;
			ReserveAmmo -= missing + 1;
			return;
		}
		CurrentAmmo = MaxClipCount;
		ReserveAmmo -= missing;
		return;
	}
	else {
		CurrentAmmo += ReserveAmmo;
		ReserveAmmo = 0;
	}
}

bool ALightGunShooter_GunBase::CheckAmmo() {
	if (CurrentAmmo > 0) {
		CurrentAmmo--;
		return true;
	}
	return false;
}

void ALightGunShooter_GunBase::FireGun_Implementation() {
	return;
}

void ALightGunShooter_GunBase::StopFiringGun_Implementation() {
	return;
}