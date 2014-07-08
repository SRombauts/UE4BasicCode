// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"
#include "BasicCodeGameMode.h"
#include "BasicCodePlayerController.h"

//
// UE4.3 build times (Editor opened):
// CompilerResultsLog: Info UBT execution time : 236, 67 seconds 
// CompilerResultsLog: Info UBT execution time : 176, 98 seconds
// 
// UE4.3 build times (Editor closed):
// CompilerResultsLog: Info UBT execution time: 33,36 seconds
// CompilerResultsLog: Info UBT execution time: 32,21 seconds
// CompilerResultsLog: Info UBT execution time: 30,82 seconds
//
// UE4.3 build times (nothing to build, Editor closed):
// CompilerResultsLog: Info UBT execution time: 14,38 seconds
// CompilerResultsLog: Info UBT execution time: 14,26 seconds
//
//
// UE4.5 source (Editor closed)
// CompilerResultsLog: Info UBT execution time: 88,14 seconds
// CompilerResultsLog: Info UBT execution time: 74,41 seconds
// CompilerResultsLog: Info UBT execution time: 76,45 seconds
ABasicCodeGameMode::ABasicCodeGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
  UE_LOG(GameInit, Log, TEXT("ABasicCodeGameMode: ctor"));

	PlayerControllerClass = ABasicCodePlayerController::StaticClass();
}

