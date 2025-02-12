#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=TextBlock -FallbackName=TextBlock
#include "TextBlock.h"
#include "Templates/SubclassOf.h"
#include "CommonTextBlock.generated.h"

class UCommonTextScrollStyle;
class UCommonTextStyle;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=CommonUI)
class COMMONUI_API UCommonTextBlock : public UTextBlock {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCommonTextStyle> Style;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCommonTextScrollStyle> ScrollStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayAllCaps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoCollapseWithEmptyText;
    
public:
    UCommonTextBlock();
    UFUNCTION(BlueprintCallable)
    void SetWrapTextWidth(int32 InWrapTextAt);
    
    UFUNCTION(BlueprintCallable)
    void SetTextCase(bool bUseAllCaps);
    
    UFUNCTION(BlueprintCallable)
    void SetStyle(TSubclassOf<UCommonTextStyle> InStyle);
    
    UFUNCTION(BlueprintCallable)
    void ResetScrollState();
    
};

