#include "TGSpawnController.h"

void ATGSpawnController::StartSpawnActor(const EMovementType MovementType) const
{
	if (OnStartActorSpawn.IsBound())
	{
		OnStartActorSpawn.Broadcast(MovementType);
	}
}
