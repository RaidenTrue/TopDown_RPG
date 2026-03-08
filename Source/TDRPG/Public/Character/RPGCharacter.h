// This Project is Copyrighted as property of Savvas Stones.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGCharacterBase.h"
#include "RPGCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class TDRPG_API ARPGCharacter : public ARPGCharacterBase
{
	GENERATED_BODY()

public:

	ARPGCharacter();


protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCamera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerCamera")
	UCameraComponent* Camera;

private:
	
};
