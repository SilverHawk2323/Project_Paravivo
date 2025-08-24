// Copyright Paravivo


#include "Player/ParavivoPlayerState.h"
#include "AbilitySystem/ParavivoAbilitySystemComponent.h"
#include "AbilitySystem/ParavivoAttributeSet.h"

AParavivoPlayerState::AParavivoPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UParavivoAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

	AttributeSet = CreateDefaultSubobject<UParavivoAttributeSet>("AttributeSet");

	
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AParavivoPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
