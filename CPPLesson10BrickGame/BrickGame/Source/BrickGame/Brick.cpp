// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxComp->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));
	RootComponent = BoxComp;
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball"))
	{
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce + 0.1f);
		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);
	}
}

void ABrick::DestroyBrick()
{
	this->Destroy();
}


