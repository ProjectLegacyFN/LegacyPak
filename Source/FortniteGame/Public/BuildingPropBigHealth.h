#pragma once
#include "CoreMinimal.h"
#include "BuildingProp.h"
#include "BuildingPropBigHealth.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class ABuildingPropBigHealth : public ABuildingProp {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_BigHealth, meta=(AllowPrivateAccess=true))
	int32 BigHealth;
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
	int32 BigHealthMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowHealthBar;
    
    ABuildingPropBigHealth();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetBigHealthMax(int32 NewHealth);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetBigHealth(int32 NewHealth);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_BigHealth();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetHealthValueText();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthValuePercent();
    
};

