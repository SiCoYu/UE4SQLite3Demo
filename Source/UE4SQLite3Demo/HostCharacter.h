// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HostCharacter.generated.h"

UCLASS()
class UE4SQLITE3DEMO_API AHostCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHostCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UFUNCTION(BlueprintCallable, Category = "My Actor")
	bool GetMyStats();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
	int32 Age;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
	FString Gender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Actor")
	float Height;

};
