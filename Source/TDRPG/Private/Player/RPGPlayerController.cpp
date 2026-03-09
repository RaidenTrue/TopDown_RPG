// This Project is Copyrighted as property of Savvas Stones.


#include "Player/RPGPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

ARPGPlayerController::ARPGPlayerController()
{
	bReplicates = true;
}

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(RpgCharacterContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(RpgCharacterContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);

	SetInputMode(InputModeData);
}

void ARPGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARPGPlayerController::Move);
}

void ARPGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ARPGPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControllerPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ARPGPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();


	/* Line trace from Cursor. There are a few scenarios: 
	 * A: LastActor is null && ThisActor is null.
	 *    - Do Nothing. 
	 * B: LastActor is null && ThisActor is valid.
	 *    - Highlight ThisActor. 
	 * C: LastActor is valid && ThisActor is null. 
	 *    - UnHighlight LastActor. 
	 * D: Both actors are valid, but LastActor != ThisActor. 
	 *    - UnHighlight LastActor && Highlight ThisActor. 
	 * E: Both actors are valid and are the same actor.
	 *    - Do Nothing. 
	 */

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			/* Case B. */
			ThisActor->HighlightActor();
		}
		else
		{
			/* Case A - Both are null, do nothing */
		}
	}
	else /* LastActor is valid*/
	{
		if (ThisActor == nullptr)
		{
			/* Case C.*/
			LastActor->UnHighlightActor();
		}
		else /* BothActors are valid. */
		{
			if (LastActor != ThisActor)
			{
				/* Case D. */
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				/* Case E - Do nothing. */
			}
		}
	}
}
