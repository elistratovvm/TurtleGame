#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurtleGameTypes.h"
#include "TGSpawnerActor.generated.h"

class ATGBaseAICharacter;
class UNiagaraSystem;
class UNiagaraComponent;

UCLASS()
class TURTLEGAME_API ATGSpawnerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATGSpawnerActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SpawnerMesh")
	UStaticMeshComponent* SpawnerMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AISpawner")
	TSubclassOf<ATGBaseAICharacter> CharacterClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AISpawner")
	EMovementType MovementType = EMovementType::Move;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AISpawner")
	float SpawnDelay = 1.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, meta = (MakeEditWidget))
	AActor* FinishLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AISpawner| SpawnEffect")
	UNiagaraSystem* SpawnNiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AISpawner| SpawnEffect")
	UNiagaraSystem* FinishNiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AISpawner| SpawnEffect")
	USoundBase* SpawnSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AISpawner| SpawnEffect")
	FVector ParticleScale = FVector(1.0f, 1.0f, 1.0f);

	UFUNCTION()
	void TryToSpawnAICharacter(EMovementType MoveType);

private:
	bool bIsSpawning = false;

	UPROPERTY()
	UNiagaraComponent* SpawnerEffect;
	UPROPERTY()
	UNiagaraComponent* FinishEffect;

	void ChangeSpawningState();

	void SetBlackBoardValue(ATGBaseAICharacter* Character);

	void SpawnEffects();
};
