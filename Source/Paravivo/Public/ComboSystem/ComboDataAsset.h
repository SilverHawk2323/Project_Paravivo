// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FComboNode.h"

#include "ComboDataAsset.generated.h"

/**
 * UComboDataAsset
 *
 * A data asset that stores a list of combo nodes for an attack combo system.
 * Each node contains information about the animation montage, hit windows, and transitions.
 *
 * Placing this data in a Data Asset allows designers to configure combos in the editor
 * without changing C++ code.
 */
UCLASS(BlueprintType)
class PARAVIVO_API UComboDataAsset : public UDataAsset
{
	GENERATED_BODY()
	

public:

	//All combo nodes available in this combo set. Designers can reorder or edit them in the editor.
	UPROPERTY(EditAnywhere, BlueprintReadOnly = Category = "Combo")
	TArray<FComboNode> ComboNodes;


	/**
	 * Finds a combo node by its unique ID.
	 *
	 * @param NodeId The name/ID of the node to find.
	 * @return Pointer to the node if found, nullptr otherwise.
	 */
	const FComboNode* FindNodeById(FName NodeId) const;
};
