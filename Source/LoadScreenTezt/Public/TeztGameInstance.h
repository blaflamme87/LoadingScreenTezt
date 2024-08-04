// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TeztGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LOADSCREENTEZT_API UTeztGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UFUNCTION()
	virtual void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
	virtual void EndLoadingScreen(UWorld* InLoadedWorld);

	UFUNCTION(BlueprintImplementableEvent, Category = "Loading Screen")
	void BeginLoadingScreen_UMG(const FString& MapName);

	UFUNCTION(BlueprintImplementableEvent, Category = "Loading Screen")
	void EndLoadingScreen_UMG(UWorld* InLoadedWorld);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading Screen")
	bool bShouldUseSlate = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading Screen")
	float MinimumLoadingScreenDisplayTime = 2.0f;
	
};
