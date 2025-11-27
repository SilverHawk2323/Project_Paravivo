// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSets/BasicAttributeSet.h"
#include "GameplayEffectExtension.h"

#include "Animation/AnimNode_Inertialization.h"

UBasicAttributeSet::UBasicAttributeSet()
{
	Health = 100;
	MaxHealth = 100;
}

void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
}

void UBasicAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}
}
