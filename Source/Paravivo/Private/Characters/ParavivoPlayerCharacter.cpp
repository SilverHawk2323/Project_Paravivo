// Copyright Paravivo


#include "Characters/ParavivoPlayerCharacter.h"

#include "AbilitySystem/ParavivoAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/ParavivoPlayerController.h"
#include "Player/ParavivoPlayerState.h"
#include "UI/HUD/ParavivoHUD.h"

AParavivoPlayerCharacter::AParavivoPlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
}

void AParavivoPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AParavivoPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AParavivoPlayerCharacter::InitAbilityActorInfo()
{
	
	AParavivoPlayerState* ParavivoPlayerState = GetPlayerState<AParavivoPlayerState>();
	check(ParavivoPlayerState);
	ParavivoPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(ParavivoPlayerState, this);
	Cast<UParavivoAbilitySystemComponent>(ParavivoPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = ParavivoPlayerState->GetAbilitySystemComponent();
	AttributeSet = ParavivoPlayerState->GetAttributeSet();

	if (AParavivoPlayerController* ParavivoPlayerController = Cast<AParavivoPlayerController>(GetController()))
	{
		if (AParavivoHUD* ParavivoHUD = Cast<AParavivoHUD>(ParavivoPlayerController->GetHUD()))
		{
			ParavivoHUD->InitOverlay(ParavivoPlayerController, ParavivoPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
