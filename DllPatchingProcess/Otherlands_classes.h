#pragma once

// Name: p, Version: 1.0.0

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
// Classes
//---------------------------------------------------------------------------

// Class Otherlands.AbilityComponent
// 0x0500 (0x05F0 - 0x00F0)
class UAbilityComponent : public UActorComponent
{
public:
	TEnumAsByte<EAbilityCastingState>                  CastState;                                                // 0x00F0(0x0001) (BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00F1(0x0007) MISSED OFFSET
	struct FName                                       AbilityId;                                                // 0x00F8(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	class ABasicCharacter*                             CharacterOwner;                                           // 0x0100(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bHasPhaseProcessed;                                       // 0x0108(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0109(0x0003) MISSED OFFSET
	float                                              CurrentChargeTime;                                        // 0x010C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              CurrentActionTime;                                        // 0x0110(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0114(0x0004) MISSED OFFSET
	struct FCastAction                                 LastCastAction;                                           // 0x0118(0x0060) (Edit, BlueprintVisible, BlueprintReadOnly)
	class UPrerequisiteInstance*                       CastPrereqInstance;                                       // 0x0178(0x0008) (ZeroConstructor, IsPlainOldData)
	class AMainGameMode*                               GameMode;                                                 // 0x0180(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x468];                                     // 0x0188(0x0468) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AbilityComponent");
		return ptr;
	}


	bool TriggerPhase(int Phase);
	bool StartAction();
	void StartAbilityCooldown(float Length);
	bool StartAbility();
	bool ShouldPreventMovement();
	void SetPreventMovement(bool Prevent);
	void ServerProcessPhase(int Phase);
	void ServerFinishAbility();
	void ServerAbortAbility();
	void SafeAbilityCleanup();
	bool ProcessPhase(int Phase);
	void PlayStartFX();
	void PlayChargeFX();
	void PlayCastFX();
	void OnRep_AbilityId();
	void NotifySpellResolved(const struct FVector& TargetLocation);
	void NotifyProjectileImpact(const struct FVector& ImpactLocation);
	void NotifyPhaseProcessed(int Phase);
	void NotifyGravityApplied(class AGameProjectile* Projectile, const struct FVector& CurrentLocation);
	void MulticastPlayStartFX();
	void MulticastPlayChargeFX();
	void MulticastPlayCastFX();
	void MulticastAbilityCleanup();
	bool IsEngaged();
	bool IsCharging();
	bool IsCasting();
	bool InitializeAbility(const struct FAbilityData& AbilityData);
	float GetPingOffset();
	float GetCreatureHaste();
	float GetCooldownRemaining();
	struct FAbilityData GetBaseAbilityData();
	bool FinishAbility();
	bool EvaluateCastPrereq(class UObject* Target);
	bool DidProcess();
	void CastFailed(ECastActionErrorType ErrorType);
	bool CanUse(bool bCheckCooldown);
	bool CanAffectTarget(class UObject* Target);
	float CalculateGlobalCooldownTime();
	float CalculateChargeTime();
	float CalculateActionTime();
	float CalculateAbilityCoolupTime();
	float CalculateAbilityCooldownTime();
	bool BeginChargeAbility();
	void AffectedTargets(TArray<class UObject*> Targets);
	bool AbortAbility();
	void AbilityCleanup();
};


// Class Otherlands.AccountService
// 0x0020 (0x0048 - 0x0028)
class UAccountService : public UObject
{
public:
	struct FString                                     AccountEndpoint;                                          // 0x0028(0x0010) (ZeroConstructor, Config)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0038(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AccountService");
		return ptr;
	}


	void GetFavoriteServerList(const struct FScriptDelegate& Delegate);
	void DeleteFavoriteServer(const struct FString& ServerId, const struct FScriptDelegate& Delegate);
	void AddFavoriteServer(const struct FFavoriteServerAddRequest& AddRequest, const struct FScriptDelegate& Delegate);
};


// Class Otherlands.ActionComponent
// 0x0040 (0x0130 - 0x00F0)
class UActionComponent : public UActorComponent
{
public:
	TScriptInterface<class UActionOwnerInterface>      ActionOwner;                                              // 0x00F0(0x0030) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0100(0x0010) MISSED OFFSET
	class UAnimMontage*                                ActiveMontage;                                            // 0x0110(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       ActionName;                                               // 0x0118(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bInitialized;                                             // 0x0120(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0xF];                                       // 0x0121(0x000F) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ActionComponent");
		return ptr;
	}


	float UpdateActiveMontage(class UAnimMontage* NewMontage, float PlayLength, float PlayRateScalar, float MaxPlayLength);
	bool StopAction(bool bForce);
	void StartActionTimer(float ActionTime);
	bool StartActionSimple();
	bool StartActionSecondary(bool bFromInput);
	bool StartActionRepeat();
	bool StartActionQueued();
	bool StartActionPrimary(bool bFromInput);
	void ServerStopAction(bool bForce);
	void ServerStartActionSimple();
	void SafeActionCleanup(TEnumAsByte<EActionCleanupReason> Reason);
	void PlayAndRegisterActionMontage();
	void OnRep_Initialized();
	void OnInitialized();
	void OnFinished(bool bTimeOut);
	void OnActionTimeOut();
	void OnActionNotifyWithParam(TEnumAsByte<EActionNotifyType> NotifyType, int IntParam);
	void OnActionNotify(TEnumAsByte<EActionNotifyType> NotifyType);
	void MulticastUpdateActiveMontage(class UAnimMontage* NewMontage, float PlayLength, float PlayRateScalar, float MaxPlayLength);
	void MulticastOnInitialized();
	void MulticastActionCleanup(TEnumAsByte<EActionCleanupReason> Reason);
	bool IsProcessing(bool bAllowSlack);
	bool IsAtiveAction();
	bool Initialize(const struct FName& InActionName);
	float GetServerPingOffset();
	float GetLagAmount();
	float GetClientPingOffset();
	float GetBothPingOffset();
	float GetActionTimeRemaining(bool bAllowSlack);
	class UAnimMontage* GetActionMontage();
	bool CanRepeat();
	bool CanQueue();
	bool CanInterrupt();
	bool CanDo();
	bool CanAbort();
	float CalculateActionSpeed();
	bool AllowEarlyFinish();
	bool ActionCleanup(TEnumAsByte<EActionCleanupReason> Reason);
};


// Class Otherlands.ActionOwnerInterface
// 0x0000 (0x0028 - 0x0028)
class UActionOwnerInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ActionOwnerInterface");
		return ptr;
	}


	bool SetActiveAction(class UActionComponent* NewAction);
	void OnActionFinished(class UActionComponent* FinishedAction);
	float GetServerPingOffset();
	class UActionComponent* GetLastActiveAction();
	float GetClientPingOffset();
	float GetBothPingOffset();
	class UActionComponent* GetActiveAction();
	class UActionComponent* GetActionByName(const struct FName& ActionName, class UClass* ActionClass);
	class UAnimInstance* GetActionAnimInstance();
	bool ClearActiveAction(class UActionComponent* OldAction);
};


// Class Otherlands.AIBehaviorInterface
// 0x0000 (0x0028 - 0x0028)
class UAIBehaviorInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AIBehaviorInterface");
		return ptr;
	}

};


// Class Otherlands.TrackTargetDataWrapper
// 0x0030 (0x0058 - 0x0028)
class UTrackTargetDataWrapper : public UObject
{
public:
	struct FTrackTargetData                            Data;                                                     // 0x0028(0x0030) (BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TrackTargetDataWrapper");
		return ptr;
	}

};


// Class Otherlands.BasicCharacter
// 0x0550 (0x0CA0 - 0x0750)
class ABasicCharacter : public ACharacter
{
public:
	unsigned char                                      UnknownData00[0x40];                                      // 0x0750(0x0040) MISSED OFFSET
	float                                              StrafeSpeedMultiplier;                                    // 0x0790(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              BackwardSpeedMultiplier;                                  // 0x0794(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CrouchStrafeSpeedMultiplier;                              // 0x0798(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CrouchBackwardSpeedMultiplier;                            // 0x079C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              WalkStrafeSpeedMultiplier;                                // 0x07A0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              WalkBackwardSpeedMultiplier;                              // 0x07A4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxAimOffsetYaw;                                          // 0x07A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              AimOffsetYaw;                                             // 0x07AC(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	float                                              AimOffsetPitch;                                           // 0x07B0(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	bool                                               bShouldStrafe;                                            // 0x07B4(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterMoveSpeed>                   MoveSpeedEnum;                                            // 0x07B5(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFollowSurfacePitch;                                      // 0x07B6(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFollowSurfaceRoll;                                       // 0x07B7(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                WeaponSwapMontage;                                        // 0x07B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UAnimMontage*                                UnarmedAttackMontage;                                     // 0x07C0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UAnimMontage*                                UnarmedAttackOffhandMontage;                              // 0x07C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              UnarmedHarvestDamage;                                     // 0x07D0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x07D4(0x0004) MISSED OFFSET
	class UAnimationAsset*                             DeathPose;                                                // 0x07D8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bIsDead;                                                  // 0x07E0(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x07E1(0x0007) MISSED OFFSET
	class UResourceComponent*                          LootResourceComp;                                         // 0x07E8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UGameCharacterMovementComponent*             GameCharacterMovementComp;                                // 0x07F0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBuffComponent*                              BuffComponent;                                            // 0x07F8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UGearComponent*                              GearComponent;                                            // 0x0800(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USpellCastComponent*                         SpellCastComponent;                                       // 0x0808(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class URangedWeaponComponent*                      RangedWeaponComponent;                                    // 0x0810(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAudioComponent*                             AudioComponent;                                           // 0x0818(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bIsSprinting;                                             // 0x0820(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0xB];                                       // 0x0821(0x000B) MISSED OFFSET
	bool                                               bIsCrouching;                                             // 0x082C(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x3];                                       // 0x082D(0x0003) MISSED OFFSET
	class UCharacterStats*                             CharacterStats;                                           // 0x0830(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAmbientStatComponent*                       AmbientStatComponent;                                     // 0x0838(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              StealthInDelay;                                           // 0x0840(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              SmoothedClientStealthedRatio;                             // 0x0844(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ClientStealthedRatio;                                     // 0x0848(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x084C(0x0004) MISSED OFFSET
	class AMainGameMode*                               GameMode;                                                 // 0x0850(0x0008) (ZeroConstructor, IsPlainOldData)
	class AMainGameState*                              GameState;                                                // 0x0858(0x0008) (ZeroConstructor, IsPlainOldData)
	class UParticleSystemComponent*                    SpellParticleSystem;                                      // 0x0860(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAudioComponent*                             SpellAudioComp;                                           // 0x0868(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class AActor*                                      SpellPointLight;                                          // 0x0870(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UStaticMeshComponent*                        PlaceableTestComponent;                                   // 0x0878(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TEnumAsByte<ESpiritRealmState>                     InSpiritRealmState;                                       // 0x0880(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x7];                                       // 0x0881(0x0007) MISSED OFFSET
	class UMaterialInterface*                          SpiritMaterial;                                           // 0x0888(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsRunning;                                               // 0x0890(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x3];                                       // 0x0891(0x0003) MISSED OFFSET
	float                                              RunVeloctiyThreshold;                                     // 0x0894(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UNavigationInvokerComponent*                 NavInvoker;                                               // 0x0898(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	int                                                CharacterStatusFlags;                                     // 0x08A0(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData08[0x4];                                       // 0x08A4(0x0004) MISSED OFFSET
	TArray<int>                                        BuffCategoryImmunity;                                     // 0x08A8(0x0010) (Net, ZeroConstructor, Transient)
	TArray<class UBuffCategoryDelegates*>              BuffCategoryDelegates;                                    // 0x08B8(0x0010) (ZeroConstructor, Transient)
	bool                                               bNewlySpawned;                                            // 0x08C8(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData09[0x3];                                       // 0x08C9(0x0003) MISSED OFFSET
	float                                              ServerActorTickInterval;                                  // 0x08CC(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ExpectedServerFrameRate;                                  // 0x08D0(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x7C];                                      // 0x08D4(0x007C) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnDeathEvent;                                             // 0x0950(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnRespawnEvent;                                           // 0x0960(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTakeDamageEvent;                                        // 0x0970(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDoDamageEvent;                                          // 0x0980(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTakeHealEvent;                                          // 0x0990(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTakeDetailedDamageEvent;                                // 0x09A0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDoDetailedDamageEvent;                                  // 0x09B0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMissEvent;                                              // 0x09C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnHitEvent;                                               // 0x09D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTakeHitEvent;                                           // 0x09E0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnKillOtherEvent;                                         // 0x09F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnKillAssistEvent;                                        // 0x0A00(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeEvent;                                 // 0x0A10(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeHealthEvent;                           // 0x0A20(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeStaminaEvent;                          // 0x0A30(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeMountStaminaEvent;                     // 0x0A40(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeEnergyEvent;                           // 0x0A50(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeBodyTempEvent;                         // 0x0A60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeHydrationEvent;                        // 0x0A70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatChangeImmobilizeEvent;                       // 0x0A80(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatWeightEvent;                                 // 0x0A90(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInstantStatNoiseEvent;                                  // 0x0AA0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnSpiritRealmEvent;                                       // 0x0AB0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAbilityStartEvent;                                      // 0x0AC0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAbilityFinishEvent;                                     // 0x0AD0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAbilityAbortEvent;                                      // 0x0AE0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInteractEvent;                                          // 0x0AF0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnFireEvent;                                              // 0x0B00(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnReloadEvent;                                            // 0x0B10(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnBuffsChangedEvent;                                      // 0x0B20(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnBuffAppliedEvent;                                       // 0x0B30(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnBuffRemovedEvent;                                       // 0x0B40(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnApplyBuffOtherEvent;                                    // 0x0B50(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnBuffTriggerEvent;                                       // 0x0B60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCharacterStatusChangeEvent;                             // 0x0B70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCharacterReportNoiseEvent;                              // 0x0B80(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	bool                                               bBuffsChanged;                                            // 0x0B90(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x3F];                                      // 0x0B91(0x003F) MISSED OFFSET
	float                                              TargetCharacterScale;                                     // 0x0BD0(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              TargetCharacterScaleTime;                                 // 0x0BD4(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData12[0x38];                                      // 0x0BD8(0x0038) MISSED OFFSET
	class UMaterialInstanceDynamic*                    GlowDynamicMaterial;                                      // 0x0C10(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      LastDamageDealer;                                         // 0x0C18(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData13[0x8];                                       // 0x0C20(0x0008) MISSED OFFSET
	class USoundAttenuation*                           NoiseAttenuation;                                         // 0x0C28(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData14[0x70];                                      // 0x0C30(0x0070) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BasicCharacter");
		return ptr;
	}


	void UpdateTerrainFollow(float DeltaTime, bool bFloorChanged);
	void SetSprint(bool bSet);
	void SetInSpiritRealm(bool bSet);
	bool SetDead(bool bSet);
	void SetCharacterScale(float NewScale);
	void ServerToggleWalk(bool bSet);
	void ServerSetSprint(bool bSet);
	void ServerSetCrouching(bool bSet);
	float ProcessTameDamage(float TameDamage, class APlayerCharacter* Tamer);
	void ProcessMoveForwardInput(float InputValue);
	void OnTickStatUnpauseTimer(int Index);
	void OnTickStatTimer(int Index);
	void OnRep_IsSprinting();
	void OnRep_InSpiritRealm(TEnumAsByte<ESpiritRealmState> OldState);
	void OnEnterLeaveSpiritWorld(bool bInSpiritWorld);
	void MulticastPlayMaterialGlow(class UMaterialInterface* SourceMat, class UCurveFloat* Curve, const struct FName& MaterialParameter, bool bHideWhenComplete);
	void MulticastPlayCharacterEffect(TEnumAsByte<ECharacterEffect> EffectType);
	void MulticastModifyLerpScale(float Scalar, float ScaleDelay);
	void MulticastIsDeadChanged(bool bNewIsDead);
	void KillCharacter(class AActor* Killer, TEnumAsByte<EDamageSourceType> DmamageType, const struct FName& SourceId);
	bool IsOutcast();
	bool IsMounted();
	bool HasPlayedRootMotionRecently();
	struct FString GetUniqueCharacterId();
	float GetStatValue_Float(TEnumAsByte<ECharacterStat> CharStat);
	float GetStamina();
	float GetPersonalAmbience(TEnumAsByte<ECharacterStat> CharStat);
	float GetNoise();
	float GetNavRadius();
	float GetNavHeight();
	float GetMountStamina();
	float GetMinStatValue_Float(TEnumAsByte<ECharacterStat> CharStat);
	float GetMaxStatValue_Float(TEnumAsByte<ECharacterStat> CharStat);
	class AActor* GetLastDamageDealer();
	float GetGlobalEncumbranceMultiplier();
	class AMainGameMode* GetGameMode();
	float GetDefaultStatValue_Float(TEnumAsByte<ECharacterStat> CharStat);
	float GetCharacterScale();
	float GetCharacterGameplayScale();
	float GetArmor();
	TEnumAsByte<EAIReaction> GetAIReactionTo(class ABasicCharacter* OtherCharacter, bool bVisible, bool bDamaged);
	void ClientTeleportTo(const struct FVector& DestLocation, const struct FRotator& DestRotation);
	void CleanupEffects();
};


// Class Otherlands.AICharacter
// 0x0320 (0x0FC0 - 0x0CA0)
class AAICharacter : public ABasicCharacter
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0CA0(0x0010) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnNewTamerEvent;                                          // 0x0CB0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTameProgressEvent;                                      // 0x0CC0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTameSuccessEvent;                                       // 0x0CD0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTameFailEvent;                                          // 0x0CE0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnSoulsHarvestedEvent;                                    // 0x0CF0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UCurveFloat*                                 DistanceScale;                                            // 0x0D00(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bMaintainFacing;                                          // 0x0D08(0x0001) (BlueprintVisible, Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bTamable;                                                 // 0x0D09(0x0001) (BlueprintVisible, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x0D0A(0x0002) MISSED OFFSET
	float                                              CachedNavRadius;                                          // 0x0D0C(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	float                                              CachedNavHeight;                                          // 0x0D10(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0D14(0x0004) MISSED OFFSET
	class AGameAIController*                           AIController;                                             // 0x0D18(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class AAIGroup*                                    AIGroup;                                                  // 0x0D20(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bSpawnAsPet;                                              // 0x0D28(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bDismissRequested;                                        // 0x0D29(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x6];                                       // 0x0D2A(0x0006) MISSED OFFSET
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0D30(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                FactionId;                                                // 0x0D38(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x0D3C(0x0004) MISSED OFFSET
	class AActor*                                      AttackTargetActor;                                        // 0x0D40(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	class AActor*                                      FriendlyTargetActor;                                      // 0x0D48(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	class UPrimitiveComponent*                         AttackTargetComponent;                                    // 0x0D50(0x0008) (ExportObject, Net, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	struct FVector                                     AttackTargetLocation;                                     // 0x0D58(0x000C) (Net, Transient, IsPlainOldData)
	bool                                               bHasAnyFocus;                                             // 0x0D64(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bPathObstructed;                                          // 0x0D65(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bNeedsAttackObstruction;                                  // 0x0D66(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData05[0x1];                                       // 0x0D67(0x0001) MISSED OFFSET
	float                                              ExploitRecoveryTime;                                      // 0x0D68(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	struct FVector                                     ExploitRecoveryLocation;                                  // 0x0D6C(0x000C) (Transient, IsPlainOldData)
	bool                                               bEvade;                                                   // 0x0D78(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bFading;                                                  // 0x0D79(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bLootDisabled;                                            // 0x0D7A(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData06[0x5];                                       // 0x0D7B(0x0005) MISSED OFFSET
	struct FName                                       TempoChannelId;                                           // 0x0D80(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	TScriptInterface<class UTempoTargetInterface>      TempoTarget;                                              // 0x0D88(0x0030) (ZeroConstructor, Transient, IsPlainOldData)
	TScriptInterface<class UTempoTargetInterface>      OldTempoTarget;                                           // 0x0D98(0x0030) (ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       CreatureId;                                               // 0x0DA8(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	float                                              VariantIndex;                                             // 0x0DB0(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	float                                              SummonRating;                                             // 0x0DB4(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                CreatureLevel;                                            // 0x0DB8(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	float                                              CreatureScaleRoll;                                        // 0x0DBC(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	float                                              AgentStepHeight;                                          // 0x0DC0(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	float                                              AgentWalkableAngle;                                       // 0x0DC4(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FCreatureBehaviorData                       BehaviorData;                                             // 0x0DC8(0x0040) (Transient)
	struct FName                                       RangedAttackSocketName;                                   // 0x0E08(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UStaticMeshComponent*                        MainHandStaticMesh;                                       // 0x0E10(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkeletalMeshComponent*                      MainHandSkeletalMesh;                                     // 0x0E18(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        OverheadStaticMesh;                                       // 0x0E20(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bCanFlankFinal;                                           // 0x0E28(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bCanFlank;                                                // 0x0E29(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData07[0x16];                                      // 0x0E2A(0x0016) MISSED OFFSET
	float                                              HarvestableSouls;                                         // 0x0E40(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              StartingHarvestableSouls;                                 // 0x0E44(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bHarvestableSoulsNotStored;                               // 0x0E48(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EAIAwakeState>                         ClientAwakeState;                                         // 0x0E49(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x3E];                                      // 0x0E4A(0x003E) MISSED OFFSET
	TArray<class UCreatureAbilityComponent*>           Abilities;                                                // 0x0E88(0x0010) (ExportObject, ZeroConstructor, Transient)
	unsigned char                                      UnknownData09[0xC0];                                      // 0x0E98(0x00C0) MISSED OFFSET
	float                                              AggroRadiusSq;                                            // 0x0F58(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x64];                                      // 0x0F5C(0x0064) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AICharacter");
		return ptr;
	}


	void WakeUp(TEnumAsByte<EAIAwakeState> InAwakeState);
	void TeleportToPlayer();
	void StopPreventMovement();
	void StopEvade();
	void StartPreventMovement();
	void StartGlobalCooldown(float GlobalCooldownTime, bool bRootDuringGCD);
	void StartExploitRecovery();
	void StartEvade();
	void SetWanderAnchor(const struct FVector& WanderAnchor, bool bUpdateLeader);
	void SetCooldownGroupTimeRemaining(const struct FName& CooldownGroupId, float Value);
	void RemovePlayerFromDamageList(class APlayerCharacter* Damager);
	void RemoveAiFromDamageList(class AAICharacter* Damager);
	void PushCharacter(const struct FVector& Direction, float Distance);
	bool ProcessTameEvent(TEnumAsByte<ETameEventType> TameEvent, float EventValue, class APlayerCharacter* Tamer);
	bool ProcessTameEnd(class APlayerCharacter* Tamer, bool bSuccess);
	void OnStartCharge(float ChargeTime);
	void OnRep_ClientAwakeState();
	void OnRep_AgentWalkableAngle();
	void OnRep_AgentStepHeight();
	void OnOtherDeathEvent(const struct FCharacterDeathEventData& GameEventData);
	void MulticastSimulateSoulsHarvested(const struct FCharacterSoulHarvestEventData& GameEvent);
	void MulticastSimulateHarvest(bool bSecondary, class UObject* ObjectHit, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal, TEnumAsByte<EPhysicalSurface> SurfaceType, const struct FName& ImpactEffectKitId);
	void MulticastPlayCreatureSound(TEnumAsByte<ECreatureSoundType> SoundType);
	void MulticastDoImpactEffectOnComponent(const struct FVector& StartLocation, const struct FVector& EndLocation, class UPrimitiveComponent* HitComponent, const struct FName& ImpactEffectKitId);
	void MulticastDoImpactEffect(const struct FVector& HitLocation, const struct FVector& ImpactNormal, const struct FName& ImpactEffectKitId, TEnumAsByte<EPhysicalSurface> SurfaceType);
	bool MaybeCanGainTamePoints();
	bool IsActiveTamer(class APlayerCharacter* Player);
	bool IgnoresEvadeVolume(class AAIEvadeVolume* Vol);
	bool HasAbilityOffCooldown(int AbilityTargetFlags);
	bool HandleHarvest(class AActor* HarvestActor);
	class APlayerCharacter* GetPlayerOwner();
	int GetNumActiveTamers();
	struct FCreatureHarvestData GetHarvestTool();
	class AGameAIController* GetGameAIController();
	float GetEngagementRadius();
	float GetDamageScore(class UObject* Target);
	class UCreatureAbilityComponent* GetCurrentAbility();
	float GetCooldownGroupTimeRemaining(const struct FName& CooldownGroupId);
	void GetCastableAbilities(const struct FTrackTargetData& TargetData, int AbilityTargetFlags, bool bFriendlyAbility, bool bCheckCooldown, TArray<class UCreatureAbilityComponent*>* OutAbilities);
	TEnumAsByte<EAIAwakeState> GetAwakeState();
	void GetAllAbilities(TArray<class UCreatureAbilityComponent*>* OutAbilities);
	class APlayerCharacter* GetActiveTamer(int Index);
	class UCreatureAbilityComponent* GetAbility(const struct FName& AbilityId, bool bAllowAdd);
	bool EngageAbility(const struct FName& AbilityId);
	void DisableLoot();
	bool CanGainTamePoints();
	bool BeginChargeOfCurrentAbility();
	bool BeginChargeAbility(const struct FName& AbilityId);
	void AsSummonCollectionEntry(struct FSummonCollectionEntry* OutEntry);
	void AllowInstantDespawn();
	void AddPlayerToDamageList(class APlayerCharacter* Damager, float Damage);
	void AddAiToDamageList(class AAICharacter* Damager, float Damage);
};


// Class Otherlands.AiConstants
// 0x0000 (0x0028 - 0x0028)
class UAiConstants : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AiConstants");
		return ptr;
	}

};


// Class Otherlands.GameVolume
// 0x0010 (0x0370 - 0x0360)
class AGameVolume : public AVolume
{
public:
	bool                                               bUseBoxOptimization;                                      // 0x0360(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0361(0x0003) MISSED OFFSET
	struct FVector                                     BoundsExtents;                                            // 0x0364(0x000C) (BlueprintVisible, BlueprintReadOnly, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameVolume");
		return ptr;
	}


	void RefreshFullBounds();
	void RefreshBoundsZ();
	bool IsZBound(float Z);
	struct FVector GetLocalPoint(const struct FVector& GlobalPoint);
	struct FVector GetGlobalPoint(const struct FVector& LocalPoint);
	float GetDistanceFromVolume(const struct FVector& GlobalPoint);
};


// Class Otherlands.AoiAiAwareVolume
// 0x0028 (0x0398 - 0x0370)
class AAoiAiAwareVolume : public AGameVolume
{
public:
	unsigned char                                      UnknownData00[0x28];                                      // 0x0370(0x0028) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AoiAiAwareVolume");
		return ptr;
	}


	bool IsAwareOfSphere(const struct FVector& Point, float Radius);
	bool IsAwareOfPoint(const struct FVector& Point);
	TEnumAsByte<EAoiAiAwareType> GetAoiAiAwareType();
};


// Class Otherlands.AIEvadeVolume
// 0x0020 (0x03B8 - 0x0398)
class AAIEvadeVolume : public AAoiAiAwareVolume
{
public:
	int                                                FactionId;                                                // 0x0398(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsEnabled;                                               // 0x039C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x039D(0x0003) MISSED OFFSET
	float                                              RemainingSecs;                                            // 0x03A0(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x14];                                      // 0x03A4(0x0014) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AIEvadeVolume");
		return ptr;
	}


	void SetEnabled(bool bNewState);
};


// Class Otherlands.SpawnGroup
// 0x0028 (0x0350 - 0x0328)
class ASpawnGroup : public AActor
{
public:
	class UObject*                                     GroupOwner;                                               // 0x0328(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	TArray<class AActor*>                              Members;                                                  // 0x0330(0x0010) (ZeroConstructor, Transient)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0340(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnGroup");
		return ptr;
	}


	void SetInactiveDespawnTime(float Time);
	void RemoveMember(class AActor* Member, bool bKilled);
	void RefreshInactiveDespawnTimer();
	TEnumAsByte<ESpiritRealmState> IsGroupInSpiritRealm();
	bool InitializeSpawnGroup(class UObject* InOwner);
	class ASpawnEvent* GetOwnerSpawnEvent();
	class APlayerCharacter* GetOwnerPlayer();
	TArray<class AActor*> GetMembers();
	class AActor* GetLeader();
	struct FVector GetGroupLocation();
	void ForceDespawn();
	void AddMember(class AActor* Member);
};


// Class Otherlands.AIGroup
// 0x0018 (0x0368 - 0x0350)
class AAIGroup : public ASpawnGroup
{
public:
	class UBlackboardComponent*                        BlackboardComponent;                                      // 0x0350(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBehaviorTreeComponent*                      BehaviorTreeComponent;                                    // 0x0358(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       GroupThreatRuleId;                                        // 0x0360(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AIGroup");
		return ptr;
	}


	void WakeUp(TEnumAsByte<EAIAwakeState> InAwakeState);
	void ReportHuntEvent(class AActor* InInstigator, const struct FVector& EventLocation, float AggroStrength, float AggroMinAge, class AActor* IgnoreActor);
	void ReportAggroEvent(class AActor* InInstigator, const struct FVector& EventLocation, float AggroStrength, float AggroMinAge, class AActor* IgnoreActor);
	void ReplicateBlackboard(const struct FVector& InEventTargetLocation, const struct FVector& GroupTargetLocation, const struct FVector& WanderAnchor, class UObject* GroupTarget, const struct FName& InGroupThreatRuleId);
	bool InitializeWaveAi(class UBehaviorTree* BehaviorTree, const struct FName& InGroupThreatRuleId);
	struct FName GetGroupThreatRuleId();
};


// Class Otherlands.AISenseEvent_Aggro
// 0x0030 (0x0058 - 0x0028)
class UAISenseEvent_Aggro : public UAISenseEvent
{
public:
	struct FAIAggroEvent                               Event;                                                    // 0x0028(0x0030) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISenseEvent_Aggro");
		return ptr;
	}

};


// Class Otherlands.AISense_Aggro
// 0x0060 (0x00E8 - 0x0088)
class UAISense_Aggro : public UAISense
{
public:
	TArray<struct FAIAggroEvent>                       RegisteredEvents;                                         // 0x0088(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0098(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISense_Aggro");
		return ptr;
	}


	void STATIC_ReportAggroEvent(class UObject* WorldContext, class AActor* InOwner, class AActor* InInstigator, const struct FVector& AggroLocation, float AggroStrength, float MinAge);
};


// Class Otherlands.AISenseEvent_GameHearing
// 0x0028 (0x0050 - 0x0028)
class UAISenseEvent_GameHearing : public UAISenseEvent
{
public:
	struct FAIGameNoiseEvent                           Event;                                                    // 0x0028(0x0028) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISenseEvent_GameHearing");
		return ptr;
	}

};


// Class Otherlands.AISense_GameHearing
// 0x0060 (0x00E8 - 0x0088)
class UAISense_GameHearing : public UAISense
{
public:
	TArray<struct FAIGameNoiseEvent>                   NoiseEvents;                                              // 0x0088(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0098(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISense_GameHearing");
		return ptr;
	}


	void STATIC_ReportGameNoiseEvent(class UObject* WorldContext, const struct FVector& NoiseLocation, TEnumAsByte<ENoiseType> NoiseType, float Loudness, class AActor* Instigator, float MaxRange);
};


// Class Otherlands.AISenseEvent_Hunt
// 0x0030 (0x0058 - 0x0028)
class UAISenseEvent_Hunt : public UAISenseEvent
{
public:
	struct FAIHuntEvent                                Event;                                                    // 0x0028(0x0030) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISenseEvent_Hunt");
		return ptr;
	}

};


// Class Otherlands.AISense_Hunt
// 0x0060 (0x00E8 - 0x0088)
class UAISense_Hunt : public UAISense
{
public:
	TArray<struct FAIHuntEvent>                        RegisteredEvents;                                         // 0x0088(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0098(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISense_Hunt");
		return ptr;
	}


	void STATIC_ReportHuntEvent(class UObject* WorldContext, class AActor* InOwner, class AActor* InInstigator, const struct FVector& HuntLocation, float HuntStrength, float MinAge);
};


// Class Otherlands.AISenseConfig_Aggro
// 0x0018 (0x0060 - 0x0048)
class UAISenseConfig_Aggro : public UAISenseConfig
{
public:
	class UClass*                                      Implementation;                                           // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, DisableEditOnInstance, NoClear, IsPlainOldData)
	float                                              AggroRadius;                                              // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ChaseRadius;                                              // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FAISenseAffiliationFilter                   DetectionByAffiliation;                                   // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, Config, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x005C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISenseConfig_Aggro");
		return ptr;
	}

};


// Class Otherlands.AISenseConfig_GameHearing
// 0x0018 (0x0060 - 0x0048)
class UAISenseConfig_GameHearing : public UAISenseConfig
{
public:
	class UClass*                                      Implementation;                                           // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, DisableEditOnInstance, NoClear, IsPlainOldData)
	float                                              HearingRange;                                             // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHearHarvestNoise;                                        // 0x0054(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0055(0x0003) MISSED OFFSET
	struct FAISenseAffiliationFilter                   DetectionByAffiliation;                                   // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, Config, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x005C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISenseConfig_GameHearing");
		return ptr;
	}

};


// Class Otherlands.AISenseConfig_Hunt
// 0x0010 (0x0058 - 0x0048)
class UAISenseConfig_Hunt : public UAISenseConfig
{
public:
	class UClass*                                      Implementation;                                           // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, DisableEditOnInstance, NoClear, IsPlainOldData)
	struct FAISenseAffiliationFilter                   DetectionByAffiliation;                                   // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, Config, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0054(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AISenseConfig_Hunt");
		return ptr;
	}

};


// Class Otherlands.SpawnerInstance
// 0x0030 (0x0358 - 0x0328)
class ASpawnerInstance : public AInfo
{
public:
	struct FName                                       SpawnBaseId;                                              // 0x0328(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TArray<struct FSpawnGroupData>                     SpawnGroups;                                              // 0x0330(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TArray<float>                                      ProbabilityWeights;                                       // 0x0340(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	bool                                               bSpawnInSpiritRealm;                                      // 0x0350(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0351(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnerInstance");
		return ptr;
	}


	class ASpawnGroup* SpawnGroup(class UObject* SpawnGroupOwner, const struct FName& SpecificSpawnGroupId, const struct FSpawnLocation& Location, const struct FSpawnOverrides& Overrides);
	bool Initialize(const struct FName& InSpawnBaseId, const struct FSpawnBaseData& SpawnBase);
	struct FVector GetRandomGroupLocation(const struct FSpawnLocation& Location);
	struct FSpawnGroupData GenerateSpawnGroup(const struct FName& InSpawnGroupId);
	bool AddSpawnGroup(const struct FSpawnGroupData& SpawnGroupData, float ProbabilityWeight);
};


// Class Otherlands.AiSpawnerInstance
// 0x0000 (0x0358 - 0x0358)
class AAiSpawnerInstance : public ASpawnerInstance
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AiSpawnerInstance");
		return ptr;
	}

};


// Class Otherlands.AmbientStatComponent
// 0x00D8 (0x01C8 - 0x00F0)
class UAmbientStatComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x00F0(0x0008) MISSED OFFSET
	class ABasicCharacter*                             CharacterOwner;                                           // 0x00F8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0100(0x0008) MISSED OFFSET
	TArray<float>                                      SelfAmbientValueAdditive;                                 // 0x0108(0x0010) (Net, ZeroConstructor)
	TArray<float>                                      SelfAmbientValueScalar;                                   // 0x0118(0x0010) (Net, ZeroConstructor)
	TArray<float>                                      SelfRawAmbientValue;                                      // 0x0128(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData02[0x20];                                      // 0x0138(0x0020) MISSED OFFSET
	TArray<float>                                      OtherAmbientValueAdditive;                                // 0x0158(0x0010) (Net, ZeroConstructor)
	TArray<float>                                      OtherAmbientValueScalar;                                  // 0x0168(0x0010) (Net, ZeroConstructor)
	TArray<float>                                      OtherRawAmbientValue;                                     // 0x0178(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData03[0x40];                                      // 0x0188(0x0040) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AmbientStatComponent");
		return ptr;
	}

};


// Class Otherlands.AoiAwareVolume
// 0x0028 (0x0398 - 0x0370)
class AAoiAwareVolume : public AGameVolume
{
public:
	unsigned char                                      UnknownData00[0x28];                                      // 0x0370(0x0028) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AoiAwareVolume");
		return ptr;
	}


	bool IsAwareOfSphere(const struct FVector& Point, float Radius);
	bool IsAwareOfPoint(const struct FVector& Point);
	void GetAwarePlayers(TArray<class APlayerCharacter*>* OutResult);
	TEnumAsByte<EAoiAwareType> GetAoiAwareType();
};


// Class Otherlands.AmbientStatVolume
// 0x0018 (0x03B0 - 0x0398)
class AAmbientStatVolume : public AAoiAwareVolume
{
public:
	TEnumAsByte<ECharacterStat>                        AmbientStat;                                              // 0x0398(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0399(0x0003) MISSED OFFSET
	float                                              RawValue;                                                 // 0x039C(0x0004) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	float                                              FalloffDistance;                                          // 0x03A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              FalloffDistanceSq;                                        // 0x03A4(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bIsEnabled;                                               // 0x03A8(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	bool                                               bIsAdditive;                                              // 0x03A9(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETimeCycleType>                        TimeCycle;                                                // 0x03AA(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x03AB(0x0005) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AmbientStatVolume");
		return ptr;
	}


	bool IsTimeCycle(bool bIsNightTime);
	bool GetAmbienceAtPoint(const struct FVector& Point, bool bIsNightTime, float* OutValue);
};


// Class Otherlands.GameBaseWidget
// 0x0018 (0x0220 - 0x0208)
class UGameBaseWidget : public UUserWidget
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0208(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameBaseWidget");
		return ptr;
	}


	void SetTickEnabled(bool bEnabled);
	class APlayerCharacter* GetPlayerCharacter();
	class AGamePlayerController* GetGamePlayerController();
	class AGameHUD* GetGameHUD();
	void EventOnGameHUDCreated();
};


// Class Otherlands.AmmoRadialMenuWidget
// 0x0028 (0x0248 - 0x0220)
class UAmmoRadialMenuWidget : public UGameBaseWidget
{
public:
	TArray<class UTexture2D*>                          AmmoIcons;                                                // 0x0220(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<struct FName>                               AmmoItemIdArray;                                          // 0x0230(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	int                                                TotalAmmoButtons;                                         // 0x0240(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0244(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AmmoRadialMenuWidget");
		return ptr;
	}


	void UpdateDisplayInformation();
	void UpdateButtonIcons();
	void Update();
	void ChooseAmmo(int Idx);
};


// Class Otherlands.ArchetypeSlotWidget
// 0x0040 (0x0260 - 0x0220)
class UArchetypeSlotWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  Icon;                                                     // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                PointCount;                                               // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x022C(0x0004) MISSED OFFSET
	struct FText                                       PointCountText;                                           // 0x0230(0x0018) (Edit, BlueprintVisible)
	bool                                               bArchetypeSlotEnabled;                                    // 0x0248(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0249(0x0007) MISSED OFFSET
	class UPerksWidget*                                ParentRowWidget;                                          // 0x0250(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TEnumAsByte<ECharacterArchetype>                   Archetype;                                                // 0x0258(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0259(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ArchetypeSlotWidget");
		return ptr;
	}


	void UpdateArchetypeSlot();
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.AscensionPerkComponent
// 0x01D0 (0x02C0 - 0x00F0)
class UAscensionPerkComponent : public UActorComponent
{
public:
	struct FScriptMulticastDelegate                    OnAscensionPointAdded;                                    // 0x00F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAscensionPointsUpdated;                                 // 0x0100(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAscensionPerksUpdated;                                  // 0x0110(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	bool                                               bExternalDataLoaded;                                      // 0x0120(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0121(0x0007) MISSED OFFSET
	struct FAscensionMatchData                         Match;                                                    // 0x0128(0x0088)
	struct FAscensionEternalData                       Eternal;                                                  // 0x01B0(0x0018)
	int                                                CurrentSagaPoints;                                        // 0x01C8(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	int                                                TotalUnspentPoints;                                       // 0x01CC(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	int                                                TotalSpentPoints;                                         // 0x01D0(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x01D4(0x0004) MISSED OFFSET
	TArray<struct FAscensionUnlock>                    KnownUnlocks;                                             // 0x01D8(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)
	TMap<struct FName, struct FAscensionUnlock>        Loadout;                                                  // 0x01E8(0x0050) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TArray<struct FAscensionSlotPerk>                  LoadoutArray;                                             // 0x0238(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)
	TArray<struct FAscensionUnlock>                    CurrUnlocks;                                              // 0x0248(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0258(0x0050) MISSED OFFSET
	class APlayerCharacter*                            PlayerOwner;                                              // 0x02A8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x02B0(0x0008) MISSED OFFSET
	class AMainGameState*                              GameState;                                                // 0x02B8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AscensionPerkComponent");
		return ptr;
	}


	void SlotPerkUnchecked(const struct FAscensionUnlock& Perk);
	TEnumAsByte<ECanAscensionReason> SlotPerk(const struct FAscensionUnlock& Perk);
	void ServerSlotPerk(const struct FAscensionUnlock& Perk);
	void ServerLearnPerk(const struct FAscensionUnlock& Perk, bool bApply);
	void OnSaveAscensionDataResponse(EDatabaseServiceResponse Response);
	void OnRep_UnspentPoints(int OldCount);
	void OnRep_SpentPoints();
	void OnRep_Loadout();
	void OnGetAscensionDataResponse(EDatabaseServiceResponse Response, const struct FKeyData& Data);
	void OnActivity(TEnumAsByte<EAscensionActivity> Activity);
	void LearnPerkUnchecked(const struct FAscensionUnlock& Perk, bool bApply);
	void LearnPerksUnchecked(TArray<struct FAscensionUnlock> Perks, TArray<bool> Apply);
	TEnumAsByte<ECanAscensionReason> LearnPerk(const struct FAscensionUnlock& Perk, bool bApply);
	TEnumAsByte<ECanAscensionReason> IsPerkUpgradeAvailable(const struct FName& PerkId);
	bool IsPerkUnlocked(const struct FAscensionUnlock& Perk);
	bool IsPerkKnown(const struct FAscensionUnlock& Perk);
	bool IsExternalDataLoaded();
	TEnumAsByte<ECanAscensionReason> IsBasePerkAvailable(const struct FName& PerkId);
	int GetUnlockedPerkRank(const struct FName& PerkId);
	struct FAscensionUnlock GetSlottedPerk(const struct FName& LoadoutSlotId);
	void GetKnownPerksBySlot(const struct FName& LoadoutSlotId, TArray<struct FAscensionUnlock>* Perks);
	int GetKnownPerkRank(const struct FName& PerkId);
	void ClientNotifyPointAdded(int NewTotal);
	TEnumAsByte<ECanAscensionReason> CanSlotPerk(const struct FAscensionUnlock& Perk);
	TEnumAsByte<ECanAscensionReason> CanLearnPerk(const struct FAscensionUnlock& Perk, bool bIgnoreCost);
	void AddSpentPoints(int Count);
	void AddRelevance(float Relevance);
	void AddPoint(int Count, bool bForceSagaGain);
};


// Class Otherlands.AudioSettingsWidget
// 0x0010 (0x0230 - 0x0220)
class UAudioSettingsWidget : public UGameBaseWidget
{
public:
	float                                              MasterVolume;                                             // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SFXVolume;                                                // 0x0224(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              VoiceVolume;                                              // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MusicVolume;                                              // 0x022C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AudioSettingsWidget");
		return ptr;
	}


	void SaveAudioSettings();
	void GetAudioSettings();
};


// Class Otherlands.AuthService
// 0x0058 (0x0080 - 0x0028)
class UAuthService : public UObject
{
public:
	struct FString                                     AuthKey;                                                  // 0x0028(0x0010) (ZeroConstructor, Config)
	struct FString                                     BlobKey;                                                  // 0x0038(0x0010) (ZeroConstructor, Config)
	unsigned char                                      UnknownData00[0x30];                                      // 0x0048(0x0030) MISSED OFFSET
	class UGameCredentialsProvider*                    GameCredentialsProvider;                                  // 0x0078(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AuthService");
		return ptr;
	}


	bool VerifySignedString(const struct FString& Str, const struct FString& Signature, const struct FString& PublicKeyIn);
	struct FString SignString(const struct FString& Str);
	class UGameCredentialsProvider* GetGameCredentialsProvider();
	struct FString GetAuthId();
	bool EncryptBlob(TArray<unsigned char> Blob, struct FString* OutCryptoMessage);
	bool DecryptBlob(const struct FString& CryptoMessage, TArray<unsigned char>* Blob);
	struct FAuthTicket DecryptAuthTicket(const struct FString& Encrypted);
};


// Class Otherlands.PlaceableStructureContainer
// 0x0000 (0x0328 - 0x0328)
class APlaceableStructureContainer : public AActor
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableStructureContainer");
		return ptr;
	}

};


// Class Otherlands.BaseHearth
// 0x01B8 (0x04E0 - 0x0328)
class ABaseHearth : public APlaceableStructureContainer
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0328(0x0018) MISSED OFFSET
	class USceneComponent*                             SceneRoot;                                                // 0x0340(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	float                                              StructureGridSizeXY;                                      // 0x0348(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	float                                              StructureGridSizeZ;                                       // 0x034C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	struct FStructureGrid                              SmallGrid;                                                // 0x0350(0x0068) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                FactionId;                                                // 0x03B8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	float                                              StructureOriginOffsetZ;                                   // 0x03BC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class APlaceableStructure*                         PlaceableStructure;                                       // 0x03C0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UStaticMesh*                                 ShieldCollisionMesh;                                      // 0x03C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UStaticMeshComponent*                        ShieldCollision[0x5];                                     // 0x03D0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBasePylonSkeletal*                          InnerPylonSkeletalA;                                      // 0x03F8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UBasePylonSkeletal*                          InnerPylonSkeletalB;                                      // 0x0400(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UBasePylonSkeletal*                          InnerPylonSkeletalC;                                      // 0x0408(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UBasePylonSkeletal*                          InnerPylonSkeletalD;                                      // 0x0410(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UBaseTree*                                   BaseTree;                                                 // 0x0418(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	bool                                               bShieldsUp;                                               // 0x0420(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0421(0x0003) MISSED OFFSET
	float                                              ShieldValue;                                              // 0x0424(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	bool                                               bReckoningState;                                          // 0x0428(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0429(0x0007) MISSED OFFSET
	class AAIEvadeVolume*                              AiEvade;                                                  // 0x0430(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UNavigationInvokerComponent*                 NavInvoker;                                               // 0x0438(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBuffComponent*                              BuffComponent;                                            // 0x0440(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USpellCastComponent*                         SpellCastComponent;                                       // 0x0448(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData03[0x90];                                      // 0x0450(0x0090) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BaseHearth");
		return ptr;
	}


	bool StartShieldUpTimer(float Delay);
	void ShieldUp();
	void ShieldDown();
	void SetShieldState(bool bSet);
	void SetBaseScale(bool bLarge);
	void PulseTrailingEdge(float Radius);
	void PulseLeadingEdge(float Radius);
	void OnRep_ShieldsUp();
	void OnRep_ReckoningState();
	void OnExplosionStart();
	void MulticastStartDestruction();
	bool GetShieldState();
	void AddExplodingBuilding(class AActor* Actor);
	void ActivateInnerPlylons();
};


// Class Otherlands.BasePylonSkeletal
// 0x0010 (0x0BC0 - 0x0BB0)
class UBasePylonSkeletal : public USkeletalMeshComponent
{
public:
	bool                                               bIsActivated;                                             // 0x0BB0(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0BB1(0x0003) MISSED OFFSET
	float                                              SoulsStored;                                              // 0x0BB4(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0BB8(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BasePylonSkeletal");
		return ptr;
	}


	void OnRep_IsActivated();
};


// Class Otherlands.GameStaticMesh
// 0x0030 (0x0630 - 0x0600)
class UGameStaticMesh : public UStaticMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x30];                                      // 0x0600(0x0030) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameStaticMesh");
		return ptr;
	}

};


// Class Otherlands.BaseTree
// 0x0020 (0x0650 - 0x0630)
class UBaseTree : public UGameStaticMesh
{
public:
	class ABaseHearth*                                 BaseHearth;                                               // 0x0630(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              armor;                                                    // 0x0638(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              OverrideEngagementRange;                                  // 0x063C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0640(0x0004) MISSED OFFSET
	float                                              RemainingSpiritLoss;                                      // 0x0644(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0648(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BaseTree");
		return ptr;
	}


	float GetSpiritsStored();
	void CalculateMaxSpiritLoss();
};


// Class Otherlands.BasicCharacterAnimInstance
// 0x0050 (0x03B0 - 0x0360)
class UBasicCharacterAnimInstance : public UAnimInstance
{
public:
	float                                              MoveAnimScale;                                            // 0x0360(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	float                                              MaxMovementBlendspaceSpeed;                               // 0x0364(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	float                                              CurrentMovementAngle;                                     // 0x0368(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	float                                              CurrentForwardMovementAngle;                              // 0x036C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	bool                                               bIsStunned;                                               // 0x0370(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	bool                                               bIsMoving;                                                // 0x0371(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	bool                                               bIsJumping;                                               // 0x0372(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	bool                                               bIsDoubleJumping;                                         // 0x0373(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	bool                                               bIsInAir;                                                 // 0x0374(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	bool                                               bIsDrawingBow;                                            // 0x0375(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0376(0x0002) MISSED OFFSET
	float                                              BowDrawScalar;                                            // 0x0378(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	int                                                TurnInPlaceDirection;                                     // 0x037C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	float                                              TurnInPlaceThreshold;                                     // 0x0380(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bIsMounted;                                               // 0x0384(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	TEnumAsByte<EMountFamily>                          MountFamily;                                              // 0x0385(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	TEnumAsByte<ECharacterStance>                      Stance;                                                   // 0x0386(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	bool                                               bIsDead;                                                  // 0x0387(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	float                                              AimOffsetYaw;                                             // 0x0388(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	float                                              AimOffsetPitch;                                           // 0x038C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	struct FRotator                                    MountSpineRotation;                                       // 0x0390(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnTemplate, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x039C(0x0004) MISSED OFFSET
	class ABasicCharacter*                             CharacterOwner;                                           // 0x03A0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class APlayerCharacter*                            PlayerOwner;                                              // 0x03A8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BasicCharacterAnimInstance");
		return ptr;
	}


	float GetAnimSequenceLength(class UAnimSequence* AnimSequence);
};


// Class Otherlands.BTD_TrackTargetDataBase
// 0x0028 (0x0090 - 0x0068)
class UBTD_TrackTargetDataBase : public UBTDecorator
{
public:
	struct FBlackboardKeySelector                      BlackboardKey;                                            // 0x0068(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_TrackTargetDataBase");
		return ptr;
	}

};


// Class Otherlands.BTD_CanAttack
// 0x0000 (0x0090 - 0x0090)
class UBTD_CanAttack : public UBTD_TrackTargetDataBase
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_CanAttack");
		return ptr;
	}

};


// Class Otherlands.BTD_CheckPlayerZone
// 0x0038 (0x00A0 - 0x0068)
class UBTD_CheckPlayerZone : public UBTDecorator
{
public:
	struct FBlackboardKeySelector                      PlayerKey;                                                // 0x0068(0x0028) (Edit)
	bool                                               bIsIn;                                                    // 0x0090(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0091(0x0007) MISSED OFFSET
	struct FName                                       ZoneId;                                                   // 0x0098(0x0008) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_CheckPlayerZone");
		return ptr;
	}

};


// Class Otherlands.BTD_HasActiveAction
// 0x0028 (0x0090 - 0x0068)
class UBTD_HasActiveAction : public UBTDecorator
{
public:
	struct FBlackboardKeySelector                      PlannerKey;                                               // 0x0068(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_HasActiveAction");
		return ptr;
	}

};


// Class Otherlands.BTD_HasActiveGoal
// 0x0028 (0x0090 - 0x0068)
class UBTD_HasActiveGoal : public UBTDecorator
{
public:
	struct FBlackboardKeySelector                      PlannerKey;                                               // 0x0068(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_HasActiveGoal");
		return ptr;
	}

};


// Class Otherlands.BTD_PetReaction
// 0x0008 (0x0070 - 0x0068)
class UBTD_PetReaction : public UBTDecorator
{
public:
	int                                                PetReactionFlags;                                         // 0x0068(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x006C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_PetReaction");
		return ptr;
	}

};


// Class Otherlands.SpawnCatalog
// 0x0028 (0x0050 - 0x0028)
class USpawnCatalog : public UObject
{
public:
	class AActor*                                      OwnerActor;                                               // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x20];                                      // 0x0030(0x0020) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnCatalog");
		return ptr;
	}


	bool NotifyState(TEnumAsByte<ETempoTargetState> CurrentState, bool bForceReset);
	void IncrementIteration(int Count);
	float GetStateAge();
	void GetSpawnGroups(TArray<class ASpawnGroup*>* Result);
	int GetSpawnCount();
	class USpawnCatalog* STATIC_GetSpawnCatalog(class UBlackboardComponent* Blackboard, const struct FBlackboardKeySelector& SpawnCatalogKey);
	class USpawnCatalog* STATIC_GetOrCreateSpawnCatalog(class UBlackboardComponent* Blackboard, const struct FBlackboardKeySelector& SpawnCatalogKey, const struct FBlackboardKeySelector& PlayerKey);
	int GetIterationValue();
	void AddSpawn(const struct FTempoSpawn& NewSpawn);
};


// Class Otherlands.BTD_SpawnCatalogCount
// 0x0060 (0x00C8 - 0x0068)
class UBTD_SpawnCatalogCount : public UBTDecorator
{
public:
	struct FBlackboardKeySelector                      SpawnCatalogKey;                                          // 0x0068(0x0028) (Edit)
	struct FBlackboardKeySelector                      ScoreKey;                                                 // 0x0090(0x0028) (Edit)
	ESpawnCatalogValue                                 LeftValue;                                                // 0x00B8(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	ESpawnCatalogCompare                               Operator;                                                 // 0x00B9(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x00BA(0x0002) MISSED OFFSET
	float                                              RightValue;                                               // 0x00BC(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                DenominatorOffset;                                        // 0x00C0(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x00C4(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_SpawnCatalogCount");
		return ptr;
	}

};


// Class Otherlands.BTD_TargetSensedBy
// 0x0008 (0x0098 - 0x0090)
class UBTD_TargetSensedBy : public UBTD_TrackTargetDataBase
{
public:
	int                                                SensedBy;                                                 // 0x0090(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0094(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTD_TargetSensedBy");
		return ptr;
	}

};


// Class Otherlands.BTService_TrackTargetsBase
// 0x00C8 (0x0138 - 0x0070)
class UBTService_TrackTargetsBase : public UBTService
{
public:
	struct FBlackboardKeySelector                      TargetDataKey;                                            // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      TargetActorKey;                                           // 0x0098(0x0028) (Edit)
	struct FBlackboardKeySelector                      TargetLocationKey;                                        // 0x00C0(0x0028) (Edit)
	struct FBlackboardKeySelector                      WanderAnchorKey;                                          // 0x00E8(0x0028) (Edit)
	struct FBlackboardKeySelector                      IsAbilityChargingKey;                                     // 0x0110(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTService_TrackTargetsBase");
		return ptr;
	}

};


// Class Otherlands.BTService_GroupFindTarget
// 0x0050 (0x0188 - 0x0138)
class UBTService_GroupFindTarget : public UBTService_TrackTargetsBase
{
public:
	struct FBlackboardKeySelector                      GroupThreatRuleKey;                                       // 0x0138(0x0028) (Edit)
	struct FBlackboardKeySelector                      EventTargetLocationKey;                                   // 0x0160(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTService_GroupFindTarget");
		return ptr;
	}

};


// Class Otherlands.BTS_MaintainGoals
// 0x0050 (0x00C0 - 0x0070)
class UBTS_MaintainGoals : public UBTService
{
public:
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      PlannerKey;                                               // 0x0098(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTS_MaintainGoals");
		return ptr;
	}

};


// Class Otherlands.BTService_MaintainLeash
// 0x0078 (0x00E8 - 0x0070)
class UBTService_MaintainLeash : public UBTService
{
public:
	struct FBlackboardKeySelector                      WanderAnchorKey;                                          // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0098(0x0028) (Edit)
	struct FBlackboardKeySelector                      PreviousStateKey;                                         // 0x00C0(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTService_MaintainLeash");
		return ptr;
	}

};


// Class Otherlands.BTService_MaintainTargetState
// 0x00A0 (0x01D8 - 0x0138)
class UBTService_MaintainTargetState : public UBTService_TrackTargetsBase
{
public:
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0138(0x0028) (Edit)
	struct FBlackboardKeySelector                      PreviousStateKey;                                         // 0x0160(0x0028) (Edit)
	struct FBlackboardKeySelector                      GroupTargetDataKey;                                       // 0x0188(0x0028) (Edit)
	struct FBlackboardKeySelector                      EventTargetLocationKey;                                   // 0x01B0(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTService_MaintainTargetState");
		return ptr;
	}

};


// Class Otherlands.BTS_MonitorTempo
// 0x0130 (0x01A0 - 0x0070)
class UBTS_MonitorTempo : public UBTService
{
public:
	struct FBlackboardKeySelector                      PlayerKey;                                                // 0x0070(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0098(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FBlackboardKeySelector                      ScoreKey;                                                 // 0x00C0(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FBlackboardKeySelector                      VolumeKey;                                                // 0x00E8(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FBlackboardKeySelector                      TempoChannelKey;                                          // 0x0110(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FBlackboardKeySelector                      SpawnCatalogKey;                                          // 0x0138(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	bool                                               bObserveBlackboardScore;                                  // 0x0160(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0161(0x0003) MISSED OFFSET
	float                                              FallbackScore;                                            // 0x0164(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     FallbackState;                                            // 0x0168(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     DeathState;                                               // 0x0169(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x016A(0x0002) MISSED OFFSET
	float                                              ThresholdScore;                                           // 0x016C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     ThresholdState;                                           // 0x0170(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     InitializeState;                                          // 0x0171(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bShouldResetOnRelevent;                                   // 0x0172(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1];                                       // 0x0173(0x0001) MISSED OFFSET
	float                                              ResetScore;                                               // 0x0174(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              TakeDamageMultiplier;                                     // 0x0178(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DoDamageMultiplier;                                       // 0x017C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              TakeHitScore;                                             // 0x0180(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DoHitScore;                                               // 0x0184(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              TimeInZoneMultiplier;                                     // 0x0188(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              TimeOutZoneMultiplier;                                    // 0x018C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UBlackboardComponent*                        BlackboardComponent;                                      // 0x0190(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x0198(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTS_MonitorTempo");
		return ptr;
	}


	void OnTempoEvent(const struct FCharacterTempoEventData& GameEventData);
	void OnTakeHitEvent(const struct FGameEventData& GameEventData);
	void OnTakeDamageEvent(const struct FCharacterDetailedDamageEventData& GameEventData);
	void OnDoHitEvent(const struct FGameEventData& GameEventData);
	void OnDoDamageEvent(const struct FCharacterDetailedDamageEventData& GameEventData);
	void OnDeathEvent(const struct FCharacterDeathEventData& GameEventData);
};


// Class Otherlands.BTService_PickEngagement
// 0x0170 (0x01E0 - 0x0070)
class UBTService_PickEngagement : public UBTService
{
public:
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      PreviousStateKey;                                         // 0x0098(0x0028) (Edit)
	struct FBlackboardKeySelector                      TargetDataKey;                                            // 0x00C0(0x0028) (Edit)
	struct FBlackboardKeySelector                      AcceptanceRangeKey;                                       // 0x00E8(0x0028) (Edit)
	struct FBlackboardKeySelector                      MinDistanceKey;                                           // 0x0110(0x0028) (Edit)
	struct FBlackboardKeySelector                      MaxDistanceKey;                                           // 0x0138(0x0028) (Edit)
	struct FBlackboardKeySelector                      DesiredDistanceKey;                                       // 0x0160(0x0028) (Edit)
	struct FBlackboardKeySelector                      ChargeDistanceKey;                                        // 0x0188(0x0028) (Edit)
	TArray<struct FName>                               AbilityIdFilter;                                          // 0x01B0(0x0010) (Edit, ZeroConstructor)
	int                                                AbilityTargetTypeFilter;                                  // 0x01C0(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                StateFlagsOverride;                                       // 0x01C4(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bAllowFriendlyCast;                                       // 0x01C8(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bForcePreSelect;                                          // 0x01C9(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bSkipAbilitySelect;                                       // 0x01CA(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bFleeIfCannotDamage;                                      // 0x01CB(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bFleeIfNeverSelect;                                       // 0x01CC(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x01CD(0x0003) MISSED OFFSET
	struct FSelectionFailureData                       SelectionFailure;                                         // 0x01D0(0x0010) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTService_PickEngagement");
		return ptr;
	}

};


// Class Otherlands.StructureQueryOwner
// 0x00E8 (0x0110 - 0x0028)
class UStructureQueryOwner : public UObject
{
public:
	struct FFindStructureTargetQuery                   Query;                                                    // 0x0028(0x00D0) (BlueprintVisible)
	bool                                               bUseMaximumAge;                                           // 0x00F8(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x00F9(0x0003) MISSED OFFSET
	float                                              MaximumAge;                                               // 0x00FC(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaximumSightAge;                                          // 0x0100(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              RemainingAge;                                             // 0x0104(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              RemainingSightAge;                                        // 0x0108(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x010C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.StructureQueryOwner");
		return ptr;
	}


	void RecheckSight();
	bool ProcessQuery(float DeltaSeconds, bool bAllowImmediateRestart);
	bool NeedsRestart(float DeltaSeconds);
	bool HasResults();
	bool AreResultsOld();
};


// Class Otherlands.TrackTargetLibrary
// 0x0000 (0x0028 - 0x0028)
class UTrackTargetLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TrackTargetLibrary");
		return ptr;
	}


	void STATIC_ScoreTrackedTargets(class APawn* Pawn, const struct FTrackTargetData& PreviousTarget, const struct FVector& EventLocation, const struct FThreatRuleData& ThreatRule, TArray<struct FTrackTargetData>* TargetData);
	void STATIC_Rectify(TEnumAsByte<EAICharacterState> CurrentState, struct FTrackTargetData* Self);
	bool STATIC_QueryStructureTargets(class UStructureQueryOwner* QueryOwner);
	bool STATIC_NotEquals(const struct FTrackTargetData& LHS, const struct FTrackTargetData& RHS);
	bool STATIC_MatchesCategory(const struct FTrackTargetData& TargetData, const struct FTrackTargetData& PreviousTarget, int CategoryFlags, bool bMatchAll, bool bRequireAttackSpace);
	bool STATIC_IsValidTarget(const struct FTrackTargetData& Self);
	bool STATIC_HasTargetObject(const struct FTrackTargetData& Self);
	void STATIC_FindUnitTargets(const struct FTrackTargetData& PreviousTarget, class APawn* Pawn, bool bInSpiritRealm, const struct FVector& TargetLocation, const struct FThreatRuleData& ThreatRule, bool* OutSuccess, TArray<struct FTrackTargetData>* OutTargetData);
	void STATIC_FindStructureTargets(const struct FTrackTargetData& PreviousTarget, class APawn* Pawn, const struct FVector& TargetLocation, const struct FThreatRuleData& ThreatRule, bool* OutSuccess, TArray<struct FTrackTargetData>* OutTargetData);
	void STATIC_FindSeenResourceTargets(class APawn* Pawn, bool bIncludeNonBlocking, bool* OutSuccess, TArray<struct FTrackTargetData>* OutTargetData);
	void STATIC_FindPerceptionTargets(class APawn* Pawn, class UAIPerceptionComponent* PerceptionComponent, int FactionId, const struct FTrackTargetData& PreviousTarget, bool bInCombat, bool* OutSuccess, TArray<struct FTrackTargetData>* OutTargetData);
	void STATIC_FindNearbyResourceTargets(class UObject* WorldContext, const struct FVector& TargetLocation, float Range, bool bIncludeNonBlocking, bool* OutSuccess, TArray<struct FTrackTargetData>* OutTargetData);
	void STATIC_FindFriendlyTargets(class APawn* Pawn, const struct FVector& TargetLocation, float Range, bool* OutSuccess, TArray<struct FTrackTargetData>* OutTargetData);
	void STATIC_FindBestTarget(TArray<struct FTrackTargetData> Targets, bool bRandomize, bool bMustSeeRandom, bool* OutSuccess, struct FTrackTargetData* OutTargetData);
	int STATIC_FindBestMatchingCategory(const struct FTrackTargetData& TargetData, const struct FTrackTargetData& PreviousTarget, TArray<struct FThreatCategory> Categories);
	bool STATIC_Equals(const struct FTrackTargetData& LHS, const struct FTrackTargetData& RHS);
	bool STATIC_CanAttack(const struct FTrackTargetData& Self);
	float STATIC_CalculateRanking(const struct FTrackTargetData& TargetData, class APawn* Pawn, const struct FVector& EventLocation, const struct FThreatRanking& Threat);
};


// Class Otherlands.BTS_VehicleTrackTargets
// 0x0000 (0x0138 - 0x0138)
class UBTS_VehicleTrackTargets : public UBTService_TrackTargetsBase
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTS_VehicleTrackTargets");
		return ptr;
	}

};


// Class Otherlands.BTT_AdjustTempoScore
// 0x0080 (0x00F0 - 0x0070)
class UBTT_AdjustTempoScore : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      TempoChannelKey;                                          // 0x0070(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FBlackboardKeySelector                      PlayerKey;                                                // 0x0098(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FBlackboardKeySelector                      ScoreKey;                                                 // 0x00C0(0x0028) (Edit)
	EAdjustTempoScoreType                              AdjustType;                                               // 0x00E8(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x00E9(0x0003) MISSED OFFSET
	float                                              Value;                                                    // 0x00EC(0x0004) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_AdjustTempoScore");
		return ptr;
	}

};


// Class Otherlands.BTTask_ChargeAttack
// 0x0008 (0x0078 - 0x0070)
class UBTTask_ChargeAttack : public UBTTaskNode
{
public:
	class UClass*                                      FilterClass;                                              // 0x0070(0x0008) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTTask_ChargeAttack");
		return ptr;
	}

};


// Class Otherlands.BTT_EndEncounter
// 0x0030 (0x00A0 - 0x0070)
class UBTT_EndEncounter : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      WanderAnchorKey;                                          // 0x0070(0x0028) (Edit)
	bool                                               bResetWanderAnchor;                                       // 0x0098(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bClearDamageList;                                         // 0x0099(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bClearPerception;                                         // 0x009A(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bNotifyAbilities;                                         // 0x009B(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x009C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_EndEncounter");
		return ptr;
	}

};


// Class Otherlands.TempoVolumeLibrary
// 0x0000 (0x0028 - 0x0028)
class UTempoVolumeLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TempoVolumeLibrary");
		return ptr;
	}


	class ADynamicSpawnVolume* STATIC_FindTempoVolumeFor(const struct FName& TempoChannelId, class AActor* TargetActor);
};


// Class Otherlands.BTT_FindVolume
// 0x0078 (0x00E8 - 0x0070)
class UBTT_FindVolume : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      PlayerKey;                                                // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      VolumeKey;                                                // 0x0098(0x0028) (Edit)
	struct FBlackboardKeySelector                      TempoChannelKey;                                          // 0x00C0(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_FindVolume");
		return ptr;
	}

};


// Class Otherlands.BTT_FindWanderLocation
// 0x00A8 (0x0118 - 0x0070)
class UBTT_FindWanderLocation : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      GroupLeaderKey;                                           // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      WanderAnchorKey;                                          // 0x0098(0x0028) (Edit)
	struct FBlackboardKeySelector                      WanderLocationKey;                                        // 0x00C0(0x0028) (Edit)
	struct FBlackboardKeySelector                      IsFollowingSplineKey;                                     // 0x00E8(0x0028) (Edit)
	bool                                               bAllowFollowLeader;                                       // 0x0110(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bAllowFollowSpline;                                       // 0x0111(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0112(0x0002) MISSED OFFSET
	float                                              SplineTravelScalar;                                       // 0x0114(0x0004) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_FindWanderLocation");
		return ptr;
	}

};


// Class Otherlands.BTT_IncrementTempoIteration
// 0x0058 (0x00C8 - 0x0070)
class UBTT_IncrementTempoIteration : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      PlayerKey;                                                // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      SpawnCatalogKey;                                          // 0x0098(0x0028) (Edit)
	int                                                NumIterations;                                            // 0x00C0(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x00C4(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_IncrementTempoIteration");
		return ptr;
	}

};


// Class Otherlands.BTT_MaintainCombatPosition
// 0x0188 (0x01F8 - 0x0070)
class UBTT_MaintainCombatPosition : public UBTTaskNode
{
public:
	class UClass*                                      FilterClass;                                              // 0x0070(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              ObservedBlackboardValueTolerance;                         // 0x0078(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bObserveBlackboardValue : 1;                              // 0x007C(0x0001) (Edit)
	unsigned char                                      UnknownData00[0x3];                                       // 0x007D(0x0003) MISSED OFFSET
	struct FBlackboardKeySelector                      MinDistanceKey;                                           // 0x0080(0x0028) (Edit)
	struct FBlackboardKeySelector                      MaxDistanceKey;                                           // 0x00A8(0x0028) (Edit)
	struct FBlackboardKeySelector                      DesiredDistanceKey;                                       // 0x00D0(0x0028) (Edit)
	struct FBlackboardKeySelector                      AcceptanceRangeKey;                                       // 0x00F8(0x0028) (Edit)
	struct FBlackboardKeySelector                      TargetDataKey;                                            // 0x0120(0x0028) (Edit)
	struct FBlackboardKeySelector                      PathFailedCountKey;                                       // 0x0148(0x0028) (Edit)
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0170(0x0028) (Edit)
	struct FBlackboardKeySelector                      PreviousStateKey;                                         // 0x0198(0x0028) (Edit)
	struct FPathFailureData                            PathFailure;                                              // 0x01C0(0x0038) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_MaintainCombatPosition");
		return ptr;
	}


	void OnAiAbilityStart(const struct FAbilityGameEventData& EventData);
};


// Class Otherlands.BTT_ReportAggro
// 0x0060 (0x00D0 - 0x0070)
class UBTT_ReportAggro : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      ReceivingActorKey;                                        // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      InstigatorActorKey;                                       // 0x0098(0x0028) (Edit)
	float                                              AggroStrength;                                            // 0x00C0(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              AggroMinAge;                                              // 0x00C4(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       AggroTag;                                                 // 0x00C8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_ReportAggro");
		return ptr;
	}

};


// Class Otherlands.BTT_SetAIState
// 0x0058 (0x00C8 - 0x0070)
class UBTT_SetAIState : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      PreviousStateKey;                                         // 0x0098(0x0028) (Edit)
	TEnumAsByte<EAICharacterState>                     NewState;                                                 // 0x00C0(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00C1(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_SetAIState");
		return ptr;
	}

};


// Class Otherlands.AiStateLibrary
// 0x0000 (0x0028 - 0x0028)
class UAiStateLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AiStateLibrary");
		return ptr;
	}


	bool STATIC_UpdateAiState(TEnumAsByte<EAICharacterState> NewState, class UBlackboardComponent* Blackboard, class AAICharacter* Character, const struct FBlackboardKeySelector& PreviousStateKey, const struct FBlackboardKeySelector& StateKey);
};


// Class Otherlands.BTT_SetTempoState
// 0x0080 (0x00F0 - 0x0070)
class UBTT_SetTempoState : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      PlayerKey;                                                // 0x0070(0x0028) (Edit)
	struct FBlackboardKeySelector                      StateKey;                                                 // 0x0098(0x0028) (Edit)
	struct FBlackboardKeySelector                      SpawnCatalogKey;                                          // 0x00C0(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly)
	TEnumAsByte<ETempoTargetState>                     NewState;                                                 // 0x00E8(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00E9(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_SetTempoState");
		return ptr;
	}

};


// Class Otherlands.BTT_SpawnTempoCreature
// 0x00E0 (0x0150 - 0x0070)
class UBTT_SpawnTempoCreature : public UBTTaskNode
{
public:
	bool                                               bForgetOnStateTransition;                                 // 0x0070(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0071(0x0003) MISSED OFFSET
	float                                              FollowTime;                                               // 0x0074(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              Strength;                                                 // 0x0078(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                IterationValue;                                           // 0x007C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	ESpawnAction                                       Action;                                                   // 0x0080(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0081(0x0007) MISSED OFFSET
	struct FBlackboardKeySelector                      PlayerKey;                                                // 0x0088(0x0028) (Edit)
	struct FBlackboardKeySelector                      VolumeKey;                                                // 0x00B0(0x0028) (Edit)
	struct FBlackboardKeySelector                      TempoChannelKey;                                          // 0x00D8(0x0028) (Edit)
	struct FBlackboardKeySelector                      TempoStateKey;                                            // 0x0100(0x0028) (Edit)
	struct FBlackboardKeySelector                      SpawnCatalogKey;                                          // 0x0128(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_SpawnTempoCreature");
		return ptr;
	}

};


// Class Otherlands.BTT_TimedMove
// 0x0030 (0x00E0 - 0x00B0)
class UBTT_TimedMove : public UBTTask_MoveTo
{
public:
	struct FBlackboardKeySelector                      AcceptanceRangeKey;                                       // 0x00B0(0x0028) (Edit)
	float                                              MoveTime;                                                 // 0x00D8(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x00DC(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_TimedMove");
		return ptr;
	}

};


// Class Otherlands.BTT_UpdateCycleCount
// 0x0028 (0x0098 - 0x0070)
class UBTT_UpdateCycleCount : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      CycleCountKey;                                            // 0x0070(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_UpdateCycleCount");
		return ptr;
	}

};


// Class Otherlands.BTT_VehicleAttack
// 0x0028 (0x0098 - 0x0070)
class UBTT_VehicleAttack : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      TrackingTargetKey;                                        // 0x0070(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_VehicleAttack");
		return ptr;
	}

};


// Class Otherlands.BTTask_Attack
// 0x0028 (0x0098 - 0x0070)
class UBTTask_Attack : public UBTTaskNode
{
public:
	struct FBlackboardKeySelector                      AcceptanceRangeKey;                                       // 0x0070(0x0028) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTTask_Attack");
		return ptr;
	}

};


// Class Otherlands.BuffComponent
// 0x0248 (0x0338 - 0x00F0)
class UBuffComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x00F0(0x0010) MISSED OFFSET
	TArray<class UBuffData*>                           Buffs;                                                    // 0x0100(0x0010) (Net, ZeroConstructor)
	TArray<struct FName>                               OldVisibleBuffs;                                          // 0x0110(0x0010) (ZeroConstructor)
	TArray<struct FName>                               DisplayBuffIds;                                           // 0x0120(0x0010) (Net, ZeroConstructor)
	class UObject*                                     BuffOwner;                                                // 0x0130(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0138(0x0028) MISSED OFFSET
	TArray<class UParticleSystemComponent*>            BuffFX;                                                   // 0x0160(0x0010) (ExportObject, ZeroConstructor)
	TArray<class UAudioComponent*>                     BuffAudio;                                                // 0x0170(0x0010) (ExportObject, ZeroConstructor)
	TArray<class AActor*>                              BuffPointLight;                                           // 0x0180(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData02[0x1A8];                                     // 0x0190(0x01A8) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuffComponent");
		return ptr;
	}


	bool SetBuffStackCount(const struct FName& BuffId, int StackCount, const struct FDamageConversionSet& Conversion, bool bRefreshDuration);
	bool SetBuffDuration(const struct FName& BuffId, float RemainingTime);
	bool RemoveBuff(const struct FName& BuffId, bool bFullStack, TEnumAsByte<EBuffRemoveReason> Reason, int StackCount);
	void OnRep_UpdateUIBuffs();
	void OnRep_DisplayBuffIds();
	void OnRep_BuffOwner();
	void MulticastUpdateDisplayBuff(int Index, const struct FName& BuffId);
	bool IsBuffCategoryPresent(const struct FName& BuffCategoryId);
	int GetBuffStackCount(const struct FName& BuffId);
	class UBuffData* GetBuffData(const struct FName& BuffId);
	void GetActiveUIBuffs(TArray<class UBuffData*>* OutBuffs);
	void GetActiveBuffs(TArray<class UBuffData*>* OutBuffs);
	bool CleanseBuff(const struct FName& BuffCategoryId, int BuffTier, int StackCount);
	class UBuffData* AddBuffWithConversion(const struct FName& BuffId, int StackCount, const struct FDamageConversionSet& Conversion, class AActor* DebuffCauser);
	class UBuffData* AddBuff(const struct FName& BuffId, int StackCount, class AActor* DebuffCauser);
};


// Class Otherlands.BuffData
// 0x0098 (0x00C0 - 0x0028)
class UBuffData : public UObject
{
public:
	class AActor*                                      LastCause;                                                // 0x0028(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<class AActor*>                              BuffCauses;                                               // 0x0030(0x0010) (BlueprintVisible, ZeroConstructor)
	struct FName                                       BuffId;                                                   // 0x0040(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x0048(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
	struct FDateTime                                   ServerExpirationTime;                                     // 0x0050(0x0008) (Net)
	class UBuffComponent*                              OwnerComponent;                                           // 0x0058(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              StackEffectiveness;                                       // 0x0060(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0064(0x0004) MISSED OFFSET
	struct FDamageConversionSet                        DamageConversion;                                         // 0x0068(0x0018) (BlueprintVisible, BlueprintReadOnly, Net)
	class UPrerequisiteInstance*                       TriggerPrereq;                                            // 0x0080(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UPrerequisiteInstance*                       TickPrereq;                                               // 0x0088(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DurationEffectiveness;                                    // 0x0090(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	bool                                               bCleansed;                                                // 0x0094(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bDestroying;                                              // 0x0095(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bIsAuraBuff;                                              // 0x0096(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1];                                       // 0x0097(0x0001) MISSED OFFSET
	int                                                LastTriggerCount;                                         // 0x0098(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x24];                                      // 0x009C(0x0024) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuffData");
		return ptr;
	}


	void UpdateEffectiveness(float InStackEffectiveness, float InDurationEffectiveness);
	void OnRep_NotifyOwnerStackCountChanged(int OldValue);
	void OnRep_NotifyOwnerBuffIdChanged();
	float GetTimeRemaining(class UWorld* World);
	class AMainGameState* GetGameState();
	struct FText STATIC_GetFormattedTooltipFor(const struct FName& BuffId, int StackCount);
	struct FText GetFormattedTooltip();
	float GetBuffTimeRemaining();
};


// Class Otherlands.BuffBlueprintableData
// 0x0028 (0x00E8 - 0x00C0)
class UBuffBlueprintableData : public UBuffData
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x00C0(0x0008) MISSED OFFSET
	TArray<struct FQueuedModifyStack>                  ApplyStackQueue;                                          // 0x00C8(0x0010) (ZeroConstructor)
	TArray<struct FQueuedEffectiveness>                ApplyEffectiveness;                                       // 0x00D8(0x0010) (ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuffBlueprintableData");
		return ptr;
	}


	void PreApplyEffect(bool bSet, TEnumAsByte<EApplyEffectReason> Reason, bool bUpdateTimeRemaining, float OverrideTimeRemaining);
	void PostApplyEffect(bool bSet, TEnumAsByte<EApplyEffectReason> Reason, bool bUpdateTimeRemaining, float OverrideTimeRemaining);
	void OverrideTimeRemaining(float OverrideTimeRemaining);
	void OnTicked(float TickScalar);
	void OnRefreshedExpiration();
	void OnExpireTick();
	bool OnBuffTriggered(const struct FCharaterBuffTriggerEventData& EventData);
	void OnAuraApplied(bool bSet, class ABasicCharacter* Target);
};


// Class Otherlands.BuffCategoryDelegates
// 0x0020 (0x0048 - 0x0028)
class UBuffCategoryDelegates : public UObject
{
public:
	class UObject*                                     BuffOwner;                                                // 0x0028(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       BuffCategoryId;                                           // 0x0030(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FScriptMulticastDelegate                    OnBuffCategoryImmunityChanged;                            // 0x0038(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuffCategoryDelegates");
		return ptr;
	}

};


// Class Otherlands.BuffOwnerInterface
// 0x0000 (0x0028 - 0x0028)
class UBuffOwnerInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuffOwnerInterface");
		return ptr;
	}


	bool UpdateBuffCategoryImmunity(const struct FName& BuffCategory);
	bool NotifyBuffUpdated();
	bool ModifyLerpScale(float Scalar, float ScaleDelay);
	bool GetBuffCategorySetValues(TArray<struct FName> BuffCategories, int Tier, float* ApplicationChance, float* StackEffectiveness, float* DurationEffectiveness);
	class UBuffCategoryDelegates* GetBuffCategoryImmunityDelegates(const struct FName& BuffCategory);
	bool BroadcastOnBuffTriggerEvent(const struct FCharaterBuffTriggerEventData& EventData);
};


// Class Otherlands.BuffSlotWidget
// 0x01F0 (0x0410 - 0x0220)
class UBuffSlotWidget : public UGameBaseWidget
{
public:
	struct FName                                       BuffId;                                                   // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SlotIndex;                                                // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x022C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CooldownPercent;                                          // 0x0230(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0234(0x0004) MISSED OFFSET
	struct FText                                       StackCountText;                                           // 0x0238(0x0018) (Edit, BlueprintVisible)
	class UBuffData*                                   BuffData;                                                 // 0x0250(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  Icon;                                                     // 0x0258(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0260(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bIsBeneficial;                                            // 0x0268(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0269(0x0007) MISSED OFFSET
	struct FText                                       DisplayName;                                              // 0x0270(0x0018) (Edit, BlueprintVisible)
	struct FText                                       CooldownText;                                             // 0x0288(0x0018) (Edit, BlueprintVisible)
	float                                              MaxCooldown;                                              // 0x02A0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CurrentCooldown;                                          // 0x02A4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FToolTipData                                ToolTipData;                                              // 0x02A8(0x0168) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuffSlotWidget");
		return ptr;
	}


	void UpdateCurrentCooldown();
	void UpdateBorder();
	void Update();
	void RemoveBuff();
	void RefreshTooltipData();
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.BuffWidget
// 0x0020 (0x0240 - 0x0220)
class UBuffWidget : public UGameBaseWidget
{
public:
	TArray<class UBuffSlotWidget*>                     Buffs;                                                    // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0230(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuffWidget");
		return ptr;
	}


	void Update();
	void RebuildBuffs();
	void OnRepopulateBuffs();
	int GetTotalBuffsNum();
	bool GetIsBeneficial(int BuffId);
	class UBuffData* GetBuffData(int Idx);
};


// Class Otherlands.BuildingAnchorComponent
// 0x0020 (0x0260 - 0x0240)
class UBuildingAnchorComponent : public USceneComponent
{
public:
	struct FName                                       InitialBuildingItemId;                                    // 0x0240(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MaximumHearthSearchRadius;                                // 0x0248(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x024C(0x0004) MISSED OFFSET
	class APlaceableActor*                             PlacedBuilding;                                           // 0x0250(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0258(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuildingAnchorComponent");
		return ptr;
	}

};


// Class Otherlands.BuildingAnchor
// 0x0020 (0x0348 - 0x0328)
class ABuildingAnchor : public AActor
{
public:
	class UBuildingAnchorComponent*                    AnchorComponent;                                          // 0x0328(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                BuildingTier;                                             // 0x0330(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	int                                                RestrictedBuildingTypes;                                  // 0x0334(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	struct FName                                       InitialBuildingItemId;                                    // 0x0338(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	float                                              MaximumHearthSearchRadius;                                // 0x0340(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0344(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuildingAnchor");
		return ptr;
	}

};


// Class Otherlands.BuildModeRadialWidget
// 0x0068 (0x0288 - 0x0220)
class UBuildModeRadialWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  MetalMaterialIcon;                                        // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  WoodMaterialIcon;                                         // 0x0228(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  StoneMaterialIcon;                                        // 0x0230(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  WallIcon;                                                 // 0x0238(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  FoundationIcon;                                           // 0x0240(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  FloorIcon;                                                // 0x0248(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  StairsIcon;                                               // 0x0250(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  PillarIcon;                                               // 0x0258(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  FoundationFloorIcon;                                      // 0x0260(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  RailingIcon;                                              // 0x0268(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  LedgeIcon;                                                // 0x0270(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  UnarmedIcon;                                              // 0x0278(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EPlaceableMaterial>                    MaterialChosen;                                           // 0x0280(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0281(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BuildModeRadialWidget");
		return ptr;
	}


	void UpdateButtonIcons();
	void Update();
	void ChooseUnarmed();
	void ChooseScaffolding(TEnumAsByte<EStructureType> ScaffoldType);
};


// Class Otherlands.CasterInterface
// 0x0000 (0x0028 - 0x0028)
class UCasterInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CasterInterface");
		return ptr;
	}


	bool PostCastAction(const struct FCastAction& CastAction);
	class UPrimitiveComponent* GetTargetComponent();
	class AActor* GetTargetActor();
	TEnumAsByte<EGender> GetCasterGender();
	bool FillCastAbilityInstance(const struct FCastAction& CastAction, struct FCastAbilityInstance* CastAbilityInstance);
	bool CreatureSummoned(class ASpawnGroup* SpawnGroup);
	bool CastFailed(const struct FCastAction& CastAction);
	bool CanDoCastAction(const struct FCastAction& CastAction, bool bCheckCooldown);
};


// Class Otherlands.AnimNotifyHit
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyHit : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyHit");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyAbilityPhase
// 0x0008 (0x0040 - 0x0038)
class UAnimNotifyAbilityPhase : public UAnimNotify
{
public:
	int                                                Phase;                                                    // 0x0038(0x0004) (Edit, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyAbilityPhase");
		return ptr;
	}

};


// Class Otherlands.AnimNotifySwap
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifySwap : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifySwap");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyStep
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyStep : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyStep");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyJumpLand
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyJumpLand : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyJumpLand");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyAmmoRelease
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyAmmoRelease : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyAmmoRelease");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyAmmoPickup
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyAmmoPickup : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyAmmoPickup");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyDrawStart
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyDrawStart : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyDrawStart");
		return ptr;
	}

};


// Class Otherlands.AnimNotify_PlaySoundScaled
// 0x0000 (0x0058 - 0x0058)
class UAnimNotify_PlaySoundScaled : public UAnimNotify_PlaySound
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotify_PlaySoundScaled");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyHideCharacter
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyHideCharacter : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyHideCharacter");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyShowCharacter
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyShowCharacter : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyShowCharacter");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyHideWeapon
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyHideWeapon : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyHideWeapon");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyShowWeapon
// 0x0000 (0x0038 - 0x0038)
class UAnimNotifyShowWeapon : public UAnimNotify
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyShowWeapon");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyHideWeaponState
// 0x0000 (0x0030 - 0x0030)
class UAnimNotifyHideWeaponState : public UAnimNotifyState
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyHideWeaponState");
		return ptr;
	}

};


// Class Otherlands.AnimNotifyHideCharacterState
// 0x0000 (0x0030 - 0x0030)
class UAnimNotifyHideCharacterState : public UAnimNotifyState
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AnimNotifyHideCharacterState");
		return ptr;
	}

};


// Class Otherlands.CharacterCreateWidget
// 0x00A8 (0x02C8 - 0x0220)
class UCharacterCreateWidget : public UGameBaseWidget
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0220(0x0008) MISSED OFFSET
	class UGearComponent*                              GearComponent;                                            // 0x0228(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0230(0x0010) MISSED OFFSET
	struct FText                                       CharacterName;                                            // 0x0240(0x0018) (Edit, BlueprintVisible)
	int                                                CharacterLevel;                                           // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                FactionId;                                                // 0x025C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0260(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0261(0x0007) MISSED OFFSET
	struct FName                                       HairStyleId;                                              // 0x0268(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaleDisplayHairStyleIndex;                                // 0x0270(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                FemaleDisplayHairStyleIndex;                              // 0x0274(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       HairColorId;                                              // 0x0278(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       SkinColorId;                                              // 0x0280(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaleDisplaySkinColorIndex;                                // 0x0288(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                FemaleDisplaySkinColorIndex;                              // 0x028C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaleDisplayHairColorIndex;                                // 0x0290(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                FemaleDisplayHairColorIndex;                              // 0x0294(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       FacialHairStyleId;                                        // 0x0298(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                DisplayFacialHairStyleIndex;                              // 0x02A0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x02A4(0x0004) MISSED OFFSET
	class APlayerCharacter*                            DefaultFemaleCharacter;                                   // 0x02A8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class APlayerCharacter*                            DefaultMaleCharacter;                                     // 0x02B0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class ASkeletalMeshActor*                          SkeletalMeshActor;                                        // 0x02B8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsEditable;                                              // 0x02C0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x7];                                       // 0x02C1(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CharacterCreateWidget");
		return ptr;
	}


	bool SwitchSkinColor(int InSkinColorId);
	bool SwitchHairColor(int InHairColorId);
	bool SwitchHair(int InHairId);
	bool SwitchGender(TEnumAsByte<EGender> InGender);
	bool SwitchFaction(int InFactionId);
	bool SwitchFacialHair(int InFacialHairId);
	void RotateRightPushed();
	void RotateLeftPushed();
	void RotateCharacter(float YawOffset);
	void RandomizeCustomization();
	void OnRandomLoad();
	void OnQueueUpdate(bool bInQueue, int QueuePosition);
	bool OnPlayButtonPushed();
	void OnFavoriteServerAdded(EAccountServiceResponse Response);
	bool OnDeleteConfirmed();
	void OnCharacterCreateStarted(bool CharacterExists, const struct FString& InCharacterId, const struct FString& InCharacterName, int InFactionId, int Level, TEnumAsByte<EGender> InGender, const struct FName& InHairId, const struct FName& InFacialHairId, const struct FName& InHairColorId, const struct FName& InSkinColorId, TArray<struct FName> PaperdollItemIds, bool InHasFactions);
	bool OnAscensionImport();
	bool OnAscensionExport();
	bool LoadCharacter();
	void LeaveQueue();
	void InitBPProperties();
	void GetSkinColorInfo(int Index, struct FName* OutId, bool* bUnlocked);
	int GetNumSkinColors();
	int GetNumHairStyles();
	int GetNumHairColors();
	int GetNumFacialHairStyles();
	void GetHairStyleInfo(int Index, struct FName* OutId, bool* bUnlocked);
	void GetHairColorInfo(int Index, struct FName* OutId, bool* bUnlocked);
	void GetFacialHairStyleInfo(int Index, struct FName* OutId, bool* bUnlocked);
};


// Class Otherlands.CharacterStats
// 0x0710 (0x0800 - 0x00F0)
class UCharacterStats : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x00F0(0x0018) MISSED OFFSET
	class ABasicCharacter*                             CharacterOwner;                                           // 0x0108(0x0008) (ZeroConstructor, IsPlainOldData)
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0110(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<int>                                        NonPlayerReplicatedIntStats;                              // 0x0118(0x0010) (Net, ZeroConstructor)
	struct FCharacterStatFloatArray                    NonPlayerReplicatedFloatStats;                            // 0x0128(0x00C8) (Net)
	unsigned char                                      UnknownData01[0x610];                                     // 0x01F0(0x0610) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CharacterStats");
		return ptr;
	}


	void OnRep_NonPlayerReplicatedFloatStats();
	int GetValue_Int(TEnumAsByte<ECharacterStat> Stat);
	float GetValue_Float(TEnumAsByte<ECharacterStat> Stat, bool bForValidate);
	float GetMinValue_Float(TEnumAsByte<ECharacterStat> Stat, bool bForValidate);
	int GetMaxValue_Int(TEnumAsByte<ECharacterStat> Stat, bool bForValidate);
	float GetMaxValue_Float(TEnumAsByte<ECharacterStat> Stat, bool bForValidate);
	float GetDefaultValue_Float(TEnumAsByte<ECharacterStat> Stat, bool bForValidate);
};


// Class Otherlands.CharacterStatManager
// 0x76E0 (0x7708 - 0x0028)
class UCharacterStatManager : public UObject
{
public:
	unsigned char                                      UnknownData00[0x6AF0];                                    // 0x0028(0x6AF0) MISSED OFFSET
	class UDataTable*                                  AmbientStatBuffTable;                                     // 0x6B18(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xA0];                                      // 0x6B20(0x00A0) MISSED OFFSET
	class UDataTable*                                  PerkRowTable;                                             // 0x6BC0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x6BC8(0x0050) MISSED OFFSET
	class UDataTable*                                  PerkBaseTable;                                            // 0x6C18(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x6C20(0x0050) MISSED OFFSET
	class UDataTable*                                  AscensionPerkLoadoutSlotTable;                            // 0x6C70(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x60];                                      // 0x6C78(0x0060) MISSED OFFSET
	class UDataTable*                                  AscensionPerkTierTable;                                   // 0x6CD8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x60];                                      // 0x6CE0(0x0060) MISSED OFFSET
	class UDataTable*                                  AscensionPerkBaseTable;                                   // 0x6D40(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0xF0];                                      // 0x6D48(0x00F0) MISSED OFFSET
	class UDataTable*                                  BadWordTable;                                             // 0x6E38(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x10];                                      // 0x6E40(0x0010) MISSED OFFSET
	class UDataTable*                                  TutorialTable;                                            // 0x6E50(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0xE0];                                      // 0x6E58(0x00E0) MISSED OFFSET
	class UDataTable*                                  HairCustomizationTable;                                   // 0x6F38(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData09[0x50];                                      // 0x6F40(0x0050) MISSED OFFSET
	class UDataTable*                                  FacialHairCustomizationTable;                             // 0x6F90(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x50];                                      // 0x6F98(0x0050) MISSED OFFSET
	class UDataTable*                                  HairColorTable;                                           // 0x6FE8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x50];                                      // 0x6FF0(0x0050) MISSED OFFSET
	class UDataTable*                                  SkinColorTable;                                           // 0x7040(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData12[0xD0];                                      // 0x7048(0x00D0) MISSED OFFSET
	class UDataTable*                                  NPCComponentBaseTable;                                    // 0x7118(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData13[0x50];                                      // 0x7120(0x0050) MISSED OFFSET
	class UDataTable*                                  MaterialSwapTable;                                        // 0x7170(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData14[0xA0];                                      // 0x7178(0x00A0) MISSED OFFSET
	class UDataTable*                                  SecondarySkillCategoryTable;                              // 0x7218(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData15[0x50];                                      // 0x7220(0x0050) MISSED OFFSET
	class UDataTable*                                  SecondarySkillTable;                                      // 0x7270(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData16[0x60];                                      // 0x7278(0x0060) MISSED OFFSET
	class UDataTable*                                  SecondarySkillStatTable;                                  // 0x72D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData17[0x50];                                      // 0x72E0(0x0050) MISSED OFFSET
	class UDataTable*                                  SecondarySkillPerkTable;                                  // 0x7330(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData18[0x50];                                      // 0x7338(0x0050) MISSED OFFSET
	class UDataTable*                                  SecondarySkillPerkSetTable;                               // 0x7388(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData19[0xA0];                                      // 0x7390(0x00A0) MISSED OFFSET
	class UDataTable*                                  CharacterEffectTable;                                     // 0x7430(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData20[0x60];                                      // 0x7438(0x0060) MISSED OFFSET
	class UDataTable*                                  CharacterVOTable;                                         // 0x7498(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData21[0x160];                                     // 0x74A0(0x0160) MISSED OFFSET
	class UCurveFloat*                                 XPCurve;                                                  // 0x7600(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData22[0x10];                                      // 0x7608(0x0010) MISSED OFFSET
	class UCurveFloat*                                 SecondarySkillXPCurve;                                    // 0x7618(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData23[0x10];                                      // 0x7620(0x0010) MISSED OFFSET
	class UCurveFloat*                                 SecondarySkillUsesCurve;                                  // 0x7630(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData24[0x10];                                      // 0x7638(0x0010) MISSED OFFSET
	class UCurveFloat*                                 StructureArmorCurve;                                      // 0x7648(0x0008) (ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WallStackArmorCurve;                                      // 0x7650(0x0008) (ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 ImmobilizationScalarCurve;                                // 0x7658(0x0008) (ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WarehouseXPCurve;                                         // 0x7660(0x0008) (ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WarehouseRepCurve;                                        // 0x7668(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData25[0x98];                                      // 0x7670(0x0098) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CharacterStatManager");
		return ptr;
	}

};


// Class Otherlands.CharacterStatManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class UCharacterStatManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CharacterStatManagerLibrary");
		return ptr;
	}


	void STATIC_ScrubString(struct FString* Input);
	bool STATIC_IsAscensionPerkValidForGender(const struct FName& AscensionPerkId, TEnumAsByte<EGender> Gender);
	float STATIC_GetXPForLevel(int Level);
	struct FTutorialBaseData STATIC_GetTutorialData(const struct FName& ID);
	TArray<struct FName> STATIC_GetTalentsForRow(TEnumAsByte<ECharacterArchetype> Archetype, int RowIndex);
	TArray<struct FName> STATIC_GetTalentRowIds();
	struct FSkinColorBaseData STATIC_GetSkinColorData(const struct FName& ID);
	struct FSecondarySkillStatData STATIC_GetSecondarySkillStatData(TEnumAsByte<ESecondarySkillStat> Stat);
	struct FSecondarySkillPerkData STATIC_GetSecondarySkillPerkData(const struct FName& ID);
	struct FName STATIC_GetSecondarySkillId(TEnumAsByte<ESecondarySkill> Skill);
	struct FSecondarySkillData STATIC_GetSecondarySkillData(const struct FName& ID);
	float STATIC_GetRepForWarehouseDepositTier(int Tier);
	struct FPerkRowData STATIC_GetPerkRowData(const struct FName& ID);
	struct FPerkBaseData STATIC_GetPerkData(const struct FName& ID);
	struct FHairCustomizationBaseData STATIC_GetHairCustomizationData(const struct FName& ID);
	struct FHairColorBaseData STATIC_GetHairColorData(const struct FName& ID);
	struct FFacialHairCustomizationBaseData STATIC_GetFacialHairCustomizationData(const struct FName& ID);
	struct FCharacterStatData STATIC_GetCharacterStatData(TEnumAsByte<ECharacterStat> Stat);
	struct FName STATIC_GetBuffIdForArchetype(TEnumAsByte<ECharacterArchetype> Archetype);
	struct FAscensionPerkTierData STATIC_GetAscensionPerkTier(const struct FName& ID);
	struct FAscensionPerkLoadoutSlotData STATIC_GetAscensionPerkLoadoutSlot(const struct FName& ID);
	class UTexture2D* STATIC_GetAscensionPerkIcon(const struct FName& ID);
	struct FAscensionPerkBaseData STATIC_GetAscensionPerkBase(const struct FName& ID);
	TArray<struct FName> STATIC_GetAscenionPerkTiers();
	TArray<struct FName> STATIC_GetAscenionPerksByTier(const struct FName& ID);
	TArray<struct FName> STATIC_GetAscenionPerkLoadoutSlots();
	bool STATIC_AscensionFromBlob(TArray<unsigned char> InBlob, const struct FString& UniqueSaveId, struct FAscensionUnlockSet* OutUnlockSet);
};


// Class Otherlands.ChatChannel
// 0x0068 (0x0090 - 0x0028)
class UChatChannel : public UObject
{
public:
	unsigned char                                      UnknownData00[0x68];                                      // 0x0028(0x0068) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ChatChannel");
		return ptr;
	}


	class AGamePlayerController* GetPlayerInChannel(const struct FString& UniqueSaveId);
	struct FString GetChatChannelTypeString();
};


// Class Otherlands.ChatChannelLibrary
// 0x0000 (0x0028 - 0x0028)
class UChatChannelLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ChatChannelLibrary");
		return ptr;
	}


	void STATIC_BroadcastKill(class UObject* WorldContextObject, class APlayerCharacter* Victim, class APlayerCharacter* Perp);
};


// Class Otherlands.ChatItemWidget
// 0x0020 (0x0240 - 0x0220)
class UChatItemWidget : public UGameBaseWidget
{
public:
	struct FText                                       ChatLineText;                                             // 0x0220(0x0018) (Edit, BlueprintVisible)
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0238(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ChatItemWidget");
		return ptr;
	}

};


// Class Otherlands.ChatWidget
// 0x0160 (0x0380 - 0x0220)
class UChatWidget : public UGameBaseWidget
{
public:
	bool                                               bIsChatInputEnabled;                                      // 0x0220(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0221(0x0007) MISSED OFFSET
	class UMultiLineEditableTextBox*                   ChatInputTextBox;                                         // 0x0228(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UMultiLineEditableTextBox*                   ChannelTextBox;                                           // 0x0230(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TEnumAsByte<EChatChannelType>                      ChatChannelType;                                          // 0x0238(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0239(0x0007) MISSED OFFSET
	struct FString                                     ChatTarget;                                               // 0x0240(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<class UChatItemWidget*>                     ChatItemWidgets;                                          // 0x0250(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	unsigned char                                      UnknownData02[0x120];                                     // 0x0260(0x0120) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ChatWidget");
		return ptr;
	}


	void UnfocusChat();
	void StartChatting();
	void SendChat();
	void ReceiveSystemMessage(const struct FChatSystemMessage& SystemMessage, TEnumAsByte<EChatChannelType> ChannelType);
	void ReceiveLocalMessage(const struct FText& Message);
	void ReceiveEventLog(const struct FEventLogEntry& EventLog);
	void ReceiveChatMessage(const struct FText& SourcePlayerName, const struct FText& ChatMessage, int FactionId, TEnumAsByte<EChatChannelType> ChannelType);
	void PostPlayerLocation();
	void GetChannelFromInput();
	void EscapeChat();
	void Emote(const struct FText& EmoteMessage);
	void ChangeColor(int Color);
	void AddChatToChatBox(const struct FText& ChatMessage, TEnumAsByte<EChatChannelType> ChannelType);
};


// Class Otherlands.ChooseItemActionComponent
// 0x0060 (0x0190 - 0x0130)
class UChooseItemActionComponent : public UActionComponent
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x0130(0x0058) MISSED OFFSET
	class APlayerCharacter*                            Player;                                                   // 0x0188(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ChooseItemActionComponent");
		return ptr;
	}


	bool StartMirrorPose(bool bMirrorPose);
	bool StartConsumeItem(class UInventoryItem* InvItem);
	bool StartChooseItemAction(const struct FChooseItemParam& Source);
	bool StartChooseItem(int ItemIdx, TEnumAsByte<EHeldItemLocation> Location, TEnumAsByte<EChooseItemToggleMode> ToggleMode);
	void ServerStartSwapItem(const struct FChooseItemParam& Source);
	void ServerStartPoseChange(const struct FChooseItemParam& Source);
	void ServerStartConsumeItem(class UInventoryItem* InvItem);
	void ServerStartChooseItemAction(const struct FChooseItemParam& Source);
	void ServerOnSwapImpl();
	struct FChooseItemParam GetItemParam(class UInventoryItem* InvItem);
	void ClientVerifyHeldItem(class UInventoryItem* HeldItem);
};


// Class Otherlands.Clan
// 0x0108 (0x0430 - 0x0328)
class AClan : public AActor
{
public:
	struct FScriptMulticastDelegate                    OnDisband;                                                // 0x0328(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMemberListUpdate;                                       // 0x0338(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UChatChannel*                                ClanChatChannel;                                          // 0x0348(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	TArray<struct FLimitedPlaceableCount>              LimitedPlaceableCounts;                                   // 0x0350(0x0010) (Net, ZeroConstructor)
	TArray<struct FClanInvite>                         PendingInvites;                                           // 0x0360(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient)
	struct FClanData                                   Data;                                                     // 0x0370(0x0028) (BlueprintVisible, BlueprintReadOnly, Net, Transient)
	TArray<struct FClanMember>                         Members;                                                  // 0x0398(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient)
	int                                                NumOnlinePlayers;                                         // 0x03A8(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x03AC(0x0004) MISSED OFFSET
	struct FStructurePermissions                       ClanPermissions;                                          // 0x03B0(0x0070) (BlueprintVisible, BlueprintReadOnly, Net, Transient)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0420(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.Clan");
		return ptr;
	}


	EClanOpResult RescindInvite(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EClanOpResult RemoveMemberBySaveId(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EClanOpResult RemoveMember(class AGamePlayerController* Caller, class AGamePlayerController* Player, bool bKicked);
	EClanOpResult RejectInvite(class AGamePlayerController* Caller);
	EClanOpResult PromoteMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	void MulticastRosterUpdated();
	bool IsPlayerClanMemberByCharacterId(const struct FString& CharacterId);
	bool IsPlayerClanMember(class AGamePlayerController* Player);
	bool HasPermissionById(const struct FString& CharacterId, const struct FName& PermissionId);
	bool HasPermission(const struct FString& CharacterId, TEnumAsByte<EPermission_CodeMap> permission);
	TArray<struct FName> GetPermissionLevels();
	struct FName GetPermissionLevel(const struct FString& CharacterId);
	EClanOpResult DemoteMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EClanOpResult CanRemoveMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EClanOpResult CanPromoteMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EClanOpResult CanLeaveClan(class AGamePlayerController* Caller);
	EClanOpResult CanInviteMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EClanOpResult CanDemoteMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EClanOpResult BroadcastToClanChannel(class AGamePlayerController* SourcePlayer, const struct FText& Input);
	EClanOpResult AddMember(class AGamePlayerController* Caller, class AGamePlayerController* Player, bool bConfirmed);
};


// Class Otherlands.ClientEffects
// 0x0028 (0x0350 - 0x0328)
class AClientEffects : public AActor
{
public:
	class USceneComponent*                             SceneRoot;                                                // 0x0328(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class USceneCaptureComponent2D*                    SpiritPortalMaskCapture;                                  // 0x0330(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UTextureRenderTarget2D*                      SpiritPortalRenderTarget;                                 // 0x0338(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0340(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ClientEffects");
		return ptr;
	}

};


// Class Otherlands.ClientGatekeeper
// 0x0240 (0x0568 - 0x0328)
class AClientGatekeeper : public AActor
{
public:
	struct FString                                     IndexEndpoint;                                            // 0x0328(0x0010) (ZeroConstructor, Config)
	struct FString                                     TicketEndpoint;                                           // 0x0338(0x0010) (ZeroConstructor, Config)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0348(0x0018) MISSED OFFSET
	class AGatekeeperBeaconClient*                     BeaconClient;                                             // 0x0360(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x200];                                     // 0x0368(0x0200) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ClientGatekeeper");
		return ptr;
	}


	struct FString GetServerId(int Index);
};


// Class Otherlands.Climate
// 0x0008 (0x0330 - 0x0328)
class AClimate : public AActor
{
public:
	class USeasonsComponent*                           Component;                                                // 0x0328(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.Climate");
		return ptr;
	}

};


// Class Otherlands.CombatantComponent
// 0x0068 (0x0158 - 0x00F0)
class UCombatantComponent : public UActorComponent
{
public:
	class UObject*                                     ReplicatedOwner;                                          // 0x00F0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x48];                                      // 0x00F8(0x0048) MISSED OFFSET
	class UStaticMesh*                                 ProjectileMesh;                                           // 0x0140(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0148(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CombatantComponent");
		return ptr;
	}


	void OnRep_ReplicatedOwner();
	void InitializeCombatant(const TScriptInterface<class UBasicIdentityInterface>& InOwner);
};


// Class Otherlands.CombatantLibrary
// 0x0000 (0x0028 - 0x0028)
class UCombatantLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CombatantLibrary");
		return ptr;
	}


	bool STATIC_SupportsCombatTarget(class UObject* Obj);
	bool STATIC_SupportsCombatant(class UObject* Obj);
	bool STATIC_SupportsBasicIdentity(class UObject* Obj);
	TScriptInterface<class UCombatTargetInterface> STATIC_GetCombatTargetFromHit(class AActor* Actor, class UActorComponent* Component, int ItemIndex, bool bAllowSpawn, bool* bDidSpawn);
	TScriptInterface<class UCombatTargetInterface> STATIC_GetCombatTarget(class UObject* Obj);
	TScriptInterface<class UBasicIdentityInterface> STATIC_GetBasicIdentityFromHit(class AActor* Actor, class UActorComponent* Component, int ItemIndex, bool bAllowSpawn, bool* bDidSpawn);
	TScriptInterface<class UBasicIdentityInterface> STATIC_GetBasicIdentity(class UObject* Obj);
};


// Class Otherlands.CombatFeedbackComponent
// 0x0018 (0x0108 - 0x00F0)
class UCombatFeedbackComponent : public UActorComponent
{
public:
	bool                                               bBroadcastDamage;                                         // 0x00F0(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x17];                                      // 0x00F1(0x0017) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CombatFeedbackComponent");
		return ptr;
	}


	void STATIC_SendFeedbackEvent(class AActor* Dealer, class AActor* Target, TEnumAsByte<EFeedbackEventType> FeedbackEvent, const struct FVector& ImpactLocation, float Amount, float Strength, float Multiplier);
	void MulticastDamageEvent(class UObject* Dealer, class UObject* Target, TEnumAsByte<EFeedbackEventType> FeedbackEvent, const struct FVector& ImpactLocation, float Amount, float Strength, float Multiplier);
	void DamageTaken(const TScriptInterface<class UBasicIdentityInterface>& Dealer, const TScriptInterface<class UCombatTargetInterface>& Target, TEnumAsByte<EFeedbackEventType> FeedbackEvent, const struct FVector& ImpactLocation, float Amount, float Strength, float Multiplier);
	void DamageDealt(const TScriptInterface<class UBasicIdentityInterface>& Dealer, const TScriptInterface<class UCombatTargetInterface>& Target, TEnumAsByte<EFeedbackEventType> FeedbackEvent, const struct FVector& ImpactLocation, float Amount, float Strength, float Multiplier);
	void ClientDamageEvent(class UObject* Dealer, class UObject* Target, TEnumAsByte<EFeedbackEventType> FeedbackEvent, const struct FVector& ImpactLocation, float Amount, float Strength, float Multiplier);
};


// Class Otherlands.BasicIdentityInterface
// 0x0000 (0x0028 - 0x0028)
class UBasicIdentityInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BasicIdentityInterface");
		return ptr;
	}


	bool RewardHit(class UObject* HitObject, float ActionTime, float Damage, bool bIsCrit, TEnumAsByte<ESecondarySkill> SecondarySkill);
	bool PlayGeneralFX(const struct FGeneralFXData& FX, const struct FVector& TargetLocation, class UParticleSystemComponent** InOutParticleComp, class UAudioComponent** InOutAudioComp, class AActor** InOutPointLight);
	bool IsPlayer();
	TEnumAsByte<ESpiritRealmState> IsInSpiritRealm();
	bool IsFriendlyTo(class AActor* Target);
	bool IsDead();
	class USceneComponent* GetWeaponSceneComponent();
	class USpellCastComponent* GetSpellCastComponent();
	class USecondarySkillComponent* GetSecondarySkillComponent();
	class USceneComponent* GetSceneComponent();
	bool GetScaledDamageConversion(int BaseLevel, struct FDamageConversionSet* OutConversion);
	class APawn* GetPawn();
	class UObject* GetObject();
	struct FVector GetGroundLocation();
	struct FString GetGenericName();
	int GetFactionId();
	struct FVector GetCombatLocation();
	class AController* GetCombatController();
	class UPrimitiveComponent* GetCombatComponent();
	class UCharacterStats* GetCharacterStats();
	int GetCharacterLevel();
	class UBuffComponent* GetBuffComponent();
	class UAmbientStatComponent* GetAmbientStatComponent();
	class AActor* GetActor();
	bool ConvertDamage(struct FTypedDamage* InOutDamage);
};


// Class Otherlands.CombatTargetInterface
// 0x0000 (0x0028 - 0x0028)
class UCombatTargetInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CombatTargetInterface");
		return ptr;
	}


	float TakeDamageOfType(const struct FTypedDamage& TypedDamage, const struct FDamageEvent& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser);
	bool TakeBuff(const struct FName& BuffId, class AActor* DebuffCauser, TEnumAsByte<EMountHitType> MountHit, const struct FDamageConversionSet& Conversion, int StackCount);
	bool ResetTickTime(TEnumAsByte<ECharacterStat> Stat, float Delay, float PauseModifier);
	bool NotifyStatChanged(TEnumAsByte<ECharacterStat> Stat, float OldFloatValue, int OldIntValue);
	bool ModifyInstantStatValue(TEnumAsByte<ECharacterStat> Stat, float FloatDelta, TEnumAsByte<EDamageSourceType> Source, const struct FName& SourceId, class AActor* StatChanger);
	bool HasAnyStatusFlags(int StatusFlags);
	float GetUnitToSiegeDamageConversionScalar();
	TEnumAsByte<EDamageTargetType> GetDamageTargetType();
	struct FName GetCreatureFamily();
	float GetCombatMaxHealth();
	float GetCombatHealth();
	bool GetCharacterStatusFlag(TEnumAsByte<ECharacterStatusFlag> StatusFlag);
	bool CanTakeDamage();
	bool ApplyStatusFlag(TEnumAsByte<ECharacterStatusFlag> StatusFlag, bool bSet);
	bool AllowsReward();
	bool AbsorbsDamage();
};


// Class Otherlands.ConfirmWidget
// 0x0028 (0x0248 - 0x0220)
class UConfirmWidget : public UGameBaseWidget
{
public:
	struct FText                                       ConfirmText;                                              // 0x0220(0x0018) (Edit, BlueprintVisible)
	bool                                               bCanConfirm;                                              // 0x0238(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xF];                                       // 0x0239(0x000F) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ConfirmWidget");
		return ptr;
	}


	void SetPlaceableToDelete(class UPlaceableMeshComponent* Mesh);
	void Confirm();
	void CloseConfirmBox();
};


// Class Otherlands.ContextMenuSlotWidget
// 0x0040 (0x0260 - 0x0220)
class UContextMenuSlotWidget : public UGameBaseWidget
{
public:
	struct FText                                       MenuItemText;                                             // 0x0220(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   SlotVisibility;                                           // 0x0238(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   WaitBarVisibility;                                        // 0x0239(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x023A(0x0002) MISSED OFFSET
	float                                              WaitBarValue;                                             // 0x023C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EContextMenuSlotState>                 SlotState;                                                // 0x0240(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0241(0x0003) MISSED OFFSET
	struct FLinearColor                                CurrentColor;                                             // 0x0244(0x0010) (Edit, BlueprintVisible, IsPlainOldData)
	struct FVector2D                                   Position;                                                 // 0x0254(0x0008) (Edit, BlueprintVisible, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x025C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ContextMenuSlotWidget");
		return ptr;
	}


	void SetSlotPosition(const struct FVector2D& Pos);
};


// Class Otherlands.ContextMenuWidget
// 0x00A0 (0x02C0 - 0x0220)
class UContextMenuWidget : public UGameBaseWidget
{
public:
	int                                                NumItems;                                                 // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                CurrentSelection;                                         // 0x0224(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       MenuTitle;                                                // 0x0228(0x0018) (Edit, BlueprintVisible)
	TArray<struct FContextMenuActionData>              MenuItems;                                                // 0x0240(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<class UContextMenuSlotWidget*>              MenuSlots;                                                // 0x0250(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	float                                              ClickToConfirmTime;                                       // 0x0260(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ClickToConfirmCurrentTime;                                // 0x0264(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   MenuSlotOffset;                                           // 0x0268(0x0008) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              MenuRadius;                                               // 0x0270(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MouseMax;                                                 // 0x0274(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MouseMultiplier;                                          // 0x0278(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MouseMargin;                                              // 0x027C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                ColorUnselected;                                          // 0x0280(0x0010) (Edit, BlueprintVisible, IsPlainOldData)
	struct FLinearColor                                ColorSelected;                                            // 0x0290(0x0010) (Edit, BlueprintVisible, IsPlainOldData)
	struct FLinearColor                                ColorWaiting;                                             // 0x02A0(0x0010) (Edit, BlueprintVisible, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x02B0(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ContextMenuWidget");
		return ptr;
	}


	void InitContextMenu();
};


// Class Otherlands.ControlPoint
// 0x00A8 (0x03D0 - 0x0328)
class AControlPoint : public APlaceableStructureContainer
{
public:
	class USceneComponent*                             SceneRoot;                                                // 0x0328(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	int                                                ControllingFactionId;                                     // 0x0330(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0334(0x0004) MISSED OFFSET
	class APlaceableStructure*                         PlaceableStructure;                                       // 0x0338(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	class UNavigationInvokerComponent*                 NavInvoker;                                               // 0x0340(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<class UMaterialInstanceDynamic*>            FactionDynamicMaterials;                                  // 0x0348(0x0010) (ZeroConstructor)
	class UPlaceableMeshComponent*                     Mesh;                                                     // 0x0358(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	struct FIntVector                                  StructureGridMin;                                         // 0x0360(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, IsPlainOldData)
	struct FIntVector                                  StructureGridMax;                                         // 0x036C(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, IsPlainOldData)
	int                                                StructurePadding;                                         // 0x0378(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              InfluenceRange;                                           // 0x037C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlaceableItemBaseId;                                      // 0x0380(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TArray<struct FControlPointBuff>                   Buffs;                                                    // 0x0388(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	class UInteractiveMeshComponent*                   PlugComponent;                                            // 0x0398(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x03A0(0x0028) UNKNOWN PROPERTY: SoftClassProperty Otherlands.ControlPoint.PointLightClass
	unsigned char                                      UnknownData02[0x8];                                       // 0x03C8(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ControlPoint");
		return ptr;
	}


	void OnRep_ControllingFactionId();
};


// Class Otherlands.CraftQueue
// 0x0048 (0x0070 - 0x0028)
class UCraftQueue : public UObject
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0028(0x0020) MISSED OFFSET
	TArray<struct FQueuedCraft>                        CraftQueue;                                               // 0x0048(0x0010) (ZeroConstructor)
	int                                                CraftQueueHead;                                           // 0x0058(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                CraftQueueTail;                                           // 0x005C(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0060(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftQueue");
		return ptr;
	}

};


// Class Otherlands.EventHandler
// 0x0010 (0x0038 - 0x0028)
class UEventHandler : public UObject
{
public:
	struct FScriptDelegate                             OnEventHandlerUnbound;                                    // 0x0028(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.EventHandler");
		return ptr;
	}

};


// Class Otherlands.CraftEventHandler
// 0x0068 (0x00A0 - 0x0038)
class UCraftEventHandler : public UEventHandler
{
public:
	struct FScriptDelegate                             OnCraftResult;                                            // 0x0038(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnCraftUpdated;                                           // 0x0048(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnCraftBegin;                                             // 0x0058(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnCraftEnd;                                               // 0x0068(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnCraftQueueAdded;                                        // 0x0078(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnStationOn;                                              // 0x0088(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0098(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftEventHandler");
		return ptr;
	}


	void Unbind();
};


// Class Otherlands.CraftEventHandlerStack
// 0x0010 (0x0038 - 0x0028)
class UCraftEventHandlerStack : public UObject
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0028(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftEventHandlerStack");
		return ptr;
	}


	class UCraftEventHandler* STATIC_CreateCraftEventHandler(class UObject* Owner);
};


// Class Otherlands.CraftComponent
// 0x0198 (0x0288 - 0x00F0)
class UCraftComponent : public UActorComponent
{
public:
	struct FScriptMulticastDelegate                    OnCraftResultEvent;                                       // 0x00F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftBrokenResultEvent;                                 // 0x0100(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftCriticalResultEvent;                               // 0x0110(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftResult;                                            // 0x0120(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftUpdated;                                           // 0x0130(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftBegin;                                             // 0x0140(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftEnd;                                               // 0x0150(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnStationOn;                                              // 0x0160(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnItemRepairEvent;                                        // 0x0170(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UCraftComponent*                             ActiveStationCraftComponent;                              // 0x0180(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FCraftRecipiePrototype                      LastPrototype;                                            // 0x0188(0x0058) (Net)
	TWeakObjectPtr<class UInventoryComponent>          InventoryComponent;                                       // 0x01E0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	TWeakObjectPtr<class UInventoryComponent>          FuelInventoryComponent;                                   // 0x01E8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	TWeakObjectPtr<class UInteractiveMeshComponent>    MeshOwner;                                                // 0x01F0(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       PlaceableItemId;                                          // 0x01F8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bIsStationActive;                                         // 0x0200(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0201(0x0003) MISSED OFFSET
	float                                              StoredSkillXP;                                            // 0x0204(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	TArray<class UCraftQueue*>                         CraftQueues;                                              // 0x0208(0x0010) (ExportObject, ZeroConstructor, Transient)
	struct FString                                     OwnerId;                                                  // 0x0218(0x0010) (Net, ZeroConstructor)
	struct FName                                       ItemIdLastFuel;                                           // 0x0228(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class URemoteCraftLinkManager*                     RemoteCraftLinkManager;                                   // 0x0230(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	class UCraftEventHandlerStack*                     EventHandlerStack;                                        // 0x0238(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x48];                                      // 0x0240(0x0048) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftComponent");
		return ptr;
	}


	bool UnbindEventHandler(class UCraftEventHandler* EventHandler);
	void SetStationOn(class APlayerCharacter* PlayerCharacter, bool bOn);
	void ServerResetTimer(int QueueIndex);
	void RequestCraftProgress(class URemoteCraftComponent* RemoteCraftComponent, int QueueIndex);
	void OnRep_StationActive();
	void OnRep_PlaceableItemId();
	bool NeedsFuel();
	bool IsStationWeaponMod();
	bool IsStationOn();
	bool IsStationActive();
	bool IsResearchUnlocked(const struct FName& RecipeId, class APlayerCharacter* Player);
	bool IsResearchStation();
	bool IsRefinery();
	bool IsPlayerOwned();
	bool IsPersonalStation(class APlayerCharacter* Player);
	bool IsCraftingAny();
	bool IsCrafting(int QueueIndex);
	TEnumAsByte<ETechTreeType> GetTechTreeType();
	TEnumAsByte<EItemStationFuelType> GetStationFuelType();
	bool GetRecipeData(const struct FName& RecipeId, struct FRecipeData* OutData);
	int GetReagentCount(const struct FName& ReagentId, class UCraftComponent* StationCraftComp, bool bUseWarehouse);
	int GetQueuedCraftNum(int QueueIndex);
	struct FQueuedCraft GetQueuedCraft(int QueueIndex, int Index, int* OutSlotIndex);
	struct FName GetPlaceableItemId();
	int GetMaxCraftCount(const struct FName& RecipeId, class UCraftComponent* StationCraftComp, class APlayerCharacter* Player);
	class UInventoryComponent* GetInventoryComponent();
	class UInventoryComponent* GetFuelInventoryComponent();
	bool GetFactionUseCost(const struct FName& RecipeId, int Count, class UCraftComponent* StationCraftComp, class APlayerCharacter* Player, float* OutUseScoreCost);
	int GetCraftQueueSlots(int QueueIndex);
	int GetCraftQueueCount();
	float GetCraftingProgress(int QueueIndex, bool* bOutNeedsUpdate);
	void GetAllSupportedSkillTrees(TArray<struct FName>* OutSkillTrees);
	void GetAllSupportedSkillTreeFolders(TArray<struct FName>* OutFolders);
	void GetAllSupportedRecipes(TArray<struct FName>* OutRecipeIds);
	bool DoesStationSupportCraftSkillTreeType(const struct FName& ID);
	bool DoesStationNeedFuelAdded();
	bool DoesPlayerHaveCraftMaterials(const struct FName& RecipeId, int Count, class UCraftComponent* StationCraftComp, class APlayerCharacter* Player);
	bool CanRepairItemAtStation(class UInventoryItem* DamagedItem, class UCraftComponent* StationCraftComp, class APlayerCharacter* Player, bool* OutHasReagents);
	bool CanPlayerCraftItem(const struct FName& RecipeId, class UCraftComponent* StationCraftComp, class APlayerCharacter* Player, ECraftRestrictedReason* Reason, float* ExpectedWarehouseCost);
	void CancelCraftAt(int QueueIndex, int AtIndex);
	bool BindEventHandler(class UCraftEventHandler* EventHandler, bool bPrimary);
};


// Class Otherlands.CraftingLootTickerSlotWidget
// 0x0060 (0x0280 - 0x0220)
class UCraftingLootTickerSlotWidget : public UGameBaseWidget
{
public:
	struct FName                                       ItemId;                                                   // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ItemCount;                                                // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x022C(0x0004) MISSED OFFSET
	struct FText                                       ItemName;                                                 // 0x0230(0x0018) (Edit, BlueprintVisible)
	struct FText                                       ItemCountText;                                            // 0x0248(0x0018) (Edit, BlueprintVisible)
	class UTexture2D*                                  ItemIcon;                                                 // 0x0260(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsRemovalSlot;                                           // 0x0268(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ECraftResultType>                      CraftResult;                                              // 0x0269(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x026A(0x0002) MISSED OFFSET
	struct FLinearColor                                TextColor;                                                // 0x026C(0x0010) (Edit, BlueprintVisible, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x027C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftingLootTickerSlotWidget");
		return ptr;
	}


	void Update();
	void OnUpdateCount(int CountToAdd);
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.CraftingLootTickerWidget
// 0x0000 (0x0220 - 0x0220)
class UCraftingLootTickerWidget : public UGameBaseWidget
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftingLootTickerWidget");
		return ptr;
	}

};


// Class Otherlands.CustomSkillTreeWidget
// 0x0000 (0x0208 - 0x0208)
class UCustomSkillTreeWidget : public UUserWidget
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CustomSkillTreeWidget");
		return ptr;
	}


	void Refresh();
	void GetChildrenOfClass(class UClass* WidgetClass, TArray<class UUserWidget*>* Results);
	void Configure(const struct FName& CraftSkillTreeId, class UCraftComponent* CraftComponentIn);
};


// Class Otherlands.CraftingManager
// 0x06D8 (0x0700 - 0x0028)
class UCraftingManager : public UObject
{
public:
	class UDataTable*                                  CraftRecipeTable;                                         // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0030(0x0050) MISSED OFFSET
	class UDataTable*                                  CraftResearchTable;                                       // 0x0080(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0088(0x0050) MISSED OFFSET
	class UDataTable*                                  CraftSkillTreeCategoryTable;                              // 0x00D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x60];                                      // 0x00E0(0x0060) MISSED OFFSET
	class UDataTable*                                  CraftSkillTreeFolderTable;                                // 0x0140(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0xB0];                                      // 0x0148(0x00B0) MISSED OFFSET
	class UDataTable*                                  CraftSkillTreeTable;                                      // 0x01F8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0xB0];                                      // 0x0200(0x00B0) MISSED OFFSET
	class UDataTable*                                  CraftDifficultyTierTable;                                 // 0x02B0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x448];                                     // 0x02B8(0x0448) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftingManager");
		return ptr;
	}

};


// Class Otherlands.CraftingManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class UCraftingManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftingManagerLibrary");
		return ptr;
	}


	bool STATIC_ShouldCraftRecipeBeInSkillTree(const struct FName& RecipeId, const struct FName& CraftSkillTreeId);
	bool STATIC_GetUnlockedCraftRecipesById(const struct FName& ID, TArray<struct FName>* Results);
	int STATIC_GetSlotIndexFromCraftRecipe(const struct FName& RecipeId, const struct FName& CraftSkillTreeId);
	class UTexture2D* STATIC_GetResearchIcon(const struct FName& ResearchId);
	class UTexture2D* STATIC_GetResearchExtraUnlockIcon(const struct FName& ResearchId, int Index);
	class UTexture2D* STATIC_GetRecipeIcon(const struct FName& RecipeId);
	struct FName STATIC_GetParentCraftRecipeId(const struct FName& RecipeId);
	int STATIC_GetNumRootCraftRecipesBySkillTree(const struct FName& SkillTreeId);
	int STATIC_GetNumCraftRecipesBySkillTree(const struct FName& SkillTreeId);
	int STATIC_GetNumChildrenCraftRecipes(int SlotIndex, const struct FName& CraftSkillTreeId);
	void STATIC_GetCraftSkillTreeListByFolder(const struct FName& ID, TArray<struct FName>* Results);
	class UTexture2D* STATIC_GetCraftSkillTreeIcon(const struct FName& CraftSkillTreeId);
	void STATIC_GetCraftSkillTreeFolderListByCategory(const struct FName& ID, TArray<struct FName>* Results);
	class UTexture2D* STATIC_GetCraftSkillTreeFolderIcon(const struct FName& CraftSkillTreeFolderId);
	bool STATIC_GetCraftSkillTreeFolderData(const struct FName& ID, struct FCraftSkillTreeFolderData* OutCraftSkillTreeFolderData);
	bool STATIC_GetCraftSkillTreeData(const struct FName& ID, struct FCraftSkillTreeData* OutCraftSkillTreeData);
	class UTexture2D* STATIC_GetCraftSkillTreeCategorySelectedIcon(const struct FName& CraftSkillTreeCategoryId);
	void STATIC_GetCraftSkillTreeCategoryList(TArray<struct FName>* Results);
	class UTexture2D* STATIC_GetCraftSkillTreeCategoryIcon(const struct FName& CraftSkillTreeCategoryId);
	bool STATIC_GetCraftSkillTreeCategoryData(const struct FName& ID, struct FCraftSkillTreeCategoryData* OutCraftSkillTreeCategoryData);
	bool STATIC_GetCraftResearchTreeByType(TEnumAsByte<ETechTreeType> TechTreeType, TArray<struct FName>* Results);
	struct FCraftResearchTierData STATIC_GetCraftResearchTierInfo(TEnumAsByte<ETechTreeType> TechTreeType, int Tier);
	int STATIC_GetCraftResearchRequiredXP(const struct FName& ResearchId);
	int STATIC_GetCraftResearchNumTiers(TEnumAsByte<ETechTreeType> TechTreeType);
	struct FCraftResearchData STATIC_GetCraftResearchData(const struct FName& ResearchId);
	bool STATIC_GetCraftRecipesUnlockedByResearch(const struct FName& ResearchId, TArray<struct FName>* OutResults);
	TArray<struct FName> STATIC_GetCraftRecipeSkillTreeList();
	struct FName STATIC_GetCraftRecipeFromSlotIndex(int SlotIndex, const struct FName& CraftSkillTreeId);
	struct FName STATIC_GetCraftRecipeForResearch(const struct FName& ResearchId);
	struct FCraftRecipeData STATIC_GetCraftRecipeData(const struct FName& RecipeId);
	bool STATIC_GetCraftDifficultyTier(const struct FName& ID, struct FCraftDifficultyTierData* OutTierData);
	struct FName STATIC_GetChildCraftRecipe(int ChildSlotIndex, int SlotIndex, const struct FName& CraftSkillTreeId);
};


// Class Otherlands.CraftingReagentSlotWidget
// 0x00B0 (0x02D0 - 0x0220)
class UCraftingReagentSlotWidget : public UGameBaseWidget
{
public:
	struct FName                                       ReagentId;                                                // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       ParentRecipeId;                                           // 0x0228(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  Icon;                                                     // 0x0230(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ItemCount;                                                // 0x0238(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x023C(0x0004) MISSED OFFSET
	struct FText                                       ItemCountText;                                            // 0x0240(0x0018) (Edit, BlueprintVisible)
	int                                                NeededCount;                                              // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x025C(0x0004) MISSED OFFSET
	struct FText                                       NeededCountText;                                          // 0x0260(0x0018) (Edit, BlueprintVisible)
	struct FText                                       RequiredCountText;                                        // 0x0278(0x0018) (Edit, BlueprintVisible)
	TEnumAsByte<EItemQuality>                          ReagentQuality;                                           // 0x0290(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EItemResourceType>                     ResourceType;                                             // 0x0291(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x2];                                       // 0x0292(0x0002) MISSED OFFSET
	float                                              RequiredResourceAmount;                                   // 0x0294(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       CategoryText;                                             // 0x0298(0x0018) (Edit, BlueprintVisible)
	struct FText                                       ReagentToolTipText;                                       // 0x02B0(0x0018) (Edit, BlueprintVisible)
	bool                                               bIsReagentSlotEnabled;                                    // 0x02C8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x02C9(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CraftingReagentSlotWidget");
		return ptr;
	}


	void Update();
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.CreatureAbilityComponent
// 0x0060 (0x0650 - 0x05F0)
class UCreatureAbilityComponent : public UAbilityComponent
{
public:
	float                                              Priority;                                                 // 0x05F0(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	float                                              Weight;                                                   // 0x05F4(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	int                                                AllowedStateFlags;                                        // 0x05F8(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1C];                                      // 0x05FC(0x001C) MISSED OFFSET
	bool                                               bUseWindupMontageTimeOut;                                 // 0x0618(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bUseActionMontageTimeOut;                                 // 0x0619(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x061A(0x0006) MISSED OFFSET
	class AAICharacter*                                AICharacterOwner;                                         // 0x0620(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	class UAnimMontage*                                ActiveMontage;                                            // 0x0628(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x20];                                      // 0x0630(0x0020) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CreatureAbilityComponent");
		return ptr;
	}


	void SnapshotCastTarget();
	bool ShouldSkipFlank();
	bool ShouldMaintainFacing();
	void SetCastTarget(class AActor* TargetActor, class UPrimitiveComponent* TargetComponent);
	void OnWindupMontageTimeOut();
	void OnWindupMontageBlendingOut(class UAnimMontage* WindupMontage, bool bInterrupted);
	void OnEncounterStart();
	void OnEncounterEnd();
	void OnCastingChargedTimer();
	void OnActionMontageTimeOut();
	void OnActionMontageFinished(class UAnimMontage* ActionMontage, bool bInterrupted);
	void MulticastPlayAbilityChargeMontage(float ChargeTime, float ActionTime);
	void MulticastPlayAbilityActionMontage(float ActionTime);
	bool InitializeCreatureAbility(const struct FName& InAbilityId);
	bool HasActiveMontage();
	struct FVector GetFireVector();
	struct FVector GetFireFrom();
	struct FCreatureAbilityData GetCreatureAbilityData();
	class UObject* GetCastTargetObject();
	class AActor* GetCastTargetActor();
	float GetAbilityMinRange();
	float GetAbilityMaxRange();
	bool EngageAbility();
	struct FCastAction ConstructCastAction(const struct FVector& From, const struct FVector& To);
	bool CanDamageStructure();
	bool CanDamagePlayer();
	bool CanChangeTarget();
};


// Class Otherlands.CrosshairWidget
// 0x0038 (0x0258 - 0x0220)
class UCrosshairWidget : public UGameBaseWidget
{
public:
	float                                              CrosshairSpread;                                          // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CrosshairDecreaseSpreadRate;                              // 0x0224(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                CrosshairColor;                                           // 0x0228(0x0010) (Edit, BlueprintVisible, IsPlainOldData)
	TEnumAsByte<ECrosshairType>                        CrosshairType;                                            // 0x0238(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bCrosshairRangeValid;                                     // 0x0239(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bCrosshairToolValid;                                      // 0x023A(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   CrossHairVisibility;                                      // 0x023B(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   HitVisibility;                                            // 0x023C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x023D(0x0003) MISSED OFFSET
	class UClass*                                      TrueAimWidgetClass;                                       // 0x0240(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UUserWidget*                                 TrueAimWidget;                                            // 0x0248(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0250(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CrosshairWidget");
		return ptr;
	}


	void ShowCrosshair();
	void HideCrosshair();
};


// Class Otherlands.CustomGameSettings
// 0x0028 (0x0050 - 0x0028)
class UCustomGameSettings : public UObject
{
public:
	bool                                               bEnableEditorAuthentication;                              // 0x0028(0x0001) (Edit, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	struct FString                                     ServerAddressOverride;                                    // 0x0030(0x0010) (Edit, ZeroConstructor, Config)
	struct FString                                     EditorVersionOverride;                                    // 0x0040(0x0010) (Edit, ZeroConstructor, Config)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.CustomGameSettings");
		return ptr;
	}

};


// Class Otherlands.DamageConversionLibrary
// 0x0000 (0x0028 - 0x0028)
class UDamageConversionLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.DamageConversionLibrary");
		return ptr;
	}


	struct FTypedDamage STATIC_ScaleDamage(const struct FTypedDamage& LHS, float Scalar);
	struct FDamageConversionSet STATIC_MakeFullDamageConversionSet(TArray<struct FDamageConversion> Conversions, float UnitScalar, float SiegeScalar);
	struct FDamageConversionSet STATIC_MakeDamageConversionSet(float UnitScalar, float SiegeScalar);
	float STATIC_GetDamageSum(const struct FTypedDamage& TypedDamage);
	void STATIC_EmptySet(struct FDamageConversionSet* Value);
	void STATIC_ConvertDamage(const struct FDamageConversionSet& Conversion, bool bIsUnit, struct FTypedDamage* Value);
	void STATIC_AddSet(int LhsStackCount, const struct FDamageConversionSet& RHS, int RhsStackCount, struct FDamageConversionSet* LHS);
	struct FTypedDamage STATIC_AddDamage(const struct FTypedDamage& LHS, const struct FTypedDamage& RHS);
};


// Class Otherlands.DatabaseService
// 0x0020 (0x0048 - 0x0028)
class UDatabaseService : public UObject
{
public:
	struct FString                                     DatabaseEndpoint;                                         // 0x0028(0x0010) (ZeroConstructor, Config)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0038(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.DatabaseService");
		return ptr;
	}


	void PutKey(const struct FString& Key, const struct FKeyData& Data, const struct FScriptDelegate& Delegate);
	void GetKey(const struct FString& Key, const struct FScriptDelegate& Delegate);
	void DeleteKey(const struct FString& Key, const struct FScriptDelegate& Delegate);
};


// Class Otherlands.BTT_ResetState
// 0x0000 (0x0070 - 0x0070)
class UBTT_ResetState : public UBTTaskNode
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_ResetState");
		return ptr;
	}

};


// Class Otherlands.PosableDepthMesh
// 0x0000 (0x0860 - 0x0860)
class UPosableDepthMesh : public UPoseableMeshComponent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PosableDepthMesh");
		return ptr;
	}

};


// Class Otherlands.BTService_ProcessFailedPath
// 0x0000 (0x0070 - 0x0070)
class UBTService_ProcessFailedPath : public UBTService
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTService_ProcessFailedPath");
		return ptr;
	}

};


// Class Otherlands.BTService_MaintainTempo
// 0x0000 (0x0070 - 0x0070)
class UBTService_MaintainTempo : public UBTService
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTService_MaintainTempo");
		return ptr;
	}

};


// Class Otherlands.BTT_FindSearchLocation
// 0x0000 (0x0070 - 0x0070)
class UBTT_FindSearchLocation : public UBTTaskNode
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_FindSearchLocation");
		return ptr;
	}

};


// Class Otherlands.BTT_InitializeState
// 0x0000 (0x0070 - 0x0070)
class UBTT_InitializeState : public UBTTaskNode
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.BTT_InitializeState");
		return ptr;
	}

};


// Class Otherlands.SpawnVolumeBase
// 0x00C8 (0x0460 - 0x0398)
class ASpawnVolumeBase : public AAoiAwareVolume
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0398(0x0008) MISSED OFFSET
	bool                                               bFreeplaceIsViable;                                       // 0x03A0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x03A1(0x0003) MISSED OFFSET
	float                                              StructureBuffer;                                          // 0x03A4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bMustBeViable;                                            // 0x03A8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bRegeneratePoints;                                        // 0x03A9(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bRegeneratePointsOnMove;                                  // 0x03AA(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x5];                                       // 0x03AB(0x0005) MISSED OFFSET
	struct FSpawnPointQueueSettings                    SpawnPointQueueSettings;                                  // 0x03B0(0x0068) (Edit, BlueprintVisible)
	float                                              SpawnZRangeOverride;                                      // 0x0418(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              SpawnVariation;                                           // 0x041C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	TArray<struct FVector>                             SpawnPointQueue;                                          // 0x0420(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FTransform                                  CachedActorTransform;                                     // 0x0430(0x0030) (IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnVolumeBase");
		return ptr;
	}


	void RegenerateSpawnPointQueue();
};


// Class Otherlands.DynamicSpawnVolume
// 0x0180 (0x05E0 - 0x0460)
class ADynamicSpawnVolume : public ASpawnVolumeBase
{
public:
	int                                                VolumePriority;                                           // 0x0460(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bDoSpiritEventSpawns;                                     // 0x0464(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0465(0x0003) MISSED OFFSET
	TArray<struct FTempoChannelSpawnData>              SpawnData;                                                // 0x0468(0x0010) (Edit, ZeroConstructor)
	unsigned char                                      UnknownData01[0x168];                                     // 0x0478(0x0168) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.DynamicSpawnVolume");
		return ptr;
	}

};


// Class Otherlands.DynamicStructure
// 0x0040 (0x0368 - 0x0328)
class ADynamicStructure : public APlaceableStructureContainer
{
public:
	struct FString                                     OwnerId;                                                  // 0x0328(0x0010) (Net, ZeroConstructor)
	int                                                FactionId;                                                // 0x0338(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x033C(0x0004) MISSED OFFSET
	class USceneComponent*                             SceneRoot;                                                // 0x0340(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class APlaceableStructure*                         PlaceableStructure;                                       // 0x0348(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UNavigationInvokerComponent*                 NavInvoker;                                               // 0x0350(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0358(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.DynamicStructure");
		return ptr;
	}

};


// Class Otherlands.EffectManager
// 0x01B8 (0x01E0 - 0x0028)
class UEffectManager : public UObject
{
public:
	class UDataTable*                                  ItemSoundTable;                                           // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0030(0x0050) MISSED OFFSET
	class UDataTable*                                  SurfaceImpactEffectTable;                                 // 0x0080(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0088(0x0050) MISSED OFFSET
	class UDataTable*                                  ImpactEffectKitTable;                                     // 0x00D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x00E0(0x0050) MISSED OFFSET
	class UDataTable*                                  HitZoneTable;                                             // 0x0130(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0138(0x0050) MISSED OFFSET
	class UDataTable*                                  PayloadTable;                                             // 0x0188(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x50];                                      // 0x0190(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.EffectManager");
		return ptr;
	}

};


// Class Otherlands.EffectManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class UEffectManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.EffectManagerLibrary");
		return ptr;
	}


	struct FPayloadData STATIC_GetPayloadData(const struct FName& ID);
};


// Class Otherlands.EnvQueryContext_BlackboardTargetLocation
// 0x0000 (0x0028 - 0x0028)
class UEnvQueryContext_BlackboardTargetLocation : public UEnvQueryContext
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.EnvQueryContext_BlackboardTargetLocation");
		return ptr;
	}

};


// Class Otherlands.EnvQueryContext_HostilesToAttack
// 0x0000 (0x0028 - 0x0028)
class UEnvQueryContext_HostilesToAttack : public UEnvQueryContext
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.EnvQueryContext_HostilesToAttack");
		return ptr;
	}

};


// Class Otherlands.EnvQueryContext_HostilesToFlee
// 0x0000 (0x0028 - 0x0028)
class UEnvQueryContext_HostilesToFlee : public UEnvQueryContext
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.EnvQueryContext_HostilesToFlee");
		return ptr;
	}

};


// Class Otherlands.EscapeMenuWidget
// 0x0000 (0x0220 - 0x0220)
class UEscapeMenuWidget : public UGameBaseWidget
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.EscapeMenuWidget");
		return ptr;
	}


	void ReturnToMainMenu();
	void CloseEscapeMenu();
};


// Class Otherlands.Faction
// 0x02C0 (0x05E8 - 0x0328)
class AFaction : public AActor
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0328(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnTechTreeSet;                                            // 0x0330(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMemoSet;                                                // 0x0340(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMotdSet;                                                // 0x0350(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnWarehouseSlotUpdated;                                   // 0x0360(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TArray<class UTechTree*>                           TechTrees;                                                // 0x0370(0x0010) (Net, ZeroConstructor, Transient)
	TArray<class UFactionSpirit*>                      Spirits;                                                  // 0x0380(0x0010) (Net, ZeroConstructor, Transient)
	float                                              SoulsStored;                                              // 0x0390(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0xA4];                                      // 0x0394(0x00A4) MISSED OFFSET
	int                                                BonusStashSlots;                                          // 0x0438(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                BonusCollectionSlots;                                     // 0x043C(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bDefeated;                                                // 0x0440(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0441(0x0007) MISSED OFFSET
	class UChatChannel*                                FactionChatChannel;                                       // 0x0448(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	TArray<int>                                        WarehouseItems;                                           // 0x0450(0x0010) (Net, ZeroConstructor, Transient)
	unsigned char                                      UnknownData03[0x10];                                      // 0x0460(0x0010) MISSED OFFSET
	struct FStructurePermissions                       FactionPermissions;                                       // 0x0470(0x0070) (BlueprintVisible, BlueprintReadOnly, Net, Transient)
	unsigned char                                      UnknownData04[0x40];                                      // 0x04E0(0x0040) MISSED OFFSET
	int                                                FactionId;                                                // 0x0520(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x0524(0x0004) MISSED OFFSET
	struct FString                                     FactionMotd;                                              // 0x0528(0x0010) (Net, ZeroConstructor, Transient)
	struct FString                                     FactionMemo;                                              // 0x0538(0x0010) (Net, ZeroConstructor, Transient)
	unsigned char                                      UnknownData06[0xA0];                                      // 0x0548(0x00A0) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.Faction");
		return ptr;
	}


	void UpdateBuffs(class APlayerCharacter* Player, bool bApply);
	TEnumAsByte<EVoteResult> TestOutcastVote(const struct FString& TargetUniqueSaveId);
	TEnumAsByte<EVoteResult> TestDemolishVote(const struct FString& TargetUniqueSaveId);
	void SetFactionMotd(const struct FString& NewMotd);
	void SetFactionMemo(const struct FString& NewMemo);
	void OnRep_WarehouseItems();
	void OnRep_TechTrees();
	void OnRep_FactionMotd();
	void OnRep_FactionMemo();
	void NotifyLadderNeedsUpdate();
	TEnumAsByte<EVoteResult> InitiateOutcastVote(const struct FString& TargetUniqueSaveId, class APlayerCharacter* Voter);
	TEnumAsByte<EVoteResult> InitiateDemolishVote(class APlayerCharacter* Requester, int RequestCount);
	int GetWarehouseCount(const struct FName& ItemId);
	float GetVictoryProgress();
	class UTechTree* GetTechTree(TEnumAsByte<ETechTreeType> TechTreeType);
	float GetSoulsStored();
	bool GetShieldState();
	float GetMaxSoulProgress();
	struct FString GetFactionMotd();
	struct FString GetFactionMemo();
	int GetFactionId();
	TEnumAsByte<EVoteResult> CastOutcastVote(const struct FString& TargetUniqueSaveId, class APlayerCharacter* Voter, bool bYae);
	TEnumAsByte<EVoteResult> CastDemolishVote(const struct FString& TargetUniqueSaveId, class APlayerCharacter* Voter, bool bYae);
	void BroadcastOutcastVoteResult(const struct FString& TargetUniqueSaveId, TEnumAsByte<EOutcastResult> Result);
	void BroadcastDemolishVoteResult(const struct FString& TargetUniqueSaveId, TEnumAsByte<EDemolishResult> Result);
	void ApplyNewPlayerBuffs(class APlayerCharacter* NewPlayer);
	void AddSouls(float SoulsToAdd);
	void AddEventLogEntry(const struct FEventLogEntry& Entry, const struct FName& ViewPermissionIdOverride);
};


// Class Otherlands.FactionManager
// 0x04E0 (0x0508 - 0x0028)
class UFactionManager : public UObject
{
public:
	class UDataTable*                                  FactionTable;                                             // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xA0];                                      // 0x0030(0x00A0) MISSED OFFSET
	class UDataTable*                                  PermissionTable;                                          // 0x00D0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x00D8(0x0050) MISSED OFFSET
	class UDataTable*                                  PermissionGroupTable;                                     // 0x0128(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0130(0x0050) MISSED OFFSET
	class UDataTable*                                  PermissionGroupLevelTable;                                // 0x0180(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0188(0x0050) MISSED OFFSET
	class UDataTable*                                  FactionReputationEventTable;                              // 0x01D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x50];                                      // 0x01E0(0x0050) MISSED OFFSET
	class UDataTable*                                  FactionStrengthEffectTable;                               // 0x0230(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x2D0];                                     // 0x0238(0x02D0) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.FactionManager");
		return ptr;
	}

};


// Class Otherlands.FactionManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class UFactionManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.FactionManagerLibrary");
		return ptr;
	}


	void STATIC_MakeStructurePermissions(TEnumAsByte<EGroupType_CodeMap> GroupType, int FactionId, struct FStructurePermissions* OutPermissions);
	TArray<struct FName> STATIC_GetPermissionsForGroup(const struct FName& PermissionGroupId);
	TArray<struct FName> STATIC_GetPermissionLevelPermissions(const struct FName& ID);
	struct FName STATIC_GetPermissionIdByGroupId(const struct FName& GroupType, TEnumAsByte<EPermission_CodeMap> permission);
	struct FName STATIC_GetPermissionId(TEnumAsByte<EGroupType_CodeMap> GroupType, TEnumAsByte<EPermission_CodeMap> permission);
	struct FName STATIC_GetPermissionGroupNormalLevelByReputationByGroupId(const struct FName& GroupType, float Reputation, float TimePlayed);
	struct FName STATIC_GetPermissionGroupNormalLevelByReputation(TEnumAsByte<EGroupType_CodeMap> GroupType, float Reputation, float TimePlayed);
	bool STATIC_GetPermissionGroupLevelsByReputationByGroupId(const struct FName& GroupType, float Reputation, int LadderPosition, float TimePlayed, struct FName* NormalLevel, struct FName* LadderBasedLevel);
	bool STATIC_GetPermissionGroupLevelsByReputation(TEnumAsByte<EGroupType_CodeMap> GroupType, float Reputation, int LadderPosition, float TimePlayed, struct FName* NormalLevel, struct FName* LadderBasedLevel);
	TArray<struct FName> STATIC_GetPermissionGroupLevelsByGroupId(const struct FName& GroupType, bool bIsLadderBased);
	TArray<struct FName> STATIC_GetPermissionGroupLevels(TEnumAsByte<EGroupType_CodeMap> GroupType, bool bIsLadderBased);
	struct FPermissionGroupLevelData STATIC_GetPermissionGroupLevelData(const struct FName& ID);
	struct FName STATIC_GetPermissionGroupLadderBasedLevelByReputationByGroupId(const struct FName& GroupType, float Reputation, int LadderPosition, float TimePlayed);
	struct FName STATIC_GetPermissionGroupLadderBasedLevelByReputation(TEnumAsByte<EGroupType_CodeMap> GroupType, float Reputation, int LadderPosition, float TimePlayed);
	struct FName STATIC_GetPermissionGroupId(TEnumAsByte<EGroupType_CodeMap> GroupType);
	struct FPermissionGroupData STATIC_GetPermissionGroupData(const struct FName& ID);
	struct FPermissionData STATIC_GetPermissionData(const struct FName& ID);
	struct FFactionStrengthEffectData STATIC_GetFactionStrengthEffectData(const struct FName& ID);
	struct FName STATIC_GetFactionReputationEventId(TEnumAsByte<EReputationEvent_CodeMap> Event);
	struct FFactionReputationEventData STATIC_GetFactionReputationEventData(const struct FName& ID);
	void STATIC_GetFactionIdList(TArray<struct FName>* Results);
	bool STATIC_GetFactionDataByIntegerId(int ID, struct FFactionData* Result);
	bool STATIC_GetFactionData(const struct FName& ID, struct FFactionData* Result);
	bool STATIC_DoesLevelGrantPermissionById_OLD(const struct FName& LevelId, const struct FName& PermissionId);
	bool STATIC_DoesLevelGrantPermission_OLD(const struct FName& LevelId, TEnumAsByte<EPermission_CodeMap> permission);
	bool STATIC_CheckPermissionsForPlayer(const struct FStructurePermissions& Permissions, const struct FName& PermissionId, class APlayerCharacter* Player);
	bool STATIC_CheckPermissionsByLevel(const struct FStructurePermissions& Permissions, const struct FName& PermissionGroupLevelId, const struct FName& PermissionId);
};


// Class Otherlands.FactionSpirit
// 0x0018 (0x0040 - 0x0028)
class UFactionSpirit : public UObject
{
public:
	struct FName                                       SpiritId;                                                 // 0x0028(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	int                                                RanksAchieved;                                            // 0x0030(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                RankProgress;                                             // 0x0034(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	class AFaction*                                    Faction;                                                  // 0x0038(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.FactionSpirit");
		return ptr;
	}

};


// Class Otherlands.GameActionBarWidget
// 0x0000 (0x0220 - 0x0220)
class UGameActionBarWidget : public UGameBaseWidget
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameActionBarWidget");
		return ptr;
	}

};


// Class Otherlands.GameAIController
// 0x0058 (0x0490 - 0x0438)
class AGameAIController : public AAIController
{
public:
	class UGameAIPerceptionComponent*                  PerceptionComp;                                           // 0x0438(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0440(0x0010) MISSED OFFSET
	class AAICharacter*                                AICharacter;                                              // 0x0450(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x38];                                      // 0x0458(0x0038) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameAIController");
		return ptr;
	}


	void WakeUp(TEnumAsByte<EAIAwakeState> InAwakeState, bool bForce);
	void SyncAbilityTree();
	bool PickAbility(const struct FName& AbilityId);
	bool IsAwake();
	class UCreatureAbilityComponent* GetCurrentAbility();
	TEnumAsByte<EAIAwakeState> GetAwakeState();
};


// Class Otherlands.GameAIPerceptionComponent
// 0x0010 (0x01D8 - 0x01C8)
class UGameAIPerceptionComponent : public UAIPerceptionComponent
{
public:
	TArray<class UAIPerceptionComponent*>              SharedPerceptionComps;                                    // 0x01C8(0x0010) (ExportObject, ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameAIPerceptionComponent");
		return ptr;
	}

};


// Class Otherlands.GameCharacterMovementComponent
// 0x0180 (0x08F0 - 0x0770)
class UGameCharacterMovementComponent : public UCharacterMovementComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0770(0x0018) MISSED OFFSET
	bool                                               bMovementEasing;                                          // 0x0788(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0789(0x0007) MISSED OFFSET
	class ABasicCharacter*                             BasicCharacter;                                           // 0x0790(0x0008) (ZeroConstructor, IsPlainOldData)
	class APlayerCharacter*                            PlayerCharacter;                                          // 0x0798(0x0008) (ZeroConstructor, IsPlainOldData)
	class AAICharacter*                                AICharacter;                                              // 0x07A0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x30];                                      // 0x07A8(0x0030) MISSED OFFSET
	class AMainGameMode*                               GameMode;                                                 // 0x07D8(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     LastGroundLocation;                                       // 0x07E0(0x000C) (BlueprintVisible, BlueprintReadOnly, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x104];                                     // 0x07EC(0x0104) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameCharacterMovementComponent");
		return ptr;
	}


	void ServerDodge(const struct FVector& Impulse);
	void MulticastDodge(const struct FVector& Impulse);
};


// Class Otherlands.GameCheatManager
// 0x0000 (0x0078 - 0x0078)
class UGameCheatManager : public UCheatManager
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameCheatManager");
		return ptr;
	}

};


// Class Otherlands.GameCredentialsProvider
// 0x00B0 (0x00D8 - 0x0028)
class UGameCredentialsProvider : public UObject
{
public:
	struct FString                                     AuthEndpoint;                                             // 0x0028(0x0010) (ZeroConstructor, Config)
	unsigned char                                      UnknownData00[0xA0];                                      // 0x0038(0x00A0) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameCredentialsProvider");
		return ptr;
	}

};


// Class Otherlands.GameDestructible
// 0x0008 (0x0350 - 0x0348)
class AGameDestructible : public ADestructibleActor
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0348(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameDestructible");
		return ptr;
	}

};


// Class Otherlands.GlobalGameAssets
// 0x01C8 (0x01F0 - 0x0028)
class UGlobalGameAssets : public UObject
{
public:
	class UBehaviorTree*                               DefaultCombatAbilityTree;                                 // 0x0028(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UBehaviorTree*                               DefaultCombatIdleTree;                                    // 0x0030(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PlayerLevelToPvpSpiritCurve;                              // 0x0038(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UMaterialInterface*                          DefaultSpiritMaterial;                                    // 0x0040(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureHealthPerLevelCurve;                              // 0x0048(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureHealthRegenPerLevelCurve;                         // 0x0050(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureSpiritRealmHealthRegenPerLevelCurve;              // 0x0058(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureArmorPerLevelCurve;                               // 0x0060(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureDamagePerLevelCurve;                              // 0x0068(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureSiegeDamagePerLevelCurve;                         // 0x0070(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 TameValuePerLevelCurve;                                   // 0x0078(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 TameValueScalarByRatingCurve;                             // 0x0080(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetCatchUpScalarCurve;                                    // 0x0088(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetXpPerLevelCurve;                                       // 0x0090(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetHealthPerLevelCurve;                                   // 0x0098(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetHealthRegenPerLevelCurve;                              // 0x00A0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetArmorPerLevelCurve;                                    // 0x00A8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetDamagePerLevelCurve;                                   // 0x00B0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetSiegeDamagePerLevelCurve;                              // 0x00B8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PetCarryWeightPerLevelCurve;                              // 0x00C0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 MountMaxStaminaPerLevelCurve;                             // 0x00C8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 MountSprintStaminaDrainRatePerLevelCurve;                 // 0x00D0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 MountStaminaRechargeRatePerLevelCurve;                    // 0x00D8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureLootPerLevelCurve;                                // 0x00E0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 CreatureXPPerLevelCurve;                                  // 0x00E8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveStrengthByDayCurve;                                   // 0x00F0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DefaultPveArmorCurve;                                     // 0x00F8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DefaultPveResistCurve;                                    // 0x0100(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DefaultPvpArmorCurve;                                     // 0x0108(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DefaultPvpResistCurve;                                    // 0x0110(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 BountySpiritScalarCurve;                                  // 0x0118(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 BountyRepEventScalarCurve;                                // 0x0120(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 BountyClaimCountToValueCurve;                             // 0x0128(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PvpXpLevelCurve;                                          // 0x0130(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 BountyXpScalarCurve;                                      // 0x0138(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PvpKillCountXpScalarCurve;                                // 0x0140(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PvpKillCountRepScalarCurve;                               // 0x0148(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelByStrengthCurve;                                 // 0x0150(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelOffsetByAvgPopCurve;                             // 0x0158(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelOffsetByAvgScoreCurve;                           // 0x0160(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelOffsetByTechCurve;                               // 0x0168(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelOffsetByTechDeltaCurve;                          // 0x0170(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelOffsetByPopDeltaCurve;                           // 0x0178(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelOffsetByScoreDeltaCurve;                         // 0x0180(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 WaveLevelOffsetByMaxLossCurve;                            // 0x0188(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 RepeatedJumpHeightReductionCurve;                         // 0x0190(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 RepeatedJumpSpeedReductionCurve;                          // 0x0198(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DepositSpiritFXTimeCurve;                                 // 0x01A0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DepositSpiritFXInterpCurve;                               // 0x01A8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class USoundCue*                                   DepositSpiritFXSound;                                     // 0x01B0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class USoundCue*                                   UICreatureSound_Aware;                                    // 0x01B8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class USoundCue*                                   UICreatureSound_Agro;                                     // 0x01C0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 SprintLoopSoundVolumeCurve;                               // 0x01C8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 SprintCameraCurve;                                        // 0x01D0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UParticleSystem*                             SprintParticles;                                          // 0x01D8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 NoiseAtteunationFalloffCurve;                             // 0x01E0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 NoiseAtteunationSphereExtentCurve;                        // 0x01E8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GlobalGameAssets");
		return ptr;
	}

};


// Class Otherlands.GameGlobalSettings
// 0x0728 (0x0760 - 0x0038)
class UGameGlobalSettings : public UDeveloperSettings
{
public:
	struct FString                                     PersistentSaveName;                                       // 0x0038(0x0010) (Edit, ZeroConstructor, Config)
	struct FName                                       ReckoningZoneId;                                          // 0x0048(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       SpiritZoneId;                                             // 0x0050(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       DefaultWeatherId;                                         // 0x0058(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       SpiritRealmWeatherId;                                     // 0x0060(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       WinningWeatherId[0x3];                                    // 0x0068(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       DamageWisp1Id;                                            // 0x0080(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       DamageWisp5Id;                                            // 0x0088(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       DamageWisp20Id;                                           // 0x0090(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       DamageWisp100Id;                                          // 0x0098(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       DroppedItemsContainerId;                                  // 0x00A0(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       ConstructionHammerId;                                     // 0x00A8(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       DefaultSleeperPlaceableItemId;                            // 0x00B0(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       MaterialSwapIdBaseDestruction;                            // 0x00B8(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       MaterialSwapIdSpirit;                                     // 0x00C0(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       MaterialSwapIdDepthMesh;                                  // 0x00C8(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       MaterialSwapIdFactionRune[0x3];                           // 0x00D0(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FSoftObjectPath                             DefaultSpiritMaterial;                                    // 0x00E8(0x0018) (Edit, Config)
	struct FName                                       ItemImpactEffectKitIdFootStep;                            // 0x0100(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       ItemImpactEffectKitIdJumpLand;                            // 0x0108(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	float                                              JumpLandVolumeScale;                                      // 0x0110(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0114(0x0004) MISSED OFFSET
	struct FName                                       ArchtypeBuffIds[0x4];                                     // 0x0118(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       SpiritRealmBuffId;                                        // 0x0138(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       RespawnInvulBuffId;                                       // 0x0140(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       ReckoningBaseBuffId;                                      // 0x0148(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FName                                       AiEvadeBuffId;                                            // 0x0150(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FSoftObjectPath                             DefaultCombatAbilityTree;                                 // 0x0158(0x0018) (Edit, Config)
	struct FSoftObjectPath                             DefaultCombatIdleTree;                                    // 0x0170(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PlayerLevelToPvpSpiritCurve;                              // 0x0188(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureHealthPerLevelCurve;                              // 0x01A0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureHealthRegenPerLevelCurve;                         // 0x01B8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureSpiritRealmHealthRegenPerLevelCurve;              // 0x01D0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureArmorPerLevelCurve;                               // 0x01E8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureDamagePerLevelCurve;                              // 0x0200(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureSiegeDamagePerLevelCurve;                         // 0x0218(0x0018) (Edit, Config)
	struct FSoftObjectPath                             TameValuePerLevelCurve;                                   // 0x0230(0x0018) (Edit, Config)
	struct FSoftObjectPath                             TameValueScalarByRatingCurve;                             // 0x0248(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureLootPerLevelCurve;                                // 0x0260(0x0018) (Edit, Config)
	struct FSoftObjectPath                             CreatureXPPerLevelCurve;                                  // 0x0278(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetCatchUpScalarCurve;                                    // 0x0290(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetXpPerLevelCurve;                                       // 0x02A8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetHealthPerLevelCurve;                                   // 0x02C0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetHealthRegenPerLevelCurve;                              // 0x02D8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetArmorPerLevelCurve;                                    // 0x02F0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetDamagePerLevelCurve;                                   // 0x0308(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetSiegeDamagePerLevelCurve;                              // 0x0320(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PetCarryWeightPerLevelCurve;                              // 0x0338(0x0018) (Edit, Config)
	struct FSoftObjectPath                             MountMaxStaminaPerLevelCurve;                             // 0x0350(0x0018) (Edit, Config)
	struct FSoftObjectPath                             MountSprintStaminaDrainRatePerLevelCurve;                 // 0x0368(0x0018) (Edit, Config)
	struct FSoftObjectPath                             MountStaminaRechargeRatePerLevelCurve;                    // 0x0380(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveStrengthByDayCurve;                                   // 0x0398(0x0018) (Edit, Config)
	struct FSoftObjectPath                             DefaultPveArmorCurve;                                     // 0x03B0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             DefaultPveResistCurve;                                    // 0x03C8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             DefaultPvpArmorCurve;                                     // 0x03E0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             DefaultPvpResistCurve;                                    // 0x03F8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             RepeatedJumpHeightReductionCurve;                         // 0x0410(0x0018) (Edit, Config)
	struct FSoftObjectPath                             RepeatedJumpSpeedReductionCurve;                          // 0x0428(0x0018) (Edit, Config)
	struct FName                                       DepositSpiritWeatherId[0x3];                              // 0x0440(0x0008) (Edit, ZeroConstructor, Config, IsPlainOldData)
	struct FSoftObjectPath                             DepositSpiritFXTimeCurve;                                 // 0x0458(0x0018) (Edit, Config)
	struct FSoftObjectPath                             DepositSpiritFXInterpCurve;                               // 0x0470(0x0018) (Edit, Config)
	struct FSoftObjectPath                             DepositSpiritFXSound;                                     // 0x0488(0x0018) (Edit, Config)
	struct FSoftObjectPath                             BountySpiritScalarCurve;                                  // 0x04A0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             BountyRepEventScalarCurve;                                // 0x04B8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             BountyClaimCountToValueCurve;                             // 0x04D0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PvpXpLevelCurve;                                          // 0x04E8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             BountyXpScalarCurve;                                      // 0x0500(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PvpKillCountXpScalarCurve;                                // 0x0518(0x0018) (Edit, Config)
	struct FSoftObjectPath                             PvpKillCountRepScalarCurve;                               // 0x0530(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelByStrengthCurve;                                 // 0x0548(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelOffsetByAvgPopCurve;                             // 0x0560(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelOffsetByAvgScoreCurve;                           // 0x0578(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelOffsetByTechCurve;                               // 0x0590(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelOffsetByTechDeltaCurve;                          // 0x05A8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelOffsetByPopDeltaCurve;                           // 0x05C0(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelOffsetByScoreDeltaCurve;                         // 0x05D8(0x0018) (Edit, Config)
	struct FSoftObjectPath                             WaveLevelOffsetByMaxLossCurve;                            // 0x05F0(0x0018) (Edit, Config)
	float                                              AfkTimeout;                                               // 0x0608(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bEnableVoice;                                             // 0x060C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x060D(0x0003) MISSED OFFSET
	float                                              LadderActivePlayerThresholdInDays;                        // 0x0610(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                ClassPerkVersion;                                         // 0x0614(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                SkillPerkVersion;                                         // 0x0618(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              XpPerSoul;                                                // 0x061C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              SpiritsForVictory;                                        // 0x0620(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              SpiritsForPylonExpansion;                                 // 0x0624(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PveMitigationFormulaConstant;                             // 0x0628(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PvpMitigationFormulaConstant;                             // 0x062C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              SiegeToUnitMultiplier;                                    // 0x0630(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              UnitToSiegeObstructuionMultiplier;                        // 0x0634(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              UnitToResourceObstructuionMultiplier;                     // 0x0638(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              CharacterMaxEncumbranceScalar;                            // 0x063C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PlayerRootViewAngle;                                      // 0x0640(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              GlobalDamageVariance;                                     // 0x0644(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	TArray<struct FFactionScoreDisplay>                FactionScoreDisplays;                                     // 0x0648(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FFactionBaseWispSettings                    FactionBaseWispSettings;                                  // 0x0658(0x0020) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FTimespan                                   GameEndDelay;                                             // 0x0678(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	TArray<struct FTimespan>                           GameEndNotifyRate;                                        // 0x0680(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FTimespan                                   GameEndCountdown;                                         // 0x0690(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	int                                                DefaultStashSize;                                         // 0x0698(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                MaxStashSize;                                             // 0x069C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                DefaultCollectionSize;                                    // 0x06A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                MaxCollectionSize;                                        // 0x06A4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                MaxFactionMotd;                                           // 0x06A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                MaxFactionMemo;                                           // 0x06AC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	struct FSoftObjectPath                             UICreatureSound_Aware;                                    // 0x06B0(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FSoftObjectPath                             UICreatureSound_Agro;                                     // 0x06C8(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FSoftObjectPath                             SprintLoopSoundVolumeCurve;                               // 0x06E0(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FSoftObjectPath                             SprintCameraCurve;                                        // 0x06F8(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	float                                              SprintFootstepVolumeScale;                                // 0x0710(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0714(0x0004) MISSED OFFSET
	struct FSoftObjectPath                             SprintParticles;                                          // 0x0718(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FSoftObjectPath                             NoiseAtteunationFalloffCurve;                             // 0x0730(0x0018) (Edit, Config)
	struct FSoftObjectPath                             NoiseAtteunationSphereExtentCurve;                        // 0x0748(0x0018) (Edit, Config)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameGlobalSettings");
		return ptr;
	}


	class UGlobalGameAssets* STATIC_GetAssets();
};


// Class Otherlands.GameHUD
// 0x00B0 (0x04C8 - 0x0418)
class AGameHUD : public AHUD
{
public:
	bool                                               bRespawnWidgetActivated;                                  // 0x0418(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsMouseLookModeEnabled;                                  // 0x0419(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsRadialMenuOpened;                                      // 0x041A(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bContextMenuActivated;                                    // 0x041B(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bConfirmBoxActivated;                                     // 0x041C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bChatEnabled;                                             // 0x041D(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bEscapeMenuEnabled;                                       // 0x041E(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsUIEnabled;                                             // 0x041F(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bShowHotkeyLegend;                                        // 0x0420(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bWindowHasFocus;                                          // 0x0421(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETechTreeType>                         SavedTechTreeType;                                        // 0x0422(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x0423(0x0005) MISSED OFFSET
	class UWidget*                                     AmmoPanelWidget;                                          // 0x0428(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UTextBlock*                                  ActiveItemCountTextWidget;                                // 0x0430(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UTextBlock*                                  ActiveItemClipCountTextWidget;                            // 0x0438(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<class USpellDisplayWidget*>                 SpellSlots;                                               // 0x0440(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	class UClass*                                      GameHUDWidgetClass;                                       // 0x0450(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UGameHUDWidget*                              GameHUDWidget;                                            // 0x0458(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UChatWidget*                                 ChatWidget;                                               // 0x0460(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBuffWidget*                                 BuffWidget;                                               // 0x0468(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UConfirmWidget*                              ConfirmWidget;                                            // 0x0470(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UContextMenuWidget*                          ContextMenuWidget;                                        // 0x0478(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkillTickerWidget*                          SkillTickerWidget;                                        // 0x0480(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UNameplateWidget*                            TargetNameplateWidget;                                    // 0x0488(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UToolTipWidget*                              StructureTooltipWidget;                                   // 0x0490(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UCrosshairWidget*                            CrosshairWidget;                                          // 0x0498(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UTutorialWidget*                             TutorialWidget;                                           // 0x04A0(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UHudMenuWidget*                              HudMenuWidget;                                            // 0x04A8(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       ClientActiveAmmoId;                                       // 0x04B0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EStructureType>                        ClientStructureType;                                      // 0x04B8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EPlaceableMaterial>                    ClientMaterialChosen;                                     // 0x04B9(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xE];                                       // 0x04BA(0x000E) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameHUD");
		return ptr;
	}


	void UpdateSpellSlots();
	void UpdateBuffs();
	void UnFocusChatInputBox();
	void TogglePlayerUI();
	void ToggleHotkeyLegend();
	void ShowConfirmBox();
	void OnUpdateWindowFocus(bool bHasFocus);
	void OnOutcastVoteStarted(const struct FString& PlayerName, const struct FString& CharacterId);
	void OnOutcastVoteFinished(const struct FString& PlayerName, const struct FString& CharacterId, TEnumAsByte<EOutcastResult> Result);
	void OnInitiateOutcastVoteResult(const struct FString& PlayerName, const struct FString& CharacterId, TEnumAsByte<EVoteResult> VoteResult);
	void OnInitiateDemolishVoteResult(TEnumAsByte<EVoteResult> VoteResult);
	void OnDemolishVoteStarted(const struct FString& PlayerName, const struct FString& CharacterId, int RequestedCount);
	void OnDemolishVoteFinished(const struct FString& PlayerName, const struct FString& CharacterId, TEnumAsByte<EDemolishResult> Result);
	void OnCastOutcastVoteResult(const struct FString& PlayerName, const struct FString& CharacterId, TEnumAsByte<EVoteResult> VoteResult);
	void OnCastDemolishVoteResult(const struct FString& PlayerName, const struct FString& CharacterId, TEnumAsByte<EVoteResult> VoteResult);
	void LootTicker(const struct FName& ItemId, int Count);
	void IssueStatWarning(const struct FText& Text);
	void HideConfirmBox();
	void FocusChatInputBox(bool bWithSlash);
	void ExitWeaponRadialMenu();
	void ExitToolRadialMenu();
	void ExitPetCommandRadialMenu();
	void ExitInteractRadialMenu();
	void ExitEmoteRadialMenu();
	void ExitBuildingModeRadial();
	void ExitAmmoRadialMenu();
	void EnterWeaponRadialMenu();
	void EnterToolRadialMenu();
	void EnterPetCommandRadialMenu();
	void EnterInteractRadialMenu();
	void EnterEmoteRadialMenu();
	void EnterBuildingModeRadial();
	void EnterAmmoRadialMenu();
	void DeActivateScaffolding();
	void CallUnFocusChatInputBox();
};


// Class Otherlands.GameHUDWidget
// 0x0060 (0x0280 - 0x0220)
class UGameHUDWidget : public UGameBaseWidget
{
public:
	float                                              CurHealth;                                                // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxHealth;                                                // 0x0224(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CurStamina;                                               // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxStamina;                                               // 0x022C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CurFood;                                                  // 0x0230(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxFood;                                                  // 0x0234(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CurWater;                                                 // 0x0238(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxWater;                                                 // 0x023C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CurWeight;                                                // 0x0240(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxWeight;                                                // 0x0244(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              XPPercentage;                                             // 0x0248(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TempBarValue;                                             // 0x024C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TempRange;                                                // 0x0250(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CurNoise;                                                 // 0x0254(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxNoise;                                                 // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ClipPercentage;                                           // 0x025C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              RadialProgress;                                           // 0x0260(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   RadialVisibility;                                         // 0x0264(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   ClipBarVisibility;                                        // 0x0265(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   InteractTextVisibility;                                   // 0x0266(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0267(0x0001) MISSED OFFSET
	struct FText                                       InteractText;                                             // 0x0268(0x0018) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameHUDWidget");
		return ptr;
	}


	void OnUpdateXPHud(float Amount);
	void OnUpdateStatHud(TEnumAsByte<ECharacterStat> Stat, float Threshold);
	void OnTemperatureUpdated(float Temp);
	void NotifyDyingIndicator(TEnumAsByte<ENotifyDeathType> NotifyDeath);
};


// Class Otherlands.GameInstancedStaticMesh
// 0x0000 (0x0690 - 0x0690)
class UGameInstancedStaticMesh : public UInstancedStaticMeshComponent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameInstancedStaticMesh");
		return ptr;
	}


	void OnConstruction();
};


// Class Otherlands.GameOptions
// 0x0028 (0x0050 - 0x0028)
class UGameOptions : public UObject
{
public:
	bool                                               EnhancedCrosshairs;                                       // 0x0028(0x0001) (Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData)
	bool                                               HideHelmet;                                               // 0x0029(0x0001) (Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData)
	bool                                               CameraShake;                                              // 0x002A(0x0001) (Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x002B(0x0001) MISSED OFFSET
	float                                              FriendlyHUDOpacity;                                       // 0x002C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, Config, IsPlainOldData)
	TArray<struct FHighlightsOptions>                  Highlights;                                               // 0x0030(0x0010) (Edit, BlueprintVisible, ZeroConstructor, Config)
	struct FScriptMulticastDelegate                    OnGameOptionsChanged;                                     // 0x0040(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameOptions");
		return ptr;
	}


	void SaveConfig();
};


// Class Otherlands.GamePlayerController
// 0x0478 (0x0AF0 - 0x0678)
class AGamePlayerController : public APlayerController
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0678(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnRefreshDeathEvent;                                      // 0x0680(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnRespawnEvent;                                           // 0x0690(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDoDamageEvent;                                          // 0x06A0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTakeDamageEvent;                                        // 0x06B0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnRespawnRequested;                                       // 0x06C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCharacterAddSkillTickerSlot;                            // 0x06D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCharacterTalentsChanged;                                // 0x06E0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCharacterSkillChanged;                                  // 0x06F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCharacterPerkSetsChanged;                               // 0x0700(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptDelegate                             OnItemContext;                                            // 0x0710(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnShowTooltip;                                            // 0x0720(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnHideTooltip;                                            // 0x0730(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnGetTooltipWidget;                                       // 0x0740(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnGetRightClickMenuWidget;                                // 0x0750(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	bool                                               bUIInputModeEnabled;                                      // 0x0760(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x57];                                      // 0x0761(0x0057) MISSED OFFSET
	TArray<struct FResourceSpawnStateHandle>           ClientResourcesToSync;                                    // 0x07B8(0x0010) (ZeroConstructor)
	TArray<struct FResourceSpawnStateHandle>           ServerResourcesToSync;                                    // 0x07C8(0x0010) (ZeroConstructor)
	TArray<struct FResourceSpawnStateHandle>           ClientResourcesToAck;                                     // 0x07D8(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData02[0x38];                                      // 0x07E8(0x0038) MISSED OFFSET
	class ABasicCharacter*                             BasicCharacter;                                           // 0x0820(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class APlayerCharacter*                            PlayerCharacter;                                          // 0x0828(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FString                                     AuthId;                                                   // 0x0830(0x0010) (Net, ZeroConstructor)
	bool                                               bPlayerCheatsAllowed;                                     // 0x0840(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0841(0x0007) MISSED OFFSET
	struct FName                                       CurrentWorldMapId;                                        // 0x0848(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x8];                                       // 0x0850(0x0008) MISSED OFFSET
	TArray<class UUIEventHandler*>                     EventHandlerStack;                                        // 0x0858(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData05[0x38];                                      // 0x0868(0x0038) MISSED OFFSET
	class UClass*                                      AIClass;                                                  // 0x08A0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UBehaviorTree*                               AIBehavior;                                               // 0x08A8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UClass*                                      ResourceClass;                                            // 0x08B0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x8];                                       // 0x08B8(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnInteractionStart;                                       // 0x08C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInteractionEnd;                                         // 0x08D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnFactionMembersLoaded;                                   // 0x08E0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanMembersLoaded;                                      // 0x08F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanInvitesLoaded;                                      // 0x0900(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanInviteAccepted;                                     // 0x0910(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanInviteRejected;                                     // 0x0920(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanPlayerInvited;                                      // 0x0930(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanInviteRescinded;                                    // 0x0940(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanPlayerPromoted;                                     // 0x0950(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanPlayerDemoted;                                      // 0x0960(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanPlayerKicked;                                       // 0x0970(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanLeft;                                               // 0x0980(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanJoined;                                             // 0x0990(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanCreated;                                            // 0x09A0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupInvitesLoaded;                                     // 0x09B0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupInviteAccepted;                                    // 0x09C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupInviteRejected;                                    // 0x09D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupPlayerInvited;                                     // 0x09E0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupInviteRescinded;                                   // 0x09F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupRequestsLoaded;                                    // 0x0A00(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupRequestToJoinAccepted;                             // 0x0A10(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupRequestToJoinRejected;                             // 0x0A20(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupPlayerRequested;                                   // 0x0A30(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupPlayerPromoted;                                    // 0x0A40(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupPlayerKicked;                                      // 0x0A50(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupLeft;                                              // 0x0A60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupJoined;                                            // 0x0A70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupCreated;                                           // 0x0A80(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnWorldMapEntered;                                        // 0x0A90(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TWeakObjectPtr<class UObject>                      CurrentInteraction;                                       // 0x0AA0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UGameCheatCommandComponent*                  CheatComponent;                                           // 0x0AA8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UGameAdminCommandComponent*                  AdminComponent;                                           // 0x0AB0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USlashCommandComponent*                      CommandComponent;                                         // 0x0AB8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData07[0x30];                                      // 0x0AC0(0x0030) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GamePlayerController");
		return ptr;
	}


	void WarehouseDeposit(const struct FName& ItemId, int ItemCount);
	void SystemMessageReceived(const struct FChatSystemMessage& SystemMessage, TEnumAsByte<EChatChannelType> ChatChannelType);
	void SwitchPlaceableVariant();
	void StartRadialTimer(TEnumAsByte<ERadialMenuType> MenuType, bool bImmediate);
	void SpectatorTurnSpeed(float Speed);
	void SpectatorTurnAcceleration(float Accel);
	void SpectatorTimeStep(float Time);
	void SpectatorTargetSpline(const struct FString& Name);
	void SpectatorSplineTimeMode(TEnumAsByte<ESplineTimeMode> SplineTimeMode);
	void SpectatorMoveSpeed(float Speed);
	void SpectatorMoveAcceleration(float Accel);
	void SpectatorLockOnTargetBone(const struct FName& BoneName);
	void SpectatorFollowSpeed(float Min, float Max, float MaxDist);
	void SpectatorCyclePlayerTargetBone(const struct FName& BoneName);
	void SpectatorCollideTerrain(bool State);
	void SpectatorCameraSpline(const struct FString& Name);
	void ShowTooltip(class UUserWidget* InAnchorWidget);
	void SetPet(int Index);
	bool SetNewSoundClassVolume(class USoundClass* TargetClass, float NewVolume);
	void SetIsInRebindKeysMode(bool bSet);
	void SetInteractionTarget(class UObject* Target, const struct FName& Action, bool bBroadcast);
	void ServerTestCheat();
	void ServerStuckRequest();
	void ServerSendFactionBroadcast(const struct FText& Message);
	void ServerSendChatMessage(const struct FText& Input, TEnumAsByte<EChatChannelType> ChatChannelType, const struct FString& ChatTarget);
	void ServerRequestResourceSync(TArray<struct FResourceSpawnStateHandle> StateHandles, bool bForceDelay);
	void ServerRequestLogout();
	void ServerRequestCharacterNameForSaveId(const struct FString& SaveId);
	void ServerReportPlayerById(const struct FString& CharacterId, TEnumAsByte<EPlayerReportReason> Reason, const struct FString& Desc);
	void ServerReportPlayer(const struct FString& PlayerName, TEnumAsByte<EPlayerReportReason> Reason, const struct FString& Desc);
	void ServerGroupRescindInvitation(const struct FGroupMemberData& InPlayer);
	void ServerGroupRequestToJoinPlayerByCharacter(class APlayerCharacter* InPlayer);
	void ServerGroupRequestToJoinPlayer(const struct FString& PlayerName);
	void ServerGroupRejectRequestToJoin(const struct FGroupMemberData& InPlayer);
	void ServerGroupReject(const struct FGroupMemberData& InPlayer);
	void ServerGroupPromotePlayerByCharacter(class APlayerCharacter* InPlayer);
	void ServerGroupPromotePlayer(const struct FString& PlayerName);
	void ServerGroupLeave();
	void ServerGroupKick(const struct FString& PlayerName);
	void ServerGroupInvitePlayerByCharacter(class APlayerCharacter* InPlayer);
	void ServerGroupInvitePlayer(const struct FString& PlayerName);
	void ServerGroupAcceptRequestToJoin(const struct FGroupMemberData& InPlayer);
	void ServerGroupAccept(const struct FGroupMemberData& InPlayer);
	void ServerGetGroupRequests();
	void ServerGetGroupInvites();
	void ServerGetFactionMembers(bool bIncludeOffline);
	void ServerGetClanMembers();
	void ServerGetClanInvites();
	void ServerFailedResourceSync(const struct FString& Reason, TArray<struct FResourceSyncPacket> SanatizedPackets);
	void ServerDoEmote(const struct FName& EmoteId);
	void ServerClanRescindInvitation(const struct FString& CharacterId);
	void ServerClanReject(const struct FString& ClanId);
	void ServerClanPromotePlayer(const struct FString& PlayerName);
	void ServerClanLeave();
	void ServerClanKick(const struct FString& PlayerName);
	void ServerClanInvitePlayerByCharacter(class APlayerCharacter* InPlayer);
	void ServerClanInvitePlayer(const struct FString& PlayerName);
	void ServerClanDemotePlayer(const struct FString& PlayerName);
	void ServerClanCreate(const struct FString& ClanName);
	void ServerClanAccept(const struct FString& ClanId);
	void ServerCheatWipeStructures();
	void ServerCheatUpgradePlaceable();
	void ServerCheatUnlockSpirit(const struct FName& SpiritId);
	void ServerCheatToggleShields();
	void ServerCheatToggleLargeBase();
	void ServerCheatToggleGender();
	void ServerCheatSuicide();
	void ServerCheatStealStationXP(class UInteractiveMeshComponent* MeshComp, const struct FName& SkillTree);
	void ServerCheatSpawnWaveEvent(const struct FName& SpawnEventId);
	void ServerCheatSpawnSpiritPortal(float Scale);
	void ServerCheatSpawnSpiritEvent(const struct FName& SpiritEventId);
	void ServerCheatSpawnSouls(float SoulsToSpawn);
	void ServerCheatSpawnGroup(const struct FName& SpawnGroupId);
	void ServerCheatSpawnEvent(const struct FName& SpawnEventId);
	void ServerCheatSpawnCreature(const struct FName& CreatureId, int CreatureLevel, bool bSpiritRealm, bool bFriendly);
	void ServerCheatSetWeather(const struct FName& WeatherId, float LerpTime);
	void ServerCheatSetTimeOfDay(float TimeOfDay);
	void ServerCheatSetStructureHealthScalar(float Val);
	void ServerCheatSetStructureArmorScalar(float Val);
	void ServerCheatSetStationStealState(class UInteractiveMeshComponent* MeshComp, float InStoredXP);
	void ServerCheatSetStat(TEnumAsByte<ECharacterStat> Stat, float Value);
	void ServerCheatSetSpiritMode(bool bSet);
	void ServerCheatSetSkinColor(const struct FName& SkinColorId);
	void ServerCheatSetSkillTreeSkilled(const struct FName& RecipeId);
	void ServerCheatSetSkillTreeMastered(const struct FName& RecipeId);
	void ServerCheatSetSkillLevel(const struct FName& SkillId, int Level);
	void ServerCheatSetServerAge(float Days);
	void ServerCheatSetSeason(TEnumAsByte<ESeason> InSeason);
	void ServerCheatSetRepLevel(const struct FName& Normal, const struct FName& LadderBased);
	void ServerCheatSetReckoningTimeMultiplier(float Val);
	void ServerCheatSetPetFollow(TEnumAsByte<EAIPetFollow> NewFollow);
	void ServerCheatSetLevel(int Level);
	void ServerCheatSetItemMod(int ItemToModSlotIndex, TEnumAsByte<EItemSlotType> ItemToModType, int ModItemSlotIndex, TEnumAsByte<EItemSlotType> ModifierItemType);
	void ServerCheatSetHeldItemMod(const struct FName& ModItemId);
	void ServerCheatSetHarvestMultiplier(float Val);
	void ServerCheatSetHairColor(const struct FName& HairColorId);
	void ServerCheatSetHair(const struct FName& HairId);
	void ServerCheatSetGodMode(bool bSet, bool bMass);
	void ServerCheatSetFaction(int FactionId);
	void ServerCheatSetFacialHair(const struct FName& FacialHairId);
	void ServerCheatSetEncumbranceMultiplier(float Val);
	void ServerCheatSetDayLength(float DayLength);
	void ServerCheatSetCreatureLevelScalar(float Val);
	void ServerCheatSetCreativeMode(bool Val);
	void ServerCheatSetCraftSpeedMultiplier(float Val);
	void ServerCheatSetBeastMaster(bool bSet, bool bMass);
	void ServerCheatScaleStat(TEnumAsByte<ECharacterStat> Stat, float Scalar);
	void ServerCheatSalvageItem(const struct FName& ItemId, int ItemCount);
	void ServerCheatRespawn();
	void ServerCheatResetTechTree(TEnumAsByte<ETechTreeType> TechTree);
	void ServerCheatResetTalentArchetypes();
	void ServerCheatResetEntropy(bool bResetEntropyLootScore, bool bResetEntropyLootRewardCount);
	void ServerCheatResetDemolishState();
	void ServerCheatResetAllSkillTrees();
	void ServerCheatResetAllSkills();
	void ServerCheatResetAllPerkPoints();
	void ServerCheatRenamePlaceable(const struct FString& NewName);
	void ServerCheatRefreshPlaceable();
	void ServerCheatReckoning(const struct FName& SpawnEventId, int FactionId);
	void ServerCheatProfileStart();
	void ServerCheatPortToStart(bool bSkipAllow);
	void ServerCheatPortLoc(const struct FVector& Loc);
	void ServerCheatPort(const struct FString& Target, bool bSkipAuth);
	void ServerCheatOutcastMe();
	void ServerCheatModifyStat(TEnumAsByte<ECharacterStat> Stat, float Delta);
	void ServerCheatMassSummon();
	void ServerCheatMassPort(const struct FString& Target);
	void ServerCheatGetStationStealState(class UInteractiveMeshComponent* MeshComp);
	void ServerCheatGetSkillTreeWhole(const struct FName& SkillTreeId);
	void ServerCheatGetSkillTreeState(const struct FName& RecipeId);
	void ServerCheatGetAscensionState();
	void ServerCheatForceSave();
	void ServerCheatForceMatchEnd();
	void ServerCheatForceEntropyPayout();
	void ServerCheatFactionVictory(int FactionId);
	void ServerCheatEndReckoning();
	void ServerCheatEndAllEvents();
	void ServerCheatDropCapturePointShields(int Count);
	void ServerCheatDisableGlobalSpawns(bool bSet);
	void ServerCheatDestroyFaction(int FactionId);
	void ServerCheatDespawnCreature(class AAICharacter* Target, bool bDestroy);
	void ServerCheatCreateLoot(const struct FName& LootBaseId, int Count, TEnumAsByte<EHarvestType> HarvestType, int QualityThreshold, bool bSkipAllow);
	void ServerCheatCreateItem(const struct FName& ItemId, int ItemCount, bool bSkipAllow);
	void ServerCheatClearSpellCooldowns();
	void ServerCheatClearInventory(bool bClearAll);
	void ServerCheatClearDeathCount();
	void ServerCheatClearCollection();
	void ServerCheatClearBounty(bool bIncludeKillRecord);
	void ServerCheatCheckEntropyScore();
	void ServerCheatAddToCollection(const struct FName& InCreatureBaseId, int InVariantIndex, float InRating, bool bSkipAllow);
	void ServerCheatAddSpell(const struct FName& SpellId);
	void ServerCheatAddSkillXP(const struct FName& SkillId, float XP);
	void ServerCheatAddSkillTreeXP(const struct FName& RecipeId, float XP);
	void ServerCheatAddReputation(float Delta);
	void ServerCheatAddFactionUseScore(float Delta);
	void ServerCheatAddFactionSouls(int FactionId, float SoulsToAdd);
	void ServerCheatAddEntropy(float Delta, bool CanPayout);
	void ServerCheatAddBuff(const struct FName& BuffId);
	void ServerCheatAddBounty(float Delta);
	void ServerCheatAddAscensionPoints(int Count);
	void ServerAdminUnbanPlayer(const struct FString& PlayerName);
	void ServerAdminTrainJrkStats();
	void ServerAdminStartTimedMultiplier(float Multiplier, float Hours);
	void ServerAdminReportJrks(float Percent, int TopX);
	void ServerAdminReportingPlayerList();
	void ServerAdminReportedPlayerList();
	void ServerAdminPlayerReportsFromList(const struct FString& PlayerName);
	void ServerAdminPlayerReportsForList(const struct FString& PlayerName);
	void ServerAdminOutcast(const struct FString& PlayerName, bool bSet);
	void ServerAdminJrkStats();
	void ServerAdminIsJrk(const struct FString& PlayerName);
	void ServerAdminClearPlayerReportsFrom(const struct FString& PlayerName);
	void ServerAdminClearPlayerReportsFor(const struct FString& PlayerName);
	void ServerAdminBanPlayer(const struct FString& PlayerName, const struct FString& Message, int Hours, bool bAccount);
	void ServerAdminBanList();
	void RestoreMouse();
	void RequestRespawn();
	void RequestMouse();
	void RequestLogout();
	void ReportPlayerById(const struct FString& CharacterId, TEnumAsByte<EPlayerReportReason> Reason, const struct FString& Message);
	void RemoveUIEventHandler(class UUIEventHandler* EventHandler);
	void ReleaseMouse();
	void QueueRequestResourceSync(const struct FResourceSpawnStateHandle& StateHandle);
	bool ProcessUIEvent(const struct FName& EventName, bool bPressed, float AxisValue, bool bIsGameInput);
	bool ParseServerSlashCommand(const struct FString& Input);
	bool ParseClientSlashCommand(const struct FString& Input, const struct FString& NewTempAuthId);
	void OnRep_CurrentWorldMapId();
	void OnMouseModeChanged(bool bMouseMode);
	void OnEnterUIMode();
	void ItemContext(class UInventoryComponent* InInventoryComponent, int InInventorySlot, class UUserWidget* InAnchorWidget);
	bool IsGameInputEnabled();
	void HoldItem(TEnumAsByte<EHeldItemLocation> Location);
	void HideTooltip(class UUserWidget* InAnchorWidget);
	void HideMouse();
	void GroupRequestToJoinReceived(const struct FGroupMemberData& GroupData);
	void GroupInviteReceived(const struct FGroupMemberData& GroupData);
	struct FString GetUniqueSaveId(bool bPrint);
	struct FString GetUniqueCharacterId();
	class UUserWidget* GetTooltipWidget();
	class UUserWidget* GetRightClickMenuWidget();
	struct FVector GetRadialSurfaceTargetLocation();
	class ABasicCharacter* GetRadialCharacterTarget();
	void GetKeysForInputAction(const struct FName& InActionName, TArray<struct FInputActionKeyMapping>* OutKeys);
	class UCraftComponent* GetInteractOrPlayerCraftComponent();
	class UCraftComponent* GetInteractCraftComponent();
	TScriptInterface<class UInteractiveInterface> GetCurrentInteraction();
	struct FVector GetAimStartLocation();
	bool ExitRadialMenu();
	void EventLogReceived(const struct FEventLogEntry& EventLog);
	void DepositResourcesIntoWarehouse(const struct FName& ItemId, int ItemCount);
	void CycleWeaponSlot();
	void CycleHarvestRune();
	void ClientResponseCharacterNameForSaveId(const struct FString& SaveId, const struct FString& Name);
	void ClientResourceSync(TArray<struct FResourceSyncPacket> Packets);
	void ClientReportPlayerResult(bool bSuccess, const struct FString& PlayerName, TArray<struct FString> CollisionResults);
	void ClientReceiveSystemMessage(const struct FChatSystemMessage& SystemMessage, TEnumAsByte<EChatChannelType> ChatChannelType);
	void ClientReceiveEventLog(const struct FEventLogEntry& EventLog);
	void ClientReceiveEmoteMessage(const struct FText& EmoteMessage);
	void ClientReceiveChatMessage(const struct FText& SourceName, const struct FText& ChatMessage, int SourceFactionId, TEnumAsByte<EChatChannelType> ChatChannelType);
	void ClientPlayerKicked(const struct FText& KickReason);
	void ClientNotifyWeaponModSuccessful();
	void ClientGroupRequestToJoinRejected(EGroupOpResult Result);
	void ClientGroupRequestToJoinAccepted(EGroupOpResult Result);
	void ClientGroupRequestToJoin(const struct FGroupMemberData& InPlayer);
	void ClientGroupRequestsLoaded(TArray<struct FGroupMemberData> Members);
	void ClientGroupPlayerRequested(EGroupOpResult Result);
	void ClientGroupPlayerPromoted(EGroupOpResult Result);
	void ClientGroupPlayerKicked(EGroupOpResult Result);
	void ClientGroupPlayerInvited(EGroupOpResult Result);
	void ClientGroupLeft(EGroupOpResult Result);
	void ClientGroupInvitesLoaded(TArray<struct FGroupMemberData> Members);
	void ClientGroupInviteRescinded(EGroupOpResult Result);
	void ClientGroupInviteRejected(EGroupOpResult Result);
	void ClientGroupInviteAccepted(EGroupOpResult Result);
	void ClientGroupInvite(const struct FGroupMemberData& InPlayer);
	void ClientFactionMembersLoaded(TArray<struct FFactionMember> Members);
	void ClientClanPlayerPromoted(EClanOpResult Result);
	void ClientClanPlayerKicked(EClanOpResult Result);
	void ClientClanPlayerInvited(EClanOpResult Result);
	void ClientClanPlayerDemoted(EClanOpResult Result);
	void ClientClanMembersLoaded(TArray<struct FClanMemberData> Members);
	void ClientClanLeft(EClanOpResult Result);
	void ClientClanInvitesLoaded(TArray<struct FClanMemberData> Members);
	void ClientClanInviteRescinded(EClanOpResult Result);
	void ClientClanInviteRejected(EClanOpResult Result);
	void ClientClanInviteAccepted(EClanOpResult Result);
	void ClientClanInvite(const struct FClanData& ClanData);
	void ClientClanCreated(EClanOpResult Result);
	void ClientAdminPlayerUnbanned(bool bSuccess, const struct FString& PlayerName);
	void ClientAdminPlayerReportResult(bool bSuccess, const struct FText& Title, const struct FString& PlayerName);
	void ClientAdminPlayerReportList(const struct FText& Title, TArray<struct FPlayerReportData> Results);
	void ClientAdminPlayerList(const struct FText& Title, TArray<struct FString> Results);
	void ClientAdminPlayerBanned(bool bSuccess, const struct FString& PlayerName);
	void ClientAdminBanList(TArray<struct FString> Results);
	void ClearInteractionTarget();
	void ClanInviteReceived(const struct FClanData& ClanData);
	void CastSpell(const struct FName& SpellId);
	void BuildModeStructure(TEnumAsByte<EStructureType> StructureType);
	void BuildModeMaterial(TEnumAsByte<EPlaceableMaterial> Material);
	bool BroadcastEmote(const struct FName& EmoteId);
	void AddUIEventHandler(class UUIEventHandler* EventHandler);
	void AddOnWorldMapEnteredHandler(const struct FScriptDelegate& InDelegate);
	void AddOnPlayerCharacterAssignedHandler(const struct FScriptDelegate& InDelegate);
};


// Class Otherlands.GameAdminCommandComponent
// 0x0000 (0x00F0 - 0x00F0)
class UGameAdminCommandComponent : public UActorComponent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameAdminCommandComponent");
		return ptr;
	}


	void UnbanPlayer(const struct FString& PlayerName);
	void TrainJrkStats();
	void StartTimedMultiplier(float Multiplier, float Hours);
	void ReportJrkStats();
	void ReportJrks(float Percent, int TopX);
	void ReportingPlayerList();
	void ReportedPlayerList();
	void PlayerReportsFromList(const struct FString& PlayerName);
	void PlayerReportsForList(const struct FString& PlayerName);
	void IsJrk(const struct FString& PlayerName);
	void ClearPlayerReportsFrom(const struct FString& PlayerName);
	void ClearPlayerReportsFor(const struct FString& PlayerName);
	void BanPlayer(const struct FString& PlayerName, const struct FString& Message, int Hours);
	void BanList();
	void BanAccount(const struct FString& UniqueSaveId, const struct FString& Message, int Hours);
	void AdminOutcastOn(const struct FString& PlayerName);
	void AdminOutcastOff(const struct FString& PlayerName);
};


// Class Otherlands.GameCheatCommandComponent
// 0x0018 (0x0108 - 0x00F0)
class UGameCheatCommandComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x00F0(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameCheatCommandComponent");
		return ptr;
	}


	void WipeStructures();
	void WaveEvent(const struct FName& SpawnEventId);
	void UpgradePlaceable();
	void UnlockSpirit(const struct FName& SpiritId);
	void ToggleSpectatorLights();
	void ToggleShields();
	void ToggleLargeBase();
	void ToggleGender();
	void Suicide();
	void StructureHealthScalar(float Val);
	void StructureArmorScalar(float Val);
	void StealStationXP(const struct FName& SkillTree);
	void StartSpiritEvent(const struct FName& SpiritEventId);
	void SpiritMode(bool bSet);
	void SpawnSpiritPortal(float Scale);
	void SpawnSouls(float SoulsToSpawn);
	void SpawnGroup(const struct FName& SpawnGroupId);
	void SpawnEvent(const struct FName& SpawnEventId);
	void SpawnCreature(const struct FName& CreatureId, int CreatureLevel, bool bSpiritRealm, bool bFriendly);
	void SetWeather(const struct FName& WeatherId, float LerpTime);
	void SetTimeOfDay(float TimeOfDay);
	void SetStationStealState(float InStoredXP);
	void SetStat(TEnumAsByte<ECharacterStat> Stat, float Value);
	void SetSkinColor(const struct FName& SkinColorId);
	void SetSkillTreeSkilled(const struct FName& RecipeId);
	void SetSkillTreeMastered(const struct FName& RecipeId);
	void SetSkillLevel(const struct FName& SkillId, int Level);
	void SetServerAge(float Days);
	void SetSeason(TEnumAsByte<ESeason> InSeason);
	void SetPlayerRepLevel(const struct FName& Normal, const struct FName& LadderBased);
	void SetPetFollowForce(TEnumAsByte<EAIPetFollow> NewFollow);
	void SetLevel(int Level);
	void SetHeldItemMod(const struct FName& ModItemId);
	void SetHairColor(const struct FName& HairColorId);
	void SetHair(const struct FName& HairId);
	void SetFaction(int FactionId);
	void SetFacialHair(const struct FName& FacialHairId);
	void SetDayLength(float Minutes);
	void SendFactionBroadcast(const struct FText& Message);
	void ScaleStat(TEnumAsByte<ECharacterStat> Stat, float Scalar);
	void SalvageItem(const struct FName& ItemId, int ItemCount);
	void Respawn();
	void ResetTutorials();
	void ResetTechTree(TEnumAsByte<ETechTreeType> TechTree);
	void ResetTalentArchetypes();
	void ResetEntropy(bool bResetEntropyLootScore, bool bResetEntropyLootRewardCount);
	void ResetDemolishState();
	void ResetAllSkillTrees();
	void ResetAllSkills();
	void ResetAllPerkPoints();
	void RenamePlaceable(const struct FString& NewName);
	void RefreshPlaceable();
	void ReckoningTimeMultiplier(float Val);
	void Reckoning(const struct FName& SpawnEventId, int FactionId);
	void ProfileStart();
	void PortToStart();
	void PortLoc(float LocX, float LocY, float LocZ);
	void PortcoL(float LocX, float LocY, float LocZ);
	void Port(const struct FString& Target);
	void ModifyStat(TEnumAsByte<ECharacterStat> Stat, float Delta);
	void Mobility(bool bEnabled);
	void Mob(bool bEnabled);
	void MassSummon();
	void MassPort(const struct FString& Target);
	void MassGodMode(bool bSet);
	void MassBeastMaster(bool bSet);
	void HarvestMultiplier(float Val);
	void GodMode(bool bSet);
	void GetStats();
	void GetStationStealState();
	void GetStat(TEnumAsByte<ECharacterStat> Stat);
	void GetSkillTreeWhole(const struct FName& SkillTreeId);
	void GetSkillTreeState(const struct FName& RecipeId);
	void GetSecondarySkillStats(TEnumAsByte<ESecondarySkill> Skill, bool bOnlyShowModified);
	void GetPerk(const struct FName& PerkId);
	void GetItemAffixApplicationTiers(const struct FName& ItemAffixApplicationId, float AnchorTierOffset);
	void ForceSave();
	void ForceMatchEnd();
	void ForceEntropyPayout();
	void ForceCrash();
	void ForceAssert();
	void FactionVictory(int FactionId);
	void ExactLoc();
	void EndReckoning();
	void EndAllEvents();
	void EncumbranceMultiplier(float Val);
	void DropCapturePointShields(int Count);
	void DisableGlobalSpawns(bool bSet);
	void DestroyFaction(int FactionId);
	void Despawn(bool bDestroy);
	void DepositSouls(float SoulsToAdd);
	void DebugLoot(bool bSecondary);
	void CreatureLevelScalar(float Val);
	void CreativeMode(bool Val);
	void CreateLoot(const struct FName& LootBaseId, int Count, TEnumAsByte<EHarvestType> HarvestType, int QualityThreshold);
	void CreateItem(const struct FName& ItemId, int ItemCount);
	void CraftSpeedMultiplier(float Val);
	void ClearSpellCooldowns();
	void ClearInventory(bool bClearAll);
	void ClearDeathCount();
	void ClearCollection();
	void ClearBounty(bool bIncludeKillRecord);
	void CheckEntropyScore();
	void CheatOutcastMe();
	void BM(bool bSet);
	void BeastMaster(bool bSet);
	void AddToCollection(const struct FName& InCreatureBaseId, int InVariantIndex, float InRating);
	void AddSpell(const struct FName& SpellId);
	void AddSkillXp(const struct FName& SkillId, float XP);
	void AddSkillTreeXP(const struct FName& RecipeId, float XP);
	void AddReputation(float Delta);
	void AddFavor(float Delta);
	void AddFactionUseScore(float Delta);
	void AddFactionSouls(int FactionId, float SoulsToAdd);
	void AddEntropy(float Delta, bool CanPayout);
	void AddBuff(const struct FName& BuffId);
	void AddBounty(float Delta);
	void AddAscensionPoints(int Count);
};


// Class Otherlands.SlashCommandComponent
// 0x0000 (0x00F0 - 0x00F0)
class USlashCommandComponent : public UActorComponent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SlashCommandComponent");
		return ptr;
	}


	void Unmute(const struct FString& CharacterName);
	void ToggleMute(const struct FString& CharacterName);
	void Stuck();
	void Squelch(const struct FString& CharacterName);
	void SlotAscension(const struct FString& PerkId, int Rank);
	void SetPetReaction(const struct FString& NewReaction);
	void SetPetFollow(const struct FString& NewFollow);
	void Request(const struct FString& PlayerName);
	void ReportPlayer(const struct FString& PlayerName, const struct FString& Desc);
	void ReportCheater(const struct FString& PlayerName, const struct FString& Desc);
	void ReportBehavior(const struct FString& PlayerName, const struct FString& Desc);
	void RenameActivePet(const struct FString& NewName);
	void Promote(const struct FString& PlayerName);
	void PetKillTarget();
	void PetHarvest(bool bSet);
	void Outcast(const struct FString& CharacterName);
	void Mute(const struct FString& CharacterName);
	void MoreHelp(const struct FString& Arg);
	void Loc();
	void Leave();
	void LearnAscension(const struct FString& PerkId, int Rank);
	void Kick(const struct FString& PlayerName);
	void Invite(const struct FString& PlayerName);
	void Ignore(const struct FString& CharacterName);
	void Help();
	void GroupRequest(const struct FString& PlayerName);
	void GroupPromote(const struct FString& PlayerName);
	void GroupLeave();
	void GroupKick(const struct FString& PlayerName);
	void GroupInvite(const struct FString& PlayerName);
	void GetAscensionState();
	void CPromote(const struct FString& PlayerName);
	void CLeave();
	void ClanPromote(const struct FString& PlayerName);
	void ClanLeave();
	void ClanKick(const struct FString& PlayerName);
	void ClanInvite(const struct FString& PlayerName);
	void ClanDemote(const struct FString& PlayerName);
	void ClanCreate(const struct FString& ClanName);
	void CKick(const struct FString& PlayerName);
	void CInvite(const struct FString& PlayerName);
	void CDemote(const struct FString& PlayerName);
};


// Class Otherlands.GameplayOptionsWidget
// 0x0008 (0x0228 - 0x0220)
class UGameplayOptionsWidget : public UGameBaseWidget
{
public:
	float                                              MouseSensitivity;                                         // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsInverted;                                              // 0x0224(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0225(0x0003) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameplayOptionsWidget");
		return ptr;
	}


	void SaveGameplaySettings();
	void GetGameplaySettings();
};


// Class Otherlands.GameplayVolumeListener
// 0x0008 (0x0030 - 0x0028)
class UGameplayVolumeListener : public UObject
{
public:
	class AGameplayVolume*                             VolumeOwner;                                              // 0x0028(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameplayVolumeListener");
		return ptr;
	}


	void OnPlayerExit(class APlayerCharacter* Player);
	void OnPlayerEnter(class APlayerCharacter* Player);
	void EndPlay();
	void BeginPlay();
	bool AffectsPlayer(class APlayerCharacter* Player);
};


// Class Otherlands.GameplayVolume
// 0x00B8 (0x0450 - 0x0398)
class AGameplayVolume : public AAoiAwareVolume
{
public:
	class UClass*                                      ListenerClass;                                            // 0x0398(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UGameplayVolumeListener*                     Listener;                                                 // 0x03A0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bGameplayEnabled;                                         // 0x03A8(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x03A9(0x0007) MISSED OFFSET
	TArray<TWeakObjectPtr<class APlayerCharacter>>     AffectedPlayers;                                          // 0x03B0(0x0010) (ZeroConstructor, Transient)
	TArray<TWeakObjectPtr<class APlayerCharacter>>     UnaffectedPlayers;                                        // 0x03C0(0x0010) (ZeroConstructor, Transient)
	TArray<struct FGameplayBuff>                       VolumeBuffs;                                              // 0x03D0(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	unsigned char                                      UnknownData01[0x70];                                      // 0x03E0(0x0070) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameplayVolume");
		return ptr;
	}


	void SetGameplayEnabled(bool bNewVal);
	void ReevaluateAffectedState();
	void OnBuffCategoryImmunityChanged(class UObject* BuffOwner, const struct FName& BuffCategoryId, int ImmuneTier);
	bool IsGameplayEnabled();
	void GetAffectedPlayers(TArray<class APlayerCharacter*>* OutResult);
};


// Class Otherlands.GameProjectileMovementComponent
// 0x0018 (0x01B8 - 0x01A0)
class UGameProjectileMovementComponent : public UProjectileMovementComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x01A0(0x0010) MISSED OFFSET
	class AGameProjectile*                             ProjectileOwner;                                          // 0x01B0(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameProjectileMovementComponent");
		return ptr;
	}

};


// Class Otherlands.GameProjectile
// 0x01D8 (0x0500 - 0x0328)
class AGameProjectile : public AActor
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0328(0x0010) MISSED OFFSET
	class UCombatantComponent*                         CombatantComponent;                                       // 0x0338(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FTransform                                  SpawnTransform;                                           // 0x0340(0x0030) (Net, IsPlainOldData)
	class UStaticMeshComponent*                        StaticMesh;                                               // 0x0370(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UGameProjectileMovementComponent*            ProjectileMovement;                                       // 0x0378(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    ParticleSystem;                                           // 0x0380(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystem*                             TracerEffect;                                             // 0x0388(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UAudioComponent*                             SoundCom;                                                 // 0x0390(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    BuffParticleSystem[0x3];                                  // 0x0398(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystem*                             BuffTracerEffect[0x3];                                    // 0x03B0(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bStopped;                                                 // 0x03C8(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x03C9(0x0003) MISSED OFFSET
	float                                              Health;                                                   // 0x03CC(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              MaxHealth;                                                // 0x03D0(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESpiritRealmState>                     InSpiritRealmState;                                       // 0x03D4(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x03D5(0x0003) MISSED OFFSET
	TWeakObjectPtr<class UAbilityComponent>            CastAbility;                                              // 0x03D8(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UCurveFloat*                                 DamageFalloffCurve;                                       // 0x03E0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x118];                                     // 0x03E8(0x0118) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameProjectile");
		return ptr;
	}


	void OnRep_Stopped(bool bWasStopped);
	void MulticastStop();
	void MulticastPlayImpactEffect(const struct FPayloadStack& InPayloadStack, const struct FCombatantHitData& HitData);
};


// Class Otherlands.GatekeeperBeaconClient
// 0x0120 (0x04C0 - 0x03A0)
class AGatekeeperBeaconClient : public AOnlineBeaconClient
{
public:
	unsigned char                                      UnknownData00[0x120];                                     // 0x03A0(0x0120) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GatekeeperBeaconClient");
		return ptr;
	}


	void TicketRedemptionStatus_Client(bool bSuccess, bool bInQueue, int QueuePosition);
	void RequestTicket_Server();
	void PunchTicket_Client(const struct FString& ID, EPunchTicketResult Result, int Port);
	void LeaveQueue_Server();
	void DeleteCharacter_Server(const struct FString& CharacterId, const struct FString& CharacterName, const struct FString& Signature);
	void CreateCharacter_Server(const struct FPlayerCharacterProperties& Character, const struct FString& Signature);
	void CharacterPing_Server(const struct FString& AuthId);
	void CharacterPing_Client(bool bSuccess, const struct FPlayerCharacterProperties& Character, bool bNeedPassword);
	void CharacterDeleted_Client(ECharacterDeleteResult Result);
	void CharacterCreated_Client(bool bSuccess);
	void Authenticated_Client(bool bSuccess, const struct FPlayerCharacterProperties& Character, const struct FAscensionUnlockSet& Unlocks, EBeaconAuthenticationError AuthenticationError);
	void Authenticate_Server(const struct FString& EncryptedTicket, const struct FString& ServerPassword);
	void AscensionImported_Client(bool bSuccess, const struct FAscensionUnlockSet& NewUnlockSet);
	void AscensionImport_Server(const struct FString& AscensionCipher);
	void AscensionExported_Client(bool bSuccess, const struct FString& AscensionCipher);
	void AscensionExport_Server();
};


// Class Otherlands.GatekeeperBeaconHost
// 0x01A8 (0x04F8 - 0x0350)
class AGatekeeperBeaconHost : public AOnlineBeaconHostObject
{
public:
	unsigned char                                      UnknownData00[0x1A8];                                     // 0x0350(0x01A8) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GatekeeperBeaconHost");
		return ptr;
	}

};


// Class Otherlands.GearOwnerInterface
// 0x0000 (0x0028 - 0x0028)
class UGearOwnerInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GearOwnerInterface");
		return ptr;
	}


	TEnumAsByte<EGender> GetGender();
	int GetFactionIdAux();
};


// Class Otherlands.GearComponent
// 0x0028 (0x0118 - 0x00F0)
class UGearComponent : public UActorComponent
{
public:
	TArray<struct FName>                               EquipIds;                                                 // 0x00F0(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0100(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GearComponent");
		return ptr;
	}


	void OnRep_EquipIds();
	void OnGameOptionsChanged();
};


// Class Otherlands.GenericSpawnerInstance
// 0x0000 (0x0358 - 0x0358)
class AGenericSpawnerInstance : public ASpawnerInstance
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GenericSpawnerInstance");
		return ptr;
	}

};


// Class Otherlands.GlobalGameData
// 0x0158 (0x0180 - 0x0028)
class UGlobalGameData : public UObject
{
public:
	unsigned char                                      UnknownData00[0x150];                                     // 0x0028(0x0150) MISSED OFFSET
	class UObjectLibrary*                              MaterialLib;                                              // 0x0178(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GlobalGameData");
		return ptr;
	}


	class UGlobalGameData* STATIC_Get();
};


// Class Otherlands.GameAsyncTextureLoader
// 0x0050 (0x0078 - 0x0028)
class UGameAsyncTextureLoader : public UObject
{
public:
	class UMaterialInstanceDynamic*                    Material;                                                 // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	class UPrimitiveComponent*                         Primitive;                                                // 0x0030(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0x40];                                      // 0x0038(0x0040) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameAsyncTextureLoader");
		return ptr;
	}

};


// Class Otherlands.GameSpectatorPawn
// 0x0108 (0x04B8 - 0x03B0)
class AGameSpectatorPawn : public ASpectatorPawn
{
public:
	class UParticleSystemComponent*                    ZoneParticleSystem;                                       // 0x03B0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0x100];                                     // 0x03B8(0x0100) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameSpectatorPawn");
		return ptr;
	}


	void OnZoneChanged(const struct FZoneData& ZoneData);
};


// Class Otherlands.GetCharacterNameProxy
// 0x0038 (0x0068 - 0x0030)
class UGetCharacterNameProxy : public UBlueprintAsyncActionBase
{
public:
	struct FScriptMulticastDelegate                    SUCCESS;                                                  // 0x0030(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    Failed;                                                   // 0x0040(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UObject*                                     WorldContext;                                             // 0x0050(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FString                                     SaveId;                                                   // 0x0058(0x0010) (ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GetCharacterNameProxy");
		return ptr;
	}


	class UGetCharacterNameProxy* STATIC_GetCharacterNameByUniqueSaveId(class UObject* WorldContextObject, const struct FString& UniqueSaveId);
};


// Class Otherlands.GlobalGameLibrary
// 0x0000 (0x0028 - 0x0028)
class UGlobalGameLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GlobalGameLibrary");
		return ptr;
	}


	bool STATIC_ValidateCharacterName(const struct FString& Name, const struct FCharacterNameValidationRules& Rules);
	void STATIC_SetCustomDepthFromSettings(class UPrimitiveComponent* PrimCom, bool Render, ERendererStencilMask StencilWriteMask, int StencilValue, bool Recurse);
	void STATIC_SetCustomDepthFromPrimitive(class UPrimitiveComponent* PrimCom, class UPrimitiveComponent* SrcCom, bool Recurse);
	void STATIC_PlayWorldCameraShake(class UObject* WorldContextObject, class UClass* Shake, const struct FVector& Epicenter, float InnerRadius, float OuterRadius, float Falloff, bool bOrientShakeTowardsEpicenter);
	class UCameraShake* STATIC_PlayLocalCameraShake(class UObject* WorldContextObject, class UClass* ShakeClass, float Scale, TEnumAsByte<ECameraAnimPlaySpace> PlaySpace, const struct FRotator& UserPlaySpaceRot);
	bool STATIC_LineTraceMultiForObjectsComplete(class UObject* WorldContextObject, const struct FVector& Start, const struct FVector& End, TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes, bool bTraceComplex, TArray<class AActor*> ActorsToIgnore, TEnumAsByte<EDrawDebugTrace> DrawDebugType, bool bIgnoreSelf, int MaxHits, const struct FLinearColor& TraceColor, const struct FLinearColor& TraceHitColor, float DrawTime, TArray<struct FHitResult>* OutHits);
	bool STATIC_LineTraceMultiComplete(class UObject* WorldContextObject, const struct FVector& Start, const struct FVector& End, TEnumAsByte<ETraceTypeQuery> TraceChannel, bool bTraceComplex, TArray<class AActor*> ActorsToIgnore, TEnumAsByte<EDrawDebugTrace> DrawDebugType, bool bIgnoreSelf, int MaxHits, const struct FLinearColor& TraceColor, const struct FLinearColor& TraceHitColor, float DrawTime, TArray<struct FHitResult>* OutHits);
	bool STATIC_IsActorOwnedByClient(class UObject* WorldContextObject, class AActor* Actor);
	struct FName STATIC_GetVariantSocket(class USceneComponent* SceneCom, const struct FName& Socket, const struct FName& Suffix);
	struct FStructureGrid STATIC_GetStructureGrid(const struct FIntVector& Min, const struct FIntVector& Max, const struct FVector& Origin, int Padding, float Yaw);
	struct FString STATIC_GetCharacterNameByUniqueSaveIdNow(class UObject* WorldContextObject, const struct FString& UniqueSaveId);
	struct FString STATIC_GetBuildVersion();
	class UObject* STATIC_CreateObjectFromClass(class UObject* Outer, class UClass* Class, const struct FName& Name);
	class USoundCue* STATIC_ConditionalSoundCue(class USoundCue* Override, class USoundCue* Default);
	EBuildConfiguration STATIC_BuildConfiguration();
};


// Class Otherlands.GameDataTableSettings
// 0x0018 (0x0050 - 0x0038)
class UGameDataTableSettings : public UDeveloperSettings
{
public:
	struct FSoftObjectPath                             LoadOrderRef;                                             // 0x0038(0x0018) (Edit, Config)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameDataTableSettings");
		return ptr;
	}

};


// Class Otherlands.GlobalGameTables
// 0x01D0 (0x01F8 - 0x0028)
class UGlobalGameTables : public UObject
{
public:
	class UDataTable*                                  LoadOrder;                                                // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<struct FDataTableInstance>                  TableInstanceCache;                                       // 0x0030(0x0010) (ZeroConstructor)
	TArray<struct FName>                               TableFlags;                                               // 0x0040(0x0010) (ZeroConstructor)
	class UDataTable*                                  MaterialSwapParametersTable;                              // 0x0050(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xA0];                                      // 0x0058(0x00A0) MISSED OFFSET
	class UDataTable*                                  MaterialPropertyTable;                                    // 0x00F8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0100(0x0050) MISSED OFFSET
	class UDataTable*                                  ReckoningStageParametersTable;                            // 0x0150(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0xA0];                                      // 0x0158(0x00A0) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GlobalGameTables");
		return ptr;
	}

};


// Class Otherlands.Goal
// 0x0050 (0x0078 - 0x0028)
class UGoal : public UObject
{
public:
	EGoalState                                         GoalState;                                                // 0x0028(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	struct FName                                       GoalId;                                                   // 0x0030(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FGoalData                                   GoalData;                                                 // 0x0038(0x0040) (BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.Goal");
		return ptr;
	}


	bool Pause(bool bPaused);
	bool OnSelect(bool bSelected);
	bool GoalTick(float DeltaSeconds);
};


// Class Otherlands.GoalAction
// 0x0078 (0x00A0 - 0x0028)
class UGoalAction : public UObject
{
public:
	EGoalState                                         GoalState;                                                // 0x0028(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	struct FName                                       GoalActionId;                                             // 0x0030(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FGoalActionData                             GoalActionData;                                           // 0x0038(0x0068) (BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GoalAction");
		return ptr;
	}


	bool Pause(bool bPaused);
	bool OnSelect(bool bSelected);
	bool ActionTick(float DeltaSeconds);
};


// Class Otherlands.GoalManager
// 0x0118 (0x0140 - 0x0028)
class UGoalManager : public UObject
{
public:
	class UDataTable*                                  GoalActorTraitTable;                                      // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0030(0x0050) MISSED OFFSET
	class UDataTable*                                  GoalActionTable;                                          // 0x0080(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x60];                                      // 0x0088(0x0060) MISSED OFFSET
	class UDataTable*                                  GoalTable;                                                // 0x00E8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x00F0(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GoalManager");
		return ptr;
	}

};


// Class Otherlands.GoalPlanningComponent
// 0x0080 (0x0170 - 0x00F0)
class UGoalPlanningComponent : public UActorComponent
{
public:
	EGoalState                                         GoalState;                                                // 0x00F0(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EAICharacterState>                     LastKnownState;                                           // 0x00F1(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x00F2(0x0006) MISSED OFFSET
	TArray<class UGoal*>                               Goals;                                                    // 0x00F8(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FGameplayTag                                TagGoalSolver;                                            // 0x0108(0x0008)
	class UGoal*                                       ActiveGoal;                                               // 0x0110(0x0008) (ZeroConstructor, IsPlainOldData)
	class UGoalAction*                                 ActiveGoalAction;                                         // 0x0118(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0120(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GoalPlanningComponent");
		return ptr;
	}


	bool UpdatePlan();
	void SetMemory(const struct FGoalMemoryKey& InKey, struct FGoalMemoryValue* InValue);
	bool RemoveGoalById(const struct FName& GoalId);
	bool RemoveGoal(class UGoal* Goal);
	void PlanTick(TEnumAsByte<EAICharacterState> AiState, float DeltaSeconds);
	void Pause(bool bPaused);
	bool GetMemory(const struct FGoalMemoryKey& InKey, struct FGoalMemoryValue* OutValue);
	class UGoal* GetActiveGoal();
	class UGoalAction* GetActiveAction();
	void ClearMemory(const struct FGoalMemoryKey& InKey);
	class UGoal* AddGoal(const struct FName& GoalId);
};


// Class Otherlands.Group
// 0x0060 (0x0388 - 0x0328)
class AGroup : public AActor
{
public:
	struct FScriptMulticastDelegate                    OnDisband;                                                // 0x0328(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMemberListUpdate;                                       // 0x0338(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UChatChannel*                                GroupChatChannel;                                         // 0x0348(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	TArray<struct FGroupInvite>                        PendingInvites;                                           // 0x0350(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient)
	TArray<struct FGroupInvite>                        PendingRequests;                                          // 0x0360(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient)
	int                                                FactionId;                                                // 0x0370(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0374(0x0004) MISSED OFFSET
	TArray<struct FGroupMember>                        Members;                                                  // 0x0378(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.Group");
		return ptr;
	}


	EGroupOpResult RescindRequest(class AGamePlayerController* Caller);
	EGroupOpResult RescindInvite(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EGroupOpResult RemoveMemberByCharacterId(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EGroupOpResult RemoveMember(class AGamePlayerController* Caller, class AGamePlayerController* Player, bool bKicked);
	EGroupOpResult RejectRequest(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EGroupOpResult RejectInvite(class AGamePlayerController* Caller);
	EGroupOpResult PromoteMember(class AGamePlayerController* Caller, class AGamePlayerController* Player);
	void MulticastRosterUpdated();
	EGroupOpResult LeaveGroup(class APlayerCharacter* Player, bool bKicked);
	bool IsPlayerGroupMemberByCharacterId(const struct FString& CharacterId);
	bool IsPlayerGroupMember(class AGamePlayerController* Player);
	bool IsPlayerGroupLeader(class APlayerCharacter* Player);
	EGroupOpResult CanRemoveMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EGroupOpResult CanPromoteMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EGroupOpResult CanInviteMember(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EGroupOpResult CanAcceptMemberRequest(class AGamePlayerController* Caller, const struct FString& CharacterId);
	EGroupOpResult BroadcastToGroupChannel(class AGamePlayerController* SourcePlayer, const struct FText& Input);
	EGroupOpResult AddMember(class AGamePlayerController* Caller, class AGamePlayerController* Player, bool bConfirmed);
};


// Class Otherlands.HarvestableInterface
// 0x0000 (0x0028 - 0x0028)
class UHarvestableInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HarvestableInterface");
		return ptr;
	}


	bool OnTriggerBy(class ABasicCharacter* Target, TEnumAsByte<EResourceTriggerTimingType> Timing);
	bool OnHarvestedBy(class ABasicCharacter* Harvester, TEnumAsByte<EHarvestType> HarvestType, int QualityThreshold, float Damage);
	bool OnCreatureDamaged(class ABasicCharacter* Creature, float Damage);
	bool HasDepleted();
	TEnumAsByte<ESecondarySkill> GetSecondarySkill();
	float GetNoiseMultiplier();
	float GetMaxHarvestDistance(int HitItem);
	struct FName GetLootId();
	bool CanBeHarvestedBy(TEnumAsByte<EHarvestType> HarvestType, int QualityThreshold, TEnumAsByte<ESpiritRealmState> SpiritRealmState);
};


// Class Otherlands.HarvestableLibrary
// 0x0000 (0x0028 - 0x0028)
class UHarvestableLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HarvestableLibrary");
		return ptr;
	}


	TScriptInterface<class UHarvestableInterface> STATIC_GetBestHarvestableFromHit(const struct FHitResult& HitResult);
	TScriptInterface<class UHarvestableInterface> STATIC_GetBestHarvestable(class UObject* Obj);
};


// Class Otherlands.HeatVolume
// 0x0000 (0x03B0 - 0x03B0)
class AHeatVolume : public AAmbientStatVolume
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HeatVolume");
		return ptr;
	}

};


// Class Otherlands.HeldItemComponent
// 0x01A0 (0x0290 - 0x00F0)
class UHeldItemComponent : public UActorComponent
{
public:
	struct FScriptMulticastDelegate                    OnBuildModeItemUpdate;                                    // 0x00F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0100(0x0008) MISSED OFFSET
	class UStaticMeshComponent*                        HeldStaticMesh;                                           // 0x0108(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkeletalMeshComponent*                      HeldSkeletalMesh;                                         // 0x0110(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        PlaceableStaticMesh;                                      // 0x0118(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        PlaceableStaticMeshMirror;                                // 0x0120(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UArrowComponent*                             PlaceableArrowComponent;                                  // 0x0128(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    ParticleSystem;                                           // 0x0130(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAudioComponent*                             AudioComp;                                                // 0x0138(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0140(0x0008) MISSED OFFSET
	class AActor*                                      PointLight;                                               // 0x0148(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       ItemId;                                                   // 0x0150(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       AmmoItemId;                                               // 0x0158(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class UInventoryItem>               InventoryItem;                                            // 0x0160(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bWeaponVisible;                                           // 0x0168(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0169(0x0007) MISSED OFFSET
	class UStaticMeshComponent*                        OffhandStaticMesh;                                        // 0x0170(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkeletalMeshComponent*                      OffhandSkeletalMesh;                                      // 0x0178(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    OffhandParticleSystem;                                    // 0x0180(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAudioComponent*                             OffhandAudioComp;                                         // 0x0188(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x0190(0x0008) MISSED OFFSET
	class AActor*                                      OffhandPointLight;                                        // 0x0198(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       OffhandItemId;                                            // 0x01A0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class UInventoryItem>               OffhandInventoryItem;                                     // 0x01A8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       ModificationItemId;                                       // 0x01B0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	int                                                BuildModePlaceableTier;                                   // 0x01B8(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EPlaceableMaterial>                    BuildModePlaceableMaterial;                               // 0x01BC(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EStructureType>                        BuildModeStructureType;                                   // 0x01BD(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x2];                                       // 0x01BE(0x0002) MISSED OFFSET
	struct FName                                       BuildModeItemPlaceableUpgradeId;                          // 0x01C0(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       BuildModeItemId;                                          // 0x01C8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UStaticMeshComponent*                        HeldModMesh;                                              // 0x01D0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    ModParticleSystem;                                        // 0x01D8(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class AActor*                                      ModPointLight;                                            // 0x01E0(0x0008) (ZeroConstructor, IsPlainOldData)
	class APlayerCharacter*                            PlayerOwner;                                              // 0x01E8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0xA0];                                      // 0x01F0(0x00A0) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HeldItemComponent");
		return ptr;
	}


	void UpdatePlaceableYaw(float Delta);
	bool TargetingPlaceableStructure();
	void ShowWeapon(bool bShow);
	void SetSnapPlaceableYaw(bool bSet);
	void SetBuildModeStructureType(TEnumAsByte<EStructureType> NewType);
	void SetBuildModePlaceableTier(int NewTier);
	void SetBuildModePlaceableMaterial(TEnumAsByte<EPlaceableMaterial> NewMaterial);
	void ServerSetBuildModeStructureType(TEnumAsByte<EStructureType> NewType);
	void ServerSetBuildModePlaceableTier(int Tier);
	void ServerSetBuildModePlaceableMaterial(TEnumAsByte<EPlaceableMaterial> NewMaterial);
	void OnRep_OffhandItemId();
	void OnRep_ItemId();
	void OnRep_BuildModeItemPlaceableUpgradeId();
	bool IsWeaponVisible();
	bool GetPlaceableUpgradeInfo(struct FItemPlaceableUpgradeInfo* OutInfo);
	struct FName GetOffHandItemId();
	struct FName GetItemId();
	class UInventoryItem* GetInventoryItem();
	EDisallowPlacementReason GetDisallowPlacementReason();
	bool CanRotateHeldItem();
};


// Class Otherlands.HeldItemAnimInstance
// 0x0040 (0x03A0 - 0x0360)
class UHeldItemAnimInstance : public UAnimInstance
{
public:
	class UAnimMontage*                                ReloadMontage;                                            // 0x0360(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlayerHandSocketName;                                     // 0x0368(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsSpinning;                                              // 0x0370(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0371(0x0003) MISSED OFFSET
	float                                              SpinUpValue;                                              // 0x0374(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              AmmoLoadedValue;                                          // 0x0378(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	TEnumAsByte<EGender>                               Gender;                                                   // 0x037C(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x037D(0x0003) MISSED OFFSET
	struct FVector                                     PlayerHandSocketWorldLocation;                            // 0x0380(0x000C) (BlueprintVisible, BlueprintReadOnly, Transient, IsPlainOldData)
	bool                                               bHasHandOnBowString;                                      // 0x038C(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x038D(0x0003) MISSED OFFSET
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0390(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x0398(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HeldItemAnimInstance");
		return ptr;
	}

};


// Class Otherlands.HitValidationComponent
// 0x0000 (0x00F0 - 0x00F0)
class UHitValidationComponent : public UActorComponent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HitValidationComponent");
		return ptr;
	}

};


// Class Otherlands.HitZoneComponent
// 0x0010 (0x05B0 - 0x05A0)
class UHitZoneComponent : public UCapsuleComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x05A0(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HitZoneComponent");
		return ptr;
	}

};


// Class Otherlands.HudMenuWidget
// 0x0000 (0x0220 - 0x0220)
class UHudMenuWidget : public UGameBaseWidget
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.HudMenuWidget");
		return ptr;
	}


	void OpenTechTree();
	void OpenTalents();
	void OpenStats();
	void OpenSpellBook();
	void OpenSkills();
	void OpenPerks();
	void OpenMenu();
	void OpenInventory();
	void OpenCrafting();
	void NotifyUnlockUp();
	void NotifyUnlockOpen();
	void NotifyTalentUp();
	void NotifySpellUp();
	void NotifySkillUp();
	void NotifySkillsOpen();
	void NotifyCraftResult(TEnumAsByte<ECraftResultType> CrafResult);
	void NotifyCraftingUp();
	void NotifyCraftingOpen();
	struct FText GetActionKey(const struct FName& ActionName);
};


// Class Otherlands.InteractiveInterface
// 0x0000 (0x0028 - 0x0028)
class UInteractiveInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.InteractiveInterface");
		return ptr;
	}


	bool OnInteract(class ABasicCharacter* Character, const struct FName& InteractActionId);
	bool IsInRange(class APlayerCharacter* Player);
	bool GetStructureUpgradeInfo(class APlayerCharacter* InPlayerCharacter, struct FItemPlaceableUpgradeInfo* OutInfo, bool* OutLocalData);
	class UPlaceableMeshComponent* GetPlaceableMesh();
	class UInventoryComponent* GetInventoryComponent();
	TEnumAsByte<EInteractType> GetInteractType();
	struct FText GetInteractTitle();
	struct FName GetInteractiveItemId();
	class UCraftComponent* GetCraftComponent();
	bool GetAllowedActions(class ABasicCharacter* InCharacter, TArray<struct FName>* OutActions);
	TEnumAsByte<ECanInteractType> CanInteract(class ABasicCharacter* Character);
	bool CanBeUpgraded(class APlayerCharacter* InPlayerCharacter);
};


// Class Otherlands.InteractiveLibrary
// 0x0000 (0x0028 - 0x0028)
class UInteractiveLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.InteractiveLibrary");
		return ptr;
	}


	bool STATIC_SupportsInteractive(class UObject* Obj);
	TScriptInterface<class UInteractiveInterface> STATIC_GetInteractiveFromHit(class AActor* Actor, class UActorComponent* Component, int ItemIndex, bool bForInteract, bool* bDidSpawn);
	TScriptInterface<class UInteractiveInterface> STATIC_GetInteractive(class UObject* Obj);
};


// Class Otherlands.PlaceableMeshComponent
// 0x0150 (0x0780 - 0x0630)
class UPlaceableMeshComponent : public UGameStaticMesh
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0630(0x0008) MISSED OFFSET
	struct FScriptDelegate                             OnFillSocketDelegate;                                     // 0x0638(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnEmptySocketDelegate;                                    // 0x0648(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             CanInteractPlugDelegate;                                  // 0x0658(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnInteractPlugDelegate;                                   // 0x0668(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             GetAllowedActionsPlugDelegate;                            // 0x0678(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0688(0x0008) MISSED OFFSET
	bool                                               bDisableTickAfterAssetsLoad;                              // 0x0690(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0691(0x0007) MISSED OFFSET
	struct FName                                       ItemId;                                                   // 0x0698(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	float                                              MaxHealth;                                                // 0x06A0(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	float                                              Health;                                                   // 0x06A4(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	float                                              armor;                                                    // 0x06A8(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x06AC(0x0004) MISSED OFFSET
	TArray<struct FPlacedSocketInfo>                   Sockets;                                                  // 0x06B0(0x0010) (Net, ZeroConstructor)
	struct FPlaceableUpgradeState                      UpgradeState;                                             // 0x06C0(0x0038) (BlueprintVisible, BlueprintReadOnly, Net)
	unsigned char                                      UnknownData04[0x8];                                       // 0x06F8(0x0008) MISSED OFFSET
	class AActor*                                      PointLight;                                               // 0x0700(0x0008) (ZeroConstructor, IsPlainOldData)
	class APlaceableActor*                             PlaceableOwner;                                           // 0x0708(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x70];                                      // 0x0710(0x0070) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableMeshComponent");
		return ptr;
	}


	void SetItem(const struct FName& NewItemId);
	void SetFactionId(int FactionId);
	void OnRep_UpgradeState();
	void OnRep_Sockets();
	void OnRep_ItemId();
	void MulticastPauseRepair();
	bool IsRepairPaused();
	bool IsPersonal();
	class UPlaceableMeshComponent* GetSocketedPlug(const struct FName& SocketName);
	float GetRepairPauseDelay();
	class UDestructibleMesh* GetDestructibleMesh();
	struct FArmorValues GetArmorValues();
	bool AreAssetsLoaded();
};


// Class Otherlands.InteractiveMeshComponent
// 0x0080 (0x0800 - 0x0780)
class UInteractiveMeshComponent : public UPlaceableMeshComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0780(0x0008) MISSED OFFSET
	bool                                               bIsDroppedItemContainer;                                  // 0x0788(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0789(0x0007) MISSED OFFSET
	class UInventoryComponent*                         InventoryComp;                                            // 0x0790(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UInventoryComponent*                         FuelInventoryComp;                                        // 0x0798(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UCraftComponent*                             CraftComp;                                                // 0x07A0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBuffComponent*                              BuffComp;                                                 // 0x07A8(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USpellCastComponent*                         SpellCastComponent;                                       // 0x07B0(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkeletalMeshComponent*                      SkeletalMeshComponent;                                    // 0x07B8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    ParticleSystem;                                           // 0x07C0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class AActor*                                      ActivePointLight;                                         // 0x07C8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UAudioComponent*                             ActiveSoundComponent;                                     // 0x07D0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAudioComponent*                             DeactivateSoundComponent;                                 // 0x07D8(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              StoredWater;                                              // 0x07E0(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1C];                                      // 0x07E4(0x001C) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.InteractiveMeshComponent");
		return ptr;
	}


	void OnHitCallback(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, const struct FVector& NormalImpulse, const struct FHitResult& Hit);
	bool IsInActiveState();
	bool HasUnlimitedWater();
	float GetStoredWater();
	void AssetsLoaded();
};


// Class Otherlands.InventoryEventHandler
// 0x0048 (0x0080 - 0x0038)
class UInventoryEventHandler : public UEventHandler
{
public:
	struct FScriptDelegate                             OnInventoryUpdated;                                       // 0x0038(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnInventorySlotsUpdated;                                  // 0x0048(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnInventorySlotUpdated;                                   // 0x0058(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	struct FScriptDelegate                             OnInventoryDestroyed;                                     // 0x0068(0x0014) (BlueprintVisible, ZeroConstructor, InstancedReference)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0078(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.InventoryEventHandler");
		return ptr;
	}


	void Unbind();
};


// Class Otherlands.InventoryEventHandlerStack
// 0x0010 (0x0038 - 0x0028)
class UInventoryEventHandlerStack : public UObject
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0028(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.InventoryEventHandlerStack");
		return ptr;
	}


	class UInventoryEventHandler* STATIC_CreateInventoryEventHandler(class UObject* Owner);
};


// Class Otherlands.InventoryComponent
// 0x0140 (0x0230 - 0x00F0)
class UInventoryComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x00F0(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnInventoryUpdated;                                       // 0x00F8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInventorySlotsUpdated;                                  // 0x0108(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnInventorySlotUpdated;                                   // 0x0118(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDecayItemEvent;                                         // 0x0128(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData01[0x20];                                      // 0x0138(0x0020) MISSED OFFSET
	TArray<class UInventoryItem*>                      Items;                                                    // 0x0158(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, DisableEditOnTemplate, EditConst)
	TEnumAsByte<EItemCategory>                         ItemCategoryRestriction;                                  // 0x0168(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0169(0x0007) MISSED OFFSET
	struct FText                                       InventoryName;                                            // 0x0170(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, Net, DisableEditOnTemplate, EditConst)
	float                                              LifeSpanRemaining;                                        // 0x0188(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, DisableEditOnTemplate, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x018C(0x0004) MISSED OFFSET
	struct FName                                       PermissionIdRequired;                                     // 0x0190(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, DisableEditOnTemplate, EditConst, IsPlainOldData)
	bool                                               bIgnoreFactionUseScore;                                   // 0x0198(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x3];                                       // 0x0199(0x0003) MISSED OFFSET
	int                                                OriginalSlotCount;                                        // 0x019C(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                MaxSlotCount;                                             // 0x01A0(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bCanDeposit;                                              // 0x01A4(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x3];                                       // 0x01A5(0x0003) MISSED OFFSET
	class APlayerCharacter*                            PlayerOwner;                                              // 0x01A8(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bInteractiveCached;                                       // 0x01B0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x7];                                       // 0x01B1(0x0007) MISSED OFFSET
	class APlaceableActor*                             PlaceableOwner;                                           // 0x01B8(0x0008) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EInventoryType>                        InventoryType;                                            // 0x01C0(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x37];                                      // 0x01C1(0x0037) MISSED OFFSET
	class UInventoryEventHandlerStack*                 EventHandlerStack;                                        // 0x01F8(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData08[0x30];                                      // 0x0200(0x0030) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.InventoryComponent");
		return ptr;
	}


	bool UsesWeight();
	bool UseRemoteItems();
	bool UnbindEventHandler(class UInventoryEventHandler* EventHandler);
	bool ShouldIgnoreFactionUseScore();
	void SetInventorySlots(int NumSlots);
	void ServerSortByWeight();
	int RemoveItemCountFromSlot(int SlotNdx, int ItemCount);
	int RemoveItemCount(const struct FName& ItemId, int ItemCount);
	void OnRep_Items();
	void OnPurgeInterestedPartiesTimer();
	bool IsOverCapacity();
	bool IsEmpty();
	bool IsAtCapacity();
	void Initialize(class APlayerCharacter* Owner, int NumSlots, TEnumAsByte<EItemCategory> CategoryRestriction, bool bCanGrow, TEnumAsByte<EInventoryType> InInventoryType, bool bPlayerCanDeposit);
	bool HasValidRemoteData();
	bool HasSpaceForItem(const struct FName& ItemId, int ItemCount);
	float GetTotalResourceAmount(TEnumAsByte<EItemResourceType> ItemResourceType);
	void GetSlotInfo(int ItemSlot, class UTexture2D** OutEmptyIcon, struct FText* OutSlotName);
	bool GetRepairKits(class UInventoryItem* DamagedItem, TArray<class UInventoryItem*>* OutRepairKitItems);
	class APlayerCharacter* GetPlayerOwner();
	int GetOriginalSlots();
	int GetNumSlots();
	int GetNumEmptySlots();
	float GetMaxWeight();
	int GetItemSlot(class UInventoryItem* Item);
	struct FName GetItemId(int ItemSlot);
	bool GetItemData(int ItemSlot, struct FRemoteItemData* RemoteItemData);
	int GetItemCount(const struct FName& ItemId);
	class UInventoryItem* GetItem(int ItemSlot);
	int GetInventoryBuffCount(const struct FName& BuffId);
	float GetCurrentWeight();
	int STATIC_GetAffixStatCount(const struct FRemoteItemData& RemoteData);
	bool STATIC_GetAffixStat(const struct FRemoteItemData& RemoteData, int Index, struct FName* OutAffixId, float* OutStatValue);
	int DropItemCountFromSlot(int SlotNdx, int ItemCount);
	int DropItemCount(const struct FName& ItemId, int ItemCount);
	int CreateAndDropItemCount(const struct FName& ItemId, int ItemCount);
	void ClientOnSlotUpdated(int Slot);
	void ClientOnSlotsUpdated(TArray<int> Slots);
	void ClientOnNumSlotsChanged();
	bool BindEventHandler(class UInventoryEventHandler* EventHandler, bool bPrimary);
	void AffectDurabilityOfAll(const struct FItemAffectDurabilityData& AffectData, float Scalar);
	int AddNewItemOrDrop(const struct FName& ItemId, int ItemCount, bool bAddtoStackOnly);
	int AddNewItem(const struct FName& ItemId, int ItemCount, bool bAddtoStackOnly, bool bForceAdd);
	bool AddLoot(TArray<struct FLootRollResult> LootResults, bool bDropExtra, bool bAddtoStackOnly, bool bForceAdd, TArray<struct FLootRollResult>* OutLeftOver);
};


// Class Otherlands.InventoryItem
// 0x0120 (0x0148 - 0x0028)
class UInventoryItem : public UObject
{
public:
	TArray<int>                                        CustomIntData;                                            // 0x0028(0x0010) (BlueprintVisible, Net, ZeroConstructor)
	TArray<float>                                      CustomFloatData;                                          // 0x0038(0x0010) (BlueprintVisible, Net, ZeroConstructor)
	TArray<struct FName>                               CustomNameData;                                           // 0x0048(0x0010) (BlueprintVisible, Net, ZeroConstructor)
	struct FName                                       ItemId;                                                   // 0x0058(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	struct FItemAffixInstance                          AffixInstance;                                            // 0x0060(0x0048) (BlueprintVisible, BlueprintReadOnly, Net)
	struct FString                                     CraftedBy;                                                // 0x00A8(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)
	struct FString                                     BoundOwnerId;                                             // 0x00B8(0x0010) (Net, ZeroConstructor)
	float                                              Durability;                                               // 0x00C8(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	float                                              DurabilityDamage;                                         // 0x00CC(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x00D0(0x0004) MISSED OFFSET
	int                                                StackCount;                                               // 0x00D4(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x00D8(0x0008) MISSED OFFSET
	struct FName                                       AmmoItemId;                                               // 0x00E0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	int                                                AmmoInClip;                                               // 0x00E8(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              StoredResource;                                           // 0x00EC(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       ModificationItemId;                                       // 0x00F0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UInventoryComponent*                         OwnerInventory;                                           // 0x00F8(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              StartingDecayTime;                                        // 0x0100(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0104(0x0004) MISSED OFFSET
	struct FItemAffixStats                             CachedAffixStats;                                         // 0x0108(0x0020) (BlueprintVisible, Net)
	struct FItemWeaponStats                            CachedWeaponStats;                                        // 0x0128(0x000C) (BlueprintVisible, Net)
	unsigned char                                      UnknownData03[0x14];                                      // 0x0134(0x0014) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.InventoryItem");
		return ptr;
	}


	void Unload();
	bool TickDurability(float SecondsUsed);
	void StorePrototype();
	bool SetModificationItem(class UItemData* ModItem);
	void SetDecayTime(float DecayTime);
	bool SetAmmoId(const struct FName& AmmoId);
	void ResetCachedWeaponStats();
	void ResetCachedAffixStats();
	void RepairWith(class UInventoryItem* RepairKitItem);
	void Reload();
	void PreOnHeld(bool bHeld, bool bOffhand);
	void PreOnEquip(bool bEquip);
	void PostOnHeld(bool bHeld, bool bOffhand);
	void PostOnEquip(bool bEquip);
	void OnStoredResourceChanged(float OldStoredResource);
	void OnStackCountChanged(int OldStackCount);
	void OnRep_UpdateItem();
	void OnRep_UpdateAmmoItem();
	void OnRep_DurabilityDamage();
	void OnRep_Durability();
	void OnRep_DecayTime();
	void OnRep_CustomNameData();
	void OnRep_CustomIntData();
	void OnRep_CustomFloatData();
	void OnRep_Clip();
	void OnRep_AffixUpdated();
	void OnConsumed();
	void OnCachedWeaponStats();
	void OnCachedAffixStats();
	void OnAmmoChanged();
	void NotifyOnFired();
	bool NoAmmoNeeded();
	bool NeedsReload();
	bool ModifyDurability(float Delta, bool bUseScalar);
	bool IsUsable();
	bool IsThrownWeapon();
	bool Initialize(EItemInitReason Reason, class UInventoryItem* Source);
	void InheritDecayTime(float ProposedDecayTime);
	bool HasAmmoInClip();
	int GetShotsPerBurst();
	class APlayerCharacter* GetPlayerOwner();
	class UInventoryComponent* GetOwnerInventory();
	struct FName GetModificationItemId();
	float GetMaxDurability();
	struct FName GetLoadedAmmoId();
	struct FName GetItemId();
	class UItemData* GetItemDataForBP();
	void GetExtraTooltip(TArray<struct FExtraTooltip>* TooltipLines);
	float GetDurabilityConsumptionScalar(bool bIncludeGameModeScalar);
	float GetDecayTimeRemaining();
	float GetCooldown();
	int GetClipSize();
	struct FName GetBuffIdInventory();
	struct FString GetBoundOwnerId();
	int GetAmmoInClip();
	int GetAffixStatCount();
	bool GetAffixStat(int Index, struct FName* OutAffixId, float* OutStatValue);
	void FullyRepair();
	void DecayItemNow(bool bFireEvent);
	bool CanStorePrototype();
	bool CanSetModificationItem(class UItemData* ModItem);
	bool CanRepair(class UInventoryItem* DamagedItem);
	bool CanReload();
	bool CanConsume();
	bool CanBeRepaired();
	bool AffectDurability(const struct FItemAffectDurabilityData& AffectData, float Scalar);
};


// Class Otherlands.ItemData
// 0x1338 (0x1360 - 0x0028)
class UItemData : public UObject
{
public:
	struct FName                                       ItemId;                                                   // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FText                                       DisplayName;                                              // 0x0030(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<EItemFamily>                           Family;                                                   // 0x0048(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemCategory>                         Category;                                                 // 0x0049(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemType>                             ItemType;                                                 // 0x004A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x004B(0x0005) MISSED OFFSET
	class UClass*                                      InventoryItemClass;                                       // 0x0050(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0058(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemData.Icon
	TEnumAsByte<ESecondarySkill>                       SecondarySkill;                                           // 0x0080(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0081(0x0003) MISSED OFFSET
	int                                                MaxStack;                                                 // 0x0084(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Weight;                                                   // 0x0088(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAllowAutoEquip;                                          // 0x008C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemQuality>                          Quality;                                                  // 0x008D(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x2];                                       // 0x008E(0x0002) MISSED OFFSET
	int                                                ItemTier;                                                 // 0x0090(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FuelValue;                                                // 0x0094(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0xC];                                       // 0x0098(0x000C) MISSED OFFSET
	float                                              MaxDurability;                                            // 0x00A4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DurabilityPerSecondUsed;                                  // 0x00A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemResourceType>                     ResourceStorageType;                                      // 0x00AC(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemSoulboundType>                    SoulboundType;                                            // 0x00AD(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x2];                                       // 0x00AE(0x0002) MISSED OFFSET
	float                                              ResourceCapacity;                                         // 0x00B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ResourceLeakRate;                                         // 0x00B4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DecayTime;                                                // 0x00B8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0xC];                                       // 0x00BC(0x000C) MISSED OFFSET
	float                                              FactionUseScore;                                          // 0x00C8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                WarehouseMaxCount;                                        // 0x00CC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                WarehouseAbsMaxCount;                                     // 0x00D0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ReuptationValueScalar;                                    // 0x00D4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bGiveRepForDeposit;                                       // 0x00D8(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x7];                                       // 0x00D9(0x0007) MISSED OFFSET
	struct FText                                       FunctionText;                                             // 0x00E0(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       FlavorText;                                               // 0x00F8(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FName                                       OverrideDroppedContainerItemId;                           // 0x0110(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CraftResearchIdRevEng;                                    // 0x0118(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RevEngResult;                                             // 0x0120(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData08[0x4];                                       // 0x0124(0x0004) MISSED OFFSET
	struct FName                                       LootBaseIdSalvage;                                        // 0x0128(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffIdInventory;                                          // 0x0130(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TMap<struct FName, float>                          CustomFloats;                                             // 0x0138(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TMap<struct FName, int>                            CustomInts;                                               // 0x0188(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TMap<struct FName, struct FName>                   CustomIds;                                                // 0x01D8(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       ItemAffixApplicationId;                                   // 0x0228(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemServerUniqueId;                                       // 0x0230(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUniquePlaceholder;                                       // 0x0238(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData09[0x3];                                       // 0x0239(0x0003) MISSED OFFSET
	int                                                MaxSagaCount;                                             // 0x023C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bDropsOnLogoff;                                           // 0x0240(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData10[0x3];                                       // 0x0241(0x0003) MISSED OFFSET
	float                                              MaximumLogoffHours;                                       // 0x0244(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                SagaUniquePriority;                                       // 0x0248(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SagaUniqueChance;                                         // 0x024C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	EItemUniqueRestriction                             SagaRestrictionRule;                                      // 0x0250(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData11[0x7];                                       // 0x0251(0x0007) MISSED OFFSET
	struct FName                                       ItemDamageDataId;                                         // 0x0258(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData12[0x1];                                       // 0x0260(0x0001) MISSED OFFSET
	bool                                               bShotgun;                                                 // 0x0261(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData13[0x6];                                       // 0x0262(0x0006) MISSED OFFSET
	int                                                ShotgunCircles;                                           // 0x0268(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ShotgunShotsPerCircle;                                    // 0x026C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData14[0x30];                                      // 0x0270(0x0030) MISSED OFFSET
	struct FName                                       PlayerAbilityIdPrimary;                                   // 0x02A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlayerAbilityIdAlternate;                                 // 0x02A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           DamageType;                                               // 0x02B0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData15[0x7];                                       // 0x02B1(0x0007) MISSED OFFSET
	TArray<struct FDamageConversion>                   DamageConversions;                                        // 0x02B8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	float                                              TrueDamagePercent;                                        // 0x02C8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitDamagePerHit;                                         // 0x02CC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamagePerHit;                                        // 0x02D0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlayerDamageScalar;                                       // 0x02D4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AttackSpeed;                                              // 0x02D8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData16[0x4];                                       // 0x02DC(0x0004) MISSED OFFSET
	float                                              RepairAmountPerHit;                                       // 0x02E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SalvageAmountPerHit;                                      // 0x02E4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData17[0xC];                                       // 0x02E8(0x000C) MISSED OFFSET
	float                                              BurstTime;                                                // 0x02F4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ShotsPerBurst;                                            // 0x02F8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ClipSize;                                                 // 0x02FC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ReloadTime;                                               // 0x0300(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EmptyTime;                                                // 0x0304(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HipSpread;                                                // 0x0308(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData18[0xF0];                                      // 0x030C(0x00F0) MISSED OFFSET
	TEnumAsByte<EAttackType>                           AttackType;                                               // 0x03FC(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData19[0x7];                                       // 0x03FD(0x0007) MISSED OFFSET
	float                                              ProjectileDistanceBeforeGravity;                          // 0x0404(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData20[0xC];                                       // 0x0408(0x000C) MISSED OFFSET
	float                                              DamageFalloffRangeMin;                                    // 0x0414(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DamageFalloffRangeMax;                                    // 0x0418(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData21[0x4];                                       // 0x041C(0x0004) MISSED OFFSET
	class UCurveFloat*                                 DamageFalloffCurve;                                       // 0x0420(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AdditionalPierceTargets;                                  // 0x0428(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxTargets;                                               // 0x042C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData22[0x108];                                     // 0x0430(0x0108) MISSED OFFSET
	struct FName                                       PayloadId;                                                // 0x0538(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemBowScalarDataId;                                      // 0x0540(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData23[0xA0];                                      // 0x0548(0x00A0) MISSED OFFSET
	class UCurveFloat*                                 DrawToDamageScalarCurve;                                  // 0x05E8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DrawToVelocityScalarCurve;                                // 0x05F0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DrawToRangeScalarCurve;                                   // 0x05F8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 DrawToAccuracyScalarCurve;                                // 0x0600(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       ItemHarvestDataId;                                        // 0x0608(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EHarvestType>                          HarvestType;                                              // 0x0610(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EHarvestType>                          HarvestTypeSecondary;                                     // 0x0611(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData24[0x2];                                       // 0x0612(0x0002) MISSED OFFSET
	float                                              HarvestDamagePerHit;                                      // 0x0614(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestDamageVariation;                                   // 0x0618(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestQuantityMultiplier;                                // 0x061C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData25[0xE8];                                      // 0x0620(0x00E8) MISSED OFFSET
	struct FName                                       ItemPlaceableDataId;                                      // 0x0708(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EPlaceableType>                        PlaceableType;                                            // 0x0710(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData26[0xF];                                       // 0x0711(0x000F) MISSED OFFSET
	int                                                PlaceableGridWidth;                                       // 0x0720(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableGridHeight;                                      // 0x0724(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceablePlugId;                                          // 0x0728(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData27[0x1C0];                                     // 0x0730(0x01C0) MISSED OFFSET
	struct FName                                       PlaceableFactionBuffId;                                   // 0x08F0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableFactionBuffStackCount;                           // 0x08F8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData28[0x24];                                      // 0x08FC(0x0024) MISSED OFFSET
	int                                                PlaceableInventorySlots;                                  // 0x0920(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData29[0x25];                                      // 0x0924(0x0025) MISSED OFFSET
	bool                                               bPlaceableIgnoreFactionUseScore;                          // 0x0949(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData30[0x2];                                       // 0x094A(0x0002) MISSED OFFSET
	int                                                InWorldLimitPerPlayer;                                    // 0x094C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                InWorldLimitPerClan;                                      // 0x0950(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bSpawnsStructure;                                         // 0x0954(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData31[0x23];                                      // 0x0955(0x0023) MISSED OFFSET
	bool                                               bPlaceableStashAccess;                                    // 0x0978(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bPlaceableWarehouseAccess;                                // 0x0979(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bPlaceableIsArmory;                                       // 0x097A(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bPlaceableIsStable;                                       // 0x097B(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bPlaceableIsWeaponModStation;                             // 0x097C(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bCanPlaceOutsideBase;                                     // 0x097D(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bAlwaysExpire;                                            // 0x097E(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESpiritRealmState>                     PlacementRestrictSpiritRealm;                             // 0x097F(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bPlaceableIsPermanent;                                    // 0x0980(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bTransferBeforeDefaults;                                  // 0x0981(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bSkipPlacementPermissionCheck;                            // 0x0982(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData32[0xD];                                       // 0x0983(0x000D) MISSED OFFSET
	bool                                               bCanBePickedUp;                                           // 0x0990(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bRenameable;                                              // 0x0991(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData33[0x26];                                      // 0x0992(0x0026) MISSED OFFSET
	float                                              IsolatedExpirationTimeSeconds;                            // 0x09B8(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData34[0x4];                                       // 0x09BC(0x0004) MISSED OFFSET
	int                                                CraftQueueCount;                                          // 0x09C0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData35[0x4];                                       // 0x09C4(0x0004) MISSED OFFSET
	struct FName                                       PlaceableCraftStatsId;                                    // 0x09C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData36[0x10];                                      // 0x09D0(0x0010) MISSED OFFSET
	float                                              PlaceableWaterStorage;                                    // 0x09E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData37[0x8];                                       // 0x09E4(0x0008) MISSED OFFSET
	float                                              PlaceableMaxHealth;                                       // 0x09EC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableArmor;                                           // 0x09F0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlugArmorAddition;                                        // 0x09F4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData38[0xA0];                                      // 0x09F8(0x00A0) MISSED OFFSET
	TArray<struct FItemPlaceableDefaultData>           PlaceableDefaultPlugs;                                    // 0x0A98(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	unsigned char                                      UnknownData39[0xA8];                                      // 0x0AA8(0x00A8) MISSED OFFSET
	struct FName                                       PlaceableAuraBuffId;                                      // 0x0B50(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData40[0x10];                                      // 0x0B58(0x0010) MISSED OFFSET
	struct FName                                       PlaceableTimedPlayerSpellId;                              // 0x0B68(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableOnHitPlayerSpellId;                              // 0x0B70(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableOnDamagedPlayerSpellId;                          // 0x0B78(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableOnParentDamagedPlayerSpellId;                    // 0x0B80(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableFuseTime;                                        // 0x0B88(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData41[0xC];                                       // 0x0B8C(0x000C) MISSED OFFSET
	struct FName                                       ItemPlaceableUpgradeId;                                   // 0x0B98(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData42[0x28];                                      // 0x0BA0(0x0028) MISSED OFFSET
	TArray<struct FName>                               PlaceableSkillTreeTypeIds;                                // 0x0BC8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	int                                                PlaceableCraftLevel;                                      // 0x0BD8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableCraftLevelMin;                                   // 0x0BDC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData43[0x4];                                       // 0x0BE0(0x0004) MISSED OFFSET
	float                                              PlaceableCraftBreakAdjust;                                // 0x0BE4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableCraftCritAdjust;                                 // 0x0BE8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableCraftTimeScalar;                                 // 0x0BEC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableCraftRecipeScalar;                               // 0x0BF0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData44[0x1C];                                      // 0x0BF4(0x001C) MISSED OFFSET
	struct FName                                       ItemConsumableDataId;                                     // 0x0C10(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData45[0x48];                                      // 0x0C18(0x0048) MISSED OFFSET
	class UAnimMontage*                                FemaleConsumeMontage;                                     // 0x0C60(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleConsumeMontage;                                       // 0x0C68(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData46[0x8];                                       // 0x0C70(0x0008) MISSED OFFSET
	TArray<struct FStatEffectData>                     ConsumableInstantStat;                                    // 0x0C78(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       ConsumableBuffId;                                         // 0x0C88(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ConsumablePlayerAbilityId;                                // 0x0C90(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       LearnedRecipeId;                                          // 0x0C98(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemResourceType>                     ConsumableItemResource;                                   // 0x0CA0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bDontConsume;                                             // 0x0CA1(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData47[0x2];                                       // 0x0CA2(0x0002) MISSED OFFSET
	float                                              ConsumableItemResourceAmount;                             // 0x0CA4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Cooldown;                                                 // 0x0CA8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData48[0xC];                                       // 0x0CAC(0x000C) MISSED OFFSET
	struct FName                                       CooldownGroupId;                                          // 0x0CB8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData49[0x8];                                       // 0x0CC0(0x0008) MISSED OFFSET
	struct FText                                       AmmoShortName;                                            // 0x0CC8(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<EAmmoType>                             AmmoType;                                                 // 0x0CE0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           AmmoDamageType;                                           // 0x0CE1(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData50[0x6];                                       // 0x0CE2(0x0006) MISSED OFFSET
	TArray<struct FDamageConversion>                   AmmoDamageConversions;                                    // 0x0CE8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	float                                              AmmoTrueDamagePercent;                                    // 0x0CF8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoPvpTrueDamagePercent;                                 // 0x0CFC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoUnitDamage;                                           // 0x0D00(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoUnitPvpDamage;                                        // 0x0D04(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoSiegeDamage;                                          // 0x0D08(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoSpreadModifier;                                       // 0x0D0C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData51[0x110];                                     // 0x0D10(0x0110) MISSED OFFSET
	TEnumAsByte<EEquipSlot>                            EquipSlot;                                                // 0x0E20(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData52[0x57];                                      // 0x0E21(0x0057) MISSED OFFSET
	bool                                               bEquipBuffOnlyWhenHeld;                                   // 0x0E78(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData53[0x7];                                       // 0x0E79(0x0007) MISSED OFFSET
	struct FName                                       EquipBuffId;                                              // 0x0E80(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EquipTemperature;                                         // 0x0E88(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bEquipStatOnlyWhenHeld;                                   // 0x0E8C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData54[0x3];                                       // 0x0E8D(0x0003) MISSED OFFSET
	TArray<struct FStatEffectData>                     EquipStat;                                                // 0x0E90(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	unsigned char                                      UnknownData55[0x398];                                     // 0x0EA0(0x0398) MISSED OFFSET
	TEnumAsByte<EEquipSlot>                            ModEquipSlot;                                             // 0x1238(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EHeldItemType>                         ModHeldItemType;                                          // 0x1239(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData56[0x86];                                      // 0x123A(0x0086) MISSED OFFSET
	struct FName                                       ModBuffId;                                                // 0x12C0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemRepairId;                                             // 0x12C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FItemRepairData                             RepairData;                                               // 0x12D0(0x0038) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	float                                              RepairStationMultiplier;                                  // 0x1308(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData57[0x4];                                       // 0x130C(0x0004) MISSED OFFSET
	struct FName                                       FieldKitItemAffectDurabilityId;                           // 0x1310(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FItemAffectDurabilityData                   FieldKitData;                                             // 0x1318(0x0038) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData58[0x10];                                      // 0x1350(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ItemData");
		return ptr;
	}


	void LoadDrawToScalars();
	bool IsWeapon();
	bool IsServerUnique();
	bool IsRepairTool();
	bool IsRepairKitFor(class UItemData* DamagedItem);
	bool IsPaperdollItem();
	bool IsBuildTool();
	bool IsArmor();
	bool IsAffectedBy(const struct FItemAffectDurabilityData& AffectData);
	bool IsActionBarItem();
	void GetIconPtr();
	class UTexture2D* GetIconAsync();
	class UTexture2D* GetIcon();
	void AsyncLoad();
};


// Class Otherlands.ItemManager
// 0x09A8 (0x09D0 - 0x0028)
class UItemManager : public UObject
{
public:
	TMap<struct FName, class UItemData*>               ItemMap;                                                  // 0x0028(0x0050) (ZeroConstructor)
	class UDataTable*                                  ItemBaseTable;                                            // 0x0078(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0080(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemServerUniqueTable;                                    // 0x00D0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x00D8(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemDamageTable;                                          // 0x0128(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0130(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemBowScalarTable;                                       // 0x0180(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0188(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemHarvestTable;                                         // 0x01D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x50];                                      // 0x01E0(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemDisplayTable;                                         // 0x0230(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x50];                                      // 0x0238(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemPlaceableTable;                                       // 0x0288(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x50];                                      // 0x0290(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemPlaceableCraftStatsTable;                             // 0x02E0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x50];                                      // 0x02E8(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemPlaceableUpgradeTable;                                // 0x0338(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x50];                                      // 0x0340(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemConsumableTable;                                      // 0x0390(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData09[0x50];                                      // 0x0398(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemAmmoTable;                                            // 0x03E8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x50];                                      // 0x03F0(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemEquipTable;                                           // 0x0440(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x50];                                      // 0x0448(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemMontageTable;                                         // 0x0498(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData12[0x50];                                      // 0x04A0(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemModificationTable;                                    // 0x04F0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData13[0x50];                                      // 0x04F8(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemAffixApplicationTable;                                // 0x0548(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData14[0x50];                                      // 0x0550(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemAffixGroupEntryTable;                                 // 0x05A0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData15[0xA0];                                      // 0x05A8(0x00A0) MISSED OFFSET
	class UDataTable*                                  ItemAffixTable;                                           // 0x0648(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData16[0x140];                                     // 0x0650(0x0140) MISSED OFFSET
	class UDataTable*                                  ItemRepairTable;                                          // 0x0790(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData17[0x50];                                      // 0x0798(0x0050) MISSED OFFSET
	class UDataTable*                                  ItemAffectDurabilityTable;                                // 0x07E8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData18[0x50];                                      // 0x07F0(0x0050) MISSED OFFSET
	class UDataTable*                                  InventoryGroupTable;                                      // 0x0840(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData19[0x10];                                      // 0x0848(0x0010) MISSED OFFSET
	class UDataTable*                                  WarehouseTypeTable;                                       // 0x0858(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData20[0x170];                                     // 0x0860(0x0170) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ItemManager");
		return ptr;
	}

};


// Class Otherlands.ItemManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class UItemManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ItemManagerLibrary");
		return ptr;
	}


	struct FWarehouseTypeData STATIC_GetWarehouseTypePage(const struct FName& ID);
	void STATIC_GetWarehousePages(TArray<struct FName>* Results);
	void STATIC_GetWarehouseItems(TArray<struct FName>* Results);
	int STATIC_GetWarehouseItemIndex(const struct FName& ItemId);
	void STATIC_GetWarehouseItemIdsByDataTier(const struct FName& ID, int Tier, TArray<struct FName>* Results);
	struct FName STATIC_GetWarehouseDataIdByType(TEnumAsByte<EItemType> ItemType);
	TArray<struct FName> STATIC_GetUnlockedItemPlaceableUpgradeByCraftResearchId(const struct FName& ID);
	TArray<struct FName> STATIC_GetUnlockedItemAffixByCraftResearchId(const struct FName& ID);
	void STATIC_GetPlaceableUpgradeReagents(const struct FItemPlaceableUpgradeData& UpgradeData, TArray<struct FName>* OutReagentItemIds, TArray<int>* OutReagentCounts);
	struct FItemRepairData STATIC_GetItemRepairData(const struct FName& ID);
	struct FName STATIC_GetItemPlaceableUpgradeIdByType(TEnumAsByte<EPlaceableMaterial> PlaceableMaterial, TEnumAsByte<EStructureType> StructureType);
	struct FItemPlaceableUpgradeData STATIC_GetItemPlaceableUpgradeData(const struct FName& ID);
	struct FItemPlaceableCraftStatsData STATIC_GetItemPlaceableCraftStatsData(const struct FName& ID);
	class UItemData* STATIC_GetItemData(const struct FName& ID);
	struct FItemBaseData STATIC_GetItemBaseData(const struct FName& ItemId);
	struct FItemAffixData STATIC_GetItemAffixData(const struct FName& ID);
	struct FName STATIC_GetItemAffixApplicationDataImplicitItemAffixId(const struct FItemAffixApplicationData& Data, int Index);
	struct FItemAffixApplicationData STATIC_GetItemAffixApplicationData(const struct FName& ID);
};


// Class Otherlands.ItemSagaVaultLibrary
// 0x0000 (0x0028 - 0x0028)
class UItemSagaVaultLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ItemSagaVaultLibrary");
		return ptr;
	}


	bool STATIC_TakeVaultItemWorld(class UObject* WorldContextObject, const struct FName& ItemId, int StackCount, class UInventoryComponent* Owner);
	bool STATIC_TakeVaultItem(const struct FName& ItemId, int StackCount, class UInventoryComponent* Owner, struct FItemSagaVault* SagaVault);
	bool STATIC_SelectVaultItemWorld(class UObject* WorldContextObject, int SagaPriority, struct FName* OutItemId, int* OutStackCount);
	bool STATIC_SelectVaultItem(const struct FItemSagaVault& SagaVault, int SagaPriority, struct FName* OutItemId, int* OutStackCount);
	void STATIC_ProcessVaultOnLogoff(class UInventoryComponent* Owner);
	void STATIC_InitializeVault(struct FItemSagaVault* SagaVault);
	bool STATIC_DropVaultItemWorld(class UObject* WorldContextObject, const struct FName& ItemId, int StackCount, class UInventoryComponent* Owner);
	bool STATIC_DropVaultItem(const struct FName& ItemId, int StackCount, class UInventoryComponent* Owner, struct FItemSagaVault* SagaVault);
	bool STATIC_ClaimVaultItemWorld(class UObject* WorldContextObject, const struct FName& ItemId, int StackCount, class UInventoryComponent* Owner, class UInventoryComponent* OldOwner);
	bool STATIC_ClaimVaultItem(const struct FName& ItemId, int StackCount, class UInventoryComponent* Owner, class UInventoryComponent* OldOwner, struct FItemSagaVault* SagaVault);
	void STATIC_CheckForReclaimmedVaultItems(class UObject* WorldContextObject, struct FItemSagaVault* SagaVault);
};


// Class Otherlands.JrkConfig
// 0x0050 (0x0088 - 0x0038)
class UJrkConfig : public UDeveloperSettings
{
public:
	struct FJrkTestMasterConfig                        Master;                                                   // 0x0038(0x0020) (Edit)
	struct FTimespan                                   DecayRate;                                                // 0x0058(0x0008) (Edit)
	double                                             Epsilon;                                                  // 0x0060(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             Gamma;                                                    // 0x0068(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                MaxIterations;                                            // 0x0070(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0074(0x0004) MISSED OFFSET
	double                                             PositiveBias;                                             // 0x0078(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             NegativeBias;                                             // 0x0080(0x0008) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.JrkConfig");
		return ptr;
	}

};


// Class Otherlands.JrkManager
// 0x0098 (0x00C0 - 0x0028)
class UJrkManager : public UObject
{
public:
	TArray<struct FPlayerReportData>                   PlayerReports;                                            // 0x0028(0x0010) (ZeroConstructor)
	TArray<struct FBannedPlayerData>                   BannedPlayers;                                            // 0x0038(0x0010) (ZeroConstructor)
	TArray<struct FJrkMember>                          JrkStats;                                                 // 0x0048(0x0010) (ZeroConstructor)
	struct FJrkTestMaster                              Master;                                                   // 0x0058(0x0010)
	unsigned char                                      UnknownData00[0x58];                                      // 0x0068(0x0058) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.JrkManager");
		return ptr;
	}

};


// Class Otherlands.KeyBindingSlotWidget
// 0x0060 (0x0280 - 0x0220)
class UKeyBindingSlotWidget : public UGameBaseWidget
{
public:
	int                                                SlotIndex;                                                // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0224(0x0004) MISSED OFFSET
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0228(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FText                                       ActionText;                                               // 0x0230(0x0018) (Edit, BlueprintVisible)
	struct FText                                       ReplaceKeyBindingText;                                    // 0x0248(0x0018) (Edit, BlueprintVisible)
	struct FText                                       KeyBindText;                                              // 0x0260(0x0018) (Edit, BlueprintVisible)
	bool                                               bIsSelected;                                              // 0x0278(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bEnableRebind;                                            // 0x0279(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsActionMapping;                                         // 0x027A(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x027B(0x0005) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.KeyBindingSlotWidget");
		return ptr;
	}


	void UpdateButtonText();
	void SetColor(bool IsSelected);
	void ResetKey();
	void RebindAxisKey(const struct FInputAxisKeyMapping& NewKey);
	void RebindActionKey(const struct FInputActionKeyMapping& NewKey);
	struct FInputAxisKeyMapping GetSelectedAxisKeyMapping();
	struct FInputActionKeyMapping GetSelectedActionKeyMapping();
	float GetAxisScale();
	struct FName GetActionName();
	void ExclusiveSelect();
};


// Class Otherlands.KeyBindingsMenuWidget
// 0x0050 (0x0270 - 0x0220)
class UKeyBindingsMenuWidget : public UGameBaseWidget
{
public:
	TArray<class UKeyBindingSlotWidget*>               ActionKeyBindingSlotWidgets;                              // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	TArray<class UKeyBindingSlotWidget*>               AxisKeyBindingSlotWidgets;                                // 0x0230(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	class UKeyBindingSlotWidget*                       SelectedKeyBindingSlotWidget;                             // 0x0240(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	ESlateVisibility                                   ServerListVisibility;                                     // 0x0248(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x27];                                      // 0x0249(0x0027) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.KeyBindingsMenuWidget");
		return ptr;
	}


	void Update();
	void SaveKeyBindings();
	void ResetToDefaultKeyBindings();
	int GetNumAxisKeyBindings();
	int GetNumActionKeyBindings();
};


// Class Otherlands.LevelUpWidget
// 0x0010 (0x0230 - 0x0220)
class ULevelUpWidget : public UGameBaseWidget
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0220(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.LevelUpWidget");
		return ptr;
	}


	void OnLevelUp();
	struct FText GetRecipeData(int Index);
	int GetNumUnlockedRecipes();
};


// Class Otherlands.LoginMessagingWidget
// 0x0020 (0x0240 - 0x0220)
class ULoginMessagingWidget : public UGameBaseWidget
{
public:
	struct FText                                       MessagingText;                                            // 0x0220(0x0018) (Edit, BlueprintVisible)
	class UServerListWidget*                           ParentWidget;                                             // 0x0238(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.LoginMessagingWidget");
		return ptr;
	}


	void SetLoginMessagingText(const struct FText& Message);
	void MessageChanged();
};


// Class Otherlands.LootData
// 0x0030 (0x0058 - 0x0028)
class ULootData : public UObject
{
public:
	unsigned char                                      UnknownData00[0x30];                                      // 0x0028(0x0030) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.LootData");
		return ptr;
	}

};


// Class Otherlands.LootManager
// 0x0260 (0x0288 - 0x0028)
class ULootManager : public UObject
{
public:
	TMap<struct FName, class ULootData*>               LootMap;                                                  // 0x0028(0x0050) (ZeroConstructor)
	class UDataTable*                                  LootBaseTable;                                            // 0x0078(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0080(0x0050) MISSED OFFSET
	class UDataTable*                                  LootItemTable;                                            // 0x00D0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x00D8(0x0050) MISSED OFFSET
	class UDataTable*                                  ResourceBaseTable;                                        // 0x0128(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0130(0x0050) MISSED OFFSET
	class UDataTable*                                  ResourceHarvestTable;                                     // 0x0180(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0188(0x0050) MISSED OFFSET
	class UDataTable*                                  ResourceSpawnTable;                                       // 0x01D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x50];                                      // 0x01E0(0x0050) MISSED OFFSET
	class UDataTable*                                  ResourceDisplayTable;                                     // 0x0230(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x50];                                      // 0x0238(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.LootManager");
		return ptr;
	}

};


// Class Otherlands.LootViewer
// 0x0040 (0x0368 - 0x0328)
class ALootViewer : public AActor
{
public:
	struct FName                                       LootId;                                                   // 0x0328(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FLootBaseData                               BaseData;                                                 // 0x0330(0x0028) (Edit, EditConst)
	TArray<struct FLootItemData>                       LootItemData;                                             // 0x0358(0x0010) (Edit, ZeroConstructor, EditConst)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.LootViewer");
		return ptr;
	}


	void LoadLootData(const struct FName& LootId);
};


// Class Otherlands.LootManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class ULootManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.LootManagerLibrary");
		return ptr;
	}


	bool STATIC_GenerateLootRoll(const struct FName& LootId, const struct FLootRollInfo& LootRollInfo, TArray<struct FLootRollResult>* OutLootResults);
};


// Class Otherlands.GameAlienFXSystem
// 0x04E0 (0x0508 - 0x0028)
class UGameAlienFXSystem : public UObject
{
public:
	unsigned char                                      bEnable : 1;                                              // 0x0028(0x0001) (Config)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData01[0x230];                                     // 0x0029(0x0230) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.GameAlienFXSystem.EffectCurves
	unsigned char                                      UnknownData02[0xA0];                                      // 0x0260(0x00A0) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.GameAlienFXSystem.FactionCurves
	TEnumAsByte<EGameAlienFX>                          SystemEffect;                                             // 0x0300(0x0001) (ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0301(0x0007) MISSED OFFSET
	TArray<struct FName>                               Devices;                                                  // 0x0308(0x0010) (ZeroConstructor, Config)
	TArray<TEnumAsByte<EGameAlienFX>>                  DeviceEffects;                                            // 0x0318(0x0010) (ZeroConstructor, Config)
	TArray<struct FName>                               Lights;                                                   // 0x0328(0x0010) (ZeroConstructor, Config)
	TArray<TEnumAsByte<EGameAlienFX>>                  LightEffects;                                             // 0x0338(0x0010) (ZeroConstructor, Config)
	class APlayerCharacter*                            Player;                                                   // 0x0348(0x0008) (ZeroConstructor, IsPlainOldData)
	class UCurveLinearColor*                           ActiveEffectCurves[0xE];                                  // 0x0350(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x118];                                     // 0x03C0(0x0118) MISSED OFFSET
	class UCurveLinearColor*                           ActiveFactionCurves[0x4];                                 // 0x04D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x10];                                      // 0x04F8(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameAlienFXSystem");
		return ptr;
	}

};


// Class Otherlands.MainGameInstance
// 0x0148 (0x01E8 - 0x00A0)
class UMainGameInstance : public UGameInstance
{
public:
	class UAudioComponent*                             MenuMusicAudioComp;                                       // 0x00A0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bNVidiaHighlightsEnabled;                                 // 0x00A8(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x00A9(0x0003) MISSED OFFSET
	struct FVector                                     StructureQuadTreeOrigin;                                  // 0x00AC(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	struct FVector                                     StructureQuadTreeExtents;                                 // 0x00B8(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6C];                                      // 0x00C4(0x006C) MISSED OFFSET
	TArray<struct FStructureQuadTreeNode>              TreeNodePool;                                             // 0x0130(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData02[0x80];                                      // 0x0140(0x0080) MISSED OFFSET
	class UAuthService*                                AuthService;                                              // 0x01C0(0x0008) (ZeroConstructor, IsPlainOldData)
	class UAccountService*                             AccountService;                                           // 0x01C8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UDatabaseService*                            DatabaseService;                                          // 0x01D0(0x0008) (ZeroConstructor, IsPlainOldData)
	class UObjectLibrary*                              ConstructLib;                                             // 0x01D8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UObjectLibrary*                              UILib;                                                    // 0x01E0(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainGameInstance");
		return ptr;
	}


	void UpdateVivoxPosition(class AActor* Actor);
	void SetVivoxOutputVolumeAdjustment(int Value);
	void SetVivoxOuputMuted(bool bSet);
	void SetVivoxInputVolumeAdjustment(int Value);
	void SetVivoxInputMuted(bool bSet);
	class UDatabaseService* GetDatabaseService();
	class UAuthService* GetAuthService();
	class UAccountService* GetAccountService();
};


// Class Otherlands.OnlinePlayerState
// 0x0030 (0x0058 - 0x0028)
class UOnlinePlayerState : public UObject
{
public:
	unsigned char                                      UnknownData00[0x30];                                      // 0x0028(0x0030) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OnlinePlayerState");
		return ptr;
	}

};


// Class Otherlands.MainGameMode
// 0x0550 (0x0960 - 0x0410)
class AMainGameMode : public AGameMode
{
public:
	class UClass*                                      SpiritPortalClass;                                        // 0x0410(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FScriptMulticastDelegate                    OnGameSaving;                                             // 0x0418(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGameLoading;                                            // 0x0428(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGameLoadingDone;                                        // 0x0438(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UGameRemoteAdminCommandComponent*            RemoteAdminComponent;                                     // 0x0448(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              DumpMetricsInterval;                                      // 0x0450(0x0004) (ZeroConstructor, Config, IsPlainOldData)
	int                                                ConnectionMetricLogFlags;                                 // 0x0454(0x0004) (ZeroConstructor, Config, IsPlainOldData)
	float                                              ProfileAndPerfInterval;                                   // 0x0458(0x0004) (ZeroConstructor, Config, IsPlainOldData)
	float                                              DumpProfileInitialDelay;                                  // 0x045C(0x0004) (ZeroConstructor, Config, IsPlainOldData)
	float                                              DumpProfileInterval;                                      // 0x0460(0x0004) (ZeroConstructor, Config, IsPlainOldData)
	float                                              ProfileExtremeFrameTime;                                  // 0x0464(0x0004) (ZeroConstructor, Config, IsPlainOldData)
	bool                                               bAllowFactionLose;                                        // 0x0468(0x0001) (ZeroConstructor, Config, IsPlainOldData)
	bool                                               GlobalAllowCheats;                                        // 0x0469(0x0001) (ZeroConstructor, Config, IsPlainOldData)
	bool                                               DefaultEquipment;                                         // 0x046A(0x0001) (ZeroConstructor, Config, IsPlainOldData)
	bool                                               bSummonAnywhere;                                          // 0x046B(0x0001) (ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x046C(0x0004) MISSED OFFSET
	struct FString                                     UniqueSaveIdOverride;                                     // 0x0470(0x0010) (ZeroConstructor, Config)
	struct FString                                     EditorUsernameOverride;                                   // 0x0480(0x0010) (ZeroConstructor, Config)
	float                                              ServerRegisterDelay;                                      // 0x0490(0x0004) (ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0494(0x0004) MISSED OFFSET
	TArray<struct FString>                             CheatAuthIdWhitelist;                                     // 0x0498(0x0010) (ZeroConstructor, Config)
	TArray<struct FString>                             AdminAuthIdWhitelist;                                     // 0x04A8(0x0010) (ZeroConstructor, Config)
	class UJrkManager*                                 JrkManager;                                               // 0x04B8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UClass*                                      FemalePawnClass;                                          // 0x04C0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UClass*                                      MalePawnClass;                                            // 0x04C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UClass*                                      SaveGameClass;                                            // 0x04D0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x10];                                      // 0x04D8(0x0010) MISSED OFFSET
	TMap<struct FString, class AActor*>                Sleepers;                                                 // 0x04E8(0x0050) (ZeroConstructor)
	TArray<class AFaction*>                            Factions;                                                 // 0x0538(0x0010) (ZeroConstructor)
	TMap<struct FString, class AClan*>                 Clans;                                                    // 0x0548(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData03[0x8];                                       // 0x0598(0x0008) MISSED OFFSET
	TArray<TWeakObjectPtr<class ASpawnEvent>>          EventsOngoing;                                            // 0x05A0(0x0010) (ZeroConstructor)
	class UChatChannel*                                GlobalChatChannel;                                        // 0x05B0(0x0008) (ZeroConstructor, IsPlainOldData)
	class UMonitorComm*                                MonitorComm;                                              // 0x05B8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UMetricsComm*                                MetricsComm;                                              // 0x05C0(0x0008) (ZeroConstructor, IsPlainOldData)
	class AServerGatekeeper*                           ServerGatekeeper;                                         // 0x05C8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x1E0];                                     // 0x05D0(0x01E0) MISSED OFFSET
	TMap<struct FString, TWeakObjectPtr<class APlayerCharacter>> DisconnectedPlayerMap;                                    // 0x07B0(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData05[0x138];                                     // 0x0800(0x0138) MISSED OFFSET
	TArray<class UResourceISMC*>                       ResourceISMCs;                                            // 0x0938(0x0010) (ExportObject, ZeroConstructor)
	TArray<class AResourceSpawnManager*>               ResourceSpawnManagers;                                    // 0x0948(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData06[0x8];                                       // 0x0958(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainGameMode");
		return ptr;
	}


	bool StartGameEndTimer(float EndDelaySeconds);
	void OnSaveAscensionDataForPendingAward(EDatabaseServiceResponse Response);
	void OnGetAscensionDataForPendingAward(EDatabaseServiceResponse Response, const struct FKeyData& KeyData);
	void MC_SetEncumbranceMultiplier(TArray<struct FString> Params);
	struct FDateTime GetServerNowTime();
	struct FTimespan GetServerElapsedTimespan();
	class UMetricsComm* GetMetricsComm();
	float GetGameEndTimeRemaining();
	int GetFactionLimit();
	class AFaction* GetFaction(int FactionId);
	class AClan* GetClan(const struct FString& ClanId);
	class AGroup* CreateNewGroup(class AGamePlayerController* SourcePlayer);
	class AClan* CreateNewClan(const struct FString& ClanName, class AGamePlayerController* SourcePlayer);
	void AwardGameEndAscensionPoints();
};


// Class Otherlands.GameRemoteAdminCommandComponent
// 0x0000 (0x00F0 - 0x00F0)
class UGameRemoteAdminCommandComponent : public UActorComponent
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameRemoteAdminCommandComponent");
		return ptr;
	}


	void Whisper(const struct FString& UniqueSaveId, const struct FString& Message, const struct FString& CommandId);
	void UnbanPlayer(const struct FString& UniqueSaveId, const struct FString& CommandId);
	void TrainJrkStats(const struct FString& CommandId);
	void SetOutcastPlayer(const struct FString& UniqueSaveId, bool bIsOutcast, const struct FString& CommandId);
	void ServerMultiplier(float Multiplier, float Hours, const struct FString& CommandId);
	void ReportJrkStats(const struct FString& CommandId);
	void ReportJrks(float Percent, int TopX, const struct FString& CommandId);
	void PortToStart(const struct FString& UniqueSaveId, const struct FString& CommandId);
	void Port(const struct FString& UniqueSaveId, const struct FString& Location, const struct FString& CommandId);
	void KillServer(const struct FString& CommandId);
	void IsJrk(const struct FString& PlayerName, const struct FString& CommandId);
	void GrantFactionAP(int FactionId, float Amount, const struct FString& CommandId);
	void GrantAP(const struct FString& UniqueSaveId, float Amount, const struct FString& CommandId);
	void GameSummary(const struct FString& CommandId);
	void ForceEarlyVictory(const struct FString& CommandId);
	void FactionBroadcast(int FactionId, const struct FString& Message, const struct FString& CommandId);
	void Delist(const struct FString& CommandId);
	void DeleteCharacter(const struct FString& UniqueSaveId, const struct FString& CommandId);
	void CreateLoot(const struct FString& UniqueSaveId, const struct FName& LootBaseId, int Count, TEnumAsByte<EHarvestType> HarvestType, int QualityThreshold, const struct FString& CommandId);
	void CreateItem(const struct FString& UniqueSaveId, const struct FName& ItemId, int ItemCount, const struct FString& CommandId);
	void ClearOutcastData(const struct FString& UniqueSaveId, const struct FString& CommandId);
	void ChangeServerName(const struct FString& NewServerName, const struct FString& CommandId);
	void Broadcast(const struct FString& Message, const struct FString& CommandId);
	void BanPlayer(const struct FString& UniqueSaveId, const struct FString& Message, int Hours, bool bAccount, const struct FString& CommandId);
	void AddToCollection(const struct FString& UniqueSaveId, const struct FName& CreatureBaseId, int VariantIndex, float Rating, const struct FString& CommandId);
};


// Class Otherlands.MainGameSession
// 0x0000 (0x0340 - 0x0340)
class AMainGameSession : public AGameSession
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainGameSession");
		return ptr;
	}

};


// Class Otherlands.MainGameState
// 0x01D8 (0x0600 - 0x0428)
class AMainGameState : public AGameState
{
public:
	struct FScriptMulticastDelegate                    OnSeasonChanged;                                          // 0x0428(0x0010) (BlueprintVisible, ZeroConstructor, InstancedReference, BlueprintAssignable)
	float                                              StartTimeOfDay;                                           // 0x0438(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DefaultDayLength;                                         // 0x043C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       DefaultWeatherId;                                         // 0x0440(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UMaterialParameterCollection*                GlobalMaterialParameters;                                 // 0x0448(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 FactionLossMaterialCurve;                                 // 0x0450(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FScriptMulticastDelegate                    OnDayNightChange;                                         // 0x0458(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TEnumAsByte<EReckoningStage>                       ReckoningStage;                                           // 0x0468(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0469(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnReckoningStateChange;                                   // 0x0470(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnFactionWin;                                             // 0x0480(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnSoulsDeposited;                                         // 0x0490(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TArray<struct FHighlight>                          Highlights;                                               // 0x04A0(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	class UCurveFloat*                                 CreatureFadeCurve;                                        // 0x04B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CreatureFadeMaterialParameter;                            // 0x04B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundAttenuation*                           DefaultCreatureAttenuation;                               // 0x04C0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x18];                                      // 0x04C8(0x0018) MISSED OFFSET
	float                                              EncumbranceMultiplier;                                    // 0x04E0(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              CraftSpeedMultiplier;                                     // 0x04E4(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              TimeOfDay;                                                // 0x04E8(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              DayLength;                                                // 0x04EC(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       CurrentWeatherId;                                         // 0x04F0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       PreviousWeatherId;                                        // 0x04F8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	float                                              WeatherLerp;                                              // 0x0500(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              WeatherLerpSpeed;                                         // 0x0504(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	struct FSeasonData                                 SeasonData;                                               // 0x0508(0x0008) (BlueprintVisible, Net)
	TArray<struct FFactionScore>                       FactionScore;                                             // 0x0510(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData02[0x10];                                      // 0x0520(0x0010) MISSED OFFSET
	bool                                               bCreativeMode;                                            // 0x0530(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0xCF];                                      // 0x0531(0x00CF) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainGameState");
		return ptr;
	}


	class ASpawnEvent* StartReckoningSpawnEvent(class ABaseHearth* FactionBase, const struct FName& SpawnEventId, const struct FSpawnEventStrength& Strength);
	bool StartReckoning(const struct FName& SpawnEvent, int FactionOverride);
	void OnRep_SeasonData();
	void OnRep_ReckoningStage();
	void OnRep_FactionScore();
	void OnRep_CurrentWeatherId(const struct FName& OldWeatherId);
	void OnReckoningStageBegin_Warning(const struct FTimespan& Duration);
	void OnReckoningStageBegin_Spawns();
	void OnReckoningStageBegin_PVP(float Duration);
	void OnReckoningSpawnEventDone(const struct FSpawnEventDoneData& EventData);
	void OnReckoningDone();
	void OnPlayerCharacterAssignedHandler(class APlayerCharacter* PlayerCharacter);
	void MulticastUpdateTimeOfDay(float InTimeOfDay);
	void MulticastSoulsDeposited(int FactionId, float SoulsDeposited);
	void MulticastFactionWin(int FactionId);
	void MulticastFactionLoss(int FactionId);
	bool IsReckoningActive();
	bool IsNightTime();
	void Initialize();
	void HighlightOccured(EHighlight Highlight);
	float GetWeatherLerp();
	float GetTrailingResearchBonus(const struct FName& ResearchId);
	float GetTimeOfDay();
	struct FDateTime GetServerTime();
	struct FWeatherData GetPreviousWeatherData();
	struct FWeatherData GetCurrentWeatherData();
	void EndReckoning();
	void DropCapturePointShields(int Count);
	void DetermineNextReckoningTime(struct FDateTime* OutNextReckoningDate, struct FTimespan* OutWarningDuration);
	void CalculateReckoningStrength(struct FSpawnEventStrength* OutStrength);
};


// Class Otherlands.MainMenuHUD
// 0x0010 (0x0428 - 0x0418)
class AMainMenuHUD : public AHUD
{
public:
	bool                                               bPlayerInventoryActivated;                                // 0x0418(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0419(0x0007) MISSED OFFSET
	class ULoginMessagingWidget*                       MessagingWidget;                                          // 0x0420(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainMenuHUD");
		return ptr;
	}


	void OnQueuePositionUpdated(int QueuePosition);
	void OnLoginServerSkipped();
	void OnCharacterSelect(const struct FAscensionUnlockSet& Unlocks);
	void OnCharacterPingFailed();
	void OnCharacterPing(const struct FPlayerCharacterProperties& Character, int ServerPing, bool bNeedPassword);
	void OnCharacterExistsSelect(const struct FPlayerCharacterProperties& Character, const struct FAscensionUnlockSet& Unlocks);
	void OnCharacterEnterWorld();
	void InformClient(const struct FText& Message);
	void FoundResults();
};


// Class Otherlands.MenuMessagingWidget
// 0x0018 (0x0238 - 0x0220)
class UMenuMessagingWidget : public UGameBaseWidget
{
public:
	struct FText                                       MessagingText;                                            // 0x0220(0x0018) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MenuMessagingWidget");
		return ptr;
	}


	void CopySteamLink();
	void CopyDiscordLink();
};


// Class Otherlands.MainSaveGame
// 0x0188 (0x01B0 - 0x0028)
class UMainSaveGame : public USaveGame
{
public:
	struct FTimespan                                   ServerElapsedTimespan;                                    // 0x0028(0x0008)
	struct FString                                     SavedMap;                                                 // 0x0030(0x0010) (ZeroConstructor)
	TArray<struct FPlayerSaveData>                     Players;                                                  // 0x0040(0x0010) (ZeroConstructor)
	TMap<struct FString, struct FAccountSaveData>      Accounts;                                                 // 0x0050(0x0050) (ZeroConstructor)
	TArray<struct FStructureSaveData>                  Structures;                                               // 0x00A0(0x0010) (ZeroConstructor)
	TArray<struct FPlaceableSaveData>                  Placeables;                                               // 0x00B0(0x0010) (ZeroConstructor)
	TArray<struct FFactionSaveData>                    Factions;                                                 // 0x00C0(0x0010) (ZeroConstructor)
	TArray<struct FClanSaveData>                       Clans;                                                    // 0x00D0(0x0010) (ZeroConstructor)
	int                                                NextClanId;                                               // 0x00E0(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x00E4(0x0004) MISSED OFFSET
	TArray<struct FControlPointSaveData>               CtrlPoints;                                               // 0x00E8(0x0010) (ZeroConstructor)
	TArray<struct FVehicleSaveData>                    Vehicles;                                                 // 0x00F8(0x0010) (ZeroConstructor)
	TArray<struct FResourceSaveData>                   ResourceStates;                                           // 0x0108(0x0010) (ZeroConstructor)
	TArray<struct FPlayerCorpseSaveData>               Corpses;                                                  // 0x0118(0x0010) (ZeroConstructor)
	struct FItemSagaVaultSaveData                      SagaVault;                                                // 0x0128(0x0020)
	struct FDateTime                                   ServerStartTime;                                          // 0x0148(0x0008)
	float                                              ActiveTimedMultiplier;                                    // 0x0150(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              TimedMultiplierDuration;                                  // 0x0154(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                WinningFactionId;                                         // 0x0158(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              GameEndTimeRemaining;                                     // 0x015C(0x0004) (ZeroConstructor, IsPlainOldData)
	TMap<struct FString, struct FObjectRecord>         ObjectData;                                               // 0x0160(0x0050) (ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainSaveGame");
		return ptr;
	}


	void SaveObject(const struct FString& Name, class UObject* Object);
	class UObject* GetSavedObject(class UObject* Outer, const struct FString& Name);
};


// Class Otherlands.MainJrkSaveGame
// 0x0040 (0x0068 - 0x0028)
class UMainJrkSaveGame : public USaveGame
{
public:
	TArray<struct FBannedPlayerData>                   BannedPlayers;                                            // 0x0028(0x0010) (ZeroConstructor)
	TArray<struct FPlayerReportData>                   PlayerReports;                                            // 0x0038(0x0010) (ZeroConstructor)
	TArray<struct FJrkMember>                          JrkStats;                                                 // 0x0048(0x0010) (ZeroConstructor)
	struct FJrkTestMaster                              JrkMaster;                                                // 0x0058(0x0010)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainJrkSaveGame");
		return ptr;
	}

};


// Class Otherlands.MainEternalSaveGame
// 0x0020 (0x0048 - 0x0028)
class UMainEternalSaveGame : public USaveGame
{
public:
	TArray<struct FEternalPlayerSaveData>              Players;                                                  // 0x0028(0x0010) (ZeroConstructor)
	TArray<struct FPendingSagaAward>                   PendingAwards;                                            // 0x0038(0x0010) (ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MainEternalSaveGame");
		return ptr;
	}

};


// Class Otherlands.MeleeActionComponent
// 0x0028 (0x0158 - 0x0130)
class UMeleeActionComponent : public UActionComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0130(0x0018) MISSED OFFSET
	class APlayerCharacter*                            Player;                                                   // 0x0148(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	float                                              CurrentActionSpeed;                                       // 0x0150(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0154(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MeleeActionComponent");
		return ptr;
	}


	void ServerStartMelee(const struct FMeleeActionParam& SourceParam);
	void ServerMeleeAttack(class UObject* HitObject, const struct FHitResult& HitResult);
	void ServerHarvest(bool bInSecondary, class UObject* ObjectHit, int InstanceIndex, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal, TEnumAsByte<EPhysicalSurface> SurfaceType);
	void ServerAttemptHarvestSpirit(class AAICharacter* SpiritCharacter, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal, TEnumAsByte<EPhysicalSurface> SurfaceType);
};


// Class Otherlands.MenuGameMode
// 0x0078 (0x0488 - 0x0410)
class AMenuGameMode : public AGameMode
{
public:
	struct FString                                     AscensionExportBlob;                                      // 0x0410(0x0010) (BlueprintVisible, ZeroConstructor, Transient)
	struct FAscensionUnlockSet                         CurrUnlockSet;                                            // 0x0420(0x0010) (BlueprintVisible, Transient)
	TArray<struct FString>                             FavoriteServers;                                          // 0x0430(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	int                                                AcceptedEULAVersion;                                      // 0x0440(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	EGameMode                                          DefaultGameMode;                                          // 0x0444(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0445(0x0003) MISSED OFFSET
	class UClass*                                      FemalePawnClass;                                          // 0x0448(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UClass*                                      MalePawnClass;                                            // 0x0450(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UClass*                                      SkeletalMeshActorClass;                                   // 0x0458(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class USoundCue*                                   MenuMusic;                                                // 0x0460(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UMainGameInstance*                           GameInstance;                                             // 0x0468(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class AClientGatekeeper*                           ClientGatekeeper;                                         // 0x0470(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0478(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MenuGameMode");
		return ptr;
	}


	void SetDefaultGameMode(EGameMode PickedGameMode);
	void OnSelectServer(int Index);
	void OnPlayButtonPushed(int Index, const struct FString& ServerPassword);
	bool NeedEULA();
	bool IsFavoriteServer(const struct FString& ServerId);
	bool HasDefaultGameMode();
	class AClientGatekeeper* GetClientGatekeeper();
	void FavoriteServer(bool bAdd, const struct FString& ServerId);
	void Authenticate(const struct FScriptDelegate& Delegate);
	void AcceptEULA();
};


// Class Otherlands.MetricsComm
// 0x0A48 (0x0A70 - 0x0028)
class UMetricsComm : public UObject
{
public:
	struct FString                                     MetricsPrefix;                                            // 0x0028(0x0010) (ZeroConstructor, Config)
	struct FString                                     MetricsEndpoint;                                          // 0x0038(0x0010) (Edit, ZeroConstructor, Config)
	int                                                MetricsPort;                                              // 0x0048(0x0004) (Edit, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0xA24];                                     // 0x004C(0x0A24) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MetricsComm");
		return ptr;
	}


	void SetGaugeFloat(const struct FString& Key, float Value);
	void SetGauge(const struct FString& Key, int Value);
	void IncrementGaugeFloat(const struct FString& Key, float Value);
	void IncrementGauge(const struct FString& Key, int Value);
	void AddTimer(const struct FString& Key, float Value, ETimerMetricUnit Unit, float SampleRate);
	void AddSet(const struct FString& Key, int Value);
	void AddCounter(const struct FString& Key, int Value, float SampleRate);
};


// Class Otherlands.MonitorComm
// 0x0078 (0x00A0 - 0x0028)
class UMonitorComm : public UObject
{
public:
	unsigned char                                      UnknownData00[0x78];                                      // 0x0028(0x0078) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MonitorComm");
		return ptr;
	}


	void MC_GetPlayerList(TArray<struct FString> Params);
};


// Class Otherlands.MountAbilityComponent
// 0x0050 (0x0640 - 0x05F0)
class UMountAbilityComponent : public UAbilityComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x05F0(0x0018) MISSED OFFSET
	bool                                               bUseWindupMontageTimeOut;                                 // 0x0608(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bUseActionMontageTimeOut;                                 // 0x0609(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bAllowMontageEndToTriggerPhase;                           // 0x060A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x060B(0x0005) MISSED OFFSET
	class APlayerCharacter*                            PlayerCharacterOwner;                                     // 0x0610(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	class UAnimMontage*                                ActiveMountMontage;                                       // 0x0618(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	class UAnimMontage*                                ActiveRiderMontage;                                       // 0x0620(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x18];                                      // 0x0628(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MountAbilityComponent");
		return ptr;
	}


	void ServerBeginChargeAbility();
	void OnWindupMontageTimeOut();
	void OnWindupMontageBlendingOut(class UAnimMontage* WindupMontage, bool bInterrupted);
	void OnCastingChargedTimer();
	void OnCastingChargeDone();
	void OnActionMontageTimeOut();
	void OnActionMontageFinished(class UAnimMontage* ActionMontage, bool bInterrupted);
	void MulticastPlayAbilityChargeMontage(float ChargeTime);
	void MulticastPlayAbilityActionMontage(float ActionTime);
	void MulticastForceInitializeMountAbility(const struct FName& InAbilityId);
	bool InitializeMountAbility(const struct FName& InAbilityId);
	float GetStateTimeRemaining();
	class UAnimMontage* GetRiderAbilityWindupMontage();
	class UAnimMontage* GetRiderAbilityChargeLoopMontage();
	class UAnimMontage* GetRiderAbilityActionMontage();
	class UAnimMontage* GetMountAbilityWindupMontage();
	class UAnimMontage* GetMountAbilityChargeLoopMontage();
	class UAnimMontage* GetMountAbilityActionMontage();
	float GetMaxCooldown();
	struct FVector GetFireFrom();
	struct FVector GetFireDirection();
	struct FCreatureAbilityData GetCreatureAbilityData();
	float GetAbilityTimeRemaining();
	void ForcePushInitializeMountAbility();
	struct FCastAction ConstructCastAction(const struct FVector& From, const struct FVector& Direction);
	void ClientStartAbilityCooldown(float Length);
};


// Class Otherlands.MountProxyActor
// 0x00E8 (0x0410 - 0x0328)
class AMountProxyActor : public AActor
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0328(0x0020) MISSED OFFSET
	class UCharacterStats*                             CharacterStats;                                           // 0x0348(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBuffComponent*                              BuffComponent;                                            // 0x0350(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0358(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0360(0x0028) MISSED OFFSET
	TArray<int>                                        BuffCategoryImmunity;                                     // 0x0388(0x0010) (Net, ZeroConstructor, Transient)
	TArray<class UBuffCategoryDelegates*>              BuffCategoryDelegates;                                    // 0x0398(0x0010) (ZeroConstructor, Transient)
	float                                              PetPveOutgoingDamageScalar;                               // 0x03A8(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	float                                              PetPvpOutgoingDamageScalar;                               // 0x03AC(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	float                                              PetPveIncomingDamageScalar;                               // 0x03B0(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	float                                              PetPvpIncomingDamageScalar;                               // 0x03B4(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       CreatureFamilyId;                                         // 0x03B8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x03C0(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.MountProxyActor");
		return ptr;
	}


	void OnTickStatUnpauseTimer(int Index);
	void OnTickStatTimer(int Index);
	void OnRep_PlayerOwner();
	float GetStatValue_Float(TEnumAsByte<ECharacterStat> CharStat);
};


// Class Otherlands.NameplateWidget
// 0x0040 (0x0260 - 0x0220)
class UNameplateWidget : public UGameBaseWidget
{
public:
	struct FText                                       NameplateText;                                            // 0x0220(0x0018) (Edit, BlueprintVisible)
	bool                                               bIsTarget;                                                // 0x0238(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bShouldShowHealth;                                        // 0x0239(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x023A(0x0002) MISSED OFFSET
	float                                              Health;                                                   // 0x023C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxHealth;                                                // 0x0240(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                FontSize;                                                 // 0x0244(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaxFontSize;                                              // 0x0248(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxNameplateDistance;                                     // 0x024C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class APlayerCharacter*                            OwningPlayer;                                             // 0x0250(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   DisplayVisibility;                                        // 0x0258(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   HealthDisplayVisibility;                                  // 0x0259(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x025A(0x0006) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.NameplateWidget");
		return ptr;
	}


	float SetNameplateVisibility();
	int GetOwningPlayerFactionId();
	float GetHealthPercentage();
};


// Class Otherlands.NavArea_LargeSolidMesh
// 0x0000 (0x0048 - 0x0048)
class UNavArea_LargeSolidMesh : public UNavArea
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.NavArea_LargeSolidMesh");
		return ptr;
	}

};


// Class Otherlands.NoPlaceableVolume
// 0x0018 (0x0388 - 0x0370)
class ANoPlaceableVolume : public AGameVolume
{
public:
	bool                                               bAbsolute;                                                // 0x0370(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0371(0x0007) MISSED OFFSET
	TArray<TEnumAsByte<EPlaceableType>>                AllowedTypes;                                             // 0x0378(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.NoPlaceableVolume");
		return ptr;
	}


	bool IsAbsolute();
	TArray<TEnumAsByte<EPlaceableType>> GetAllowedTypes();
};


// Class Otherlands.OptionsMenuWidget
// 0x0020 (0x0240 - 0x0220)
class UOptionsMenuWidget : public UGameBaseWidget
{
public:
	class UAudioSettingsWidget*                        AudioSettings;                                            // 0x0220(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UVideoOptionsWidget*                         VideoSettings;                                            // 0x0228(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UGameplayOptionsWidget*                      GameplayOptions;                                          // 0x0230(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UKeyBindingsMenuWidget*                      KeyBindings;                                              // 0x0238(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OptionsMenuWidget");
		return ptr;
	}


	void SaveAllSettings();
	void GetAllSettings();
};


// Class Otherlands.OtherlandsReplicationGraph
// 0x0358 (0x0548 - 0x01F0)
class UOtherlandsReplicationGraph : public UReplicationGraph
{
public:
	unsigned char                                      UnknownData00[0xA0];                                      // 0x01F0(0x00A0) MISSED OFFSET
	class UOtherlandsReplicationGraphNode_GridSpatialization2D_ConnectionVariation* UnphasedGridNode;                                         // 0x0290(0x0008) (ZeroConstructor, IsPlainOldData)
	class UOtherlandsReplicationGraphNode_GridSpatialization2D_Phase* PhasedGridNode;                                           // 0x0298(0x0008) (ZeroConstructor, IsPlainOldData)
	class UReplicationGraphNode_ActorList*             AlwaysAndBeaconRelevantNode;                              // 0x02A0(0x0008) (ZeroConstructor, IsPlainOldData)
	class UOtherlandsReplicationGraphNode_ActorList_SkipBeacon* AlwaysRelevantNode;                                       // 0x02A8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UOtherlandsReplicationGraphNode_ActorListFrequencyBuckets_SkipBeacon* AlwaysRelevantLimitedNode;                                // 0x02B0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x290];                                     // 0x02B8(0x0290) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OtherlandsReplicationGraph");
		return ptr;
	}

};


// Class Otherlands.OtherlandsReplicationGraphNode_GridSpatialization2D_ConnectionVariation
// 0x0000 (0x01D0 - 0x01D0)
class UOtherlandsReplicationGraphNode_GridSpatialization2D_ConnectionVariation : public UReplicationGraphNode_GridSpatialization2D
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OtherlandsReplicationGraphNode_GridSpatialization2D_ConnectionVariation");
		return ptr;
	}

};


// Class Otherlands.OtherlandsReplicationGraphNode_GridSpatialization2D_Phase
// 0x0090 (0x0130 - 0x00A0)
class UOtherlandsReplicationGraphNode_GridSpatialization2D_Phase : public UReplicationGraphNode
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x00A0(0x0010) MISSED OFFSET
	class UOtherlandsReplicationGraphNode_GridSpatialization2D_ConnectionVariation* ReleventWhileInRealmNode;                                 // 0x00B0(0x0008) (ZeroConstructor, IsPlainOldData)
	class UOtherlandsReplicationGraphNode_GridSpatialization2D_ConnectionVariation* InRealmNode;                                              // 0x00B8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UOtherlandsReplicationGraphNode_GridSpatialization2D_ConnectionVariation* OutRealmNode;                                             // 0x00C0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x68];                                      // 0x00C8(0x0068) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OtherlandsReplicationGraphNode_GridSpatialization2D_Phase");
		return ptr;
	}

};


// Class Otherlands.OtherlandsReplicationGraphNode_AlwaysRelevant_ForConnection
// 0x0060 (0x01B0 - 0x0150)
class UOtherlandsReplicationGraphNode_AlwaysRelevant_ForConnection : public UReplicationGraphNode_ActorList
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0150(0x0010) MISSED OFFSET
	class AActor*                                      LastBeacon;                                               // 0x0160(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      LastController;                                           // 0x0168(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      LastPawn;                                                 // 0x0170(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      LastPet;                                                  // 0x0178(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      LastFaction;                                              // 0x0180(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      LastClan;                                                 // 0x0188(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      LastGroup;                                                // 0x0190(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<class AActor*>                              LastGroupMembers;                                         // 0x0198(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData01[0x8];                                       // 0x01A8(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OtherlandsReplicationGraphNode_AlwaysRelevant_ForConnection");
		return ptr;
	}

};


// Class Otherlands.OtherlandsReplicationGraphNode_ActorList_SkipBeacon
// 0x0000 (0x0150 - 0x0150)
class UOtherlandsReplicationGraphNode_ActorList_SkipBeacon : public UReplicationGraphNode_ActorList
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OtherlandsReplicationGraphNode_ActorList_SkipBeacon");
		return ptr;
	}

};


// Class Otherlands.OtherlandsReplicationGraphNode_ActorListFrequencyBuckets_SkipBeacon
// 0x0000 (0x0180 - 0x0180)
class UOtherlandsReplicationGraphNode_ActorListFrequencyBuckets_SkipBeacon : public UReplicationGraphNode_ActorListFrequencyBuckets
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.OtherlandsReplicationGraphNode_ActorListFrequencyBuckets_SkipBeacon");
		return ptr;
	}

};


// Class Otherlands.PerkArchetype
// 0x0020 (0x0048 - 0x0028)
class UPerkArchetype : public UObject
{
public:
	TArray<int>                                        PerkPoints;                                               // 0x0028(0x0010) (Net, ZeroConstructor)
	int                                                MaxRowIndex;                                              // 0x0038(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ECharacterArchetype>                   Archetype;                                                // 0x003C(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x003D(0x0003) MISSED OFFSET
	class UPerkComponent*                              PerkComp;                                                 // 0x0040(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerkArchetype");
		return ptr;
	}


	void OnRep_UpdatePerkPoints(TArray<int>* OldValues);
};


// Class Otherlands.PerkComponent
// 0x0020 (0x0110 - 0x00F0)
class UPerkComponent : public UActorComponent
{
public:
	bool                                               bWasReset;                                                // 0x00F0(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00F1(0x0007) MISSED OFFSET
	TArray<class UPerkArchetype*>                      PerkArchetypes;                                           // 0x00F8(0x0010) (Net, ZeroConstructor)
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0108(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerkComponent");
		return ptr;
	}


	bool WasReset();
	void ResetAllPoints(bool bResetArchetypes);
	void OnRep_UpdatePerks();
	bool IsRowUnlocked(TEnumAsByte<ECharacterArchetype> Archetype, const struct FName& RowId);
	bool IsPerkUnlocked(const struct FName& PerkId);
	bool IsArchetypeChosen(TEnumAsByte<ECharacterArchetype> InArchetype);
	int GetPointsSpentInPerk(const struct FName& PerkId);
	int GetPointsSpentInArchetype(TEnumAsByte<ECharacterArchetype> InArchetype);
	int GetPointsSpent();
	int GetNumArchetypes();
	int GetMaxRowIndexInArchetype(TEnumAsByte<ECharacterArchetype> InArchetype);
	TEnumAsByte<ECharacterArchetype> GetArchetypeByIndex(int Index);
	void ClearReset();
	bool CanSpendPointInArchetype(TEnumAsByte<ECharacterArchetype> InArchetype);
	bool CanSpendPerkPoint(const struct FName& PerkId);
};


// Class Otherlands.PerkSetChoiceWidget
// 0x0058 (0x0278 - 0x0220)
class UPerkSetChoiceWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  Icon;                                                     // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       PerkToolTipTitle;                                         // 0x0228(0x0018) (Edit, BlueprintVisible)
	struct FText                                       PerkToolTipText;                                          // 0x0240(0x0018) (Edit, BlueprintVisible)
	bool                                               bPerkSlotEnabled;                                         // 0x0258(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0259(0x0007) MISSED OFFSET
	class UPerkSetTreeWidget*                          ParentWidget;                                             // 0x0260(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TEnumAsByte<ECharacterArchetype>                   PerkArchetype;                                            // 0x0268(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0269(0x0007) MISSED OFFSET
	struct FName                                       PerkId;                                                   // 0x0270(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerkSetChoiceWidget");
		return ptr;
	}


	void Update();
	void SetSelected();
	struct FToolTipData GetTooltipData();
	bool ChoosePerk();
};


// Class Otherlands.PerkSetListWidget
// 0x0028 (0x0248 - 0x0220)
class UPerkSetListWidget : public UGameBaseWidget
{
public:
	TArray<class UPerkSetSlotWidget*>                  PerkSetSlotWidgets;                                       // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0230(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerkSetListWidget");
		return ptr;
	}


	void Update();
	struct FName GetSkillId(int Idx);
	int GetNumSkills();
};


// Class Otherlands.PerkSetSlotWidget
// 0x0060 (0x0280 - 0x0220)
class UPerkSetSlotWidget : public UGameBaseWidget
{
public:
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0220(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FText                                       SkillName;                                                // 0x0228(0x0018) (Edit, BlueprintVisible)
	struct FText                                       SkillLevel;                                               // 0x0240(0x0018) (Edit, BlueprintVisible)
	float                                              LevelProgress;                                            // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsSelected;                                              // 0x025C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x025D(0x0003) MISSED OFFSET
	class UTexture2D*                                  SkillIcon;                                                // 0x0260(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       SkillId;                                                  // 0x0268(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SlotIndex;                                                // 0x0270(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0274(0x0004) MISSED OFFSET
	class UPerkSetTreeWidget*                          PerkTreeWidget;                                           // 0x0278(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerkSetSlotWidget");
		return ptr;
	}


	void Update();
	void PopulatePerkTree();
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.PerkSetTreeWidget
// 0x0028 (0x0248 - 0x0220)
class UPerkSetTreeWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  SkillIcon;                                                // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              LevelProgress;                                            // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1C];                                      // 0x022C(0x001C) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerkSetTreeWidget");
		return ptr;
	}


	void Update();
	void PopulateTree(const struct FName& ParentSkillId);
	void OnUpdateChoices();
	void OnPopulateTree();
	void OnPopulateChoices(int SkillLevelRequired, const struct FName& TopPerkId, const struct FName& BotPerkId);
	struct FSecondarySkillPerkSetData GetPerkSet(int Index);
	int GetNumPerkSets();
};


// Class Otherlands.PerksRowWidget
// 0x0038 (0x0258 - 0x0220)
class UPerksRowWidget : public UGameBaseWidget
{
public:
	int                                                PerkRowIndex;                                             // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0224(0x0004) MISSED OFFSET
	TArray<class UPerksSlotWidget*>                    PerksSlotWidgets;                                         // 0x0228(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	struct FText                                       PerksRowDescriptionText;                                  // 0x0238(0x0018) (Edit, BlueprintVisible)
	class UPerksWidget*                                ParentPerksWidget;                                        // 0x0250(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerksRowWidget");
		return ptr;
	}


	void UpdatePerksRow();
};


// Class Otherlands.PerksSlotWidget
// 0x0080 (0x02A0 - 0x0220)
class UPerksSlotWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  Icon;                                                     // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                PointCount;                                               // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x022C(0x0004) MISSED OFFSET
	struct FText                                       PointCountText;                                           // 0x0230(0x0018) (Edit, BlueprintVisible)
	struct FText                                       PerkToolTipTitle;                                         // 0x0248(0x0018) (Edit, BlueprintVisible)
	struct FText                                       PerkToolTipText;                                          // 0x0260(0x0018) (Edit, BlueprintVisible)
	bool                                               bPerkSlotEnabled;                                         // 0x0278(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsArchetypeChosen;                                       // 0x0279(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x027A(0x0006) MISSED OFFSET
	class UPerksRowWidget*                             ParentRowWidget;                                          // 0x0280(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TEnumAsByte<ECharacterArchetype>                   PerkArchetype;                                            // 0x0288(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0289(0x0007) MISSED OFFSET
	struct FName                                       PerkId;                                                   // 0x0290(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                PerkRowIndex;                                             // 0x0298(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x029C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerksSlotWidget");
		return ptr;
	}


	void UpdatePerksSlot();
	void SpendPerkPoint();
	void OnArchetypeNotChosen();
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.PerksWidget
// 0x0058 (0x0278 - 0x0220)
class UPerksWidget : public UGameBaseWidget
{
public:
	TArray<class UPerksRowWidget*>                     PerksRowWidgets;                                          // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	TEnumAsByte<ECharacterArchetype>                   SelectedArchetype;                                        // 0x0230(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0231(0x0003) MISSED OFFSET
	int                                                MaxNumArchetypes;                                         // 0x0234(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                CurNumArchetypes;                                         // 0x0238(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                NumPerkPointsAvailable;                                   // 0x023C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       NumPerkPointsAvailableText;                               // 0x0240(0x0018) (Edit, BlueprintVisible)
	int                                                NumPerkPointsSpent;                                       // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x025C(0x0004) MISSED OFFSET
	struct FText                                       NumPerkPointsSpentText;                                   // 0x0260(0x0018) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PerksWidget");
		return ptr;
	}


	void UpdateArchetypes();
	void ShowConfirmBox(TEnumAsByte<ECharacterArchetype> InArchetype);
	void OnUpdatePerks();
	void OnShowConfirmBox();
	void OnChooseArchetype();
	int GetNumPerkRows();
	int GetNumPerkArchetypes();
};


// Class Otherlands.PlaceableActor
// 0x00A0 (0x03C8 - 0x0328)
class APlaceableActor : public AActor
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0328(0x0020) MISSED OFFSET
	class UInteractiveMeshComponent*                   MainMesh;                                                 // 0x0348(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                FactionId;                                                // 0x0350(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0354(0x0004) MISSED OFFSET
	struct FString                                     OwnerId;                                                  // 0x0358(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)
	struct FString                                     ClanId;                                                   // 0x0368(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor)
	class APlaceableStructure*                         OwningStructure;                                          // 0x0378(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	struct FString                                     CustomPlaceableName;                                      // 0x0380(0x0010) (Net, ZeroConstructor)
	bool                                               bWasDestroyed;                                            // 0x0390(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0xF];                                       // 0x0391(0x000F) MISSED OFFSET
	struct FTimerHandle                                ExplosiveTimer;                                           // 0x03A0(0x0008) (BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData03[0x20];                                      // 0x03A8(0x0020) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableActor");
		return ptr;
	}


	void OnStructureSyncDone();
	void OnRep_OwningStructure();
	void OnRep_FactionId();
	void OnInitializationComplete(bool bFromLoad);
	void OnActiveStateChange(bool bIsActive);
	void NotifyOnMeshSetItem();
	void NotifyOnExplosiveTimer();
	void MulticastOnDestroy(class UDestructibleMesh* Destructible, class USoundCue* DestructionSound, const struct FTransform& Transform, float ImpulseForce, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal);
	void MulticastHideOnDestroy();
	struct FString GetCustomPlaceableName();
	void ClearExplosiveTimer();
};


// Class Otherlands.PlaceableBlueprintActor
// 0x0000 (0x03C8 - 0x03C8)
class APlaceableBlueprintActor : public APlaceableActor
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableBlueprintActor");
		return ptr;
	}


	float TakePointDamageOfTypeMeshOverride(const struct FTypedDamage& TypedDamage, const struct FHitResult& HitInfo, const struct FVector& ShotDirection, class AController* EventInstigator, class AActor* DamageCauser, bool* bOutHandled);
	bool OnInteractMeshOverride(class ABasicCharacter* Character, bool* bOutHandled);
	TEnumAsByte<ETargetType> GetTargetTypeOverride();
	float GetInteractScoreOverride();
	int GetFactionIdOverride();
	bool GetAllowedActionsOverride(class ABasicCharacter* InCharacter, TArray<struct FName>* OutActions);
	TEnumAsByte<ECanInteractType> CanInteractMeshOverride(class ABasicCharacter* Character, bool* bOutHandled);
	bool CanBeSeenFromOverride(const struct FVector& ObserverLocation, class AActor* IgnoreActor, struct FVector* OutSeenLocation, int* NumberOfLoSChecksPerformed, float* OutSightStrength);
};


// Class Otherlands.PlaceableAnimInstance
// 0x0010 (0x0370 - 0x0360)
class UPlaceableAnimInstance : public UAnimInstance
{
public:
	class UInteractiveMeshComponent*                   MeshComponentOwner;                                       // 0x0360(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0368(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableAnimInstance");
		return ptr;
	}

};


// Class Otherlands.PlaceableMeshOwnerInterface
// 0x0000 (0x0028 - 0x0028)
class UPlaceableMeshOwnerInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableMeshOwnerInterface");
		return ptr;
	}

};


// Class Otherlands.PlaceableSocketManager
// 0x0108 (0x0130 - 0x0028)
class UPlaceableSocketManager : public UObject
{
public:
	class UDataTable*                                  PlaceableSocketTable;                                     // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0030(0x0050) MISSED OFFSET
	class UDataTable*                                  PlaceablePlugTable;                                       // 0x0080(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0088(0x0050) MISSED OFFSET
	class UDataTable*                                  PlaceablePlugSocketTable;                                 // 0x00D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x00E0(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableSocketManager");
		return ptr;
	}

};


// Class Otherlands.StructureOwnedPlaceableInterface
// 0x0000 (0x0028 - 0x0028)
class UStructureOwnedPlaceableInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.StructureOwnedPlaceableInterface");
		return ptr;
	}


	bool IsStructureOwned();
	bool IsAttachedToStructure();
	class APlaceableStructure* GetOwningStructure();
	class UPlaceableStructureComponent* GetAttachedStructure();
};


// Class Otherlands.PlaceableStructure
// 0x0350 (0x0678 - 0x0328)
class APlaceableStructure : public AActor
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0328(0x0008) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnSyncDoneDelegate;                                       // 0x0330(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0340(0x0004) MISSED OFFSET
	struct FStructureGrid                              StructureGrid;                                            // 0x0344(0x0068) (Net)
	unsigned char                                      UnknownData02[0x4];                                       // 0x03AC(0x0004) MISSED OFFSET
	struct FStructurePermissions                       StructurePermissions;                                     // 0x03B0(0x0070) (Net)
	bool                                               bDestroyed;                                               // 0x0420(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bDynamic;                                                 // 0x0421(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x6];                                       // 0x0422(0x0006) MISSED OFFSET
	TArray<struct FStructureGridReplicationData>       GridReplicationData;                                      // 0x0428(0x0010) (ZeroConstructor)
	TArray<struct FStructurePlugReplicationData>       PlugReplicationData;                                      // 0x0438(0x0010) (ZeroConstructor)
	class USceneComponent*                             SceneComponent;                                           // 0x0448(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class APlaceableStructureContainer*                Container;                                                // 0x0450(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UStaticMeshComponent*                        GridEdgeLocationTestComponent;                            // 0x0458(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData04[0x218];                                     // 0x0460(0x0218) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableStructure");
		return ptr;
	}


	void UpdatePermissions(const struct FStructurePermissions& NewPermissions);
	void UpdateGrid(const struct FStructureGrid& NewGrid);
	void SetContainer(class APlaceableStructureContainer* NewContainer, const struct FStructureGrid& InitialGrid, const struct FStructurePermissions& InitialPermissions);
	bool PlayerHasPermissionWithOverride(class APlayerCharacter* Player, TEnumAsByte<EPermission_CodeMap> Action, const struct FName& OptionalActionId);
	bool PlayerHasPermissionById(class APlayerCharacter* Player, const struct FName& ActionId);
	bool PlayerHasPermission(class APlayerCharacter* Player, TEnumAsByte<EPermission_CodeMap> Action);
	void OnRep_StructureGrid();
	void MulticastUpdateUpgradeState(int GridMapId, const struct FName& ItemId, int Count);
	void MulticastUpdatePlugHealth(TArray<struct FPlugHealthUpdate> PlugHealthUpdates);
	void MulticastUpdatePlug(int GridMapId, const struct FName& ItemId, uint32_t NetGUID, const struct FName& TargetSocketName, const struct FName& PlugSocketName, float Health, bool bActivated);
	void MulticastUpdateGridSlot(TArray<struct FUpdatedGridSlotData> GridSlotData);
	void MulticastUpdateComponentHealth(TArray<int> GridMapIds, TArray<int> DamagedIds, TArray<float> HealthValues);
	void MulticastOnDestroyComponent(TArray<struct FDestroyedComponentData> DestroyedComponentData);
	void MulticastActivatePlug(int GridMapId, const struct FName& TargetSocketName, bool bActivated, int YawModifier);
	bool IsStructureDestroyed();
	struct FStructureGrid GetStructureGrid();
	float GetDistanceFromBase(const struct FVector& Point);
	class APlaceableStructure* STATIC_FindContainingStructureInRange(class UObject* WorldContextObj, const struct FVector& Location, float Radius);
	class APlaceableStructure* STATIC_FindContainingStructure(class UObject* WorldContextObj, const struct FVector& Location);
	void EditPermissions(TArray<struct FName> NewPermissionGroupLevelIds);
	struct FStructurePermissions BP_GetStructurePermissions();
};


// Class Otherlands.PlaceableStructureComponent
// 0x0040 (0x07C0 - 0x0780)
class UPlaceableStructureComponent : public UPlaceableMeshComponent
{
public:
	TArray<bool>                                       AttackSpaces;                                             // 0x0780(0x0010) (ZeroConstructor)
	class UPlayerSpawnComponent*                       PlayerSpawn;                                              // 0x0790(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0798(0x0028) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableStructureComponent");
		return ptr;
	}

};


// Class Otherlands.PlaceableStructurePlug
// 0x00B0 (0x0870 - 0x07C0)
class UPlaceableStructurePlug : public UPlaceableStructureComponent
{
public:
	class UMaterialInstanceDynamic*                    ForceFieldDynamicMaterial;                                // 0x07C0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xA8];                                      // 0x07C8(0x00A8) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceableStructurePlug");
		return ptr;
	}

};


// Class Otherlands.PlaceActionComponent
// 0x0018 (0x0148 - 0x0130)
class UPlaceActionComponent : public UActionComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0130(0x0010) MISSED OFFSET
	class APlayerCharacter*                            Player;                                                   // 0x0140(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlaceActionComponent");
		return ptr;
	}


	void ServerReplaceInStructure(class UPlaceableStructureComponent* StructureComponent);
	void ServerPlaceVehicle(const struct FTransform& SpawnTransform);
	void ServerPlaceStandalone(const struct FTransform& SpawnTransform, class UObject* TargetObject);
	void ServerPlacePlug(class UPlaceableMeshComponent* MeshTarget, const struct FName& TargetSocketName, const struct FName& PlugSocketName);
	void ServerPlaceInStructure(class APlaceableStructure* Structure, const struct FIntVector& GridIndex, TEnumAsByte<EStructureEdge> StructureEdge, bool bFlipped);
	void ServerPlaceBuilding(class UBuildingAnchorComponent* BuildingAnchor);
};


// Class Otherlands.PlayAreaVolume
// 0x0058 (0x03C8 - 0x0370)
class APlayAreaVolume : public AGameVolume
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x0370(0x0058) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayAreaVolume");
		return ptr;
	}


	int GlobalToBucketId(const struct FVector& GlobalPoint);
	struct FVector BucketIdToGlobal(int BucketId, float GlobalZ);
};


// Class Otherlands.VolumeAtPointProxy
// 0x0038 (0x0068 - 0x0030)
class UVolumeAtPointProxy : public UBlueprintAsyncActionBase
{
public:
	struct FScriptMulticastDelegate                    LoopBody;                                                 // 0x0030(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    Completed;                                                // 0x0040(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UObject*                                     WorldContext;                                             // 0x0050(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     TestPoint;                                                // 0x0058(0x000C) (IsPlainOldData)
	TEnumAsByte<EAoiAwareType>                         AoiAwareType;                                             // 0x0064(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bBroken;                                                  // 0x0065(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0066(0x0002) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.VolumeAtPointProxy");
		return ptr;
	}


	class UVolumeAtPointProxy* STATIC_ForEachVolumeByTypeAtPoint(class UObject* WorldContextObject, TEnumAsByte<EAoiAwareType> AwareType, const struct FVector& Point);
	class UVolumeAtPointProxy* STATIC_ForEachVolumeAtPoint(class UObject* WorldContextObject, const struct FVector& Point);
	void Break();
};


// Class Otherlands.PlayerInRangeProxy
// 0x0040 (0x0070 - 0x0030)
class UPlayerInRangeProxy : public UBlueprintAsyncActionBase
{
public:
	struct FScriptMulticastDelegate                    LoopBody;                                                 // 0x0030(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    Completed;                                                // 0x0040(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UObject*                                     WorldContext;                                             // 0x0050(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     TestPoint;                                                // 0x0058(0x000C) (IsPlainOldData)
	float                                              TestRange;                                                // 0x0064(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bBroken;                                                  // 0x0068(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0069(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerInRangeProxy");
		return ptr;
	}


	class UPlayerInRangeProxy* STATIC_ForEachPlayerInRange(class UObject* WorldContextObject, const struct FVector& Point, float Range);
	void Break();
};


// Class Otherlands.AiInRangeProxy
// 0x0040 (0x0070 - 0x0030)
class UAiInRangeProxy : public UBlueprintAsyncActionBase
{
public:
	struct FScriptMulticastDelegate                    LoopBody;                                                 // 0x0030(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    Completed;                                                // 0x0040(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UObject*                                     WorldContext;                                             // 0x0050(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     TestPoint;                                                // 0x0058(0x000C) (IsPlainOldData)
	float                                              TestRange;                                                // 0x0064(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bBroken;                                                  // 0x0068(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0069(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.AiInRangeProxy");
		return ptr;
	}


	class UAiInRangeProxy* STATIC_ForEachAiInRange(class UObject* WorldContextObject, const struct FVector& Point, float Range);
	void Break();
};


// Class Otherlands.PlayAreaLibrary
// 0x0000 (0x0028 - 0x0028)
class UPlayAreaLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayAreaLibrary");
		return ptr;
	}


	class AAoiAwareVolume* STATIC_FindFirstVolumeByTypeAtPoint(class UObject* WorldContextObject, TEnumAsByte<EAoiAwareType> AwareType, const struct FVector& Point, class UClass* AoiAwareVolumeClass);
};


// Class Otherlands.PlayerAbilityComponent
// 0x0080 (0x0670 - 0x05F0)
class UPlayerAbilityComponent : public UAbilityComponent
{
public:
	TWeakObjectPtr<class UInventoryItem>               NextSourceItem;                                           // 0x05F0(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	TWeakObjectPtr<class UBuffData>                    NextSourceBuff;                                           // 0x05F8(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	TWeakObjectPtr<class UObject>                      NextTarget;                                               // 0x0600(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0608(0x0018) MISSED OFFSET
	bool                                               bUseWindupMontageTimeOut;                                 // 0x0620(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bUseActionMontageTimeOut;                                 // 0x0621(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bAllowMontageEndToTriggerPhase;                           // 0x0622(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EPlayerAbilitySource>                  AbilitySource;                                            // 0x0623(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bHasSourceItem;                                           // 0x0624(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0625(0x0003) MISSED OFFSET
	TWeakObjectPtr<class UInventoryItem>               CurrentSourceItem;                                        // 0x0628(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	TWeakObjectPtr<class UBuffData>                    CurrentSourceBuff;                                        // 0x0630(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	TWeakObjectPtr<class UObject>                      CurrentTarget;                                            // 0x0638(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       InteractActionId;                                         // 0x0640(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	class APlayerCharacter*                            PlayerCharacterOwner;                                     // 0x0648(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	class UAnimMontage*                                ActiveMontage;                                            // 0x0650(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x18];                                      // 0x0658(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerAbilityComponent");
		return ptr;
	}


	bool ShouldCastHere();
	void ServerBeginChargeAbility(class UInventoryItem* InNextSourceItem);
	bool PostPhaseStartCooldown(int Phase);
	void OnWindupMontageTimeOut();
	void OnWindupMontageBlendingOut(class UAnimMontage* WindupMontage, bool bInterrupted);
	void OnCastingChargedTimer();
	void OnCastingChargeDone();
	void OnActionMontageTimeOut();
	void OnActionMontageFinished(class UAnimMontage* ActionMontage, bool bInterrupted);
	void MulticastStopChargeMontage();
	void MulticastPlayAbilityChargeMontage(float ChargeTime);
	void MulticastPlayAbilityActionMontage(float ActionTime);
	void MulticastForceInitializePlayerAbility(const struct FName& InAbilityId, TEnumAsByte<EPlayerAbilitySource> InSource);
	bool InitializePlayerAbility(const struct FName& InAbilityId, TEnumAsByte<EPlayerAbilitySource> InSource);
	float GetStateTimeRemaining();
	struct FPlayerAbilityData GetPlayerAbilityData();
	float GetMaxCooldown();
	struct FVector GetFireFrom();
	struct FVector GetFireDirection();
	class UAnimMontage* GetAbilityWindupMontage();
	float GetAbilityTimeRemaining();
	class UAnimMontage* GetAbilityChargeLoopMontage();
	class UAnimMontage* GetAbilityActionMontage();
	void ForcePushInitializePlayerAbility();
	struct FCastAction ConstructCastAction(const struct FVector& From, const struct FVector& Direction);
	void ClientStartAbilityCooldown(float Length);
};


// Class Otherlands.PlayerCharacter
// 0x1060 (0x1D00 - 0x0CA0)
class APlayerCharacter : public ABasicCharacter
{
public:
	unsigned char                                      UnknownData00[0xA0];                                      // 0x0CA0(0x00A0) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnInventoryUpdate;                                        // 0x0D40(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnStatUpdate;                                             // 0x0D50(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDodgeUpdate;                                            // 0x0D60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnVisitedZonesUpdated;                                    // 0x0D70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	float                                              DodgeImpulseMagnitude;                                    // 0x0D80(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DodgeDuration;                                            // 0x0D84(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 DodgeFrictionCurve;                                       // 0x0D88(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DodgeMaxAcceleration;                                     // 0x0D90(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC];                                       // 0x0D94(0x000C) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnHeldItemUpdate;                                         // 0x0DA0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnFactionSet;                                             // 0x0DB0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTechTreeSet;                                            // 0x0DC0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanSet;                                                // 0x0DD0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClanCleared;                                            // 0x0DE0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupSet;                                               // 0x0DF0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGroupCleared;                                           // 0x0E00(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPersonalWaypointUpdated;                                // 0x0E10(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClipUpdate;                                             // 0x0E20(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnXPUpdate;                                               // 0x0E30(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnUpgradeStateReceived;                                   // 0x0E40(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnConsumeItemEvent;                                       // 0x0E50(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAcquireItemEvent;                                       // 0x0E60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnLoseItemEvent;                                          // 0x0E70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMotionStateChangeEvent;                                 // 0x0E80(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnJumpEvent;                                              // 0x0E90(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnZoneChangeEvent;                                        // 0x0EA0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDepositSpiritsEvent;                                    // 0x0EB0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnChangeHeldItemEvent;                                    // 0x0EC0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDrinkEvent;                                             // 0x0ED0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnFillEvent;                                              // 0x0EE0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnHarvestEvent;                                           // 0x0EF0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnHarvestRewardedEvent;                                   // 0x0F00(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnHarvestDepletedEvent;                                   // 0x0F10(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnSalvageItemEvent;                                       // 0x0F20(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDecayItemEvent;                                         // 0x0F30(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnBuildStructureEvent;                                    // 0x0F40(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnUpgradeStructureEvent;                                  // 0x0F50(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPlacePlaceableEvent;                                    // 0x0F60(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDestroyPlaceableEvent;                                  // 0x0F70(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnEnterBaseEvent;                                         // 0x0F80(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnLeaveBaseEvent;                                         // 0x0F90(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAdsEnterEvent;                                          // 0x0FA0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnAdsExitEvent;                                           // 0x0FB0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftRecipeXpEvent;                                     // 0x0FC0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftRecipeSkilledEvent;                                // 0x0FD0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCraftRecipeMasteredEvent;                               // 0x0FE0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnLevelUpEvent;                                           // 0x0FF0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnXpChangedEvent;                                         // 0x1000(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnSecondarySkillLevelUpEvent;                             // 0x1010(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnGainAscensionEvent;                                     // 0x1020(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTameProgressEvent;                                      // 0x1030(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTameSuccessEvent;                                       // 0x1040(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTameFailEvent;                                          // 0x1050(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnMountEvent;                                             // 0x1060(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnDismountEvent;                                          // 0x1070(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnPetStateChangedEvent;                                   // 0x1080(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnTempoEvent;                                             // 0x1090(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnClaimBountyEvent;                                       // 0x10A0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnWeaponFullyDrawnEvent;                                  // 0x10B0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnWeaponStartDrawEvent;                                   // 0x10C0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnSecondarySkillLevel;                                    // 0x10D0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData02[0x150];                                     // 0x10E0(0x0150) MISSED OFFSET
	class USoundCue*                                   GatherFailSound;                                          // 0x1230(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   GatherWaterSound;                                         // 0x1238(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   ItemBreakSound;                                           // 0x1240(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   ItemDropSound;                                            // 0x1248(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSEnterSpeed;                                            // 0x1250(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSExitSpeed;                                             // 0x1254(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USceneComponent*                             AimPoint;                                                 // 0x1258(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	class USceneComponent*                             CameraRecoilControl;                                      // 0x1260(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	float                                              GlobalRecoilPitchScalar;                                  // 0x1268(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              GlobalRecoilYawScalar;                                    // 0x126C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              GlobalRecoilDurationScalar;                               // 0x1270(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RecoilCameraDampening;                                    // 0x1274(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TrueAimDistance;                                          // 0x1278(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TargetUnderReticleDistance;                               // 0x127C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTrueAimActive;                                           // 0x1280(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x1281(0x0003) MISSED OFFSET
	struct FVector                                     TrueAimPoint;                                             // 0x1284(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, EditConst, IsPlainOldData)
	TWeakObjectPtr<class AActor>                       ActorUnderReticle;                                        // 0x1290(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	class UAnimMontage*                                DrinkMontage;                                             // 0x1298(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              EntropyLootScore;                                         // 0x12A0(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                EntropyLootRewardCount;                                   // 0x12A4(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 EntropyLootMaxScore;                                      // 0x12A8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EntropyLootMaxChance;                                     // 0x12B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x12B4(0x0004) MISSED OFFSET
	TArray<struct FName>                               VisitedZones;                                             // 0x12B8(0x0010) (Net, ZeroConstructor)
	struct FName                                       SleeperPlaceableItemId;                                   // 0x12C8(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<struct FLimitedPlaceableCount>              LimitedPlaceableCounts;                                   // 0x12D0(0x0010) (Net, ZeroConstructor)
	TEnumAsByte<ESpiritRealmState>                     LastDeathRealm;                                           // 0x12E0(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x17];                                      // 0x12E1(0x0017) MISSED OFFSET
	float                                              QueueLeniencyTimeRemaining;                               // 0x12F8(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	float                                              TotalPlayTime;                                            // 0x12FC(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FDateTime                                   LastPlayStartTime;                                        // 0x1300(0x0008) (Net, Transient)
	float                                              SameFactionTargetTime;                                    // 0x1308(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bTreatAsHostileCache;                                     // 0x130C(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData06[0x3];                                       // 0x130D(0x0003) MISSED OFFSET
	struct FCharacterDeathEventData                    LastDeathEventData;                                       // 0x1310(0x0038)
	struct FCharacterDamageEventData                   LastDamageEventData;                                      // 0x1348(0x0038)
	unsigned char                                      UnknownData07[0x10];                                      // 0x1380(0x0010) MISSED OFFSET
	class UActionComponent*                            ActiveAction;                                             // 0x1390(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UActionComponent*                            LastClearAction;                                          // 0x1398(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UActionComponent*                            QueuedAction;                                             // 0x13A0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UChooseItemActionComponent*                  ChooseItemAction;                                         // 0x13A8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UMeleeActionComponent*                       MeleeAction;                                              // 0x13B0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class URangedAttackActionComponent*                RangedAction;                                             // 0x13B8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UPlaceActionComponent*                       PlaceAction;                                              // 0x13C0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UVehicleActionComponent*                     VehicleAction;                                            // 0x13C8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USpellCastActionComponent*                   SpellCastAction;                                          // 0x13D0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData08[0x8];                                       // 0x13D8(0x0008) MISSED OFFSET
	class AGamePlayerController*                       PlayerController;                                         // 0x13E0(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UInventoryComponent*                         Inventory;                                                // 0x13E8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UInventoryComponent*                         ActionBar;                                                // 0x13F0(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UInventoryComponent*                         Paperdoll;                                                // 0x13F8(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UInventoryComponent*                         Stash;                                                    // 0x1400(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UInventoryComponent*                         PetInventory;                                             // 0x1408(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UHeldItemComponent*                          HeldItemComp;                                             // 0x1410(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UCraftComponent*                             CraftComponent;                                           // 0x1418(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAscensionPerkComponent*                     AscensionPerkComponent;                                   // 0x1420(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UPerkComponent*                              PerkComponent;                                            // 0x1428(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USecondarySkillComponent*                    SecondarySkillComponent;                                  // 0x1430(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkillTreeComponent*                         SkillTreeComponent;                                       // 0x1438(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USpellBookComponent*                         SpellBookComponent;                                       // 0x1440(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USummonCollectionComponent*                  SummonCollectionComponent;                                // 0x1448(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    SprintBuffParticleSystem;                                 // 0x1450(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    SprintParticlesCom;                                       // 0x1458(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              SprintTime;                                               // 0x1460(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData09[0x4];                                       // 0x1464(0x0004) MISSED OFFSET
	class URemoteCraftComponent*                       RemoteCraftComponent;                                     // 0x1468(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<class UPlayerAbilityComponent*>             AbilityComponents;                                        // 0x1470(0x0010) (ExportObject, ZeroConstructor)
	TArray<class UMountAbilityComponent*>              MountAbilityComponents;                                   // 0x1480(0x0010) (ExportObject, ZeroConstructor)
	class USkeletalMesh*                               BaseMesh;                                                 // 0x1490(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkeletalMesh*                               HeadMesh;                                                 // 0x1498(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkeletalMesh*                               ChestMesh;                                                // 0x14A0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkeletalMesh*                               HandsMesh;                                                // 0x14A8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkeletalMesh*                               LegsMesh;                                                 // 0x14B0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkeletalMesh*                               FeetMesh;                                                 // 0x14B8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkeletalMesh*                               HairMesh;                                                 // 0x14C0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DefaultCameraFOV;                                         // 0x14C8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DefaultCameraDistance;                                    // 0x14CC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DefaultCameraShift;                                       // 0x14D0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DefaultCameraLoft;                                        // 0x14D4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ZoomCameraDistanceMin;                                    // 0x14D8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ZoomCameraDistanceMax;                                    // 0x14DC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ZoomCameraShiftMin;                                       // 0x14E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ZoomCameraShiftMax;                                       // 0x14E4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ZoomCameraLoftMin;                                        // 0x14E8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ZoomCameraLoftMax;                                        // 0x14EC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ZoomCameraSteps;                                          // 0x14F0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ZoomCameraSpeed;                                          // 0x14F4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CorpseTrackingDistanceMinimum;                            // 0x14F8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData10[0x4];                                       // 0x14FC(0x0004) MISSED OFFSET
	float                                              BarhandAttackSpeed;                                       // 0x1500(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData) IMPORTANTTHING
	unsigned char                                      UnknownData11[0x4];                                       // 0x1504(0x0004) MISSED OFFSET
	struct FName                                       BarehandImpactEffectKitId;                                // 0x1508(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UMaterialInstance*                           PlaceableGoodMaterial;                                    // 0x1510(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UMaterialInstance*                           PlaceableRotatingMaterial;                                // 0x1518(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UMaterialInstance*                           PlaceableErrorMaterial;                                   // 0x1520(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EHeldItemLocation>                     ActiveHeldItemLocation;                                   // 0x1528(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData12[0x7];                                       // 0x1529(0x0007) MISSED OFFSET
	struct FString                                     CharacterId;                                              // 0x1530(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData13[0x10];                                      // 0x1540(0x0010) MISSED OFFSET
	int                                                ActiveActionBarSlot;                                      // 0x1550(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	int                                                ActiveBuildSlot;                                          // 0x1554(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                ActiveWeaponSlot;                                         // 0x1558(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                ActiveHarvestRune;                                        // 0x155C(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bIsVisible;                                               // 0x1560(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData14[0x3];                                       // 0x1561(0x0003) MISSED OFFSET
	struct FVector                                     PersonalWaypoint;                                         // 0x1564(0x000C) (BlueprintVisible, BlueprintReadOnly, Net, IsPlainOldData)
	bool                                               bPersonalWaypointSet;                                     // 0x1570(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData15[0x3];                                       // 0x1571(0x0003) MISSED OFFSET
	float                                              FactionUseScore;                                          // 0x1574(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData16[0x10];                                      // 0x1578(0x0010) MISSED OFFSET
	int                                                FactionId;                                                // 0x1588(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                InitialFactionId;                                         // 0x158C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	TArray<class UTechTree*>                           TechTrees;                                                // 0x1590(0x0010) (Net, ZeroConstructor, Transient)
	unsigned char                                      UnknownData17[0x8];                                       // 0x15A0(0x0008) MISSED OFFSET
	class AFaction*                                    Faction;                                                  // 0x15A8(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FString                                     ClanId;                                                   // 0x15B0(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient)
	class AClan*                                       Clan;                                                     // 0x15C0(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	class AGroup*                                      Group;                                                    // 0x15C8(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bInGroup;                                                 // 0x15D0(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData18[0x3];                                       // 0x15D1(0x0003) MISSED OFFSET
	int                                                XP;                                                       // 0x15D4(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       CurrentWorldMapId;                                        // 0x15D8(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	float                                              FactionReputation;                                        // 0x15E0(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData19[0xC];                                       // 0x15E4(0x000C) MISSED OFFSET
	int                                                FactionLadderPosition;                                    // 0x15F0(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData20[0x7C];                                      // 0x15F4(0x007C) MISSED OFFSET
	bool                                               bIsOutcast;                                               // 0x1670(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData21[0x3];                                       // 0x1671(0x0003) MISSED OFFSET
	float                                              OutcastPenalty;                                           // 0x1674(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                OutcastCount;                                             // 0x1678(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData22[0x4];                                       // 0x167C(0x0004) MISSED OFFSET
	struct FDateTime                                   OutcastStartTimestamp;                                    // 0x1680(0x0008) (Net, Transient)
	unsigned char                                      UnknownData23[0x4];                                       // 0x1688(0x0004) MISSED OFFSET
	int                                                DemolishPermissionCount;                                  // 0x168C(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FDateTime                                   DemolishPermissionStartTimestamp;                         // 0x1690(0x0008) (Net, Transient)
	unsigned char                                      UnknownData24[0x8];                                       // 0x1698(0x0008) MISSED OFFSET
	struct FName                                       OverrideFactionNormalLevel;                               // 0x16A0(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       OverrideFactionLadderBasedLevel;                          // 0x16A8(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                Level;                                                    // 0x16B0(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bStopShowingTutorials;                                    // 0x16B4(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData25[0x3];                                       // 0x16B5(0x0003) MISSED OFFSET
	int                                                ServerFps;                                                // 0x16B8(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData26[0x4];                                       // 0x16BC(0x0004) MISSED OFFSET
	int                                                TutorialsCleared;                                         // 0x16C0(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData27[0x5C];                                      // 0x16C4(0x005C) MISSED OFFSET
	struct FString                                     CharacterName;                                            // 0x1720(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, EditConst)
	class UPlayerSpawnComponent*                       RespawnLocation;                                          // 0x1730(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              CustomizedCharacterScale;                                 // 0x1738(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData28[0x4];                                       // 0x173C(0x0004) MISSED OFFSET
	bool                                               bAimDownSight;                                            // 0x1740(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData29[0x7];                                       // 0x1741(0x0007) MISSED OFFSET
	class USkeletalMeshComponent*                      MountComponent;                                           // 0x1748(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	bool                                               bMounted;                                                 // 0x1750(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData30[0x1F];                                      // 0x1751(0x001F) MISSED OFFSET
	bool                                               bHasPet;                                                  // 0x1770(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bInClanBase;                                              // 0x1771(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bInPersonalBase;                                          // 0x1772(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bInFactionBase;                                           // 0x1773(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bNearStables;                                             // 0x1774(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData31[0x3];                                       // 0x1775(0x0003) MISSED OFFSET
	float                                              NearStablesLastValid;                                     // 0x1778(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bOffhandOut;                                              // 0x177C(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData32[0x3];                                       // 0x177D(0x0003) MISSED OFFSET
	struct FName                                       HairCustomizationId;                                      // 0x1780(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       FacialHairCustomizationId;                                // 0x1788(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       HairColorId;                                              // 0x1790(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       SkinColorId;                                              // 0x1798(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	TEnumAsByte<EGender>                               Gender;                                                   // 0x17A0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               MirrorPose;                                               // 0x17A1(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData33[0x6];                                       // 0x17A2(0x0006) MISSED OFFSET
	class UClass*                                      ClientEffectsClass;                                       // 0x17A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TArray<struct FTameState>                          TameState;                                                // 0x17B0(0x0010) (Net, ZeroConstructor, Transient)
	unsigned char                                      UnknownData34[0x10];                                      // 0x17C0(0x0010) MISSED OFFSET
	TWeakObjectPtr<class AMountProxyActor>             MountProxy;                                               // 0x17D0(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	TWeakObjectPtr<class AAICharacter>                 SummonedPet;                                              // 0x17D8(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData35[0x20];                                      // 0x17E0(0x0020) MISSED OFFSET
	class AClientEffects*                              ClientEffects;                                            // 0x1800(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class APlayerVehicle*                              ControlledVehicle;                                        // 0x1808(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	class USceneComponent*                             DefaultCameraAttachment;                                  // 0x1810(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<int>                                        AoiAwareFlags;                                            // 0x1818(0x0010) (Net, ZeroConstructor, Transient)
	int                                                AllAoiAwareFlags;                                         // 0x1828(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData36[0x4];                                       // 0x182C(0x0004) MISSED OFFSET
	struct FName                                       ServerZoneId;                                             // 0x1830(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData37[0x10];                                      // 0x1838(0x0010) MISSED OFFSET
	struct FName                                       ClientZoneId;                                             // 0x1848(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	TWeakObjectPtr<class APlayerCharacter>             ServerRecentPlayer;                                       // 0x1850(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	TArray<struct FRecentPlayer>                       RecentPlayers;                                            // 0x1858(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient)
	unsigned char                                      UnknownData38[0xF4];                                      // 0x1868(0x00F4) MISSED OFFSET
	int                                                JumpPenaltyCount;                                         // 0x195C(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData39[0x10];                                      // 0x1960(0x0010) MISSED OFFSET
	class UAudioComponent*                             MusicAudioComp;                                           // 0x1970(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UAudioComponent*                             AmbienceAudioComp[0x2];                                   // 0x1978(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData40[0x18];                                      // 0x1988(0x0018) MISSED OFFSET
	TArray<class UAudioComponent*>                     PersistentVOAudioComps;                                   // 0x19A0(0x0010) (ExportObject, ZeroConstructor)
	unsigned char                                      UnknownData41[0x8];                                       // 0x19B0(0x0008) MISSED OFFSET
	TArray<struct FString>                             MutedCharacterIds;                                        // 0x19B8(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData42[0x78];                                      // 0x19C8(0x0078) MISSED OFFSET
	TMap<struct FName, struct FPlayerTempoState>       TempoChannels;                                            // 0x1A40(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData43[0x270];                                     // 0x1A90(0x0270) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerCharacter");
		return ptr;
	}


	void ValidatePetInventory(const struct FVector& PetLocation, bool bForceDrop);
	void ValidateMountStamina();
	bool UpdateRecipeForCrafting(struct FRecipeData* RecipeData);
	bool UpdateRecentPlayerEntry(const struct FString& InCharacterId, const struct FString& InCharacterName);
	bool UpdateRecentPlayer(class APlayerCharacter* RecentPlayer);
	void UpdatePlayerCameraValues(float Distance, float FOV, float Shift, float Loft, float Speed);
	bool UpdateCheckInPersonalBase(bool bCheckList);
	bool UpdateCheckInFactionBase(bool bCheckList);
	bool UpdateCheckInClanBase(bool bCheckList);
	bool UpdateCheckInAnyBase(bool bCheckList);
	void UpdateCameraForHeldItem(float InCameraSpeed);
	void TriggerTutorialByCodeMap(TEnumAsByte<ETutorial_CodeMap> CodeMap);
	void TriggerTutorial(const struct FName& TutorialId);
	void TriggerCooldownGroup(const struct FName& CooldownGroupId, float Scalar);
	bool TreatAsHostile();
	bool SwapItem(class UInventoryComponent* SourceInventory, int SourceSlot, class UInventoryComponent* TargetInventory, int TargetSlot, bool bOnlyEmptySlot);
	void SwapActiveSpells(int SourceSlot, int TargetSlot);
	void SummonPet();
	void StopBeingOutcast();
	void StopAction(bool bAllowSpellCast);
	bool StartDemolishPermission(int NewCount);
	void StartBeingOutcast();
	void StartAction();
	void SplitItem(class UInventoryComponent* InventoryComp, int SlotIndex, int Count);
	bool SpendPerkPoint(const struct FName& PerkId);
	void SortInventory();
	void SetPersonalWaypoint(bool bSet, const struct FVector& Location);
	void SetOffhandOut(bool bSet);
	void SetMirrorPose(bool InMirrorPos);
	void SetCameraZoomStep(int InStep);
	void SetCameraRecoilControl(class USceneComponent* NewControl);
	void SetAimPoint(class USceneComponent* NewPoint);
	void SetAimDownSight(bool bSet);
	void SetActiveSpell(const struct FName& SpellId, int ActiveSpellSlot);
	void ServerUpdateStructurePermissions(class APlaceableStructure* Structure, TArray<struct FName> PermissionGroupLevelIds);
	void ServerUpdateClanPermissions(TArray<struct FName> PermissionGroupLevelIds);
	void ServerTriggerTutorial(const struct FName& TutorialId);
	void ServerTeleportToPoint(int Index);
	void ServerTeleport(class ATeleporterVolume* TeleporterVolume);
	void ServerSwitchPlaceableVariant(class UPlaceableMeshComponent* Placeable);
	void ServerSwapItem(class UInventoryComponent* SourceInventory, int SourceSlot, class UInventoryComponent* TargetInventory, int TargetSlot, bool bOnlyEmptySlot, bool bForceDrop);
	void ServerSwapActiveSpell(int SourceSlot, int TargetSlot);
	void ServerSummonPet();
	void ServerStoreItemPrototype(class UInventoryItem* InvItem);
	void ServerStopShowingTutorials();
	void ServerStartStealSkillXP(class UCraftComponent* CraftComp, class UCraftComponent* StationCraftComp, const struct FName& SkillTree);
	void ServerSplitItem(class UInventoryComponent* InventoryComp, int SlotIndex, int Count);
	void ServerSpendPerkPoint(const struct FName& PerkId);
	void ServerSetPersonalWaypoint(bool bSet, const struct FVector& Location);
	void ServerSetOffhandOut(bool bSet);
	void ServerSetFactionMotd(const struct FString& NewMotd);
	void ServerSetFactionMemo(const struct FString& NewMemo);
	void ServerSetAmmo(class UInventoryItem* InventoryItemIn, const struct FName& AmmoItemIdIn);
	void ServerSetAimDownSight(bool bSet);
	void ServerSetActiveSpell(const struct FName& SourceSpellId, int TargetSlot);
	void ServerSetActiveCorpseConsent(bool bConsent);
	void ServerSelectSpawnPoint(int Index);
	void ServerSalvageTarget(class UObject* SalvageObject, const struct FHitResult& HitResult);
	void ServerSalvageItem(class UInventoryItem* Item, int StackCount);
	void ServerRespawnPlayer();
	void ServerResetTutorials();
	void ServerRequestTeleportPoints();
	void ServerRequestSpawnPoints();
	void ServerRequestLifeSpanRemaining(class UInventoryComponent* InventoryComp);
	void ServerRequestInventoryComponentData(class UInventoryComponent* InventoryComp);
	void ServerRequestInitialCooldowns();
	void ServerRequestCraftStealState(class UCraftComponent* CraftComp);
	void ServerRequestCraftFuelTime(class UCraftComponent* CraftComp);
	void ServerRepairTarget(class UObject* RepairObject, const struct FHitResult& HitResult);
	void ServerRepairItemAtStation(class UCraftComponent* CraftComp, class UCraftComponent* StationCraftComp, class UInventoryItem* DamagedItem);
	void ServerRepairItem(class UInventoryItem* DamagedItem, class UInventoryItem* RepairKitItem);
	void ServerRenamePlaceable(class APlaceableActor* Placeable, const struct FString& NewName);
	void ServerRemoveBuff(const struct FName& BuffId);
	void ServerPourOutFromItem(class UInventoryItem* InvItem);
	void ServerPickUpVehicle(class APlayerVehicle* Vehicle);
	void ServerPickUpPlaceable(class APlaceableActor* Placeable);
	void ServerOnInteract(class UInteractiveMeshComponent* MeshComponent, const struct FName& InteractActionId);
	void ServerMutePlayerChatById(const struct FString& TaretCharacterId, bool bSet, bool bToggle);
	void ServerMutePlayerChat(const struct FString& TargetCharacterName, bool bSet, bool bToggle);
	void ServerMountPet();
	void ServerMountHarvest(class UObject* ObjectHit, int InstanceIndex, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal, TEnumAsByte<EPhysicalSurface> SurfaceType);
	void ServerModifyEntropyLootScore(float Delta, bool CanPayout, bool ForcePayout);
	void ServerLootCorpse(class UInventoryComponent* TargetInventory);
	void ServerInteractWithStructurePlug(class UPlaceableStructurePlug* StructurePlug, const struct FName& InteractActionId);
	void ServerInteractHarvert(const struct FVector& StartVector, const struct FVector& EndVector);
	void ServerInitiateOutcastVoteById(const struct FString& TargetCharacterId);
	void ServerInitiateOutcastVote(const struct FString& TargetPlayerName);
	void ServerInitiateDemolishVote(int RequestedCount);
	void ServerInitializeVoice();
	void ServerGetUpgradeState(class UPlaceableMeshComponent* UpgradeComponent);
	void ServerGetStructureGridData(class APlaceableStructure* Structure, bool bForReplay);
	void ServerFillItem(class UInventoryItem* InvItem, class UObject* Target);
	void ServerExitVehicle();
	void ServerEnterVehicle(class APlayerVehicle* Vehicle);
	void ServerEnterSpiritPortal(class ASpiritPortal* SpiritPortal, bool bEnterSpiritRealm);
	void ServerDropRemoteItem(class UInventoryComponent* RemoteInventory, const struct FRemoteItemData& Item);
	void ServerDropItems(TArray<class UInventoryItem*> Items);
	void ServerDropActiveSpell(int ActiveSpellIdx);
	void ServerDrinkFromItem(class UInventoryItem* InvItem);
	void ServerDrink(class UObject* Target);
	void ServerDismountPet();
	void ServerDismissPet();
	void ServerDestroyTarget(class UObject* DestroyObj);
	void ServerDepositUpgradeResourcesIntoPlaceable(const struct FName& ItemId, int ItemCount, class UPlaceableMeshComponent* Placeable);
	void ServerDepositSpiritsUnchecked(float AmountToDeposit);
	void ServerDepositSouls(float AmountToDeposit);
	void ServerDepositPylonSouls(class UBasePylonSkeletal* Pylon, float AmountToDeposit);
	void ServerDepositIntoWarehouse(class UInteractiveMeshComponent* Warehouse, const struct FName& ItemId, int ItemCount);
	void ServerDepositAllIntoWarehouse(class UInteractiveMeshComponent* Warehouse);
	void ServerClearTutorial(const struct FName& TutorialId);
	void ServerClearCraftQueue(class UCraftComponent* CraftComp);
	void ServerChooseArchetype(TEnumAsByte<ECharacterArchetype> InArchetype);
	void ServerCheckInBase(class APlaceableStructure* BaseStructure);
	void ServerCastOutcastVote(const struct FString& TargetCharacterId, bool bYae);
	void ServerCastDemolishVote(const struct FString& TargetCharacterId, bool bYae);
	void ServerCancelIndividualCraft(int SlotIdx);
	void ServerAddToCraftQueue(class UCraftComponent* CraftComp, class UCraftComponent* StationCraftComp, const struct FName& RecipeId, int Count, bool bCraftPrototype);
	void ServerAddSecondarySkillPerk(const struct FName& PerkId);
	void ServerAcknowledgeClientReady();
	void SendOnTakeDamage(const struct FCharacterDamageEventData& GameEvent);
	void SendOnDoDamage(const struct FCharacterDamageEventData& GameEvent);
	void SelectAimPoint(class USceneComponent* TruePoint, class USceneComponent* CameraPoint);
	bool SalvageItem(class UInventoryItem* Item, int StackCount);
	void RespawnPlayer(bool bInPlace);
	void ResetTutorials();
	void RequestTeleportPoints(const struct FScriptDelegate& InDelegate);
	void RequestSpawnPoints(const struct FScriptDelegate& InDelegate);
	void RequestInventoryComponentData(class UInventoryComponent* InventoryComp);
	void RequestCraftStealState(class UCraftComponent* CraftComp);
	bool RepairItemAtStation(class UCraftComponent* CraftComp, class UCraftComponent* StationCraftComp, class UInventoryItem* DamagedItem);
	void RepairItem(class UInventoryItem* DamagedItem, class UInventoryItem* RepairKitItem);
	int RemoveItemForCrafting(const struct FName& ItemId, int ItemCount, bool bIncludeWarehouse, class UInventoryComponent* ExtraInventory, bool bForce, bool bFreeWarhouseUse, int* OutWarehouseCount);
	int RemoveItem(const struct FName& ItemId, int ItemCount, bool bFromPaperdoll, bool bFromStash, bool bFromPet);
	bool ProcessFactionReputationEventById(const struct FName& EventId, float EventScalar);
	bool ProcessFactionReputationEvent(TEnumAsByte<EReputationEvent_CodeMap> Event, float EventScalar);
	void OnZoneChanged(const struct FZoneData& ZoneData);
	void OnRep_VisitedZones();
	void OnRep_UpdateXP();
	void OnRep_UpdateLevel();
	void OnRep_TutorialsCleared(int OldValue);
	void OnRep_TechTrees();
	void OnRep_TameState();
	void OnRep_ServerZoneChanged();
	void OnRep_RecentPlayer();
	void OnRep_PersonalWaypoint();
	void OnRep_OutcastStartTimestamp();
	void OnRep_OffhandOut();
	void OnRep_Mounted();
	void OnRep_MirrorPose();
	void OnRep_JumpPenaltyCount(int OldJumpPenaltyCount);
	void OnRep_IsVisible();
	void OnRep_IsOutcast();
	void OnRep_InPersonalBase();
	void OnRep_InFactionBase();
	void OnRep_InClanBase();
	void OnRep_HasPet();
	void OnRep_HairCustomization();
	void OnRep_Group();
	void OnRep_Faction();
	void OnRep_DemolishPermissionStartTimestamp();
	void OnRep_ControlledVehicle();
	void OnRep_Clan();
	void OnRep_ADS();
	void OnRep_ActiveAction();
	void OnReckoningStateChange(const struct FReckoiningStateChangeData& Data);
	void OnPlayerInteract();
	void OnMusicEnd();
	void OnMountHarvest(const struct FVector& StartVector, const struct FVector& Direction, bool bCheckAoe);
	void OnEntropyLootPayout();
	void OnDodging();
	void OnDayNightChange(bool bIsNight);
	void MutePlayer(const struct FString& TaretCharacterId, bool bSet);
	void MulticastTriggerVO(TEnumAsByte<EVOTrigger> Trigger, const struct FName& EmoteId, bool bSet);
	void MulticastTriggerEmoteVO(TEnumAsByte<EVOTrigger> Trigger, const struct FName& EmoteId, bool bSet);
	void MulticastSimulateSalvageTarget(class UObject* SalvageObject, const struct FHitResult& HitResult);
	void MulticastSimulateRepairTarget(class UObject* RepairObject, const struct FHitResult& HitResult);
	void MulticastSimulateMeleeAttack(class UObject* HitObject, const struct FHitResult& HitResult);
	void MulticastSimulateHarvestAll(bool bSecondary, class UObject* ObjectHit, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal, TEnumAsByte<EPhysicalSurface> SurfaceType);
	void MulticastSimulateHarvest(bool bSecondary, class UObject* ObjectHit, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal, TEnumAsByte<EPhysicalSurface> SurfaceType);
	void MulticastPlayJumpFX();
	void MulticastPlayDrinkMontage();
	void MulticastPlayConsumeFX(const struct FName& ItemId);
	void MulticastInitialGrid(class APlaceableStructure* Structure, TArray<struct FStructureGridReplicationData> GridData, TArray<struct FStructurePlugReplicationData> PlugData);
	void MountPet();
	void MarkAsTempHostile(float Length);
	bool LootCorpse(class UInventoryComponent* TargetInventory);
	bool IsTutorialTriggered(const struct FName& TutorialId);
	bool IsTutorialCleared(const struct FName& TutorialId);
	bool IsTrueAimActive();
	bool IsNearStables();
	bool IsMuting(const struct FString& TaretCharacterId);
	bool IsInZone(const struct FName& ZoneId);
	bool IsInPersonalBase();
	bool IsInGroup();
	bool IsInFactionBase();
	bool IsInClanBase();
	bool IsInBase();
	bool IsAttackRepEvent(class APlayerCharacter* Attacker);
	bool HasVisitedZone(const struct FName& ZoneId);
	bool HasPet();
	bool HasItemCountForCrafting(const struct FName& ItemId, int Count, bool bIncludeWarehouse, class UInventoryComponent* ExtraInventory, int* OutWarehouseCount, float* OutUseScoreCost);
	bool HasFactionPermissionById(const struct FName& PermissionId);
	bool HasFactionPermission(TEnumAsByte<EPermission_CodeMap> permission);
	void GiveLootRoll(const struct FName& LootId, TArray<float> XPRewardPerTier, TEnumAsByte<ESecondarySkill> SkillType, TEnumAsByte<EHarvestType> HarvestType, int QualityThreshold);
	int GetXPForLevel();
	int GetXP();
	struct FVector GetTrueAimPoint();
	float GetTotalResourceAmount(TEnumAsByte<EItemResourceType> ItemResourceType);
	float GetTimePlayed();
	class UTechTree* GetTechTree(TEnumAsByte<ETechTreeType> TechTreeType);
	bool GetTameProgressFor(class AAICharacter* Target, float* OutScore, float* OutMaxScore);
	float GetTamePointsFor(class AAICharacter* Target);
	class AAICharacter* GetSummonedPetCharacter();
	class AAICharacter* GetSummonedPet();
	float GetRespawnDelayRemaining();
	class URemoteCraftComponent* GetRemoteCraftComponent();
	float GetRemainingDemolishTime();
	int GetPlayerLevel();
	float GetOutcastStartTime();
	float GetOutcastPenalty();
	int GetOutcastCount();
	class AMountProxyActor* GetMountProxy();
	int GetMountAbilityCount();
	class UMountAbilityComponent* GetMountAbilityByIndex(int Index, bool bAllowAdd);
	class UMountAbilityComponent* GetMountAbility(const struct FName& AbilityId, bool bAllowAdd);
	float GetMaxFactionUseCost();
	struct FMotionEventData GetLastMotionState();
	int GetItemCountForCrafting(const struct FName& ItemId, bool bIncludeWarehouse, class UInventoryComponent* ExtraInventory);
	int GetItemCount(const struct FName& ItemId, bool bSearchAll);
	int GetInventoryBuffCount(const struct FName& BuffId);
	TScriptInterface<class UInteractiveInterface> GetInteractTarget(bool bOnInteract);
	class UHeldItemComponent* GetHeldItemComponent();
	class AGroup* GetGroup();
	float GetFactionReputation();
	struct FName GetFactionPermissionTitleId();
	bool GetFactionPermissionLevels(struct FName* NormalLevel, struct FName* LadderBasedLevel);
	int GetFactionLadderPosition();
	class AFaction* GetFaction();
	void GetCurrentZoneList(TArray<struct FName>* Result);
	struct FZoneData GetCurrentZone();
	int GetCurrentDodgeCount();
	struct FName GetCurrentBuildModeUpgradeId();
	class UCraftComponent* GetCraftComponent();
	class AClientEffects* GetClientEffects();
	class AClan* GetClan();
	int GetCameraZoomStep();
	float GetBountyValue();
	int GetAvailablePerkPoints();
	class APlayerCharacter* STATIC_GetAttackingPlayer(class AController* EventInstigator, class AActor* DamageCauser, bool bIncludePlaceable);
	int GetAllowedDemolishCount();
	void GetAllMountAbilities(TArray<class UMountAbilityComponent*>* Abilities);
	void GetAllAbilities(TArray<class UPlayerAbilityComponent*>* Abilities);
	struct FVector GetAimStartLocation(bool bForceGetPlayer);
	struct FVector GetAimDirection(bool bForceGetPlayer);
	float GetActiveItemMouseSpeedScalar();
	class UAbilityComponent* GetActiveAbility();
	class UPlayerAbilityComponent* GetAbility(const struct FName& AbilityId, bool bAllowAdd, TEnumAsByte<EPlayerAbilitySource> InSource);
	void ForceDespawnPet();
	void FillItem(class UInventoryItem* InvItem, class UObject* Target);
	void FailAllTames();
	void DropRemoteItem(class UInventoryComponent* RemoteInventory, const struct FRemoteItemData& Item);
	void DropItems(TArray<class UInventoryItem*> Items);
	int DropItemById(const struct FName& ItemId, int ItemCount, bool bFromPaperdoll, bool bFromStash, bool bFromPet);
	void DropItem(class UInventoryItem* Item);
	void Drink(class UObject* Target);
	void DismountPetUnchecked();
	void DismountPet();
	void DismissPetUnchecked();
	void DismissPet();
	bool DepositStructureUpgradeItemsAll();
	bool DepositStructureUpgradeItems(const struct FName& ItemId, int ItemCount);
	float DeductResource(TEnumAsByte<EItemResourceType> ItemResourceType, float Amount);
	bool DecrementDemolishCount(int NegCount);
	struct FCrosshairState CurrentCrosshairState();
	bool ConsumeItem(class UInventoryItem* InvItem);
	void ClientUpdateRecentPlayerEntry(const struct FString& InCharacterId, const struct FString& InCharacterName);
	void ClientUpdateLifeSpanRemaining(class UInventoryComponent* InventoryComp, float InTimeRemaining);
	void ClientUpdateInventoryComponentSlots(class UInventoryComponent* InventoryComp, int NumSlots);
	void ClientUpdateInventoryComponentItemCount(class UInventoryComponent* InventoryComp, int Slot, int Count);
	void ClientUpdateInventoryComponentItem(class UInventoryComponent* InventoryComp, const struct FRemoteItemData& ItemData);
	void ClientUpdateCraftStealStateSingle(class UCraftComponent* CraftComp, const struct FCraftStealState& StealState);
	void ClientUpdateCraftStealState(class UCraftComponent* CraftComp, TArray<struct FCraftStealState> StealState);
	void ClientUpdateCraftFuelTime(class UCraftComponent* CraftComp, float FuelTime);
	void ClientTriggerVO(TEnumAsByte<EVOTrigger> Trigger, const struct FName& EmoteId, bool bSet);
	void ClientTriggerTutorial(const struct FName& TutorialId);
	void ClientTriggerItemCooldown(const struct FName& ItemId);
	void ClientTriggerCooldownGroup(const struct FName& CooldownGroupId, float Scalar);
	void ClientSyncStamina(float Value);
	void ClientSyncNoise(float Value);
	void ClientSyncMountStamina(float Value);
	void ClientSendUpgradeState(class UPlaceableMeshComponent* UpgradeComponent, const struct FPlaceableUpgradeState& NewUpgradeState);
	void ClientSendServerTime(const struct FDateTime& ServerTime);
	void ClientSendInventoryComponent(class UInventoryComponent* InventoryComp, const struct FText& InventoryName, int NumSlots, TArray<struct FRemoteItemData> ItemData);
	void ClientSendGridPlugData(class APlaceableStructure* Structure, TArray<struct FStructurePlugReplicationData> PlugData, int OffsetIndex, int PlugDataMaxSize);
	void ClientSendGridData(class APlaceableStructure* Structure, TArray<struct FStructureGridReplicationData> GridData, int OffsetIndex, int GridDataMaxSize);
	void ClientSendDamagedStructureData(class APlaceableStructure* Structure, TArray<int> GridIds, TArray<struct FPlugIdBase> PlugIds);
	void ClientResultTeleportPoints(TArray<struct FPlayerSpawnPointData> AvailablePoints);
	void ClientResultSpawnPoints(TArray<struct FPlayerSpawnPointData> AvailablePoints);
	void ClientResetTutorials();
	void ClientRemoveInventoryComponentItem(class UInventoryComponent* InventoryComp, int Slot);
	void ClientOutcastVoteStarted(const struct FString& TargetPlayerName, const struct FString& TargetCharacterId);
	void ClientOutcastVoteFinished(const struct FString& TargetPlayerName, const struct FString& TargetCharacterId, TEnumAsByte<EOutcastResult> Result);
	void ClientOnTakeDamage(const struct FCharacterDamageEventData& GameEvent);
	void ClientOnKillOtherEvent(const struct FGameEventData& EventData);
	void ClientOnKillAssistEvent(const struct FGameEventData& EventData);
	void ClientOnDoDamage(const struct FCharacterDamageEventData& GameEvent);
	void ClientNotifyUnlocksUpdated();
	void ClientNotifyTameEnd(class AAICharacter* Target, float TameScore, bool bSuccess);
	void ClientNotifySpawn();
	void ClientNotifySkillXPGain(const struct FName& SkillId, float SkillXP, float Total);
	void ClientNotifySkillTreeXPGain(const struct FName& RecipeId, float SkillXP, float Total, TEnumAsByte<ECraftSkillUpReasonType> Reason, bool bBecameSkilled, bool bBecameMastered);
	void ClientNotifySkillLevel(const struct FName& SkillId, int SkillLevel);
	void ClientNotifyPlaceableExpiration(float IsolatedExpirationTimeSeconds);
	void ClientNotifyCraftingAdded();
	void ClientNotifyBuffChanged();
	void ClientLootTicker(const struct FName& ItemId, int Count);
	void ClientInventoryDestroyed(class UInventoryComponent* InventoryComp);
	void ClientInitiateOutcastVote(const struct FString& TargetPlayerName, const struct FString& TargetCharacterId, TEnumAsByte<EVoteResult> VoteResult);
	void ClientInitiateDemolishVote(TEnumAsByte<EVoteResult> VoteResult);
	void ClientInitializeVoice(const struct FVivoxData& VivoxData);
	void ClientInitializePlayerStats();
	void ClientInitCooldowns(float DeltaTime, TArray<struct FPlayerCooldownEntry> InItemCooldowns, TArray<struct FPlayerCooldownEntry> InGroupCooldowns);
	void ClientHeldItemUpdate();
	void ClientHandleDeathEvent(const struct FCharacterDeathEventData& EventData, const struct FDateTime& InServerRespawnTime);
	void ClientFactionRepDelta(float Delta, bool Rollover);
	void ClientDemolishVoteStarted(const struct FString& TargetPlayerName, const struct FString& TargetCharacterId, int RequestedCount);
	void ClientDemolishVoteFinished(const struct FString& TargetPlayerName, const struct FString& TargetCharacterId, TEnumAsByte<EDemolishResult> Result);
	void ClientClearTutorial(const struct FName& TutorialId);
	void ClientCastOutcastVote(const struct FString& PlayerName, const struct FString& TargetCharacterId, TEnumAsByte<EVoteResult> VoteResult);
	void ClientCastDemolishVote(const struct FString& PlayerName, const struct FString& TargetCharacterId, TEnumAsByte<EVoteResult> VoteResult);
	void ClientApplyCooldownEffect(TEnumAsByte<ECustomAbilityType> CooldownAbility, const struct FName& CooldownGroupId, TEnumAsByte<ECooldownEffectType> CooldownEffect, float Value);
	void ClienInvalidateRemoteInventoryComponent(class UInventoryComponent* InventoryComp);
	void ClearTutorialByCodeMap(TEnumAsByte<ETutorial_CodeMap> CodeMap);
	void ClearTutorial(const struct FName& TutorialId);
	void ClearTame(class AAICharacter* Target, bool bSuccess);
	void ClearOutcastData();
	void ClearBounty(bool bIncludeKillRecord);
	bool CleanupRecentPlayer();
	bool ChooseItem(int SourceItemIdx, TEnumAsByte<EHeldItemLocation> SourceLocation, TEnumAsByte<EChooseItemToggleMode> ToggleMode);
	void ChooseArchetype(TEnumAsByte<ECharacterArchetype> InArchetype);
	bool CastSpellBookSpell(int SpellSlot);
	bool CastSpell(const struct FName& PlayerAbilityId, class UObject* PreferredTarget, const struct FName& InteractActionId);
	bool CastMountAbilityByIndex(int Index);
	bool CastMountAbilityById(const struct FName& MountAbilityId);
	bool CanSalvageItem(class UInventoryItem* Item);
	TEnumAsByte<EInteractType> CanPlayerInteract();
	void BP_ServerOnInteract(class UObject* Interactive, const struct FName& InteractActionId);
	void ApplyCooldownScalarMax(const struct FName& ID, TEnumAsByte<ECooldownEffectType> EffectType, float Value);
	void ApplyCooldownScalar(const struct FName& ID, TEnumAsByte<ECooldownEffectType> EffectType, float Value);
	void ApplyCooldownOffset(const struct FName& ID, TEnumAsByte<ECooldownEffectType> EffectType, float Value);
	void ApplyCooldownEffect(TEnumAsByte<ECustomAbilityType> CooldownAbility, const struct FName& CooldownGroupId, TEnumAsByte<ECooldownEffectType> CooldownEffect, float Value);
	float AdjustTamePointsFor(class AAICharacter* Target, float Delta, TEnumAsByte<ETameEventType> SourceEvent);
	bool AdjustFactionUseScore(float Delta, bool bOnlyTest, bool bForceExceed);
	void AddXP(float Amount, TEnumAsByte<EXPSource> Source);
	bool AddToCraftQueue(class UCraftComponent* CraftComp, class UCraftComponent* StationCraftComp, const struct FName& RecipeId, int Count, bool bCraftPrototype);
	void AddTempoScore(float Amount, const struct FName& ChannelId, TEnumAsByte<ETempoTargetState> TempoState);
	void AddSkillXp(TEnumAsByte<ESecondarySkill> SkillType, float XpScalar, int SkillLevel);
	float AddSkillTreeXP(const struct FName& RecipeId, TEnumAsByte<ECraftSkillUpReasonType> Reason);
	float AddResource(TEnumAsByte<EItemResourceType> ItemResourceType, float Amount);
	bool AddReputationUnchecked(float Delta);
	int AddNewItem(const struct FName& ItemId, int ItemCount, bool bSendLootTicker);
	bool AddBountyUnchecked(float Delta);
};


// Class Otherlands.PlayerCorpse
// 0x00E0 (0x0408 - 0x0328)
class APlayerCorpse : public AActor
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0328(0x0010) MISSED OFFSET
	bool                                               bConsent;                                                 // 0x0338(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0339(0x0007) MISSED OFFSET
	class UInventoryComponent*                         Inventory;                                                // 0x0340(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USphereComponent*                            SphereComp;                                               // 0x0348(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkeletalMeshComponent*                      SkeletalMesh;                                             // 0x0350(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	TEnumAsByte<ESpiritRealmState>                     InSpiritRealmState;                                       // 0x0358(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0359(0x0007) MISSED OFFSET
	class USkeletalMesh*                               MeshAsset;                                                // 0x0360(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	class UAnimationAsset*                             DeathPose;                                                // 0x0368(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	class UGearComponent*                              GearComponent;                                            // 0x0370(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkeletalMesh*                               BaseMesh;                                                 // 0x0378(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	TArray<class USkeletalMesh*>                       GearMeshes;                                               // 0x0380(0x0010) (Net, ZeroConstructor, Transient)
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0390(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0391(0x0007) MISSED OFFSET
	struct FName                                       HairCustomizationId;                                      // 0x0398(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       FacialHairCustomizationId;                                // 0x03A0(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       SkinColorId;                                              // 0x03A8(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	struct FName                                       HairColorId;                                              // 0x03B0(0x0008) (Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                FactionId;                                                // 0x03B8(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x03BC(0x0004) MISSED OFFSET
	struct FString                                     UniqueCharacterId;                                        // 0x03C0(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient)
	struct FString                                     CharacterName;                                            // 0x03D0(0x0010) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient)
	struct FName                                       CharacterRepLevelId;                                      // 0x03E0(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bTreatAsHostile;                                          // 0x03E8(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData05[0x1F];                                      // 0x03E9(0x001F) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerCorpse");
		return ptr;
	}


	bool WillTriggerFactionMessage(class APlayerCharacter* Player);
	bool WillIncureRepPenalty(class APlayerCharacter* Player);
};


// Class Otherlands.PlayerSpawnComponent
// 0x0050 (0x0290 - 0x0240)
class UPlayerSpawnComponent : public USceneComponent
{
public:
	bool                                               bDefault;                                                 // 0x0240(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bDropGear;                                                // 0x0241(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0242(0x0006) MISSED OFFSET
	TArray<struct FName>                               RequireZoneIds;                                           // 0x0248(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TArray<struct FName>                               ExcludeZoneIds;                                           // 0x0258(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	int                                                MaxLevel;                                                 // 0x0268(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                MinLevel;                                                 // 0x026C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                FactionIdOverride;                                        // 0x0270(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bEnabled;                                                 // 0x0274(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0275(0x0003) MISSED OFFSET
	struct FName                                       ItemBaseIdOverride;                                       // 0x0278(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ZoneIdOverride;                                           // 0x0280(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x0288(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerSpawnComponent");
		return ptr;
	}


	void SetZoneIdOverride(const struct FName& NewZoneIdOverride);
	void SetItemBaseIdOverride(const struct FName& NewItemBaseIdOverride);
	void SetFactionIdOverride(int NewFactionIdOverride);
};


// Class Otherlands.PlayerSpawnLocation
// 0x0018 (0x0340 - 0x0328)
class APlayerSpawnLocation : public AActor
{
public:
	bool                                               bForInitialSpawn;                                         // 0x0328(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0329(0x0003) MISSED OFFSET
	int                                                FactionId;                                                // 0x032C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SpawnRadius;                                              // 0x0330(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0334(0x0004) MISSED OFFSET
	class UStaticMeshComponent*                        InteractMesh;                                             // 0x0338(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerSpawnLocation");
		return ptr;
	}

};


// Class Otherlands.PlayerStats
// 0x0210 (0x0A10 - 0x0800)
class UPlayerStats : public UCharacterStats
{
public:
	TArray<int>                                        SelfReplicatedIntStats;                                   // 0x0800(0x0010) (Net, ZeroConstructor)
	struct FPlayerStatFloatArray                       SelfReplicatedFloatStats;                                 // 0x0810(0x00D0) (Net)
	TArray<int>                                        OtherReplicatedIntStats;                                  // 0x08E0(0x0010) (Net, ZeroConstructor)
	struct FPlayerStatFloatArray                       OtherReplicatedFloatStats;                                // 0x08F0(0x00D0) (Net)
	unsigned char                                      UnknownData00[0x50];                                      // 0x09C0(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerStats");
		return ptr;
	}


	void OnRep_SelfReplicatedFloatStats();
	void OnRep_OtherReplicatedFloatStats();
};


// Class Otherlands.PlayerVehicleAnimInstance
// 0x0010 (0x0370 - 0x0360)
class UPlayerVehicleAnimInstance : public UAnimInstance
{
public:
	float                                              PitchOffset;                                              // 0x0360(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0364(0x0004) MISSED OFFSET
	class APlayerVehicle*                              VehicleOwner;                                             // 0x0368(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerVehicleAnimInstance");
		return ptr;
	}

};


// Class Otherlands.PlayerVisualComponent
// 0x2740 (0x2830 - 0x00F0)
class UPlayerVisualComponent : public UActorComponent
{
public:
	class UMaterialParameterCollection*                PlayerVisualMaterialParameters;                           // 0x00F0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x28];                                      // 0x00F8(0x0028) MISSED OFFSET
	class USeasonsComponent*                           SeasonCom;                                                // 0x0120(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x130];                                     // 0x0128(0x0130) MISSED OFFSET
	class UTexture2D*                                  SeasonLocalFogColorTexture[0x2];                          // 0x0258(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0xC50];                                     // 0x0268(0x0C50) MISSED OFFSET
	class UTexture2D*                                  GlobalFogTexture[0x2];                                    // 0x0EB8(0x0008) (ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  GlobalFogFarTexture[0x2];                                 // 0x0EC8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x18C8];                                    // 0x0ED8(0x18C8) MISSED OFFSET
	class UMaterialParameterCollection*                WeatherMaterialParameters;                                // 0x27A0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x68];                                      // 0x27A8(0x0068) MISSED OFFSET
	class UMaterialParameterCollection*                GlobalShaderParameters;                                   // 0x2810(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x10];                                      // 0x2818(0x0010) MISSED OFFSET
	class UGameAlienFXSystem*                          GameAlienFXSystem;                                        // 0x2828(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerVisualComponent");
		return ptr;
	}


	void OnTakeHeal(const struct FCharacterDamageEventData& DamageEventData);
	void OnTakeDamage(const struct FCharacterDamageEventData& DamageEventData);
	void OnSpiritRealmEvent(const struct FSpiritRealmEventData& Data);
	void OnSoulsDeposited(int FactionId, float DeltaSouls);
	void OnSeasonChanged(const struct FSeasonData& SeasonData);
	void OnKill(const struct FGameEventData& DamageEventData);
	void OnGameOptionsChanged();
	void OnFactionWin(int Faction);
	void OnDoDamage(const struct FCharacterDamageEventData& DamageEventData);
	void InitializeSeasons(const struct FSeasonData& SeasonData, float ElapsedTime);
};


// Class Otherlands.PortDestination
// 0x0010 (0x0338 - 0x0328)
class APortDestination : public AActor
{
public:
	class USceneComponent*                             SceneRoot;                                                // 0x0328(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       PortName;                                                 // 0x0330(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PortDestination");
		return ptr;
	}

};


// Class Otherlands.RadialMenuWidget
// 0x0030 (0x0250 - 0x0220)
class URadialMenuWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  WoodHarvesterIcon;                                        // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  StoneHarvesterIcon;                                       // 0x0228(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  PlantHarvesterIcon;                                       // 0x0230(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  MetalHarvesterIcon;                                       // 0x0238(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  UnarmedIcon;                                              // 0x0240(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                TotalButtons;                                             // 0x0248(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SelectedButtonIdx;                                        // 0x024C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RadialMenuWidget");
		return ptr;
	}


	void UpdateButtonIcons();
	void Update();
	struct FVector2D GetPositionOfButton(int ScreenHeight, int Idx);
	int GetIdxFromMousePos(float XPos, float YPos);
	void ChooseWoodHarvester();
	void ChooseUnarmed();
	void ChooseStoneHarvester();
	void ChoosePlantHarvester();
	void ChooseMetalHarvester();
};


// Class Otherlands.RadiusCheck
// 0x0028 (0x0350 - 0x0328)
class ARadiusCheck : public AActor
{
public:
	class UArrowComponent*                             ArrowComponent;                                           // 0x0328(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<float>                                      RadiusChecks;                                             // 0x0330(0x0010) (Edit, ZeroConstructor)
	struct FColor                                      StartColor;                                               // 0x0340(0x0004) (Edit, IsPlainOldData)
	struct FColor                                      EndColor;                                                 // 0x0344(0x0004) (Edit, IsPlainOldData)
	bool                                               bDirectional;                                             // 0x0348(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0349(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RadiusCheck");
		return ptr;
	}

};


// Class Otherlands.RangedAttackActionComponent
// 0x0088 (0x01B8 - 0x0130)
class URangedAttackActionComponent : public UActionComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0130(0x0018) MISSED OFFSET
	class APlayerCharacter*                            Player;                                                   // 0x0148(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UInventoryItem*                              CurrentItem;                                              // 0x0150(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UItemData*                                   CurrentItemData;                                          // 0x0158(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bDrawing;                                                 // 0x0160(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bHasAmmo;                                                 // 0x0161(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x0162(0x0002) MISSED OFFSET
	float                                              DrawSpeed;                                                // 0x0164(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bShouldShowAmmo;                                          // 0x0168(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x33];                                      // 0x0169(0x0033) MISSED OFFSET
	float                                              CurrentActionSpeed;                                       // 0x019C(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	class UAudioComponent*                             ReloadSoundCom;                                           // 0x01A0(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	class UAnimMontage*                                DrawMontage;                                              // 0x01A8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x01B0(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RangedAttackActionComponent");
		return ptr;
	}


	bool StartRangedAction(TEnumAsByte<ERangedActionType> InRangedAction, bool bFromInput);
	void ServerStartRangedAction(TEnumAsByte<ERangedActionType> InRangedAction);
	void ServerFinishReload();
	void OnRep_Drawing();
	void OnBurstShotTimer();
	void OnAmmoPickup();
	void MulticastProcessAction(TEnumAsByte<ERangedActionType> InRangedAction, class UAnimMontage* NewMontage, float ActionSpeed);
	bool IsReloading();
	bool IsDrawing();
	bool HasHandOnBowString();
	bool HasAmmo();
	int GetShotsPerBurst();
	float GetDrawScalarAtFire();
	float GetDrawScalar();
	float GetAmmoLoadScalar();
	void ClientVerifyAmmoState(class UInventoryItem* ExpectedHeldItem, int ExpectedAmmoCount);
	void ClientForceVerifyAmmoState();
	bool CanProcessStart();
	bool CanProcessFinish(TEnumAsByte<ERangedActionType> RangedAction);
};


// Class Otherlands.RangedWeaponComponent
// 0x0038 (0x0190 - 0x0158)
class URangedWeaponComponent : public UCombatantComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0158(0x0018) MISSED OFFSET
	struct FName                                       ItemId;                                                   // 0x0170(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class UInventoryItem>               InventoryItem;                                            // 0x0178(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       AmmoItemId;                                               // 0x0180(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	int                                                ProjectileFireIndex;                                      // 0x0188(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x018C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RangedWeaponComponent");
		return ptr;
	}


	void SetItem(const struct FName& ItemId);
	void SetInventoryItem(class UInventoryItem* InventoryItemIn);
	bool SetAmmo(const struct FName& AmmoItemIdIn);
	void ServerSetAmmo(const struct FName& AmmoItemIdIn);
	void ServerDoProjectileAttack(const struct FTransform& SpawnTransform, const struct FVector& TargetLocation);
	void ServerDoHitTraceAttack(const struct FVector& FireLocation, const struct FVector& ShotDirection, float FireRange, TArray<struct FCombatantHitData> HitData, TArray<struct FName> BuffIds);
	void MulticastSimulateTracerFire(const struct FName& AmmoId, TArray<struct FCombatantHitData> HitData, TArray<struct FName> BuffIds);
	void MulticastSimulateProjectileFireEvent();
	void InitializeWeapon(const TScriptInterface<class URangedWeaponInterface>& InOwner, int ProjectileFireIndexIn);
	float GetReloadSpeed();
	struct FName GetAmmoItemId();
	void DoRangedAttack(const struct FVector& FireLocation, const struct FRotator& FireDirection, float FireRange, float AccuracyRange);
	void CheckLoadedAmmo(const struct FName& ForAmmoId);
	bool CanFire();
};


// Class Otherlands.RangedWeaponInterface
// 0x0000 (0x0028 - 0x0028)
class URangedWeaponInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RangedWeaponInterface");
		return ptr;
	}


	bool UsingDrawScalar();
	bool TrackPlayer(class APlayerCharacter* Target);
	bool RemoveItemCount(const struct FName& ItemId, int Count);
	bool ItemUpdated();
	bool IsStabilized();
	bool IsAimingDownSight();
	struct FVector GetProjectileFireLocation(int Index);
	class UInventoryComponent* GetInventoryComp();
	float GetDrawScalar();
	bool FiredProjectile(class AGameProjectile* GameProjectile);
	float DrawToVelocityScalar();
	float DrawToRangeScalar();
	float DrawToDamageScalar();
	float DrawToAccuracyScalar();
	bool AmmoUpdated(class UInventoryItem* InventoryItem);
};


// Class Otherlands.RemoteCraftComponent
// 0x0018 (0x0108 - 0x00F0)
class URemoteCraftComponent : public UActorComponent
{
public:
	TArray<struct FLocalCraftLink>                     LocalLinks;                                               // 0x00F0(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0100(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RemoteCraftComponent");
		return ptr;
	}


	void UnlinkCraftComponent(class UCraftComponent* CraftComponent);
	void ServerUnlinkCraftComponent(class UCraftComponent* CraftComponent);
	void ServerSetStationActive(class UCraftComponent* CraftComponent, bool bSet);
	void ServerRequestCraftProgress(class UCraftComponent* CraftComponent, int QueueIndex);
	void ServerLinkCraftComponent(class UCraftComponent* CraftComponent);
	void ServerCancelCraftAt(class UCraftComponent* CraftComponent, int QueueIndex, int Index);
	void LinkCraftComponent(class UCraftComponent* CraftComponent);
	void ClientUpdateCraftQueue(class UCraftComponent* CraftComponent, int QueueIndex, TArray<struct FQueuedCraft> CraftQueue, int Head, int Tail);
	void ClientUpdateCraftProgress(class UCraftComponent* CraftComponent, int QueueIndex, const struct FName& CraftRecipeId, int CraftCount, float Progress);
	void ClientNotifyCraftResult(class UCraftComponent* CraftComponent, int QueueIndex, const struct FName& ItemId, int ItemCount, TEnumAsByte<ECraftResultType> CraftResult, const struct FName& RecipeId);
};


// Class Otherlands.RemoteCraftLinkManager
// 0x0030 (0x0058 - 0x0028)
class URemoteCraftLinkManager : public UObject
{
public:
	class UCraftComponent*                             CraftComponentOwner;                                      // 0x0028(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<struct FRemoteCraftLink>                    RemoteLinks;                                              // 0x0030(0x0010) (ZeroConstructor)
	TArray<struct FRemoteCraftLink>                    LocalLinks;                                               // 0x0040(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0050(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RemoteCraftLinkManager");
		return ptr;
	}

};


// Class Otherlands.RepairTargetInterface
// 0x0000 (0x0028 - 0x0028)
class URepairTargetInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.RepairTargetInterface");
		return ptr;
	}

};


// Class Otherlands.ResourceActor
// 0x0078 (0x03A0 - 0x0328)
class AResourceActor : public AActor
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0328(0x0020) MISSED OFFSET
	class UStaticMeshComponent*                        StaticMeshComp;                                           // 0x0348(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	struct FName                                       ResourceDisplayId;                                        // 0x0350(0x0008) (Edit, Net, ZeroConstructor, IsPlainOldData)
	float                                              RestrictLifespanTo;                                       // 0x0358(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x035C(0x0004) MISSED OFFSET
	class UResourceISMC*                               ResourceISMCComp;                                         // 0x0360(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UResourceComponent*                          ResourceComp;                                             // 0x0368(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                InstanceIndex;                                            // 0x0370(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0374(0x0004) MISSED OFFSET
	class USpellCastComponent*                         SpellCastComponent;                                       // 0x0378(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class ADestructibleActor*                          DestructibleActor;                                        // 0x0380(0x0008) (ZeroConstructor, IsPlainOldData)
	class AStaticMeshActor*                            TrunkActor;                                               // 0x0388(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bDepleted;                                                // 0x0390(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0xF];                                       // 0x0391(0x000F) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ResourceActor");
		return ptr;
	}


	void OnRep_Collision();
	bool OnDepleted();
	void MulticastOnDepleted(const struct FTransform& OriginalTransform, bool bFrozen);
	void MulticastClearStump();
	void MarkDepleted();
	bool InitializeFromResourceBase(const struct FName& ResourceBaseId);
	bool InitializeFromISCM(class UClass* ResourceISMCSource);
	bool BP_OnHarvested(int Broken);
	bool BP_OnDepleted(int Broken);
	bool BP_OnCreatureDamaged(int Broken);
};


// Class Otherlands.ResourceComponent
// 0x00B8 (0x01A8 - 0x00F0)
class UResourceComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x00F0(0x0008) MISSED OFFSET
	struct FName                                       ResourceHarvestId;                                        // 0x00F8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	struct FResourceHarvestData                        ResourceHarvestData;                                      // 0x0100(0x0078)
	float                                              LootScalar;                                               // 0x0178(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bDepleted;                                                // 0x017C(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x017D(0x0003) MISSED OFFSET
	float                                              MaxHealth;                                                // 0x0180(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Health;                                                   // 0x0184(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              HealthPerLoot;                                            // 0x0188(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              XPPerLoot[0x5];                                           // 0x018C(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                NumLootRolls;                                             // 0x01A0(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                LootRollsGranted;                                         // 0x01A4(0x0004) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ResourceComponent");
		return ptr;
	}


	void SetResourceHarvestById(const struct FName& InResourceHarvestId);
	void SetLootScalar(float NewScalar);
	void OnRep_ResourceHarvestId();
};


// Class Otherlands.ResourceISMC
// 0x0210 (0x09B0 - 0x07A0)
class UResourceISMC : public UFoliageInstancedStaticMeshComponent
{
public:
	struct FName                                       ResourceBaseId;                                           // 0x07A0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class AMainGameMode*                               GameMode;                                                 // 0x07A8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x200];                                     // 0x07B0(0x0200) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ResourceISMC");
		return ptr;
	}

};


// Class Otherlands.ResourceSpawnState
// 0x00E0 (0x0108 - 0x0028)
class UResourceSpawnState : public UObject
{
public:
	struct FResourceSpawnStateData                     Data;                                                     // 0x0028(0x0028)
	TArray<unsigned char>                              DespawnedBits;                                            // 0x0050(0x0010) (ZeroConstructor)
	TArray<unsigned char>                              ClaimedBits;                                              // 0x0060(0x0010) (ZeroConstructor)
	struct FResourceSpawnStateHandle                   Handle;                                                   // 0x0070(0x0010)
	unsigned char                                      UnknownData00[0x88];                                      // 0x0080(0x0088) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ResourceSpawnState");
		return ptr;
	}

};


// Class Otherlands.ResourceSpawnManager
// 0x0030 (0x03A0 - 0x0370)
class AResourceSpawnManager : public AGameVolume
{
public:
	int                                                SpawnPriority;                                            // 0x0370(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                SpawnStateCount;                                          // 0x0374(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0378(0x0008) MISSED OFFSET
	TArray<class UResourceSpawnState*>                 SpawnStates;                                              // 0x0380(0x0010) (ZeroConstructor, Transient)
	bool                                               bGlobalManager;                                           // 0x0390(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0xF];                                       // 0x0391(0x000F) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ResourceSpawnManager");
		return ptr;
	}


	void OnDayNightChange(bool bIsNight);
	void MulticastUpdateSpawnState(int StateIndex, int InstanceIndex, bool bSpawned);
	class AResourceActor* STATIC_GetResourceActorFromInstance(class UActorComponent* Component, int ItemIndex, bool* bDidSpawn);
	class AResourceActor* STATIC_GetDefaultResourceActor(class UActorComponent* Component);
};


// Class Otherlands.DelayResourceSpawnManager
// 0x0018 (0x0340 - 0x0328)
class ADelayResourceSpawnManager : public AActor
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0328(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.DelayResourceSpawnManager");
		return ptr;
	}

};


// Class Otherlands.ScaleLighting
// 0x0008 (0x0330 - 0x0328)
class AScaleLighting : public AActor
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0328(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ScaleLighting");
		return ptr;
	}

};


// Class Otherlands.ScaleLightingInterface
// 0x0000 (0x0028 - 0x0028)
class UScaleLightingInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ScaleLightingInterface");
		return ptr;
	}


	void SetSkyLightMod(const struct FColor& Color);
	void SetDirLightMod(const struct FColor& Color);
};


// Class Otherlands.SeasonsComponent
// 0x0200 (0x0440 - 0x0240)
class USeasonsComponent : public USceneComponent
{
public:
	class UMaterialParameterCollection*                MaterialParameterCollection;                              // 0x0240(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class APostProcessVolume*                          PostProcessVolume;                                        // 0x0248(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class AScaleLighting*                              ScaleLighting;                                            // 0x0250(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class ALocalFog*                                   LocalFog;                                                 // 0x0258(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FSeasonParameters                           SeasonValues[0x4];                                        // 0x0260(0x0078) (Edit)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SeasonsComponent");
		return ptr;
	}

};


// Class Otherlands.SecondarySkill
// 0x0028 (0x0050 - 0x0028)
class USecondarySkill : public UObject
{
public:
	struct FName                                       SkillId;                                                  // 0x0028(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	float                                              SkillXP;                                                  // 0x0030(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                SkillLevel;                                               // 0x0034(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	TArray<float>                                      SkillStats;                                               // 0x0038(0x0010) (Net, ZeroConstructor)
	class USecondarySkillComponent*                    SecondarySkillComp;                                       // 0x0048(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SecondarySkill");
		return ptr;
	}


	void OnRep_SkillXP();
};


// Class Otherlands.SecondarySkillComponent
// 0x0040 (0x0130 - 0x00F0)
class USecondarySkillComponent : public UActorComponent
{
public:
	bool                                               bWasReset;                                                // 0x00F0(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	bool                                               bCanUnlockPerk;                                           // 0x00F1(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x00F2(0x0006) MISSED OFFSET
	TArray<class USecondarySkill*>                     SecondarySkills;                                          // 0x00F8(0x0010) (Net, ZeroConstructor)
	TArray<struct FName>                               SkillPerks;                                               // 0x0108(0x0010) (Net, ZeroConstructor)
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0118(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0120(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SecondarySkillComponent");
		return ptr;
	}


	bool WasReset();
	void ResetAllPoints();
	void OnRep_UpdatePlayerPerkSets(TArray<struct FName>* OldValues);
	void OnRep_CanUnlockPerk();
	bool IsPerkSetUnlocked(const struct FName& PerkSetId);
	bool HasPerk(const struct FName& SecondarySkillPerkId);
	float GetSkillStat(TEnumAsByte<ESecondarySkill> SkillType, TEnumAsByte<ESecondarySkillStat> SkillStat);
	int GetSkillLevel(TEnumAsByte<ESecondarySkill> SkillType);
	float GetSecondarySkillXp(TEnumAsByte<ESecondarySkill> SkillType);
	bool GetSecondarySkillInfo(const struct FName& SkillId, struct FSecondarySkillInfo* Info);
	void ClearReset();
	bool CanUnlockPerkForSkill(TEnumAsByte<ESecondarySkill> CheckSkill);
	bool CanSpendPerkPoint(const struct FName& SecondarySkillPerkId);
};


// Class Otherlands.SecondarySkillPerksWidget
// 0x0008 (0x0228 - 0x0220)
class USecondarySkillPerksWidget : public UGameBaseWidget
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0220(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SecondarySkillPerksWidget");
		return ptr;
	}


	void Update();
	struct FSecondarySkillData GetSecondarySkillData();
};


// Class Otherlands.SecondarySkillsRecipeSlotWidget
// 0x0050 (0x0270 - 0x0220)
class USecondarySkillsRecipeSlotWidget : public UGameBaseWidget
{
public:
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0220(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FText                                       RecipeName;                                               // 0x0228(0x0018) (Edit, BlueprintVisible)
	bool                                               bIsSelected;                                              // 0x0240(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0241(0x0003) MISSED OFFSET
	float                                              RecipeUnlockProgress;                                     // 0x0244(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsUnlocked;                                              // 0x0248(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0249(0x0003) MISSED OFFSET
	int                                                SlotIndex;                                                // 0x024C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       PerkSetId;                                                // 0x0250(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  SlotIcon;                                                 // 0x0258(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<class USkillDisplayWidget*>                 SkillSlotWidgets;                                         // 0x0260(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SecondarySkillsRecipeSlotWidget");
		return ptr;
	}


	void Update();
	void SwitchUnlockLists();
	void SetVisibilityByLevel();
	void SetColor(bool IsSelected);
	void ResetVisibility();
	bool IsUnlocked();
	struct FName GetSkillId(int Idx);
	int GetNumSlots();
	void ExclusiveSelect();
};


// Class Otherlands.SecondarySkillsRecipeWidget
// 0x0058 (0x0278 - 0x0220)
class USecondarySkillsRecipeWidget : public UGameBaseWidget
{
public:
	TArray<class USecondarySkillsRecipeSlotWidget*>    RecipeSlotWidgets;                                        // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	class USecondarySkillsRecipeSlotWidget*            SelectedRecipeSlotWidget;                                 // 0x0230(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<class UPerkSetSlotWidget*>                  PerkSetSlotWidgets;                                       // 0x0238(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0248(0x0008) MISSED OFFSET
	bool                                               bIsViewAllChecked;                                        // 0x0250(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsLookingAtRecipes;                                      // 0x0251(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x26];                                      // 0x0252(0x0026) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SecondarySkillsRecipeWidget");
		return ptr;
	}


	void Update();
	void RepopulateWidgets();
	struct FName GetPerkSetRecipeId(int SlotIndex);
	struct FName GetPerkSetId(int SlotIndex);
	int GetNumRecipes();
	int GetNumPerkSetUnlocks();
	void BuildInitialWidgetList();
	void BuildAndSortUnlocks();
};


// Class Otherlands.SecondarySkillsWidget
// 0x0030 (0x0250 - 0x0220)
class USecondarySkillsWidget : public UGameBaseWidget
{
public:
	TArray<class USkillDisplayWidget*>                 AdventuringSkills;                                        // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	TArray<class USkillDisplayWidget*>                 CombatSkills;                                             // 0x0230(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	TArray<class USkillDisplayWidget*>                 CraftingSkills;                                           // 0x0240(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SecondarySkillsWidget");
		return ptr;
	}


	void Update();
	TArray<struct FName> GetSecondarySkills();
	struct FName GetCategoryId(const struct FName& SkillId);
};


// Class Otherlands.ServerGatekeeper
// 0x0118 (0x0440 - 0x0328)
class AServerGatekeeper : public AActor
{
public:
	struct FString                                     IndexEndpoint;                                            // 0x0328(0x0010) (ZeroConstructor, Config)
	struct FString                                     ServerId;                                                 // 0x0338(0x0010) (ZeroConstructor, Config)
	struct FString                                     ServerPublicKey;                                          // 0x0348(0x0010) (ZeroConstructor, Config)
	struct FString                                     ServerSigningKey;                                         // 0x0358(0x0010) (ZeroConstructor, Config)
	bool                                               bOfficial;                                                // 0x0368(0x0001) (ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0xD7];                                      // 0x0369(0x00D7) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ServerGatekeeper");
		return ptr;
	}

};


// Class Otherlands.ServerListWidget
// 0x0058 (0x0278 - 0x0220)
class UServerListWidget : public UGameBaseWidget
{
public:
	TArray<class UServerSlotWidget*>                   ServerSlotWidgets;                                        // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	class ULoginMessagingWidget*                       LoginMessagingWidget;                                     // 0x0230(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UServerSlotWidget*                           SelectedServerSlotWidget;                                 // 0x0238(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	ESlateVisibility                                   ServerListVisibility;                                     // 0x0240(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0241(0x0007) MISSED OFFSET
	struct FServerFilterData                           ServerFilterData;                                         // 0x0248(0x0028) (Edit, BlueprintVisible)
	bool                                               bIsJoinButtonEnabled;                                     // 0x0270(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0271(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ServerListWidget");
		return ptr;
	}


	void Update();
	void PopulateDummyServerList(int NumServers);
	void OnRefreshButtonClicked();
	void OnLoginServerSkipped();
	void OnLoginMessageReceived();
	void OnLeaveQueue();
	void OnJoinButtonClicked(const struct FString& ServerPassword);
	void HideLoginMessage();
	int GetNumServers();
	void FoundResults();
	void FilterAndSort();
};


// Class Otherlands.ServerSettings
// 0x02D0 (0x0308 - 0x0038)
class UServerSettings : public UDeveloperSettings
{
public:
	float                                              MinRespawnDelay;                                          // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              MaxRespawnDelay;                                          // 0x003C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              RespawnDelayIncrement;                                    // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              RespawnDelayWindow;                                       // 0x0044(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              ForceRespawnDelay;                                        // 0x0048(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              BaseShotVolume;                                           // 0x004C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              BaseHarvestVolume;                                        // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              BaseLandingVolume;                                        // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              BaseMovementVolume;                                       // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              StationaryMovementScalar;                                 // 0x005C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              SprintMovementScalar;                                     // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0064(0x0004) MISSED OFFSET
	struct FTimespan                                   ReckoningServerAgeRequirement;                            // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FTimespan                                   ReckoningServerUpRequirement;                             // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	TArray<struct FWaveScheduleDay>                    WaveScheduleDays;                                         // 0x0078(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	int                                                TimeZoneUTCOffset;                                        // 0x0088(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x008C(0x0004) MISSED OFFSET
	struct FTimespan                                   WarningStageDuration;                                     // 0x0090(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FTimespan                                   PVPStageDuration;                                         // 0x0098(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FWaveScheduleDay                            RestartScheduleDay;                                       // 0x00A0(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, Config, IsPlainOldData)
	float                                              DisconnectLogoutTimeSeconds;                              // 0x00AC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bTrackFactionUseScore;                                    // 0x00B0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bLogExceedFactionUseScore;                                // 0x00B1(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bTrackWarehouseFactionUseScore;                           // 0x00B2(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bSafeLogoff;                                              // 0x00B3(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bNoSafeLogoff;                                            // 0x00B4(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bNoLootPlayers;                                           // 0x00B5(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bFactionlessClans;                                        // 0x00B6(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bFactionlessGroups;                                       // 0x00B7(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	EGameMode                                          ServerGameMode;                                           // 0x00B8(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bNoFactionShields;                                        // 0x00B9(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bNoFactionVictory;                                        // 0x00BA(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bDisableCapturePoints;                                    // 0x00BB(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bDisableOutcastSystem;                                    // 0x00BC(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x00BD(0x0003) MISSED OFFSET
	float                                              TempHostileAttackLength;                                  // 0x00C0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              TempHostileUseScoreLength;                                // 0x00C4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DepositSpiritThreshold;                                   // 0x00C8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DepositSpiritCooldown;                                    // 0x00CC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DamageMultiplier;                                         // 0x00D0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PvpDamageMultiplier;                                      // 0x00D4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PveDamageMultiplier;                                      // 0x00D8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              FriendlyDamageMultiplier;                                 // 0x00DC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              SiegeDamageMultiplier;                                    // 0x00E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PlayerSiegeDamageMultiplier;                              // 0x00E4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              EnvSiegeDamageMultiplier;                                 // 0x00E8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              SiegeRepairPauseDelay;                                    // 0x00EC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	TArray<struct FString>                             ReservedSlotAuthIds;                                      // 0x00F0(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FString                                     ServerPassword;                                           // 0x0100(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	int                                                FactionLimit;                                             // 0x0110(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x0114(0x0004) MISSED OFFSET
	struct FString                                     ServerName;                                               // 0x0118(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FString                                     ServerId;                                                 // 0x0128(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FString                                     ServerDescription;                                        // 0x0138(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FString                                     MetricsPrefix;                                            // 0x0148(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FString                                     MetricsId;                                                // 0x0158(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	float                                              ServerSaveTimer;                                          // 0x0168(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              ServerSaveBackupTimer;                                    // 0x016C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PetPvpIncomingDamageScalar;                               // 0x0170(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PetPvpOutgoingDamageScalar;                               // 0x0174(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PetPveIncomingDamageScalar;                               // 0x0178(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PetPveOutgoingDamageScalar;                               // 0x017C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              PlayerHealthMultiplier;                                   // 0x0180(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              CreatureHealthMultiplier;                                 // 0x0184(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              HarvestDamageMultiplier;                                  // 0x0188(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              ResourceSpawnSpeedMultiplier;                             // 0x018C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              CreatureSpawnSpeedMultiplier;                             // 0x0190(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DamageToPlayerMultiplier;                                 // 0x0194(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DamageToCreatureMultiplier;                               // 0x0198(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DamageFromPlayerMultiplier;                               // 0x019C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DamageFromCreatureMultiplier;                             // 0x01A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              DurabilityDamageMultiplier;                               // 0x01A4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              CreatureSenseRadiusMultiplier;                            // 0x01A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              ServerAgeOffset;                                          // 0x01AC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                ServerAgeOverride;                                        // 0x01B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x01B4(0x0004) MISSED OFFSET
	TArray<int>                                        FactionPopCountOverride;                                  // 0x01B8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	TArray<float>                                      FactionTechRatioOverride;                                 // 0x01C8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	float                                              TreeDamageToSoulScalar;                                   // 0x01D8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              ResearchMultiplier;                                       // 0x01DC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              MaximumPlayTimeForDeleteMinutes;                          // 0x01E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                MaximumDeletesPerAccount;                                 // 0x01E4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                SpawnRestrictionLevelThreshold;                           // 0x01E8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                TeleportRestrictionLevelThreshold;                        // 0x01EC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              QueueLeniencyTimeSeconds;                                 // 0x01F0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x01F4(0x0004) MISSED OFFSET
	TArray<struct FOutcastSetting>                     OutcastLevels;                                            // 0x01F8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	float                                              OutcastVotePercent;                                       // 0x0208(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              OutcastVoteTimeLimit;                                     // 0x020C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	struct FDemolishPermissionSetting                  Demolish;                                                 // 0x0210(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	float                                              PassiveScoreRatePerDay;                                   // 0x0228(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              CapturePointPassiveScoreRatePerDay;                       // 0x022C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              FactionPopAgeDays;                                        // 0x0230(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData06[0x4];                                       // 0x0234(0x0004) MISSED OFFSET
	TArray<float>                                      WarObservationBonus;                                      // 0x0238(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	struct FTimespan                                   BountyCooldownPeriod;                                     // 0x0248(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	struct FTimespan                                   PvpAttackPeriod;                                          // 0x0250(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, Config)
	int                                                MaxPvpAttackerNumber;                                     // 0x0258(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	int                                                MaximumRestrictedUniques;                                 // 0x025C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              LegendaryDropScalar;                                      // 0x0260(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData07[0x4];                                       // 0x0264(0x0004) MISSED OFFSET
	TArray<struct FName>                               GameModeFlags;                                            // 0x0268(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config)
	bool                                               bPersonalTechTree;                                        // 0x0278(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bNoFactions;                                              // 0x0279(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	bool                                               bCreativeMode;                                            // 0x027A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData08[0x1];                                       // 0x027B(0x0001) MISSED OFFSET
	float                                              JumpPenaltyPeriod;                                        // 0x027C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              StackCountScalar;                                         // 0x0280(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              XPMultiplier;                                             // 0x0284(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              SkillXPMultiplier;                                        // 0x0288(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              MaxEncumbranceMultiplier;                                 // 0x028C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              CraftSpeedMultiplier;                                     // 0x0290(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              ReckoningTimeMultiplier;                                  // 0x0294(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              HarvestMultiplier;                                        // 0x0298(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              RareResourceHarvestMultiplier;                            // 0x029C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              StructureHealthScalar;                                    // 0x02A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              StructureArmorScalar;                                     // 0x02A4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              CreatureLevelScalar;                                      // 0x02A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              WaveTimeScalar;                                           // 0x02AC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	float                                              WarehouseDepositMaxCapScalar;                             // 0x02B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Config, IsPlainOldData)
	unsigned char                                      UnknownData09[0x4];                                       // 0x02B4(0x0004) MISSED OFFSET
	struct FAscensionSettings                          Ascension;                                                // 0x02B8(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, Config)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ServerSettings");
		return ptr;
	}

};


// Class Otherlands.ServerTransients
// 0x00A8 (0x00D0 - 0x0028)
class UServerTransients : public UObject
{
public:
	struct FSharedServerSettings                       Shared;                                                   // 0x0028(0x0028) (Edit, BlueprintVisible, BlueprintReadOnly, Transient)
	bool                                               bCreativeMode;                                            // 0x0050(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0051(0x0003) MISSED OFFSET
	float                                              XPMultiplier;                                             // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              SkillXPMultiplier;                                        // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              MaxEncumbranceMultiplier;                                 // 0x005C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              CraftSpeedMultiplier;                                     // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              ReckoningTimeMultiplier;                                  // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              HarvestMultiplier;                                        // 0x0068(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              RareResourceHarvestMultiplier;                            // 0x006C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              StructureHealthScalar;                                    // 0x0070(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              StructureArmorScalar;                                     // 0x0074(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              CreatureLevelScalar;                                      // 0x0078(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              WaveTimeScalar;                                           // 0x007C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	struct FAscensionSettings                          Ascension;                                                // 0x0080(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, Transient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ServerTransients");
		return ptr;
	}

};


// Class Otherlands.ServerSlotWidget
// 0x00B0 (0x02D0 - 0x0220)
class UServerSlotWidget : public UGameBaseWidget
{
public:
	int                                                SlotIndex;                                                // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                DisplayIndex;                                             // 0x0224(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsFiltered;                                              // 0x0228(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0229(0x0007) MISSED OFFSET
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0230(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bIsFavorite;                                              // 0x0238(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bNeedsPassword;                                           // 0x0239(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsSelected;                                              // 0x023A(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x023B(0x0005) MISSED OFFSET
	TArray<int>                                        FactionPopulation;                                        // 0x0240(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<struct FText>                               NewPlayerBuff;                                            // 0x0250(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<struct FText>                               AllPlayerBuff;                                            // 0x0260(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	int                                                TotalPopulation;                                          // 0x0270(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0274(0x0004) MISSED OFFSET
	struct FString                                     ServerType;                                               // 0x0278(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FString                                     ServerName;                                               // 0x0288(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FString                                     ServerDescription;                                        // 0x0298(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<struct FServerListReckoningInfo>            Reckonings;                                               // 0x02A8(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	int                                                ServerAgeInHours;                                         // 0x02B8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsOfficial;                                              // 0x02BC(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsCheatProtected;                                        // 0x02BD(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bHasFactionShields;                                       // 0x02BE(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bHasFactions;                                             // 0x02BF(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	EGameMode                                          ServerGameMode;                                           // 0x02C0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0xF];                                       // 0x02C1(0x000F) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ServerSlotWidget");
		return ptr;
	}


	void SetFavorite(bool bSet);
	void OnUpdated();
	void ExclusiveSelect();
	bool CanJoin();
};


// Class Otherlands.SkillDisplayWidget
// 0x0058 (0x0278 - 0x0220)
class USkillDisplayWidget : public UGameBaseWidget
{
public:
	struct FName                                       SkillId;                                                  // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  Icon;                                                     // 0x0228(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bHasIcon;                                                 // 0x0230(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0231(0x0003) MISSED OFFSET
	int                                                SkillLevel;                                               // 0x0234(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       SkillLevelText;                                           // 0x0238(0x0018) (Edit, BlueprintVisible)
	struct FText                                       DisplayName;                                              // 0x0250(0x0018) (Edit, BlueprintVisible)
	float                                              ProgressBarValue;                                         // 0x0268(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x026C(0x0004) MISSED OFFSET
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0270(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SkillDisplayWidget");
		return ptr;
	}


	void UpdateDisplayInformation(const struct FName& InSkillId);
	void Update();
	void SetLevelAchieved();
	void RefreshLevelAchieved();
	void OpenSkillPerksMenu();
	void OpenSecondarySkillsMenu();
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.SkillTickerSlotWidget
// 0x0020 (0x0240 - 0x0220)
class USkillTickerSlotWidget : public UGameBaseWidget
{
public:
	int                                                SlotIndex;                                                // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TickerTextTimer;                                          // 0x0224(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkillTickerWidget*                          ParentWidget;                                             // 0x0228(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkillDisplayWidget*                         DisplayWidget;                                            // 0x0230(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0238(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SkillTickerSlotWidget");
		return ptr;
	}


	void UpdateDisplayInformation(const struct FName& InSkillId);
	float GetAlpha();
};


// Class Otherlands.SkillTickerWidget
// 0x0050 (0x0270 - 0x0220)
class USkillTickerWidget : public UGameBaseWidget
{
public:
	float                                              TickerTimerDuration;                                      // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                TickerNumLines;                                           // 0x0224(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class USkillTickerSlotWidget*                      TickerSkillSlot1;                                         // 0x0228(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkillTickerSlotWidget*                      TickerSkillSlot2;                                         // 0x0230(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USkillTickerSlotWidget*                      TickerSkillSlot3;                                         // 0x0238(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UClass*                                      TickerSlotWidgetClass;                                    // 0x0240(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                NumLinesActive;                                           // 0x0248(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x24];                                      // 0x024C(0x0024) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SkillTickerWidget");
		return ptr;
	}


	class USkillTickerSlotWidget* GetTickerSlotWidget(int Index);
	float GetTickerLineAlpha(int Index);
	void EventShowTicker();
	void EventHideTicker();
	void AddTickerSlotWidget(const struct FName& SkillId);
};


// Class Otherlands.SkillTreeNode
// 0x0018 (0x0040 - 0x0028)
class USkillTreeNode : public UObject
{
public:
	struct FName                                       RecipeId;                                                 // 0x0028(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	float                                              SkillXP;                                                  // 0x0030(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bKnown : 1;                                               // 0x0034(0x0001) (Net)
	unsigned char                                      bSkilled : 1;                                             // 0x0034(0x0001) (Net)
	unsigned char                                      bMastered : 1;                                            // 0x0034(0x0001) (Net)
	unsigned char                                      UnknownData00[0xB];                                       // 0x0035(0x000B) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SkillTreeNode");
		return ptr;
	}

};


// Class Otherlands.SkillTreeComponent
// 0x00B0 (0x01A0 - 0x00F0)
class USkillTreeComponent : public UActorComponent
{
public:
	struct FScriptMulticastDelegate                    OnSkillLearned;                                           // 0x00F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TArray<class USkillTreeNode*>                      SkillTreeNodes;                                           // 0x0100(0x0010) (Net, ZeroConstructor)
	TArray<struct FName>                               FoundRecipeIds;                                           // 0x0110(0x0010) (Net, ZeroConstructor)
	TArray<struct FName>                               UnlockedRecipeIds;                                        // 0x0120(0x0010) (Net, ZeroConstructor)
	TArray<struct FCraftRecipiePrototype>              Prototypes;                                               // 0x0130(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData00[0x58];                                      // 0x0140(0x0058) MISSED OFFSET
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0198(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SkillTreeComponent");
		return ptr;
	}


	void OnRep_SkillTreeNodes();
	void OnRep_Prototypes();
	float GetSkillXP(const struct FName& RecipeId);
};


// Class Otherlands.SocialWidget
// 0x0020 (0x0240 - 0x0220)
class USocialWidget : public UGameBaseWidget
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0220(0x0020) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SocialWidget");
		return ptr;
	}


	void UpdateWidget();
	void Update();
	void OnPlayerLoggedOut(class AGamePlayerController* ExitPlayer);
	void OnPlayerLoggedIn(class AGamePlayerController* EnterPlayer);
	int GetTotalOnlinePlayers();
	int GetTotalOfflinePlayers();
	void GetOnlinePlayerInfo(int Idx, struct FString* Name);
	void GetOfflinePlayerInfo(int Idx, struct FString* Name);
};


// Class Otherlands.SpawnerBlueprintInstance
// 0x0000 (0x0358 - 0x0358)
class ASpawnerBlueprintInstance : public ASpawnerInstance
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnerBlueprintInstance");
		return ptr;
	}


	class ASpawnGroup* SpawnGroupImpl(class UObject* SpawnGroupOwner, const struct FName& SpecificSpawnGroupId, const struct FSpawnLocation& Location, const struct FSpawnOverrides& Overrides);
	bool InitializeImpl(const struct FName& InSpawnBaseId, const struct FSpawnBaseData& SpawnBase);
	struct FSpawnGroupData GenerateSpawnGroupImpl(const struct FName& InSpawnGroupId);
	bool AddSpawnGroupImpl(const struct FSpawnGroupData& SpawnGroupData, float ProbabilityWeight);
};


// Class Otherlands.SpawnWaveData
// 0x0038 (0x0060 - 0x0028)
class USpawnWaveData : public UObject
{
public:
	unsigned char                                      UnknownData00[0x38];                                      // 0x0028(0x0038) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnWaveData");
		return ptr;
	}

};


// Class Otherlands.SpawnEventData
// 0x0020 (0x0048 - 0x0028)
class USpawnEventData : public UObject
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0028(0x0020) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnEventData");
		return ptr;
	}

};


// Class Otherlands.SpiritData
// 0x05F0 (0x0618 - 0x0028)
class USpiritData : public UObject
{
public:
	unsigned char                                      UnknownData00[0x5F0];                                     // 0x0028(0x05F0) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpiritData");
		return ptr;
	}

};


// Class Otherlands.SpawnWave
// 0x0050 (0x0378 - 0x0328)
class ASpawnWave : public AActor
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x0328(0x0008) MISSED OFFSET
	class ASpawnEvent*                                 OwnerSpawnEvent;                                          // 0x0330(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x40];                                      // 0x0338(0x0040) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnWave");
		return ptr;
	}


	void OnGroupTimer(int Index);
};


// Class Otherlands.SpawnEvent
// 0x0108 (0x0430 - 0x0328)
class ASpawnEvent : public AActor
{
public:
	struct FScriptMulticastDelegate                    OnEventDone;                                              // 0x0328(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	unsigned char                                      UnknownData00[0xF8];                                      // 0x0338(0x00F8) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnEvent");
		return ptr;
	}


	void OnWaveTimer(int Index);
	int GetOwnerFaction();
};


// Class Otherlands.SpawnGroupBlueprint
// 0x0000 (0x0350 - 0x0350)
class ASpawnGroupBlueprint : public ASpawnGroup
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnGroupBlueprint");
		return ptr;
	}


	void OnRemoveMember(class AActor* Member);
	bool OnInitialized();
	void OnAddMember(class AActor* Member);
};


// Class Otherlands.SpawnGroupMemberInterface
// 0x0000 (0x0028 - 0x0028)
class USpawnGroupMemberInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnGroupMemberInterface");
		return ptr;
	}


	bool UpdateLeader();
	bool SetSpawnGroup(class ASpawnGroup* SpawnGroup);
	bool InitWithParameters(const struct FSpawnActorParameters& Params);
	class ASpawnGroup* GetSpawnGroup();
};


// Class Otherlands.SpawnGroupOwnerInterface
// 0x0000 (0x0028 - 0x0028)
class USpawnGroupOwnerInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnGroupOwnerInterface");
		return ptr;
	}


	bool OnGroupRemoved(class ASpawnGroup* SpawnGroup);
	class ASpawnEvent* GetOwnerSpawnEvent();
};


// Class Otherlands.SpawnManager
// 0x0A00 (0x0A28 - 0x0028)
class USpawnManager : public UObject
{
public:
	TMap<struct FName, class ASpawnerInstance*>        SpawnMap;                                                 // 0x0028(0x0050) (ZeroConstructor)
	TMap<struct FName, class USpiritData*>             SpiritMap;                                                // 0x0078(0x0050) (ZeroConstructor)
	class UDataTable*                                  SpawnBaseTable;                                           // 0x00C8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x00D0(0x0050) MISSED OFFSET
	class UDataTable*                                  SpawnGroupTable;                                          // 0x0120(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0128(0x0050) MISSED OFFSET
	class UDataTable*                                  ThreatRuleTable;                                          // 0x0178(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0180(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureBaseTable;                                        // 0x01D0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x01D8(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureClassTable;                                       // 0x0228(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x50];                                      // 0x0230(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureFamilyTable;                                      // 0x0280(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x50];                                      // 0x0288(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureMovementTable;                                    // 0x02D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x50];                                      // 0x02E0(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureMountTable;                                       // 0x0330(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x50];                                      // 0x0338(0x0050) MISSED OFFSET
	class UDataTable*                                  CreaturePetTable;                                         // 0x0388(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x50];                                      // 0x0390(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureResurrectTable;                                   // 0x03E0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData09[0x50];                                      // 0x03E8(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureSummonDisplayTable;                               // 0x0438(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x50];                                      // 0x0440(0x0050) MISSED OFFSET
	class UDataTable*                                  WanderSplineGroupTable;                                   // 0x0490(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x60];                                      // 0x0498(0x0060) MISSED OFFSET
	class UDataTable*                                  SpiritBaseTable;                                          // 0x04F8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData12[0x50];                                      // 0x0500(0x0050) MISSED OFFSET
	class UDataTable*                                  SpiritEventTable;                                         // 0x0550(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData13[0x50];                                      // 0x0558(0x0050) MISSED OFFSET
	class UDataTable*                                  SpiritTreeTable;                                          // 0x05A8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData14[0x50];                                      // 0x05B0(0x0050) MISSED OFFSET
	class UDataTable*                                  SpiritBonusTable;                                         // 0x0600(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData15[0x50];                                      // 0x0608(0x0050) MISSED OFFSET
	class UDataTable*                                  WaveGroupTable;                                           // 0x0658(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData16[0x50];                                      // 0x0660(0x0050) MISSED OFFSET
	class UDataTable*                                  WaveBaseTable;                                            // 0x06B0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData17[0x50];                                      // 0x06B8(0x0050) MISSED OFFSET
	class UDataTable*                                  SpawnEventBaseTable;                                      // 0x0708(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData18[0x50];                                      // 0x0710(0x0050) MISSED OFFSET
	class UDataTable*                                  TempoChannelTable;                                        // 0x0760(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData19[0x68];                                      // 0x0768(0x0068) MISSED OFFSET
	class UDataTable*                                  TempoStateTable;                                          // 0x07D0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData20[0xA0];                                      // 0x07D8(0x00A0) MISSED OFFSET
	class UDataTable*                                  ScheduledWaveTable;                                       // 0x0878(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData21[0x60];                                      // 0x0880(0x0060) MISSED OFFSET
	TMap<struct FName, class USpawnWaveData*>          SpawnWaveMap;                                             // 0x08E0(0x0050) (ZeroConstructor)
	TMap<struct FName, class USpawnEventData*>         SpawnEventMap;                                            // 0x0930(0x0050) (ZeroConstructor)
	unsigned char                                      UnknownData22[0xA8];                                      // 0x0980(0x00A8) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnManager");
		return ptr;
	}

};


// Class Otherlands.SpawnManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class USpawnManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnManagerLibrary");
		return ptr;
	}


	void STATIC_UpdateOverrideNamedParameters(TArray<struct FSpawnNamedParameter> Overrides, struct FSpawnOverrides* Parent);
	void STATIC_UpdateNamedParameters(TArray<struct FSpawnNamedParameter> Overrides, struct FSpawnActorParameters* Parent);
	float STATIC_SpawnSouls(class UObject* WorldContextObject, float SoulsToSpawn, const struct FVector& SpawonPoint, float SpawnRadius, int MaxWispCount, bool bSpawnInSpiritRealm);
	class ASpawnGroup* STATIC_SpawnGroupFromAbility(class UObject* WorldContextObject, class UObject* SpawnGroupOwner, const struct FAbilityData& AbilityData, const TScriptInterface<class UCasterInterface>& Caster, const struct FSpawnLocation& Location, const struct FSpawnOverrides& Overrides);
	class ASpawnGroup* STATIC_SpawnGroupAiWave(class UObject* WorldContextObject, class UObject* SpawnGroupOwner, const struct FWaveGroupData& WaveGroupData, int EntryIndex, const struct FSpawnLocation& Location, const struct FSpawnOverrides& Overrides);
	class ASpawnGroup* STATIC_SpawnGroup(class UObject* WorldContextObject, class UObject* SpawnGroupOwner, const struct FName& SpawnBaseId, const struct FName& SpecificSpawnGroupId, const struct FSpawnLocation& Location, const struct FSpawnOverrides& Overrides);
	class ASpawnGroup* STATIC_SpawnAIAtSafePointInGroup(class UObject* WorldContextObject, class UObject* SpawnGroupOwner, const struct FSpawnActorParameters& Params, const struct FVector& SpawnPoint, float SpawnRadius, float MaxLifeSpan, bool bSpawnInSpiritRealm, int InOverrideFactionId, bool bAllowUnsafe);
	class AAICharacter* STATIC_SpawnAIAtSafePoint(class UObject* WorldContextObject, const struct FSpawnActorParameters& Params, const struct FVector& SpawnPoint, float SpawnRadius, float MaxLifeSpan, bool bSpawnInSpiritRealm, int InOverrideFactionId, class AAIGroup* AIGroup);
	class AAICharacter* STATIC_SpawnAI(class UObject* WorldContextObject, const struct FSpawnActorParameters& Params, const struct FTransform& SpawnTransform, class AAIGroup* AIGroup, bool bSpawnInSpiritRealm, int InOverrideFactionId);
	class AActor* STATIC_SpawnActor(class UObject* WorldContextObject, const struct FSpawnActorParameters& Params, const struct FTransform& SpawnTransform, class ASpawnGroup* SpawnGroup, bool bSpawnInSpiritRealm, int InOverrideFactionId);
	void STATIC_SetOverrideNamedParameterName(const struct FName& ParameterName, const struct FName& NameValue, struct FSpawnOverrides* Parent);
	void STATIC_SetOverrideNamedParameterInt(const struct FName& ParameterName, int IntValue, struct FSpawnOverrides* Parent);
	void STATIC_SetOverrideNamedParameterFloat(const struct FName& ParameterName, float FloatValue, struct FSpawnOverrides* Parent);
	void STATIC_SetNamedParameterName(const struct FName& ParameterName, const struct FName& NameValue, struct FSpawnActorParameters* Parent);
	void STATIC_SetNamedParameterInt(const struct FName& ParameterName, int IntValue, struct FSpawnActorParameters* Parent);
	void STATIC_SetNamedParameterFloat(const struct FName& ParameterName, float FloatValue, struct FSpawnActorParameters* Parent);
	struct FThreatRuleData STATIC_GetThreatRuleData(const struct FName& ID);
	class UTexture2D* STATIC_GetSummonDisplayIcon(const struct FName& ID);
	struct FCreatureSummonDisplayData STATIC_GetSummonDisplayData(const struct FName& ID);
	struct FSpawnGroupData STATIC_GetSpawnGroupData(const struct FName& ID);
	class ASpawnerInstance* STATIC_GetSpawnerInstance(const struct FName& ID);
	struct FName STATIC_GetScheduledWaveEventId(float WaveStrength);
	bool STATIC_GetScalarCreatureStats(class UObject* WorldContextObject, const struct FName& CreatureId, int CreatureLevel, float SummonRating, bool bIsPet, bool bInSpiritRealm, struct FCreatureScalarStats* OutStats);
	TEnumAsByte<EAIReaction> STATIC_GetReactionTo(const struct FName& Source, const struct FName& Target);
	struct FSpawnNamedParameter STATIC_GetOverrideNamedParameter(const struct FSpawnOverrides& Parent, const struct FName& ParameterName, bool* bOutFound);
	bool STATIC_GetObjectBounds(class UObject* WorldContextObject, const struct FVector& Point, float MinRadius, float MaxRadius, TEnumAsByte<ECollisionChannel> ObjectType, bool bAsChannel, struct FBoxSphereBounds* OutBounds);
	struct FSpawnNamedParameter STATIC_GetNamedParameter(const struct FSpawnActorParameters& Parent, const struct FName& ParameterName, bool* bOutFound);
	int STATIC_GetFamilyFaction(const struct FName& Family);
	class UClass* STATIC_GetDefaultSpawnGroupClass();
	class UClass* STATIC_GetDefaultSpawnerInstanceClass();
	struct FName STATIC_GetCreatureFamilyId(TEnumAsByte<ECreatureFamily_CodeMap> CodeMap);
	struct FCreatureFamilyData STATIC_GetCreatureFamily(const struct FName& ID);
	struct FCreatureBaseData STATIC_GetCreatureData(const struct FName& ID);
	struct FCreatureClassData STATIC_GetCreatureClass(const struct FName& ID);
	void STATIC_GenerateSpawnPointQueue(class AGameVolume* Volume, const struct FSpawnPointQueueSettings& Settings, TArray<struct FVector>* OutSpawnPointQueue);
	bool STATIC_GenerateSpawnPoint(class UObject* WorldContextObject, const struct FVector& InSpawnPoint, const struct FSpawnPointSettings& Settings, struct FTransform* OutSpawnTransform);
	void STATIC_CalculateSpawnEventOverrides(const struct FSpawnEventStrength& InStrength, struct FSpawnOverrides* OutOverrides);
};


// Class Otherlands.SpawnVolumeDataManager
// 0x0008 (0x0030 - 0x0028)
class USpawnVolumeDataManager : public UObject
{
public:
	class ASpawnVolume*                                VolumeOwner;                                              // 0x0028(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnVolumeDataManager");
		return ptr;
	}


	bool ProcessUpdate(struct FSpawnVolumeData* Data);
	bool EndPlay(struct FSpawnVolumeData* Data);
	bool DoseMatchCustomCycle(struct FSpawnVolumeData* Data);
	bool BeginPlay(struct FSpawnVolumeData* Data);
};


// Class Otherlands.SpawnVolume
// 0x0080 (0x04E0 - 0x0460)
class ASpawnVolume : public ASpawnVolumeBase
{
public:
	TEnumAsByte<ENetCullRangeType>                     WakeUpRange;                                              // 0x0460(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bOneSpawnPerLocation;                                     // 0x0461(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0462(0x0006) MISSED OFFSET
	TArray<struct FSpawnVolumeData>                    Parameters;                                               // 0x0468(0x0010) (Edit, ZeroConstructor)
	class UNavigationInvokerComponent*                 NavInvoker;                                               // 0x0478(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x60];                                      // 0x0480(0x0060) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpawnVolume");
		return ptr;
	}


	bool SpawnImmediatelyNewOwner(const TScriptInterface<class USpawnGroupOwnerInterface>& GroupOwner, int ParameterIndex, float MinCount, float MaxCount, const struct FName& OverrideSpawnBaseId, const struct FName& OverrideSpawnGroupId, TArray<class ASpawnGroup*>* OutNewSpawns);
	bool SpawnImmediately(int ParameterIndex, float MinCount, float MaxCount, bool bObeyMaxPopulation, const struct FName& OverrideSpawnBaseId, const struct FName& OverrideSpawnGroupId, TArray<class ASpawnGroup*>* OutNewSpawns);
	void SetCycleForcedOff(bool NewVal);
	void OnDayNightChange(bool bIsNight);
	bool IsCycleForcedOff();
	void DespawnAll(int InstanceIdx);
};


// Class Otherlands.SpellBookComponent
// 0x0098 (0x0188 - 0x00F0)
class USpellBookComponent : public UActorComponent
{
public:
	struct FScriptMulticastDelegate                    OnSpellbookUpdated;                                       // 0x00F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TArray<struct FName>                               ActiveSpells;                                             // 0x0100(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData00[0x70];                                      // 0x0110(0x0070) MISSED OFFSET
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0180(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellBookComponent");
		return ptr;
	}


	void ServerRequestInitialSpells();
	void OnRep_UpdateActiveSpells(TArray<struct FName>* OldValues);
	float GetSpellMaxCooldown(const struct FName& PlayerSpellId);
	float GetSpellCooldown(const struct FName& PlayerSpellId);
	struct FName GetSpellByIndex(int Index, bool bActive);
	int GetNumSpells(bool bActive);
	void ClientSpellUnlock(const struct FName& PlayerSpellId, int Count);
	void ClientReplaceSpell(const struct FName& OldPlayerSpellId, const struct FName& NewPlayerSpellId);
	void ClientInitialSpells(const struct FSpellBookInit& Init);
};


// Class Otherlands.SpellBookWidget
// 0x0020 (0x0240 - 0x0220)
class USpellBookWidget : public UGameBaseWidget
{
public:
	TArray<class USpellSlotWidget*>                    spells;                                                   // 0x0220(0x0010) (Edit, BlueprintVisible, ExportObject, ZeroConstructor)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0230(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellBookWidget");
		return ptr;
	}


	void Update();
	void OnRepopulateSpells();
	int GetTotalSpellsNum();
	struct FName GetSpellId(int Idx);
};


// Class Otherlands.SpellCastActionComponent
// 0x00B0 (0x01E0 - 0x0130)
class USpellCastActionComponent : public UActionComponent
{
public:
	unsigned char                                      UnknownData00[0xA0];                                      // 0x0130(0x00A0) MISSED OFFSET
	class APlayerCharacter*                            Player;                                                   // 0x01D0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UAbilityComponent*                           CurrentSpellCast;                                         // 0x01D8(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellCastActionComponent");
		return ptr;
	}


	bool StartUseItem(class UInventoryItem* Item, TEnumAsByte<EUseSpellItemType> UseItemType);
	bool StartSpellCast(const struct FSpellCastParam& SourceParam);
	bool StartPlayerSpellCast(const struct FName& SpellId, class UObject* PreferredTarget, const struct FName& InteractActionId);
	bool StartMountSpellCast(const struct FName& SpellId);
	bool StartBuffSpellCast(const struct FName& SpellId, class UBuffData* Buff, class UObject* PreferredTarget);
	void SetupAbility(class UPlayerAbilityComponent* PlayerSpell, const struct FSpellCastParam& Param);
	void ServerStartSpellCast(const struct FSpellCastParam& SourceParam);
	void QueueUseItem(class UInventoryItem* Item, TEnumAsByte<EUseSpellItemType> UseItemType);
	void QueueSpellCast(const struct FSpellCastParam& SourceParam);
	bool QueueMountSpell(bool bPrimary, bool bFromInput);
	void OnAbilityFinished(const struct FAbilityGameEventData& GameEventData);
	class UAbilityComponent* GetPlayerAbility(const struct FName& SpellId, TEnumAsByte<EPlayerAbilitySource> AbilitySource);
	class UAbilityComponent* GetParamSpell(const struct FSpellCastParam& Param);
	class UAbilityComponent* GetItemAbility(const struct FName& ItemId, TEnumAsByte<EUseSpellItemType> UseType);
	float GetCastSpeed(const struct FName& InAbilityId, bool bIsPlayerAbility);
	struct FName GetAbilityId();
	void ClientStartSpellCast(const struct FSpellCastParam& SourceParam);
};


// Class Otherlands.DamageType_Explosion
// 0x0000 (0x0040 - 0x0040)
class UDamageType_Explosion : public UDamageType
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.DamageType_Explosion");
		return ptr;
	}

};


// Class Otherlands.SpellCastComponent
// 0x0018 (0x0170 - 0x0158)
class USpellCastComponent : public UCombatantComponent
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0158(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellCastComponent");
		return ptr;
	}


	void ServerCastTargetSpell(const struct FCastAction& CastAction, class UObject* PreferredTarget);
	void ServerCastSpawnSpell(const struct FCastAction& CastAction, const struct FTransform& SpawnTransform);
	void ServerCastProjectileSpell(const struct FCastAction& CastAction, const struct FTransform& SpawnTransform);
	void ServerCastHitTraceSpell(const struct FCastAction& CastAction, const struct FVector& ShotDirection, TArray<struct FCombatantHitData> SpellHitData);
	void ServerCastAoESpell(const struct FCastAction& CastAction);
	void MulticastSimulateTeleportSpell(const struct FCastAction& CastAction, const struct FVector& StartLocation, const struct FVector& EndLocation);
	void MulticastSimulateTargetSpell(const struct FCastAction& CastAction, class UObject* Target);
	void MulticastSimulateSpellTracer(const struct FCastAction& CastAction, TArray<struct FCombatantHitData> SpellHitData);
	void MulticastSimulateAoESpell(const struct FCastAction& CastAction, const struct FVector& TargetLocation, const struct FVector& HitNormal, TEnumAsByte<EPhysicalSurface> SurfaceType, TArray<class UPrimitiveComponent*> HitComponents);
	void InitializeCaster(const TScriptInterface<class UCasterInterface>& InOwner);
	bool ForceCastTargetSpell(const struct FCastAction& CastAction, TArray<class UObject*> Targets);
	void ClientSimulateSpellTracer(const struct FCastAction& CastAction, TArray<struct FCombatantHitData> SpellHitData);
	bool CastSpell(const struct FCastAction& CastAction, class UObject* PreferredTarget);
	bool STATIC_CanHitTeam(class UObject* Owner, class UObject* Target, int CastTargetFlags);
};


// Class Otherlands.PrerequisiteCustom
// 0x0000 (0x0028 - 0x0028)
class UPrerequisiteCustom : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PrerequisiteCustom");
		return ptr;
	}


	float GetPrereqFloat(const struct FName& PrereqId, const struct FPrerequisiteData& PrereqData, class ABasicCharacter* Source, class ABasicCharacter* Target, int EntityIndex);
	bool GetPrereqBoolean(const struct FName& PrereqId, const struct FPrerequisiteData& PrereqData, class ABasicCharacter* Source, class ABasicCharacter* Target, int EntityIndex);
};


// Class Otherlands.PrerequisiteInstance
// 0x0058 (0x0080 - 0x0028)
class UPrerequisiteInstance : public UObject
{
public:
	class UPrerequisiteInstance*                       Child[0x2];                                               // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	class UPrerequisiteCustom*                         Custom[0x2];                                              // 0x0038(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       PrereqId;                                                 // 0x0048(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x30];                                      // 0x0050(0x0030) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PrerequisiteInstance");
		return ptr;
	}

};


// Class Otherlands.SpellDisplayWidget
// 0x0088 (0x02A8 - 0x0220)
class USpellDisplayWidget : public UGameBaseWidget
{
public:
	struct FName                                       SpellId;                                                  // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SlotIndex;                                                // 0x0228(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x022C(0x0004) MISSED OFFSET
	class UTexture2D*                                  Icon;                                                     // 0x0230(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsEmpty;                                                 // 0x0238(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsSelected;                                              // 0x0239(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsBeingDragged;                                          // 0x023A(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsSwappable;                                             // 0x023B(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x023C(0x0004) MISSED OFFSET
	struct FText                                       DisplayName;                                              // 0x0240(0x0018) (Edit, BlueprintVisible)
	struct FText                                       Description;                                              // 0x0258(0x0018) (Edit, BlueprintVisible)
	TArray<struct FText>                               StatCostTexts;                                            // 0x0270(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FText                                       CooldownText;                                             // 0x0280(0x0018) (Edit, BlueprintVisible)
	float                                              MaxCooldown;                                              // 0x0298(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CurrentCooldown;                                          // 0x029C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UGameBaseWidget*                             ParentWidget;                                             // 0x02A0(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellDisplayWidget");
		return ptr;
	}


	void Update();
	void SwapSpells(class USpellDisplayWidget* SourceSpell);
	void ShowActivatableBar(bool bShow);
	struct FToolTipData GetTooltipData();
	void DropSpell();
	void CastSpell();
};


// Class Otherlands.SpellManager
// 0x0300 (0x0328 - 0x0028)
class USpellManager : public UObject
{
public:
	class UDataTable*                                  BuffBaseTable;                                            // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0030(0x0050) MISSED OFFSET
	class UDataTable*                                  BuffTriggerTable;                                         // 0x0080(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x50];                                      // 0x0088(0x0050) MISSED OFFSET
	class UDataTable*                                  PrerequisiteTable;                                        // 0x00D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x00E0(0x0050) MISSED OFFSET
	class UDataTable*                                  CooldownGroupTable;                                       // 0x0130(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0138(0x0050) MISSED OFFSET
	class UDataTable*                                  CreatureAbilityTable;                                     // 0x0188(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x50];                                      // 0x0190(0x0050) MISSED OFFSET
	class UDataTable*                                  PlayerAbilityTable;                                       // 0x01E0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x60];                                      // 0x01E8(0x0060) MISSED OFFSET
	class UDataTable*                                  BuffCategoryTable;                                        // 0x0248(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x70];                                      // 0x0250(0x0070) MISSED OFFSET
	class UDataTable*                                  DamageTypeTable;                                          // 0x02C0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x60];                                      // 0x02C8(0x0060) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellManager");
		return ptr;
	}

};


// Class Otherlands.SpellManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class USpellManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellManagerLibrary");
		return ptr;
	}


	void STATIC_SetAudioComponentParameters(class UAudioComponent* AudioComp, TEnumAsByte<EGender> Gender);
	class UAudioComponent* STATIC_PlaySpellSoundAttached(class UWorld* World, class USoundBase* Sound, class USceneComponent* AttachComp, const struct FName& AttachPoint, const struct FSpellSoundParams& Params, class UAudioComponent* ExistingAudioComponent);
	class UAudioComponent* STATIC_PlaySpellSoundAtLocation(class UWorld* World, class USoundBase* Sound, const struct FVector& Location, const struct FSpellSoundParams& Params, class UAudioComponent* ExistingAudioComponent);
	bool STATIC_MakePlayerAbilityInstance(const struct FName& PlayerAbilityId, float InRangeScalar, float InDamageScalar, float InActionTime, bool bInIsExplosive, struct FCastAbilityInstance* OutAbilityInstance);
	bool STATIC_MakeCreatureAbilityInstance(const struct FName& CreatureAbilityId, float InRangeScalar, float InUnitDamageBase, float InSiegeDamageBase, float InActionTime, struct FCastAbilityInstance* OutAbilityInstance);
	class UTexture2D* STATIC_GetPlayerAbilityIcon(const struct FName& ID);
	struct FPlayerAbilityData STATIC_GetPlayerAbilityData(const struct FName& ID);
	float STATIC_GetPlayerAbilityCustomFloatParameter(const struct FPlayerAbilityData& Data, int Index);
	struct FDamageTypeData STATIC_GetDamageTypeData(TEnumAsByte<EDamageType> ID);
	struct FCreatureAbilityData STATIC_GetCreatureAbilityData(const struct FName& ID);
	struct FCooldownGroupData STATIC_GetCooldownGroupData(const struct FName& ID);
	struct FBuffTriggerData STATIC_GetBuffTriggerData(const struct FName& ID);
	float STATIC_GetBuffCustomFloatParameter(const struct FBuffBaseData& Data, int Index);
	struct FBuffCategoryData STATIC_GetBuffCategoryData(const struct FName& ID);
	struct FBuffBaseData STATIC_GetBuffBaseData(const struct FName& ID);
	bool STATIC_ClearObstructions(class UObject* WorldContextObject, class AAICharacter* Instigator, const struct FVector& StartPoint, const struct FVector& Direction, float Radius, float Cone, float DamageScalar);
};


// Class Otherlands.PrerequisiteDataLibrary
// 0x0000 (0x0028 - 0x0028)
class UPrerequisiteDataLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PrerequisiteDataLibrary");
		return ptr;
	}


	float STATIC_GetReferenceValue(const struct FPrerequisiteData& Self, int Index);
	struct FName STATIC_GetReferenceId(const struct FPrerequisiteData& Self, int Index);
	TEnumAsByte<EPrerequisiteEntity> STATIC_GetReferenceEntity(const struct FPrerequisiteData& Self, int Index);
	class UClass* STATIC_GetReferenceCustom(const struct FPrerequisiteData& Self, int Index);
};


// Class Otherlands.SpellSlotWidget
// 0x0050 (0x0270 - 0x0220)
class USpellSlotWidget : public UGameBaseWidget
{
public:
	class UGameBaseWidget*                             ParentWidget;                                             // 0x0220(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       SpellId;                                                  // 0x0228(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SlotIdx;                                                  // 0x0230(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0234(0x0004) MISSED OFFSET
	class USpellDisplayWidget*                         DisplayWidget;                                            // 0x0238(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FText                                       Description;                                              // 0x0240(0x0018) (Edit, BlueprintVisible)
	struct FText                                       DisplayName;                                              // 0x0258(0x0018) (Edit, BlueprintVisible)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpellSlotWidget");
		return ptr;
	}


	void UpdateStatsAffected();
	void Update();
	void GetCharacterStat(int Idx, TEnumAsByte<ECharacterStat>* Stat, float* ReqAmount);
};


// Class Otherlands.SpiritEvent
// 0x0060 (0x0388 - 0x0328)
class ASpiritEvent : public AActor
{
public:
	class USceneComponent*                             SceneComp;                                                // 0x0328(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       SpiritEventId;                                            // 0x0330(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	int                                                OwningFactionId;                                          // 0x0338(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                RequiredEventScore;                                       // 0x033C(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	int                                                EventScore;                                               // 0x0340(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x44];                                      // 0x0344(0x0044) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpiritEvent");
		return ptr;
	}

};


// Class Otherlands.SpiritPortal
// 0x0028 (0x0350 - 0x0328)
class ASpiritPortal : public AActor
{
public:
	class USceneComponent*                             SceneRoot;                                                // 0x0328(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class USceneComponent*                             PortalRoot;                                               // 0x0330(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UBoxComponent*                               PortalDoorCollision;                                      // 0x0338(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	float                                              LastActivatedTime;                                        // 0x0340(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData00[0xC];                                       // 0x0344(0x000C) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SpiritPortal");
		return ptr;
	}


	void OnOverlapPortalDoorCollision(class UPrimitiveComponent* OverlappedComp, class AActor* Other, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& OverlapInfo);
};


// Class Otherlands.SummonCollectionComponent
// 0x04F0 (0x05E0 - 0x00F0)
class USummonCollectionComponent : public UActorComponent
{
public:
	struct FScriptMulticastDelegate                    OnCollectionUpdated;                                      // 0x00F0(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCollectionSlotsUpdated;                                 // 0x0100(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCollectionSlotUpdated;                                  // 0x0110(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCollectionSelected;                                     // 0x0120(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnCollectionResurrect;                                    // 0x0130(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TArray<struct FSummonCollectionEntry>              Collection;                                               // 0x0140(0x0010) (Net, ZeroConstructor, Transient)
	int                                                AllowedSlotCount;                                         // 0x0150(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0154(0x0008) MISSED OFFSET
	int                                                AllowedFavoriteCount;                                     // 0x015C(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	int                                                CurrentFavoriteCount;                                     // 0x0160(0x0004) (Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               SummonAnywhereCheatEnabled;                               // 0x0164(0x0001) (Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0165(0x0003) MISSED OFFSET
	int                                                SummonIndex;                                              // 0x0168(0x0004) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	TEnumAsByte<EAIPetReaction>                        DefaultPetReaction;                                       // 0x016C(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	TEnumAsByte<EAIPetFollow>                          DefaultPetFollow;                                         // 0x016D(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bPetShouldHarvest;                                        // 0x016E(0x0001) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1];                                       // 0x016F(0x0001) MISSED OFFSET
	struct FVector                                     MoveToPoint;                                              // 0x0170(0x000C) (BlueprintVisible, BlueprintReadOnly, Transient, IsPlainOldData)
	TWeakObjectPtr<class ABasicCharacter>              KillTarget;                                               // 0x017C(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x0184(0x0004) MISSED OFFSET
	struct FSummonCollectionEntry                      ActiveSummon;                                             // 0x0188(0x0078) (BlueprintVisible, BlueprintReadOnly, Net, Transient)
	struct FCreatureScalarStats                        ActiveSummonStats;                                        // 0x0200(0x0058) (Transient)
	float                                              PetXpCatchScalar;                                         // 0x0258(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bActiveIsMount;                                           // 0x025C(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bActiveIsPet;                                             // 0x025D(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData04[0x2];                                       // 0x025E(0x0002) MISSED OFFSET
	struct FCreatureMountData                          ActiveMountData;                                          // 0x0260(0x0138) (BlueprintVisible, BlueprintReadOnly, Transient)
	struct FCreaturePetData                            ActivePetData;                                            // 0x0398(0x0148) (BlueprintVisible, BlueprintReadOnly, Transient)
	struct FCreatureResurrectData                      ActiveResurrectData;                                      // 0x04E0(0x0038) (BlueprintVisible, BlueprintReadOnly, Transient)
	class USkeletalMesh*                               ActiveMountMesh;                                          // 0x0518(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	class UMaterialInstance*                           ActiveVariantMaterial;                                    // 0x0520(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	class UClass*                                      ActiveMountAnimClass;                                     // 0x0528(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bExternalDataLoaded;                                      // 0x0530(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x27];                                      // 0x0531(0x0027) MISSED OFFSET
	class APlayerCharacter*                            PlayerOwner;                                              // 0x0558(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData06[0x80];                                      // 0x0560(0x0080) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.SummonCollectionComponent");
		return ptr;
	}


	bool SwapEntries(int FirstIndex, int SecondIndex);
	bool StartResurrectEntry(int Index);
	bool SetPetShouldHarvestUnchecked(bool bSet);
	bool SetPetShouldHarvest(bool bSet);
	bool SetKillTargetUnchecked(class ABasicCharacter* NewKillTarget);
	bool SetKillTarget(class ABasicCharacter* NewKillTarget);
	bool SetFavoriteFlagEntryUnchecked(int Index, bool bSet);
	bool SetFavoriteFlagEntry(int Index, bool bSet);
	bool SetFavoriteFlagActiveEntry(bool bSet);
	bool SetDefaultPetReactionUnchecked(TEnumAsByte<EAIPetReaction> NewPetReaction);
	bool SetDefaultPetReaction(TEnumAsByte<EAIPetReaction> NewPetReaction);
	bool SetDefaultPetFollowWithMove(TEnumAsByte<EAIPetFollow> NewPetFollow, const struct FVector& NewMoveToPoint);
	bool SetDefaultPetFollowUnchecked(TEnumAsByte<EAIPetFollow> NewPetFollow, const struct FVector& NewMoveToPoint);
	bool SetDefaultPetFollow(TEnumAsByte<EAIPetFollow> NewPetFollow);
	bool SetActiveSummonUnchecked(int Index, bool bForce);
	bool SetActiveSummon(int Index, bool bForce);
	void ServerSwapEntries(int FirstIndex, int SecondIndex);
	void ServerStartResurrectEntry(int Index);
	void ServerSetPetShouldHarvest(bool bSet);
	void ServerSetKillTarget(class ABasicCharacter* NewKillTarget);
	void ServerSetFavoriteFlagEntry(int Index, bool bSet);
	void ServerSetDefaultPetReaction(TEnumAsByte<EAIPetReaction> NewPetReaction);
	void ServerSetDefaultPetFollow(TEnumAsByte<EAIPetFollow> NewPetFollow, const struct FVector& NewMoveToPoint);
	void ServerSetActiveSummon(int Index, bool bForce);
	void ServerRenameEntry(int Index, const struct FString& InNewName);
	void ServerFinishResurrect(int Index);
	void ServerClearEntry(int Index);
	bool RenameEntryUnchecked(int Index, const struct FString& InNewName);
	bool RenameEntry(int Index, const struct FString& InNewName);
	bool RenameActiveEntry(const struct FString& InNewName);
	void RefreshCachedStats();
	void ReadySave();
	void OnSummonHit();
	void OnSaveExternalDataResponse(EDatabaseServiceResponse Response);
	void OnResurrectionTimer();
	void OnRep_SummonIndex();
	void OnRep_CurrentFavoriteCount();
	void OnRep_Collection();
	void OnRep_AllowedFavoriteCount();
	void OnRep_ActiveSummon();
	void OnGetExternalDataResponse(EDatabaseServiceResponse Response, const struct FKeyData& Data);
	bool IsSummonValid();
	bool IsExternalDataLoaded();
	bool IsActivePet();
	bool IsActiveMount();
	bool HasEmptySlot();
	int GetScaledPetBuffStackCount();
	int GetScaledMountBuffStackCount();
	float GetResurrectionRemaining();
	float GetResurrectionProgress();
	struct FCreatureResurrectData GetResurrectCost(int Entry);
	bool GetMountAimPoint(struct FVector* OutAimPoint);
	int GetFilledCount();
	float GetEntryStamina(int Index);
	struct FText GetEntryName(int Index);
	float GetEntryHealth(int Index);
	int GetEntryCount();
	struct FSummonCollectionEntry GetEntry(int Index);
	int GetCurrentFavoriteCount();
	int GetAllowedFavoriteCount();
	int GetAllowedCount();
	struct FText GetActiveEntryName();
	void ClientSlotUpdated(int Index);
	void ClientFinishResurrect(int Index, bool bSuccess);
	bool ClearEntry(int Index);
	bool ClearActiveSummon();
	bool CanSummonPet();
	bool CanSetActiveSummonIndex(int Index, bool bIgnoreCurrent);
	bool CanResurrectEntry(int Entry);
	bool CanPetHarvest();
	bool CanMountPet();
	bool CanCommandPet();
	bool CanClearActiveSummon();
	void AddXP(float Amount);
	int AddToCollection(const struct FName& InCreatureBaseId, int InVariantIndex, float InRating);
};


// Class Otherlands.TechTreeOwnerInterface
// 0x0000 (0x0028 - 0x0028)
class UTechTreeOwnerInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TechTreeOwnerInterface");
		return ptr;
	}


	bool RemoveTechBuff(const struct FName& BuffId, int BuffStackCount);
	bool NotifyResearchDone();
	class UObject* GetObject();
	bool AddTechStashSlots(int StashSlots);
	bool AddTechCollectionSlots(int StableSlots);
	bool AddTechBuff(const struct FName& BuffId, int BuffStackCount);
};


// Class Otherlands.TechTree
// 0x0058 (0x0080 - 0x0028)
class UTechTree : public UObject
{
public:
	struct FScriptMulticastDelegate                    OnResearchCompleted;                                      // 0x0028(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TArray<float>                                      ResearchXP;                                               // 0x0038(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, DisableEditOnInstance)
	TEnumAsByte<ETechTreeType>                         TechTreeType;                                             // 0x0048(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0049(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnTechResearchUpdate;                                     // 0x0050(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UObject*                                     TechTreeOwnerObject;                                      // 0x0060(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0068(0x0010) MISSED OFFSET
	class AFaction*                                    FactionOwner;                                             // 0x0078(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TechTree");
		return ptr;
	}


	void OnRep_UpdateTech(TArray<float>* OldValues);
	bool IsTierUnlocked(int Tier);
	bool IsTechResearched(const struct FName& CraftResearchId);
	bool IsTechResearchable(const struct FName& CraftResearchId, int* OutProgressCount);
	bool IsMilestoneUnlocked(int Tier, int* OutProgressCount);
	float GetTechResearchXP(const struct FName& CraftResearchId);
	float GetTechResearchProgress(const struct FName& CraftResearchId);
	TScriptInterface<class UTechTreeOwnerInterface> GetOwner();
	bool AddResearchXP(const struct FName& CraftResearchId, float XP);
};


// Class Otherlands.TeleporterVolume
// 0x0060 (0x03D0 - 0x0370)
class ATeleporterVolume : public AGameVolume
{
public:
	class ATeleporterVolume*                           TeleportTo;                                               // 0x0370(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData)
	struct FSpawnPointSettings                         SpawnSettings;                                            // 0x0378(0x0058) (Edit, BlueprintVisible, BlueprintReadOnly)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TeleporterVolume");
		return ptr;
	}

};


// Class Otherlands.TemperatureWidget
// 0x0058 (0x0278 - 0x0220)
class UTemperatureWidget : public UGameBaseWidget
{
public:
	struct FText                                       AmbientTemperatureText;                                   // 0x0220(0x0018) (Edit, BlueprintVisible)
	float                                              AmbientTemperatureValue;                                  // 0x0238(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x023C(0x0004) MISSED OFFSET
	struct FText                                       PlayerTemperatureText;                                    // 0x0240(0x0018) (Edit, BlueprintVisible)
	float                                              PlayerTemperatureValue;                                   // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              PlayerColdResistValue;                                    // 0x025C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              PlayerHeatResistValue;                                    // 0x0260(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ColdThresholdSafeValue;                                   // 0x0264(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              HeatThresholdSafeValue;                                   // 0x0268(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AmbientColdThresholdSafeValue;                            // 0x026C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AmbientHeatThresholdSafeValue;                            // 0x0270(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0274(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TemperatureWidget");
		return ptr;
	}


	void UpdateWidgetValues();
	void UpdateTemp();
	struct FToolTipData GetTooltipData();
};


// Class Otherlands.TempoTargetInterface
// 0x0000 (0x0028 - 0x0028)
class UTempoTargetInterface : public UInterface
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TempoTargetInterface");
		return ptr;
	}


	float ScaleTempoDelta(const struct FName& TempoChannelId, float Delta);
	void ModifyTempoChannel(const struct FName& TempoChannelId, float Scalar, bool bRemove);
	struct FVector GetTempoLocation();
	class AActor* GetTempoActor();
};


// Class Otherlands.TickerWidget
// 0x0000 (0x0220 - 0x0220)
class UTickerWidget : public UGameBaseWidget
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TickerWidget");
		return ptr;
	}


	void OpenTalentsMenu();
	void OpenPerksMenu();
	void EventShowTicker(const struct FText& TickerText, TEnumAsByte<ETickerType> TickerType);
	void EventHideTicker(TEnumAsByte<ETickerType> TickerType);
};


// Class Otherlands.ToolRadialMenuWidget
// 0x0028 (0x0248 - 0x0220)
class UToolRadialMenuWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  WoodHarvesterIcon;                                        // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  StoneHarvesterIcon;                                       // 0x0228(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  PlantHarvesterIcon;                                       // 0x0230(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  MetalHarvesterIcon;                                       // 0x0238(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  UnarmedIcon;                                              // 0x0240(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ToolRadialMenuWidget");
		return ptr;
	}


	void UpdateButtonIcons();
	void Update();
	void ChooseWoodHarvester();
	void ChooseUnarmed();
	void ChooseStoneHarvester();
	void ChoosePlantHarvester();
	void ChooseMetalHarvester();
};


// Class Otherlands.ToolTipWidget
// 0x0240 (0x0460 - 0x0220)
class UToolTipWidget : public UGameBaseWidget
{
public:
	float                                              HealthBarProgress;                                        // 0x0220(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   HealthBarVisibility;                                      // 0x0224(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EToolTipWidgetMode>                    CurrentMode;                                              // 0x0225(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0226(0x0002) MISSED OFFSET
	struct FText                                       Title;                                                    // 0x0228(0x0018) (Edit, BlueprintVisible)
	struct FText                                       TooltipContentText;                                       // 0x0240(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   ContentTextVisibility;                                    // 0x0258(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0259(0x0007) MISSED OFFSET
	struct FText                                       CategoryText;                                             // 0x0260(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   CategoryTextVisibility;                                   // 0x0278(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0279(0x0007) MISSED OFFSET
	struct FText                                       WeightText;                                               // 0x0280(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   WeightTextVisibility;                                     // 0x0298(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0299(0x0007) MISSED OFFSET
	struct FText                                       DescriptionText;                                          // 0x02A0(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   DescriptionTextVisibility;                                // 0x02B8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x7];                                       // 0x02B9(0x0007) MISSED OFFSET
	struct FText                                       SoulboundText;                                            // 0x02C0(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   SoulboundVisibility;                                      // 0x02D8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x7];                                       // 0x02D9(0x0007) MISSED OFFSET
	class UTexture2D*                                  ItemIcon;                                                 // 0x02E0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       TitleText;                                                // 0x02E8(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   TitleTextVisibility;                                      // 0x0300(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x7];                                       // 0x0301(0x0007) MISSED OFFSET
	struct FText                                       TypeText;                                                 // 0x0308(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   TypeTextVisibility;                                       // 0x0320(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0x7];                                       // 0x0321(0x0007) MISSED OFFSET
	struct FText                                       BaseStatsText;                                            // 0x0328(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   BaseStatsTextVisibility;                                  // 0x0340(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x7];                                       // 0x0341(0x0007) MISSED OFFSET
	struct FText                                       BaseBuffText;                                             // 0x0348(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   BaseBuffTextVisibility;                                   // 0x0360(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData09[0x7];                                       // 0x0361(0x0007) MISSED OFFSET
	struct FText                                       AffixStatsText;                                           // 0x0368(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   AffixStatsTextVisibility;                                 // 0x0380(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData10[0x7];                                       // 0x0381(0x0007) MISSED OFFSET
	struct FText                                       AffixBuffText;                                            // 0x0388(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   AffixBuffTextVisibility;                                  // 0x03A0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData11[0x7];                                       // 0x03A1(0x0007) MISSED OFFSET
	struct FText                                       FlavorText;                                               // 0x03A8(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   FlavorTextVisibility;                                     // 0x03C0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData12[0x7];                                       // 0x03C1(0x0007) MISSED OFFSET
	struct FText                                       FunctionText;                                             // 0x03C8(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   FunctionTextVisibility;                                   // 0x03E0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData13[0x7];                                       // 0x03E1(0x0007) MISSED OFFSET
	struct FText                                       CraftedByText;                                            // 0x03E8(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   CraftedByTextVisibility;                                  // 0x0400(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData14[0x3];                                       // 0x0401(0x0003) MISSED OFFSET
	float                                              Durability;                                               // 0x0404(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       DurabilityText;                                           // 0x0408(0x0018) (Edit, BlueprintVisible)
	ESlateVisibility                                   DurabilityTextVisibility;                                 // 0x0420(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData15[0x7];                                       // 0x0421(0x0007) MISSED OFFSET
	struct FText                                       DecayText;                                                // 0x0428(0x0018) (Edit, BlueprintVisible)
	float                                              DecayTime;                                                // 0x0440(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ESlateVisibility                                   DecayTextVisibility;                                      // 0x0444(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData16[0x3];                                       // 0x0445(0x0003) MISSED OFFSET
	struct FLinearColor                                TitleColor;                                               // 0x0448(0x0010) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              ToolTipOpenDelay;                                         // 0x0458(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData17[0x4];                                       // 0x045C(0x0004) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ToolTipWidget");
		return ptr;
	}


	void ToolTipInit(const struct FToolTipData& ToolTipData);
	void SetToolTipTitle(const struct FText& Text);
	void SetToolTipContextText(const struct FText& Text);
	void SetItemTooltip(const struct FName& ItemId);
	bool OpenToolTip(TEnumAsByte<EToolTipWidgetMode> Mode);
	void OnTooltipInit();
	void OnOpenToolTip();
	void OnCloseToolTip();
	TEnumAsByte<EToolTipWidgetMode> GetToolTipWidgetMode();
	void CloseToolTip(TEnumAsByte<EToolTipWidgetMode> Mode);
};


// Class Otherlands.TranslucentPriorityComponent
// 0x0008 (0x00F8 - 0x00F0)
class UTranslucentPriorityComponent : public UActorComponent
{
public:
	ETranslucentSortLayer                              Layer;                                                    // 0x00F0(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x00F1(0x0003) MISSED OFFSET
	int                                                Offset;                                                   // 0x00F4(0x0004) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TranslucentPriorityComponent");
		return ptr;
	}


	void SetPriority(ETranslucentSortLayer InLayer, int InOffset);
};


// Class Otherlands.TutorialWidget
// 0x0038 (0x0258 - 0x0220)
class UTutorialWidget : public UGameBaseWidget
{
public:
	struct FText                                       Title;                                                    // 0x0220(0x0018) (Edit, BlueprintVisible)
	struct FText                                       Tooltip;                                                  // 0x0238(0x0018) (Edit, BlueprintVisible)
	struct FName                                       CurTutorialId;                                            // 0x0250(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.TutorialWidget");
		return ptr;
	}


	void PopulateTutorialData();
	void OnTutorialTriggered(const struct FName& TutorialId);
	void OnTutorialCleared(const struct FName& TutorialId);
	void ClearTutorial(const struct FName& TutorialId, bool bStopShowingTutorials);
};


// Class Otherlands.UIEventHandler
// 0x0058 (0x0080 - 0x0028)
class UUIEventHandler : public UObject
{
public:
	bool                                               bConsumeAllEvents;                                        // 0x0028(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bPreventGameInput;                                        // 0x0029(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x56];                                      // 0x002A(0x0056) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.UIEventHandler");
		return ptr;
	}


	void SetDelegate(const struct FName& EventName, const struct FScriptDelegate& Delegate);
	TEnumAsByte<EUIResultType> ProcessUIEvent(const struct FName& EventName, bool bPressed, float AxisValue);
};


// Class Otherlands.UIEventHandlerWidget
// 0x0038 (0x0258 - 0x0220)
class UUIEventHandlerWidget : public UGameBaseWidget
{
public:
	struct FScriptMulticastDelegate                    OnEventHandlerActivatedDelegate;                          // 0x0220(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnEventHandlerDeactivatedDelegate;                        // 0x0230(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UUIEventHandler*                             UIEventHandler;                                           // 0x0240(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0248(0x0010) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.UIEventHandlerWidget");
		return ptr;
	}


	void OpenEventHandlerWidget(class UUIEventHandlerWidget* Widget, class UWidgetSwitcher* WidgetSwitcher, EEventHandlerWidgetActivated* Branches);
	void OnEventHandlerDeactivated();
	void OnEventHandlerActivated();
	bool IsEventHandlerActivated();
	class UUIEventHandler* GetUIEventHandler();
	void DeactivateEventHandler();
	void CreateEventHandler(const struct FName& EventName, const struct FScriptDelegate& Delegate);
	void ActivateEventHandler();
};


// Class Otherlands.UIManager
// 0x02C0 (0x02E8 - 0x0028)
class UUIManager : public UObject
{
public:
	unsigned char                                      UnknownData00[0x2B8];                                     // 0x0028(0x02B8) MISSED OFFSET
	class UCurveFloat*                                 PerkTreeCurve;                                            // 0x02E0(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.UIManager");
		return ptr;
	}

};


// Class Otherlands.PlayerVehicle
// 0x0148 (0x04D0 - 0x0388)
class APlayerVehicle : public APawn
{
public:
	unsigned char                                      UnknownData00[0x30];                                      // 0x0388(0x0030) MISSED OFFSET
	class USceneComponent*                             SceneRoot;                                                // 0x03B8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class USkeletalMeshComponent*                      Mesh;                                                     // 0x03C0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class USpringArmComponent*                         CameraBoom;                                               // 0x03C8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	float                                              ClientTickInterval;                                       // 0x03D0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              YawRate;                                                  // 0x03D4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              PitchRate;                                                // 0x03D8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SightRadius;                                              // 0x03DC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              LoseSightRadius;                                          // 0x03E0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxCameraYaw;                                             // 0x03E4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MinPitch;                                                 // 0x03E8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxPitch;                                                 // 0x03EC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CameraPitchOffset;                                        // 0x03F0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x03F4(0x0004) MISSED OFFSET
	struct FName                                       ProjectileBoneName;                                       // 0x03F8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UAnimMontage*                                FireMontage;                                              // 0x0400(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              LeadPredicitionScalar;                                    // 0x0408(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bTargetPerception;                                        // 0x040C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bPerfectAim;                                              // 0x040D(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bAttackOnlyPlayers;                                       // 0x040E(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1];                                       // 0x040F(0x0001) MISSED OFFSET
	class APlayerCharacter*                            Driver;                                                   // 0x0410(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UInventoryComponent*                         InventoryComp;                                            // 0x0418(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	class URangedWeaponComponent*                      RangedWeaponComp;                                         // 0x0420(0x0008) (ExportObject, Net, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               bRotationFromTarget;                                      // 0x0428(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0429(0x0003) MISSED OFFSET
	float                                              TargetYaw;                                                // 0x042C(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              TargetPitch;                                              // 0x0430(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x0434(0x0004) MISSED OFFSET
	struct FName                                       ProjectileSocketName;                                     // 0x0438(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	float                                              MaxHealth;                                                // 0x0440(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              Health;                                                   // 0x0444(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	float                                              armor;                                                    // 0x0448(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x24];                                      // 0x044C(0x0024) MISSED OFFSET
	struct FName                                       VehicleItemId;                                            // 0x0470(0x0008) (BlueprintVisible, BlueprintReadOnly, Net, ZeroConstructor, IsPlainOldData)
	int                                                PlacedFactionId;                                          // 0x0478(0x0004) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x4];                                       // 0x047C(0x0004) MISSED OFFSET
	struct FString                                     PlacedClanId;                                             // 0x0480(0x0010) (ZeroConstructor)
	struct FString                                     PlacedOwnerId;                                            // 0x0490(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData07[0x1C];                                      // 0x04A0(0x001C) MISSED OFFSET
	TWeakObjectPtr<class APlaceableStructure>          OwningStructure;                                          // 0x04BC(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0xC];                                       // 0x04C4(0x000C) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.PlayerVehicle");
		return ptr;
	}


	void OnStructureSyncDone();
	void OnRep_OwningStructure();
	void MulticastSimulateFire();
	void MulticastOnDestroy(class UDestructibleMesh* Destructible, class USoundCue* DestructionSound, const struct FTransform& Transform, float ImpulseForce, const struct FVector& ImpactPoint, const struct FVector& ImpactNormal);
	float GetCurrentYaw();
	float GetCurrentPitch();
};


// Class Otherlands.VehicleActionComponent
// 0x0018 (0x0148 - 0x0130)
class UVehicleActionComponent : public UActionComponent
{
public:
	unsigned char                                      UnknownData00[0x10];                                      // 0x0130(0x0010) MISSED OFFSET
	class APlayerCharacter*                            Player;                                                   // 0x0140(0x0008) (ZeroConstructor, Transient, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.VehicleActionComponent");
		return ptr;
	}

};


// Class Otherlands.VehicleAIController
// 0x0028 (0x0460 - 0x0438)
class AVehicleAIController : public AAIController
{
public:
	class UGameAIPerceptionComponent*                  PerceptionComp;                                           // 0x0438(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	class APlayerVehicle*                              Vehicle;                                                  // 0x0440(0x0008) (ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class ACharacter>                   FocusCharacter;                                           // 0x0448(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               PerceptionRegistered;                                     // 0x0450(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0xF];                                       // 0x0451(0x000F) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.VehicleAIController");
		return ptr;
	}

};


// Class Otherlands.VideoOptionsWidget
// 0x0050 (0x0270 - 0x0220)
class UVideoOptionsWidget : public UGameBaseWidget
{
public:
	struct FString                                     SelectedWindowedItem;                                     // 0x0220(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FString                                     SelectedResolutionItem;                                   // 0x0230(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TEnumAsByte<EWindowMode>                           SavedWindowMode;                                          // 0x0240(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0241(0x0003) MISSED OFFSET
	int                                                SavedWindowWidth;                                         // 0x0244(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SavedWindowHeight;                                        // 0x0248(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ResolutionScale;                                          // 0x024C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ViewDistance;                                             // 0x0250(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ViewDistanceQuality;                                      // 0x0254(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                AntiAliasing;                                             // 0x0258(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                PostProcess;                                              // 0x025C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                Shadow;                                                   // 0x0260(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                Texture;                                                  // 0x0264(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                Effects;                                                  // 0x0268(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bVSync;                                                   // 0x026C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x026D(0x0003) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.VideoOptionsWidget");
		return ptr;
	}


	void SetVideoQualitySettings();
	void SetScreenResolution(int Width, int Height);
	void SetResolutionMode(TEnumAsByte<EWindowMode> WindowMode);
	void SaveVideoSettings();
	void GetVideoQualitySettings();
	bool STATIC_GetSupportedScreenResolutions(TArray<struct FString>* Resolutions);
};


// Class Otherlands.WanderSpline
// 0x0078 (0x03A0 - 0x0328)
class AWanderSpline : public AActor
{
public:
	class USplineComponent*                            SplineComponent;                                          // 0x0328(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UNavigationInvokerComponent*                 NavInvoker;                                               // 0x0330(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       WanderSplineGroupId;                                      // 0x0338(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              OverrideWanderRadius;                                     // 0x0340(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bHasMemory;                                               // 0x0344(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bKeepAttached;                                            // 0x0345(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0346(0x0002) MISSED OFFSET
	int                                                MaxCapacity;                                              // 0x0348(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MaximumDistance;                                          // 0x034C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              Weight;                                                   // 0x0350(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              SplineHeight;                                             // 0x0354(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bAutoClampCurve;                                          // 0x0358(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bRegisterOnFail;                                          // 0x0359(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bDrawDebug;                                               // 0x035A(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x035B(0x0005) MISSED OFFSET
	TArray<struct FWanderState>                        Followers;                                                // 0x0360(0x0010) (ZeroConstructor)
	TArray<struct FWanderDeadLink>                     DeadLinks;                                                // 0x0370(0x0010) (Net, ZeroConstructor)
	unsigned char                                      UnknownData02[0x20];                                      // 0x0380(0x0020) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.WanderSpline");
		return ptr;
	}


	void UpdateCenter();
};


// Class Otherlands.WaterVolume
// 0x0050 (0x04A0 - 0x0450)
class AWaterVolume : public AGameplayVolume
{
public:
	struct FScriptMulticastDelegate                    OnDrinkEvent;                                             // 0x0450(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnFillEvent;                                              // 0x0460(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	TArray<struct FGameplayBuff>                       DrinkBuffs;                                               // 0x0470(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	bool                                               bFillWaterskins;                                          // 0x0480(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0481(0x0007) MISSED OFFSET
	class UStaticMeshComponent*                        WaterPlaneMeshComponent;                                  // 0x0488(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UTranslucentPriorityComponent*               TranslucentPriorityComponent;                             // 0x0490(0x0008) (Edit, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UMaterialInterface*                          WaterMaterial;                                            // 0x0498(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.WaterVolume");
		return ptr;
	}

};


// Class Otherlands.WeaponRadialMenuWidget
// 0x0018 (0x0238 - 0x0220)
class UWeaponRadialMenuWidget : public UGameBaseWidget
{
public:
	class UTexture2D*                                  Weapon1Icon;                                              // 0x0220(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  Weapon2Icon;                                              // 0x0228(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  UnarmedIcon;                                              // 0x0230(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.WeaponRadialMenuWidget");
		return ptr;
	}


	void UpdateButtonIcons();
	void Update();
	void ChooseWeapon2();
	void ChooseWeapon1();
	void ChooseUnarmed();
};


// Class Otherlands.WorldManager
// 0x0470 (0x0498 - 0x0028)
class UWorldManager : public UObject
{
public:
	class UDataTable*                                  MapWaypointDataTable;                                     // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x50];                                      // 0x0030(0x0050) MISSED OFFSET
	class UDataTable*                                  WorldMapDataTable;                                        // 0x0080(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xA0];                                      // 0x0088(0x00A0) MISSED OFFSET
	class UDataTable*                                  ZoneDataTable;                                            // 0x0128(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x50];                                      // 0x0130(0x0050) MISSED OFFSET
	class UDataTable*                                  WeatherDataTable;                                         // 0x0180(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x50];                                      // 0x0188(0x0050) MISSED OFFSET
	class UDataTable*                                  EmoteDataTable;                                           // 0x01D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x60];                                      // 0x01E0(0x0060) MISSED OFFSET
	class UDataTable*                                  EventLogDataTable;                                        // 0x0240(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0xA0];                                      // 0x0248(0x00A0) MISSED OFFSET
	class UDataTable*                                  SlashCommandTable;                                        // 0x02E8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0xA0];                                      // 0x02F0(0x00A0) MISSED OFFSET
	class UDataTable*                                  InteractActionDataTable;                                  // 0x0390(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0xA8];                                      // 0x0398(0x00A8) MISSED OFFSET
	class UDataTable*                                  LoreTextDataTable;                                        // 0x0440(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x50];                                      // 0x0448(0x0050) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.WorldManager");
		return ptr;
	}

};


// Class Otherlands.WorldManagerLibrary
// 0x0000 (0x0028 - 0x0028)
class UWorldManagerLibrary : public UBlueprintFunctionLibrary
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.WorldManagerLibrary");
		return ptr;
	}


	void STATIC_UpdateAxisMapping(const struct FInputAxisKeyMapping& AxisMapping);
	void STATIC_UpdateActionMapping(const struct FInputActionKeyMapping& KeyMapping);
	void STATIC_SetScreenResolution(int Width, int Height);
	void STATIC_SetResolutionMode(TEnumAsByte<EWindowMode> WindowMode);
	void STATIC_SetAxisConfigProperties(const struct FName& AxisName, const struct FInputAxisProperties& Properties, class APlayerController* PlayerController);
	struct FZoneData STATIC_GetZoneData(const struct FName& ID);
	struct FName STATIC_GetZoneAtPoint(class UObject* WorldContextObject, const struct FVector& Point);
	struct FWorldMapData STATIC_GetWorldMapDataByLevel(const struct FString& Level);
	struct FWorldMapData STATIC_GetWorldMapData(const struct FName& ID);
	struct FWeatherData STATIC_GetWeatherData(const struct FName& ID);
	bool STATIC_GetSupportedScreenResolutions(TArray<struct FString>* Resolutions);
	struct FSlashCommandData STATIC_GetSlashCommandData(const struct FName& ID);
	TArray<struct FName> STATIC_GetRadialEmoteIds();
	struct FMapWaypointData STATIC_GetMapWaypointData(const struct FName& ID);
	struct FLoreTextData STATIC_GetLoreTextData(const struct FName& ID);
	struct FName STATIC_GetInteractActionIdFromCodeMap(TEnumAsByte<EInteractAction_CodeMap> CodeMap);
	class UTexture2D* STATIC_GetInteractActionIcon(const struct FName& ID);
	struct FInteractActionData STATIC_GetInteractActionData(const struct FName& ID);
	class UGameUserSettings* STATIC_GetGameSettings();
	class UGameOptions* STATIC_GetGameOptions();
	struct FEventLogEntryParameter STATIC_GetEventLogEntryParameter(const struct FEventLogEntry& Entry, int Index);
	struct FEmoteData STATIC_GetEmoteData(const struct FName& ID);
	struct FInputAxisProperties STATIC_GetAxisConfigProperties(const struct FName& AxisName);
	struct FEventLogEntry STATIC_CreateEventLogEntry(const struct FName& EventLogId, const struct FName& ViewPermissionIdOverride, bool bChatAnnouncementOverride, bool bPersistOverride);
	struct FEventLogEntry STATIC_AddEventLogTextParameter(const struct FText& Value, struct FEventLogEntry* Entry);
	struct FEventLogEntry STATIC_AddEventLogNameParameter(const struct FName& Value, struct FEventLogEntry* Entry);
	struct FEventLogEntry STATIC_AddEventLogIntParameter(int Value, struct FEventLogEntry* Entry);
	struct FEventLogEntry STATIC_AddEventLogFloatParameter(float Value, struct FEventLogEntry* Entry);
};


// Class Otherlands.WorldMapVolume
// 0x0008 (0x03A0 - 0x0398)
class AWorldMapVolume : public AAoiAwareVolume
{
public:
	struct FName                                       WorldMapId;                                               // 0x0398(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.WorldMapVolume");
		return ptr;
	}

};


// Class Otherlands.ZoneVolume
// 0x0020 (0x03B8 - 0x0398)
class AZoneVolume : public AAoiAwareVolume
{
public:
	struct FName                                       ZoneId;                                                   // 0x0398(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x18];                                      // 0x03A0(0x0018) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.ZoneVolume");
		return ptr;
	}


	void OnDayNightChange(bool bIsNight);
};


// Class Otherlands.GameAsyncMaterialLoader
// 0x0040 (0x0068 - 0x0028)
class UGameAsyncMaterialLoader : public UObject
{
public:
	unsigned char                                      UnknownData00[0x40];                                      // 0x0028(0x0040) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("Class Otherlands.GameAsyncMaterialLoader");
		return ptr;
	}

};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
