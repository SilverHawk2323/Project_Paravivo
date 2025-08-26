// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ParavivoHUD.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UOverlayWidgetController;
class UParavivoUserWidget;
struct FWidgetControllerParams;
/**
 * Custom HUD class for the game
 *
 * This HUD manages the creation and initilisation of the overlay UI (HUD Widgets)
 * It also owns and initialises the OverlayWidgetController, which connects gameplay data
 * to the OverlayWidget.
 */
UCLASS()
class PARAVIVO_API AParavivoHUD : public AHUD
{
	GENERATED_BODY()

public:

	/* Instance of the OverlayWidget currently on screen*/
	UPROPERTY()
	TObjectPtr<UParavivoUserWidget> OverlayWidget;

	/* Returns the OverlayWidgetController, creating it if it doesn't exist yet */
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams);

	/* Initialises the overlay UI and binds it to gameplay systems */
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:

	/* The class used to spawn the OverlayWidget (set in blueprint) */
	UPROPERTY(EditAnywhere)
	TSubclassOf<UParavivoUserWidget> OverlayWidgetClass;

	/* The instance of the OverlayWidgetController, created at runtime */
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	/* The class used to spawn the OverlayWidgetController (set in bluerpint) */
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
