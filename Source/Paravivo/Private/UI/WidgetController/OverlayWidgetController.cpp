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
		ParavivoAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
		{
				OnHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ParavivoAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
		{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ParavivoAttributeSet->GetBloodAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
		{
				OnBloodChanged.Broadcast(Data.NewValue);
		}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		ParavivoAttributeSet->GetMaxBloodAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
		{
				OnMaxBloodChanged.Broadcast(Data.NewValue);
		}
		);

	Cast<UParavivoAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				//"Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
					GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Red, Msg);

					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}