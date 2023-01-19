// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Characters/Animations/TGBaseCharacterAnimInstance.h"
#include "AI/Characters/TGBaseAICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UTGBaseCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<ATGBaseAICharacter>(), TEXT("UTGBaseCharacterAnimInstance::NativeBeginPlay() UTGBaseCharacterAnimInstance can be used only with ATGBaseAICharacter"));
	CachedBaseCharacter = StaticCast<ATGBaseAICharacter*>(TryGetPawnOwner());
}

void UTGBaseCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!CachedBaseCharacter.IsValid())
	{
		return;
	}

	UCharacterMovementComponent* CharacterMovement = CachedBaseCharacter->GetCharacterMovement();
	Speed = CharacterMovement->Velocity.Size();
}
