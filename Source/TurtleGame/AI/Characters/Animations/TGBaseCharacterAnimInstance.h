// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TGBaseCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TURTLEGAME_API UTGBaseCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character animation")
	float Speed = 0.0f;

private:
	TWeakObjectPtr<class ATGBaseAICharacter> CachedBaseCharacter;
};
