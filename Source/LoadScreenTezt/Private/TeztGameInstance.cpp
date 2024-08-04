// Fill out your copyright notice in the Description page of Project Settings.

#include "TeztGameInstance.h"
#include "SLoadingScreen.h"
#include "MoviePlayer.h"

void UTeztGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UTeztGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UTeztGameInstance::EndLoadingScreen);
}

void UTeztGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.MinimumLoadingScreenDisplayTime = 2;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		//LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
		LoadingScreen.WidgetLoadingScreen = SNew(SLoadingScreen);
 
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void UTeztGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
}
