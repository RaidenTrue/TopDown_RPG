// This Project is Copyrighted as property of Savvas Stones.


#include "Character/RPGCharacter.h"
#include "Camera/CameraComponent.h"
#include "Player/RPGPlayerState.h"
#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ARPGCharacter::ARPGCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 700.f;
	CameraBoom->bEnableCameraLag = true;

	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritYaw = false;
	CameraBoom->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	Camera->SetupAttachment(CameraBoom);
}

void ARPGCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	/* Init AbilityActorInfo for the Server. */
	InitAbilityActorInfo();
}

void ARPGCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	/* Init AbilityActorInfo for the Client. */
	InitAbilityActorInfo();
}

void ARPGCharacter::InitAbilityActorInfo()
{
	ARPGPlayerState* RpgPlayerState = GetPlayerState<ARPGPlayerState>();
	check(RpgPlayerState);
	RpgPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(RpgPlayerState, this);

	AbilitySystemComponent = RpgPlayerState->GetAbilitySystemComponent();
	AttributeSet = RpgPlayerState->GetAttributeSet();
}
