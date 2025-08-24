
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// For Obstacle
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"

// For time resetting
#include "MyGameMode.h"


// For Sound
#include "Sound/SoundBase.h"

#include "Obstacle.generated.h"

UCLASS()
class DESERTO_RACER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	

	// For Obstacle
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* ObstacleSprite;

	// For time resetting
	AMyGameMode* MyGameMode;

	// For Sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsFinishLine= false;



	AObstacle();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;



	// For Obstacle Collision
	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);
	// (1:the component that got overlapped which is our capsule component, 2: actor that we collide which is the player)

};
