// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

// For the components in character blueprint (a)
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperSpriteComponent.h"
 
// For Enhanced Input (b)
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/Controller.h"

#include "PlayerCharacter.generated.h"

UCLASS()
class DESERTO_RACER_API APlayerCharacter : public APawn
{
	GENERATED_BODY()

public:

	// For the components in character blueprint (a)


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* CarSprite;


	// For Enhanced Input (b)

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* MoveAction;

	// For Enhanced Input (b)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotationSpeed = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CanMove = true;

	APlayerCharacter();


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// For Enhanced Input (b)
	void Move(const FInputActionValue& Value);
};
