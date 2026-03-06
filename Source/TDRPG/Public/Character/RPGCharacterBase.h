// This Project is Copyrighted as property of Savvas Stones.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RPGCharacterBase.generated.h"

UCLASS(Abstract)
class TDRPG_API ARPGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	ARPGCharacterBase();

protected:
	
	virtual void BeginPlay() override;

};
