// Fill out your copyright notice in the Description page of Project Settings.

#include "TeztGameInstance.h"
#include "SLoadingScreen.h"
#include "MoviePlayer.h"

void UTeztGameInstance::Init()
{
	Super::Init();

	if (bShouldUseSlate)
	{
		FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UTeztGameInstance::BeginLoadingScreen);
		FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UTeztGameInstance::EndLoadingScreen);
	}
	else
	{
		FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UTeztGameInstance::BeginLoadingScreen_UMG);
		FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UTeztGameInstance::EndLoadingScreen_UMG);
	}
	

}

void UTeztGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.MinimumLoadingScreenDisplayTime = MinimumLoadingScreenDisplayTime;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		//LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();
		LoadingScreen.WidgetLoadingScreen = SNew(SLoadingScreen);
 
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void UTeztGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
}
