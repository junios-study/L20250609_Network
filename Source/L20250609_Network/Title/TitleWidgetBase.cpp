// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidgetBase.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"

void UTitleWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	UserIdText = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("UserIDText")));
	ServerIPText = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("ServerIPText")));
	PasswordText = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("PasswordText")));

	StartServerButton = Cast<UButton>(GetWidgetFromName(TEXT("StartServerButton")));
	ConnectButton = Cast<UButton>(GetWidgetFromName(TEXT("ConnectButton")));

	if (StartServerButton)
	{
		StartServerButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::OnClickServerStartButton);
	}

	if (ConnectButton)
	{
		ConnectButton->OnClicked.AddDynamic(this, &UTitleWidgetBase::OnClickConnectButton);
	}
	
}

void UTitleWidgetBase::OnClickServerStartButton()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClickServerStartButton"));
}

void UTitleWidgetBase::OnClickConnectButton()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClickConnectButton"));
}
