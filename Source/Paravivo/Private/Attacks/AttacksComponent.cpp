// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacks/AttacksComponent.h"

// Sets default values for this component's properties
UAttacksComponent::UAttacksComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	Damage = 0;
	DamagedActor = nullptr;
	AttackMontage = nullptr;

	// ...
}

void UAttacksComponent::AttackStart_Implementation(AActor* AttackTarget)
{
	
}

// Called when the game starts
void UAttacksComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAttacksComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

