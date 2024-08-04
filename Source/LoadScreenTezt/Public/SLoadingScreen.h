// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LoadingScreenTeztSettings.h"

/**
 * 
 */
class SLoadingScreen : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SLoadingScreen) {}
	SLATE_END_ARGS()
	
	SLoadingScreen();
	~SLoadingScreen();

	void Construct(const FArguments& InArgs)
	{

		UE_LOG(LogTemp, Warning, TEXT("SLoadingScreen::Construct we in it"));
		ChildSlot
			[
				SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Fill)
					[SNew(SImage).Image(&ULoadingScreenTeztSettings::Get()->LoadingScreenBrush)]
			];
	}
};
