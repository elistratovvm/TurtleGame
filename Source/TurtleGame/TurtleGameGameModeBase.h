#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TurtleGameGameModeBase.generated.h"

class USoundBase;

UCLASS()
class TURTLEGAME_API ATurtleGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void PlayFinishSound(USoundBase* FinishSound) const;

protected:
	UPROPERTY()
	UAudioComponent* AudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FinishEffects")
	USoundBase* BaseFinishSound;

	virtual void BeginPlay() override;
};
