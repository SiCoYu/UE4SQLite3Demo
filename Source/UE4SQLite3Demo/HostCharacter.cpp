// Fill out your copyright notice in the Description page of Project Settings.


#include "HostCharacter.h"
#include "SQLiteDatabase.h"

// Sets default values
AHostCharacter::AHostCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHostCharacter::BeginPlay()
{
	Super::BeginPlay();
	bool is_ok = GetMyStats();
	if (is_ok)
	{
		UE_LOG(LogTemp, Log, TEXT("Name = %s"), *Name);
		UE_LOG(LogTemp, Log, TEXT("Age = %d"), Age);
		UE_LOG(LogTemp, Log, TEXT("Gender = %s"), *Gender);
		UE_LOG(LogTemp, Log, TEXT("Height = %f"), Height);
	}
}

// Called every frame
void AHostCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHostCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AHostCharacter::GetMyStats()
{
	FString dbName = TEXT("TestDatabase");
	FString actorName = TEXT("Bruce Willis");

	if (!USQLiteDatabase::IsDatabaseRegistered(dbName))
	{
		USQLiteDatabase::RegisterDatabase(dbName, "Databases/TestDatabase.db", true);
	}

	bool didPopulate = USQLiteDatabase::GetDataIntoObject(dbName, FString::Printf(TEXT("SELECT Name, Age, Gender, Height FROM Actors WHERE Name = \"%s\""), *actorName), this);

	return didPopulate;
}
