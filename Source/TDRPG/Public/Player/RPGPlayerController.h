// This Project is Copyrighted as property of Savvas Stones.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IEnemyInterface;

struct FInputActionValue;

/**
 * 
 */
UCLASS()
class TDRPG_API ARPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ARPGPlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
 
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> RpgCharacterContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	
};
