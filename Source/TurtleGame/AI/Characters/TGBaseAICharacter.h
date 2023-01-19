#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TurtleGameTypes.h"
#include "TGBaseAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class TURTLEGAME_API ATGBaseAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	EMovementType MovementType = EMovementType::Move;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FinishEffects")
	USoundBase* FinishSound;

	UBehaviorTree* GetBehaviorTree() const;
	void PlayFinishSound();
	void DestroyCharacter();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;

private:
	bool bIsSoundPlaying = false;

	void ChangeSoundState();
};
