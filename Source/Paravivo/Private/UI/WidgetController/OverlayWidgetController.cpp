// Copyright Paravivo


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/ParavivoAbilitySystemComponent.h"
#include "AbilitySystem/ParavivoAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UParavivoAttributeSet* ParavivoAttributeSet = CastChecked<UParavivoAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(ParavivoAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(ParavivoAttributeSet->GetMaxHealth());
	OnBloodChanged.Broadcast(ParavivoAttributeSet->GetBlood());
	OnMaxBloodChanged.Broadcast(ParavivoAttributeSet->GetMaxBlood());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UParavivoAttributeSet* ParavivoAttributeSet = CastChecked<UParavivoAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ParavivoAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ParavivoAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ParavivoAttributeSet->GetBloodAttribute()).AddUObject(this, &UOverlayWidgetController::BloodChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ParavivoAttributeSet->GetMaxBloodAttribute()).AddUObject(this, &UOverlayWidgetController::MaxBloodChanged);

	Cast<UParavivoAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, Msg);

				FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
			}
		}
	);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::BloodChanged(const FOnAttributeChangeData& Data) const
{
	OnBloodChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxBloodChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxBloodChanged.Broadcast(Data.NewValue);
}
