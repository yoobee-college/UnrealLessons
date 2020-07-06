// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine.h"
#include "Brick_PC.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"

ABrick_PC::ABrick_PC()
{
}


void ABrick_PC::BeginPlay()
{
	TArray<AActor*> CameraActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActor);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActor[0], Params);

	SpawnNewBall();
}

void ABrick_PC::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &ABrick_PC::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &ABrick_PC::Launch);
}

void ABrick_PC::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn)
	{
		MyPawn->MoveHorizontal(AxisValue);
	}
}

void ABrick_PC::Launch()
{
	MyBall->LaunchBall();
}

void ABrick_PC::SpawnNewBall()
{
	if (!MyBall)
	{
		MyBall = nullptr;
	}
	if (BallObj)
	{
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);
	}
}
