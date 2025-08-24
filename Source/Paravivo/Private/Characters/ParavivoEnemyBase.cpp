// Copyright Paravivo


#include "Characters/ParavivoEnemyBase.h"
#include "AbilitySystem/ParavivoAbilitySystemComponent.h"
#include "AbilitySystem/ParavivoAttributeSet.h"

AParavivoEnemyBase::AParavivoEnemyBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<UParavivoAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UParavivoAttributeSet>("AttributeSet");
}

void AParavivoEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
