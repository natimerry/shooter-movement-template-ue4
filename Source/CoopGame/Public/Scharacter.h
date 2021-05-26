// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Scharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
UCLASS()
class COOPGAME_API AScharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AScharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void BeginCrouch();
	void EndCrouch();
	void MoveForward(float Value);
	void MoveRight(float Value);
	void SJump();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components")
	UCameraComponent*CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent*SpringArmComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
