// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
		FString length,
		FString shoulderLength,
		FString width,
		FString sleeveLength,
		FString yukitake
	);
};
