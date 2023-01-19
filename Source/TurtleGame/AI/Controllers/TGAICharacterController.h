#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurtleGameTypes.h"
#include "TGAICharacterController.generated.h"

UCLASS()
class TURTLEGAME_API ATGAICharacterController : public AAIController
{
	GENERATED_BODY()

public:
	void SetBlackBoardValue(FVector StartPosition, FVector FinishPosition, EMovementType MoveType) const;
	virtual void SetPawn(APawn* InPawn) override;
	virtual void OnMoveCompleted(const FAIRequestID RequestID, const FPathFollowingResult& Result) override;

protected:
	virtual void BeginPlay() override;

private:
	TWeakObjectPtr<class ATGBaseAICharacter> CachedAICharacter;

	UPROPERTY()
	class ATurtleGameGameModeBase* TurtleGameMode;
};
