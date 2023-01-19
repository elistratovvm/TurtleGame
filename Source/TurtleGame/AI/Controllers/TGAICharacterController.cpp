#include "TGAICharacterController.h"
#include "AI/Characters/TGBaseAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TurtleGameGameModeBase.h"

void ATGAICharacterController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	
	if (IsValid(InPawn))
	{
		checkf(
			InPawn->IsA<ATGBaseAICharacter>(),
			TEXT("ATGAICharacterController::SetPawn TGAICharacterController can possess only TGBaseAICharacter"));
		
		CachedAICharacter = StaticCast<ATGBaseAICharacter*>(InPawn);
		RunBehaviorTree(CachedAICharacter->GetBehaviorTree());
	}
	else
	{
		CachedAICharacter = nullptr;
	}
}

void ATGAICharacterController::SetBlackBoardValue(
	const FVector StartPosition,
	const FVector FinishPosition,
	EMovementType MoveType) const
{
	if (Blackboard)
	{
		Blackboard->SetValueAsVector(BB_StartPosition, StartPosition);
		Blackboard->SetValueAsVector(BB_FinishPosition, FinishPosition);
		Blackboard->SetValueAsEnum(BB_MovementType, static_cast<uint8>(MoveType));
	}
}

void ATGAICharacterController::OnMoveCompleted(const FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	
	if (!Result.IsSuccess())
	{
		return;
	}
	if (CachedAICharacter.IsValid())
	{
		if (IsValid(TurtleGameMode))
		{
			TurtleGameMode->PlayFinishSound(CachedAICharacter->FinishSound);
		}
		CachedAICharacter->DestroyCharacter();
	}
}

void ATGAICharacterController::BeginPlay()
{
	Super::BeginPlay();

	TurtleGameMode = StaticCast<ATurtleGameGameModeBase*>(GetWorld()->GetAuthGameMode());
}
