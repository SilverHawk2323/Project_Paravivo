// Copyright Paravivo


#include "AbilitySystem/ParavivoAbilitySystemComponent.h"



void UParavivoAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UParavivoAbilitySystemComponent::EffectApplied);
}

void UParavivoAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(1,8.f,FColor::Red,"Effect Applied!");
}
