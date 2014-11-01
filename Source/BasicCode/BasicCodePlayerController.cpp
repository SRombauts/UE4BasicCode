// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"
#include "BasicCodePlayerController.h"
#include "HelloWorldPrinter.h"
#include "GameGeneratedActor.h"
#include "GeneratedTriangle.h"


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
			// Spawn a static mesh cube in front of the starting position of the player, a bit on the right
			const FVector   Location(550.f, 50.f, 0.f);
			const FRotator  Rotation = FRotator::ZeroRotator;
			AHelloWorldPrinter* const HelloWorldPrinter = World->SpawnActor<AHelloWorldPrinter>(Location, Rotation);
			if(HelloWorldPrinter)
			{
				UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: HelloWorldPrinter spawned with Location"));
			}
			// Spawn a dynamic mesh in front of the player, a little bit on the left
			const FVector   Location2(200.f, -150.f, 0.f);
			const FRotator  Rotation2(0.f, 45.f, 0.f);
			AGameGeneratedActor* const GameGeneratedActor = World->SpawnActor<AGameGeneratedActor>(Location2, Rotation2);
			if(GameGeneratedActor)
			{
				// Scale it x5
				//GameGeneratedActor->SetActorScale3D(FVector(5.f, 5.f, 5.f));
				UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: GameGeneratedActor spawned"));
			}
			// Spawn a dynamic mesh in front of the player, a little bit on the right
			const FVector   Location3(150.f, 100.f, -30.f);
			AGeneratedTriangle* const GeneratedTriangle = World->SpawnActor<AGeneratedTriangle>(Location3, Rotation);
			if(GeneratedTriangle)
			{
				UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: GeneratedTriangle spawned"));
			}
		}
	}
}

