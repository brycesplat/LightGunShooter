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

void ALightGunShooterPlayer::ShootFromScreenPosition(FVector2D Position, FHitResult& Result, bool& Success) {
	APlayerController* ctrl = ALightGunShooterPlayer::GetController<APlayerController>();
	if (ctrl == nullptr) {
		Success = false;
		return;
	}

	FHitResult Hit;

	if (!(ctrl->GetHitResultAtScreenPosition(Position, ECC_Visibility, true, Hit))) {
		Success = false;
		return;
	}

	Result = Hit;
	Success = true;
	return;
}

void ALightGunShooterPlayer::AddToMousePosition(FVector2D Modifier, FVector2D& Result, bool& Success) {
	APlayerController* ctrl = ALightGunShooterPlayer::GetController<APlayerController>();
	if (ctrl == nullptr) {
		Success = false;
		return;
	}

	float x, y;
	ctrl->GetMousePosition(x, y);
	Modifier.X += x;
	Modifier.Y += y;

	Success = true;
	Result = Modifier;
	return;
}