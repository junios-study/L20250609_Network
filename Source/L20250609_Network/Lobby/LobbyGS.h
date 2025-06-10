// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGS.generated.h"

/**
 * 
 */
UCLASS()
class L20250609_NETWORK_API ALobbyGS : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(Replicated)
	uint16 LeftTime = 60;

	UPROPERTY(Replicated)
	uint16 ConnectCount = 0;


	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
