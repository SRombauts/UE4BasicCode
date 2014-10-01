// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "GeneratedMeshComponent.h"
#include "GameGeneratedActor.generated.h"

/**
*
*/
UCLASS()
class AGameGeneratedActor : public AActor
{
	GENERATED_UCLASS_BODY()

		void Lathe(const TArray<FVector>& points, TArray<FGeneratedMeshTriangle>& triangles, int segments = 64);

};
