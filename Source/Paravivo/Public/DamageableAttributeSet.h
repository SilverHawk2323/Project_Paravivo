// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "DamageableAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class PARAVIVO_API UDamageableAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DamageableAttributeSet")
	FGameplayAttributeData Health = 100.0f;
	ATTRIBUTE_ACCESSORS(UDamageableAttributeSet, Health)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DamageableAttributeSet")
	FGameplayAttributeData MaxHealth = 100.0f;
	ATTRIBUTE_ACCESSORS(UDamageableAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DamageableAttributeSet")
	FGameplayAttributeData Damage = 5.f;
	ATTRIBUTE_ACCESSORS(UDamageableAttributeSet, Damage)

	
};
