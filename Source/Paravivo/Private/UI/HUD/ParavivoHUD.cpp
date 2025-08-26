// Copyright Paravivo


#include "UI/HUD/ParavivoHUD.h"
#include "UI/Widget/ParavivoUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AParavivoHUD::GetOverlayWidgetController(
	const FWidgetControllerParams& WidgetControllerParams)
{
	//if the overlay widget controller hasn't been created yet...
	if (OverlayWidgetController == nullptr)
	{
		//...create it...
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		// ...and initialise the controller with the gameplay references
		OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);
		OverlayWidgetController->BindCallbacksToDependencies();

		return OverlayWidgetController;
	}
	//if it exists already just return the existing one
	return OverlayWidgetController;
}

void AParavivoHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	//Safety checks : make sure blueprint classes are assigned in BP_ParavivoHUD
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialised, please fill out BP_ParavivoHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialised, please fill out BP_ParavivoHUD"));

	//Create an instance of the Overlay Widget
	UUserWidget* Widget = CreateWidget<UParavivoUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UParavivoUserWidget>(Widget);

	//Build the params needed by the widget controller
	const FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);

	//Create or get the existing Widget Controller
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	//Give the overlay widget a reference to its controller so it can pull data from gameplay systems
	OverlayWidget->SetWidgetController(WidgetController);

	//Call a function to Update the UI with the initial values
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}
