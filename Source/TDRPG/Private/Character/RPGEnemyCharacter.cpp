// This Project is Copyrighted as property of Savvas Stones.


#include "Character/RPGEnemyCharacter.h"
#include "TDRPG/TDRPG.h"

ARPGEnemyCharacter::ARPGEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void ARPGEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void ARPGEnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
