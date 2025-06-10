// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidgetBase.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

void ULobbyWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartButton)
	{
		StartButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::Start);
	}

	if (ChatEnterButton)
	{
		ChatEnterButton->OnClicked.AddDynamic(this, &ULobbyWidgetBase::EnterChat);
	}

	if (ChatInput)
	{
		ChatInput->OnTextChanged.AddDynamic(this, &ULobbyWidgetBase::OnChangedEvent);
		ChatInput->OnTextCommitted.AddDynamic(this, &ULobbyWidgetBase::OnCommittedEvent);
	}
}

void ULobbyWidgetBase::Start()
{

}

void ULobbyWidgetBase::EnterChat()
{

}

void ULobbyWidgetBase::OnChangedEvent(const FText& Text)
{
}

void ULobbyWidgetBase::OnCommittedEvent(const FText& Text, ETextCommit::Type CommitMethod)
{
}

void ULobbyWidgetBase::ShowStartButton()
{
	if (StartButton)
	{
		StartButton->SetVisibility(ESlateVisibility::Visible);
	}
}
