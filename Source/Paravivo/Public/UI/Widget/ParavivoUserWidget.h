// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ParavivoUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PARAVIVO_API UParavivoUserWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
