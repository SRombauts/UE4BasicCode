// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/GameMode.h"
#include "BasicCodeGameMode.generated.h"

/**
 * Management of the Game (server side only!)
 */
UCLASS()
class ABasicCodeGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

public:
	/** Transitions to WaitingToStart and calls BeginPlay on actors. */
	virtual void StartPlay() override;
};
