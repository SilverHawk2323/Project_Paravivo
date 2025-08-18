// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboSystem/ComboComponent.h"
#include "ComboSystem/ComboDataAsset.h"
#include "FComboNode.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"

// Sets default values for this component's properties
UComboComponent::UComboComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	CurrentNode = nullptr;

	// ...
}

void UComboComponent::HandleAttackInput()
{
	if (!ComboData) return;

	//If we're already mid combo...
	if (CurrentNode)
	{
		//...Queue next move
		if (CurrentNode->Transitions.Num() > 0)
		{
			QueueNextCombo(CurrentNode->Transitions[0].NextNodeId);
		}
	}
	//If we're not mid combo...
	else if (ComboData->ComboNodes.Num() > 0)
	{
		//...Start a combo
		StartCombo(&ComboData->ComboNodes[0]);
	}
}

void UComboComponent::StartCombo(const FComboNode* FirstNode)
{
	PlayComboNode(FirstNode);
}

void UComboComponent::QueueNextCombo(FName DesiredNextId)
{
	const FComboNode* NextNode = ComboData->FindNodeById(DesiredNextId);
	if (NextNode)
	{
		QueuedNode = NextNode;
	}
}

void UComboComponent::PlayComboNode(const FComboNode* Node)
{
	if (!Node || !Node->AttackMontage) return;

	CurrentNode = Node;
	QueuedNode = nullptr; // clear it so it doesn't re-play or block new inputs

	ACharacter* OwnerChar = Cast<ACharacter>(GetOwner());
	if (OwnerChar && OwnerChar->GetMesh() && OwnerChar->GetMesh()->GetAnimInstance())
	{
		OwnerChar->GetMesh()->GetAnimInstance()->Montage_Play(Node->AttackMontage);
	}
}

void UComboComponent::OnComboWindowOpened()
{
	if (QueuedNode)
	{
		PlayComboNode(QueuedNode);
	}
}

void UComboComponent::OnComboWindowClosed()
{
	QueuedNode = nullptr; // clear it so it doesn't play or block new inputs
	CurrentNode = nullptr; // clear when the window closes and the combo is reset
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

