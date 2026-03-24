// This Project is Copyrighted as property of Savvas Stones.


#include "UI/Widget/RPGUserWidget.h"

void URPGUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
