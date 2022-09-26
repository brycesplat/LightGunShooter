// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AEnemyBase::AEnemyBase(bool HealthBased, bool DropAmmo) {
	PrimaryActorTick.bCanEverTick = true;
	this->HealthBased = HealthBased;
	CanDropAmmo = DropAmmo;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::TakeDamage(float damage) {
	HitHealth--;
	Hits++;
	Health -= damage;
}

bool AEnemyBase::IsDead(){
	if((HitHealth <= 0 && !HealthBased)
		|| (Health <= 0 && HealthBased)){
		return true;
	} 
	return false;
}

bool AEnemyBase::TakeDamageAndDie(float damage) {
	TakeDamage(damage);
	return IsDead();
}