#pragma once

#include "ServerSettings.generated.h"

UCLASS(Config=ServerSettings)
class KAST_API UServerSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString Host;

	UPROPERTY(Config)
	FString PostTopsPath;

	UPROPERTY(Config)
	FString PostBottomsPath;
};
