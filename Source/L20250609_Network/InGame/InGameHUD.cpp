// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"
#include "Engine/Canvas.h"
#include "GameFramework/Character.h"

void AInGameHUD::DrawHUD()
{
	Super::DrawHUD();

	ACharacter* Pawn = Cast<ACharacter>(GetOwningPawn());
	if (IsValid(Pawn))
	{
		float Speed = Pawn->GetVelocity().Size();
		float SpeedRatio = Speed / 300.0f;

		float Unit = Canvas->SizeX / 100.0f;

		float CenterX = Canvas->SizeX / 2.0f;
		float CenterY = Canvas->SizeY / 2.0f;

		//Left
		DrawLine(CenterX - (Unit * 2) - (Unit * SpeedRatio),
			CenterY,
			CenterX - (Unit * SpeedRatio),
			CenterY,
			FLinearColor::Red, 2.0f);

		//Right
		DrawLine(CenterX + (Unit * SpeedRatio),
			CenterY,
			CenterX + (Unit * 2) + (Unit * SpeedRatio),
			CenterY,
			FLinearColor::Red, 2.0f);

		//Up
		DrawLine(CenterX,
			CenterY - (Unit * 2) - (Unit * SpeedRatio),
			CenterX,
			CenterY - (Unit * SpeedRatio),
			FLinearColor::Red, 2.0f);

		//Down
		DrawLine(CenterX,
			CenterY + (Unit * SpeedRatio),
			CenterX,
			CenterY + (Unit * 2) + (Unit * SpeedRatio),
			FLinearColor::Red, 2.0f);
	}
}