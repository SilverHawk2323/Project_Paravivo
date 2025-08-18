// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimMontage.h"


#include "FComboNode.generated.h"

/**
 * Structs related to the combo's
 */
UENUM(BlueprintType)
enum class EAttackType : uint8 { Light, Heavy, Counter, Finisher };

USTRUCT(BlueprintType)
struct FComboTransition
{
	GENERATED_BODY()
	// e.g., "Light_2"
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	FName NextNodeId;   
	bool bAllowDirectionalSwitch = true;
};


USTRUCT(BlueprintType)
struct FComboNode
{
	GENERATED_BODY()
	// "Light_1"
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	FName Id;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	float DamageAmount;
	// anim that plays
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	UAnimMontage* AttackMontage; 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	bool bUseRootMotion = true;
	// The next attack that can play
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	TArray<FComboTransition> Transitions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	float CameraImpulse = 0.6f;  // camera kick
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	float HitStopMs = 75.f;  // per-hit freeze
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	float TargetAssistAngle = 60.f; // degrees
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	float TargetAssistRange = 900.f; // cm
};