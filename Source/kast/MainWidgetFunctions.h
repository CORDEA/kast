// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MainWidgetFunctions.generated.h"

/**
 * 
 */
UCLASS()
class KAST_API UMainWidgetFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static void OnSubmitted(
		FString Length,
		FString ShoulderLength,
		FString Width,
		FString SleeveLength,
		FString Yukitake
	);

	static void OnNext(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
};
