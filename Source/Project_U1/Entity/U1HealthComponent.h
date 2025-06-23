#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Project_U1/DamageCaster/U1Damageable.h"
#include "Project_U1/Stat/U1StatInitializeObject.h"
#include "U1HealthComponent.generated.h"

class UU1StatComponent;

DECLARE_EVENT_TwoParams(UU1HealthComponent, FHealthChangedEvent, float, float)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_U1_API UU1HealthComponent : public UActorComponent, public IU1Damageable, public IU1StatInitializeObject
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UU1HealthComponent();

	virtual void Initialize(UU1StatComponent* StatComponent) override;

	float GetHealthPercentage() const;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	virtual void ApplyDamage(AActor* Attacker, int Damage) override;
	virtual void OnDie() override;

public:
	FHealthChangedEvent HealthChangedEvent;
	
protected:
	UPROPERTY(Transient)
	UU1StatComponent* CashedStatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HealthCopmonent)
	int CurrentHealth;
};
