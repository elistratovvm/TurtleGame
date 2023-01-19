#include "AI/Characters/TGBaseAICharacter.h"
#include "Kismet/GameplayStatics.h"

UBehaviorTree* ATGBaseAICharacter::GetBehaviorTree() const
{
	return BehaviorTree;
}

void ATGBaseAICharacter::PlayFinishSound()
{
	if (!IsValid(FinishSound) || bIsSoundPlaying)
	{
		return;
	}

	bIsSoundPlaying = true;
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), FinishSound, GetActorLocation());

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ATGBaseAICharacter::ChangeSoundState,
		FinishSound->GetDuration());
}

void ATGBaseAICharacter::ChangeSoundState()
{
	bIsSoundPlaying = false;
	DestroyCharacter();
}

void ATGBaseAICharacter::DestroyCharacter()
{
	K2_DestroyActor();
}

