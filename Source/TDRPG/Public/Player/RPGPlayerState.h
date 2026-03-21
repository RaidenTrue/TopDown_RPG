// This Project is Copyrighted as property of Savvas Stones.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "RPGPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class TDRPG_API ARPGPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	ARPGPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
