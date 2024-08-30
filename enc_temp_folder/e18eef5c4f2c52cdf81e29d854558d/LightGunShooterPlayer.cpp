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
	CurrentGun = 0;
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

bool ALightGunShooterPlayer::ShootFromScreenPosition(FVector2D Position, ETraceTypeQuery TraceChannel, bool bTraceComplex, FHitResult& Result) {
	APlayerController* ctrl = ALightGunShooterPlayer::GetController<APlayerController>();
	if (ctrl == nullptr) {
		return false;
	}
	double mX, mY;
	ctrl->GetMousePosition(mX, mY);
	Position.X += mX;
	Position.Y += mY;
	bool bHit = false;
	bHit = ctrl->GetHitResultAtScreenPosition(Position, TraceChannel, bTraceComplex, Result);
	

	if (!bHit) {
		Result = FHitResult();
	}
	return bHit;
}

void ALightGunShooterPlayer::Refill(FString Key, int Ammo) {
	(**(Guns.Find(Key))).ReserveAmmo += Ammo;
}


int ALightGunShooterPlayer::DamageHealth(uint8 Damage) {
	Health -= Damage;
	return Health;
}

void ALightGunShooterPlayer::AddHealth(uint8 Heal) {
	if (Health + Heal > 255) {
		Health = 255;
		return;
	}
	Health += Heal;
}

void ALightGunShooterPlayer::EquipNewGun(ALightGunShooter_GunBase* NewGun) {
	if (NewGun == nullptr) {
		return;
	}
	Guns.Add(NewGun->Key, NewGun);
	GunList.Add(1, NewGun->Key);
	CurrentGun = 1;
}

void ALightGunShooterPlayer::EquipOldGun() {
	if (CurrentGun == 0) {
		return;
	}
	
	Guns.Remove(GunList[CurrentGun]);
	GunList.Remove(CurrentGun);
	CurrentGun = 0;
}

void ALightGunShooterPlayer::SwapGuns(int NewGun) {
	if (!GunList.Contains(NewGun)) {
		return;
	}
	CurrentGun = NewGun;
}

void ALightGunShooterPlayer::SwapUpGuns() {
	if (!GunList.Contains(++CurrentGun)) {
		CurrentGun = 0;
	}
}

ALightGunShooter_GunBase* ALightGunShooterPlayer::GetCurrentGun() {
	return (Guns[GunList[CurrentGun]]);
}

void ALightGunShooterPlayer::AddGunToList(TSubclassOf<ALightGunShooter_GunBase> Gun) {
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ActorSpawnParams.Owner = this;

	ALightGunShooter_GunBase* spawn =  GetWorld()->SpawnActor<ALightGunShooter_GunBase>(Gun, FVector{0,0,0}, FRotator{0,0,0}, ActorSpawnParams);

	Guns.Add(spawn->Key, spawn);
	GunList.Add(GunList.Num(), spawn->Key);
}