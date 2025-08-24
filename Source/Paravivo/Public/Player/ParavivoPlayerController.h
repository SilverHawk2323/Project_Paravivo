// Copyright Paravivo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ParavivoPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class PARAVIVO_API AParavivoPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AParavivoPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> InputContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& InputActionValue);
};
