// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanPawn.h"
#include "Food.h"

// Sets default values
APacmanPawn::APacmanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

// Called every frame
void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Frozen) {
		AddMovementInput(GetActorForwardVector());
	}

}

// Called to bind functionality to input
void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APacmanPawn::SetDirection(const FVector Direction)
{

	if (Direction == FVector::UpVector) {
		SetActorRotation(FRotator(0.0f, 270.0f, 0.0f));
	}
	else if (Direction == FVector::DownVector) {
		SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	}
	else if (Direction == FVector::RightVector) {
		SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (Direction == FVector::LeftVector) {
		SetActorRotation(FRotator(0.0f, 180.0f, 180.0f));
	}
}

void APacmanPawn::OnOverlapBegin(AActor* PlyaerActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Food.Regular")) {
		Cast<AFood>(OtherActor)->Consume();
	}

	if (OtherActor->ActorHasTag("Food.PowerUp")) {
		Cast<AFood>(OtherActor)->Consume();
	}
}

