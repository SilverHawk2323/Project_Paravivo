// Copyright Paravivo


#include "Characters/ParavivoCharacterBase.h"

// Sets default values
AParavivoCharacterBase::AParavivoCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

UAbilitySystemComponent* AParavivoCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void AParavivoCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AParavivoCharacterBase::InitAbilityActorInfo()
{
	
}
