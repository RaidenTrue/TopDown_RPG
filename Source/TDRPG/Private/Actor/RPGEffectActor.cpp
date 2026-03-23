// This Project is Copyrighted as property of Savvas Stones.


#include "Actor/RPGEffectActor.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/RPGAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
ARPGEffectActor::ARPGEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshRoot");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ARPGEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/* TODO: Change this to Apply a GameplayEffect, as now I'm using a const_cast as a temp workaround. */
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const URPGAttributeSet* RPGAttributeSet = Cast<URPGAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(URPGAttributeSet::StaticClass()));

		URPGAttributeSet* MutableRPGAttributeSet = const_cast<URPGAttributeSet*>(RPGAttributeSet);
		MutableRPGAttributeSet->SetHealth(RPGAttributeSet->GetHealth() + 50.f);
		Destroy();
	}
}

void ARPGEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

// Called when the game starts or when spawned
void ARPGEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARPGEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ARPGEffectActor::EndOverlap);
}

