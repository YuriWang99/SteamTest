// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

bool UTextFileManager::SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting = false)
{
	SaveDirectory += "\\";
	SaveDirectory += FileName;

	if (!AllowOverWriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}

	FString FinalString = "";
	for (FString& Each : SaveText)
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}

	return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}

TArray<FString> UTextFileManager::LoadFileToStringArray(FString ReadDirectory, FString FileName)
{
	ReadDirectory += "\\";
	ReadDirectory += FileName;
	TArray<FString> result;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*ReadDirectory))
	{
		
	}
	FFileHelper::LoadFileToStringArray(result,*ReadDirectory);
	return result;

}

