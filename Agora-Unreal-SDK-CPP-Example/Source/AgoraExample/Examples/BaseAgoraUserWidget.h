// Copyright(c) 2024 Agora.io. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFrameWork/PlayerController.h"
#include <string>
#include "Async/Async.h"
#include "BaseAgoraUserWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class AGORAEXAMPLE_API UBaseAgoraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void InitAgoraWidget(FString APP_ID, FString TOKEN, FString CHANNEL_NAME);


protected:
	void NativeConstruct() override;

};
