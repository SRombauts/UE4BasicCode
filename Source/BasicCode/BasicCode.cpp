// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "BasicCode.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, BasicCode, "BasicCode" );


// Logging during game startup
// (Logging, see UnrealEngine Wiki "Logs, Printing Messages To Yourself During Runtime")
DEFINE_LOG_CATEGORY(GameInit);


/*
Load Editor:
GameInit:Warning: ABasicCodeGameMode: ctor (GEngine null)
GameInit:Warning: ABasicCodePlayerController: ctor (GEngine null)
GameInit:Warning: AHelloWorldPrinter: ctor (GEngine null)
...
Hit Play:
GameInit : ABasicCodePlayerController : ctor
GameInit : ABasicCodePlayerController : BeginPlay
GameInit : ABasicCodePlayerController : World
GameInit : AHelloWorldPrinter : ctor
GameInit : ABasicCodePlayerController : HelloWorldPrinter spawned
GameInit : AHelloWorldPrinter : BeginPlay Number = 42

GameInit : ABasicCodeGameMode : StartPlay
*/