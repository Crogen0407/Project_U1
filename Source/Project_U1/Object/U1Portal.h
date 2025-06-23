#pragma once

#include "CoreMinimal.h"
#include "U1InteractableObject.h"
#include "U1Portal.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_U1_API AU1Portal : public AU1InteractableObject
{
	GENERATED_BODY()

public:
	AU1Portal();
	
	virtual void Interact(AU1Player* Player) override;
};
