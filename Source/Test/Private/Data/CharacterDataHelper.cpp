#include "Data/CharacterDataHelper.h"

void UCharacterDataHelper::PrintCharacterData(const UCharacterData* Data)
{
	if (!Data)
	{
		UE_LOG(LogTemp, Error, TEXT("[CharacterDataHelper] Data is nullptr!"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("========================================"));
	UE_LOG(LogTemp, Warning, TEXT("       CHARACTER DATA INFO"));
	UE_LOG(LogTemp, Warning, TEXT("========================================"));

	PrintBaseInfo(Data->CharacterBaseInfo);
	PrintBattleInfo(Data->CharacterBattleInfo);
	PrintAttributesInfo(Data->CharacterAttributesInfo);
	PrintExpInfo(Data->CharacterExpInfo);
	PrintEquipmentInfo(Data->CharacterEquipmentInfo);

	UE_LOG(LogTemp, Warning, TEXT("========================================"));
}

void UCharacterDataHelper::PrintBaseInfo(const FCharacterBaseInfo& Info)
{
	UE_LOG(LogTemp, Warning, TEXT("[BASE INFO]"));
	UE_LOG(LogTemp, Warning, TEXT("  Name: %s"), *Info.CharacterName);
	UE_LOG(LogTemp, Warning, TEXT("  Level: %d"), Info.Level);
	UE_LOG(LogTemp, Warning, TEXT("  Class: %s"), *Info.CharacterClass);
}

void UCharacterDataHelper::PrintBattleInfo(const FCharacterBattleInfo& Info)
{
	UE_LOG(LogTemp, Warning, TEXT("[BATTLE INFO]"));
	UE_LOG(LogTemp, Warning, TEXT("  Max Health: %.1f"), Info.MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("  Max Mana: %.1f"), Info.MaxMana);
	UE_LOG(LogTemp, Warning, TEXT("  Attack Power: %.1f"), Info.AttackPower);
	UE_LOG(LogTemp, Warning, TEXT("  Defense: %.1f"), Info.Defense);
	UE_LOG(LogTemp, Warning, TEXT("  Critical Chance: %.1f%%"), Info.CriticalChance * 100);
	UE_LOG(LogTemp, Warning, TEXT("  Critical Damage: %.1fx"), Info.CriticalDamage);
}

void UCharacterDataHelper::PrintAttributesInfo(const FCharacterAttributesInfo& Info)
{
	UE_LOG(LogTemp, Warning, TEXT("[ATTRIBUTES]"));
	UE_LOG(LogTemp, Warning, TEXT("  Strength: %d"), Info.Strength);
	UE_LOG(LogTemp, Warning, TEXT("  Intelligence: %d"), Info.Intelligence);
	UE_LOG(LogTemp, Warning, TEXT("  Dexterity: %d"), Info.Dexterity);
	UE_LOG(LogTemp, Warning, TEXT("  Vitality: %d"), Info.Vitality);
}

void UCharacterDataHelper::PrintExpInfo(const FCharacterExpInfo& Info)
{
	UE_LOG(LogTemp, Warning, TEXT("[EXPERIENCE]"));
	UE_LOG(LogTemp, Warning, TEXT("  Current Exp: %d / %d"), Info.CurrentExp, Info.ExpToNextLevel);
	UE_LOG(LogTemp, Warning, TEXT("  Skill Points: %d"), Info.SkillPoints);
}

void UCharacterDataHelper::PrintEquipmentInfo(const FCharacterEquipmentInfo& Info)
{
	UE_LOG(LogTemp, Warning, TEXT("[EQUIPMENT]"));

	if (Info.EquippedWeapon.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("  Weapons:"));
		for (const FString& Weapon : Info.EquippedWeapon)
		{
			UE_LOG(LogTemp, Warning, TEXT("    - %s"), *Weapon);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("  Weapons: None"));
	}

	if (Info.EquippedArmor.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("  Armor:"));
		for (const FString& Armor : Info.EquippedArmor)
		{
			UE_LOG(LogTemp, Warning, TEXT("    - %s"), *Armor);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("  Armor: None"));
	}
}

FString UCharacterDataHelper::GetFormattedCharacterInfo(const UCharacterData* Data)
{
	if (!Data)
	{
		return TEXT("Invalid Character Data");
	}

	FString Result = TEXT("=== CHARACTER INFO ===\n");
	Result += GetFormattedBaseInfo(Data->CharacterBaseInfo) + TEXT("\n");
	Result += GetFormattedBattleInfo(Data->CharacterBattleInfo);

	return Result;
}

FString UCharacterDataHelper::GetFormattedBaseInfo(const FCharacterBaseInfo& Info)
{
	return FString::Printf(TEXT("%s (Lv.%d %s)"),
		*Info.CharacterName,
		Info.Level,
		*Info.CharacterClass);
}

FString UCharacterDataHelper::GetFormattedBattleInfo(const FCharacterBattleInfo& Info)
{
	return FString::Printf(TEXT("HP: %.0f | MP: %.0f | ATK: %.0f | DEF: %.0f"),
		Info.MaxHealth,
		Info.MaxMana,
		Info.AttackPower,
		Info.Defense);
}