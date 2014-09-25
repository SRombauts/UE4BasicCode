

#include "BasicCode.h"
#include "HelloWorldPrinter.h"


AHelloWorldPrinter::AHelloWorldPrinter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
	, Number(42)
{
	if (GEngine)
	{
		UE_LOG(GameInit, Log, TEXT("AHelloWorldPrinter: ctor"));
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Green, FString("AHelloWorldPrinter: ctor"));

		// Create a Mesh Component as sub-object
		TSubobjectPtr<UStaticMeshComponent> MeshComponent = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MyMesh"));
		MeshComponent->bOwnerNoSee = false;
		MeshComponent->bCastDynamicShadow = true;
		MeshComponent->CastShadow = true;
		MeshComponent->BodyInstance.SetObjectType(ECC_WorldDynamic);
		MeshComponent->BodyInstance.SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		MeshComponent->BodyInstance.SetResponseToAllChannels(ECR_Ignore);
		MeshComponent->BodyInstance.SetResponseToChannel(ECC_WorldStatic, ECR_Block);
		MeshComponent->BodyInstance.SetResponseToChannel(ECC_WorldDynamic, ECR_Block);
		MeshComponent->BodyInstance.SetResponseToChannel(ECC_Pawn, ECR_Block);
		MeshComponent->SetHiddenInGame(false);

		// Asset, Reference Obtained Via Right Click in Editor
		static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/Meshes/TemplateCube_Rounded.TemplateCube_Rounded'"));
		MeshComponent->SetStaticMesh(StaticMesh.Object);

		// Attach the Mesh as the RootComponent (a Root Component is required to prevent Garbage Collection of the Actor)
		RootComponent = MeshComponent;
	}
	else
	{
		UE_LOG(GameInit, Warning, TEXT("AHelloWorldPrinter: ctor (GEngine null)"));
	}
}

void AHelloWorldPrinter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("AHelloWorldPrinter: BeginPlay Number=%d"), Number);
		GEngine->AddOnScreenDebugMessage(-1, 60.f, FColor::Yellow, *Message);

		UE_LOG(GameInit, Log, TEXT("AHelloWorldPrinter: BeginPlay Number=%d"), Number);
	}
}

