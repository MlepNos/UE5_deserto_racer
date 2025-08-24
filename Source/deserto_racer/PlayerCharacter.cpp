// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CapsuleComp = CreateDefaultSubobject < UCapsuleComponent >(TEXT("CapsuleComp"));
	SetRootComponent(CapsuleComp);


	SpringArm = CreateDefaultSubobject < USpringArmComponent >(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject < UCameraComponent >(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);


	CarSprite = CreateDefaultSubobject < UPaperSpriteComponent >(TEXT("CarSprite"));
	CarSprite->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// For Enhanced Input (b)
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem)
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}

	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	// For Enhanced Input (b)
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	}
}

// For Enhanced Input (b)
void APlayerCharacter::Move(const FInputActionValue& Value)
{
	// (X, Y) 
	// X value represents A or D keys 
	// Y value represents W or S keys 
	// if the value is 0 its not pressed
	FVector2D MoveActionValue = Value.Get<FVector2D>();
	GEngine->AddOnScreenDebugMessage(1, 10.0f, FColor::White, MoveActionValue.ToString());


	if (CanMove)
	{
		if (abs(MoveActionValue.Y) > 0.0f)  //W is pressed means W is greater than 0 S pressed means W is less than zero but the abs value is greater than 0 which means one of them is pressed if this statement is true
		{
			float DeltaTime = GetWorld()->DeltaTimeSeconds;
			// For Rotation
			if (abs(MoveActionValue.X) > 0.0f) 
			{
				float RotationAmount = -RotationSpeed * MoveActionValue.X * DeltaTime;
				AddActorWorldRotation(FRotator(RotationAmount,0.0f, 0.0f));
			}

			// For Forwards Backwards Movement
			float FinalMovementSpeed = MovementSpeed;
			if (MoveActionValue.Y < 0.0f)
			{
				FinalMovementSpeed *= 0.5f;
			}

			GEngine->AddOnScreenDebugMessage(
				-1, 10.0f, FColor::Blue,
				FString::Printf(TEXT("FinalMovementSpeed: %.2f"), FinalMovementSpeed)
			);

			FVector CurrentLocation = GetActorLocation();
			FVector DistanceToMove = GetActorUpVector() * FinalMovementSpeed * MoveActionValue.Y * DeltaTime;

			FVector NewLocation = CurrentLocation + DistanceToMove;
			SetActorLocation(NewLocation);
		}

		if (abs(MoveActionValue.X) > 0.0f) 
		{

		}
	}
}
