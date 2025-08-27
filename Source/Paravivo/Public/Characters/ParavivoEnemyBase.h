// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "Characters/ParavivoCharacterBase.h"
#include "ParavivoEnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class PARAVIVO_API AParavivoEnemyBase : public AParavivoCharacterBase
{
	GENERATED_BODY()

	public:
	AParavivoEnemyBase();

	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
