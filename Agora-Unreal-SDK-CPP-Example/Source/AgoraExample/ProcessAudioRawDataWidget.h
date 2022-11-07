// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAgoraUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "AgoraPluginInterface.h"
#include "Sound/SoundWaveProcedural.h"
#include "AgoraSoundWaveProcedural.h"
#include "Components/AudioComponent.h"
#if PLATFORM_ANDROID
#include "AndroidPermission/Classes/AndroidPermissionFunctionLibrary.h"
#endif
#include "ProcessAudioRawDataWidget.generated.h"

using namespace agora::rtc;
using namespace agora;
/**
 * 
 */
UCLASS(Abstract)
class AGORAEXAMPLE_API UProcessAudioRawDataWidget : public UBaseAgoraUserWidget, public agora::rtc::IRtcEngineEventHandlerEx, public agora::media::IAudioFrameObserver
{
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* JoinBtn = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UButton* LeaveBtn = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* BackHomeBtn = nullptr;

	void CheckAndroidPermission();

	UFUNCTION(BlueprintCallable)
	void OnJoinButtonClick();

	UFUNCTION(BlueprintCallable)
	void OnLeaveButtonClick();

	class UAgoraSoundWaveProcedural* AgoraSoundWaveProcedural;

	class UAudioComponent* AgoraSound;

	void InitAgoraWidget(FString APP_ID, FString TOKEN, FString CHANNEL_NAME) override;

	void NativeDestruct() override;

	void onUserJoined(const RtcConnection& connection,agora::rtc::uid_t uid, int elapsed) override;

	void onJoinChannelSuccess(const RtcConnection& connection, int elapsed) override;

	bool onPlaybackAudioFrameBeforeMixing(const char* channelId, agora::rtc::uid_t uid, agora::media::IAudioFrameObserverBase::AudioFrame& audioFrame) override;
	bool onRecordAudioFrame(const char* channelId, agora::media::IAudioFrameObserverBase::AudioFrame& audioFrame) override;
	bool onPlaybackAudioFrame(const char* channelId, agora::media::IAudioFrameObserverBase::AudioFrame& audioFrame) override;
	bool onMixedAudioFrame(const char* channelId, agora::media::IAudioFrameObserverBase::AudioFrame& audioFrame) override;
	int getObservedAudioFramePosition() override;
	agora::media::IAudioFrameObserverBase::AudioParams getPlaybackAudioParams() override;
	agora::media::IAudioFrameObserverBase::AudioParams getRecordAudioParams() override;
	agora::media::IAudioFrameObserverBase::AudioParams getMixedAudioParams() override;

private:

	agora::rtc::IRtcEngine* RtcEngineProxy;

	agora::media::IMediaEngine* MediaEngine;

	FString AppId;

	FString Token;

	FString ChannelName;

	agora::media::IAudioFrameObserverBase::AudioParams audioParams;

	void SetButtonClickAble(bool enable);

	void InitAgoraEngine(FString APP_ID, FString TOKEN, FString CHANNEL_NAME);

	void SetUpUIEvent();

	void InitConfig();

	int SAMPLE_RATE = 32000; // this should = CLIP_SAMPLES x PULL_FREQ_PER_SEC

	int CHANNEL = 1; 

};
