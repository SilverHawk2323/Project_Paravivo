// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboSystem/ComboComponent.h"
#include "ComboSystem/ComboDataAsset.h"
#include "FComboNode.h"
#include "GameFramework/Actor.h"
#include "Animation/AnimInstance.h"

// Sets default values for this component's properties
UComboComponent::UComboComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	CurrentNode = nullptr;
	bCanQueueNext = false;

	// ...
}

void UComboComponent::StartCombo(FName FirstNodeId)
{
	if (!ComboData)
	{
		UE_LOG(LogTemp, Warning, TEXT("No combo data assigned."));
		return;
	}

	// Look up the first node in the combo set
	CurrentNode = ComboData->FindNodeById(FirstNodeId);

	if (CurrentNode)
	{
		// Play the animation montage for the first node
		if (AActor* Owner = GetOwner())
		{
			if (UAnimInstance* AnimInst = Owner->FindComponentByClass<USkeletalMeshComponent>()->GetAnimInstance())
			{
				AnimInst->Montage_Play(CurrentNode->Montage);
			}
		}

		// Allow queuing for next input during this animation's hit window
		bCanQueueNext = true;
	}
}

void UComboComponent::QueueNextCombo(FName NextNodeId)
{
	if (!bCanQueueNext || !ComboData)
	{
		return; // Can't queue next attack yet
	}

	const FComboNode* NextNode = ComboData->FindNodeById(NextNodeId);
	if (NextNode)
	{
		// Transition to next attack
		CurrentNode = NextNode;

		if (AActor* Owner = GetOwner())
		{
			if (UAnimInstance* AnimInst = Owner->FindComponentByClass<USkeletalMeshComponent>()->GetAnimInstance())
			{
				AnimInst->Montage_Play(CurrentNode->Montage);
			}
		}

		// Reset queue window until next animation allows it again
		bCanQueueNext = false;
	}
}

void UComboComponent::ResetCombo()
{
	CurrentNode = nullptr;
	bCanQueueNext = false;
}


// Called when the game starts
void UComboComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComboComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

