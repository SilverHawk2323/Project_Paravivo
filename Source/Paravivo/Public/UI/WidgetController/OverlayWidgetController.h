// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "ParavivoWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBloodChangedSignature, float, NewBlood);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxBloodChangedSignature, float, NewMaxBlood);
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class PARAVIVO_API UOverlayWidgetController : public UParavivoWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnBloodChangedSignature OnBloodChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnMaxBloodChangedSignature OnMaxBloodChanged;

protected:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void BloodChanged(const FOnAttributeChangeData& Data) const;
	void MaxBloodChanged(const FOnAttributeChangeData& Data) const;
};
