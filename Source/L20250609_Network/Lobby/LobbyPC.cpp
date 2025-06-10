// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidgetBase.h"


//Server, Client
void ALobbyPC::BeginPlay()
{
	Super::BeginPlay();

	//#include "WB_Lobby"
	FSoftClassPath LobbyWidgetPath(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Bluprints/Lobby/WB_Lobby.WB_Lobby_C'"));

	UClass* WidgetClass = LobbyWidgetPath.TryLoadClass<ULobbyWidgetBase>();
	if (WidgetClass)
	{
		if (IsLocalPlayerController())
		{
			//ULobbyWidgetBase* WidgetObject = new WB_Lobby
			WidgetObject = CreateWidget<ULobbyWidgetBase>(this, WidgetClass);

			//Listen Server(client), Client 
			WidgetObject->AddToViewport();

			if (HasAuthority())
			{
				WidgetObject->ShowStartButton();
			}

			bShowMouseCursor = true;

			SetInputMode(FInputModeGameAndUI());
		}
	}

}
