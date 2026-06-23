// Fill out your copyright notice in the Description page of Project Settings.


#include "TestModuleActor.h"

ATestModuleActor::ATestModuleActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATestModuleActor::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Cyan, FString::Printf(TEXT("Test 모듈 : %s "), *GetName()));
}

