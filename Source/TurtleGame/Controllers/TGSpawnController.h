#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TurtleGameTypes.h"
#include "TGSpawnController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartActorSpawn, EMovementType, MovementType);

UCLASS()
class TURTLEGAME_API ATGSpawnController : public APlayerController
{
	GENERATED_BODY()

public:
	FOnStartActorSpawn OnStartActorSpawn;

	UFUNCTION(BlueprintCallable, Category = "SpawnActors")
	void StartSpawnActor(const EMovementType MovementType) const;
};
