
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// For Obstacle
#include "Components/CapsuleComponent.h"
#include "PaperSpriteComponent.h"

#include "Obstacle.generated.h"

UCLASS()
class DESERTO_RACER_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* ObstacleSprite;

	AObstacle();


	virtual void BeginPlay() override;


	virtual void Tick(float DeltaTime) override;

};
