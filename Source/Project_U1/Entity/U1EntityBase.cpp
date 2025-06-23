#include "U1EntityBase.h"
#include "U1HealthComponent.h"
#include "U1StatComponent.h"
#include "Components/WidgetComponent.h"
#include "Project_U1/Entity/U1AttackerComponent.h"

// Sets default values
AU1EntityBase::AU1EntityBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	StatComponent = CreateDefaultSubobject<UU1StatComponent>(TEXT("StatComponent"));
	HealthComponent = CreateDefaultSubobject<UU1HealthComponent>(TEXT("HealthComponent"));
	
	HpBarWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HpBarWidgetComponent"));
	HpBarWidgetComponent->SetupAttachment(RootComponent);
	HpBarWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HpBarWidgetComponent->SetDrawAtDesiredSize(true);
	HpBarWidgetComponent->SetPivot({0.5f, 4.2f});
	static ConstructorHelpers::FClassFinder<UUserWidget> WB_HpBarClass(TEXT("/Game/Blueprints/Widget/WB_HpBar"));
	if (WB_HpBarClass.Succeeded())
	{
		HpBarWidgetComponent->SetWidgetClass(WB_HpBarClass.Class);
	}
}

// Called when the game starts or when spawned
void AU1EntityBase::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<UActorComponent*> Components;
	GetComponents(Components);

	for (UActorComponent* Component : GetComponents())
	{
		if (IU1StatInitializeObject* InitObj = Cast<IU1StatInitializeObject>(Component))
		{
			InitObj->Initialize(StatComponent);
		}
	}
}
// Called every frame
void AU1EntityBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AU1EntityBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AU1EntityBase::ApplyDamage(AActor* Attacker, int Damage)
{
	HealthComponent->ApplyDamage(Attacker, Damage);
	
	// Actor의 모든 컴포넌트를 가져와서 검사
	// TArray<UActorComponent*> Components = GetComponents().Array();
	//
	// for (UActorComponent* Comp : Components)
	// {
	// 	// 해당 컴포넌트가 인터페이스를 구현했는지 확인
	// 	if (Comp && Comp->GetClass()->ImplementsInterface(UU1Damageable::StaticClass()))
	// 	{
	// 		// C++에서는 인터페이스 캐스팅은 이런 식으로
	// 		IU1Damageable* InterfaceComp = Cast<IU1Damageable>(Comp);
	// 		if (InterfaceComp)
	// 		{
	// 			InterfaceComp->ApplyDamage(Attacker, Damage); // 너가 호출하고 싶은 인터페이스 함수
	// 			break; // 하나만 호출하고 끝낼 거면 break
	// 		}
	// 	}
	// }
}

UU1AttackerComponent* AU1EntityBase::GetAttackerComponent()
{
	if (AttackComponent == nullptr)
		AttackComponent = FindComponentByClass<UU1AttackerComponent>();
	
	return AttackComponent;
}
