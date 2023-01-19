// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Characters/Animations/Notifies/AnimNotify_Steps.h"
#include "../../TGBaseAICharacter.h"
#include "Kismet/GameplayStatics.h"

void UAnimNotify_Steps::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	ATGBaseAICharacter* CachedCharacter = Cast<ATGBaseAICharacter>(MeshComp->GetOwner());
	if (CachedCharacter)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), CachedCharacter->FinishSound, CachedCharacter->GetActorLocation());
	}
}
