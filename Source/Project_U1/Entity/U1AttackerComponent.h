#pragma once

#include "CoreMinimal.h"
#include "U1StatComponent.h"
#include "Components/ActorComponent.h"
#include "Project_U1/Stat/U1StatInitializeObject.h"
#include "U1AttackerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECT_U1_API UU1AttackerComponent : public UActorComponent, public IU1StatInitializeObject
{
	GENERATED_BODY()

public:	
	UU1AttackerComponent();

	virtual void Initialize(UU1StatComponent* StatComponent) override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void BeginAttack();

	void AutoAttackLogic(float DeltaTime);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AutoAttack)
	bool AutoAttack;
	bool IsAttacking;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=AutoAttack)
	float AttackDelay = 1.f;
	
	float AttackTimer;

protected:
	UPROPERTY(Transient, BlueprintReadOnly)
	TObjectPtr<UU1StatComponent> CashedStatComponent;
};
