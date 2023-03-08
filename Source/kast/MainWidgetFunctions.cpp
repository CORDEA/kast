// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidgetFunctions.h"

#include "HttpModule.h"
#include "ServerSettings.h"
#include <string>

#include "Interfaces/IHttpResponse.h"

void UMainWidgetFunctions::OnSubmitted(
	FString Length,
	FString ShoulderLength,
	FString Width,
	FString SleeveLength,
	FString Yukitake
)
{
	const auto Settings = GetDefault<UServerSettings>();
	auto HTTPModule = &FHttpModule::Get();
	auto Request = HTTPModule->CreateRequest();
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");

	TSharedRef<FJsonObject> JSON = MakeShareable(new FJsonObject());
	JSON->SetNumberField("length", std::stod(*Length));
	JSON->SetNumberField("shoulderLength", std::stod(*ShoulderLength));
	JSON->SetNumberField("width", std::stod(*Width));
	JSON->SetNumberField("sleeveLength", std::stod(*SleeveLength));
	JSON->SetNumberField("yukitake", std::stod(*Yukitake));
	FString JSONString;
	const auto Writer = TJsonWriterFactory<>::Create(&JSONString);
	FJsonSerializer::Serialize(JSON, Writer);

	Request->SetContentAsString(JSONString);
	Request->SetURL("https://" + Settings->Host + Settings->PostTopsPath);
	Request->OnProcessRequestComplete().BindStatic(OnNext);
	Request->ProcessRequest();
}

void UMainWidgetFunctions::OnNext(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	if (Response.Get()->GetResponseCode() != 200)
	{
		return;
	}
}
