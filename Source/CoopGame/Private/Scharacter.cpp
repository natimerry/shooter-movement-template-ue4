// Fill out your copyright notice in the Description page of Project Settings.

#include "Scharacter.h"
#include <Camera/CameraComponent.h>
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
AScharacter::AScharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComponent); 

	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;
}

// Called when the game starts or when spawned
void AScharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AScharacter::BeginCrouch()
{
	Crouch();
}

void AScharacter::EndCrouch()
{
	UnCrouch();
}

void AScharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
	
}

void AScharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);

}

// Called every frame
void AScharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AScharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&AScharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AScharacter::MoveRight);

	PlayerInputComponent->BindAxis("Lookup", this, &AScharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &AScharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AScharacter::BeginCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AScharacter::EndCrouch);
	
	
}

