// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "Characters/ParavivoCharacterBase.h"
#include "ParavivoPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PARAVIVO_API AParavivoPlayerCharacter : public AParavivoCharacterBase
{
	GENERATED_BODY()


public:
	AParavivoPlayerCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	virtual void InitAbilityActorInfo() override;
};

