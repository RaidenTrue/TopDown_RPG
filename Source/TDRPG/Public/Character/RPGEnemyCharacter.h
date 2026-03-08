// This Project is Copyrighted as property of Savvas Stones.

#pragma once

#include "CoreMinimal.h"
#include "Character/RPGCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "RPGEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TDRPG_API ARPGEnemyCharacter : public ARPGCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
};
