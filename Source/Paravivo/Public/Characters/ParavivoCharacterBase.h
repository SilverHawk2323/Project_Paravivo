// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ParavivoCharacterBase.generated.h"

UCLASS(Abstract)
class PARAVIVO_API AParavivoCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AParavivoCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
