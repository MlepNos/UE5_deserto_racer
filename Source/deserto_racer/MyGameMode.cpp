// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"

// For Resetting the Game
#include "Kismet/GameplayStatics.h"

void AMyGameMode::ResetLevel(bool isWin) 
{

	float ResetTime= LoseResetTime;
	if (isWin)
	{
		ResetTime = WinResetTime;
	}
	
	GetWorldTimerManager().SetTimer(ResetGameTimer, this, &AMyGameMode::OnResetGameTimerTimeout, 1.0f, false, ResetTime);


}



void AMyGameMode::OnResetGameTimerTimeout()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainLevel"));
}