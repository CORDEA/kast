// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidgetFunctions.h"

#include "ServerSettings.h"
#include <string>

void UMainWidgetFunctions::OnSubmitted(
	FString length,
	FString shoulderLength,
	FString width,
	FString sleeveLength,
	FString yukitake
)
{
	const auto Settings = GetDefault<UServerSettings>();
	TSharedRef<FJsonObject> JSON = MakeShareable(new FJsonObject());
	JSON->SetNumberField("length", std::stod(*length));
	JSON->SetNumberField("shoulderLength", std::stod(*shoulderLength));
	JSON->SetNumberField("width", std::stod(*width));
	JSON->SetNumberField("sleeveLength", std::stod(*sleeveLength));
	JSON->SetNumberField("yukitake", std::stod(*yukitake));
	FString JSONString;
	const auto Writer = TJsonWriterFactory<>::Create(&JSONString);
	FJsonSerializer::Serialize(JSON, Writer);
}
