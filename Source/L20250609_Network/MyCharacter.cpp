// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (IsValid(UIC))
	{
		UIC->BindAction(FireInput, ETriggerEvent::Completed, this, &AMyCharacter::OnFire);
	}

}

void AMyCharacter::OnFire()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (IsValid(PC))
	{
		int32 SizeX;
		int32 SizeY;
		FVector WorldPosition;
		FVector WorldDirection;

		PC->GetViewportSize(SizeX, SizeY);

		PC->DeprojectScreenPositionToWorld(SizeX / 2.0f,
			SizeY / 2.0f,
			WorldPosition,
			WorldDirection
		);

		FVector SpawnPosition = GetActorLocation() + (WorldDirection * 100.f);
		FRotator SpawnRotation = WorldDirection.Rotation();
		//GetWorld()->SpawnActor<AActor>(BulletActor, SpawnPosition, WorldDirection.Rotation());
		C2S_Fire(SpawnPosition, SpawnRotation);
	}
}

bool AMyCharacter::C2S_Fire_Validate(const FVector& SpawnPosition, const FRotator& SpawnRotation)
{
	return true;
}

void AMyCharacter::C2S_Fire_Implementation(const FVector& SpawnPosition, const FRotator& SpawnRotation)
{
	GetWorld()->SpawnActor<AActor>(BulletActor, SpawnPosition, SpawnRotation);
}


