// Fill out your copyright notice in the Description page of Project Settings.


#include "LightGunShooterPlayer.h"

// Sets default values
ALightGunShooterPlayer::ALightGunShooterPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Hitbox = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));

	Camera->SetupAttachment(RootComponent);
	Hitbox->SetupAttachment(Camera);

	Health = 3;
	CurrentGun = "INSERT SOMETHING HERE!";
}

// Called when the game starts or when spawned
void ALightGunShooterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightGunShooterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALightGunShooterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ALightGunShooterPlayer::ShootFromScreenPosition(FVector2D Position, FHitResult& Result) {
	APlayerController* ctrl = ALightGunShooterPlayer::GetController<APlayerController>();
	if (ctrl == nullptr) {
		return false;
	}

	FHitResult Hit;

	if (!(ctrl->GetHitResultAtScreenPosition(Position, ECC_Visibility, true, Hit))) {
		return false;
	}

	Result = Hit;
	return true;
}

void ALightGunShooterPlayer::Refill(FString Key, int Ammo) {
	(**(Guns.Find(Key))).AmmoCount += Ammo;
}

//TODO: DamageHealth should check if player dies.
int ALightGunShooterPlayer::DamageHealth(uint8 Damage) {
	return Health;
}

void ALightGunShooterPlayer::AddHealth(uint8 Heal) {
	if (Health + Heal > 255) {
		Health = 255;
		return;
	}
	Health += Heal;
}