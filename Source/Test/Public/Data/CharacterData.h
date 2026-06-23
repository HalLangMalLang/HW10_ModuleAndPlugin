// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterData.generated.h"

// 기본 정보
USTRUCT(BlueprintType)
struct FCharacterBaseInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterName = TEXT("Unknown");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CharacterClass = TEXT("Warrior");
};

// 전투 정보
USTRUCT(BlueprintType)
struct FCharacterBattleInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxMana = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackPower = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Defense = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CriticalChance = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CriticalDamage = 1.5f;
};

// 속성 정보
USTRUCT(BlueprintType)
struct FCharacterAttributesInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Strength = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Intelligence = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Dexterity = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Vitality = 10;
};

// 경험치 정보
USTRUCT(BlueprintType)
struct FCharacterExpInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentExp = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ExpToNextLevel = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SkillPoints = 0;
};

// 장비 정보
USTRUCT(BlueprintType)
struct FCharacterEquipmentInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> EquippedWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FString> EquippedArmor;
};

UCLASS()
class TEST_API UCharacterData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	FCharacterBaseInfo CharacterBaseInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battle")
	FCharacterBattleInfo CharacterBattleInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FCharacterAttributesInfo CharacterAttributesInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Experience")
	FCharacterExpInfo CharacterExpInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	FCharacterEquipmentInfo CharacterEquipmentInfo;
};
