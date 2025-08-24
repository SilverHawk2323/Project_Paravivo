// Copyright Paravivo


#include "Player/ParavivoPlayerState.h"

#include "DamageableAttributeSet.h"
#include "AbilitySystem/ParavivoAbilitySystemComponent.h"

AParavivoPlayerState::AParavivoPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UParavivoAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

	AttributeSet = CreateDefaultSubobject<UDamageableAttributeSet>("AttributeSet");

	
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AParavivoPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
