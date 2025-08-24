// Copyright Paravivo


#include "UI/Widget/ParavivoUserWidget.h"

void UParavivoUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
