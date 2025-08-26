// Copyright Paravivo


#include "UI/WidgetController/ParavivoWidgetController.h"

void UParavivoWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void UParavivoWidgetController::BroadcastInitialValues()
{
	
}

void UParavivoWidgetController::BindCallbacksToDependencies()
{
	
}
