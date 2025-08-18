// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComboSystem/ComboDataAsset.h"
#include "FComboNode.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"

#include "ComboComponent.generated.h"

class UComboDataAsset;
struct FComboNode;

/**
 * UComboComponent
 *
 * Handles executing and transitioning between combo nodes during combat.
 * Works with a UComboDataAsset to determine which animations to play and when to transition.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARAVIVO_API UComboComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComboComponent();

	// The combo data asset that defines all possible combo moves for this character.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	UComboDataAsset* ComboData;

	//the currently active combo node (nullptr if idle).
	const FComboNode* CurrentNode;

	//The next node requested from input
	const FComboNode* QueuedNode;

	UFUNCTION(BlueprintCallable)
	void HandleAttackInput();

	void StartCombo(const FComboNode* FirstNode);
	void QueueNextCombo(FName DesiredNextId);
	void PlayComboNode(const FComboNode* Node);

	UFUNCTION(BlueprintCallable)
	void OnComboWindowOpened();

	UFUNCTION(BlueprintCallable)
	void OnComboWindowClosed();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
