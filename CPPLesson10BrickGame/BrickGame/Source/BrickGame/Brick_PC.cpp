// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick_PC.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"

ABrick_PC::ABrick_PC()
{
}


void ABrick_PC::BeginPlay()
{
	TArray<AActor*> CameraActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActor);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActor[0], Params);
}

void ABrick_PC::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &ABrick_PC::MoveHorizontal);
}

void ABrick_PC::MoveHorizontal(float AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn)
	{
		MyPawn->MoveHorizontal(AxisValue);
	}
}
