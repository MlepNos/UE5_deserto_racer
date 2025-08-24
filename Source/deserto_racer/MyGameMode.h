// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"


// For Resetting the Game
#include "Engine/TimerHandle.h"




#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DESERTO_RACER_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()



public:
	// For Resetting the Game
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LoseResetTime = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WinResetTime = 4.0f;

	FTimerHandle ResetGameTimer;

	void ResetLevel(bool isWin);
	void OnResetGameTimerTimeout();

	
};
