// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboSystem/ComboDataAsset.h"


/**
 * Find a combo node in the ComboNodes array that matches the given ID.
 *
 * This is separated into the .cpp file because:
 * - It's not a trivial one-liner getter (has a lambda).
 * - It may change in the future (e.g., partial matching, logging, error handling).
 * - Keeping it in the .cpp reduces compile dependencies if we change its implementation.
 */
const FComboNode* UComboDataAsset::FindNodeById(FName NodeId) const
{
    // Search the array for the first node whose Id matches the given NodeId.
    // The lambda takes each FComboNode and returns true if the Id matches.
 
    // A lambda is an inline, anonymous function 
    // meaning you can write the function code right where you use it, instead of having to declare it somewhere else with a name.
    return ComboNodes.FindByPredicate([&](const FComboNode& Node)
        {
            return Node.Id == NodeId;
        });
}
