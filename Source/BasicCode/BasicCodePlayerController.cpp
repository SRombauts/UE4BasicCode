// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"
#include "BasicCodePlayerController.h"


ABasicCodePlayerController::ABasicCodePlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
  UE_LOG(GameInit, Log, TEXT("ABasicCodePlayerController: ctor"));

  // NOTE SRombauts: this crash the Editor at startup!
  // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString("PlayerController: Test"));
}


