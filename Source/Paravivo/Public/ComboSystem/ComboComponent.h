// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

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

	// Called to start a combo sequence from the first node.
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void StartCombo(FName FirstNodeId);

	// Called when the player presses the attack button during a combo.
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void QueueNextCombo(FName NextNodeId);

	// Resets Combo back to idle state.
	UFUNCTION(BlueprintCallable, Category = "Combo")
	void ResetCombo();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// The combo data asset that defines all possible combo moves for this character.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	UComboDataAsset* ComboData;

	//the currently active combo node (nullptr if idle).
	const FComboNode* CurrentNode;

	//Whether we are currently inside a combo animation's input window where the next attack can be queued.
	bool bCanQueueNext;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
