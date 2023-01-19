#pragma once

//Value to BlackBoard
const FName BB_StartPosition = "StartPosition";
const FName BB_FinishPosition = "FinishPosition";
const FName BB_MovementType = "MovementType";

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Move,
	MoveAndWait,
	MoveAndGoBack
};