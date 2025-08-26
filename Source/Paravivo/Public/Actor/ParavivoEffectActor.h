// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParavivoEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class PARAVIVO_API AParavivoEffectActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AParavivoEffectActor();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};
