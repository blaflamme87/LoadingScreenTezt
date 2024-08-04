// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "LoadingScreenTeztSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Game, defaultconfig)
class LOADSCREENTEZT_API ULoadingScreenTeztSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly)
    FSlateBrush LoadingScreenBrush;

	UFUNCTION(BlueprintPure)
	static const ULoadingScreenTeztSettings* Get()
	{
		return GetDefault<ULoadingScreenTeztSettings>();
	}
};
