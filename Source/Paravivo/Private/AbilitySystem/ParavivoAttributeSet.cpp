// Copyright Paravivo


#include "AbilitySystem/ParavivoAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
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

void UParavivoAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	if (Attribute == GetBloodAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxBlood());
	}
}

void UParavivoAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);
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

void UParavivoAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data,
	FEffectProperties& Props) const
{
	// Source = causer of the effect, Target = target of the effect (owner of this AS)
	
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (!IsValid(Props.SourceASC) && !Props.SourceASC->AbilityActorInfo.IsValid() && !Props.SourceASC->AbilityActorInfo.IsValid())
	{
		return;
	}
	Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
	Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
	if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
	{
		if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
		{
			Props.SourceController = Pawn->GetController();
		}
	}
	if (Props.SourceController != nullptr)
	{
		Props.SourceAvatarActor = Cast<ACharacter>(Props.SourceController->GetPawn());
	}

	if (!Data.Target.AbilityActorInfo.IsValid() && !Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		return;
	}
	Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
	Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
	Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
	Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
}
