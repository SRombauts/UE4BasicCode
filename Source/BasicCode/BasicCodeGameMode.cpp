// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"
#include "BasicCodeGameMode.h"
#include "BasicCodePlayerController.h"

ABasicCodeGameMode::ABasicCodeGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = ABasicCodePlayerController::StaticClass();
}


