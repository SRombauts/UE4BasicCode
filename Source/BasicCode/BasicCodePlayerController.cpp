// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"
#include "BasicCodePlayerController.h"
#include "HelloWorldPrinter.h"


ABasicCodePlayerController::ABasicCodePlayerController(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	if (GEngine)
	{
		UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: ctor"));
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Green, FString("ABasicCodePlayerController: ctor"));
	}
	else
	{
		UE_LOG(GameInit, Warning, TEXT("ABasicCodePlayerController: ctor (GEngine null)"));
	}
}


void ABasicCodePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: BeginPlay"));
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Green, TEXT("ABasicCodePlayerController: BeginPlay"));

		UWorld* const World = GetWorld();
		if (World)
		{
			UE_LOG(GameInit, Log, TEXT("ABasicCodeGameMode: World"));
			// FActorSpawnParameters SpawnParams;
			// SpawnParams.Owner = this;
	     // AHelloWorldPrinter* const HelloWorldPrinter = World->SpawnActor<AHelloWorldPrinter>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			AHelloWorldPrinter* const HelloWorldPrinter = World->SpawnActor<AHelloWorldPrinter>();
			if (HelloWorldPrinter)
			{
				UE_LOG(GameInit, Log, TEXT("ABasicCodeGameMode: HelloWorldPrinter spawned"));
			}
		}
	}
	else
	{
		// TODO SRombauts: possible?
		UE_LOG(GameInit, Error, TEXT("ABasicCodePlayerController: StartPlay (GEngine null)"));
	}
}

