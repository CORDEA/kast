// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KAST_API UMainUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void OnSubmitSucceeded();

	UFUNCTION(BlueprintNativeEvent)
	void OnSubmitFailed();

	UFUNCTION(BlueprintCallable)
	void OnSubmitted(
		FString Length,
		FString ShoulderLength,
		FString Width,
		FString SleeveLength,
		FString Yukitake
	);
};
