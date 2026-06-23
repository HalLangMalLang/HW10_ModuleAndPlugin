// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/CharacterData.h"
#include "CharacterDataHelper.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API UCharacterDataHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// 전체 정보 출력
	UFUNCTION(BlueprintCallable, Category = "Character Data Helper")
	static void PrintCharacterData(const UCharacterData* Data);

	// 카테고리별 출력
	UFUNCTION(BlueprintCallable, Category = "Character Data Helper")
	static void PrintBaseInfo(const FCharacterBaseInfo& Info);

	UFUNCTION(BlueprintCallable, Category = "Character Data Helper")
	static void PrintBattleInfo(const FCharacterBattleInfo& Info);

	UFUNCTION(BlueprintCallable, Category = "Character Data Helper")
	static void PrintAttributesInfo(const FCharacterAttributesInfo& Info);

	UFUNCTION(BlueprintCallable, Category = "Character Data Helper")
	static void PrintExpInfo(const FCharacterExpInfo& Info);

	UFUNCTION(BlueprintCallable, Category = "Character Data Helper")
	static void PrintEquipmentInfo(const FCharacterEquipmentInfo& Info);

	// 포맷팅된 문자열 반환(Blueprint에서 사용 가능)
	UFUNCTION(BlueprintPure, Category = "Character Data Helper")
	static FString GetFormattedCharacterInfo(const UCharacterData* Data);

	UFUNCTION(BlueprintPure, Category = "Character Data Helper")
	static FString GetFormattedBaseInfo(const FCharacterBaseInfo& Info);

	UFUNCTION(BlueprintPure, Category = "Character Data Helper")
	static FString GetFormattedBattleInfo(const FCharacterBattleInfo& Info);
};
