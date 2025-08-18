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
struct FHitWindow
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	float StartTime = 0.18f;
	UPROPERTY(EditAnywhere)
	float EndTime = 0.33f;
	UPROPERTY(EditAnywhere)
	float Radius = 65.f;
	UPROPERTY(EditAnywhere)
	float Range = 180.f;
	UPROPERTY(EditAnywhere)
	FName Socket = "hand_r";
	UPROPERTY(EditAnywhere)
	TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditAnywhere)
	float Damage = 15.f;
};

USTRUCT(BlueprintType)
struct FComboNode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	FName Id; // "Light_1"
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	UAnimMontage* Montage; // anim that plays
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	bool bUseRootMotion = true;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combo")
	TArray<FHitWindow> HitWindows;
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