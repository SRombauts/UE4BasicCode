// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"
#include "BasicCodeGameMode.h"
#include "BasicCodePlayerController.h"

//
ABasicCodeGameMode::ABasicCodeGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	if (GEngine)
	{
		UE_LOG(GameInit, Log, TEXT("ABasicCodeGameMode: ctor"));
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Blue, FString("ABasicCodeGameMode: ctor"));
	}
	else
	{
		UE_LOG(GameInit, Warning, TEXT("ABasicCodeGameMode: ctor (GEngine null)"));
	}

	PlayerControllerClass = ABasicCodePlayerController::StaticClass();
}

void ABasicCodeGameMode::StartPlay()
{
	Super::StartPlay();

	if (GEngine)
	{
		UE_LOG(GameInit, Log, TEXT("ABasicCodeGameMode: StartPlay"));
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Blue, FString("ABasicCodeGameMode: StartPlay"));
	}
}