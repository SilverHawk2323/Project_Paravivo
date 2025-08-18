// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "I_Attacker.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimMontage.h"
#include "AttacksComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARAVIVO_API UAttacksComponent : public UActorComponent, public II_Attacker
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttacksComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Attack")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Attack")
	UAnimMontage* AttackMontage;

	UPROPERTY(BlueprintReadOnly, Category= "Attack")
	AActor* DamagedActor;

	void AttackStart_Implementation(AActor* AttackTarget) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
