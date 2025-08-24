// Copyright Paravivo


#include "Characters/ParavivoPlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Player/ParavivoPlayerState.h"

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

	//// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AParavivoPlayerCharacter::InitAbilityActorInfo()
{
	
	AParavivoPlayerState* ParavivoPlayerState = GetPlayerState<AParavivoPlayerState>();
	check(ParavivoPlayerState);
	ParavivoPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(ParavivoPlayerState, this);
	AbilitySystemComponent = ParavivoPlayerState->GetAbilitySystemComponent();
	AttributeSet = ParavivoPlayerState->GetAttributeSet();
}
