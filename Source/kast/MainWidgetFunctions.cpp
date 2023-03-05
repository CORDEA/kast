// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidgetFunctions.h"

#include "ServerSettings.h"

void UMainWidgetFunctions::OnSubmitted(
	FString length,
	FString shoulderLength,
	FString width,
	FString sleeveLength,
	FString yukitake
)
{
	const UServerSettings* settings = GetDefault<UServerSettings>();
}
