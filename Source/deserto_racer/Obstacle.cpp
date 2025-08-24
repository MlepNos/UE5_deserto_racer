

#include "Obstacle.h"


#include "PlayerCharacter.h"

AObstacle::AObstacle()
{
	PrimaryActorTick.bCanEverTick = true;






	CapsuleComp = CreateDefaultSubobject < UCapsuleComponent >(TEXT("CapsuleComp"));
	SetRootComponent(CapsuleComp);

	
	

	ObstacleSprite = CreateDefaultSubobject < UPaperSpriteComponent >(TEXT("ObstacleSprite"));
	ObstacleSprite->SetupAttachment(RootComponent);
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	CapsuleComp->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::OverlapBegin);
	
}

void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// For Obstacle Collision
void AObstacle::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor); // the thing the obstacle collided with should be character if its the character this cast will work and we get 1 if it isnt the player the cast wont work and we get null

	if (Player)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, TEXT("Overlapped with Player"));
		if (Player->CanMove) 
		{
			Player->CanMove = false;

		}
	}
}
