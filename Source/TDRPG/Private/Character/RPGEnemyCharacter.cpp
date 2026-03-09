// This Project is Copyrighted as property of Savvas Stones.


#include "Character/RPGEnemyCharacter.h"

void ARPGEnemyCharacter::HighlightActor()
{
	bIsHighlighted = true;
	UE_LOG(LogTemp, Warning, TEXT("This Enemy is Highlighted!"));
}

void ARPGEnemyCharacter::UnHighlightActor()
{
	bIsHighlighted = false;
}
