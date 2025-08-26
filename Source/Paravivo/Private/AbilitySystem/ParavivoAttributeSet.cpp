// Copyright Paravivo


#include "AbilitySystem/ParavivoAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UParavivoAttributeSet::UParavivoAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitBlood(50.f);
	InitMaxBlood(100.f);
}

void UParavivoAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UParavivoAttributeSet,Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UParavivoAttributeSet,MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UParavivoAttributeSet,Blood, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UParavivoAttributeSet,MaxBlood, COND_None, REPNOTIFY_Always);
}

void UParavivoAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UParavivoAttributeSet, Health, OldHealth);
}

void UParavivoAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UParavivoAttributeSet, MaxHealth, OldMaxHealth);
}

void UParavivoAttributeSet::OnRep_Blood(const FGameplayAttributeData& OldBlood) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UParavivoAttributeSet, Blood, OldBlood);
}

void UParavivoAttributeSet::OnRep_MaxBlood(const FGameplayAttributeData& OldMaxBlood) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UParavivoAttributeSet, MaxBlood, OldMaxBlood);
}

