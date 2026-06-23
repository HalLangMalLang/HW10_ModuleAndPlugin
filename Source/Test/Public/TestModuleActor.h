// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestModuleActor.generated.h"

UCLASS()
class TEST_API ATestModuleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestModuleActor();

protected:
	virtual void BeginPlay() override;

};
