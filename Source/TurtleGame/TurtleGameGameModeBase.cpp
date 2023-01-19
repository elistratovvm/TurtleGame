// Copyright Epic Games, Inc. All Rights Reserved.


#include "TurtleGameGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Components/AudioComponent.h"


void ATurtleGameGameModeBase::PlayFinishSound(USoundBase* FinishSound) const
{
	if (!IsValid(AudioComponent))
	{
		return;
	}

	AudioComponent->Deactivate();
	AudioComponent->SetSound(FinishSound);
	AudioComponent->Activate();
}

void ATurtleGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	AudioComponent = UGameplayStatics::CreateSound2D(GetWorld(), BaseFinishSound);
	AudioComponent->bAutoDestroy = false;
}
