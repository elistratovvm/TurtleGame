#include "Actors/TGSpawnerActor.h"
#include "Controllers/TGSpawnController.h"
#include "Kismet/GameplayStatics.h"
#include "AI/Characters/TGBaseAICharacter.h"
#include "AI/Controllers/TGAICharacterController.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"

ATGSpawnerActor::ATGSpawnerActor()
{
	SpawnerMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnerMeshComponent"));
}

void ATGSpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	
	ATGSpawnController* CachedSpawnController = Cast<ATGSpawnController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	if (CachedSpawnController)
	{
		CachedSpawnController->OnStartActorSpawn.AddDynamic(this, &ATGSpawnerActor::TryToSpawnAICharacter);
	}
}

void ATGSpawnerActor::TryToSpawnAICharacter(EMovementType MoveType)
{
	if (!IsValid(CharacterClass) || MovementType != MoveType || bIsSpawning)
	{
		return;
	}

	SpawnEffects();

	bIsSpawning = true;

	const FVector ActorLocation = GetActorLocation();
	const FRotator ActorRotation = GetActorRotation();

	ATGBaseAICharacter* AICharacter = GetWorld()->SpawnActor<ATGBaseAICharacter>(CharacterClass, ActorLocation, ActorRotation);
	
	if (IsValid(AICharacter))
	{
		if (!IsValid(AICharacter->Controller))
		{
			AICharacter->SpawnDefaultController();
		}
		AICharacter->MovementType = MovementType;
		SetBlackBoardValue(AICharacter);
	}

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ATGSpawnerActor::ChangeSpawningState, SpawnDelay);
}

void ATGSpawnerActor::ChangeSpawningState()
{	
	bIsSpawning = false;
}

void ATGSpawnerActor::SetBlackBoardValue(ATGBaseAICharacter* Character)
{
	ATGAICharacterController* CachedController = Cast<ATGAICharacterController>(Character->Controller);
	
	if (CachedController)
	{
		CachedController->SetBlackBoardValue(
			GetActorLocation(),
			FinishLocation->GetActorLocation(),
			Character->MovementType);

	}
}

void ATGSpawnerActor::SpawnEffects()
{
	if(!SpawnerEffect)
	{
		if(SpawnNiagaraSystem)
		{
			SpawnerEffect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
				GetWorld(),
				SpawnNiagaraSystem,
				GetActorLocation() + FVector(0.0f, 0.0f, 100.0f),
				GetActorRotation(),
				ParticleScale);
		}
	}
		

	if(!FinishEffect)
	{
		if(FinishNiagaraSystem)
		{
			FinishEffect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
				GetWorld(),
				FinishNiagaraSystem,
				FinishLocation->GetActorLocation(),
				GetActorRotation(),
				ParticleScale);
		}
	}
		
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), SpawnSound, GetActorLocation());
}

