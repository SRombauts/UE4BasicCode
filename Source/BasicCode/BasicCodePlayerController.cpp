// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"
#include "BasicCodePlayerController.h"
#include "HelloWorldPrinter.h"
#include "GameGeneratedActor.h"


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
			UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: World"));
			// Spawn a big static mesh cube in front of the starting position of the player, a bit on the right
            const FVector   Location = FVector(400.f, 50.f, 0.f);
			const FRotator  Rotation = FRotator::ZeroRotator;
			AHelloWorldPrinter* const HelloWorldPrinter = World->SpawnActor<AHelloWorldPrinter>(Location, Rotation);
			if(HelloWorldPrinter)
			{
				UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: HelloWorldPrinter spawned with Location"));
			}
            // Spawn a small dynamic mesh in front of the player, a little bit on the left
			const FVector   Location2 = FVector(200.f, -10.f, 0.f);
			AGameGeneratedActor* const GameGeneratedActor = World->SpawnActor<AGameGeneratedActor>(Location2, Rotation);
			if(GameGeneratedActor)
			{
				UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: GameGeneratedActor spawned with Location"));
			}
		}
	}
}

