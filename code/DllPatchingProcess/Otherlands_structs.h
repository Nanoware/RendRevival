#pragma once

// Name: p, Version: 1.0.0

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
// Enums
//---------------------------------------------------------------------------

// Enum Otherlands.EReckoningStage
enum class EReckoningStage : uint8_t
{
	EReckoningStage_None           = 0,
	EReckoningStage_Warning        = 1,
	EReckoningStage_SpawnEvents    = 2,
	EReckoningStage_PVP            = 3,
	EReckoningStage_MAX            = 4
};


// Enum Otherlands.EKilledByType
enum class EKilledByType : uint8_t
{
	KilledBy_Creature              = 0,
	KilledBy_Player                = 1,
	KilledBy_Self                  = 2,
	KilledBy_Unknown               = 3,
	KilledByCount                  = 4,
	EKilledByType_MAX              = 5
};


// Enum Otherlands.EMountHitType
enum class EMountHitType : uint8_t
{
	MountHit_RiderOnly             = 0,
	MountHit_MountOnly             = 1,
	MountHit_Both                  = 2,
	MountHitCount                  = 3,
	EMountHitType_MAX              = 4
};


// Enum Otherlands.EDamageType
enum class EDamageType : uint8_t
{
	DamageType_Physical            = 0,
	DamageType_Natural             = 1,
	DamageType_Elemental           = 2,
	DamageType_Divine              = 3,
	DamageType_Natural_Bleed       = 4,
	DamageType_Natural_Disease     = 5,
	DamageType_Natural_Poison      = 6,
	DamageType_Elemental_Fire      = 7,
	DamageType_Elemental_Cold      = 8,
	DamageType_Elemental_Lighting  = 9,
	DamageType_Divine_Light        = 10,
	DamageType_Divine_Spirit       = 11,
	DamageType_Divine_Dark         = 12,
	DamageType_TameProgress        = 13,
	DamageTypeCount                = 14,
	EDamageType_MAX                = 15
};


// Enum Otherlands.ETempoTargetState
enum class ETempoTargetState : uint8_t
{
	TempoTargetState_Rest          = 0,
	TempoTargetState_RisingAction  = 1,
	TempoTargetState_Climax        = 2,
	TempoTargetState_Recovery      = 3,
	TempoTargetState_FallingAction = 4,
	TempoTargetStateCount          = 5,
	ETempoTargetState_MAX          = 6
};


// Enum Otherlands.ECraftResultType
enum class ECraftResultType : uint8_t
{
	CraftResult_Broken             = 0,
	CraftResult_Normal             = 1,
	CraftResult_Critical           = 2,
	CraftResult_Unknown            = 3,
	CraftResultCount               = 4,
	ECraftResultType_MAX           = 5
};


// Enum Otherlands.EMotionState
enum class EMotionState : uint8_t
{
	MotionState_Still              = 0,
	MotionState_Moving             = 1,
	MotionState_Mounted            = 2,
	MotionStateCount               = 3,
	EMotionState_MAX               = 4
};


// Enum Otherlands.EResourceTriggerTimingType
enum class EResourceTriggerTimingType : uint8_t
{
	ResourceTriggerTiming_OnDamaged = 0,
	ResourceTriggerTiming_OnGotLoot = 1,
	ResourceTriggerTiming_OnDepleted = 2,
	ResourceTriggerTiming_MAX      = 3
};


// Enum Otherlands.EHarvestType
enum class EHarvestType : uint8_t
{
	HarvestType_None               = 0,
	HarvestType_Stone              = 1,
	HarvestType_StoneAlt           = 2,
	HarvestType_Metal              = 3,
	HarvestType_MetalAlt           = 4,
	HarvestType_Wood               = 5,
	HarvestType_WoodAlt            = 6,
	HarvestType_Plant              = 7,
	HarvestType_PlantAlt           = 8,
	HarvestType_Salvage            = 9,
	HarvestType_Any                = 10,
	HarvestType_AnyAlt             = 11,
	HarvestTypeCount               = 12,
	EHarvestType_MAX               = 13
};


// Enum Otherlands.ECharacterStatusFlag
enum class ECharacterStatusFlag : uint8_t
{
	CharStatus_Invulnerable        = 0,
	CharStatus_Root                = 1,
	CharStatus_NoHealthRegen       = 2,
	CharStatus_NoStamRegen         = 3,
	CharStatus_Stunned             = 4,
	CharStatus_Silenced            = 5,
	CharStatus_Disarmed            = 6,
	CharStatus_PhaseShift          = 7,
	CharStatus_Immortal            = 8,
	CharStatusCount                = 9,
	ECharacterStatusFlag_MAX       = 10
};


// Enum Otherlands.EBuffTrigger
enum class EBuffTrigger : uint8_t
{
	BuffTrigger_DoHit              = 0,
	BuffTrigger_TakeHit            = 1,
	BuffTrigger_StandStill         = 2,
	BuffTrigger_Moving             = 3,
	BuffTrigger_Mounted            = 4,
	BuffTrigger_Kill               = 5,
	BuffTrigger_Harvest            = 6,
	BuffTrigger_LowHealth          = 7,
	BuffTrigger_Expire             = 8,
	BuffTrigger_Cleanse            = 9,
	BuffTrigger_Remove             = 10,
	BuffTrigger_Fire               = 11,
	BuffTrigger_CollectSpirits     = 12,
	BuffTrigger_HarvestDepleted    = 13,
	BuffTrigger_DoCriticalHit      = 14,
	BuffTrigger_TakeCriticalHit    = 15,
	BuffTrigger_HighHealth         = 16,
	BuffTrigger_GainCharacterStatus = 17,
	BuffTrigger_LoseCharacterStatus = 18,
	BuffTriggerCount               = 19,
	EBuffTrigger_MAX               = 20
};


// Enum Otherlands.ECharacterStat
enum class ECharacterStat : uint8_t
{
	CharStat_MaxHealth             = 0,
	CharStat_Health                = 1,
	CharStat_MaxStamina            = 2,
	CharStat_Stamina               = 3,
	CharStat_SprintStaminaDrainRate = 4,
	CharStat_StaminaRechargeRate   = 5,
	CharStat_MaxEnergy             = 6,
	CharStat_Energy                = 7,
	CharStat_EnergyDrainRate       = 8,
	CharStat_HungerDamageRate      = 9,
	CharStat_WalkSpeed             = 10,
	CharStat_RunSpeed              = 11,
	CharStat_SprintSpeed           = 12,
	CharStat_CrouchSpeedScalar     = 13,
	CharStat_Immobilization        = 14,
	CharStat_HealthRegenRate       = 15,
	CharStat_MouseSensitivity      = 16,
	CharStat_HealthRegenWaitTime   = 17,
	CharStat_StaminaRegenWaitTime  = 18,
	CharStat_Armor                 = 19,
	CharStat_Weight                = 20,
	CharStat_MaxCarryWeight        = 21,
	CharStat_BodyTemp              = 22,
	CharStat_MaxHydration          = 23,
	CharStat_Hydration             = 24,
	CharStat_HydrationDrainRate    = 25,
	CharStat_ThirstDamageRate      = 26,
	CharStat_HeatResistance        = 27,
	CharStat_ColdResistance        = 28,
	CharStat_WeaponMovePenaltyScalar = 29,
	CharStat_GeneralXPScalar       = 30,
	CharStat_KillXPScalar          = 31,
	CharStat_GatherXPScalar        = 32,
	CharStat_BonusPerkRate         = 33,
	CharStat_GearWeightScalar      = 34,
	CharStat_MaterialWeightScalar  = 35,
	CharStat_AccuracyScalar        = 36,
	CharStat_RangeScalar           = 37,
	CharStat_ClipSizeScalar        = 38,
	CharStat_ReloadTimeScalar      = 39,
	CharStat_FallDamageScalar      = 40,
	CharStat_SprintSpeedScalar     = 41,
	CharStat_MovementNoiseScalar   = 42,
	CharStat_CraftingMovePenaltyScalar = 43,
	CharStat_SprintEnergyDrainRate = 44,
	CharStat_SprintHydrationDrainRate = 45,
	CharStat_JumpEnergyCost        = 46,
	CharStat_JumpHydrationCost     = 47,
	CharStat_HarvestEnergyDrainRate = 48,
	CharStat_HarvestHydrationDrainRate = 49,
	CharStat_MountSpeed            = 50,
	CharStat_MountSprintSpeed      = 51,
	CharStat_SpiritRealmDebuffAddRate = 52,
	CharStat_SpiritRealmDebuffRemoveRate = 53,
	CharStat_SpiritRealmStaminaDrainRate = 54,
	CharStat_JumpHeight            = 55,
	CharStat_RangedDamage          = 56,
	CharStat_HipAccuracyScalar     = 57,
	CharStat_ADSAccuracyScalar     = 58,
	CharStat_HipWeaponMovePenaltyScalar = 59,
	CharStat_ADSWeaponMovePenaltyScalar = 60,
	CharStat_RangedAttackSpeed     = 61,
	CharStat_FallDamageMinThreshold = 62,
	CharStat_FallDamageMaxThreshold = 63,
	CharStat_SpellStatCostScalar   = 64,
	CharStat_SpellCooldownScalar   = 65,
	CharStat_SpiritRealmDamageScalar = 66,
	CharStat_ShortRangeDamageScalar = 67,
	CharStat_LongRangeDamageScalar = 68,
	CharStat_CombatRegenScalar     = 69,
	CharStat_RareResourceChanceScalar = 70,
	CharStat_HeadShotDamageScalar  = 71,
	CharStat_BodyTempFreezeRate    = 72,
	CharStat_BodyTempHeatRate      = 73,
	CharStat_BodyTempFreezeRecoveryRate = 74,
	CharStat_BodyTempHeatRecoveryRate = 75,
	CharStat_MeleeAttackSpeed      = 76,
	CharStat_HeadShotTakeDamageScalar = 77,
	CharStat_HarvestDamageScalar   = 78,
	CharStat_DamageResistance_Natural = 79,
	CharStat_DamageResistance_Elemental = 80,
	CharStat_DamageResistance_Divine = 81,
	CharStat_DamageResistance_Bleed = 82,
	CharStat_DamageResistance_Disease = 83,
	CharStat_DamageResistance_Poison = 84,
	CharStat_DamageResistance_Fire = 85,
	CharStat_DamageResistance_Cold = 86,
	CharStat_DamageResistance_Lightning = 87,
	CharStat_DamageResistance_Light = 88,
	CharStat_DamageResistance_Spirit = 89,
	CharStat_DamageResistance_Dark = 90,
	CharStat_BonusDamagePercent_Natural = 91,
	CharStat_BonusDamagePercent_Elemental = 92,
	CharStat_BonusDamagePercent_Divine = 93,
	CharStat_BonusDamagePercent_Bleed = 94,
	CharStat_BonusDamagePercent_Disease = 95,
	CharStat_BonusDamagePercent_Poison = 96,
	CharStat_BonusDamagePercent_Fire = 97,
	CharStat_BonusDamagePercent_Cold = 98,
	CharStat_BonusDamagePercent_Lightning = 99,
	CharStat_BonusDamagePercent_Light = 100,
	CharStat_BonusDamagePercent_Spirit = 101,
	CharStat_BonusDamagePercent_Dark = 102,
	CharStat_DamageConversion_Natural = 103,
	CharStat_DamageConversion_Elemental = 104,
	CharStat_DamageConversion_Divine = 105,
	CharStat_DamageConversion_Bleed = 106,
	CharStat_DamageConversion_Disease = 107,
	CharStat_DamageConversion_Poison = 108,
	CharStat_DamageConversion_Fire = 109,
	CharStat_DamageConversion_Cold = 110,
	CharStat_DamageConversion_Lightning = 111,
	CharStat_DamageConversion_Light = 112,
	CharStat_DamageConversion_Spirit = 113,
	CharStat_DamageConversion_Dark = 114,
	CharStat_DamageScalar_Physical = 115,
	CharStat_DamageScalar_Natural  = 116,
	CharStat_DamageScalar_Elemental = 117,
	CharStat_DamageScalar_Divine   = 118,
	CharStat_DamageScalar_Bleed    = 119,
	CharStat_DamageScalar_Disease  = 120,
	CharStat_DamageScalar_Poison   = 121,
	CharStat_DamageScalar_Fire     = 122,
	CharStat_DamageScalar_Cold     = 123,
	CharStat_DamageScalar_Lightning = 124,
	CharStat_DamageScalar_Light    = 125,
	CharStat_DamageScalar_Spirit   = 126,
	CharStat_DamageScalar_Dark     = 127,
	CharStat_HipRecoilScalar       = 128,
	CharStat_ADSRecoilScalar       = 129,
	CharStat_OutgoingKnockbackScalar = 130,
	CharStat_IncomingKnockbackScalar = 131,
	CharStat_WeaponSwapSpeedScalar = 132,
	CharStat_ADSCameraFOVOffset    = 133,
	CharStat_ADSCameraDistanceOffset = 134,
	CharStat_TrueDamageScalar      = 135,
	CharStat_ShotsPerBurstScalar   = 136,
	CharStat_CreatureHaste         = 137,
	CharStat_VisibilityMitigation  = 138,
	CharStat_NoiseVolumeReduction  = 139,
	CharStat_SightPenetration      = 140,
	CharStat_CollectedSpirits      = 141,
	CharStat_MaxCollectedSpirits   = 142,
	CharStat_ADSCameraShiftOffset  = 143,
	CharStat_ADSCameraLoftOffset   = 144,
	CharStat_ItemCooldownScalar    = 145,
	CharStat_CreatureAggroScalar   = 146,
	CharStat_HarvestStaminaDrainRate = 147,
	CharStat_WeaponDurabilityConsumptionScalar = 148,
	CharStat_ArmorDurabilityConsumptionScalar = 149,
	CharStat_WoundApplicationChanceScalar = 150,
	CharStat_WoundDurationScalar   = 151,
	CharStat_PoisonApplicationChanceScalar = 152,
	CharStat_PoisonDurationScalar  = 153,
	CharStat_DiseaseApplicationChanceScalar = 154,
	CharStat_DiseaseDurationScalar = 155,
	CharStat_DiseaseEffectScalar   = 156,
	CharStat_SpiritRealmDebuffEffectScalar = 157,
	CharStat_MovementImpairApplicationChanceScalar = 158,
	CharStat_MovementImpairEffectScalar = 159,
	CharStat_MovementImpairDurationScalar = 160,
	CharStat_Breath                = 161,
	CharStat_BreathRecoveryRate    = 162,
	CharStat_BreathDrainRate       = 163,
	CharStat_TameValue             = 164,
	CharStat_PetWeight             = 165,
	CharStat_PetMaxCarryWeight     = 166,
	CharStat_MountMaxStamina       = 167,
	CharStat_MountStamina          = 168,
	CharStat_MountSprintStaminaDrainRate = 169,
	CharStat_MountStaminaRechargeRate = 170,
	CharStat_MountStaminaRegenWaitTime = 171,
	CharStat_PVP_OutgoingDamageScalar = 172,
	CharStat_PVP_IncomingDamageScalar = 173,
	CharStat_ResearchSparkScalar   = 174,
	CharStat_ShrineDurationScalar  = 175,
	CharStat_CraftingSpeedScalar   = 176,
	CharStat_CraftingCriticalChanceModifier = 177,
	CharStat_CraftingBreakChanceModifier = 178,
	CharStat_PotionDurationScalar  = 179,
	CharStat_DepositXPScalar       = 180,
	CharStat_ImmobilizationRecovery = 181,
	CharStat_Noise                 = 182,
	CharStat_NoiseDecay            = 183,
	CharStat_MaxNoise              = 184,
	CharStat_MaxDodgeCount         = 185,
	CharStat_DodgeRechargeTime     = 186,
	CharStat_CraftingReagentScalar = 187,
	CharStatCount                  = 188,
	ECharacterStat_MAX             = 189
};


// Enum Otherlands.EAbilityCastingState
enum class EAbilityCastingState : uint8_t
{
	AbilityCastingState_None       = 0,
	AbilityCastingState_Engaged    = 1,
	AbilityCastingState_Charging   = 2,
	AbilityCastingState_Acting     = 3,
	AbilityCastingState_Processed  = 4,
	AbilityCastingState_Cooldown   = 5,
	AbilityCastingState_MAX        = 6
};


// Enum Otherlands.ETameEventType
enum class ETameEventType : uint8_t
{
	TameEvent_Tick                 = 0,
	TameEvent_Damage               = 1,
	TameEvent_CritDamage           = 2,
	TameEvent_Healing              = 3,
	TameEvent_Proximity            = 4,
	TameEvent_DirectInteractWith   = 5,
	TameEvent_IndirectInteractWith = 6,
	TameEvent_Totem                = 7,
	TameEvent_Siphon               = 8,
	TameEvent_Trap                 = 9,
	TameEvent_Amplify              = 10,
	TameEvent_DamageConversion     = 11,
	TameEvent_Decay                = 12,
	TameEvent_Custom               = 13,
	TameEventCount                 = 14,
	ETameEventType_MAX             = 15
};


// Enum Otherlands.ENoiseType
enum class ENoiseType : uint8_t
{
	NoiseType_Movement             = 0,
	NoiseType_Combat               = 1,
	NoiseType_Harvest              = 2,
	NoiseTypeCount                 = 3,
	ENoiseType_MAX                 = 4
};


// Enum Otherlands.ECanInteractType
enum class ECanInteractType : uint8_t
{
	CanInteract_Never              = 0,
	CanInteract_NotNow             = 1,
	CanInteract_OnCooldown         = 2,
	CanInteract_LowPrivlege        = 3,
	CanInteract_Yes                = 4,
	CanInteract_MAX                = 5
};


// Enum Otherlands.EDatabaseServiceResponse
enum class EDatabaseServiceResponse : uint8_t
{
	EDatabaseServiceResponse__DatabaseServiceResponse_Success = 0,
	EDatabaseServiceResponse__DatabaseServiceResponse_UnauthorizedFailure = 1,
	EDatabaseServiceResponse__DatabaseServiceResponse_UnknownFailure = 2,
	EDatabaseServiceResponse__DatabaseServiceResponse_NotFoundFailure = 3,
	EDatabaseServiceResponse__DatabaseServiceResponse_ConflictFailure = 4,
	EDatabaseServiceResponse__DatabaseServiceResponseCount = 5,
	EDatabaseServiceResponse__EDatabaseServiceResponse_MAX = 6
};


// Enum Otherlands.ESeason
enum class ESeason : uint8_t
{
	Season_Winter                  = 0,
	Season_Spring                  = 1,
	Season_Summer                  = 2,
	Season_Autumn                  = 3,
	Season_Count                   = 4,
	Season_MAX                     = 5
};


// Enum Otherlands.EAccountServiceResponse
enum class EAccountServiceResponse : uint8_t
{
	EAccountServiceResponse__AccountServiceResponse_Unauthorized = 0,
	EAccountServiceResponse__AccountServiceResponse_UnknownFailure = 1,
	EAccountServiceResponse__AccountServiceResponse_Success = 2,
	EAccountServiceResponse__AccountServiceResponseCount = 3,
	EAccountServiceResponse__EAccountServiceResponse_MAX = 4
};


// Enum Otherlands.EUIResultType
enum class EUIResultType : uint8_t
{
	UIResult_Unhandled             = 0,
	UIResult_Handled               = 1,
	UIResult_Skip                  = 2,
	UIResultCount                  = 3,
	EUIResultType_MAX              = 4
};


// Enum Otherlands.EClanOpResult
enum class EClanOpResult : uint8_t
{
	EClanOpResult__ClanOp_Success  = 0,
	EClanOpResult__ClanOp_Failed   = 1,
	EClanOpResult__ClanOp_AlreadyInClan = 2,
	EClanOpResult__ClanOp_WrongFaction = 3,
	EClanOpResult__ClanOp_NotInClan = 4,
	EClanOpResult__ClanOp_LowPriv  = 5,
	EClanOpResult__ClanOp_NoInvite = 6,
	EClanOpResult__ClanOp_Duplicate = 7,
	EClanOpResult__ClanOp_LoneLeader = 8,
	EClanOpResult__ClanOp_MAX      = 9
};


// Enum Otherlands.EGroupOpResult
enum class EGroupOpResult : uint8_t
{
	EGroupOpResult__GroupOp_Success = 0,
	EGroupOpResult__GroupOp_Failed = 1,
	EGroupOpResult__GroupOp_AlreadyInGroup = 2,
	EGroupOpResult__GroupOp_WrongFaction = 3,
	EGroupOpResult__GroupOp_NotInGroup = 4,
	EGroupOpResult__GroupOp_LowPriv = 5,
	EGroupOpResult__GroupOp_NoInvite = 6,
	EGroupOpResult__GroupOp_NoRequest = 7,
	EGroupOpResult__GroupOp_AlreadyLeader = 8,
	EGroupOpResult__GroupOp_MAX    = 9
};


// Enum Otherlands.ETeleportRestriction
enum class ETeleportRestriction : uint8_t
{
	ETeleportRestriction__None     = 0,
	ETeleportRestriction__DropGear = 1,
	ETeleportRestriction__Encumbered = 2,
	ETeleportRestriction__Unavailable = 3,
	ETeleportRestriction__LevelTooLow = 4,
	ETeleportRestriction__Unfamilar = 5,
	ETeleportRestriction__Count    = 6,
	ETeleportRestriction__ETeleportRestriction_MAX = 7
};


// Enum Otherlands.EActionCleanupReason
enum class EActionCleanupReason : uint8_t
{
	ActionCleanupReason_Stop       = 0,
	ActionCleanupReason_Abort      = 1,
	ActionCleanupReason_Finish     = 2,
	ActionCleanupReason_MAX        = 3
};


// Enum Otherlands.EActionNotifyType
enum class EActionNotifyType : uint8_t
{
	ActionNotify_Hit               = 0,
	ActionNotify_Swap              = 1,
	ActionNotify_Release           = 2,
	ActionNotify_Reload            = 3,
	ActionNotify_Draw              = 4,
	ActionNotify_Phase             = 5,
	ActionNotify_MAX               = 6
};


// Enum Otherlands.ESensedByType
enum class ESensedByType : uint8_t
{
	SensedBy_Hearing               = 0,
	SensedBy_Sight                 = 1,
	SensedBy_Aggro                 = 2,
	SensedBy_Damage                = 3,
	SensedBy_Hunt                  = 4,
	SensedBy_MAX                   = 5
};


// Enum Otherlands.EAITargetTrackSpin
enum class EAITargetTrackSpin : uint8_t
{
	AITTSpin_None                  = 0,
	AITTSpin_Left                  = 1,
	AITTSpin_Right                 = 2,
	AITTSpin_MAX                   = 3
};


// Enum Otherlands.EAoiAiAwareType
enum class EAoiAiAwareType : uint8_t
{
	AoiAiAware_Evade               = 0,
	AoiAiAwareCount                = 1,
	EAoiAiAwareType_MAX            = 2
};


// Enum Otherlands.EAoiAwareType
enum class EAoiAwareType : uint8_t
{
	AoiAware_Spawn                 = 0,
	AoiAware_Tempo                 = 1,
	AoiAware_Gameplay              = 2,
	AoiAware_Zone                  = 3,
	AoiAware_Ambient               = 4,
	AoiAware_Water                 = 5,
	AoiAware_WorldMap              = 6,
	AoiAwareCount                  = 7,
	EAoiAwareType_MAX              = 8
};


// Enum Otherlands.ECanAscensionReason
enum class ECanAscensionReason : uint8_t
{
	CanAscensionReason_Success     = 0,
	CanAscensionReason_InvalidPerk = 1,
	CanAscensionReason_TierLocked  = 2,
	CanAscensionReason_NoLearn_RankLocked = 3,
	CanAscensionReason_NoLearn_NotEnoughPoints = 4,
	CanAscensionReason_NoSlot_NotRequired = 5,
	CanAscensionReason_NoSlot_PerkNotKnown = 6,
	CanAscensionReason_NoSlot_AlreadyFilled = 7,
	CanAscensionReasonCount        = 8,
	ECanAscensionReason_MAX        = 9
};


// Enum Otherlands.ESpawnCatalogValue
enum class ESpawnCatalogValue : uint8_t
{
	ESpawnCatalogValue__SpawnNumber = 0,
	ESpawnCatalogValue__IterationNumber = 1,
	ESpawnCatalogValue__StateAge   = 2,
	ESpawnCatalogValue__ScorePerSpawn = 3,
	ESpawnCatalogValue__ScorePerIteration = 4,
	ESpawnCatalogValue__ESpawnCatalogValue_MAX = 5
};


// Enum Otherlands.ESpawnCatalogCompare
enum class ESpawnCatalogCompare : uint8_t
{
	ESpawnCatalogCompare__GreaterThan = 0,
	ESpawnCatalogCompare__GreaterThanOrEqual = 1,
	ESpawnCatalogCompare__LesserThan = 2,
	ESpawnCatalogCompare__LesserThanOrEqual = 3,
	ESpawnCatalogCompare__Equal    = 4,
	ESpawnCatalogCompare__NotEqual = 5,
	ESpawnCatalogCompare__ESpawnCatalogCompare_MAX = 6
};


// Enum Otherlands.EStructureQueryPhase
enum class EStructureQueryPhase : uint8_t
{
	StructureQueryPhase_None       = 0,
	StructureQueryPhase_Init       = 1,
	StructureQueryPhase_Sight      = 2,
	StructureQueryPhase_StartForward = 3,
	StructureQueryPhase_Forward    = 4,
	StructureQueryPhase_StartSiege = 5,
	StructureQueryPhase_Siege      = 6,
	StructureQueryPhase_StartHuge  = 7,
	StructureQueryPhase_Huge       = 8,
	StructureQueryPhase_Result     = 9,
	StructureQueryPhase_NoResult   = 10,
	StructureQueryPhase_MAX        = 11
};


// Enum Otherlands.EAdjustTempoScoreType
enum class EAdjustTempoScoreType : uint8_t
{
	EAdjustTempoScoreType__SetScore = 0,
	EAdjustTempoScoreType__AdjustScore = 1,
	EAdjustTempoScoreType__EAdjustTempoScoreType_MAX = 2
};


// Enum Otherlands.EPathFailReason
enum class EPathFailReason : uint8_t
{
	PathFail_PathFollowComponent   = 0,
	PathFail_TooHigh               = 1,
	PathFail_TooFar                = 2,
	PathFail_TurnAround            = 3,
	PathFail_FollowTickOffNav      = 4,
	PathFail_DidNotMove            = 5,
	PathFail_ShiftOffNav           = 6,
	PathFail_MoveOffNav            = 7,
	PathFail_FollowOffNav          = 8,
	PathFail_CastFailed            = 9,
	PathFailCount                  = 10,
	EPathFailReason_MAX            = 11
};


// Enum Otherlands.ESpawnAction
enum class ESpawnAction : uint8_t
{
	ESpawnAction__AggroTarget      = 0,
	ESpawnAction__PointOfInterest  = 1,
	ESpawnAction__ESpawnAction_MAX = 2
};


// Enum Otherlands.EApplyEffectReason
enum class EApplyEffectReason : uint8_t
{
	ApplyReason_Init               = 0,
	ApplyReason_ModifyStack        = 1,
	ApplyReason_UpdateEffectiveness = 2,
	ApplyReason_Remove             = 3,
	ApplyReason_MAX                = 4
};


// Enum Otherlands.ECastActionErrorType
enum class ECastActionErrorType : uint8_t
{
	ECastActionErrorType__None     = 0,
	ECastActionErrorType__PreCastFailed = 1,
	ECastActionErrorType__InvalidState = 2,
	ECastActionErrorType__RangeFailed = 3,
	ECastActionErrorType__LosToCastFail = 4,
	ECastActionErrorType__ECastActionErrorType_MAX = 5
};


// Enum Otherlands.ECastActionType
enum class ECastActionType : uint8_t
{
	CastAction_PlayerCastHeldItem  = 0,
	CastAction_PlayerSpell         = 1,
	CastAction_CreatureAbility     = 2,
	CastActionCount                = 3,
	ECastActionType_MAX            = 4
};


// Enum Otherlands.ECharacterDeleteResult
enum class ECharacterDeleteResult : uint8_t
{
	ECharacterDeleteResult__CharacterDeleteResult_Success = 0,
	ECharacterDeleteResult__CharacterDeleteResult_TooManyDeletions = 1,
	ECharacterDeleteResult__CharacterDeleteResult_CharacterTooOld = 2,
	ECharacterDeleteResult__CharacterDeleteResult_CharacterInWorld = 3,
	ECharacterDeleteResult__CharacterDeleteResult_Unknown = 4,
	ECharacterDeleteResult__CharacterDeleteResult_MAX = 5
};


// Enum Otherlands.ESpiritRealmState
enum class ESpiritRealmState : uint8_t
{
	SpiritRealm_Out                = 0,
	SpiritRealm_In                 = 1,
	SpiritRealm_Both               = 2,
	SpiritRealm_MAX                = 3
};


// Enum Otherlands.ETargetType
enum class ETargetType : uint8_t
{
	TargetType_None                = 0,
	TargetType_Unit                = 1,
	TargetType_Structure           = 2,
	TargetType_Resource            = 3,
	TargetType_Interact            = 4,
	TargetType_PointOfInterest     = 5,
	TargetType_Friendly            = 6,
	TargetType_MAX                 = 7
};


// Enum Otherlands.EAICombatState
enum class EAICombatState : uint8_t
{
	AICombatState_Attack           = 0,
	AICombatState_Charge           = 1,
	AICombatState_Circle           = 2,
	AICombatState_MAX              = 3
};


// Enum Otherlands.EAICharacterState
enum class EAICharacterState : uint8_t
{
	AICharState_None               = 0,
	AICharState_Leash              = 1,
	AICharState_Idle               = 2,
	AICharState_Aware              = 3,
	AICharState_Combat             = 4,
	AICharState_Interact           = 5,
	AICharState_Flee               = 6,
	AICharState_Flee_Repeat        = 7,
	AICharState_Tempo_DEPRECATED   = 8,
	AICharState_MAX                = 9
};


// Enum Otherlands.EAIAwakeState
enum class EAIAwakeState : uint8_t
{
	AIAwake_NotAwake               = 0,
	AIAwake_Background             = 1,
	AIAwake_VisibleWander          = 2,
	AIAwake_CreatureInteract       = 3,
	AIAwake_PlayerInteract         = 4,
	AIAwake_WaveCombat             = 5,
	AIAwake_MAX                    = 6
};


// Enum Otherlands.EVOTrigger
enum class EVOTrigger : uint8_t
{
	VO_TakeDamageSmall             = 0,
	VO_TakeDamageLarge             = 1,
	VO_TakeDamageTick              = 2,
	VO_Death                       = 3,
	VO_LowHealth                   = 4,
	VO_LowHealthPersist            = 5,
	VO_Emote                       = 6,
	VO_SprintStart                 = 7,
	VO_SprintLoop                  = 8,
	VO_SprintStop                  = 9,
	VOCount                        = 10,
	EVOTrigger_MAX                 = 11
};


// Enum Otherlands.ECharacterEffect
enum class ECharacterEffect : uint8_t
{
	CharacterEffect_Spawn          = 0,
	CharacterEffect_Ascend         = 1,
	CharacterEffect_LevelUp        = 2,
	CharacterEffect_SkillUp        = 3,
	CharacterEffect_CorpseLocal    = 4,
	CharacterEffect_CorpseGlobal   = 5,
	CharacterEffect_AscensionPoint = 6,
	CharacterEffectCount           = 7,
	ECharacterEffect_MAX           = 8
};


// Enum Otherlands.ESecondarySkillStat
enum class ESecondarySkillStat : uint8_t
{
	SkillStat_Speed                = 0,
	SkillStat_Damage               = 1,
	SkillStat_PvpDamage            = 2,
	SkillStat_PveDamage            = 3,
	SkillStat_Yield                = 4,
	SkillStat_Reload               = 5,
	SkillStat_Swap                 = 6,
	SkillStat_Accuracy             = 7,
	SkillStat_Resist               = 8,
	SkillStat_Sound                = 9,
	SkillStat_ClipSize             = 10,
	SkillStat_HeadhostScalar       = 11,
	SkillStat_TrueDamagePercent    = 12,
	SkillStat_HipRecoil            = 13,
	SkillStat_ADSRecoil            = 14,
	SkillStat_HipMoveSpeed         = 15,
	SkillStat_ADSMoveSpeed         = 16,
	SkillStat_KnockbackScalar      = 17,
	SkillStat_RangeScalar          = 18,
	SkillStat_AdditiveDrop2        = 19,
	SkillStat_AdditiveDrop3        = 20,
	SkillStat_AdditiveDrop4        = 21,
	SkillStat_AdditiveDrop5        = 22,
	SkillStat_AdditiveDrop6        = 23,
	SkillStat_AdditiveDrop7        = 24,
	SkillStat_AdditiveDrop8        = 25,
	SkillStat_ADSCameraFOVOffset   = 26,
	SkillStat_ADSCameraDistanceOffset = 27,
	SkillStat_ShotsPerBurstScalar  = 28,
	SkillStat_ADSCameraShiftOffset = 29,
	SkillStat_ADSCameraLoftOffset  = 30,
	SkillStat_XPScalar             = 31,
	SkillStat_CriticalChanceModifier = 32,
	SkillStat_BreakChanceModifier  = 33,
	SkillStat_ShotsPerBurstOffset  = 34,
	SkillStat_ClipSizeOffset       = 35,
	SkillStatCount                 = 36,
	ESecondarySkillStat_MAX        = 37
};


// Enum Otherlands.ESecondarySkill
enum class ESecondarySkill : uint8_t
{
	SecondarySkill_HarvestWood     = 0,
	SecondarySkill_HarvestStone    = 1,
	SecondarySkill_HarvestMetal    = 2,
	SecondarySkill_HarvestPlant    = 3,
	SecondarySkill_HarvestCreature = 4,
	SecondarySkill_Bow             = 5,
	SecondarySkill_Repeater        = 6,
	SecondarySkill_Crossbow        = 7,
	SecondarySkill_SpikeLauncher   = 8,
	SecondarySkill_Blaster         = 9,
	SecondarySkill_SiegeWeapons    = 10,
	SecondarySkill_Adventuring     = 11,
	SecondarySkill_Construction    = 12,
	SecondarySkill_Invention       = 13,
	SecondarySkill_Mysticism       = 14,
	SecondarySkill_Cooking         = 15,
	SecondarySkillCount            = 16,
	ESecondarySkill_MAX            = 17
};


// Enum Otherlands.ECraftSkillTreeCategory
enum class ECraftSkillTreeCategory : uint8_t
{
	CraftSkillCategory_Tools       = 0,
	CraftSkillCategory_Weapons     = 1,
	CraftSkillCategory_Ammo        = 2,
	CraftSkillCategory_Armor       = 3,
	CraftSkillCategory_Building    = 4,
	CraftSkillCategory_Misc        = 5,
	CraftSkillCategory_Refinery    = 6,
	CraftSkillCategory_Station     = 7,
	CraftSkillCategoryCount        = 8,
	ECraftSkillTreeCategory_MAX    = 9
};


// Enum Otherlands.EGender
enum class EGender : uint8_t
{
	Gender_Male                    = 0,
	Gender_Female                  = 1,
	GenderCount                    = 2,
	EGender_MAX                    = 3
};


// Enum Otherlands.EWaveSpawnLocation
enum class EWaveSpawnLocation : uint8_t
{
	WaveSpawnLocation_Any          = 0,
	WaveSpawnLocation_Front        = 1,
	WaveSpawnLocation_FlankRight   = 2,
	WaveSpawnLocation_FlankLeft    = 3,
	WaveSpawnLocation_Rear         = 4,
	WaveSpawnLocation_Action       = 5,
	WaveSpawnLocation_Weakness     = 6,
	WaveSpawnLocation_Defense      = 7,
	WaveSpawnLocation_MAX          = 8
};


// Enum Otherlands.EHairSection
enum class EHairSection : uint8_t
{
	HairSection_Skull              = 0,
	HairSection_Face               = 1,
	HairSection_Back               = 2,
	HairSection_Sideburns          = 3,
	HairSection_FacialShadow       = 4,
	HairSection_FacialHair         = 5,
	HairSection_FacialHairAlternate = 6,
	HairSectionCount               = 7,
	EHairSection_MAX               = 8
};


// Enum Otherlands.ECastTargetFlag
enum class ECastTargetFlag : uint8_t
{
	CastTargetFlag_Enemy           = 0,
	CastTargetFlag_Friendly        = 1,
	CastTargetFlag_Player          = 2,
	CastTargetFlag_Creature        = 3,
	CastTargetFlag_Resource        = 4,
	CastTargetFlag_MAX             = 5
};


// Enum Otherlands.ECastTargetType
enum class ECastTargetType : uint8_t
{
	CastTarget_Enemy               = 0,
	CastTarget_Friendly            = 1,
	CastTarget_Both                = 2,
	CastTargetCount                = 3,
	ECastTargetType_MAX            = 4
};


// Enum Otherlands.ECastMethod
enum class ECastMethod : uint8_t
{
	CastMethod_Projectile          = 0,
	CastMethod_HitScan             = 1,
	CastMethod_Ground              = 2,
	CastMethod_Self                = 3,
	CastMethod_PBAE                = 4,
	CastMethod_Custom              = 5,
	CastMethod_Target              = 6,
	CastMethodCount                = 7,
	ECastMethod_MAX                = 8
};


// Enum Otherlands.EAIGroupIndividualType
enum class EAIGroupIndividualType : uint8_t
{
	AIGroupIndividualType_MeleeGrunt = 0,
	AIGroupIndividualType_RangedGrunt = 1,
	AIGroupIndividualType_MeleeSiege = 2,
	AIGroupIndividualType_RangedSiege = 3,
	AIGroupIndividualType_Leaper   = 4,
	AIGroupIndividualType_Sapper   = 5,
	AIGroupIndividualType_PlayerKiller = 6,
	AIGroupIndividualType_Summoner = 7,
	AIGroupIndividualType_Chaos    = 8,
	AIGroupIndividualType_Stealther = 9,
	AIGroupIndividualType_Licker   = 10,
	AIGroupIndividualTypeCount     = 11,
	EAIGroupIndividualType_MAX     = 12
};


// Enum Otherlands.EAIGroupType
enum class EAIGroupType : uint8_t
{
	AIGroupType_StructureDamager   = 0,
	AIGroupType_PlayerDamager      = 1,
	AIGroupType_Infiltrator        = 2,
	AIGroupType_Berserker          = 3,
	AIGroupTypeCount               = 4,
	EAIGroupType_MAX               = 5
};


// Enum Otherlands.EAIPetFollow
enum class EAIPetFollow : uint8_t
{
	AIPetFollow_Follow             = 0,
	AIPetFollow_Stay               = 1,
	AIPetFollow_MoveTo             = 2,
	AIPetFollowCount               = 3,
	EAIPetFollow_MAX               = 4
};


// Enum Otherlands.EAIPetReaction
enum class EAIPetReaction : uint8_t
{
	AIPetReaction_Flee             = 0,
	AIPetReaction_Passive          = 1,
	AIPetReaction_Neutral          = 2,
	AIPetReaction_Aggressive       = 3,
	AIPetReaction_MAX              = 4
};


// Enum Otherlands.EAIReaction
enum class EAIReaction : uint8_t
{
	AIReaction_Ignore              = 0,
	AIReaction_Attack              = 1,
	AIReaction_Flee                = 2,
	AIReaction_Interact            = 3,
	AIReaction_MAX                 = 4
};


// Enum Otherlands.EAbilityTargetFlagType
enum class EAbilityTargetFlagType : uint8_t
{
	AbilityTargetFlag_Player       = 0,
	AbilityTargetFlag_Creature     = 1,
	AbilityTargetFlag_DestroyObstruction = 2,
	AbilityTargetFlag_Structure    = 3,
	AbilityTargetFlag_Interact     = 4,
	AbilityTargetFlag_Self         = 5,
	AbilityTargetFlag_Friendly     = 6,
	AbilityTargetFlag_MAX          = 7
};


// Enum Otherlands.EAbilityPurpose
enum class EAbilityPurpose : uint8_t
{
	AbilityPurpose_Damage          = 0,
	AbilityPurpose_AoE             = 1,
	AbilityPurpose_Snare           = 2,
	AbilityPurpose_CloseGap        = 3,
	AbilityPurpose_GainDistance    = 4,
	AbilityPurpose_Buff            = 5,
	AbilityPurpose_Debuff          = 6,
	AbilityPurpose_Heal            = 7,
	AbilityPurpose_Assassinate     = 8,
	AbilityPurpose_MAX             = 9
};


// Enum Otherlands.EXPSource
enum class EXPSource : uint8_t
{
	XPSource_General               = 0,
	XPSource_Kill                  = 1,
	XPSource_Gather                = 2,
	XPSource_Cheat                 = 3,
	XPSource_Craft                 = 4,
	XPSource_Deposit               = 5,
	XPSource_MAX                   = 6
};


// Enum Otherlands.ECharacterArchetype
enum class ECharacterArchetype : uint8_t
{
	CharArchetype_Scout            = 0,
	CharArchetype_Soldier          = 1,
	CharArchetype_Survivalist      = 2,
	CharArchetype_Mystic           = 3,
	CharArchetypeCount             = 4,
	ECharacterArchetype_MAX        = 5
};


// Enum Otherlands.ECharacterStance
enum class ECharacterStance : uint8_t
{
	CharStance_Default             = 0,
	CharStance_Melee               = 1,
	CharStance_Spear               = 2,
	CharStance_Offhand             = 3,
	CharStance_MeleeOffhand        = 4,
	CharStance_SpearOffhand        = 5,
	CharStance_1HRanged            = 6,
	CharStance_1HRangedOffhand     = 7,
	CharStance_2HRanged            = 8,
	CharStance_Bow                 = 9,
	CharStance_BowADS              = 10,
	CharStance_Crouch              = 11,
	CharStance_MeleeCrouch         = 12,
	CharStance_SpearCrouch         = 13,
	CharStance_OffhandCrouch       = 14,
	CharStance_MeleeOffhandCrouch  = 15,
	CharStance_SpearOffhandCrouch  = 16,
	CharStance_1HRangedCrouch      = 17,
	CharStance_1HRangedOffhandCrouch = 18,
	CharStance_2HRangedCrouch      = 19,
	CharStance_BowCrouch           = 20,
	CharStance_BowADSCrouch        = 21,
	CharStance_Mounted             = 22,
	CharStance_SpearMounted        = 23,
	CharStance_1HRangedMounted     = 24,
	CharStance_2HRangedMounted     = 25,
	CharStance_BowMounted          = 26,
	CharStance_BowADSMounted       = 27,
	CharStance_BowEmpty            = 28,
	CharStance_MAX                 = 29
};


// Enum Otherlands.EHeldItemType
enum class EHeldItemType : uint8_t
{
	HeldItem_None                  = 0,
	HeldItem_Melee                 = 1,
	HeldItem_Spear                 = 2,
	HeldItem_Repair                = 3,
	HeldItem_1HRanged              = 4,
	HeldItem_2HRanged              = 5,
	HeldItem_Syphon                = 6,
	HeldItem_Bow                   = 7,
	HeldItem_Build                 = 8,
	HeldItem_MAX                   = 9
};


// Enum Otherlands.ECharacterMoveSpeed
enum class ECharacterMoveSpeed : uint8_t
{
	CharMoveSpeed_None             = 0,
	CharMoveSpeed_Walk             = 1,
	CharMoveSpeed_Run              = 2,
	CharMoveSpeed_MAX              = 3
};


// Enum Otherlands.EAscensionFeature
enum class EAscensionFeature : uint8_t
{
	AscensionFeature_SummonFavorite = 0,
	AscensionFeature_SummonSlot    = 1,
	AscensionFeature_MAX           = 2
};


// Enum Otherlands.EAscensionPerkDisplayType
enum class EAscensionPerkDisplayType : uint8_t
{
	AscensionPerkDisplay_Default   = 0,
	AscensionPerkDisplay_Construction = 1,
	AscensionPerkDisplay_HairColor = 2,
	AscensionPerkDisplay_HairStyle = 3,
	AscensionPerkDisplay_Recipe    = 4,
	AscensionPerkDisplay_Upgradeable = 5,
	AscensionPerkDisplay_Slotable  = 6,
	AscensionPerkDisplay_MAX       = 7
};


// Enum Otherlands.EAscensionPerkCategory
enum class EAscensionPerkCategory : uint8_t
{
	AscensionPerkCategory_Other    = 0,
	AscensionPerkCategory_CombatBonus = 1,
	AscensionPerkCategory_NonCombatBonus = 2,
	AscensionPerkCategory_CharacterCosmetic = 3,
	AscensionPerkCategory_BuildingCosmetic = 4,
	AscensionPerkCategory_MAX      = 5
};


// Enum Otherlands.ECharacterStatDisplayType
enum class ECharacterStatDisplayType : uint8_t
{
	CharacterStatDisplayType_Additive = 0,
	CharacterStatDisplayType_Scalar = 1,
	CharacterStatDisplayType_ScalarSmallerIsBetter = 2,
	CharacterStatDisplayType_AdditiveScalar = 3,
	CharacterStatDisplayType_AdditiveScalarSmallerIsBetter = 4,
	CharacterStatDisplayTypeCount  = 5,
	ECharacterStatDisplayType_MAX  = 6
};


// Enum Otherlands.EScalarConversionCurve
enum class EScalarConversionCurve : uint8_t
{
	ScalarConversionCurve_ArmorDamageMitigation = 0,
	ScalarConversionCurve_OtherDamageMitigation = 1,
	ScalarConversionCurveCount     = 2,
	EScalarConversionCurve_MAX     = 3
};


// Enum Otherlands.ESystemMessage_CodeMap
enum class ESystemMessage_CodeMap : uint8_t
{
	SystemMessage_CodeMap_GenericError = 0,
	SystemMessage_CodeMap_LowPriv  = 1,
	SystemMessage_CodeMap_JoinChannel = 2,
	SystemMessage_CodeMap_LeaveChannel = 3,
	SystemMessage_CodeMap_KillMessage = 4,
	SystemMessage_CodeMap_ClanJoin = 5,
	SystemMessage_CodeMap_ClanLeave = 6,
	SystemMessage_CodeMap_ClanKicked = 7,
	SystemMessage_CodeMap_ClanPromote = 8,
	SystemMessage_CodeMap_ClanDemote = 9,
	SystemMessage_CodeMap_ClanError = 10,
	SystemMessage_CodeMap_ClassPerkReset = 11,
	SystemMessage_CodeMap_SkillPerkReset = 12,
	SystemMessage_CodeMap_GameEndNotify = 13,
	SystemMessage_CodeMap_Broadcast = 14,
	SystemMessage_CodeMap_FactionMotd = 15,
	SystemMessage_CodeMap_FactionShieldUp = 16,
	SystemMessage_CodeMap_GroupJoin = 17,
	SystemMessage_CodeMap_GroupLeave = 18,
	SystemMessage_CodeMap_GroupKicked = 19,
	SystemMessage_CodeMap_GroupError = 20,
	SystemMessage_CodeMap_RestartNotify = 21,
	SystemMessage_CodeMap_Unmapped = 22,
	SystemMessageCodeMapCount      = 23,
	ESystemMessage_CodeMap_MAX     = 24
};


// Enum Otherlands.EChatChannelType
enum class EChatChannelType : uint8_t
{
	ChatChannelType_Say            = 0,
	ChatChannelType_Faction        = 1,
	ChatChannelType_Whisper        = 2,
	ChatChannelType_General        = 3,
	ChatChannelType_Clan           = 4,
	ChatChannelType_FactionAnnouncement = 5,
	ChatChannelType_ClanAnnouncement = 6,
	ChatChannelType_Emote          = 7,
	ChatChannelType_System         = 8,
	ChatChannelType_Broadcast      = 9,
	ChatChannelType_Group          = 10,
	ChatChannelType_GroupAnnouncement = 11,
	ChatChannelTypeCount           = 12,
	EChatChannelType_MAX           = 13
};


// Enum Otherlands.EChooseItemToggleMode
enum class EChooseItemToggleMode : uint8_t
{
	ToggleMode_CycleUp             = 0,
	ToggleMode_CycleDown           = 1,
	ToggleMode_PutAway             = 2,
	ToggleMode_Leave               = 3,
	ToggleMode_None                = 4,
	ToggleMode_MAX                 = 5
};


// Enum Otherlands.EChooseItemActionType
enum class EChooseItemActionType : uint8_t
{
	ChooseItemAction_None          = 0,
	ChooseItemAction_Start         = 1,
	ChooseItemAction_Fill          = 2,
	ChooseItemAction_Drink         = 3,
	ChooseItemAction_Swap          = 4,
	ChooseItemAction_Consume       = 5,
	ChooseItemAction_MirrorPose    = 6,
	ChooseItemAction_NormalPose    = 7,
	ChooseItemAction_MAX           = 8
};


// Enum Otherlands.EGatekeeperConnectionResult
enum class EGatekeeperConnectionResult : uint8_t
{
	EGatekeeperConnectionResult__GatekeeperConnectionResult_Success = 0,
	EGatekeeperConnectionResult__GatekeeperConnectionResult_FailureBeaconConnect = 1,
	EGatekeeperConnectionResult__GatekeeperConnectionResult_FailureBeaconMissing = 2,
	EGatekeeperConnectionResult__GatekeeperConnectionResult_FailureTicketRedemption = 3,
	EGatekeeperConnectionResult__GatekeeperConnectionResult_FailureTicketRetrieval = 4,
	EGatekeeperConnectionResult__GatekeeperConnectionResult_FailureUnauthorized = 5,
	EGatekeeperConnectionResult__GatekeeperConnectionResult_FailureMalformedResponse = 6,
	EGatekeeperConnectionResult__GatekeeperConnectionResultCount = 7,
	EGatekeeperConnectionResult__EGatekeeperConnectionResult_MAX = 8
};


// Enum Otherlands.EFeedbackEventType
enum class EFeedbackEventType : uint8_t
{
	FeedbackEvent_Damage           = 0,
	FeedbackEvent_Evade            = 1,
	FeedbackEvent_Tame             = 2,
	FeedbackEvent_IneffectiveDamage = 3,
	FeedbackEvent_IneffectiveTool  = 4,
	FeedbackEvent_HarvestDamage    = 5,
	FeedbackEvent_GainSouls        = 6,
	FeedbackEvent_MAX              = 7
};


// Enum Otherlands.EDamageTargetType
enum class EDamageTargetType : uint8_t
{
	DamageTarget_Unit              = 0,
	DamageTarget_Siege             = 1,
	DamageTargetCount              = 2,
	EDamageTargetType_MAX          = 3
};


// Enum Otherlands.EContextMenuSlotState
enum class EContextMenuSlotState : uint8_t
{
	ContextMenuSlotState_Unselected = 0,
	ContextMenuSlotState_Selected  = 1,
	ContextMenuSlotState_Waiting   = 2,
	ContextMenuSlotState_WaitOver  = 3,
	ContextMenuSlotState_MAX       = 4
};


// Enum Otherlands.EContextMenuActionType
enum class EContextMenuActionType : uint8_t
{
	ContextMenuActionType_None     = 0,
	ContextMenuActionType_Cancel   = 1,
	ContextMenuActionType_RepairPlaceable = 2,
	ContextMenuActionType_DestroyPlaceable = 3,
	ContextMenuActionType_MAX      = 4
};


// Enum Otherlands.EControlPointBuffTiming
enum class EControlPointBuffTiming : uint8_t
{
	ControlPointBuffTiming_NoOwner_AllFactions = 0,
	ControlPointBuffTiming_HasOwner_OwningFaction = 1,
	ControlPointBuffTiming_HasOwner_OtherFactions = 2,
	ControlPointBuffTimingCount    = 3,
	EControlPointBuffTiming_MAX    = 4
};


// Enum Otherlands.ECraftSkillUpReasonType
enum class ECraftSkillUpReasonType : uint8_t
{
	CraftSkillUpReason_BrokenResult = 0,
	CraftSkillUpReason_NormalResult = 1,
	CraftSkillUpReason_CriticalResult = 2,
	CraftSkillUpReason_Stolen      = 3,
	CraftSkillUpReason_Learning    = 4,
	CraftSkillUpReason_Overflow    = 5,
	CraftSkillUpReasonCount        = 6,
	ECraftSkillUpReasonType_MAX    = 7
};


// Enum Otherlands.ETechTreeType
enum class ETechTreeType : uint8_t
{
	TechTree_Adventuring           = 0,
	TechTree_Construction          = 1,
	TechTree_Invention             = 2,
	TechTree_Mystic                = 3,
	TechTreeCount                  = 4,
	ETechTreeType_MAX              = 5
};


// Enum Otherlands.ECraftTypeFlags
enum class ECraftTypeFlags : uint8_t
{
	ECraftTypeFlags__Personal      = 0,
	ECraftTypeFlags__CraftStation  = 1,
	ECraftTypeFlags__PersonalStation = 2,
	ECraftTypeFlags__ECraftTypeFlags_MAX = 3
};


// Enum Otherlands.ECraftRestrictedReason
enum class ECraftRestrictedReason : uint8_t
{
	ECraftRestrictedReason__CraftRestrictedReason_MissingResources = 0,
	ECraftRestrictedReason__CraftRestrictedReason_RecipeSkillLocked = 1,
	ECraftRestrictedReason__CraftRestrictedReason_RecipePerkLocked = 2,
	ECraftRestrictedReason__CraftRestrictedReason_RecipePerkSetLocked = 3,
	ECraftRestrictedReason__CraftRestrictedReason_TalentLocked = 4,
	ECraftRestrictedReason__CraftRestrictedReason_ResearchLocked = 5,
	ECraftRestrictedReason__CraftRestrictedReason_RequiresLearning = 6,
	ECraftRestrictedReason__CraftRestrictedReason_StationOutOfReach = 7,
	ECraftRestrictedReason__CraftRestrictedReason_MissingTool = 8,
	ECraftRestrictedReason__CraftRestrictedReason_BadData = 9,
	ECraftRestrictedReason__CraftRestrictedReason_StationInadequate = 10,
	ECraftRestrictedReason__CraftRestrictedReason_StationLevelTooLow = 11,
	ECraftRestrictedReason__CraftRestrictedReason_StationLevelTooHigh = 12,
	ECraftRestrictedReason__CraftRestrictedReason_RequiresPersonalStation = 13,
	ECraftRestrictedReason__CraftRestrictedReason_RecipeAscensionRankLocked = 14,
	ECraftRestrictedReason__CraftRestrictedReason_RecipeBuffLocked = 15,
	ECraftRestrictedReason__CraftRestrictedReason_NotEnoughUseScore = 16,
	ECraftRestrictedReason__CraftRestrictedReason_Unknown = 17,
	ECraftRestrictedReason__CraftRestrictedReasonCount = 18,
	ECraftRestrictedReason__ECraftRestrictedReason_MAX = 19
};


// Enum Otherlands.ECraftSkillUpLocation
enum class ECraftSkillUpLocation : uint8_t
{
	CraftSkillUpLocation_PersonalStationOnly = 0,
	CraftSkillUpLocation_AnyStation = 1,
	CraftSkillUpLocation_Anywhere  = 2,
	CraftSkillUpLocation_MAX       = 3
};


// Enum Otherlands.EDemolishResult
enum class EDemolishResult : uint8_t
{
	DemolishResult_Success         = 0,
	DemolishResult_Failed          = 1,
	DemolishResult_MAX             = 2
};


// Enum Otherlands.EOutcastResult
enum class EOutcastResult : uint8_t
{
	OutcastResult_Success          = 0,
	OutcastResult_BelowMin         = 1,
	OutcastResult_BelowRatio       = 2,
	OutcastResult_AdminDisabled    = 3,
	OutcastResult_MAX              = 4
};


// Enum Otherlands.EVoteResult
enum class EVoteResult : uint8_t
{
	VoteResult_Success             = 0,
	VoteResult_Error               = 1,
	VoteResult_AlreadyActive       = 2,
	VoteResult_AlreadyOutcast      = 3,
	VoteResult_AlreadyGranted      = 4,
	VoteResult_AlreadyVoted        = 5,
	VoteResult_NotActive           = 6,
	VoteResult_LowPrivleges        = 7,
	VoteResult_MAX                 = 8
};


// Enum Otherlands.EReputationEvent_CodeMap
enum class EReputationEvent_CodeMap : uint8_t
{
	ReputationEvent_CodeMap_DepositSoul = 0,
	ReputationEvent_CodeMap_FriendlyFire = 1,
	ReputationEvent_CodeMap_EnemyFire = 2,
	ReputationEvent_CodeMap_LevelUp = 3,
	ReputationEvent_CodeMap_SkillUp = 4,
	ReputationEvent_CodeMap_Research = 5,
	ReputationEvent_CodeMap_WarehoseDeposit = 6,
	ReputationEvent_CodeMap_UpgradeDeposit = 7,
	ReputationEvent_CodeMap_FriendlyFirePet = 8,
	ReputationEvent_CodeMap_EnemyFirePet = 9,
	ReputationEvent_CodeMap_FriendlyFireSiege = 10,
	ReputationEvent_CodeMap_LootFriendlyCorpse = 11,
	ReputationEvent_CodeMap_Unmapped = 12,
	ReputationEventCodeMapCount    = 13,
	EReputationEvent_CodeMap_MAX   = 14
};


// Enum Otherlands.EGroupType_CodeMap
enum class EGroupType_CodeMap : uint8_t
{
	GroupType_CodeMap_Faction      = 0,
	GroupType_CodeMap_Clan         = 1,
	GroupType_CodeMap_Personal     = 2,
	GroupType_CodeMap_Unmapped     = 3,
	GroupTypeCodeMapCount          = 4,
	EGroupType_CodeMap_MAX         = 5
};


// Enum Otherlands.EPermission_CodeMap
enum class EPermission_CodeMap : uint8_t
{
	Permission_CodeMap_PlacePlaceable = 0,
	Permission_CodeMap_DestroyPlaceable = 1,
	Permission_CodeMap_PlacePlug   = 2,
	Permission_CodeMap_PlaceRefinery = 3,
	Permission_CodeMap_UseWarehouse = 4,
	Permission_CodeMap_DestroyPlug = 5,
	Permission_CodeMap_DestroyRefinery = 6,
	Permission_CodeMap_SetObjective = 7,
	Permission_CodeMap_PlaceBuilding = 8,
	Permission_CodeMap_PlaceStructure = 9,
	Permission_CodeMap_DestroyStructure = 10,
	Permission_CodeMap_DestroyBuilding = 11,
	Permission_CodeMap_UpgradeBase = 12,
	Permission_CodeMap_Chat        = 13,
	Permission_CodeMap_ClanInvite  = 14,
	Permission_CodeMap_ClanKick    = 15,
	Permission_CodeMap_ClanPromote = 16,
	Permission_CodeMap_ClanDemote  = 17,
	Permission_CodeMap_SpawnAt     = 18,
	Permission_CodeMap_Interact    = 19,
	Permission_CodeMap_InitiateOutcastVote = 20,
	Permission_CodeMap_CastOutcastVote = 21,
	Permission_CodeMap_ViewUseScore = 22,
	Permission_CodeMap_CanExceedAllowedUseScore = 23,
	Permission_CodeMap_EditMotd    = 24,
	Permission_CodeMap_EditMemo    = 25,
	Permission_CodeMap_InitiateDemolishVote = 26,
	Permission_CodeMap_CastDemolishVote = 27,
	Permission_CodeMap_InteractDefenses = 28,
	Permission_CodeMap_Unmapped    = 29,
	PermissionCodeMapCount         = 30,
	EPermission_CodeMap_MAX        = 31
};


// Enum Otherlands.ETooltipColor
enum class ETooltipColor : uint8_t
{
	ETooltipColor__ColorNormal     = 0,
	ETooltipColor__ColorBuff       = 1,
	ETooltipColor__ColorDebuff     = 2,
	ETooltipColor__ETooltipColor_MAX = 3
};


// Enum Otherlands.ETooltipTextSize
enum class ETooltipTextSize : uint8_t
{
	ETooltipTextSize__TooltipSmall = 0,
	ETooltipTextSize__TooltipNormal = 1,
	ETooltipTextSize__TooltipLarge = 2,
	ETooltipTextSize__ETooltipTextSize_MAX = 3
};


// Enum Otherlands.ETooltipType
enum class ETooltipType : uint8_t
{
	ETooltipType__TooltipNone      = 0,
	ETooltipType__TooltipText      = 1,
	ETooltipType__TooltipProgress  = 2,
	ETooltipType__TooltipSeperator = 3,
	ETooltipType__ETooltipType_MAX = 4
};


// Enum Otherlands.EGameMode
enum class EGameMode : uint8_t
{
	EGameMode__None                = 0,
	EGameMode__Exploration         = 1,
	EGameMode__Classic             = 2,
	EGameMode__FactionWar          = 3,
	EGameMode__Custom              = 4,
	EGameMode__Count               = 5,
	EGameMode__EGameMode_MAX       = 6
};


// Enum Otherlands.ETimeCycleType
enum class ETimeCycleType : uint8_t
{
	TimeCycle_NightOnly            = 0,
	TimeCycle_DayOnly              = 1,
	TimeCycle_Anytime              = 2,
	TimeCycle_MAX                  = 3
};


// Enum Otherlands.ECooldownEffectType
enum class ECooldownEffectType : uint8_t
{
	CooldownEffect_EffectAll       = 0,
	CooldownEffect_EffectGroups    = 1,
	CooldownEffect_EffectSpells    = 2,
	CooldownEffect_EffectItems     = 3,
	CooldownEffectCount            = 4,
	ECooldownEffectType_MAX        = 5
};


// Enum Otherlands.ECharacterSoundPriority
enum class ECharacterSoundPriority : uint8_t
{
	CharSound_Critical             = 0,
	CharSound_Combat               = 1,
	CharSound_Background           = 2,
	CharSound_None                 = 3,
	CharSound_MAX                  = 4
};


// Enum Otherlands.EMountFamily
enum class EMountFamily : uint8_t
{
	Mount_Wolf                     = 0,
	Mount_Bullbeak                 = 1,
	Mount_Bear                     = 2,
	Mount_Bird                     = 3,
	Mount_Boar                     = 4,
	Mount_Cat                      = 5,
	Mount_Chomper                  = 6,
	Mount_Elk                      = 7,
	Mount_Frog                     = 8,
	Mount_Goat                     = 9,
	Mount_Komodo                   = 10,
	Mount_Maggot                   = 11,
	Mount_Raptor                   = 12,
	Mount_Rat                      = 13,
	Mount_Spider                   = 14,
	Mount_Turtle                   = 15,
	Mount_Charger                  = 16,
	Mount_Dragon                   = 17,
	Mount_Bronto                   = 18,
	Mount_MAX                      = 19
};


// Enum Otherlands.ECreatureSoundType
enum class ECreatureSoundType : uint8_t
{
	CreatureSound_Agro             = 0,
	CreatureSound_TakeHit          = 1,
	CreatureSound_Death            = 2,
	CreatureSound_Aware            = 3,
	CreatureSound_Flee             = 4,
	CreatureSound_MAX              = 5
};


// Enum Otherlands.ETickerType
enum class ETickerType : uint8_t
{
	TickerType_Talents             = 0,
	TickerType_Perks               = 1,
	TickerTypeCount                = 2,
	ETickerType_MAX                = 3
};


// Enum Otherlands.ECrosshairType
enum class ECrosshairType : uint8_t
{
	CrosshairType_Circle           = 0,
	CrosshairType_Cross            = 1,
	CrosshairType_Interactive      = 2,
	CrosshairType_Butchery         = 3,
	CrosshairType_Fist             = 4,
	CrosshairType_Sickle           = 5,
	CrosshairType_Hammer           = 6,
	CrosshairType_Pick             = 7,
	CrosshairType_Axe              = 8,
	CrosshairType_MAX              = 9
};


// Enum Otherlands.ECrosshairMode
enum class ECrosshairMode : uint8_t
{
	CrosshairMode_Original         = 0,
	CrosshairMode_Enhanced         = 1,
	CrosshairModeCount             = 2,
	ECrosshairMode_MAX             = 3
};


// Enum Otherlands.EInteractAction_CodeMap
enum class EInteractAction_CodeMap : uint8_t
{
	InteractAction_CodeMap_OpenStation = 0,
	InteractAction_CodeMap_Server  = 1,
	InteractAction_CodeMap_UpgradePlaceable = 2,
	InteractAction_CodeMap_Drink   = 3,
	InteractAction_CodeMap_DismissPet = 4,
	InteractAction_CodeMap_PickUpPlaceable = 5,
	InteractAction_CodeMap_DepositSouls = 6,
	InteractAction_CodeMap_RenamePlaceable = 7,
	InteractAction_CodeMap_MountPet = 8,
	InteractAction_CodeMap_StructureTeleport = 9,
	InteractAction_CodeMap_Unmapped = 10,
	InteractActionCodeMapCount     = 11,
	EInteractAction_CodeMap_MAX    = 12
};


// Enum Otherlands.ETutorial_CodeMap
enum class ETutorial_CodeMap : uint8_t
{
	Tutorial_CodeMap_Hunger        = 0,
	Tutorial_CodeMap_Thirst        = 1,
	Tutorial_CodeMap_CursorControl = 2,
	Tutorial_CodeMap_Movement      = 3,
	Tutorial_CodeMap_Sprint        = 4,
	Tutorial_CodeMap_Unmapped      = 5,
	TutorialCodeMapCount           = 6,
	ETutorial_CodeMap_MAX          = 7
};


// Enum Otherlands.ESpiritBonusType
enum class ESpiritBonusType : uint8_t
{
	SpiritBonus_Sentry             = 0,
	SpiritBonus_StructureArmor     = 1,
	SpiritBonus_InBaseBuff         = 2,
	SpiritBonus_CastBuff           = 3,
	SpiritBonus_SelfBuff           = 4,
	SpiritBonus_RecipeUnlock       = 5,
	SpiritBonus_RareCreatureDetection = 6,
	SpiritBonus_RareResourceDetection = 7,
	SpiritBonus_Teleport           = 8,
	SpiritBonus_ResourceProduction = 9,
	SpiritBonusCount               = 10,
	ESpiritBonusType_MAX           = 11
};


// Enum Otherlands.EDeathCauseType
enum class EDeathCauseType : uint8_t
{
	DeathCause_AI                  = 0,
	DeathCause_Ally                = 1,
	DeathCause_Opponent            = 2,
	DeathCause_Terrain             = 3,
	DeathCauseCount                = 4,
	EDeathCauseType_MAX            = 5
};


// Enum Otherlands.ESpiritEventRewardType
enum class ESpiritEventRewardType : uint8_t
{
	SpiritEventReward_FactionSpirit = 0,
	SpiritEventReward_Mount        = 1,
	SpiritEventRewardCount         = 2,
	ESpiritEventRewardType_MAX     = 3
};


// Enum Otherlands.EEventType
enum class EEventType : uint8_t
{
	Event_Holdout                  = 0,
	Event_Wave                     = 1,
	EventCount                     = 2,
	EEventType_MAX                 = 3
};


// Enum Otherlands.ESpiritEventType
enum class ESpiritEventType : uint8_t
{
	SpiritEvent_Holdout            = 0,
	SpiritEvent_Hunt               = 1,
	SpiritEvent_Wisp               = 2,
	SpiritEvent_Gather             = 3,
	SpiritEvent_Kill               = 4,
	SpiritEvent_Combat             = 5,
	SpiritEvent_Syphon             = 6,
	SpiritEventCount               = 7,
	ESpiritEventType_MAX           = 8
};


// Enum Otherlands.ERadialMenuType
enum class ERadialMenuType : uint8_t
{
	RadialMenu_Harvester           = 0,
	RadialMenu_Weapon              = 1,
	RadialMenu_BuildingMode        = 2,
	RadialMenu_Ammo                = 3,
	RadialMenu_Interact            = 4,
	RadialMenu_PetCommand          = 5,
	RadialMenu_Emote               = 6,
	RadialMenuCount                = 7,
	ERadialMenuType_MAX            = 8
};


// Enum Otherlands.EHitDirection
enum class EHitDirection : uint8_t
{
	HitDirection_TopLeft           = 0,
	HitDirection_TopRight          = 1,
	HitDirection_BotLeft           = 2,
	HitDirection_BotRight          = 3,
	HitDirection_Self              = 4,
	HitDirection_MAX               = 5
};


// Enum Otherlands.EInteractType
enum class EInteractType : uint8_t
{
	InteractType_MeshComponent     = 0,
	InteractType_StructureComponent = 1,
	InteractType_PlugComponent     = 2,
	InteractType_SpawnPoint        = 3,
	InteractType_Corpse            = 4,
	InteractType_Water             = 5,
	InteractType_Vehicle           = 6,
	InteractType_Teleporter        = 7,
	InteractType_Loot              = 8,
	InteractType_Creature          = 9,
	InteractTypeCount              = 10,
	EInteractType_MAX              = 11
};


// Enum Otherlands.ENotifyDeathType
enum class ENotifyDeathType : uint8_t
{
	NotifyDeath_None               = 0,
	NotifyDeath_Light              = 1,
	NotifyDeath_Heavy              = 2,
	NotifyDeathCount               = 3,
	ENotifyDeathType_MAX           = 4
};


// Enum Otherlands.ESplineTimeMode
enum class ESplineTimeMode : uint8_t
{
	SplineTimeMode_Absolute        = 0,
	SplineTimeMode_Relative        = 1,
	SplineTimeMode_Key             = 2,
	SplineTimeMode_Count           = 3,
	SplineTimeMode_MAX             = 4
};


// Enum Otherlands.EPunchTicketResult
enum class EPunchTicketResult : uint8_t
{
	EPunchTicketResult__PunchTicketResult_Success = 0,
	EPunchTicketResult__PunchTicketResult_FailureCharacterRetrieval = 1,
	EPunchTicketResult__PunchTicketResult_FailureCreateCharacter = 2,
	EPunchTicketResult__PunchTicketResult_FailureInvalidTicket = 3,
	EPunchTicketResult__PunchTicketResult_FailureMalformedTicket = 4,
	EPunchTicketResult__PunchTicketResultCount = 5,
	EPunchTicketResult__EPunchTicketResult_MAX = 6
};


// Enum Otherlands.EBeaconAuthenticationError
enum class EBeaconAuthenticationError : uint8_t
{
	EBeaconAuthenticationError__BeaconAuthenticationError_BadPassword = 0,
	EBeaconAuthenticationError__BeaconAuthenticationError_InvalidTicket = 1,
	EBeaconAuthenticationError__BeaconAuthenticationError_ServerBanned = 2,
	EBeaconAuthenticationError__BeaconAuthenticationErrorCount = 3,
	EBeaconAuthenticationError__EBeaconAuthenticationError_MAX = 4
};


// Enum Otherlands.ETranslucentSortLayer
enum class ETranslucentSortLayer : uint8_t
{
	ETranslucentSortLayer__Default = 0,
	ETranslucentSortLayer__Water   = 1,
	ETranslucentSortLayer__Count   = 2,
	ETranslucentSortLayer__ETranslucentSortLayer_MAX = 3
};


// Enum Otherlands.EBuildConfiguration
enum class EBuildConfiguration : uint8_t
{
	EBuildConfiguration__Unknown   = 0,
	EBuildConfiguration__Shipping  = 1,
	EBuildConfiguration__Debug     = 2,
	EBuildConfiguration__Development = 3,
	EBuildConfiguration__Test      = 4,
	EBuildConfiguration__EBuildConfiguration_MAX = 5
};


// Enum Otherlands.EGoalState
enum class EGoalState : uint8_t
{
	EGoalState__NotActive          = 0,
	EGoalState__Active             = 1,
	EGoalState__Paused             = 2,
	EGoalState__Complete           = 3,
	EGoalState__Failed             = 4,
	EGoalState__EGoalState_MAX     = 5
};


// Enum Otherlands.EGoalMemoryCheckOperation
enum class EGoalMemoryCheckOperation : uint8_t
{
	EGoalMemoryCheckOperation__EntryExists = 0,
	EGoalMemoryCheckOperation__EntryNotExists = 1,
	EGoalMemoryCheckOperation__ValueEqual = 2,
	EGoalMemoryCheckOperation__ValueNotEqual = 3,
	EGoalMemoryCheckOperation__ValueLessThan = 4,
	EGoalMemoryCheckOperation__ValueLessThanEqual = 5,
	EGoalMemoryCheckOperation__ValueGreaterThan = 6,
	EGoalMemoryCheckOperation__ValueGreaterThanEqual = 7,
	EGoalMemoryCheckOperation__EGoalMemoryCheckOperation_MAX = 8
};


// Enum Otherlands.EGoalMemoryType
enum class EGoalMemoryType : uint8_t
{
	EGoalMemoryType__None          = 0,
	EGoalMemoryType__String        = 1,
	EGoalMemoryType__Integer       = 2,
	EGoalMemoryType__Float         = 3,
	EGoalMemoryType__Object        = 4,
	EGoalMemoryType__EGoalMemoryType_MAX = 5
};


// Enum Otherlands.EItemUniqueRestriction
enum class EItemUniqueRestriction : uint8_t
{
	EItemUniqueRestriction__Unrestricted = 0,
	EItemUniqueRestriction__PriorityRestricted = 1,
	EItemUniqueRestriction__GlobalRestricted = 2,
	EItemUniqueRestriction__EItemUniqueRestriction_MAX = 3
};


// Enum Otherlands.EItemInitReason
enum class EItemInitReason : uint8_t
{
	EItemInitReason__NewItem       = 0,
	EItemInitReason__CopyItem      = 1,
	EItemInitReason__LoadItem      = 2,
	EItemInitReason__EItemInitReason_MAX = 3
};


// Enum Otherlands.EItemRepairType
enum class EItemRepairType : uint8_t
{
	ItemRepairType_Wood            = 0,
	ItemRepairType_Plant           = 1,
	ItemRepairType_Stone           = 2,
	ItemRepairType_Metal           = 3,
	ItemRepairType_Gem             = 4,
	ItemRepairType_CreatureParts   = 5,
	ItemRepairType_Other           = 6,
	ItemRepairTypeCount            = 7,
	EItemRepairType_MAX            = 8
};


// Enum Otherlands.EItemAffixStat
enum class EItemAffixStat : uint8_t
{
	ItemAffixStat_MaxDurabilityScalar = 0,
	ItemAffixStat_DurabilityConsumptionScalar = 1,
	ItemAffixStat_WeightScalar     = 2,
	ItemAffixStatCount             = 3,
	EItemAffixStat_MAX             = 4
};


// Enum Otherlands.EPlaceableMaterial
enum class EPlaceableMaterial : uint8_t
{
	PlaceableMaterial_Wood         = 0,
	PlaceableMaterial_Stone        = 1,
	PlaceableMaterial_Metal        = 2,
	PlaceableMaterialCount         = 3,
	EPlaceableMaterial_MAX         = 4
};


// Enum Otherlands.EItemStationFuelType
enum class EItemStationFuelType : uint8_t
{
	ItemStationFuel_None           = 0,
	ItemStationFuel_Manual_AssumeOn = 1,
	ItemStationFuel_Manual_AssumeOff = 2,
	ItemStationFuel_Manual_CannotStop = 3,
	ItemStationFuel_Auto_ConserveFuel = 4,
	ItemStationFuel_MAX            = 5
};


// Enum Otherlands.EItemSoulboundType
enum class EItemSoulboundType : uint8_t
{
	ItemSoulbound_OnPickup         = 0,
	ItemSoulbound_OnUse            = 1,
	ItemSoulboundCount             = 2,
	EItemSoulboundType_MAX         = 3
};


// Enum Otherlands.EAmmoType
enum class EAmmoType : uint8_t
{
	AmmoType_Bolt                  = 0,
	AmmoType_Arrow                 = 1,
	AmmoType_Spike                 = 2,
	AmmoType_Shard                 = 3,
	AmmoType_Dart                  = 4,
	AmmoType_NoAmmo                = 5,
	AmmoType_Siege                 = 6,
	AmmoType_Arbalest              = 7,
	AmmoTypeCount                  = 8,
	EAmmoType_MAX                  = 9
};


// Enum Otherlands.EItemResourceType
enum class EItemResourceType : uint8_t
{
	ItemResource_Water             = 0,
	ItemResource_Souls             = 1,
	ItemResourceCount              = 2,
	EItemResourceType_MAX          = 3
};


// Enum Otherlands.EContextWidgetType
enum class EContextWidgetType : uint8_t
{
	ContextWidget_Inventory        = 0,
	ContextWidget_CraftingStation  = 1,
	ContextWidget_Refinery         = 2,
	ContextWidget_Container        = 3,
	ContextWidget_Warehouse        = 4,
	ContextWidget_Scaffolding      = 5,
	ContextWidgetCount             = 6,
	EContextWidgetType_MAX         = 7
};


// Enum Otherlands.EAttackType
enum class EAttackType : uint8_t
{
	AttackType_None                = 0,
	AttackType_Melee               = 1,
	AttackType_Ranged              = 2,
	AttackType_Thrown              = 3,
	AttackType_Spear               = 4,
	AttackType_Syphon              = 5,
	AttackType_MAX                 = 6
};


// Enum Otherlands.EInventoryGroup
enum class EInventoryGroup : uint8_t
{
	InventoryGroup_All             = 0,
	InventoryGroup_Resource        = 1,
	InventoryGroup_Tools           = 2,
	InventoryGroup_Weapon          = 3,
	InventoryGroup_Armor           = 4,
	InventoryGroup_Structures      = 5,
	InventoryGroup_FoodWater       = 6,
	InventoryGroup_Utility         = 7,
	InventoryGroup_Constructed     = 8,
	InventoryGroup_CraftResearch   = 9,
	InventoryGroup_MAX             = 10
};


// Enum Otherlands.EItemType
enum class EItemType : uint8_t
{
	ItemType_LootedResource        = 0,
	ItemType_Wood                  = 1,
	ItemType_Plant                 = 2,
	ItemType_Stone                 = 3,
	ItemType_Metal                 = 4,
	ItemType_Gem                   = 5,
	ItemType_Meat                  = 6,
	ItemType_CreatureParts         = 7,
	ItemType_Ingredient            = 8,
	ItemType_Sap                   = 9,
	ItemType_ArmorLight            = 10,
	ItemType_ArmorMedium           = 11,
	ItemType_ArmorHeavy            = 12,
	ItemType_Axe                   = 13,
	ItemType_Pick                  = 14,
	ItemType_Sickle                = 15,
	ItemType_Hammer                = 16,
	ItemType_ConstructionTool      = 17,
	ItemType_Bow                   = 18,
	ItemType_Repeater              = 19,
	ItemType_Crossbow              = 20,
	ItemType_SpikeLauncher         = 21,
	ItemType_ShardBlaster          = 22,
	ItemType_WeaponMelee           = 23,
	ItemType_WeaponOther           = 24,
	ItemType_SiegeWeapon           = 25,
	ItemType_Arbalest              = 26,
	ItemType_Arrow                 = 27,
	ItemType_Bolt                  = 28,
	ItemType_Dart                  = 29,
	ItemType_Spike                 = 30,
	ItemType_Shard                 = 31,
	ItemType_Food                  = 32,
	ItemType_Potion                = 33,
	ItemType_Elixir                = 34,
	ItemType_Poison                = 35,
	ItemType_Draught               = 36,
	ItemType_FirstAid              = 37,
	ItemType_WeaponModification    = 38,
	ItemType_Bomb                  = 39,
	ItemType_Trap                  = 40,
	ItemType_Barricade             = 41,
	ItemType_Building              = 42,
	ItemType_Structure             = 43,
	ItemType_Station               = 44,
	ItemType_Foundation            = 45,
	ItemType_Wall                  = 46,
	ItemType_Platform              = 47,
	ItemType_Pillar                = 48,
	ItemType_Stairs                = 49,
	ItemType_Plug                  = 50,
	ItemType_CapturePoint          = 51,
	ItemType_Cosmetic              = 52,
	ItemType_Light                 = 53,
	ItemType_Reinforcement         = 54,
	ItemType_Totem                 = 55,
	ItemType_CraftingStation       = 56,
	ItemType_Refinery              = 57,
	ItemType_Armory                = 58,
	ItemType_Container             = 59,
	ItemType_Artifact              = 60,
	ItemType_Relic                 = 61,
	ItemType_Waterskin             = 62,
	ItemType_Research              = 63,
	ItemType_Wondrous              = 64,
	ItemType_Horn                  = 65,
	ItemType_Fang                  = 66,
	ItemType_Coin                  = 67,
	ItemType_Scroll                = 68,
	ItemType_Blade                 = 69,
	ItemType_Head                  = 70,
	ItemType_Other                 = 71,
	ItemTypeCount                  = 72,
	EItemType_MAX                  = 73
};


// Enum Otherlands.EItemCategory
enum class EItemCategory : uint8_t
{
	ItemCategory_Station           = 0,
	ItemCategory_Building          = 1,
	ItemCategory_Fortification     = 2,
	ItemCategory_Standalone        = 3,
	ItemCategory_SiegeWeapon       = 4,
	ItemCategory_Tool              = 5,
	ItemCategory_Weapon            = 6,
	ItemCategory_Armor             = 7,
	ItemCategory_Consumable        = 8,
	ItemCategory_Utility           = 9,
	ItemCategory_Ammo              = 10,
	ItemCategory_RawResource       = 11,
	ItemCategory_Ingredient        = 12,
	ItemCategory_LootablePart      = 13,
	ItemCategory_SiegeAmmo         = 14,
	ItemCategory_Relic             = 15,
	ItemCategoryCount              = 16,
	EItemCategory_MAX              = 17
};


// Enum Otherlands.EItemFamily
enum class EItemFamily : uint8_t
{
	ItemFamily_Tool                = 0,
	ItemFamily_Equipable           = 1,
	ItemFamily_Consumable          = 2,
	ItemFamily_Placeable           = 3,
	ItemFamily_Resource            = 4,
	ItemFamily_Other               = 5,
	ItemFamily_MAX                 = 6
};


// Enum Otherlands.EItemQuality
enum class EItemQuality : uint8_t
{
	ItemQuality_Low                = 0,
	ItemQuality_Average            = 1,
	ItemQuality_Good               = 2,
	ItemQuality_Rare               = 3,
	ItemQuality_Epic               = 4,
	ItemQuality_Legendary          = 5,
	ItemQuality_Artifact           = 6,
	ItemQuality_MAX                = 7
};


// Enum Otherlands.EEquipSlot
enum class EEquipSlot : uint8_t
{
	EquipSlot_Head                 = 0,
	EquipSlot_Chest                = 1,
	EquipSlot_Legs                 = 2,
	EquipSlot_Shoulders            = 3,
	EquipSlot_Hands                = 4,
	EquipSlot_Feet                 = 5,
	EquipSlot_Offhand              = 6,
	EquipSlot_Backpack             = 7,
	EquipSlot_WeaponPrimary        = 8,
	EquipSlot_WeaponSecondary      = 9,
	EquipSlot_HarvestWood          = 10,
	EquipSlot_HarvestStone         = 11,
	EquipSlot_HarvestPlant         = 12,
	EquipSlot_HarvestMetal         = 13,
	EquipSlot_ConstructionHammer   = 14,
	EquipSlot_Relic                = 15,
	EquipSlotCount                 = 16,
	EEquipSlot_MAX                 = 17
};


// Enum Otherlands.EHeldItemLocation
enum class EHeldItemLocation : uint8_t
{
	HeldItemLocation_None          = 0,
	HeldItemLocation_ActionBar     = 1,
	HeldItemLocation_HarvestRune   = 2,
	HeldItemLocation_WeaponSlot    = 3,
	HeldItemLocation_Build         = 4,
	HeldItemLocation_MAX           = 5
};


// Enum Otherlands.EInventoryType
enum class EInventoryType : uint8_t
{
	Inventory_Backpack             = 0,
	Inventory_ActionBar            = 1,
	Inventory_Paperdoll            = 2,
	Inventory_Stash                = 3,
	Inventory_Armory               = 4,
	Inventory_Container            = 5,
	Inventory_Corpse               = 6,
	Inventory_Pet                  = 7,
	Inventory_MAX                  = 8
};


// Enum Otherlands.EItemSlotType
enum class EItemSlotType : uint8_t
{
	Type_ActionBar                 = 0,
	Type_Inventory                 = 1,
	Type_Container                 = 2,
	Type_CraftRecipe               = 3,
	Type_CraftStationItem          = 4,
	Type_CraftStationRecipe        = 5,
	Type_Equipment                 = 6,
	Type_MAX                       = 7
};


// Enum Otherlands.EJrkTest
enum class EJrkTest : uint8_t
{
	JrkTest_ReportingPlayer        = 0,
	JrkTest_PlayerReported         = 1,
	JrkTest_InitiateOutcast        = 2,
	JrkTest_WasOutcast             = 3,
	JrkTest_FactionExceedUseScore  = 4,
	JrkTest_ScrubbedString         = 5,
	JrkTest_InitiateDemolish       = 6,
	JrkTestCount                   = 7,
	EJrkTest_MAX                   = 8
};


// Enum Otherlands.EPlayerReportReason
enum class EPlayerReportReason : uint8_t
{
	PlayerReportReason_Cheat       = 0,
	PlayerReportReason_Behavior    = 1,
	PlayerReportReason_PowerAbuse  = 2,
	PlayerReportReason_Other       = 3,
	PlayerReportReasonConst        = 4,
	EPlayerReportReason_MAX        = 5
};


// Enum Otherlands.EResourceTriggerDataType
enum class EResourceTriggerDataType : uint8_t
{
	ResourceTriggerData_Buff       = 0,
	ResourceTriggerData_PlayerAbility = 1,
	ResourceTriggerData_CreatureAbility = 2,
	ResourceTriggerData_MAX        = 3
};


// Enum Otherlands.ELootCondition
enum class ELootCondition : uint8_t
{
	LootCondition_Unique           = 0,
	LootCondition_UpgradeEquipSlot = 1,
	LootCondition_SpiritRealmIn    = 2,
	LootCondition_SpiritRealmOut   = 3,
	LootCondition_DoNotScale       = 4,
	LootConditionCount             = 5,
	ELootCondition_MAX             = 6
};


// Enum Otherlands.EGameAlienFX
enum class EGameAlienFX : uint8_t
{
	GameAlienFX_Inherit            = 0,
	GameAlienFX_None               = 1,
	GameAlienFX_Stat_Health        = 2,
	GameAlienFX_Stat_Food          = 3,
	GameAlienFX_Stat_Water         = 4,
	GameAlienFX_Stat_Temperature   = 5,
	GameAlienFX_Stat_Stamina       = 6,
	GameAlienFX_Stat_Weight        = 7,
	GameAlienFX_Stat_Sound         = 8,
	GameAlienFX_Faction            = 9,
	GameAlienFX_Event_TakeDamage   = 10,
	GameAlienFX_Event_DoDamage     = 11,
	GameAlienFX_Event_TakeHeal     = 12,
	GameAlienFX_Event_Kill         = 13,
	GameAlienFX_Count              = 14,
	GameAlienFX_MAX                = 15
};


// Enum Otherlands.EConnectionMetricLogFlags
enum class EConnectionMetricLogFlags : uint8_t
{
	ConnectionMetricLogFlags_Byte  = 0,
	ConnectionMetricLogFlags_Packet = 1,
	ConnectionMetricLogFlags_PacketLost = 2,
	ConnectionMetricLogFlags_Average = 3,
	ConnectionMetricLogFlags_Max   = 4,
	ConnectionMetricLogFlags_LAST_BIT = 5
};


// Enum Otherlands.EHighlight
enum class EHighlight : uint8_t
{
	EHighlight__Death              = 0,
	EHighlight__PlayerKill         = 1,
	EHighlight__PlayerAssist       = 2,
	EHighlight__Tame               = 3,
	EHighlight__SkillUp            = 4,
	EHighlight__LevelUp            = 5,
	EHighlight__Win                = 6,
	EHighlight__Count              = 7,
	EHighlight__EHighlight_MAX     = 8
};


// Enum Otherlands.ETimerMetricUnit
enum class ETimerMetricUnit : uint8_t
{
	ETimerMetricUnit__MT_Milliseconds = 0,
	ETimerMetricUnit__MT_Seconds   = 1,
	ETimerMetricUnit__MT_Minutes   = 2,
	ETimerMetricUnit__MT_Hours     = 3,
	ETimerMetricUnit__MT_Days      = 4,
	ETimerMetricUnit__MT_MAX       = 5
};


// Enum Otherlands.EClassRepNodeMapping
enum class EClassRepNodeMapping : uint8_t
{
	EClassRepNodeMapping__NotRouted = 0,
	EClassRepNodeMapping__ServerLimitedRelevant = 1,
	EClassRepNodeMapping__ServerRelevant = 2,
	EClassRepNodeMapping__ServerAndBeaconRelevant = 3,
	EClassRepNodeMapping__Spatialize_Static = 4,
	EClassRepNodeMapping__Spatialize_Dynamic = 5,
	EClassRepNodeMapping__Spatialize_Dormancy = 6,
	EClassRepNodeMapping__Phase_Static = 7,
	EClassRepNodeMapping__Phase_Dynamic = 8,
	EClassRepNodeMapping__Phase_Dynamic_DualRelevent = 9,
	EClassRepNodeMapping__Phase_Dormancy = 10,
	EClassRepNodeMapping__EClassRepNodeMapping_MAX = 11
};


// Enum Otherlands.EPlaceableRestriction
enum class EPlaceableRestriction : uint8_t
{
	PlaceableRestriction_NotInFactionStructure = 0,
	PlaceableRestriction_NotInPersonalStructure = 1,
	PlaceableRestriction_NotInTribeStructure = 2,
	PlaceableRestriction_NotOnGround = 3,
	PlaceableRestriction_NotOnStructure = 4,
	PlaceableRestriction_NotOutsideOfStructure = 5,
	PlaceableRestriction_NotInsideOfStructure = 6,
	PlaceableRestrictionCount      = 7,
	EPlaceableRestriction_MAX      = 8
};


// Enum Otherlands.EPlaceablePlugType
enum class EPlaceablePlugType : uint8_t
{
	PlaceablePlug_WallReinforcement = 0,
	PlaceablePlug_WallBrace        = 1,
	PlaceablePlug_Beam             = 2,
	PlaceablePlug_Decoration       = 3,
	PlaceablePlug_Station          = 4,
	PlaceablePlug_Door             = 5,
	PlaceablePlug_GroundGate       = 6,
	PlaceablePlug_FoundationGate   = 7,
	PlaceablePlug_Portcullis       = 8,
	PlaceablePlug_ControlPointKey  = 9,
	PlaceablePlug_Refinery         = 10,
	PlaceablePlug_PersonalCraftStation = 11,
	PlaceablePlug_PersonalStationEnhancement = 12,
	PlaceablePlug_FactionStash     = 13,
	PlaceablePlug_Storage          = 14,
	PlaceablePlug_Armory           = 15,
	PlaceablePlug_Trapdoor         = 16,
	PlaceablePlug_Murderhole       = 17,
	PlaceablePlug_WindowShutter    = 18,
	PlaceablePlugCount             = 19,
	EPlaceablePlugType_MAX         = 20
};


// Enum Otherlands.EPlaceableSocketType
enum class EPlaceableSocketType : uint8_t
{
	PlaceableSocket_ExteriorWall   = 0,
	PlaceableSocket_InteriorWall   = 1,
	PlaceableSocket_Building       = 2,
	PlaceableSocket_DoorFrame      = 3,
	PlaceableSocket_GroundGateFrame = 4,
	PlaceableSocket_FoundationGateFrame = 5,
	PlaceableSocket_PortcullisFrame = 6,
	PlaceableSocket_ControlPoint   = 7,
	PlaceableSocket_Refinery       = 8,
	PlaceableSocket_PersonalCraftStation = 9,
	PlaceableSocket_PersonalStationEnhancement = 10,
	PlaceableSocket_Reinforcement  = 11,
	PlaceableSocket_FactionStash   = 12,
	PlaceableSocket_Storage        = 13,
	PlaceableSocket_Armory         = 14,
	PlaceableSocket_TrapdoorFrame  = 15,
	PlaceableSocket_WindowFrame    = 16,
	PlaceableSocketCount           = 17,
	EPlaceableSocketType_MAX       = 18
};


// Enum Otherlands.EStructureEdge
enum class EStructureEdge : uint8_t
{
	StructureEdge_WallLeft         = 0,
	StructureEdge_WallTop          = 1,
	StructureEdge_WallRight        = 2,
	StructureEdge_WallBottom       = 3,
	StructureEdge_WallLR           = 4,
	StructureEdge_WallRL           = 5,
	StructureEdge_Floor            = 6,
	StructureEdge_FloorTL          = 7,
	StructureEdge_FloorTR          = 8,
	StructureEdge_FloorBL          = 9,
	StructureEdge_FloorBR          = 10,
	StructureEdge_RampLeft         = 11,
	StructureEdge_RampTop          = 12,
	StructureEdge_RampRight        = 13,
	StructureEdge_RampBottom       = 14,
	StructureEdge_RampTL           = 15,
	StructureEdge_RampTR           = 16,
	StructureEdge_RampBL           = 17,
	StructureEdge_RampBR           = 18,
	StructureEdge_Pillar           = 19,
	StructureEdge_PillarTL         = 20,
	StructureEdge_PillarTR         = 21,
	StructureEdge_PillarBL         = 22,
	StructureEdge_PillarBR         = 23,
	StructureEdge_LedgeLeft        = 24,
	StructureEdge_LedgeTop         = 25,
	StructureEdge_LedgeRight       = 26,
	StructureEdge_LedgeBottom      = 27,
	StructureEdge_LedgeTL          = 28,
	StructureEdge_LedgeTR          = 29,
	StructureEdge_LedgeBL          = 30,
	StructureEdge_LedgeBR          = 31,
	StructureEdgeCount             = 32,
	EStructureEdge_MAX             = 33
};


// Enum Otherlands.EDisallowPlacementReason
enum class EDisallowPlacementReason : uint8_t
{
	EDisallowPlacementReason__None = 0,
	EDisallowPlacementReason__Unknown = 1,
	EDisallowPlacementReason__BlockedByResource = 2,
	EDisallowPlacementReason__BlockedByStructure = 3,
	EDisallowPlacementReason__BlockedByObject = 4,
	EDisallowPlacementReason__BlockedByStructureComponent = 5,
	EDisallowPlacementReason__NoBuildModeItemSelected = 6,
	EDisallowPlacementReason__InvalidBuildModeItemSelected = 7,
	EDisallowPlacementReason__NoSolidBaseFound = 8,
	EDisallowPlacementReason__NoValidAttachmentFound = 9,
	EDisallowPlacementReason__NoValidSocketFound = 10,
	EDisallowPlacementReason__Restriction_NotInFactionStructure = 11,
	EDisallowPlacementReason__Restriction_NotInPersonalStructure = 12,
	EDisallowPlacementReason__Restriction_NotInTribeStructure = 13,
	EDisallowPlacementReason__Restriction_NotOnStructure = 14,
	EDisallowPlacementReason__Restriction_NotOnGround = 15,
	EDisallowPlacementReason__Restriction_NotInStructure = 16,
	EDisallowPlacementReason__Restriction_NotOutsideOfStructure = 17,
	EDisallowPlacementReason__Restriction_OnlyOnFlatSurface = 18,
	EDisallowPlacementReason__Restriction_WrongSpiritMode = 19,
	EDisallowPlacementReason__StructureAlreadyOwned = 20,
	EDisallowPlacementReason__NoPermission = 21,
	EDisallowPlacementReason__NoValidBuildingAnchorFound = 22,
	EDisallowPlacementReason__IncompatibleBuildingAnchor = 23,
	EDisallowPlacementReason__EnemyBuildingAnchor = 24,
	EDisallowPlacementReason__RestrictedArea = 25,
	EDisallowPlacementReason__InsufficientMaterials = 26,
	EDisallowPlacementReason__PersonalInWorldLimitReached = 27,
	EDisallowPlacementReason__ClanInWorldLimitReached = 28,
	EDisallowPlacementReason__DesiredLocationTooFar = 29,
	EDisallowPlacementReason__NoGroundSupport = 30,
	EDisallowPlacementReason__OnlyOnGround = 31,
	EDisallowPlacementReason__UnsupportedAttachment = 32,
	EDisallowPlacementReason__OutsideStructureBounds = 33,
	EDisallowPlacementReason__NotStructurallySound = 34,
	EDisallowPlacementReason__EDisallowPlacementReason_MAX = 35
};


// Enum Otherlands.EBuildingType
enum class EBuildingType : uint8_t
{
	BuildingType_HuntingLodge      = 0,
	BuildingType_Construction      = 1,
	BuildingType_Invention         = 2,
	BuildingType_Mysticism         = 3,
	BuildingType_Research          = 4,
	BuildingType_Warehouse         = 5,
	BuildingType_WoodRefinery      = 6,
	BuildingType_StoneRefinery     = 7,
	BuildingType_MetalRefinery     = 8,
	BuildingType_OutfitterRefinery = 9,
	BuildingType_AlchemyRefinery   = 10,
	BuildingType_SiegeFactory      = 11,
	BuildingType_Stables           = 12,
	BuildingType_Stash             = 13,
	BuildingType_Armory            = 14,
	BuildingType_World             = 15,
	BuildingTypeCount              = 16,
	EBuildingType_MAX              = 17
};


// Enum Otherlands.EStructureType
enum class EStructureType : uint8_t
{
	StructureType_Foundation       = 0,
	StructureType_Wall             = 1,
	StructureType_Floor            = 2,
	StructureType_Ramp             = 3,
	StructureType_FoundationRamp   = 4,
	StructureType_Door             = 5,
	StructureType_GroundGate       = 6,
	StructureType_FoundationGate   = 7,
	StructureType_Pillar           = 8,
	StructureType_GroundPillar     = 9,
	StructureType_FoundationFloor  = 10,
	StructureType_Railing          = 11,
	StructureType_Ledge            = 12,
	StructureTypeCount             = 13,
	EStructureType_MAX             = 14
};


// Enum Otherlands.EPlaceableType
enum class EPlaceableType : uint8_t
{
	PlaceableType_Standalone       = 0,
	PlaceableType_Building         = 1,
	PlaceableType_Structure        = 2,
	PlaceableType_Plug             = 3,
	PlaceableType_Vehicle          = 4,
	PlaceableTypeCount             = 5,
	EPlaceableType_MAX             = 6
};


// Enum Otherlands.EUnusableGridFlags
enum class EUnusableGridFlags : uint8_t
{
	EUnusableGridFlags__None       = 0,
	EUnusableGridFlags__Replaceable = 1,
	EUnusableGridFlags__Underlay   = 2,
	EUnusableGridFlags__Occupied   = 3,
	EUnusableGridFlags__EUnusableGridFlags_MAX = 4
};


// Enum Otherlands.ERangedActionType
enum class ERangedActionType : uint8_t
{
	RangedAction_None              = 0,
	RangedAction_Fire              = 1,
	RangedAction_StartDraw         = 2,
	RangedAction_StopDraw          = 3,
	RangedAction_SpinUp            = 4,
	RangedAction_Reload            = 5,
	RangedAction_Empty             = 6,
	RangedAction_MAX               = 7
};


// Enum Otherlands.EAscensionActivity
enum class EAscensionActivity : uint8_t
{
	AscensionActivity_PlayerXp     = 0,
	AscensionActivity_SkillXp      = 1,
	AscensionActivity_RepGain      = 2,
	AscensionActivity_Placement    = 3,
	AscensionActivityCount         = 4,
	EAscensionActivity_MAX         = 5
};


// Enum Otherlands.EThreatRankingType
enum class EThreatRankingType : uint8_t
{
	ThreatRanking_DistanceNear2D   = 0,
	ThreatRanking_DistanceNearZ    = 1,
	ThreatRanking_DistanceNear3D   = 2,
	ThreatRanking_DirectionForward = 3,
	ThreatRanking_UnitDamageCaused = 4,
	ThreatRanking_UnitAggroScore   = 5,
	ThreatRanking_InteractScore    = 6,
	ThreatRanking_StructureLowHealth = 7,
	ThreatRanking_StructureSize    = 8,
	ThreatRanking_DistanceNearEvent2D = 9,
	ThreatRanking_DistanceNearEventZ = 10,
	ThreatRanking_DistanceNearEvent3D = 11,
	ThreatRankingCount             = 12,
	EThreatRankingType_MAX         = 13
};


// Enum Otherlands.EThreatCategoryType
enum class EThreatCategoryType : uint8_t
{
	ThreatCategory_CurrentTarger   = 0,
	ThreatCategory_Visible         = 1,
	ThreatCategory_Unit            = 2,
	ThreatCategory_Player          = 3,
	ThreatCategory_Creature        = 4,
	ThreatCategory_UnitHasAggro    = 5,
	ThreatCategory_Interact        = 6,
	ThreatCategory_Structure       = 7,
	ThreatCategory_PointOfInterest = 8,
	ThreatCategory_FactionBase     = 9,
	ThreatCategory_ClanBase        = 10,
	ThreatCategory_PersonalBase    = 11,
	ThreatCategory_Freeplace       = 12,
	ThreatCategory_Harvest         = 13,
	ThreatCategoryCount            = 14,
	EThreatCategoryType_MAX        = 15
};


// Enum Otherlands.EThreatRuleFlags
enum class EThreatRuleFlags : uint8_t
{
	ThreatRule_UseDistance         = 0,
	ThreatRule_UseDirection        = 1,
	ThreatRule_UseDamage           = 2,
	ThreatRule_PreferCurrentTarger = 3,
	ThreatRule_PreferVisible       = 4,
	ThreatRule_PreferPlayer        = 5,
	ThreatRule_PickRandom          = 6,
	ThreatRule_RequireMatchingAbility = 7,
	ThreatRule_PickAbilityForEngagement = 8,
	ThreatRule_MAX                 = 9
};


// Enum Otherlands.ECreatureFamily_CodeMap
enum class ECreatureFamily_CodeMap : uint8_t
{
	CreatureFamily_CodeMap_Human   = 0,
	CreatureFamily_CodeMap_Unmapped = 1,
	CreatureFamilyCodeMapCount     = 2,
	ECreatureFamily_CodeMap_MAX    = 3
};


// Enum Otherlands.ESpawnScoreTriggerType
enum class ESpawnScoreTriggerType : uint8_t
{
	SpawnScoreTrigger_RisingEdge   = 0,
	SpawnScoreTrigger_FallingEdge  = 1,
	SpawnScoreTrigger_BothEdges    = 2,
	SpawnScoreTrigger_MAX          = 3
};


// Enum Otherlands.ESpawnTimeCycleType
enum class ESpawnTimeCycleType : uint8_t
{
	SpawnTimeCycle_NightOnly       = 0,
	SpawnTimeCycle_DayOnly         = 1,
	SpawnTimeCycle_Anytime         = 2,
	SpawnTimeCycle_MAX             = 3
};


// Enum Otherlands.ESpawnPointAvoidFlags
enum class ESpawnPointAvoidFlags : uint8_t
{
	SpawnPointAvoid_Pawn           = 0,
	SpawnPointAvoid_Water          = 1,
	SpawnPointAvoid_Resource       = 2,
	SpawnPointAvoid_Land           = 3,
	SpawnPointAvoid_MAX            = 4
};


// Enum Otherlands.ESpawnSpiritRealm
enum class ESpawnSpiritRealm : uint8_t
{
	SpawnSpiritRealm_NoOverride    = 0,
	SpawnSpiritRealm_InSpiritRealmOverride = 1,
	SpawnSpiritRealm_NotInSpiritRealmOverride = 2,
	SpawnSpiritRealm_MAX           = 3
};


// Enum Otherlands.ENetCullRangeType
enum class ENetCullRangeType : uint8_t
{
	NetCullRange_Ambush            = 0,
	NetCullRange_ExtraSmall        = 1,
	NetCullRange_Small             = 2,
	NetCullRange_Medium            = 3,
	NetCullRange_Large             = 4,
	NetCullRange_ExtraLarge        = 5,
	NetCullRange_Global            = 6,
	NetCullRange_MAX               = 7
};


// Enum Otherlands.ETempoEventType
enum class ETempoEventType : uint8_t
{
	TempoEvent_EnemyIgnores        = 0,
	TempoEvent_EnemyFlees          = 1,
	TempoEvent_EnemySelectsTarget  = 2,
	TempoEvent_EnemyRemoved        = 3,
	TempoEvent_EnemyKilled         = 4,
	TempoEvent_EnemySpawn          = 5,
	TempoEvent_DamageToHero        = 6,
	TempoEvent_DamageFromHero      = 7,
	TempoEvent_KilledAlly          = 8,
	TempoEvent_ZoneTickIn          = 9,
	TempoEvent_ZoneTickOut         = 10,
	TempoEvent_HeroHarvested       = 11,
	TempoEvent_Raw                 = 12,
	TempoEvent_Reset               = 13,
	TempoEventCount                = 14,
	ETempoEventType_MAX            = 15
};


// Enum Otherlands.ETempoChannel_CodeMap
enum class ETempoChannel_CodeMap : uint8_t
{
	TempoChannel_CodeMap_Ambush    = 0,
	TempoChannel_CodeMap_Unmapped  = 1,
	TempoChannelCodeMapCount       = 2,
	ETempoChannel_CodeMap_MAX      = 3
};


// Enum Otherlands.EUseSpellItemType
enum class EUseSpellItemType : uint8_t
{
	UseSpellItem_None              = 0,
	UseSpellItem_Consume           = 1,
	UseSpellItem_Primary           = 2,
	UseSpellItem_Secondary         = 3,
	UseSpellItem_MAX               = 4
};


// Enum Otherlands.ESpellCastActionType
enum class ESpellCastActionType : uint8_t
{
	SpellCastAction_None           = 0,
	SpellCastAction_PlayerSpell    = 1,
	SpellCastAction_MountSpell     = 2,
	SpellCastAction_UseItem        = 3,
	SpellCastAction_Buff           = 4,
	SpellCastAction_MAX            = 5
};


// Enum Otherlands.ESpellHitBoxType
enum class ESpellHitBoxType : uint8_t
{
	SpellHitBox_Cone               = 0,
	SpellHitBox_Sphere             = 1,
	SpellHitBox_Line               = 2,
	SpellHitBox_CenteredLine       = 3,
	SpellHitBox_MAX                = 4
};


// Enum Otherlands.EAllowedMovementFlags
enum class EAllowedMovementFlags : uint8_t
{
	AllowedMovement_Standing       = 0,
	AllowedMovement_Moving         = 1,
	AllowedMovement_Sprinting      = 2,
	AllowedMovement_Falling        = 3,
	AllowedMovement_Mounted        = 4,
	AllowedMovement_MAX            = 5
};


// Enum Otherlands.EPlayerAbilitySource
enum class EPlayerAbilitySource : uint8_t
{
	PlayerAbilitySource_SpellBook  = 0,
	PlayerAbilitySource_Item       = 1,
	PlayerAbilitySource_BuffTrigger = 2,
	PlayerAbilitySource_Default    = 3,
	PlayerAbilitySource_ClientItem = 4,
	PlayerAbilitySourceCount       = 5,
	EPlayerAbilitySource_MAX       = 6
};


// Enum Otherlands.ECustomBuffType
enum class ECustomBuffType : uint8_t
{
	CustomBuff_ScaleCharacter      = 0,
	CustomBuffCount                = 1,
	ECustomBuffType_MAX            = 2
};


// Enum Otherlands.ECustomAbilityType
enum class ECustomAbilityType : uint8_t
{
	CustomAbility_OpenSpiritPortal = 0,
	CustomAbility_CooldownOffset   = 1,
	CustomAbility_CooldownScalar   = 2,
	CustomAbility_CooldownScalarMax = 3,
	CustomAbility_SummonCasterLevel = 4,
	CustomAbility_SummonRandomLevel = 5,
	CustomAbility_CreateLootPersonal = 6,
	CustomAbility_CreateLootZoneForage = 7,
	CustomAbilityCount             = 8,
	ECustomAbilityType_MAX         = 9
};


// Enum Otherlands.EBuffCategoryResistType
enum class EBuffCategoryResistType : uint8_t
{
	BuffCategoryResist_IgnoreStack = 0,
	BuffCategoryResist_StackReduction = 1,
	BuffCategoryResist_DurationReduction = 2,
	BuffCategoryResist_MAX         = 3
};


// Enum Otherlands.EBuffStackingRule
enum class EBuffStackingRule : uint8_t
{
	BuffStackingRule_UpgradeTo     = 0,
	BuffStackingRule_CompoundWith  = 1,
	BuffStackingRule_ApplyBuff     = 2,
	BuffStackingRuleCount          = 3,
	EBuffStackingRule_MAX          = 4
};


// Enum Otherlands.EBuffRemoveReason
enum class EBuffRemoveReason : uint8_t
{
	BuffRemove_Expire              = 0,
	BuffRemove_Cleanse             = 1,
	BuffRemove_Other               = 2,
	BuffRemove_Trigger             = 3,
	BuffRemoveCount                = 4,
	EBuffRemoveReason_MAX          = 5
};


// Enum Otherlands.EPrerequisiteOperator
enum class EPrerequisiteOperator : uint8_t
{
	PrerequisiteOperator_EqualTo   = 0,
	PrerequisiteOperator_NotEqualTo = 1,
	PrerequisiteOperator_LessThan  = 2,
	PrerequisiteOperator_GreaterThan = 3,
	PrerequisiteOperator_LessThanEqualTo = 4,
	PrerequisiteOperator_GreaterThanEqualTo = 5,
	PrerequisiteOperator_Is        = 6,
	PrerequisiteOperator_Not       = 7,
	PrerequisiteOperator_And       = 8,
	PrerequisiteOperator_Or        = 9,
	PrerequisiteOperatorCount      = 10,
	EPrerequisiteOperator_MAX      = 11
};


// Enum Otherlands.EPrerequisiteEntity
enum class EPrerequisiteEntity : uint8_t
{
	PrerequisiteEntity_SelfCharacter = 0,
	PrerequisiteEntity_TargetCharacter = 1,
	PrerequisiteEntity_Prerequisite = 2,
	PrerequisiteEntity_Value       = 3,
	PrerequisiteEntity_Custom      = 4,
	PrerequisiteEntityCount        = 5,
	EPrerequisiteEntity_MAX        = 6
};


// Enum Otherlands.EPrerequisiteType
enum class EPrerequisiteType : uint8_t
{
	PrerequisiteType_StatPercent   = 0,
	PrerequisiteType_StatValue     = 1,
	PrerequisiteType_Distance      = 2,
	PrerequisiteType_BuffStackCount = 3,
	PrerequisiteType_BuffCategoryPresent = 4,
	PrerequisiteType_Compound      = 5,
	PrerequisiteType_CharacterGameplayScale = 6,
	PrerequisiteTypeCount          = 7,
	EPrerequisiteType_MAX          = 8
};


// Enum Otherlands.EProjectileTargeting
enum class EProjectileTargeting : uint8_t
{
	ProjectileTargeting_Dumbfire   = 0,
	ProjectileTargeting_Lead       = 1,
	ProjectileTargetingCount       = 2,
	EProjectileTargeting_MAX       = 3
};


// Enum Otherlands.EProjectileLaunch
enum class EProjectileLaunch : uint8_t
{
	ProjectileLaunch_Default       = 0,
	ProjectileLaunch_Time          = 1,
	ProjectileLaunchCount          = 2,
	EProjectileLaunch_MAX          = 3
};


// Enum Otherlands.EBuffTracerCombine
enum class EBuffTracerCombine : uint8_t
{
	BuffTracerCombine_Add          = 0,
	BuffTracerCombine_Replace      = 1,
	BuffTracerCombine_MAX          = 2
};


// Enum Otherlands.ToolTipWidgetMode
enum class EToolTipWidgetMode : uint8_t
{
	MODE_NONE                      = 0,
	MODE_CRAFTRECIPE               = 1,
	MODE_INVENTORYITEM             = 2,
	MODE_PLACEDITEM                = 3,
	MODE_MAX                       = 4
};


// Enum Otherlands.EEventHandlerWidgetActivated
enum class EEventHandlerWidgetActivated : uint8_t
{
	EEventHandlerWidgetActivated__Activated = 0,
	EEventHandlerWidgetActivated__Deactivated = 1,
	EEventHandlerWidgetActivated__EEventHandlerWidgetActivated_MAX = 2
};


// Enum Otherlands.EMenuGroup
enum class EMenuGroup : uint8_t
{
	MenuGroup_Inventory            = 0,
	MenuGroup_Crafting             = 1,
	MenuGroup_CraftSkillTree       = 2,
	MenuGroup_Context              = 3,
	MenuGroup_Progression          = 4,
	MenuGroup_Talents              = 5,
	MenuGroup_Tech                 = 6,
	MenuGroup_Settings             = 7,
	MenuGroupCount                 = 8,
	EMenuGroup_MAX                 = 9
};


// Enum Otherlands.EEventLogType
enum class EEventLogType : uint8_t
{
	EEventLogType__MemberLevelMilestoneAchieved = 0,
	EEventLogType__MemberRankChanged = 1,
	EEventLogType__OutcastVoteInitiated = 2,
	EEventLogType__OutcastVoteSuccess = 3,
	EEventLogType__OutcastVoteFail = 4,
	EEventLogType__FactionExceedUseScore = 5,
	EEventLogType__FriendlyCorpseLooted = 6,
	EEventLogType__DemolishVoteInitiated = 7,
	EEventLogType__DemolishVoteSuccess = 8,
	EEventLogType__DemolishVoteFail = 9,
	EEventLogType__Unmapped        = 10,
	EEventLogType__EEventLogType_MAX = 11
};


// Enum Otherlands.EEventLogParameterType
enum class EEventLogParameterType : uint8_t
{
	EEventLogParameterType__None   = 0,
	EEventLogParameterType__Integer = 1,
	EEventLogParameterType__Float  = 2,
	EEventLogParameterType__Text   = 3,
	EEventLogParameterType__Item   = 4,
	EEventLogParameterType__Zone   = 5,
	EEventLogParameterType__Faction = 6,
	EEventLogParameterType__Title  = 7,
	EEventLogParameterType__EEventLogParameterType_MAX = 8
};


// Enum Otherlands.EDamageSourceType
enum class EDamageSourceType : uint8_t
{
	DamageSource_PlayerSpell       = 0,
	DamageSource_CreatureAbility   = 1,
	DamageSource_Buff              = 2,
	DamageSource_Item              = 3,
	DamageSource_Weapon            = 4,
	DamageSource_Exhaustion_DEPRECATED = 5,
	DamageSource_Dehydration       = 6,
	DamageSource_Starvation        = 7,
	DamageSource_Falling           = 8,
	DamageSourceCount              = 9,
	EDamageSourceType_MAX          = 10
};



//---------------------------------------------------------------------------
// Script Structs
//---------------------------------------------------------------------------

// ScriptStruct Otherlands.CastAction
// 0x0060
struct FCastAction
{
	TEnumAsByte<ECastActionType>                       CastActionType;                                           // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FName                                       DataId;                                                   // 0x0008(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bForceCast;                                               // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
	struct FVector                                     CastLocation;                                             // 0x0014(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FVector                                     ProjectileFireLocation;                                   // 0x0020(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FVector                                     FireVector;                                               // 0x002C(0x000C) (BlueprintVisible, IsPlainOldData)
	TWeakObjectPtr<class UBuffData>                    SourceBuff;                                               // 0x0038(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class UInventoryItem>               InventoryItem;                                            // 0x0040(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bActionTriggered;                                         // 0x0048(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bDeductSpellCost;                                         // 0x0049(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x6];                                       // 0x004A(0x0006) MISSED OFFSET
	struct FName                                       InteractActionId;                                         // 0x0050(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ECastActionErrorType                               ErrorType;                                                // 0x0058(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0059(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.StatEffectData
// 0x0008
struct FStatEffectData
{
	TEnumAsByte<ECharacterStat>                        CharacterStat;                                            // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              StatValue;                                                // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CleanseBuffEntryData
// 0x0010
struct FCleanseBuffEntryData
{
	struct FName                                       BuffCategory;                                             // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BuffTier;                                                 // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                StackCount;                                               // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.BuffEntryData
// 0x0010
struct FBuffEntryData
{
	struct FName                                       BuffId;                                                   // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                StackCount;                                               // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.GeneralFXData
// 0x0048
struct FGeneralFXData
{
	struct FName                                       AttachSocket;                                             // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAttachToWeapon;                                          // 0x0008(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bStationaryFX;                                            // 0x0009(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x000A(0x0006) MISSED OFFSET
	class UParticleSystem*                             Particles;                                                // 0x0010(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   SoundCue;                                                 // 0x0018(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0020(0x0028) UNKNOWN PROPERTY: SoftClassProperty Otherlands.GeneralFXData.PointLight
};

// ScriptStruct Otherlands.AbilityData
// 0x0438 (0x0458 - 0x0020)
struct FAbilityData : public FTableRowSequencedBase
{
	float                                              MinRange;                                                 // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxRange;                                                 // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRangeScaled;                                             // 0x0028(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0029(0x0003) MISSED OFFSET
	int                                                CharacterStatusFlagsPrevent;                              // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CastPrerequisiteId;                                       // 0x0030(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FStatEffectData>                     InstantStats;                                             // 0x0038(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	class UStaticMesh*                                 ProjectileMesh;                                           // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileSpeed;                                          // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileDistance;                                       // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileDistanceBeforeGravity;                          // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileGravityScale;                                   // 0x005C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileLaunchAngle;                                    // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileMinTime;                                        // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileMaxTime;                                        // 0x0068(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileTimeJitter;                                     // 0x006C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileXYJitter;                                       // 0x0070(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EProjectileLaunch>                     ProjectileLaunch;                                         // 0x0074(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EProjectileTargeting>                  ProjectileTargeting;                                      // 0x0075(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x0076(0x0002) MISSED OFFSET
	float                                              ProjectileLifeSpanAfterImpact;                            // 0x0078(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECastMethod>                           CastMethod;                                               // 0x007C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x007D(0x0003) MISSED OFFSET
	int                                                CastTargetFlags;                                          // 0x0080(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x0084(0x0004) MISSED OFFSET
	struct FName                                       SourceBoneName;                                           // 0x0088(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ChargeTime;                                               // 0x0090(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ChargeTimeMax;                                            // 0x0094(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           DamageType;                                               // 0x0098(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESpellHitBoxType>                      HitBoxType;                                               // 0x0099(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x2];                                       // 0x009A(0x0002) MISSED OFFSET
	float                                              TrueDamagePercent;                                        // 0x009C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitDamageRadius;                                         // 0x00A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitDamageCone;                                           // 0x00A4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitDamageSpeed;                                          // 0x00A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamageRadius;                                        // 0x00AC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamageCone;                                          // 0x00B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamageSpeed;                                         // 0x00B4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PercentAtMaxDist;                                         // 0x00B8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x00BC(0x0004) MISSED OFFSET
	TArray<struct FCleanseBuffEntryData>               CleanseData;                                              // 0x00C0(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FBuffEntryData>                      TargetBuffs;                                              // 0x00D0(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FBuffEntryData>                      SelfBuffs;                                                // 0x00E0(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	int                                                MaxDirectTargets;                                         // 0x00F0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Cooldown;                                                 // 0x00F4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CooldownMax;                                              // 0x00F8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CoolupMin;                                                // 0x00FC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CoolupMax;                                                // 0x0100(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              GlobalCooldown;                                           // 0x0104(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              GlobalCooldownMax;                                        // 0x0108(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIgnoreGlobalCooldown;                                    // 0x010C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x3];                                       // 0x010D(0x0003) MISSED OFFSET
	struct FName                                       CooldownGroupId;                                          // 0x0110(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRootDuringGCD;                                           // 0x0118(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x7];                                       // 0x0119(0x0007) MISSED OFFSET
	struct FName                                       ImpactEffectKitId;                                        // 0x0120(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TeleportDistance;                                         // 0x0128(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTeleportSelfToTarget;                                    // 0x012C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTeleportThroughStructures;                               // 0x012D(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECustomAbilityType>                    CustomAbilityType;                                        // 0x012E(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData08[0x1];                                       // 0x012F(0x0001) MISSED OFFSET
	float                                              CustomAbililityFloatData[0x3];                            // 0x0130(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData09[0x4];                                       // 0x013C(0x0004) MISSED OFFSET
	struct FName                                       CustomAbilityId[0x3];                                     // 0x0140(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FGeneralFXData                              StartFX;                                                  // 0x0158(0x0048) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FGeneralFXData                              CastFX[0x3];                                              // 0x01A0(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              ChargeFX;                                                 // 0x0278(0x0048) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FGeneralFXData                              TargetFX[0x3];                                            // 0x02C0(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              GroundFX;                                                 // 0x0398(0x0048) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	class UParticleSystem*                             TracerEffect;                                             // 0x03E0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFireFromWeapon;                                          // 0x03E8(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData10[0x7];                                       // 0x03E9(0x0007) MISSED OFFSET
	class UClass*                                      CameraShakeClass;                                         // 0x03F0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraShakeInnerRadius;                                   // 0x03F8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraShakeOuterRadius;                                   // 0x03FC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraShakeFalloff;                                       // 0x0400(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData11[0x4];                                       // 0x0404(0x0004) MISSED OFFSET
	class UMaterial*                                   DecalMaterial;                                            // 0x0408(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FVector                                     DecalSize;                                                // 0x0410(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	struct FRotator                                    DecalRotation;                                            // 0x041C(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	float                                              DecalLifeSpan;                                            // 0x0428(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DecalFadeDelay;                                           // 0x042C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterialInterface*                          WeaponGlowMaterial;                                       // 0x0430(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 WeaponGlowCurve;                                          // 0x0438(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       WeaponGlowParameterName;                                  // 0x0440(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PayloadId;                                                // 0x0448(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PayloadDelay;                                             // 0x0450(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData12[0x4];                                       // 0x0454(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.FavoriteServerAddRequest
// 0x0020
struct FFavoriteServerAddRequest
{
	struct FString                                     ServerId;                                                 // 0x0000(0x0010) (BlueprintVisible, ZeroConstructor)
	struct FString                                     ServerName;                                               // 0x0010(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.TrackTargetData
// 0x0030
struct FTrackTargetData
{
	class UObject*                                     TargetObject;                                             // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector                                     Location;                                                 // 0x0008(0x000C) (BlueprintVisible, IsPlainOldData)
	int                                                HitItem;                                                  // 0x0014(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETargetType>                           Type;                                                     // 0x0018(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EAIReaction>                           Reaction;                                                 // 0x0019(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bCanSee;                                                  // 0x001A(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x001B(0x0001) MISSED OFFSET
	float                                              UniqueScores[0x2];                                        // 0x001C(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                SensedBy;                                                 // 0x0024(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                Priority;                                                 // 0x0028(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Score;                                                    // 0x002C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureBehaviorData
// 0x0040
struct FCreatureBehaviorData
{
	class UBehaviorTree*                               BaseTree;                                                 // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               Combat;                                                   // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               Interact;                                                 // 0x0010(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               Idle;                                                     // 0x0018(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               Aware;                                                    // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               Search;                                                   // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               Flee;                                                     // 0x0030(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               FleeRepeat;                                               // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.GameEventData
// 0x0010
struct FGameEventData
{
	TWeakObjectPtr<class UObject>                      Owner;                                                    // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class UObject>                      Instigator;                                               // 0x0008(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CharacterDeathEventData
// 0x0028 (0x0038 - 0x0010)
struct FCharacterDeathEventData : public FGameEventData
{
	TEnumAsByte<EKilledByType>                         KilledBy;                                                 // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EDamageSourceType>                     Source;                                                   // 0x0011(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0012(0x0006) MISSED OFFSET
	struct FName                                       KillerSourceId;                                           // 0x0018(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FString                                     KillerPlayerName;                                         // 0x0020(0x0010) (BlueprintVisible, ZeroConstructor)
	int                                                KillerFactionId;                                          // 0x0030(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0034(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterSoulHarvestEventData
// 0x0004 (0x0014 - 0x0010)
struct FCharacterSoulHarvestEventData : public FGameEventData
{
	float                                              SoulsHarvested;                                           // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureHarvestData
// 0x0068
struct FCreatureHarvestData
{
	TEnumAsByte<EHarvestType>                          HarvestType;                                              // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAllowCorpseHarvest;                                      // 0x0001(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0002(0x0002) MISSED OFFSET
	int                                                HarvestQuality;                                           // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 RatingQualityOffsetCurve;                                 // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              QuantityMultiplier;                                       // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestDelayMinTime;                                      // 0x0014(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestDelayMaxTime;                                      // 0x0018(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestRange;                                             // 0x001C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestDamageMin;                                         // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestDamageMax;                                         // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 RatingDamageMultiplierCurve;                              // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              GlobalAdditiveDropChance;                                 // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0034(0x0004) MISSED OFFSET
	class UCurveFloat*                                 RatingGlobalAdditveDropChanceOffsetCurve;                 // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<float>                                      AdditiveDropChances;                                      // 0x0040(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<class UCurveFloat*>                         RatingAdditiveDropChanceOffsetCurves;                     // 0x0050(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       ImpactEffectKitId;                                        // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SummonCollectionId
// 0x0010
struct FSummonCollectionId
{
	struct FName                                       CreatureBaseId;                                           // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                VariantIndex;                                             // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Rating;                                                   // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.SummonCollectionPersonal
// 0x0020 (0x0030 - 0x0010)
struct FSummonCollectionPersonal : public FSummonCollectionId
{
	struct FString                                     GivenName;                                                // 0x0010(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FString                                     UniqueId;                                                 // 0x0020(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.DamageConversion
// 0x0010
struct FDamageConversion
{
	TEnumAsByte<EDamageType>                           DamageType;                                               // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              ConversionRate;                                           // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              BonusRate;                                                // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Scalar;                                                   // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.DamageConversionSet
// 0x0018
struct FDamageConversionSet
{
	TArray<struct FDamageConversion>                   Conversions;                                              // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	float                                              UnitScalar;                                               // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SiegeScalar;                                              // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerBuffEntry
// 0x0028
struct FPlayerBuffEntry
{
	struct FName                                       BuffId;                                                   // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TimeRemaining;                                            // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x000C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FDamageConversionSet                        DamageConversion;                                         // 0x0010(0x0018) (BlueprintVisible)
};

// ScriptStruct Otherlands.SummonCollectionEntry
// 0x0048 (0x0078 - 0x0030)
struct FSummonCollectionEntry : public FSummonCollectionPersonal
{
	bool                                               bFavorite;                                                // 0x0030(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
	struct FDateTime                                   LastImported;                                             // 0x0038(0x0008) (Edit, BlueprintVisible)
	int                                                Level;                                                    // 0x0040(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                XP;                                                       // 0x0044(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Health;                                                   // 0x0048(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Stamina;                                                  // 0x004C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FDateTime                                   LastSaveTime;                                             // 0x0050(0x0008) (BlueprintVisible, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
	TArray<struct FPlayerBuffEntry>                    Buffs;                                                    // 0x0058(0x0010) (BlueprintVisible, ZeroConstructor, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
	float                                              MaxHealth;                                                // 0x0068(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	float                                              MaxStamina;                                               // 0x006C(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	float                                              MaxCarryWeight;                                           // 0x0070(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0074(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.AIAggroEvent
// 0x0030
struct FAIAggroEvent
{
	struct FVector                                     AggroLocation;                                            // 0x0000(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              AggroStrength;                                            // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AggroMinAge;                                              // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	class AActor*                                      Owner;                                                    // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class AActor*                                      Instigator;                                               // 0x0020(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0028(0x0008) MISSED OFFSET
};

// ScriptStruct Otherlands.AIGameNoiseEvent
// 0x0028
struct FAIGameNoiseEvent
{
	unsigned char                                      UnknownData00[0x4];                                       // 0x0000(0x0004) MISSED OFFSET
	struct FVector                                     NoiseLocation;                                            // 0x0004(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              Loudness;                                                 // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxRange;                                                 // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class AActor*                                      Instigator;                                               // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0020(0x0008) MISSED OFFSET
};

// ScriptStruct Otherlands.AIHuntEvent
// 0x0030
struct FAIHuntEvent
{
	struct FVector                                     HuntLocation;                                             // 0x0000(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              HuntStrength;                                             // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              HuntMinAge;                                               // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	class AActor*                                      Owner;                                                    // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class AActor*                                      Instigator;                                               // 0x0020(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0028(0x0008) MISSED OFFSET
};

// ScriptStruct Otherlands.SpawnNamedParameter
// 0x0018
struct FSpawnNamedParameter
{
	struct FName                                       ParameterName;                                            // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       NameValue;                                                // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FloatValue;                                               // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              IntValue;                                                 // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpawnActorParameters
// 0x0078
struct FSpawnActorParameters
{
	struct FName                                       CreatureBaseId;                                           // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       LootBaseId;                                               // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SpawnCount;                                               // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                LevelMin;                                                 // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                LevelMax;                                                 // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
	class UClass*                                      OverrideActor;                                            // 0x0020(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FCreatureBehaviorData                       OverrideBehavior;                                         // 0x0028(0x0040) (Edit, BlueprintVisible)
	TArray<struct FSpawnNamedParameter>                NamedParameters;                                          // 0x0068(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.SpawnGroupData
// 0x0028 (0x0048 - 0x0020)
struct FSpawnGroupData : public FTableRowSequencedBase
{
	class UClass*                                      SpawnGroupClass;                                          // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UBehaviorTree*                               GroupBehaviorTree;                                        // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       GroupThreatRuleId;                                        // 0x0030(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FSpawnActorParameters>               Spawns;                                                   // 0x0038(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.SpawnLocation
// 0x0058
struct FSpawnLocation
{
	struct FVector                                     Center;                                                   // 0x0000(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              GroupOffset;                                              // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SpawnOffset;                                              // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ZRange;                                                   // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector                                     GroupOffsetDir;                                           // 0x0018(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	TEnumAsByte<EWaveSpawnLocation>                    GroupLocation;                                            // 0x0024(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESpawnSpiritRealm>                     SpiritRealm;                                              // 0x0025(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0026(0x0002) MISSED OFFSET
	struct FNavAgentProperties                         NavAgentProps;                                            // 0x0028(0x0030) (Edit, BlueprintVisible)
};

// ScriptStruct Otherlands.SpawnOverrides
// 0x0028
struct FSpawnOverrides
{
	int                                                FactionId;                                                // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MinLevel;                                                 // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaxLevel;                                                 // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              CountScalar;                                              // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              RestrictLifeSpan;                                         // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	TArray<struct FSpawnNamedParameter>                NamedParameters;                                          // 0x0018(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.SpawnGroupEntry
// 0x0010
struct FSpawnGroupEntry
{
	struct FName                                       SpawnGroupId;                                             // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProbabilityWeight;                                        // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.SpawnBaseData
// 0x0020 (0x0040 - 0x0020)
struct FSpawnBaseData : public FTableRowSequencedBase
{
	bool                                               bSpawnInSpiritRealm;                                      // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class UClass*                                      SpawnerInstanceClass;                                     // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FSpawnGroupEntry>                    SpawnGroups;                                              // 0x0030(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.ToolTipData
// 0x0168
struct FToolTipData
{
	struct FText                                       Title;                                                    // 0x0000(0x0018) (Edit, BlueprintVisible)
	class UTexture2D*                                  Icon;                                                     // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FText                                       CraftedByText;                                            // 0x0020(0x0018) (Edit, BlueprintVisible)
	struct FText                                       TooltipContentText;                                       // 0x0038(0x0018) (Edit, BlueprintVisible)
	struct FText                                       CategoryText;                                             // 0x0050(0x0018) (Edit, BlueprintVisible)
	struct FText                                       DescriptionText;                                          // 0x0068(0x0018) (Edit, BlueprintVisible)
	struct FText                                       DecayText;                                                // 0x0080(0x0018) (Edit, BlueprintVisible)
	float                                              DecayTime;                                                // 0x0098(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x009C(0x0004) MISSED OFFSET
	struct FText                                       FunctionText;                                             // 0x00A0(0x0018) (Edit, BlueprintVisible)
	struct FText                                       SoulboundText;                                            // 0x00B8(0x0018) (Edit, BlueprintVisible)
	struct FText                                       TypeText;                                                 // 0x00D0(0x0018) (Edit, BlueprintVisible)
	struct FText                                       BaseStatsText;                                            // 0x00E8(0x0018) (Edit, BlueprintVisible)
	struct FText                                       BaseBuffText;                                             // 0x0100(0x0018) (Edit, BlueprintVisible)
	struct FText                                       AffixStatsText;                                           // 0x0118(0x0018) (Edit, BlueprintVisible)
	struct FText                                       AffixBuffText;                                            // 0x0130(0x0018) (Edit, BlueprintVisible)
	struct FText                                       FlavorText;                                               // 0x0148(0x0018) (Edit, BlueprintVisible)
	float                                              Durability;                                               // 0x0160(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EItemQuality>                          ToolTipQuality;                                           // 0x0164(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0165(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.AscensionUnlock
// 0x0010
struct FAscensionUnlock
{
	struct FName                                       AscensionPerkId;                                          // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                Rank;                                                     // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.AscensionMatchData
// 0x0088
struct FAscensionMatchData
{
	int                                                SagaPoints;                                               // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TrackedActivity;                                          // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TrackedRelevance;                                         // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AdjustActivity;                                           // 0x000C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TMap<struct FName, struct FAscensionUnlock>        Loadout;                                                  // 0x0010(0x0050) (BlueprintVisible, ZeroConstructor)
	float                                              DesiredActivity;                                          // 0x0060(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	float                                              LastRelevanceTime;                                        // 0x0064(0x0004) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	int                                                EarnedPoints;                                             // 0x0068(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                GameEndEarnedPoints;                                      // 0x006C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SpentPoints;                                              // 0x0070(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0074(0x0004) MISSED OFFSET
	TArray<struct FAscensionUnlock>                    Unlocks;                                                  // 0x0078(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.AscensionEternalData
// 0x0018
struct FAscensionEternalData
{
	int                                                EarnedPoints;                                             // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SpentPoints;                                              // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FAscensionUnlock>                    Unlocks;                                                  // 0x0008(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.AscensionSlotPerk
// 0x0018
struct FAscensionSlotPerk
{
	struct FName                                       LoadoutId;                                                // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FAscensionUnlock                            UnlockData;                                               // 0x0008(0x0010) (Edit, BlueprintVisible)
};

// ScriptStruct Otherlands.KeyData
// 0x0018
struct FKeyData
{
	int                                                Version;                                                  // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FString                                     Data;                                                     // 0x0008(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.AuthTicket
// 0x0030
struct FAuthTicket
{
	bool                                               bValid;                                                   // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	int                                                Platform;                                                 // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FString                                     ID;                                                       // 0x0008(0x0010) (ZeroConstructor)
	struct FString                                     Key;                                                      // 0x0018(0x0010) (ZeroConstructor)
	int                                                Expiration;                                               // 0x0028(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.StructureGrid
// 0x0068
struct FStructureGrid
{
	int                                                Padding;                                                  // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FIntVector                                  UseableMax;                                               // 0x0004(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	struct FIntVector                                  UseableMin;                                               // 0x0010(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	struct FIntVector                                  RealMax;                                                  // 0x001C(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	struct FIntVector                                  RealMin;                                                  // 0x0028(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	struct FVector                                     Origin;                                                   // 0x0034(0x000C) (Edit, BlueprintVisible, EditConst, IsPlainOldData)
	struct FVector                                     EffectiveOrigin;                                          // 0x0040(0x000C) (Edit, BlueprintVisible, EditConst, IsPlainOldData)
	struct FVector                                     Extents;                                                  // 0x004C(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	float                                              Yaw;                                                      // 0x0058(0x0004) (Edit, BlueprintVisible, ZeroConstructor, EditConst, IsPlainOldData)
	struct FVector                                     AxisAlignedExtents;                                       // 0x005C(0x000C) (Edit, BlueprintVisible, EditConst, IsPlainOldData)
};

// ScriptStruct Otherlands.TempoSpawn
// 0x0010
struct FTempoSpawn
{
	class ASpawnGroup*                                 SpawnGroup;                                               // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bShouldForget;                                            // 0x0008(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0009(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterTempoEventData
// 0x0018 (0x0028 - 0x0010)
struct FCharacterTempoEventData : public FGameEventData
{
	float                                              Value;                                                    // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	struct FName                                       TempoChannelId;                                           // 0x0018(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     TempoState;                                               // 0x0020(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterDamageEventData
// 0x0028 (0x0038 - 0x0010)
struct FCharacterDamageEventData : public FGameEventData
{
	TEnumAsByte<EDamageSourceType>                     Source;                                                   // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
	struct FVector                                     SourceDirection;                                          // 0x0014(0x000C) (BlueprintVisible, IsPlainOldData)
	struct FName                                       SourceId;                                                 // 0x0020(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                DamageTypes;                                              // 0x0028(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TotalDamage;                                              // 0x002C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsCrit;                                                  // 0x0030(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.TypedDamageInstance
// 0x000C
struct FTypedDamageInstance
{
	TEnumAsByte<EDamageType>                           DamageType;                                               // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              Damage;                                                   // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              PercentUnmitigated;                                       // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.TypedDamage
// 0x0030
struct FTypedDamage
{
	TArray<struct FTypedDamageInstance>                Damages;                                                  // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	bool                                               bAffectsDurabiity;                                        // 0x0010(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsCrit;                                                  // 0x0011(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EMountHitType>                         MountHit;                                                 // 0x0012(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EDamageSourceType>                     Source;                                                   // 0x0013(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	struct FName                                       ReferenceId;                                              // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x10];                                      // 0x0020(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterDetailedDamageEventData
// 0x0030 (0x0068 - 0x0038)
struct FCharacterDetailedDamageEventData : public FCharacterDamageEventData
{
	struct FTypedDamage                                Detail;                                                   // 0x0038(0x0030) (BlueprintVisible)
};

// ScriptStruct Otherlands.SelectionFailureData
// 0x0010
struct FSelectionFailureData
{
	float                                              MaxNoSelectionScalar;                                     // 0x0000(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MinNoSelectionTime;                                       // 0x0004(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MinNoDamageTime;                                          // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                MinNoDamageCount;                                         // 0x000C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ThreatRanking
// 0x0008
struct FThreatRanking
{
	TEnumAsByte<EThreatRankingType>                    Ranking;                                                  // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              Scalar;                                                   // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ThreatCategory
// 0x0020
struct FThreatCategory
{
	int                                                CategoryFlags;                                            // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bMatchAll;                                                // 0x0004(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bRequireAttackSpace;                                      // 0x0005(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0006(0x0002) MISSED OFFSET
	int                                                Priority;                                                 // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Scalar;                                                   // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FThreatRanking>                      Rankings;                                                 // 0x0010(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.ThreatRuleData
// 0x0010 (0x0030 - 0x0020)
struct FThreatRuleData : public FTableRowSequencedBase
{
	TArray<struct FThreatCategory>                     Threats;                                                  // 0x0020(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.FindStructureTargetQuery
// 0x00D0
struct FFindStructureTargetQuery
{
	TWeakObjectPtr<class APawn>                        Pawn;                                                     // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FTrackTargetData                            PreviousTarget;                                           // 0x0008(0x0030) (BlueprintVisible)
	struct FVector                                     TargetLocation;                                           // 0x0038(0x000C) (BlueprintVisible, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	struct FThreatRuleData                             ThreatRule;                                               // 0x0048(0x0030) (BlueprintVisible)
	TEnumAsByte<EStructureQueryPhase>                  Phase;                                                    // 0x0078(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0079(0x0007) MISSED OFFSET
	TArray<struct FTrackTargetData>                    LastTargetData;                                           // 0x0080(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	unsigned char                                      UnknownData02[0x40];                                      // 0x0090(0x0040) MISSED OFFSET
};

// ScriptStruct Otherlands.PathFailureScoreScalar
// 0x0008
struct FPathFailureScoreScalar
{
	TEnumAsByte<EPathFailReason>                       Reason;                                                   // 0x0000(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              Scalar;                                                   // 0x0004(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PathFailureData
// 0x0038
struct FPathFailureData
{
	float                                              OutSpiritRealmTime;                                       // 0x0000(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              InSpiritRealmTime;                                        // 0x0004(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              SuccessDecayRate;                                         // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MinAttackObstructionMoveDist;                             // 0x000C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MinAttackObstructionCooldown;                             // 0x0010(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MinAttackObstructionCoolup;                               // 0x0014(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              BackoffFrameScalar;                                       // 0x0018(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              BackoffCascadeScalar;                                     // 0x001C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              BackoffMaxTime;                                           // 0x0020(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              BackoffSucessInverseScalar;                               // 0x0024(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	TArray<struct FPathFailureScoreScalar>             Scores;                                                   // 0x0028(0x0010) (Edit, ZeroConstructor)
};

// ScriptStruct Otherlands.AbilityGameEventData
// 0x0004 (0x0014 - 0x0010)
struct FAbilityGameEventData : public FGameEventData
{
	TEnumAsByte<EAbilityCastingState>                  PreviousState;                                            // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.QueuedModifyStack
// 0x0030
struct FQueuedModifyStack
{
	int                                                Delta;                                                    // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bHasConversion;                                           // 0x0004(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0005(0x0003) MISSED OFFSET
	struct FDamageConversionSet                        AddedConversion;                                          // 0x0008(0x0018)
	bool                                               bAllowRefresh;                                            // 0x0020(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class AActor*                                      BuffCauser;                                               // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.QueuedEffectiveness
// 0x0008
struct FQueuedEffectiveness
{
	float                                              StackEffectiveness;                                       // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              DurationEffectiveness;                                    // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CharaterBuffEventData
// 0x0010 (0x0020 - 0x0010)
struct FCharaterBuffEventData : public FGameEventData
{
	struct FName                                       BuffId;                                                   // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                OldStackCount;                                            // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                NewStackCount;                                            // 0x001C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CharaterBuffTriggerEventData
// 0x0008 (0x0028 - 0x0020)
struct FCharaterBuffTriggerEventData : public FCharaterBuffEventData
{
	TEnumAsByte<EBuffTrigger>                          BuffTrigger;                                              // 0x0020(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.CastAbilityInstance
// 0x0038
struct FCastAbilityInstance
{
	unsigned char                                      UnknownData00[0x38];                                      // 0x0000(0x0038) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterStatFloatItem
// 0x0004 (0x0010 - 0x000C)
struct FCharacterStatFloatItem : public FFastArraySerializerItem
{
	float                                              Value;                                                    // 0x000C(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CharacterStatFloatArray
// 0x0018 (0x00C8 - 0x00B0)
struct FCharacterStatFloatArray : public FFastArraySerializer
{
	TArray<struct FCharacterStatFloatItem>             Items;                                                    // 0x00B0(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x8];                                       // 0x00C0(0x0008) MISSED OFFSET
};

// ScriptStruct Otherlands.TutorialBaseData
// 0x0038 (0x0058 - 0x0020)
struct FTutorialBaseData : public FTableRowSequencedBase
{
	struct FText                                       TitleText;                                                // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       TooltipText;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<ETutorial_CodeMap>                     TutorialCodeMap;                                          // 0x0050(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0051(0x0003) MISSED OFFSET
	float                                              TriggerDelay;                                             // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SkinColorBaseData
// 0x0040 (0x0060 - 0x0020)
struct FSkinColorBaseData : public FTableRowSequencedBase
{
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	struct FLinearColor                                SkinMult;                                                 // 0x0024(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                Subcolor;                                                 // 0x0034(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
	float                                              Opacity;                                                  // 0x0044(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpecMult;                                                 // 0x0048(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
	struct FAscensionUnlock                            AscensionRequired;                                        // 0x0050(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Otherlands.SecondarySkillStatData
// 0x0020 (0x0040 - 0x0020)
struct FSecondarySkillStatData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<ECharacterStatDisplayType>             DisplayEnum;                                              // 0x0038(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkillStat>                   SkillStat;                                                // 0x0039(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x003A(0x0006) MISSED OFFSET
};

// ScriptStruct Otherlands.SecondarySkillPerkData
// 0x0040 (0x0060 - 0x0020)
struct FSecondarySkillPerkData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	class UTexture2D*                                  Icon;                                                     // 0x0050(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffId;                                                   // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SecondarySkillData
// 0x0048 (0x0068 - 0x0020)
struct FSecondarySkillData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	class UTexture2D*                                  Icon;                                                     // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkill>                       SkillType;                                                // 0x0040(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0041(0x0007) MISSED OFFSET
	struct FName                                       SecondarySkillCategoryId;                                 // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                DisplayIndex;                                             // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0054(0x0004) MISSED OFFSET
	struct FName                                       PerLevelBuffId;                                           // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ExpectedUsesPerLevel;                                     // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                NumAdditiveDropTypes;                                     // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.PerkRowData
// 0x0030 (0x0050 - 0x0020)
struct FPerkRowData : public FTableRowSequencedBase
{
	int                                                Index;                                                    // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
	struct FText                                       DisplayName;                                              // 0x0028(0x0018) (Edit, DisableEditOnInstance)
	int                                                RequiredPoints;                                           // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ColumnCount;                                              // 0x0044(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxPerks;                                                 // 0x0048(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxArchetypeCount;                                        // 0x004C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.PerkBaseData
// 0x0090 (0x00B0 - 0x0020)
struct FPerkBaseData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<ECharacterArchetype>                   Archetype;                                                // 0x0050(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0051(0x0007) MISSED OFFSET
	struct FName                                       PerkRowId;                                                // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0060(0x0004) MISSED OFFSET
	int                                                PerkColumnOrder;                                          // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x0068(0x0008) MISSED OFFSET
	class UTexture2D*                                  Icon;                                                     // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffId;                                                   // 0x0078(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlayerAbilityId[0x5];                                     // 0x0080(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxRanks;                                                 // 0x00A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x00AC(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.HairCustomizationBaseData
// 0x0040 (0x0060 - 0x0020)
struct FHairCustomizationBaseData : public FTableRowSequencedBase
{
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class USkeletalMesh*                               SkullMesh;                                                // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               FaceMesh;                                                 // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               BackMesh;                                                 // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               SideburnsMesh;                                            // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UTexture2D*                                  Icon;                                                     // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FAscensionUnlock                            AscensionRequired;                                        // 0x0050(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Otherlands.HairColorBaseData
// 0x00C0 (0x00E0 - 0x0020)
struct FHairColorBaseData : public FTableRowSequencedBase
{
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class UMaterialInstance*                           HairMaterial;                                             // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                HairColor;                                                // 0x0030(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                AnisotropicColor;                                         // 0x0040(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
	float                                              AnisoSpecScalar;                                          // 0x0050(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Anisotropic;                                              // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Contrast;                                                 // 0x0058(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Opacity;                                                  // 0x005C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Roughness;                                                // 0x0060(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              StandardSpec;                                             // 0x0064(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                AlbedoColor;                                              // 0x0068(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                FactionTint;                                              // 0x0078(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                SubsurfaceColor;                                          // 0x0088(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
	float                                              EmissiveInnerFresnelPower;                                // 0x0098(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EmissiveInnerFresnelBlendValue;                           // 0x009C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EmissiveInnerFresnelLerp;                                 // 0x00A0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EmissiveInnerFresnelIntensity;                            // 0x00A4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UVPanningScale;                                           // 0x00A8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              XPanning;                                                 // 0x00AC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              YPanning;                                                 // 0x00B0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ScrollingScalar;                                          // 0x00B4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                GlowEmissive;                                             // 0x00B8(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
	float                                              TipsScalar;                                               // 0x00C8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x00CC(0x0004) MISSED OFFSET
	struct FAscensionUnlock                            AscensionRequired;                                        // 0x00D0(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Otherlands.FacialHairCustomizationBaseData
// 0x0038 (0x0058 - 0x0020)
struct FFacialHairCustomizationBaseData : public FTableRowSequencedBase
{
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class USkeletalMesh*                               FacialShadowMesh;                                         // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               FacialHairMesh;                                           // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               FacialHairAlternateMesh;                                  // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UTexture2D*                                  Icon;                                                     // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FAscensionUnlock                            AscensionRequired;                                        // 0x0048(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Otherlands.CharacterStatData
// 0x0090
struct FCharacterStatData
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
	struct FText                                       DisplayName;                                              // 0x0008(0x0018) (BlueprintVisible, BlueprintReadOnly)
	TEnumAsByte<ECharacterStatDisplayType>             DisplayEnum;                                              // 0x0020(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x37];                                      // 0x0021(0x0037) MISSED OFFSET
	class UCurveFloat*                                 PveOverrideConversionCurve;                               // 0x0058(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UCurveFloat*                                 PvpOverrideConversionCurve;                               // 0x0060(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x28];                                      // 0x0068(0x0028) MISSED OFFSET
};

// ScriptStruct Otherlands.AscensionPerkTierData
// 0x0020 (0x0040 - 0x0020)
struct FAscensionPerkTierData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                SpentPointsToUnlock;                                      // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.AscensionPerkLoadoutSlotData
// 0x0038 (0x0058 - 0x0020)
struct FAscensionPerkLoadoutSlotData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                DisplayOrder;                                             // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0054(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.AscensionPerkRank
// 0x0020
struct FAscensionPerkRank
{
	int                                                Cost;                                                     // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FName                                       AbilityId;                                                // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       StarterItemId;                                            // 0x0010(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                StarterItemCount;                                         // 0x0018(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AscensionFeatures;                                        // 0x001C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.AscensionPerkBaseData
// 0x0098 (0x00B8 - 0x0020)
struct FAscensionPerkBaseData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0038(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.AscensionPerkBaseData.Icon
	struct FText                                       Tooltip;                                                  // 0x0060(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<EAscensionPerkCategory>                PerkCategory;                                             // 0x0078(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EAscensionPerkDisplayType>             PerkDisplayType;                                          // 0x0079(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x007A(0x0002) MISSED OFFSET
	int                                                DisplayOrder;                                             // 0x007C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AscensionPerkTierIdUnlocked;                              // 0x0080(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AscensionPerkLoadoutSlotId;                               // 0x0088(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffId;                                                   // 0x0090(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       StarterBuffId;                                            // 0x0098(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCosmeticUnlock;                                          // 0x00A0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRecipeUnlock;                                            // 0x00A1(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x6];                                       // 0x00A2(0x0006) MISSED OFFSET
	TArray<struct FAscensionPerkRank>                  Ranks;                                                    // 0x00A8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.AscensionUnlockSet
// 0x0010
struct FAscensionUnlockSet
{
	TArray<struct FAscensionUnlock>                    Unlocks;                                                  // 0x0000(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.ChatSystemMessage
// 0x0050
struct FChatSystemMessage
{
	TEnumAsByte<ESystemMessage_CodeMap>                MessageTypeCodeMap;                                       // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FName                                       MessageType;                                              // 0x0008(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FString>                             MessageStrings;                                           // 0x0010(0x0010) (BlueprintVisible, ZeroConstructor)
	TArray<int>                                        MessageInts;                                              // 0x0020(0x0010) (BlueprintVisible, ZeroConstructor)
	TArray<float>                                      MessageFloats;                                            // 0x0030(0x0010) (BlueprintVisible, ZeroConstructor)
	TArray<struct FName>                               MessageNames;                                             // 0x0040(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.EventLogEntryParameter
// 0x0028
struct FEventLogEntryParameter
{
	int                                                IntegerParam;                                             // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              FloatParam;                                               // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FText                                       TextParam;                                                // 0x0008(0x0018) (BlueprintVisible, BlueprintReadOnly)
	struct FName                                       NameParam;                                                // 0x0020(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.EventLogEntry
// 0x00E8
struct FEventLogEntry
{
	struct FName                                       EventLogId;                                               // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FEventLogEntryParameter                     Parameters[0x5];                                          // 0x0008(0x0028)
	struct FDateTime                                   Time;                                                     // 0x00D0(0x0008) (BlueprintVisible, BlueprintReadOnly)
	struct FName                                       ViewPermissionIdOverride;                                 // 0x00D8(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bChatAnnouncementOverride;                                // 0x00E0(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bPersistOverride;                                         // 0x00E1(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x00E2(0x0002) MISSED OFFSET
	int                                                ParameterCount;                                           // 0x00E4(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ChooseItemParam
// 0x0018
struct FChooseItemParam
{
	TEnumAsByte<EChooseItemActionType>                 ActionType;                                               // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	int                                                ItemIdx;                                                  // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EHeldItemLocation>                     Location;                                                 // 0x0008(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EChooseItemToggleMode>                 ToggleMode;                                               // 0x0009(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x000A(0x0006) MISSED OFFSET
	class UObject*                                     TargetContainer;                                          // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.LimitedPlaceableCount
// 0x0010
struct FLimitedPlaceableCount
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                Count;                                                    // 0x0008(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ClanInvite
// 0x0030
struct FClanInvite
{
	TWeakObjectPtr<class AGamePlayerController>        Player;                                                   // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              TimeRemaining;                                            // 0x0008(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	struct FString                                     CharacterId;                                              // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     UniqueSaveId;                                             // 0x0020(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Otherlands.ClanData
// 0x0028
struct FClanData
{
	int                                                FactionId;                                                // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FString                                     ID;                                                       // 0x0008(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     Name;                                                     // 0x0018(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Otherlands.ClanMember
// 0x0028
struct FClanMember
{
	struct FString                                     CharacterId;                                              // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     UniqueSaveId;                                             // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	int                                                PermissionLevelIndex;                                     // 0x0020(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.StructurePermissions
// 0x0070
struct FStructurePermissions
{
	int                                                FactionId;                                                // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FString                                     OwnerId;                                                  // 0x0008(0x0010) (BlueprintVisible, ZeroConstructor)
	struct FString                                     ClanId;                                                   // 0x0018(0x0010) (BlueprintVisible, ZeroConstructor)
	struct FString                                     OwnerName;                                                // 0x0028(0x0010) (BlueprintVisible, ZeroConstructor)
	struct FString                                     ClanName;                                                 // 0x0038(0x0010) (BlueprintVisible, ZeroConstructor)
	TEnumAsByte<EGroupType_CodeMap>                    GroupType;                                                // 0x0048(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0049(0x0007) MISSED OFFSET
	TArray<struct FName>                               PermissionIds;                                            // 0x0050(0x0010) (BlueprintVisible, ZeroConstructor)
	TArray<struct FName>                               PermissionGroupLevelIds;                                  // 0x0060(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.ContextMenuActionData
// 0x0028
struct FContextMenuActionData
{
	unsigned char                                      UnknownData00[0xC];                                       // 0x0000(0x000C) MISSED OFFSET
	bool                                               bClickToConfirm;                                          // 0x000C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
	struct FText                                       MenuItemText;                                             // 0x0010(0x0018) (Edit, BlueprintVisible)
};

// ScriptStruct Otherlands.ControlPointBuff
// 0x0018
struct FControlPointBuff
{
	TEnumAsByte<EControlPointBuffTiming>               Timing;                                                   // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FName                                       BuffId;                                                   // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemReagentData
// 0x0010
struct FItemReagentData
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                Count;                                                    // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.RecipeData
// 0x0030
struct FRecipeData
{
	struct FName                                       RecipeId;                                                 // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FItemReagentData>                    Reagents;                                                 // 0x0008(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	unsigned char                                      UnknownData00[0x18];                                      // 0x0018(0x0018) MISSED OFFSET
};

// ScriptStruct Otherlands.QueuedCraft
// 0x0050
struct FQueuedCraft
{
	bool                                               bStealing;                                                // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bCraftPrototype;                                          // 0x0001(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0002(0x0006) MISSED OFFSET
	struct FRecipeData                                 Target;                                                   // 0x0008(0x0030) (BlueprintVisible, BlueprintReadOnly)
	struct FName                                       CraftSkillTreeId;                                         // 0x0038(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                CraftCount;                                               // 0x0040(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class UCraftComponent>              StationCraftComponent;                                    // 0x0044(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemAffixInstance
// 0x0048
struct FItemAffixInstance
{
	struct FName                                       ItemAffixId[0x6];                                         // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              AffixValue[0x6];                                          // 0x0030(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CraftRecipiePrototype
// 0x0058
struct FCraftRecipiePrototype
{
	struct FName                                       RecipeId;                                                 // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FItemAffixInstance                          AffixInstance;                                            // 0x0008(0x0048)
	bool                                               bCrit;                                                    // 0x0050(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0051(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.CraftSkillTreeFolderData
// 0x0050 (0x0070 - 0x0020)
struct FCraftSkillTreeFolderData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FName                                       CraftSkillTreeCategoryId;                                 // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                DisplayIndex;                                             // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	unsigned char                                      UnknownData01[0x28];                                      // 0x0044(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.CraftSkillTreeFolderData.Icon
};

// ScriptStruct Otherlands.CraftSkillTreeData
// 0x0078 (0x0098 - 0x0020)
struct FCraftSkillTreeData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0038(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.CraftSkillTreeData.Icon
	class UClass*                                      CustomSkillTreeWidgetClass;                               // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECraftSkillTreeCategory>               CraftSkillTreeCategory;                                   // 0x0068(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0069(0x0007) MISSED OFFSET
	struct FName                                       CraftSkillTreeFolderId;                                   // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FText                                       DisplayStationRequired;                                   // 0x0078(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                DisplayIndex;                                             // 0x0090(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECraftSkillUpLocation>                 SkillUpLocation;                                          // 0x0094(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHiddenTree;                                              // 0x0095(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHideIfEmpty;                                             // 0x0096(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1];                                       // 0x0097(0x0001) MISSED OFFSET
};

// ScriptStruct Otherlands.CraftSkillTreeCategoryData
// 0x0070 (0x0090 - 0x0020)
struct FCraftSkillTreeCategoryData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                DisplayIndex;                                             // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	unsigned char                                      UnknownData01[0x28];                                      // 0x003C(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.CraftSkillTreeCategoryData.Icon
	unsigned char                                      UnknownData02[0x28];                                      // 0x0068(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.CraftSkillTreeCategoryData.SelectedIcon
};

// ScriptStruct Otherlands.CraftResearchTierData
// 0x0018
struct FCraftResearchTierData
{
	TArray<struct FName>                               TierResearchIds;                                          // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       MilestoneResearchId;                                      // 0x0010(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ResearchUnlockData
// 0x0058
struct FResearchUnlockData
{
	struct FText                                       DisplayName;                                              // 0x0000(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       TooltipText;                                              // 0x0018(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0030(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ResearchUnlockData.Icon
};

// ScriptStruct Otherlands.CraftResearchData
// 0x00A0 (0x00C0 - 0x0020)
struct FCraftResearchData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<ETechTreeType>                         TechTreeType;                                             // 0x0050(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0051(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData01[0x28];                                      // 0x0051(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.CraftResearchData.Icon
	int                                                Tier;                                                     // 0x0080(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsMilestone;                                             // 0x0084(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0085(0x0003) MISSED OFFSET
	int                                                RequiredXP;                                               // 0x0088(0x0004) (Edit, EditFixedSize, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                GridX;                                                    // 0x008C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                StashSlots;                                               // 0x0090(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                StableSlots;                                              // 0x0094(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffId;                                                   // 0x0098(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BuffStackCount;                                           // 0x00A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RevEngParentMultiplier;                                   // 0x00A4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FResearchUnlockData>                 ExtraUnlockData;                                          // 0x00A8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	float                                              ResearchScoreValue;                                       // 0x00B8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x00BC(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.CraftRecipeData
// 0x0130 (0x0150 - 0x0020)
struct FCraftRecipeData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                CraftTypeFlags;                                           // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FName                                       CraftSkillTreeTypeId;                                     // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkill>                       SecondarySkillType;                                       // 0x0048(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0049(0x0003) MISSED OFFSET
	int                                                CraftLevel;                                               // 0x004C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanBePrototyped;                                         // 0x0050(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0051(0x0007) MISSED OFFSET
	TArray<struct FItemReagentData>                    Reagents;                                                 // 0x0058(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       ItemIdTool;                                               // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemResourceType>                     ItemResourceType;                                         // 0x0070(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0071(0x0003) MISSED OFFSET
	float                                              ItemResourceAmount;                                       // 0x0074(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CraftTime;                                                // 0x0078(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRepeatable;                                              // 0x007C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanUseWarehouse;                                         // 0x007D(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x2];                                       // 0x007E(0x0002) MISSED OFFSET
	struct FName                                       CraftDifficultyTierId;                                    // 0x0080(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemIdResult;                                             // 0x0088(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ResultCount;                                              // 0x0090(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x0094(0x0004) MISSED OFFSET
	struct FName                                       ResultItemAffixApplicationId;                             // 0x0098(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemIdBroken;                                             // 0x00A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BrokenCount;                                              // 0x00A8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x4];                                       // 0x00AC(0x0004) MISSED OFFSET
	struct FName                                       BrokenItemAffixApplicationId;                             // 0x00B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemIdCrit;                                               // 0x00B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                CritCount;                                                // 0x00C0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x4];                                       // 0x00C4(0x0004) MISSED OFFSET
	struct FName                                       CritItemAffixApplicationId;                               // 0x00C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CraftResearchIdResult;                                    // 0x00D0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlayerXP;                                                 // 0x00D8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SkillUseCredit;                                           // 0x00DC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CraftRecipeIdSkillTreeRequired;                           // 0x00E0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CraftResearchIdRequired;                                  // 0x00E8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SecondarySkillPerkSetIdRequired;                          // 0x00F0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SecondarySkillPerkIdRequired;                             // 0x00F8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PerkBaseIdTalentRequired;                                 // 0x0100(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                TalentPointsRequired;                                     // 0x0108(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData08[0x4];                                       // 0x010C(0x0004) MISSED OFFSET
	struct FName                                       BuffIdRequired;                                           // 0x0110(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FAscensionUnlock                            AscensionRequired;                                        // 0x0118(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	float                                              ReputationTier;                                           // 0x0128(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanBeStolen;                                             // 0x012C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bMustFind;                                                // 0x012D(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHideWhileLocked;                                         // 0x012E(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData09[0x1];                                       // 0x012F(0x0001) MISSED OFFSET
	class USoundCue*                                   LoopingSound;                                             // 0x0130(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   CompleteSound;                                            // 0x0138(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   CompleteBreakSound;                                       // 0x0140(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   CompleteCritSound;                                        // 0x0148(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CraftDifficultyTierData
// 0x0058 (0x0078 - 0x0020)
struct FCraftDifficultyTierData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	class UCurveFloat*                                 CritChanceCurve;                                          // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 BreakChanceCurve;                                         // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                SkilledXp;                                                // 0x0048(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MasteryXp;                                                // 0x004C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              OverflowRatio;                                            // 0x0050(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              BaseXp;                                                   // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              BreakXpMultiplier;                                        // 0x0058(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CritXpMultiplier;                                         // 0x005C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LearnXpMultiplier;                                        // 0x0060(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              StealXpMultiplier;                                        // 0x0064(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              StealTierMultiplier;                                      // 0x0068(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SecondaryBreakXpMultiplier;                               // 0x006C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SecondaryCritXpMultiplier;                                // 0x0070(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SecondaryStealXpMultiplier;                               // 0x0074(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureAbilityData
// 0x00A8 (0x0500 - 0x0458)
struct FCreatureAbilityData : public FAbilityData
{
	class UBehaviorTree*                               AbilityBehaviorTree;                                      // 0x0458(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitDamageScalar;                                         // 0x0460(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamageScalar;                                        // 0x0464(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                ActionMontage;                                            // 0x0468(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                WindupMontage;                                            // 0x0470(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WindupPlayRateScalar;                                     // 0x0478(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x047C(0x0004) MISSED OFFSET
	class UAnimMontage*                                ChargeLoopMontage;                                        // 0x0480(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ChargeLoopPlayRateScalar;                                 // 0x0488(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x048C(0x0004) MISSED OFFSET
	class UAnimMontage*                                FemaleMountRiderActionMontage;                            // 0x0490(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleMountRiderActionMontage;                              // 0x0498(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleMountRiderWindupMontage;                            // 0x04A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleMountRiderWindupMontage;                              // 0x04A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleMountRiderChargeMontage;                            // 0x04B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleMountRiderChargeMontage;                              // 0x04B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AttackTimeMin;                                            // 0x04C0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AttackTimeMax;                                            // 0x04C4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AbilityTargetFlags;                                       // 0x04C8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ChargeDistance;                                           // 0x04CC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FollowThroughDistance;                                    // 0x04D0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CloseGapDistance;                                         // 0x04D4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPreventMovement;                                         // 0x04D8(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPreventTargetChange;                                     // 0x04D9(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSkipFlankWhileEngaging;                                  // 0x04DA(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFaceTargetWhileCasting;                                  // 0x04DB(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFlyingRootMotion;                                        // 0x04DC(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bOverrideEngagement;                                      // 0x04DD(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x2];                                       // 0x04DE(0x0002) MISSED OFFSET
	float                                              EngagementOffsetRatio;                                    // 0x04E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRequireLineOfSight;                                      // 0x04E4(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x04E5(0x0003) MISSED OFFSET
	float                                              RequiredFacing;                                           // 0x04E8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x04EC(0x0004) MISSED OFFSET
	class UClass*                                      AbilityClass;                                             // 0x04F0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      MountAbilityClass;                                        // 0x04F8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpawnPointSettings
// 0x0058
struct FSpawnPointSettings
{
	float                                              ZRange;                                                   // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AddedNavRange;                                            // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Variation;                                                // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AcceptableAngle;                                          // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bAssumeGroundPoint;                                       // 0x0010(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bPreTrace;                                                // 0x0011(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bNavProjection;                                           // 0x0012(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0013(0x0001) MISSED OFFSET
	int                                                AvoidFlags;                                               // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bForceSuccess;                                            // 0x0018(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bFaceInterestPoint;                                       // 0x0019(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x001A(0x0002) MISSED OFFSET
	struct FVector                                     InterestPoint;                                            // 0x001C(0x000C) (Edit, BlueprintVisible, IsPlainOldData)
	struct FNavAgentProperties                         NavAgentProps;                                            // 0x0028(0x0030) (Edit, BlueprintVisible)
};

// ScriptStruct Otherlands.SpawnPointQueueSettings
// 0x0068
struct FSpawnPointQueueSettings
{
	float                                              SpawnPointRadius;                                         // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MinimumPoints;                                            // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaximumPoints;                                            // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	struct FSpawnPointSettings                         SpawnPointSettings;                                       // 0x0010(0x0058) (Edit, BlueprintVisible)
};

// ScriptStruct Otherlands.TempoStateSpawnData
// 0x0020
struct FTempoStateSpawnData
{
	TEnumAsByte<ETempoTargetState>                     TempoState;                                               // 0x0000(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESpawnTimeCycleType>                   SpawnTime;                                                // 0x0001(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESpawnSpiritRealm>                     SpawnRealm;                                               // 0x0002(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x0003(0x0005) MISSED OFFSET
	struct FName                                       SpawnBaseId;                                              // 0x0008(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              InactiveDespawnTime;                                      // 0x0010(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bSpawnOnPlayer;                                           // 0x0014(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
	float                                              MinimumDistance;                                          // 0x0018(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MaximumDistance;                                          // 0x001C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.TempoChannelSpawnData
// 0x0028
struct FTempoChannelSpawnData
{
	struct FName                                       TempoChannelId;                                           // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	TArray<struct FTempoStateSpawnData>                States;                                                   // 0x0008(0x0010) (Edit, ZeroConstructor)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0018(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.BuffEffectData
// 0x0010
struct FBuffEffectData
{
	struct FName                                       BuffId;                                                   // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                StackCount;                                               // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ApplyChance;                                              // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.PayloadData
// 0x0270 (0x0290 - 0x0020)
struct FPayloadData : public FTableRowSequencedBase
{
	struct FName                                       ImpactEffectKitId;                                        // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0028(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.PayloadData.StaticMesh
	unsigned char                                      UnknownData01[0xA0];                                      // 0x0050(0x00A0) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.PayloadData.TracerEffect
	unsigned char                                      UnknownData02[0x28];                                      // 0x00F0(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.PayloadData.Sound
	float                                              KnockbackRadius;                                          // 0x0118(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              KnockbackPower;                                           // 0x011C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              KnockbackAngle;                                           // 0x0120(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x0124(0x0004) MISSED OFFSET
	struct FName                                       ImpactCreatureAbilityId;                                  // 0x0128(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ImpactPlayerAbilityId;                                    // 0x0130(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ImpactPlaceableItemId;                                    // 0x0138(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ImpactNoiseLevel;                                         // 0x0140(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSpawnPlaceableOnPenetration;                             // 0x0144(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSpawnPlaceableOnGround;                                  // 0x0145(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x2];                                       // 0x0146(0x0002) MISSED OFFSET
	TArray<struct FBuffEffectData>                     TargetBuff;                                               // 0x0148(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FStatEffectData>                     InstantStat;                                              // 0x0158(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       ItemAffectDurabilityId;                                   // 0x0168(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ItemAffectDurabilityScalar;                               // 0x0170(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPenetrates;                                              // 0x0174(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x3];                                       // 0x0175(0x0003) MISSED OFFSET
	struct FGeneralFXData                              TargetFX[0x3];                                            // 0x0178(0x0048) (Edit, DisableEditOnInstance)
	class UClass*                                      CameraShakeClass;                                         // 0x0250(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraShakeInnerRadius;                                   // 0x0258(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraShakeOuterRadius;                                   // 0x025C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraShakeFalloff;                                       // 0x0260(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              VisualImportance;                                         // 0x0264(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxHealth;                                                // 0x0268(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           DamageType;                                               // 0x026C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x3];                                       // 0x026D(0x0003) MISSED OFFSET
	float                                              TrueDamagePercent;                                        // 0x0270(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitDamage;                                               // 0x0274(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamage;                                              // 0x0278(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              BaseLevel;                                                // 0x027C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x10];                                      // 0x0280(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.PermissionGroupLevelData
// 0x0070 (0x0090 - 0x0020)
struct FPermissionGroupLevelData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FName                                       PermissionGroupId;                                        // 0x0050(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RequiredReputation;                                       // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                RequiredLadderPosition;                                   // 0x005C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MinimumTimePlayed;                                        // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0064(0x0004) MISSED OFFSET
	struct FName                                       BuffId;                                                   // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTreatAsHostile;                                          // 0x0070(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0071(0x0003) MISSED OFFSET
	float                                              HostileActionRepScalar;                                   // 0x0074(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MinimumOutcastVoteCount;                                  // 0x0078(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UseScoreReplenishPerHour;                                 // 0x007C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AllowedUseScore;                                          // 0x0080(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaximumUseScore;                                          // 0x0084(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              VoteScore;                                                // 0x0088(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x008C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PermissionGroupData
// 0x0038 (0x0058 - 0x0020)
struct FPermissionGroupData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<EGroupType_CodeMap>                    GroupTypeCodeMap;                                         // 0x0050(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0051(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.PermissionData
// 0x0050 (0x0070 - 0x0020)
struct FPermissionData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<EPermission_CodeMap>                   PermissionCodeMap;                                        // 0x0050(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsEditable;                                              // 0x0051(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHostileHasPermission;                                    // 0x0052(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bOutcastHasPermission;                                    // 0x0053(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0054(0x0004) MISSED OFFSET
	struct FName                                       PermissionGroupLevelIdFactionUnlocked;                    // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PermissionGroupLevelIdClanUnlocked;                       // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PermissionGroupLevelIdPersonalUnlocked;                   // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.FactionStrengthEffectData
// 0x0038 (0x0058 - 0x0020)
struct FFactionStrengthEffectData : public FTableRowSequencedBase
{
	bool                                               bUseValue;                                                // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	float                                              MinimumPopulation;                                        // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaximumPopulation;                                        // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUseDelta;                                                // 0x002C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x002D(0x0003) MISSED OFFSET
	float                                              MinimumDeltaPopulation;                                   // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaximumDeltaPopulation;                                   // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AllMembersBuffId;                                         // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AllMembersStackCount;                                     // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	struct FName                                       NewMembersBuffId;                                         // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                NewMembersStackCount;                                     // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x0054(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.FactionReputationEventData
// 0x0018 (0x0038 - 0x0020)
struct FFactionReputationEventData : public FTableRowSequencedBase
{
	float                                              Delta;                                                    // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsScaled;                                                // 0x0024(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
	class UCurveFloat*                                 ScalarCurve;                                              // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EReputationEvent_CodeMap>              CodeMap;                                                  // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0031(0x0003) MISSED OFFSET
	float                                              BountyScalar;                                             // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.FactionData
// 0x0030 (0x0050 - 0x0020)
struct FFactionData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                IntegerId;                                                // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                FactionColor;                                             // 0x003C(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.FactionScoreDisplay
// 0x0020
struct FFactionScoreDisplay
{
	float                                              Scalar;                                                   // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              Offset;                                                   // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       ScoreParamName;                                           // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       WinParamName;                                             // 0x0010(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       GlowParamName;                                            // 0x0018(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.FactionBaseWispSettings
// 0x0020
struct FFactionBaseWispSettings
{
	float                                              MaxSoulCountToSpawnWisps;                                 // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MaxWispSpawnCount;                                        // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              IntervalToSpawnWisps;                                     // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              AbsMinSoulCountToSpawnWisps;                              // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MaxSpiritLossPerReckoningScalar;                          // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	struct FTimespan                                   SpiritLostShieldResetTime;                                // 0x0018(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Otherlands.HighlightsOptions
// 0x000C
struct FHighlightsOptions
{
	EHighlight                                         Highlight;                                                // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	EGfeSDKHighlightType                               Type;                                                     // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0002(0x0002) MISSED OFFSET
	float                                              StartDelta;                                               // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              EndDelta;                                                 // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ResourceSpawnStateHandle
// 0x0010
struct FResourceSpawnStateHandle
{
	class AResourceSpawnManager*                       SpawnManager;                                             // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                StateIndex;                                               // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.GroupMemberData
// 0x0020
struct FGroupMemberData
{
	struct FString                                     CharacterId;                                              // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Otherlands.ResourceSpawnStateData
// 0x0028
struct FResourceSpawnStateData
{
	int                                                NumClaimedInstances;                                      // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                MinClaimedIndex;                                          // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	class UResourceISMC*                               ResourceComp;                                             // 0x0008(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FString                                     ResourceSafeName;                                         // 0x0010(0x0010) (ZeroConstructor)
	class UClass*                                      ResourceClass;                                            // 0x0020(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ResourceSyncPacket
// 0x0058
struct FResourceSyncPacket
{
	struct FResourceSpawnStateHandle                   Handle;                                                   // 0x0000(0x0010)
	struct FResourceSpawnStateData                     Data;                                                     // 0x0010(0x0028)
	TArray<unsigned char>                              DespawnedBits;                                            // 0x0038(0x0010) (ZeroConstructor)
	TArray<unsigned char>                              ClaimedBits;                                              // 0x0048(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.FactionMember
// 0x0048
struct FFactionMember
{
	struct FString                                     UniqueSaveId;                                             // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     CharacterId;                                              // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0020(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	bool                                               bOnline;                                                  // 0x0030(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0031(0x0003) MISSED OFFSET
	int                                                LastOnlineInHours;                                        // 0x0034(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              FactionReputation;                                        // 0x0038(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                LadderPosition;                                           // 0x003C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bIsOutcast;                                               // 0x0040(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0041(0x0003) MISSED OFFSET
	float                                              FactionUseRatio;                                          // 0x0044(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ClanMemberData
// 0x0030
struct FClanMemberData
{
	struct FString                                     CharacterId;                                              // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0010(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FName                                       PermissionLevel;                                          // 0x0020(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bOnline;                                                  // 0x0028(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0029(0x0003) MISSED OFFSET
	int                                                LastOnlineInHours;                                        // 0x002C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerReportData
// 0x0060
struct FPlayerReportData
{
	struct FString                                     SourceUniqueSaveId;                                       // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     SourceCharacterName;                                      // 0x0010(0x0010) (ZeroConstructor)
	struct FString                                     ReportedUniqueSaveId;                                     // 0x0020(0x0010) (ZeroConstructor)
	struct FString                                     ReportedCharacterName;                                    // 0x0030(0x0010) (ZeroConstructor)
	struct FDateTime                                   ReportTime;                                               // 0x0040(0x0008)
	struct FString                                     ReasonMessage;                                            // 0x0048(0x0010) (ZeroConstructor)
	TEnumAsByte<EPlayerReportReason>                   ReasonType;                                               // 0x0058(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0059(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.GameplayBuff
// 0x0010
struct FGameplayBuff
{
	struct FName                                       BuffId;                                                   // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PayloadStack
// 0x0018
struct FPayloadStack
{
	struct FName                                       PayloadIds[0x3];                                          // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CombatantHitData
// 0x0058
struct FCombatantHitData
{
	TWeakObjectPtr<class UPrimitiveComponent>          HitComponent;                                             // 0x0000(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                HitItem;                                                  // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     Origin;                                                   // 0x000C(0x000C) (IsPlainOldData)
	struct FVector                                     ImpactPoint;                                              // 0x0018(0x000C) (IsPlainOldData)
	struct FVector                                     ImpactNormal;                                             // 0x0024(0x000C) (IsPlainOldData)
	struct FVector                                     BoneOffset;                                               // 0x0030(0x000C) (IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FName                                       BoneName;                                                 // 0x0040(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              Distance;                                                 // 0x0048(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bPenetrating;                                             // 0x004C(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bStartPenetrating;                                        // 0x004D(0x0001) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EPhysicalSurface>                      SurfaceType;                                              // 0x004E(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x1];                                       // 0x004F(0x0001) MISSED OFFSET
	float                                              OffBy;                                                    // 0x0050(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0054(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PlayerCharacterProperties
// 0x0060
struct FPlayerCharacterProperties
{
	struct FString                                     CharacterId;                                              // 0x0000(0x0010) (BlueprintVisible, ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0010(0x0010) (BlueprintVisible, ZeroConstructor)
	int                                                FactionId;                                                // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                Level;                                                    // 0x0024(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0028(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	struct FName                                       HairId;                                                   // 0x0030(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       FacialHairId;                                             // 0x0038(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       HairColorId;                                              // 0x0040(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       SkinColorId;                                              // 0x0048(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FName>                               PaperdollItemIds;                                         // 0x0050(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.ZoneData
// 0x00C8 (0x00E8 - 0x0020)
struct FZoneData : public FTableRowSequencedBase
{
	struct FName                                       InternalName;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FText                                       DisplayName;                                              // 0x0028(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FName                                       ParentZoneId;                                             // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                Priority;                                                 // 0x0048(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                ZoneColorId;                                              // 0x004C(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x005C(0x0004) MISSED OFFSET
	struct FName                                       ZoneDayBuffId;                                            // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ZoneNightBuffId;                                          // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ForageLootId;                                             // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ExtractorLootId;                                          // 0x0078(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UParticleSystem*                             Particulates;                                             // 0x0080(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UParticleSystem*                             ParticulatesLow;                                          // 0x0088(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UParticleSystem*                             ParticulatesReplay;                                       // 0x0090(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FVector                                     WindDirection;                                            // 0x0098(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x00A4(0x0004) MISSED OFFSET
	class USoundCue*                                   MainMusicDay;                                             // 0x00A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   MainMusicNight;                                           // 0x00B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   AmbientMusicDay;                                          // 0x00B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   AmbientMusicNight;                                        // 0x00C0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmbientMusicDelay;                                        // 0x00C8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmbientMusicDelayVariation;                               // 0x00CC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   AmbientSoundDay;                                          // 0x00D0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   AmbientSoundNight;                                        // 0x00D8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bDiscoverable;                                            // 0x00E0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x00E1(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterNameValidationRules
// 0x0018
struct FCharacterNameValidationRules
{
	struct FString                                     DisallowedCharacters;                                     // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	int                                                MaximumCharacters;                                        // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MinimumCharacters;                                        // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.GoalMemoryKey
// 0x0010
struct FGoalMemoryKey
{
	struct FName                                       Name;                                                     // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	EGoalMemoryType                                    Type;                                                     // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0009(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.GoalMemoryValue
// 0x0020
struct FGoalMemoryValue
{
	struct FString                                     String;                                                   // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	int                                                Integer;                                                  // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              Float;                                                    // 0x0014(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UObject*                                     Object;                                                   // 0x0018(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.GoalMemoryEntry
// 0x0030
struct FGoalMemoryEntry
{
	struct FGoalMemoryKey                              Key;                                                      // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FGoalMemoryValue                            Value;                                                    // 0x0010(0x0020) (Edit, BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Otherlands.GoalMemoryState
// 0x0038
struct FGoalMemoryState
{
	struct FGoalMemoryEntry                            Memory;                                                   // 0x0000(0x0030) (Edit, BlueprintVisible, BlueprintReadOnly)
	EGoalMemoryCheckOperation                          CheckOp;                                                  // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.GoalData
// 0x0020 (0x0040 - 0x0020)
struct FGoalData : public FTableRowSequencedBase
{
	float                                              Priority;                                                 // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                AllowedStates;                                            // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TArray<struct FGoalMemoryState>                    DesiredResultMemory;                                      // 0x0028(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	class UClass*                                      GoalClass;                                                // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.GoalActionData
// 0x0048 (0x0068 - 0x0020)
struct FGoalActionData : public FTableRowSequencedBase
{
	class UBehaviorTree*                               ActionBehavior;                                           // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TArray<struct FName>                               RequiredTraits;                                           // 0x0028(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	float                                              Weight;                                                   // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	TArray<struct FGoalMemoryState>                    PrerequisiteMemory;                                       // 0x0040(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TArray<struct FGoalMemoryState>                    ExpectedResultMemory;                                     // 0x0050(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	class UClass*                                      GoalActionClass;                                          // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.GroupInvite
// 0x0020
struct FGroupInvite
{
	struct FString                                     CharacterId;                                              // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TWeakObjectPtr<class AGamePlayerController>        Player;                                                   // 0x0010(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              TimeRemaining;                                            // 0x0018(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.GroupMember
// 0x0018
struct FGroupMember
{
	struct FString                                     CharacterId;                                              // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	class APlayerCharacter*                            Member;                                                   // 0x0010(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemPlaceableUpgradeItemInfo
// 0x0020
struct FItemPlaceableUpgradeItemInfo
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                RequiredCount;                                            // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                CurrentCount;                                             // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                CarriedCount;                                             // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                WarehouseCount;                                           // 0x0014(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              FactionUseCost;                                           // 0x0018(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemPlaceableUpgradeInfo
// 0x0020
struct FItemPlaceableUpgradeInfo
{
	TArray<struct FItemPlaceableUpgradeItemInfo>       UpgradeItems;                                             // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FName                                       UpgradeResultItemId;                                      // 0x0010(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FName                                       CraftResearchIdUpgradeRequired;                           // 0x0018(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlacedSocketInfo
// 0x0020
struct FPlacedSocketInfo
{
	struct FName                                       SocketId;                                                 // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       SocketName;                                               // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bParent;                                                  // 0x0010(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
	TWeakObjectPtr<class UPlaceableMeshComponent>      SocketedMesh;                                             // 0x0014(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PlaceableUpgradeState
// 0x0038
struct FPlaceableUpgradeState
{
	bool                                               bValid;                                                   // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	TArray<struct FName>                               ResourceIds;                                              // 0x0008(0x0010) (ZeroConstructor)
	TArray<int>                                        ResourceCounts;                                           // 0x0018(0x0010) (ZeroConstructor)
	struct FName                                       ItemIdResult;                                             // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       CraftResearchIdRequired;                                  // 0x0030(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ArmorValues
// 0x000C
struct FArmorValues
{
	float                                              BaseArmor;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              BonusArmor;                                               // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              PlugArmor;                                                // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.RemoteItemData
// 0x0028
struct FRemoteItemData
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Durability;                                               // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              StoredResource;                                           // 0x000C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                Slot;                                                     // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x0014(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FItemAffixInstance>                  AffixInstance;                                            // 0x0018(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.ItemAffectDurabilityData
// 0x0018 (0x0038 - 0x0020)
struct FItemAffectDurabilityData : public FTableRowSequencedBase
{
	int                                                RepairTypeBitmask;                                        // 0x0020(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxTier;                                                  // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                SlotBitmask;                                              // 0x0028(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AffectValue;                                              // 0x002C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsPercent;                                               // 0x0030(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.LootRollResult
// 0x0010
struct FLootRollResult
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ItemCount;                                                // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemAffixStats
// 0x0020
struct FItemAffixStats
{
	bool                                               bValid;                                                   // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FName                                       BuffIdInventory;                                          // 0x0008(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxDurability;                                            // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ItemConsumptionScalar;                                    // 0x0014(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              WeightScalar;                                             // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemWeaponStats
// 0x000C
struct FItemWeaponStats
{
	bool                                               bValid;                                                   // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	int                                                ShotsPerBurst;                                            // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                ClipSize;                                                 // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.TooltipText
// 0x0020
struct FTooltipText
{
	ETooltipTextSize                                   Size;                                                     // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	ETooltipColor                                      Color;                                                    // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0002(0x0006) MISSED OFFSET
	struct FText                                       Text;                                                     // 0x0008(0x0018) (Edit, BlueprintVisible)
};

// ScriptStruct Otherlands.ExtraTooltip
// 0x0020
struct FExtraTooltip
{
	ETooltipType                                       Type;                                                     // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	TArray<struct FTooltipText>                        TooltipText;                                              // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	float                                              ProgressValue;                                            // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemPlaceableDefaultData
// 0x0018
struct FItemPlaceableDefaultData
{
	struct FName                                       PlugItemId;                                               // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       TargetSocket;                                             // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlugSocket;                                               // 0x0010(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemRepairData
// 0x0018 (0x0038 - 0x0020)
struct FItemRepairData : public FTableRowSequencedBase
{
	int                                                RepairTypeBitmask;                                        // 0x0020(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
	TArray<struct FItemReagentData>                    StationCost;                                              // 0x0028(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.WarehouseTypeData
// 0x0030 (0x0050 - 0x0020)
struct FWarehouseTypeData : public FTableRowSequencedBase
{
	TArray<TEnumAsByte<EItemType>>                     ItemTypes;                                                // 0x0020(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FText                                       DisplayName;                                              // 0x0030(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                OverrideOrdinal;                                          // 0x0048(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemPlaceableUpgradeData
// 0x0050 (0x0070 - 0x0020)
struct FItemPlaceableUpgradeData : public FTableRowSequencedBase
{
	struct FName                                       ItemIdResult;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CraftResearchIdRequired;                                  // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemIdReagent[0x5];                                       // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ReagentCount[0x5];                                        // 0x0058(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemPlaceableCraftStatsData
// 0x0058 (0x0078 - 0x0020)
struct FItemPlaceableCraftStatsData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TArray<struct FName>                               PlaceableSkillTreeTypeIds;                                // 0x0038(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	int                                                PlaceableCraftLevel;                                      // 0x0048(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableCraftLevelMin;                                   // 0x004C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableInitStoredSkillXP;                               // 0x0050(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableCraftBreakAdjust;                                // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableCraftCritAdjust;                                 // 0x0058(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               PlaceableCraftSelfOnly;                                   // 0x005C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               PlaceableCraftAdjustOnly;                                 // 0x005D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               PlaceableCraftIsRefinery;                                 // 0x005E(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               PlaceableCraftIsResearch;                                 // 0x005F(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableCraftXPMultiplier;                               // 0x0060(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0064(0x0004) MISSED OFFSET
	struct FName                                       PlaceableCraftItemAffixApplicationId;                     // 0x0068(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableCraftTimeScalar;                                 // 0x0070(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableCraftRecipeScalar;                               // 0x0074(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemBaseData
// 0x0288 (0x02A8 - 0x0020)
struct FItemBaseData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<EItemFamily>                           Family;                                                   // 0x0038(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemCategory>                         Category;                                                 // 0x0039(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x003A(0x0006) MISSED OFFSET
	class UClass*                                      InventoryItemClass;                                       // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemType>                             ItemType;                                                 // 0x0048(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkill>                       SecondarySkill;                                           // 0x0049(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x004A(0x0006) MISSED OFFSET
	unsigned char                                      UnknownData02[0x28];                                      // 0x004A(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemBaseData.Icon
	TEnumAsByte<EItemSoulboundType>                    SoulboundType;                                            // 0x0078(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemQuality>                          Quality;                                                  // 0x0079(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAllowAutoEquip;                                          // 0x007A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x1];                                       // 0x007B(0x0001) MISSED OFFSET
	int                                                ItemTier;                                                 // 0x007C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxStack;                                                 // 0x0080(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Weight;                                                   // 0x0084(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FText                                       FunctionText;                                             // 0x0088(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       FlavorText;                                               // 0x00A0(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FName                                       OverrideDroppedContainerItemId;                           // 0x00B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemServerUniqueId;                                       // 0x00C0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemDamageDataId;                                         // 0x00C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemHarvestDataId;                                        // 0x00D0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemDisplayDataId;                                        // 0x00D8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemAmmoDataId;                                           // 0x00E0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemEquipDataId;                                          // 0x00E8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemAffixApplicationId;                                   // 0x00F0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemPlaceableDataId;                                      // 0x00F8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemConsumableDataId;                                     // 0x0100(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemModificationId;                                       // 0x0108(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemMontageDataId;                                        // 0x0110(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemSoundDataId;                                          // 0x0118(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemImpactEffectKitId;                                    // 0x0120(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxDurability;                                            // 0x0128(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DurabilityPerSecondUsed;                                  // 0x012C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemRepairId;                                             // 0x0130(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RepairStationMultiplier;                                  // 0x0138(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x013C(0x0004) MISSED OFFSET
	struct FName                                       FieldKitItemAffectDurabilityId;                           // 0x0140(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FuelValue;                                                // 0x0148(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x014C(0x0004) MISSED OFFSET
	struct FName                                       FuelByproductItemId;                                      // 0x0150(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FuelByproductAmount;                                      // 0x0158(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemResourceType>                     ResourceStorageType;                                      // 0x015C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x3];                                       // 0x015D(0x0003) MISSED OFFSET
	float                                              WaterCapacity;                                            // 0x0160(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ResourceCapacity;                                         // 0x0164(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WaterLeakRate;                                            // 0x0168(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ResourceLeakRate;                                         // 0x016C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DecayTime;                                                // 0x0170(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x4];                                       // 0x0174(0x0004) MISSED OFFSET
	struct FName                                       DecayIntoItemId;                                          // 0x0178(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                WarehouseMaxCount;                                        // 0x0180(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ReuptationValueScalar;                                    // 0x0184(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bGiveRepForDeposit;                                       // 0x0188(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData08[0x7];                                       // 0x0189(0x0007) MISSED OFFSET
	struct FName                                       CraftResearchIdRevEng;                                    // 0x0190(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RevEngResult;                                             // 0x0198(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData09[0x4];                                       // 0x019C(0x0004) MISSED OFFSET
	struct FName                                       LootBaseIdSalvage;                                        // 0x01A0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffIdInventory;                                          // 0x01A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FactionUseScore;                                          // 0x01B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData10[0x4];                                       // 0x01B4(0x0004) MISSED OFFSET
	TMap<struct FName, float>                          CustomFloats;                                             // 0x01B8(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TMap<struct FName, int>                            CustomInts;                                               // 0x0208(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TMap<struct FName, struct FName>                   CustomIds;                                                // 0x0258(0x0050) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.ItemAffixData
// 0x0048 (0x0068 - 0x0020)
struct FItemAffixData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                AllowedGroupId;                                           // 0x0038(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AllowedTier;                                              // 0x003C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ExclusiveAffixCategoryId;                                 // 0x0040(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        CharStat;                                                 // 0x0044(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkill>                       SecondarySkill;                                           // 0x0045(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkillStat>                   SkillStat;                                                // 0x0046(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemAffixStat>                        ItemAffixStat;                                            // 0x0047(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffId;                                                   // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ValueMin;                                                 // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ValueMax;                                                 // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ValueGrainularity;                                        // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bOnlyWhenHeld;                                            // 0x005C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x005D(0x0003) MISSED OFFSET
	struct FName                                       RequiredCraftResearchId;                                  // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemAffixApplicationData
// 0x0048 (0x0068 - 0x0020)
struct FItemAffixApplicationData : public FTableRowSequencedBase
{
	float                                              Count;                                                    // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AnchorTier;                                               // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 TierCurve;                                                // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              StatRangeAdjust;                                          // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0034(0x0004) MISSED OFFSET
	struct FName                                       ImplicitItemAffixIds[0x6];                                // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemSagaVault
// 0x00F0
struct FItemSagaVault
{
	unsigned char                                      UnknownData00[0xF0];                                      // 0x0000(0x00F0) MISSED OFFSET
};

// ScriptStruct Otherlands.JrkTestConfig
// 0x0038
struct FJrkTestConfig
{
	TEnumAsByte<EJrkTest>                              JrkTest;                                                  // 0x0000(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	double                                             FalsePositiveRate;                                        // 0x0008(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             FalseNegativeRate;                                        // 0x0010(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             JrkRate;                                                  // 0x0018(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             FeatureScore;                                             // 0x0020(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             MinAccuracy;                                              // 0x0028(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             MinMCC;                                                   // 0x0030(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.JrkTestMasterConfig
// 0x0020
struct FJrkTestMasterConfig
{
	TArray<struct FJrkTestConfig>                      Config;                                                   // 0x0000(0x0010) (Edit, ZeroConstructor)
	double                                             BaseScore;                                                // 0x0010(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	double                                             MinJrkDelta;                                              // 0x0018(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.BannedPlayerData
// 0x0048
struct FBannedPlayerData
{
	struct FString                                     UniqueSaveId;                                             // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0010(0x0010) (ZeroConstructor)
	struct FString                                     Reason;                                                   // 0x0020(0x0010) (ZeroConstructor)
	struct FDateTime                                   BanTime;                                                  // 0x0030(0x0008)
	bool                                               bTemporary;                                               // 0x0038(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0039(0x0007) MISSED OFFSET
	struct FDateTime                                   BanLiftTime;                                              // 0x0040(0x0008)
};

// ScriptStruct Otherlands.RunningStats
// 0x0018
struct FRunningStats
{
	int64_t                                            Count;                                                    // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             Mean;                                                     // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             S;                                                        // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.TimedStats
// 0x0040
struct FTimedStats
{
	struct FRunningStats                               SUCCESS;                                                  // 0x0000(0x0018)
	struct FRunningStats                               DeltaSeconds;                                             // 0x0018(0x0018)
	struct FDateTime                                   LastTest;                                                 // 0x0030(0x0008)
	struct FDateTime                                   FirstTest;                                                // 0x0038(0x0008)
};

// ScriptStruct Otherlands.JrkTestStats
// 0x0008 (0x0048 - 0x0040)
struct FJrkTestStats : public FTimedStats
{
	TEnumAsByte<EJrkTest>                              JrkTest;                                                  // 0x0040(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0041(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.JrkMember
// 0x0020
struct FJrkMember
{
	struct FString                                     UniqueSaveId;                                             // 0x0000(0x0010) (ZeroConstructor)
	TArray<struct FJrkTestStats>                       TestSet;                                                  // 0x0010(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.JrkTestMaster
// 0x0010
struct FJrkTestMaster
{
	TArray<struct FJrkTestStats>                       TestSet;                                                  // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.LootBaseData
// 0x0008 (0x0028 - 0x0020)
struct FLootBaseData : public FTableRowSequencedBase
{
	struct FName                                       ParentLootBaseId;                                         // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.LootItemData
// 0x0038 (0x0058 - 0x0020)
struct FLootItemData : public FTableRowSequencedBase
{
	struct FName                                       LootBaseDataId;                                           // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EHarvestType>                          HarvestType;                                              // 0x0028(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	struct FName                                       ItemId;                                                   // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       LootIdDrop;                                               // 0x0038(0x0008) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	int                                                QualityThreshold;                                         // 0x0040(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProbabilityWeight;                                        // 0x0044(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AdditiveDropIndex;                                        // 0x0048(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DropAmount;                                               // 0x004C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DropVariation;                                            // 0x0050(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                LootConditionFlags;                                       // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.LootRollInfo
// 0x0038
struct FLootRollInfo
{
	TEnumAsByte<EHarvestType>                          HarvestType;                                              // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	int                                                QualityThreshold;                                         // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              QuantityMultiplier;                                       // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	class UObject*                                     WorldContextObject;                                       // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class APlayerCharacter*                            Caller;                                                   // 0x0018(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESpiritRealmState>                     SpiritRealmState;                                         // 0x0020(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	float                                              GlobalAdditiveDropChance;                                 // 0x0024(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<float>                                      AdditiveDropChances;                                      // 0x0028(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.StructureQuadTreeNode
// 0x0040
struct FStructureQuadTreeNode
{
	unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
	TArray<TWeakObjectPtr<class APlaceableStructure>>  Structures;                                               // 0x0010(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData01[0x20];                                      // 0x0020(0x0020) MISSED OFFSET
};

// ScriptStruct Otherlands.Highlight
// 0x0028
struct FHighlight
{
	EHighlight                                         Highlight;                                                // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FString                                     Name;                                                     // 0x0008(0x0010) (BlueprintVisible, ZeroConstructor)
	EGfeSDKHighlightType                               Type;                                                     // 0x0018(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
	float                                              StartDelta;                                               // 0x001C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              EndDelta;                                                 // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.SeasonData
// 0x0008
struct FSeasonData
{
	TEnumAsByte<ESeason>                               CurrentSeason;                                            // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	TEnumAsByte<ESeason>                               PreviousSeason;                                           // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0002(0x0002) MISSED OFFSET
	float                                              SeasonLength;                                             // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
};

// ScriptStruct Otherlands.FactionScore
// 0x0020
struct FFactionScore
{
	bool                                               bLost;                                                    // 0x0000(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	TArray<struct FName>                               KnownResearchIds;                                         // 0x0008(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient)
	float                                              ResearchScore;                                            // 0x0018(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              Progress;                                                 // 0x001C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
};

// ScriptStruct Otherlands.SpawnEventStrength
// 0x0060
struct FSpawnEventStrength
{
	float                                              ServerAgeStrength;                                        // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	TArray<float>                                      TechStrength;                                             // 0x0008(0x0010) (BlueprintVisible, ZeroConstructor)
	TArray<float>                                      ScoreStrength;                                            // 0x0018(0x0010) (BlueprintVisible, ZeroConstructor)
	TArray<float>                                      PopulationStrength;                                       // 0x0028(0x0010) (BlueprintVisible, ZeroConstructor)
	float                                              AvgTechStrength;                                          // 0x0038(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AvgScoreStrength;                                         // 0x003C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AvgPopulationStrength;                                    // 0x0040(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	TArray<float>                                      MaxLossStrength;                                          // 0x0048(0x0010) (BlueprintVisible, ZeroConstructor)
	int                                                TargetFactionId;                                          // 0x0058(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x005C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.SpawnEventDoneData
// 0x0000 (0x0010 - 0x0010)
struct FSpawnEventDoneData : public FGameEventData
{

};

// ScriptStruct Otherlands.WeatherGlobalFogData
// 0x0C30
struct FWeatherGlobalFogData
{
	float                                              Density;                                                  // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              ColorScale;                                               // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MinFog;                                                   // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MinFogRange;                                              // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              FarClip;                                                  // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              FarColorRange;                                            // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              LocalFogWeight;                                           // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
	class UTexture2D*                                  Color;                                                    // 0x0020(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UTexture2D*                                  FarColor;                                                 // 0x0028(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC00];                                     // 0x0030(0x0C00) MISSED OFFSET
};

// ScriptStruct Otherlands.WeatherMaterialScalar
// 0x0010
struct FWeatherMaterialScalar
{
	struct FName                                       ParameterName;                                            // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DefaultValue;                                             // 0x0008(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.WeatherMaterialVector
// 0x0018
struct FWeatherMaterialVector
{
	struct FName                                       ParameterName;                                            // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FLinearColor                                DefaultValue;                                             // 0x0008(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.WeatherMaterialParameters
// 0x0020
struct FWeatherMaterialParameters
{
	TArray<struct FWeatherMaterialScalar>              ScalarParameters;                                         // 0x0000(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FWeatherMaterialVector>              VectorParameters;                                         // 0x0010(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.WeatherData
// 0x0CF0 (0x0D10 - 0x0020)
struct FWeatherData : public FTableRowSequencedBase
{
	struct FName                                       InternalName;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LerpTime;                                                 // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
	class UCurveLinearColor*                           HorizonColor;                                             // 0x0030(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           HorizonBlendColor;                                        // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           ZenithColor;                                              // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 StarsIntensity;                                           // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           HeavenColor;                                              // 0x0050(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           SunLightColor;                                            // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           AmbientLightColor;                                        // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           CloudLightColor;                                          // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           CloudDarkColor;                                           // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           DistFogCloseColor;                                        // 0x0078(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           DistFogMidColor;                                          // 0x0080(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           DistFogFarColor;                                          // 0x0088(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           DistFogGroundColor;                                       // 0x0090(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 DistFogDensity;                                           // 0x0098(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           HeightFogColor;                                           // 0x00A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 HeightFogDensity;                                         // 0x00A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 HeightFogFalloff;                                         // 0x00B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveLinearColor*                           HeightFogInscatteringColor;                               // 0x00B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FWeatherGlobalFogData                       GlobalFog;                                                // 0x00C0(0x0C30) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FWeatherMaterialParameters                  MaterialParameters;                                       // 0x0CF0(0x0020) (Edit, DisableEditOnInstance)
};

// ScriptStruct Otherlands.ActorSaveData
// 0x0030
struct FActorSaveData
{
	struct FTransform                                  Transform;                                                // 0x0000(0x0030) (IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerKillRecordSave
// 0x0020
struct FPlayerKillRecordSave
{
	struct FString                                     CharacterId;                                              // 0x0000(0x0010) (BlueprintVisible, ZeroConstructor)
	int                                                KillCount;                                                // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	struct FDateTime                                   FirstKillTime;                                            // 0x0018(0x0008) (BlueprintVisible)
};

// ScriptStruct Otherlands.PlayerCooldownEntry
// 0x0010
struct FPlayerCooldownEntry
{
	struct FName                                       CooldownId;                                               // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              TimeRemaining;                                            // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EPlayerAbilitySource>                  Source;                                                   // 0x000C(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.PlayerSummonCollectionSaveData
// 0x0028
struct FPlayerSummonCollectionSaveData
{
	TArray<struct FSummonCollectionEntry>              Collection;                                               // 0x0000(0x0010) (ZeroConstructor)
	int                                                SummonIndex;                                              // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               SummonActive;                                             // 0x0014(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
	struct FVector                                     SummonLocation;                                           // 0x0018(0x000C) (IsPlainOldData)
	TEnumAsByte<EAIPetReaction>                        DefaultPetReaction;                                       // 0x0024(0x0001) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EAIPetFollow>                          DefaultPetFollow;                                         // 0x0025(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bPetShouldHarvest;                                        // 0x0026(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x1];                                       // 0x0027(0x0001) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemSaveData
// 0x00C8
struct FItemSaveData
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FString                                     CraftedBy;                                                // 0x0008(0x0010) (ZeroConstructor)
	struct FString                                     BoundOwnerId;                                             // 0x0018(0x0010) (ZeroConstructor)
	float                                              Durability;                                               // 0x0028(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x002C(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FName                                       AmmoItemId;                                               // 0x0030(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              StoredResource;                                           // 0x0038(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              DecayTimeRemaining;                                       // 0x003C(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                Slot;                                                     // 0x0040(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	struct FName                                       ItemModificationId;                                       // 0x0048(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FItemAffixInstance                          AffixInstance;                                            // 0x0050(0x0048)
	TArray<int>                                        CustomIntData;                                            // 0x0098(0x0010) (ZeroConstructor)
	TArray<float>                                      CustomFloatData;                                          // 0x00A8(0x0010) (ZeroConstructor)
	TArray<struct FName>                               CustomNameData;                                           // 0x00B8(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.InventorySaveData
// 0x0010
struct FInventorySaveData
{
	TArray<struct FItemSaveData>                       Items;                                                    // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.PlayerPerkPointsSaveData
// 0x0018
struct FPlayerPerkPointsSaveData
{
	TEnumAsByte<ECharacterArchetype>                   Archetype;                                                // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FName                                       RowId;                                                    // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                ColumnIndex;                                              // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                Points;                                                   // 0x0014(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerPerksSaveData
// 0x0018
struct FPlayerPerksSaveData
{
	int                                                SavedClassVersion;                                        // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	TArray<struct FPlayerPerkPointsSaveData>           PerkPoints;                                               // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.PlayerSecondarySkillSaveData
// 0x0010
struct FPlayerSecondarySkillSaveData
{
	struct FName                                       SkillId;                                                  // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                SkillLevel;                                               // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              SkillXP;                                                  // 0x000C(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerSecondarySkillsSaveData
// 0x0028
struct FPlayerSecondarySkillsSaveData
{
	int                                                SavedSkillVersion;                                        // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	TArray<struct FPlayerSecondarySkillSaveData>       skills;                                                   // 0x0008(0x0010) (ZeroConstructor)
	TArray<struct FName>                               SkillPerks;                                               // 0x0018(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.PlayerSkillTreeNodeSaveData
// 0x0010
struct FPlayerSkillTreeNodeSaveData
{
	struct FName                                       RecipeId;                                                 // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              SkillXP;                                                  // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      bKnown : 1;                                               // 0x000C(0x0001)
	unsigned char                                      bSkilled : 1;                                             // 0x000C(0x0001)
	unsigned char                                      bMastered : 1;                                            // 0x000C(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.PlayerSkillTreeSaveData
// 0x0030
struct FPlayerSkillTreeSaveData
{
	TArray<struct FPlayerSkillTreeNodeSaveData>        Nodes;                                                    // 0x0000(0x0010) (ZeroConstructor)
	TArray<struct FName>                               FoundRecipeIds;                                           // 0x0010(0x0010) (ZeroConstructor)
	TArray<struct FCraftRecipiePrototype>              Prototypes;                                               // 0x0020(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.TechTreeResearchSaveData
// 0x0018
struct FTechTreeResearchSaveData
{
	struct FName                                       CraftResearchId;                                          // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                ResearchIndex;                                            // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                ResearchXP;                                               // 0x000C(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              ResearchProgress;                                         // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.TechTreeSaveData
// 0x0018
struct FTechTreeSaveData
{
	TEnumAsByte<ETechTreeType>                         TechTreeType;                                             // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	TArray<struct FTechTreeResearchSaveData>           ResearchXP;                                               // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.DemolishPermissionState
// 0x0010
struct FDemolishPermissionState
{
	int                                                Count;                                                    // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FDateTime                                   StartTime;                                                // 0x0008(0x0008) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Otherlands.PlayerSaveData
// 0x0350 (0x0380 - 0x0030)
struct FPlayerSaveData : public FActorSaveData
{
	struct FString                                     UniqueSaveId;                                             // 0x0030(0x0010) (ZeroConstructor)
	struct FString                                     CharacterId;                                              // 0x0040(0x0010) (ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0050(0x0010) (ZeroConstructor)
	int                                                FactionId;                                                // 0x0060(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                InitialFactionId;                                         // 0x0064(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FString                                     ClanId;                                                   // 0x0068(0x0010) (ZeroConstructor)
	float                                              FactionUseScore;                                          // 0x0078(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              EntropyLootScore;                                         // 0x007C(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                EntropyLootRewardCount;                                   // 0x0080(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0084(0x0004) MISSED OFFSET
	struct FDateTime                                   CreateTime;                                               // 0x0088(0x0008)
	struct FDateTime                                   LastSaveTime;                                             // 0x0090(0x0008)
	float                                              TimePlayed;                                               // 0x0098(0x0004) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EGender>                               SpawnGender;                                              // 0x009C(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x009D(0x0003) MISSED OFFSET
	struct FVector                                     RespawnLocation;                                          // 0x00A0(0x000C) (IsPlainOldData)
	int                                                Level;                                                    // 0x00AC(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                XP;                                                       // 0x00B0(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              FactionReputation;                                        // 0x00B4(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bDead;                                                    // 0x00B8(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x00B9(0x0003) MISSED OFFSET
	int                                                DeathCount;                                               // 0x00BC(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FDateTime                                   LastDeathTime;                                            // 0x00C0(0x0008)
	bool                                               bNeedsCorpse;                                             // 0x00C8(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x00C9(0x0003) MISSED OFFSET
	int                                                BountyValue;                                              // 0x00CC(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                BountyClaimCount;                                         // 0x00D0(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x00D4(0x0004) MISSED OFFSET
	struct FDateTime                                   FirstBountyClaimTime;                                     // 0x00D8(0x0008)
	TArray<struct FPlayerKillRecordSave>               KillRecords;                                              // 0x00E0(0x0010) (ZeroConstructor)
	bool                                               bInBase;                                                  // 0x00F0(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bStopShowingTutorials;                                    // 0x00F1(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x2];                                       // 0x00F2(0x0002) MISSED OFFSET
	float                                              Health;                                                   // 0x00F4(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Energy;                                                   // 0x00F8(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Hydration;                                                // 0x00FC(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FName                                       ActiveSpells[0x3];                                        // 0x0100(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       HairId[0x2];                                              // 0x0118(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       FacialHairId[0x2];                                        // 0x0128(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       HairColorId[0x2];                                         // 0x0138(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       SkinColorId[0x2];                                         // 0x0148(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       SleeperPlaceableItemId;                                   // 0x0158(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<struct FName>                               TutorialsCleared;                                         // 0x0160(0x0010) (ZeroConstructor)
	TArray<struct FPlayerCooldownEntry>                SpellCooldowns;                                           // 0x0170(0x0010) (ZeroConstructor)
	TArray<struct FPlayerCooldownEntry>                ItemCooldowns;                                            // 0x0180(0x0010) (ZeroConstructor)
	TArray<struct FPlayerCooldownEntry>                GroupCooldowns;                                           // 0x0190(0x0010) (ZeroConstructor)
	TArray<struct FPlayerBuffEntry>                    Buffs;                                                    // 0x01A0(0x0010) (ZeroConstructor)
	TArray<struct FLimitedPlaceableCount>              LimitedPlaceableCounts;                                   // 0x01B0(0x0010) (ZeroConstructor)
	bool                                               bLimitedPlaceableCountsUpdated;                           // 0x01C0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x7];                                       // 0x01C1(0x0007) MISSED OFFSET
	struct FPlayerSummonCollectionSaveData             CollectionSaveData;                                       // 0x01C8(0x0028)
	struct FAscensionMatchData                         AscensionData;                                            // 0x01F0(0x0088)
	struct FInventorySaveData                          Inventory;                                                // 0x0278(0x0010)
	struct FInventorySaveData                          ActionBar;                                                // 0x0288(0x0010)
	struct FInventorySaveData                          Paperdoll;                                                // 0x0298(0x0010)
	struct FInventorySaveData                          Stash;                                                    // 0x02A8(0x0010)
	struct FInventorySaveData                          PetInventory;                                             // 0x02B8(0x0010)
	struct FPlayerPerksSaveData                        Perks;                                                    // 0x02C8(0x0018)
	struct FPlayerSecondarySkillsSaveData              SecondarySkills;                                          // 0x02E0(0x0028)
	struct FPlayerSkillTreeSaveData                    SkillTrees;                                               // 0x0308(0x0030)
	TArray<struct FName>                               VisitedZones;                                             // 0x0338(0x0010) (ZeroConstructor)
	TArray<struct FString>                             MutedCharacterIds;                                        // 0x0348(0x0010) (ZeroConstructor)
	TArray<struct FTechTreeSaveData>                   TechTrees;                                                // 0x0358(0x0010) (ZeroConstructor)
	struct FDemolishPermissionState                    DemolishPermission;                                       // 0x0368(0x0010)
	unsigned char                                      UnknownData07[0x8];                                       // 0x0378(0x0008) MISSED OFFSET
};

// ScriptStruct Otherlands.AccountSaveData
// 0x0004
struct FAccountSaveData
{
	int                                                DeleteCount;                                              // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlaceableCraftingSaveData
// 0x0030 (0x0060 - 0x0030)
struct FPlaceableCraftingSaveData : public FActorSaveData
{
	bool                                               bIsOn;                                                    // 0x0030(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0031(0x0003) MISSED OFFSET
	float                                              FuelTime;                                                 // 0x0034(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FName                                       ItemIdLastFuel;                                           // 0x0038(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<struct FName>                               RefineryQueue;                                            // 0x0040(0x0010) (ZeroConstructor)
	float                                              StoredSkillXP;                                            // 0x0050(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC];                                       // 0x0054(0x000C) MISSED OFFSET
};

// ScriptStruct Otherlands.PlaceablePlugDataSaveData
// 0x00E0
struct FPlaceablePlugDataSaveData
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       TargetSocketName;                                         // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       PlugSocketName;                                           // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              Health;                                                   // 0x0018(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
	struct FPlaceableUpgradeState                      UpgradeProgress;                                          // 0x0020(0x0038)
	struct FInventorySaveData                          Inventory;                                                // 0x0058(0x0010)
	struct FInventorySaveData                          FuelInventory;                                            // 0x0068(0x0010)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0078(0x0008) MISSED OFFSET
	struct FPlaceableCraftingSaveData                  Crafting;                                                 // 0x0080(0x0060)
};

// ScriptStruct Otherlands.PlaceableSaveData
// 0x0120 (0x0150 - 0x0030)
struct FPlaceableSaveData : public FActorSaveData
{
	struct FName                                       ItemId;                                                   // 0x0030(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                FactionId;                                                // 0x0038(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FString                                     OwnerId;                                                  // 0x0040(0x0010) (ZeroConstructor)
	struct FString                                     ClanId;                                                   // 0x0050(0x0010) (ZeroConstructor)
	float                                              Health;                                                   // 0x0060(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              StoredWater;                                              // 0x0064(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FPlaceableUpgradeState                      UpgradeProgress;                                          // 0x0068(0x0038)
	bool                                               bIsBuilding;                                              // 0x00A0(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bIsDroppedItemContainer;                                  // 0x00A1(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x00A2(0x0002) MISSED OFFSET
	float                                              ExpirationTimeRemaining;                                  // 0x00A4(0x0004) (ZeroConstructor, IsPlainOldData)
	TArray<struct FPlaceablePlugDataSaveData>          Plugs;                                                    // 0x00A8(0x0010) (ZeroConstructor)
	struct FInventorySaveData                          Inventory;                                                // 0x00B8(0x0010)
	struct FInventorySaveData                          FuelInventory;                                            // 0x00C8(0x0010)
	unsigned char                                      UnknownData02[0x8];                                       // 0x00D8(0x0008) MISSED OFFSET
	struct FPlaceableCraftingSaveData                  Crafting;                                                 // 0x00E0(0x0060)
	struct FString                                     CustomPlaceableName;                                      // 0x0140(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.VehicleSaveData
// 0x0060
struct FVehicleSaveData
{
	struct FTransform                                  Transform;                                                // 0x0000(0x0030) (IsPlainOldData)
	struct FName                                       VehicleItemId;                                            // 0x0030(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                PlacedFactionId;                                          // 0x0038(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FInventorySaveData                          Inventory;                                                // 0x0040(0x0010)
	float                                              Health;                                                   // 0x0050(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0xC];                                       // 0x0054(0x000C) MISSED OFFSET
};

// ScriptStruct Otherlands.StructureItemSaveData
// 0x0070
struct FStructureItemSaveData
{
	int                                                GridMapId;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FName                                       ItemId;                                                   // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              Health;                                                   // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bFlipped;                                                 // 0x0014(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
	TArray<struct FPlaceableSaveData>                  AttachedPlaceables;                                       // 0x0018(0x0010) (ZeroConstructor)
	TArray<struct FVehicleSaveData>                    AttachedVehicles;                                         // 0x0028(0x0010) (ZeroConstructor)
	struct FPlaceableUpgradeState                      UpgradeProgress;                                          // 0x0038(0x0038)
};

// ScriptStruct Otherlands.StructurePlugSaveData
// 0x0018 (0x0088 - 0x0070)
struct FStructurePlugSaveData : public FStructureItemSaveData
{
	struct FName                                       TargetSocketName;                                         // 0x0070(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       PlugSocketName;                                           // 0x0078(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bActivated;                                               // 0x0080(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0081(0x0003) MISSED OFFSET
	int                                                YawModifier;                                              // 0x0084(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.StructureSaveData
// 0x0138
struct FStructureSaveData
{
	struct FVector                                     Location;                                                 // 0x0000(0x000C) (IsPlainOldData)
	int                                                FactionId;                                                // 0x000C(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FString                                     OwnerId;                                                  // 0x0010(0x0010) (ZeroConstructor)
	bool                                               bDynamic;                                                 // 0x0020(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	struct FStructureGrid                              Grid;                                                     // 0x0024(0x0068)
	unsigned char                                      UnknownData01[0x4];                                       // 0x008C(0x0004) MISSED OFFSET
	struct FStructurePermissions                       Permissions;                                              // 0x0090(0x0070)
	TArray<struct FStructureItemSaveData>              Items;                                                    // 0x0100(0x0010) (ZeroConstructor)
	TArray<struct FStructurePlugSaveData>              Plugs;                                                    // 0x0110(0x0010) (ZeroConstructor)
	float                                              PylonSouls[0x4];                                          // 0x0120(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bLargeBase;                                               // 0x0130(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0131(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.WarehouseItemSaveData
// 0x0010
struct FWarehouseItemSaveData
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                ItemCount;                                                // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.FactionStrength
// 0x0040 (0x0060 - 0x0020)
struct FFactionStrength : public FFactionScore
{
	struct FTimedStats                                 Population;                                               // 0x0020(0x0040)
};

// ScriptStruct Otherlands.FactionSaveData
// 0x0108
struct FFactionSaveData
{
	int                                                FactionId;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	TArray<struct FTechTreeSaveData>                   TechTrees;                                                // 0x0008(0x0010) (ZeroConstructor)
	float                                              FactionSouls;                                             // 0x0018(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              FactionMaxSoulProgress;                                   // 0x001C(0x0004) (ZeroConstructor, IsPlainOldData)
	TArray<struct FWarehouseItemSaveData>              Warehouse;                                                // 0x0020(0x0010) (ZeroConstructor)
	TArray<struct FEventLogEntry>                      FactionLog;                                               // 0x0030(0x0010) (ZeroConstructor)
	struct FFactionStrength                            Strength;                                                 // 0x0040(0x0060)
	struct FTimedStats                                 ArpcvsStats;                                              // 0x00A0(0x0040)
	int                                                ArpcvsVersion;                                            // 0x00E0(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x00E4(0x0004) MISSED OFFSET
	struct FString                                     FactionMemo;                                              // 0x00E8(0x0010) (ZeroConstructor)
	struct FString                                     FactionMotd;                                              // 0x00F8(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ClanSaveData
// 0x00B8
struct FClanSaveData
{
	struct FClanData                                   Data;                                                     // 0x0000(0x0028)
	TArray<struct FClanMember>                         Members;                                                  // 0x0028(0x0010) (ZeroConstructor)
	TArray<struct FLimitedPlaceableCount>              LimitedPlaceableCounts;                                   // 0x0038(0x0010) (ZeroConstructor)
	struct FStructurePermissions                       ClanPermissions;                                          // 0x0048(0x0070)
};

// ScriptStruct Otherlands.ControlPointSaveData
// 0x0030
struct FControlPointSaveData
{
	struct FVector                                     Location;                                                 // 0x0000(0x000C) (IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	struct FName                                       TargetSocketName;                                         // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       PlugSocketName;                                           // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       ItemIdKey;                                                // 0x0020(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                ControllingFactionId;                                     // 0x0028(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ResourceSaveData
// 0x0018
struct FResourceSaveData
{
	class UResourceISMC*                               ResourceComp;                                             // 0x0000(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<unsigned char>                              DespawnedBits;                                            // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.PlayerCorpseSaveData
// 0x0030 (0x0060 - 0x0030)
struct FPlayerCorpseSaveData : public FActorSaveData
{
	struct FString                                     PlayerCharacterId;                                        // 0x0030(0x0010) (ZeroConstructor)
	struct FInventorySaveData                          CorpseInventory;                                          // 0x0040(0x0010)
	bool                                               bIsInspiritRealm;                                         // 0x0050(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xF];                                       // 0x0051(0x000F) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemSagaUnique
// 0x0028
struct FItemSagaUnique
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                Count;                                                    // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	struct FString                                     OwnerId;                                                  // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TWeakObjectPtr<class UObject>                      Owner;                                                    // 0x0020(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemSagaVaultSaveData
// 0x0020
struct FItemSagaVaultSaveData
{
	TArray<struct FItemSagaUnique>                     VaultIn;                                                  // 0x0000(0x0010) (ZeroConstructor)
	TArray<struct FItemSagaUnique>                     VaultOut;                                                 // 0x0010(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ObjectRecord
// 0x0018
struct FObjectRecord
{
	class UClass*                                      Class;                                                    // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<unsigned char>                              Data;                                                     // 0x0008(0x0010) (BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.OutcastState
// 0x0018
struct FOutcastState
{
	int                                                Count;                                                    // 0x0000(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              Penalty;                                                  // 0x0004(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FDateTime                                   StartTime;                                                // 0x0008(0x0008) (BlueprintVisible, BlueprintReadOnly)
	bool                                               bIsOutcast;                                               // 0x0010(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0011(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.EternalPlayerSaveData
// 0x0058
struct FEternalPlayerSaveData
{
	struct FString                                     UniqueSaveId;                                             // 0x0000(0x0010) (ZeroConstructor)
	struct FAscensionEternalData                       AscensionData;                                            // 0x0010(0x0018)
	TArray<struct FSummonCollectionPersonal>           Favorites;                                                // 0x0028(0x0010) (ZeroConstructor)
	TArray<struct FSummonCollectionId>                 Collection;                                               // 0x0038(0x0010) (ZeroConstructor)
	TArray<struct FOutcastState>                       Outcast;                                                  // 0x0048(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.PendingSagaAward
// 0x0018
struct FPendingSagaAward
{
	struct FString                                     UniqueSaveId;                                             // 0x0000(0x0010) (ZeroConstructor)
	int                                                PointCount;                                               // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.MeleeActionParam
// 0x0004
struct FMeleeActionParam
{
	bool                                               bSecondary;                                               // 0x0000(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bActive;                                                  // 0x0001(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bProcessed;                                               // 0x0002(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bFinished;                                                // 0x0003(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.SecondarySkillPerkSetData
// 0x0048 (0x0068 - 0x0020)
struct FSecondarySkillPerkSetData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<ESecondarySkill>                       RequiredSkills[0x5];                                      // 0x0038(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x003D(0x0003) MISSED OFFSET
	int                                                RequiredSkillLevels[0x5];                                 // 0x0040(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0054(0x0004) MISSED OFFSET
	struct FName                                       SecondarySkillPerkIds[0x2];                               // 0x0058(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.StructureGridReplicationData
// 0x0018
struct FStructureGridReplicationData
{
	uint32_t                                           NetGUID;                                                  // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                GridMapId;                                                // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FName                                       ItemId;                                                   // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              Health;                                                   // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bFlipped;                                                 // 0x0014(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.StructurePlugReplicationData
// 0x0018 (0x0030 - 0x0018)
struct FStructurePlugReplicationData : public FStructureGridReplicationData
{
	struct FName                                       TargetSocketName;                                         // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       PlugSocketName;                                           // 0x0020(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bActivated;                                               // 0x0028(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0029(0x0003) MISSED OFFSET
	int                                                YawModifier;                                              // 0x002C(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlugIdBase
// 0x0010
struct FPlugIdBase
{
	int                                                GridMapId;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FName                                       TargetSocket;                                             // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlugHealthUpdate
// 0x0008 (0x0018 - 0x0010)
struct FPlugHealthUpdate : public FPlugIdBase
{
	float                                              NewHealth;                                                // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bDamaged;                                                 // 0x0014(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.UpdatedGridSlotData
// 0x0050
struct FUpdatedGridSlotData
{
	int                                                GridMapId;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	struct FName                                       ItemId;                                                   // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               bFlipped;                                                 // 0x0010(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
	uint32_t                                           NetGUID;                                                  // 0x0014(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FPlaceableUpgradeState                      UpgradeState;                                             // 0x0018(0x0038)
};

// ScriptStruct Otherlands.DestroyedComponentData
// 0x0070
struct FDestroyedComponentData
{
	class UDestructibleMesh*                           DestructibleMesh;                                         // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	class USoundCue*                                   DestructionSound;                                         // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FTransform                                  Transform;                                                // 0x0010(0x0030) (IsPlainOldData)
	float                                              ImpulseForce;                                             // 0x0040(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     ImpactPoint;                                              // 0x0044(0x000C) (IsPlainOldData)
	struct FVector                                     ImpactNormal;                                             // 0x0050(0x000C) (IsPlainOldData)
	struct FVector                                     OriginalImpactPoint;                                      // 0x005C(0x000C) (IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0068(0x0008) MISSED OFFSET
};

// ScriptStruct Otherlands.PlayerAbilityData
// 0x00F0 (0x0548 - 0x0458)
struct FPlayerAbilityData : public FAbilityData
{
	struct FText                                       DisplayName;                                              // 0x0458(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0470(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0488(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.PlayerAbilityData.Icon
	int                                                AllowedMovementFlags;                                     // 0x04B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitDamage;                                               // 0x04B4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamage;                                              // 0x04B8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x04BC(0x0004) MISSED OFFSET
	class UAnimMontage*                                MaleActionMontage;                                        // 0x04C0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleActionMontage;                                      // 0x04C8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CastSpeed;                                                // 0x04D0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              NoiseModifier;                                            // 0x04D4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DurabilityCostInSeconds;                                  // 0x04D8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x04DC(0x0004) MISSED OFFSET
	struct FName                                       ItemIdReagent;                                            // 0x04E0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsRepeatable;                                            // 0x04E8(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x04E9(0x0007) MISSED OFFSET
	class UAnimMontage*                                MaleWindupMontage;                                        // 0x04F0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleWindupMontage;                                      // 0x04F8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WindupPlayRateScalar;                                     // 0x0500(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x0504(0x0004) MISSED OFFSET
	class UAnimMontage*                                MaleChargeLoopMontage;                                    // 0x0508(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleChargeLoopMontage;                                  // 0x0510(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ChargeLoopPlayRateScalar;                                 // 0x0518(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bBlockOnInvalidTarget;                                    // 0x051C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCastOnMiss;                                              // 0x051D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bInteractWithTarget;                                      // 0x051E(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAlwaysKnown;                                             // 0x051F(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHidden;                                                  // 0x0520(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x7];                                       // 0x0521(0x0007) MISSED OFFSET
	TArray<struct FStatEffectData>                     CostStats;                                                // 0x0528(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TEnumAsByte<ESecondarySkill>                       SecondarySkill;                                           // 0x0538(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x7];                                       // 0x0539(0x0007) MISSED OFFSET
	class UClass*                                      AbilityClass;                                             // 0x0540(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.TameState
// 0x0010
struct FTameState
{
	class AAICharacter*                                TameTarget;                                               // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              TameScore;                                                // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              TameValue;                                                // 0x000C(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.RecentPlayer
// 0x0028
struct FRecentPlayer
{
	struct FDateTime                                   LastSeen;                                                 // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly)
	struct FString                                     CharacterId;                                              // 0x0008(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0018(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Otherlands.PlayerTempoState
// 0x0008
struct FPlayerTempoState
{
	float                                              PositiveScalar;                                           // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              NegativeScalar;                                           // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ReckoiningStateChangeData
// 0x0004 (0x0014 - 0x0010)
struct FReckoiningStateChangeData : public FGameEventData
{
	TEnumAsByte<EReckoningStage>                       NewState;                                                 // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.MotionEventData
// 0x0004 (0x0014 - 0x0010)
struct FMotionEventData : public FGameEventData
{
	TEnumAsByte<EMotionState>                          MotionState;                                              // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsSprinting;                                             // 0x0011(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0012(0x0002) MISSED OFFSET
};

// ScriptStruct Otherlands.CrosshairState
// 0x0008
struct FCrosshairState
{
	TEnumAsByte<ECrosshairType>                        Crosshair;                                                // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bOutOfRange;                                              // 0x0001(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bWrongTool;                                               // 0x0002(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0003(0x0001) MISSED OFFSET
	float                                              Spread;                                                   // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CraftStealState
// 0x0018
struct FCraftStealState
{
	struct FName                                       CraftSkillTreeId;                                         // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       StolenRecipeId;                                           // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              ProgressRatio;                                            // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PlayerSpawnPointData
// 0x0060
struct FPlayerSpawnPointData
{
	struct FString                                     Name;                                                     // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst)
	struct FString                                     OwnerId;                                                  // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst)
	struct FString                                     ClanId;                                                   // 0x0020(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst)
	bool                                               bDefault;                                                 // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0031(0x0003) MISSED OFFSET
	int                                                FactionId;                                                // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	struct FName                                       ZoneId;                                                   // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	struct FName                                       ItemId;                                                   // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	struct FName                                       WorldMapId;                                               // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	struct FVector                                     WorldLocation;                                            // 0x0050(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, EditConst, IsPlainOldData)
	ETeleportRestriction                               TeleportRestriction;                                      // 0x005C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x005D(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.VivoxData
// 0x0040
struct FVivoxData
{
	struct FString                                     AccountName;                                              // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     LoginToken;                                               // 0x0010(0x0010) (ZeroConstructor)
	struct FString                                     ChannelId;                                                // 0x0020(0x0010) (ZeroConstructor)
	struct FString                                     ChannelJoinToken;                                         // 0x0030(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.PlayerStatFloatItem
// 0x0004 (0x0010 - 0x000C)
struct FPlayerStatFloatItem : public FFastArraySerializerItem
{
	float                                              Value;                                                    // 0x000C(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerStatFloatArray
// 0x0020 (0x00D0 - 0x00B0)
struct FPlayerStatFloatArray : public FFastArraySerializer
{
	TArray<struct FPlayerStatFloatItem>                Items;                                                    // 0x00B0(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0x10];                                      // 0x00C0(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.SpiritRealmEventData
// 0x0004 (0x0014 - 0x0010)
struct FSpiritRealmEventData : public FGameEventData
{
	bool                                               bEntering;                                                // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.LocalCraftLink
// 0x0010
struct FLocalCraftLink
{
	TWeakObjectPtr<class UCraftComponent>              CraftComponent;                                           // 0x0000(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                Links;                                                    // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	bool                                               bStale;                                                   // 0x000C(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.RemoteCraftLink
// 0x000C
struct FRemoteCraftLink
{
	TWeakObjectPtr<class URemoteCraftComponent>        RemoteCraftComponent;                                     // 0x0000(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                Links;                                                    // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ResourceTrigger
// 0x0020
struct FResourceTrigger
{
	TEnumAsByte<EResourceTriggerDataType>              DataType;                                                 // 0x0000(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EResourceTriggerTimingType>            TimingType;                                               // 0x0001(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0002(0x0006) MISSED OFFSET
	struct FName                                       DataId;                                                   // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                DataValue;                                                // 0x0010(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TriggerChance;                                            // 0x0014(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bExclusive;                                               // 0x0018(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bMatchInstigatorRealm;                                    // 0x0019(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x001A(0x0006) MISSED OFFSET
};

// ScriptStruct Otherlands.ResourceHarvestData
// 0x0058 (0x0078 - 0x0020)
struct FResourceHarvestData : public FTableRowSequencedBase
{
	struct FName                                       LootId;                                                   // 0x0020(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              BaseMaxHealth;                                            // 0x0028(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              BaseMaxHealthVariation;                                   // 0x002C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              DespawnThreshold;                                         // 0x0030(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESecondarySkill>                       SkillType;                                                // 0x0034(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0035(0x0003) MISSED OFFSET
	float                                              BaseNumLootRolls;                                         // 0x0038(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              BaseNumLootRollsVariation;                                // 0x003C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bLootRollPerHarvest;                                      // 0x0040(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0041(0x0003) MISSED OFFSET
	float                                              HarvestXP[0x5];                                           // 0x0044(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              NoiseMultiplier;                                          // 0x0058(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x005C(0x0004) MISSED OFFSET
	TArray<struct FResourceTrigger>                    Triggers;                                                 // 0x0060(0x0010) (Edit, ZeroConstructor)
	class UClass*                                      ResourceActorClass;                                       // 0x0070(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.SeasonMaterialScalars
// 0x0010
struct FSeasonMaterialScalars
{
	struct FName                                       ParameterName;                                            // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              DefaultValue;                                             // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.SeasonMaterialVectors
// 0x0018
struct FSeasonMaterialVectors
{
	struct FName                                       ParameterName;                                            // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                DefaultValue;                                             // 0x0008(0x0010) (Edit, IsPlainOldData)
};

// ScriptStruct Otherlands.SeasonMaterialParameters
// 0x0020
struct FSeasonMaterialParameters
{
	TArray<struct FSeasonMaterialScalars>              ScalarParameters;                                         // 0x0000(0x0010) (Edit, ZeroConstructor)
	TArray<struct FSeasonMaterialVectors>              VectorParameters;                                         // 0x0010(0x0010) (Edit, ZeroConstructor)
};

// ScriptStruct Otherlands.SeasonLocalFogParameters
// 0x0020
struct FSeasonLocalFogParameters
{
	class UTexture2D*                                  FogColor;                                                 // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              FogDensity;                                               // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              ColorScale;                                               // 0x000C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0010(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.SeasonPostProcessParameters
// 0x0018
struct FSeasonPostProcessParameters
{
	float                                              WhiteTemp;                                                // 0x0000(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              WhiteTint;                                                // 0x0004(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                SceneColorTint;                                           // 0x0008(0x0010) (Edit, IsPlainOldData)
};

// ScriptStruct Otherlands.SeasonScaleLightingParameters
// 0x0020
struct FSeasonScaleLightingParameters
{
	struct FLinearColor                                SkyLightMod;                                              // 0x0000(0x0010) (Edit, IsPlainOldData)
	struct FLinearColor                                DirLightMod;                                              // 0x0010(0x0010) (Edit, IsPlainOldData)
};

// ScriptStruct Otherlands.SeasonParameters
// 0x0078
struct FSeasonParameters
{
	struct FSeasonMaterialParameters                   MaterialParameters;                                       // 0x0000(0x0020) (Edit)
	struct FSeasonLocalFogParameters                   LocalFogParameters;                                       // 0x0020(0x0020) (Edit)
	struct FSeasonPostProcessParameters                PostProcessParameters;                                    // 0x0040(0x0018) (Edit)
	struct FSeasonScaleLightingParameters              ScaleLightingParameters;                                  // 0x0058(0x0020) (Edit)
};

// ScriptStruct Otherlands.PerkSetInfo
// 0x0020
struct FPerkSetInfo
{
	int                                                RequiredLevel;                                            // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0004(0x0004) MISSED OFFSET
	TArray<struct FName>                               PerkIds;                                                  // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	bool                                               bUnlocked;                                                // 0x0018(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
	int                                                ChosenIndex;                                              // 0x001C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.SecondarySkillInfo
// 0x0020
struct FSecondarySkillInfo
{
	int                                                SkillLevel;                                               // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaxLevel;                                                 // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SkillXP;                                                  // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              XPToLevel;                                                // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FPerkSetInfo>                        PerkSets;                                                 // 0x0010(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.ServerFilterData
// 0x0028
struct FServerFilterData
{
	struct FString                                     SearchText;                                               // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	TArray<bool>                                       ReckoningDays;                                            // 0x0010(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	bool                                               bPassword;                                                // 0x0020(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bProtected;                                               // 0x0021(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bUnprotected;                                             // 0x0022(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bExploration;                                             // 0x0023(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bClassic;                                                 // 0x0024(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bFactionWar;                                              // 0x0025(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bCustom;                                                  // 0x0026(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0027(0x0001) MISSED OFFSET
};

// ScriptStruct Otherlands.WaveScheduleDay
// 0x000C
struct FWaveScheduleDay
{
	int                                                DayOfWeek;                                                // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                Hour;                                                     // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                Minute;                                                   // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.OutcastSetting
// 0x0010
struct FOutcastSetting
{
	struct FTimespan                                   Duration;                                                 // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly)
	float                                              Penalty;                                                  // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.DemolishPermissionSetting
// 0x0018
struct FDemolishPermissionSetting
{
	struct FTimespan                                   Length;                                                   // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FTimespan                                   Cooldown;                                                 // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly)
	float                                              VoteRequirement;                                          // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                Version;                                                  // 0x0014(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.AscensionRelevance
// 0x0008
struct FAscensionRelevance
{
	TEnumAsByte<EAscensionActivity>                    Activity;                                                 // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	int                                                RequiredActivityCount;                                    // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.AscensionSettings
// 0x0050
struct FAscensionSettings
{
	float                                              MinimumRewardActiveHr;                                    // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ExpectedAverageRewardActiveHr;                            // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ExpectedRelevanceMin;                                     // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	TArray<struct FAscensionRelevance>                 Activities;                                               // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	float                                              WinBonus;                                                 // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              GameEndBonus;                                             // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ExpectedRelevanceSec;                                     // 0x0028(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              MinimumRewardActiveSec;                                   // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ExpectedAverageRewardActiveSec;                           // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MaximumRewardActiveSec;                                   // 0x0034(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              RewardActiveRangeSec;                                     // 0x0038(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData)
	float                                              Relevance[0x4];                                           // 0x003C(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.SharedServerSettings
// 0x0028
struct FSharedServerSettings
{
	TArray<struct FName>                               GameModeFlags;                                            // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	bool                                               bPersonalTechTree;                                        // 0x0010(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bNoFactions;                                              // 0x0011(0x0001) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0012(0x0002) MISSED OFFSET
	float                                              JumpPenaltyPeriod;                                        // 0x0014(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              StackCountScalar;                                         // 0x0018(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              WarehouseDepositMaxCapScalar;                             // 0x001C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                FactionLimit;                                             // 0x0020(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ServerListReckoningInfo
// 0x000C
struct FServerListReckoningInfo
{
	int                                                DayOfWeek;                                                // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                Hour;                                                     // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                Minute;                                                   // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.WaveGroupEntry
// 0x0010
struct FWaveGroupEntry
{
	struct FName                                       SpawnGroupId;                                             // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpawnDistance;                                            // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EWaveSpawnLocation>                    SpawnLocation;                                            // 0x000C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.WaveGroupData
// 0x0030 (0x0050 - 0x0020)
struct FWaveGroupData : public FTableRowSequencedBase
{
	struct FName                                       WaveBaseId;                                               // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SpawnBaseId;                                              // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpawnDelay;                                               // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bClearWaveOnDestroy;                                      // 0x0034(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0035(0x0003) MISSED OFFSET
	int                                                LevelRangeMinOverride;                                    // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                LevelRangeMaxOverride;                                    // 0x003C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FWaveGroupEntry>                     GroupEntries;                                             // 0x0040(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.CreatureSummonDisplayData
// 0x0040 (0x0060 - 0x0020)
struct FCreatureSummonDisplayData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0038(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.CreatureSummonDisplayData.Icon
};

// ScriptStruct Otherlands.CreatureScalarStats
// 0x0058
struct FCreatureScalarStats
{
	float                                              Health;                                                   // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              HealthRegen;                                              // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              HealthRegenWait;                                          // 0x0008(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              armor;                                                    // 0x000C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              UnitDamageBase;                                           // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SiegeDamageBase;                                          // 0x0014(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              UnitDamageScalar;                                         // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SiegeDamageScalar;                                        // 0x001C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SpeedScalar;                                              // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                XpValue;                                                  // 0x0024(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              LootScalar;                                               // 0x0028(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TameRate;                                                 // 0x002C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              TameValue;                                                // 0x0030(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              PetCarryWeight;                                           // 0x0034(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MountMaxStamina;                                          // 0x0038(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MountSprintStaminaDrainRate;                              // 0x003C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MountStaminaRechargeRate;                                 // 0x0040(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              PetXpScalar;                                              // 0x0044(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              PetPvpIncomingDamageScalar;                               // 0x0048(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              PetPvpOutgoingDamageScalar;                               // 0x004C(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              PetPveIncomingDamageScalar;                               // 0x0050(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              PetPveOutgoingDamageScalar;                               // 0x0054(0x0004) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.TameEventScalarEntry
// 0x0008
struct FTameEventScalarEntry
{
	TEnumAsByte<ETameEventType>                        TameEvent;                                                // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              Scalar;                                                   // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureFamilyData
// 0x0040 (0x0060 - 0x0020)
struct FCreatureFamilyData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<ECreatureFamily_CodeMap>               CodeMap;                                                  // 0x0038(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0039(0x0007) MISSED OFFSET
	struct FName                                       CreatureClassId;                                          // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FTameEventScalarEntry>               TameEventScalars;                                         // 0x0048(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	bool                                               bHasSoul;                                                 // 0x0058(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0059(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.CreatureAbilityTableData
// 0x0018
struct FCreatureAbilityTableData
{
	float                                              Priority;                                                 // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Weight;                                                   // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AbilityId;                                                // 0x0008(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AllowedStateFlags;                                        // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.CreatureVariantTableData
// 0x0028
struct FCreatureVariantTableData
{
	class UMaterialInstance*                           MaterialOverride;                                         // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Weight;                                                   // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SummonRatingMin;                                          // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SummonRatingMax;                                          // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	class UCurveFloat*                                 SummonRatingCurve;                                        // 0x0018(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SummonDisplayId;                                          // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureBaseData
// 0x0298 (0x02B8 - 0x0020)
struct FCreatureBaseData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	class UClass*                                      CreatureBlueprint;                                        // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CreatureFamilyId;                                         // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FName>                               CreatureClasses;                                          // 0x0048(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FCreatureBehaviorData                       Behavior;                                                 // 0x0058(0x0040) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FCreatureBehaviorData                       SpiritRealmBehaviorOverride;                              // 0x0098(0x0040) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                OverrideNavAgentIndex;                                    // 0x00D8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AwareDuration;                                            // 0x00DC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                DefaultLevel;                                             // 0x00E0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HealthScalar;                                             // 0x00E4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HealthRegenRateScalar;                                    // 0x00E8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ArmorScalar;                                              // 0x00EC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DamageScalar;                                             // 0x00F0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LootScalar;                                               // 0x00F4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              XpScalar;                                                 // 0x00F8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TameValueScalar;                                          // 0x00FC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpiritRealmHealthScalar;                                  // 0x0100(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpiritRealmHealthRegenRateScalar;                         // 0x0104(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TameRateAdditive;                                         // 0x0108(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetHealthScalar;                                          // 0x010C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetHealthRegenRateScalar;                                 // 0x0110(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetArmorScalar;                                           // 0x0114(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetDamageScalar;                                          // 0x0118(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetCarryWeightScalar;                                     // 0x011C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MountMaxStaminaScalar;                                    // 0x0120(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MountSprintStaminaDrainRateScalar;                        // 0x0124(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MountStaminaRechargeRateScalar;                           // 0x0128(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPvpIncomingDamageScalar;                               // 0x012C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPvpOutgoingDamageScalar;                               // 0x0130(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPveIncomingDamageScalar;                               // 0x0134(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPveOutgoingDamageScalar;                               // 0x0138(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetXpScalar;                                              // 0x013C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FName>                               OnSpawnBuffIds;                                           // 0x0140(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       OnDeathSpellId;                                           // 0x0150(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bReactToHarvestNoise;                                     // 0x0158(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0159(0x0003) MISSED OFFSET
	float                                              FleeHealthThreshold;                                      // 0x015C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bOpenlyHostile;                                           // 0x0160(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0161(0x0007) MISSED OFFSET
	struct FName                                       SightPerceptionSocket;                                    // 0x0168(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       EngagementRangeSocket;                                    // 0x0170(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FCreatureAbilityTableData>           Abilities;                                                // 0x0178(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       ImpactEffectKitId;                                        // 0x0188(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MovementRotationRateYaw;                                  // 0x0190(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              StationaryRotationRateYaw;                                // 0x0194(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WanderRadius;                                             // 0x0198(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ChildrenWanderRadius;                                     // 0x019C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ParentedWanderRadius;                                     // 0x01A0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x01A4(0x0004) MISSED OFFSET
	struct FName                                       WanderSplineGroupId;                                      // 0x01A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LeashRadius;                                              // 0x01B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AttentionSpan;                                            // 0x01B4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SightRadius;                                              // 0x01B8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LoseSightRadius;                                          // 0x01BC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SightCone;                                                // 0x01C0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HearingRadius;                                            // 0x01C4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WakeUpRadius;                                             // 0x01C8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              NearbyRadius;                                             // 0x01CC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AggroRadius;                                              // 0x01D0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxChaseRadius;                                           // 0x01D4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ENetCullRangeType>                     NetCullRange;                                             // 0x01D8(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EAIReaction>                           FamilyReactionAttackAs;                                   // 0x01D9(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EAIReaction>                           FamilyReactionFleeAs;                                     // 0x01DA(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EAIReaction>                           FamilyReactionIgnoreAs;                                   // 0x01DB(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x01DC(0x0004) MISSED OFFSET
	struct FName                                       CreatureMovementId;                                       // 0x01E0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FlankChance;                                              // 0x01E8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ResourceClearRadiusScalar;                                // 0x01EC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ResourceClearCone;                                        // 0x01F0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxThreatListCount;                                       // 0x01F4(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ThreatRuleId;                                             // 0x01F8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRandomThreat;                                            // 0x0200(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTargetRequireAbility;                                    // 0x0201(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPickAbilityAfterEngagement;                              // 0x0202(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x1];                                       // 0x0203(0x0001) MISSED OFFSET
	float                                              EngagementRangeMin;                                       // 0x0204(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EngagementRangeMax;                                       // 0x0208(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x020C(0x0004) MISSED OFFSET
	class USoundCue*                                   AwareSound;                                               // 0x0210(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   AgroSound;                                                // 0x0218(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   FleeSound;                                                // 0x0220(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   TakeHitSound;                                             // 0x0228(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   DeathSound;                                               // 0x0230(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       NPCComponentId;                                           // 0x0238(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestableSouls;                                         // 0x0240(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CreatureScale;                                            // 0x0244(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetCreatureScale;                                         // 0x0248(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CreatureScaleVariance;                                    // 0x024C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WalkSpeed;                                                // 0x0250(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RunSpeed;                                                 // 0x0254(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUseReservationSlot;                                      // 0x0258(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0259(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsSpirit;                                                // 0x025A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x5];                                       // 0x025B(0x0005) MISSED OFFSET
	class UStaticMesh*                                 OverheadAttachment;                                       // 0x0260(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FCreatureVariantTableData>           Variants;                                                 // 0x0268(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       VariantSocketSuffix;                                      // 0x0278(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   RandomNoiseCue;                                           // 0x0280(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RandomNoiseFrequency;                                     // 0x0288(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RandomNoiseFrequencyVariation;                            // 0x028C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       LootResourceHarvestId;                                    // 0x0290(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpawnRadiusScalar;                                        // 0x0298(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x4];                                       // 0x029C(0x0004) MISSED OFFSET
	struct FName                                       PetId;                                                    // 0x02A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       MountId;                                                  // 0x02A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ResurrectId;                                              // 0x02B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureClassData
// 0x0060 (0x0080 - 0x0020)
struct FCreatureClassData : public FTableRowSequencedBase
{
	float                                              HealthScalar;                                             // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HealthRegenRateScalar;                                    // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ArmorScalar;                                              // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DamageScalar;                                             // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LootScalar;                                               // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              XpScalar;                                                 // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpeedScalar;                                              // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TameValueScalar;                                          // 0x003C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpiritRealmHealthScalar;                                  // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpiritRealmHealthRegenRateScalar;                         // 0x0044(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TameRateAdditive;                                         // 0x0048(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetHealthScalar;                                          // 0x004C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetHealthRegenRateScalar;                                 // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetArmorScalar;                                           // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetDamageScalar;                                          // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetCarryWeightScalar;                                     // 0x005C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MountMaxStaminaScalar;                                    // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MountSprintStaminaDrainRateScalar;                        // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MountStaminaRechargeRateScalar;                           // 0x0068(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPvpIncomingDamageScalar;                               // 0x006C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPvpOutgoingDamageScalar;                               // 0x0070(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPveIncomingDamageScalar;                               // 0x0074(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetPveOutgoingDamageScalar;                               // 0x0078(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PetXpScalar;                                              // 0x007C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpawnVolumeData
// 0x0058
struct FSpawnVolumeData
{
	bool                                               bSpawnDuringDay;                                          // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bSpawnDuringNight;                                        // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESpiritRealmState>                     SpawnWithPlayersInRealm;                                  // 0x0002(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bDespawnOffCycle;                                         // 0x0003(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bHuntOnSpawn;                                             // 0x0004(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0005(0x0003) MISSED OFFSET
	struct FName                                       HunterChannelId;                                          // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       OverrideWanderSplineGroupId;                              // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TArray<struct FSpawnNamedParameter>                OverrideNamedParameters;                                  // 0x0018(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	struct FName                                       SpawnBaseId;                                              // 0x0028(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MinPopulation;                                            // 0x0030(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                MaxPopulation;                                            // 0x0034(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                StartingPopulation;                                       // 0x0038(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SpawnRateAtMinPopulation;                                 // 0x003C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SpawnRateAtMaxPopulation;                                 // 0x0040(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	class UClass*                                      ManagerClass;                                             // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class USpawnVolumeDataManager*                     Manager;                                                  // 0x0050(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// ScriptStruct Otherlands.SpellBookInit
// 0x0058
struct FSpellBookInit
{
	TArray<struct FName>                               LearnedSpells;                                            // 0x0000(0x0010) (ZeroConstructor)
	float                                              GlobalCooldown;                                           // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              ImmobalizeTime;                                           // 0x0014(0x0004) (ZeroConstructor, IsPlainOldData)
	TArray<struct FName>                               CooldownBySpellKeys;                                      // 0x0018(0x0010) (ZeroConstructor)
	TArray<float>                                      CooldownBySpellValues;                                    // 0x0028(0x0010) (ZeroConstructor)
	TArray<struct FName>                               UnlockedSpells;                                           // 0x0038(0x0010) (ZeroConstructor)
	TArray<int>                                        UnlockedSpellCount;                                       // 0x0048(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.SpellCastParam
// 0x0030
struct FSpellCastParam
{
	TEnumAsByte<ESpellCastActionType>                  ActionType;                                               // 0x0000(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EUseSpellItemType>                     UseItemType;                                              // 0x0001(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0002(0x0006) MISSED OFFSET
	struct FName                                       SpellId;                                                  // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UObject*                                     PreferredTarget;                                          // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       InteractActionId;                                         // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UInventoryItem*                              UseItem;                                                  // 0x0020(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TWeakObjectPtr<class UBuffData>                    Buff;                                                     // 0x0028(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PrerequisiteData
// 0x0030 (0x0050 - 0x0020)
struct FPrerequisiteData : public FTableRowSequencedBase
{
	TEnumAsByte<EPrerequisiteType>                     PrerequisiteType;                                         // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EPrerequisiteOperator>                 PrerequisiteOperator;                                     // 0x0021(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        ReferenceStat;                                            // 0x0022(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EPrerequisiteEntity>                   ReferenceEntity[0x2];                                     // 0x0023(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
	struct FName                                       ReferenceId[0x2];                                         // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ReferenceValue[0x2];                                      // 0x0038(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      ReferenceCustom[0x2];                                     // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpellSoundParams
// 0x0001
struct FSpellSoundParams
{
	TEnumAsByte<EGender>                               Gender;                                                   // 0x0000(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.DamageTypeData
// 0x0020 (0x0040 - 0x0020)
struct FDamageTypeData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<EDamageType>                           Type;                                                     // 0x0038(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        ResistanceStat;                                           // 0x0039(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        BonusDamagePercentStat;                                   // 0x003A(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        ConvertDamageStat;                                        // 0x003B(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        ScalarStat;                                               // 0x003C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           ParentDamageType;                                         // 0x003D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x003E(0x0002) MISSED OFFSET
};

// ScriptStruct Otherlands.CooldownGroupData
// 0x0008 (0x0028 - 0x0020)
struct FCooldownGroupData : public FTableRowSequencedBase
{
	float                                              GroupCooldown;                                            // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.BuffTriggerData
// 0x0050 (0x0070 - 0x0020)
struct FBuffTriggerData : public FTableRowSequencedBase
{
	TEnumAsByte<EBuffTrigger>                          BuffTrigger;                                              // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	int                                                RemoveStacksOnTrigger;                                    // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkill>                       BuffTriggerFilterSecondarySkill;                          // 0x0028(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	struct FName                                       BuffTriggerFilterCreatureFamily;                          // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BuffTriggerOnStatusChanceFlags;                           // 0x0038(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              BuffTriggerChance;                                        // 0x003C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUseActionSpeed;                                          // 0x0040(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0041(0x0003) MISSED OFFSET
	float                                              BuffTriggerThreshold;                                     // 0x0044(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffTriggerBuffId;                                        // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffTriggerTargetBuffId;                                  // 0x0050(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       TriggerPlayerAbilityId;                                   // 0x0058(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              BuffTriggerCooldown;                                      // 0x0060(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bClearTriggerOnMotionChange;                              // 0x0064(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bOnlyTriggerOnce;                                         // 0x0065(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x2];                                       // 0x0066(0x0002) MISSED OFFSET
	int                                                AllowedTargetType;                                        // 0x0068(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.BuffCategoryEntryData
// 0x0010
struct FBuffCategoryEntryData
{
	struct FName                                       BuffCategory;                                             // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BuffTier;                                                 // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.BuffStatEffectData
// 0x0038
struct FBuffStatEffectData
{
	TEnumAsByte<ECharacterStat>                        CharacterStat;                                            // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              StatValue;                                                // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsAdditive;                                              // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsAmbient;                                               // 0x0009(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x000A(0x0006) MISSED OFFSET
	unsigned char                                      UnknownData02[0x28];                                      // 0x000A(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.BuffStatEffectData.StackCurve
};

// ScriptStruct Otherlands.BuffSkillEffectData
// 0x0030
struct FBuffSkillEffectData
{
	TEnumAsByte<ESecondarySkill>                       SecondarySkill;                                           // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkillStat>                   SkillStat;                                                // 0x0001(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0002(0x0002) MISSED OFFSET
	float                                              SkillStatValue;                                           // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0008(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.BuffSkillEffectData.SkillStackCurve
};

// ScriptStruct Otherlands.BuffTempoEffectData
// 0x0010
struct FBuffTempoEffectData
{
	struct FName                                       TempoChannelId;                                           // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EffectValue;                                              // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.BuffBaseData
// 0x0378 (0x0398 - 0x0020)
struct FBuffBaseData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       TooltipText;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	class UTexture2D*                                  Icon;                                                     // 0x0050(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsVisibleInUI;                                           // 0x0058(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsBeneficial;                                            // 0x0059(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bGeneratesAggro;                                          // 0x005A(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x005B(0x0001) MISSED OFFSET
	int                                                BaseLevel;                                                // 0x005C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FName>                               BuffCategoryIds;                                          // 0x0060(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	int                                                BuffTier;                                                 // 0x0070(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0074(0x0004) MISSED OFFSET
	TArray<struct FBuffCategoryEntryData>              Immunities;                                               // 0x0078(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	int                                                CharacterStatusFlags;                                     // 0x0088(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Duration;                                                 // 0x008C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       UnlockPlayerAbilityId;                                    // 0x0090(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FBuffStatEffectData>                 BuffStatData;                                             // 0x0098(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FBuffSkillEffectData>                BuffSkillStatData;                                        // 0x00A8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FBuffTempoEffectData>                TempoScalar;                                              // 0x00B8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FBuffTempoEffectData>                TempoTick;                                                // 0x00C8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	int                                                StackableCount;                                           // 0x00D8(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EBuffStackingRule>                     BuffStackingRule;                                         // 0x00DC(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x00DD(0x0003) MISSED OFFSET
	struct FName                                       BuffStackingBuffId;                                       // 0x00E0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BuffStackingBuffCount;                                    // 0x00E8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bStackDuration;                                           // 0x00EC(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bExpireSingleStack;                                       // 0x00ED(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x2];                                       // 0x00EE(0x0002) MISSED OFFSET
	TArray<struct FName>                               BuffTriggerIds;                                           // 0x00F0(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	int                                                BuffStackingTriggerCount;                                 // 0x0100(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRemoveOnDeath;                                           // 0x0104(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRemoveOnWeaponSwap;                                      // 0x0105(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bDoNotPersist;                                            // 0x0106(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCountdownOffline;                                        // 0x0107(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTickOnApply;                                             // 0x0108(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bProrateLastTick;                                         // 0x0109(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x2];                                       // 0x010A(0x0002) MISSED OFFSET
	float                                              TickRate;                                                 // 0x010C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FStatEffectData>                     TickStatData;                                             // 0x0110(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	float                                              TickDamage;                                               // 0x0120(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TickTrueDamagePercent;                                    // 0x0124(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           TickDamageType;                                           // 0x0128(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x3];                                       // 0x0129(0x0003) MISSED OFFSET
	int                                                AuraAllowedTargetType;                                    // 0x012C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AuraRadius;                                               // 0x0130(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x4];                                       // 0x0134(0x0004) MISSED OFFSET
	struct FName                                       AuraBuffId;                                               // 0x0138(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       TickPlayerAbilityId;                                      // 0x0140(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       TickItemAffectDurabilityId;                               // 0x0148(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TickItemAffectDurabilityScalar;                           // 0x0150(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECustomBuffType>                       CustomBuffType;                                           // 0x0154(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x3];                                       // 0x0155(0x0003) MISSED OFFSET
	float                                              CustomBuffFloats[0x3];                                    // 0x0158(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData08[0x4];                                       // 0x0164(0x0004) MISSED OFFSET
	struct FGeneralFXData                              PersistentFX;                                             // 0x0168(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              ApplyFX;                                                  // 0x01B0(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              RemoveFX;                                                 // 0x01F8(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              SprintFX;                                                 // 0x0240(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              JumpFX;                                                   // 0x0288(0x0048) (Edit, DisableEditOnInstance)
	TEnumAsByte<EBuffTracerCombine>                    TracerCombine;                                            // 0x02D0(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData09[0x7];                                       // 0x02D1(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData10[0xA0];                                      // 0x02D1(0x00A0) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.BuffBaseData.TracerEffect
	bool                                               bMaintainCauseOrder;                                      // 0x0378(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData11[0x7];                                       // 0x0379(0x0007) MISSED OFFSET
	class UClass*                                      BuffClass;                                                // 0x0380(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData12[0x10];                                      // 0x0388(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.BuffCategoryData
// 0x0060 (0x0080 - 0x0020)
struct FBuffCategoryData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	bool                                               bExclusive;                                               // 0x0038(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTierMultiplicitive;                                      // 0x0039(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x003A(0x0006) MISSED OFFSET
	class UCurveFloat*                                 TierResistAdjustment;                                     // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffCategoryIdResistParent;                               // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        IgnoreChanceStat;                                         // 0x0050(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0051(0x0007) MISSED OFFSET
	class UCurveFloat*                                 ResistIgnoreChanceCurve;                                  // 0x0058(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        StackReductionStat;                                       // 0x0060(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0061(0x0007) MISSED OFFSET
	class UCurveFloat*                                 ResistStackReductionCurve;                                // 0x0068(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        DurationReductionStat;                                    // 0x0070(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0071(0x0007) MISSED OFFSET
	class UCurveFloat*                                 ResistDurationReductionCurve;                             // 0x0078(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureMountData
// 0x0118 (0x0138 - 0x0020)
struct FCreatureMountData : public FTableRowSequencedBase
{
	TEnumAsByte<EMountFamily>                          MountFamily;                                              // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	struct FRotator                                    MountSpineBaseRotation;                                   // 0x0024(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FName>                               MountSpineMotionBones;                                    // 0x0030(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	float                                              MountBoneMultiplier;                                      // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
	struct FName                                       AimStartBone;                                             // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RunSpeed;                                                 // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SprintSpeed;                                              // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 RatingSpeedMultiplierCurve;                               // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 MountMaxStaminaScalarByRatingCurve;                       // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 MountSprintStaminaDrainRateScalarByRatingCurve;           // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 MountStaminaRechargeRateByRatingCurve;                    // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanJump;                                                 // 0x0078(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanStrafe;                                               // 0x0079(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanTurnInPlace;                                          // 0x007A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x1];                                       // 0x007B(0x0001) MISSED OFFSET
	float                                              TurnRate;                                                 // 0x007C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxAimOffsetYaw;                                          // 0x0080(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFollowSurfacePitch;                                      // 0x0084(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFollowSurfaceRoll;                                       // 0x0085(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x2];                                       // 0x0086(0x0002) MISSED OFFSET
	float                                              CapsuleHalfHeight;                                        // 0x0088(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CapsuleRadius;                                            // 0x008C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MeshOffsetZ;                                              // 0x0090(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraDistanceOffset;                                     // 0x0094(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraShiftOffset;                                        // 0x0098(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CameraLoftOffset;                                         // 0x009C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       MountPetBuffId;                                           // 0x00A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       MountedPlayerBuffId;                                      // 0x00A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 RatingBuffStackCurve;                                     // 0x00B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FName>                               CreatureAbilityId;                                        // 0x00B8(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	struct FCreatureHarvestData                        HarvestTool;                                              // 0x00C8(0x0068) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FName                                       MountPlayerAbilityId;                                     // 0x0130(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreaturePetData
// 0x0128 (0x0148 - 0x0020)
struct FCreaturePetData : public FTableRowSequencedBase
{
	float                                              WanderRadius;                                             // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestWanderRadius;                                      // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CommandRadius;                                            // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MountRadius;                                              // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FCreatureBehaviorData                       OverrideBehavior;                                         // 0x0030(0x0040) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FName                                       OverrideThreatRuleId;                                     // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FCreatureAbilityTableData>           OverrideAbilities;                                        // 0x0078(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	class UCurveFloat*                                 RatingBuffStackCurve;                                     // 0x0088(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 TameValueScalarByRatingCurve;                             // 0x0090(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 PetCarryWeightScalarByRatingCurve;                        // 0x0098(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 PetHealthScalarByRatingCurve;                             // 0x00A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 PetHealthRegenScalarByRatingCurve;                        // 0x00A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 PetArmorScalarByRatingCurve;                              // 0x00B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 PetDamageScalarByRatingCurve;                             // 0x00B8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 PetSiegeDamageScalarByRatingCurve;                        // 0x00C0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ActiveBuffId;                                             // 0x00C8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PetSelfBuffId;                                            // 0x00D0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUseBaseOnSpawnBuff;                                      // 0x00D8(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00D9(0x0007) MISSED OFFSET
	struct FCreatureHarvestData                        HarvestTool;                                              // 0x00E0(0x0068) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Otherlands.RatingItemReagentData
// 0x0008 (0x0018 - 0x0010)
struct FRatingItemReagentData : public FItemReagentData
{
	class UCurveFloat*                                 CountRatingScalarCurve;                                   // 0x0010(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureResurrectData
// 0x0018 (0x0038 - 0x0020)
struct FCreatureResurrectData : public FTableRowSequencedBase
{
	float                                              ResurrectTime;                                            // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
	TArray<struct FRatingItemReagentData>              Reagents;                                                 // 0x0028(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.WanderState
// 0x0020
struct FWanderState
{
	TWeakObjectPtr<class AActor>                       Follower;                                                 // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     ExpectedStart;                                            // 0x0008(0x000C) (IsPlainOldData)
	bool                                               bReverse;                                                 // 0x0014(0x0001) (ZeroConstructor, IsPlainOldData)
	bool                                               bFailedLast;                                              // 0x0015(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0016(0x0002) MISSED OFFSET
	float                                              PrevSplineLoc;                                            // 0x0018(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              SplineLoc;                                                // 0x001C(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.WanderDeadLink
// 0x000C
struct FWanderDeadLink
{
	float                                              StartSplineLoc;                                           // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              EndSplineLoc;                                             // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              LastDeadTime;                                             // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.WorldMapData
// 0x0050 (0x0070 - 0x0020)
struct FWorldMapData : public FTableRowSequencedBase
{
	struct FName                                       InternalName;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FString                                     LevelName;                                                // 0x0028(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	class UTexture2D*                                  MapImage;                                                 // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UTexture2D*                                  ZoneImage;                                                // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FVector2D                                   TopLeftCoordinate;                                        // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	struct FVector2D                                   BottomRightCoordinate;                                    // 0x0050(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance, IsPlainOldData)
	float                                              MapRotation;                                              // 0x0058(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x005C(0x0004) MISSED OFFSET
	TArray<struct FName>                               ContainedZoneIds;                                         // 0x0060(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.SlashCommandData
// 0x0018 (0x0038 - 0x0020)
struct FSlashCommandData : public FTableRowSequencedBase
{
	struct FString                                     StringCommand;                                            // 0x0020(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       EmoteId;                                                  // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MapWaypointData
// 0x0018 (0x0038 - 0x0020)
struct FMapWaypointData : public FTableRowSequencedBase
{
	struct FName                                       InternalName;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UTexture2D*                                  WaypointIcon;                                             // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      WaypointWidgetClass;                                      // 0x0030(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.LoreTextData
// 0x0060 (0x0080 - 0x0020)
struct FLoreTextData : public FTableRowSequencedBase
{
	struct FText                                       Title;                                                    // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       LoreText;                                                 // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       FunctionText;                                             // 0x0050(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Attribution;                                              // 0x0068(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Otherlands.InteractActionData
// 0x0080 (0x00A0 - 0x0020)
struct FInteractActionData : public FTableRowSequencedBase
{
	struct FName                                       ActionName;                                               // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       InputActionName;                                          // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PermissionIdOverride;                                     // 0x0030(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EInteractAction_CodeMap>               InteractActionCodeMap;                                    // 0x0038(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0039(0x0007) MISSED OFFSET
	struct FText                                       DisplayName;                                              // 0x0040(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0058(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0070(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.InteractActionData.Icon
	bool                                               bCanBeDefaultAction;                                      // 0x0098(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bShowInInteractRadial;                                    // 0x0099(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x6];                                       // 0x009A(0x0006) MISSED OFFSET
};

// ScriptStruct Otherlands.EmoteData
// 0x0060 (0x0080 - 0x0020)
struct FEmoteData : public FTableRowSequencedBase
{
	class USoundCue*                                   MaleSoundEmote;                                           // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   FemaleSoundEmote;                                         // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleEmoteMontage;                                         // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleEmoteMontage;                                       // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bStopMontageOnMove;                                       // 0x0040(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAllowMontageMounted;                                     // 0x0041(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0042(0x0006) MISSED OFFSET
	struct FText                                       EmoteText;                                                // 0x0048(0x0018) (Edit, DisableEditOnInstance)
	class UTexture2D*                                  EmoteIcon;                                                // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FText                                       EmoteName;                                                // 0x0068(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
};

// ScriptStruct Otherlands.WaterVolumeEventData
// 0x0004 (0x0014 - 0x0010)
struct FWaterVolumeEventData : public FGameEventData
{
	float                                              Amount;                                                   // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ResearchCompletedData
// 0x0010
struct FResearchCompletedData
{
	class UTechTree*                                   TechTree;                                                 // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       CraftResearchId;                                          // 0x0008(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CharacterRespawnEventData
// 0x000C (0x001C - 0x0010)
struct FCharacterRespawnEventData : public FGameEventData
{
	struct FVector                                     SpawnPoint;                                               // 0x0010(0x000C) (BlueprintVisible, IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerBountyEventData
// 0x0008 (0x0018 - 0x0010)
struct FPlayerBountyEventData : public FGameEventData
{
	float                                              BountyValue;                                              // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bLastHit;                                                 // 0x0014(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.WeaponEventData
// 0x0018 (0x0028 - 0x0010)
struct FWeaponEventData : public FGameEventData
{
	struct FName                                       ItemId;                                                   // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       AmmoItemId;                                               // 0x0018(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DrawScalar;                                               // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemEventData
// 0x0010 (0x0020 - 0x0010)
struct FItemEventData : public FGameEventData
{
	struct FName                                       ItemId;                                                   // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                StackCount;                                               // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemDecayEventData
// 0x0008 (0x0028 - 0x0020)
struct FItemDecayEventData : public FItemEventData
{
	struct FName                                       DecayIntoItemId;                                          // 0x0020(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CraftResultEventData
// 0x0010 (0x0030 - 0x0020)
struct FCraftResultEventData : public FItemEventData
{
	TEnumAsByte<ECraftResultType>                      CraftResult;                                              // 0x0020(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	struct FName                                       RecipeId;                                                 // 0x0028(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.RecipeEventData
// 0x0010 (0x0020 - 0x0010)
struct FRecipeEventData : public FGameEventData
{
	struct FName                                       RecipeId;                                                 // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SkillXP;                                                  // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bSkilled;                                                 // 0x001C(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bMastered;                                                // 0x001D(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x001E(0x0002) MISSED OFFSET
};

// ScriptStruct Otherlands.ZoneEventData
// 0x0008 (0x0018 - 0x0010)
struct FZoneEventData : public FGameEventData
{
	struct FName                                       ZoneId;                                                   // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.HarvestEventData
// 0x0018 (0x0028 - 0x0010)
struct FHarvestEventData : public FGameEventData
{
	struct FName                                       LootId;                                                   // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EHarvestType>                          HarvestType;                                              // 0x0018(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
	int                                                QualityThreshold;                                         // 0x001C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Damage;                                                   // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EResourceTriggerTimingType>            TimingType;                                               // 0x0024(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterStatusEventData
// 0x0004 (0x0014 - 0x0010)
struct FCharacterStatusEventData : public FGameEventData
{
	TEnumAsByte<ECharacterStatusFlag>                  StatusFlag;                                               // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bSet;                                                     // 0x0011(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0012(0x0002) MISSED OFFSET
};

// ScriptStruct Otherlands.SpiritDepositEventData
// 0x0010 (0x0020 - 0x0010)
struct FSpiritDepositEventData : public FGameEventData
{
	int                                                Amount;                                                   // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	class UBasePylonSkeletal*                          Pylon;                                                    // 0x0018(0x0008) (BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// ScriptStruct Otherlands.CharacterStatEventData
// 0x000C (0x001C - 0x0010)
struct FCharacterStatEventData : public FGameEventData
{
	TEnumAsByte<ECharacterStat>                        CharStat;                                                 // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
	float                                              OldValue;                                                 // 0x0014(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              NewValue;                                                 // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CharacterAimDownSightEvent
// 0x0004 (0x0014 - 0x0010)
struct FCharacterAimDownSightEvent : public FGameEventData
{
	bool                                               bAimingDownSight;                                         // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0011(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterBuildEventData
// 0x0008 (0x0018 - 0x0010)
struct FCharacterBuildEventData : public FGameEventData
{
	struct FName                                       ItemId;                                                   // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.CharacterBuildUpgradeEventData
// 0x0018 (0x0030 - 0x0018)
struct FCharacterBuildUpgradeEventData : public FCharacterBuildEventData
{
	struct FName                                       FinalItemId;                                              // 0x0018(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FName                                       DepositedItemId;                                          // 0x0020(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                DepositedCount;                                           // 0x0028(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterBaseEventData
// 0x0004 (0x0014 - 0x0010)
struct FCharacterBaseEventData : public FGameEventData
{
	bool                                               bFaction;                                                 // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bPersonal;                                                // 0x0011(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bClan;                                                    // 0x0012(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0013(0x0001) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterTameEventData
// 0x0008 (0x0018 - 0x0010)
struct FCharacterTameEventData : public FGameEventData
{
	float                                              TamePoints;                                               // 0x0010(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETameEventType>                        TameEventType;                                            // 0x0014(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterPetEventData
// 0x0004 (0x0014 - 0x0010)
struct FCharacterPetEventData : public FGameEventData
{
	bool                                               bHasSpawn;                                                // 0x0010(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               bIsMounted;                                               // 0x0011(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0012(0x0002) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterSecondarySkillEventData
// 0x0010 (0x0020 - 0x0010)
struct FCharacterSecondarySkillEventData : public FGameEventData
{
	struct FName                                       SkillId;                                                  // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                SkillLevel;                                               // 0x0018(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x001C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterReportNoiseEvent
// 0x0018 (0x0028 - 0x0010)
struct FCharacterReportNoiseEvent : public FGameEventData
{
	struct FVector                                     NoiseLocation;                                            // 0x0010(0x000C) (BlueprintVisible, IsPlainOldData)
	TEnumAsByte<ENoiseType>                            NoiseType;                                                // 0x001C(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x001D(0x0003) MISSED OFFSET
	float                                              Volume;                                                   // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MaxRange;                                                 // 0x0024(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemRepairEventData
// 0x0008 (0x0018 - 0x0010)
struct FItemRepairEventData : public FGameEventData
{
	struct FName                                       ItemId;                                                   // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.FavoriteServerList
// 0x0010
struct FFavoriteServerList
{
	TArray<struct FFavoriteServerAddRequest>           Servers;                                                  // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Otherlands.VolumeValue
// 0x000C
struct FVolumeValue
{
	unsigned char                                      UnknownData00[0xC];                                       // 0x0000(0x000C) MISSED OFFSET
};

// ScriptStruct Otherlands.StoredAscensionData
// 0x0028
struct FStoredAscensionData
{
	TArray<struct FString>                             ContributingServers;                                      // 0x0000(0x0010) (ZeroConstructor)
	TArray<struct FAscensionUnlock>                    Unlocks;                                                  // 0x0010(0x0010) (ZeroConstructor)
	int                                                EarnedPoints;                                             // 0x0020(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                SpentPoints;                                              // 0x0024(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.TriggerInstanceCall
// 0x0040
struct FTriggerInstanceCall
{
	unsigned char                                      UnknownData00[0x40];                                      // 0x0000(0x0040) MISSED OFFSET
};

// ScriptStruct Otherlands.TriggerInstance
// 0x0018
struct FTriggerInstance
{
	unsigned char                                      UnknownData00[0x18];                                      // 0x0000(0x0018) MISSED OFFSET
};

// ScriptStruct Otherlands.PlayerKillRecordData
// 0x0008
struct FPlayerKillRecordData
{
	int                                                KillCount;                                                // 0x0000(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              FirstKillTime;                                            // 0x0004(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PerkTreeRow
// 0x0018
struct FPerkTreeRow
{
	TArray<struct FName>                               PerkBaseIds;                                              // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	int                                                MaxPerks;                                                 // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PerkTree
// 0x0020
struct FPerkTree
{
	TArray<struct FPerkTreeRow>                        PerkRows;                                                 // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FName>                               PerkBaseIds;                                              // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.BadWordData
// 0x0010 (0x0018 - 0x0008)
struct FBadWordData : public FTableRowBase
{
	struct FString                                     WordToFilter;                                             // 0x0008(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.CharacterVOData
// 0x0020 (0x0040 - 0x0020)
struct FCharacterVOData : public FTableRowSequencedBase
{
	TEnumAsByte<EVOTrigger>                            VOTrigger;                                                // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class USoundCue*                                   MaleSound;                                                // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   FemaleSound;                                              // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPersistent;                                              // 0x0038(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlayInWorld;                                             // 0x0039(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x003A(0x0006) MISSED OFFSET
};

// ScriptStruct Otherlands.CharacterEffectData
// 0x0048 (0x0068 - 0x0020)
struct FCharacterEffectData : public FTableRowSequencedBase
{
	TEnumAsByte<ECharacterEffect>                      EffectType;                                               // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class UParticleSystem*                             ParticleEffect[0x3];                                      // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AttachSocket;                                             // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   SoundEffect;                                              // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleCharacterMontage;                                     // 0x0050(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleCharacterMontage;                                   // 0x0058(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bLockPlayer;                                              // 0x0060(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0061(0x0003) MISSED OFFSET
	float                                              DrawCharacterDelay;                                       // 0x0064(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SecondarySkillCategoryData
// 0x0028 (0x0048 - 0x0020)
struct FSecondarySkillCategoryData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, DisableEditOnInstance)
	struct FName                                       SecondarySkillCategoryId;                                 // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                DisplayIndex;                                             // 0x0040(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0044(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.MaterialSwapData
// 0x0038 (0x0058 - 0x0020)
struct FMaterialSwapData : public FTableRowSequencedBase
{
	struct FName                                       MaterialSwapSetId;                                        // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterial*                                   BaseMaterial;                                             // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterial*                                   SwapMaterial;                                             // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterialInstance*                           BaseMaterialInstance;                                     // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterialInstance*                           SwapMaterialInstance;                                     // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterialInterface*                          BaseMaterialInterface;                                    // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UMaterialInterface*                          SwapMaterialInterface;                                    // 0x0050(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MaterialSwapSetData
// 0x0008 (0x0028 - 0x0020)
struct FMaterialSwapSetData : public FTableRowSequencedBase
{
	struct FName                                       InternalName;                                             // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.NPCComponentBaseData
// 0x0088 (0x00A8 - 0x0020)
struct FNPCComponentBaseData : public FTableRowSequencedBase
{
	struct FName                                       HairCustomizationId;                                      // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       FacialHairCustomizationId;                                // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       HairColorId;                                              // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SkinColorId;                                              // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               HeadMesh;                                                 // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               ChestMesh;                                                // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               LegsMesh;                                                 // 0x0050(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               HandsMesh;                                                // 0x0058(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletalMesh*                               FeetMesh;                                                 // 0x0060(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       HeadItemEquipId;                                          // 0x0068(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ChestItemEquipId;                                         // 0x0070(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       LegsItemEquipId;                                          // 0x0078(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ShouldersItemEquipId;                                     // 0x0080(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       HandsItemEquipId;                                         // 0x0088(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       FeetItemEquipId;                                          // 0x0090(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       MainHandItemDisplayId;                                    // 0x0098(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       OffHandItemDisplayId;                                     // 0x00A0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.AmbientStatBuffData
// 0x0010 (0x0030 - 0x0020)
struct FAmbientStatBuffData : public FTableRowSequencedBase
{
	TEnumAsByte<ECharacterStat>                        CharacterStatIdAmbient;                                   // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	float                                              AmbientThreshold;                                         // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       BuffId;                                                   // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CharacterStatBaseData
// 0x0058 (0x0078 - 0x0020)
struct FCharacterStatBaseData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TEnumAsByte<ECharacterStat>                        StatEnum;                                                 // 0x0038(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStatDisplayType>             DisplayEnum;                                              // 0x0039(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAllowInstantChange;                                      // 0x003A(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bStoreAsInt;                                              // 0x003B(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bMultiplicativeScalar;                                    // 0x003C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUseMin;                                                  // 0x003D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUseMax;                                                  // 0x003E(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x003F(0x0001) MISSED OFFSET
	float                                              DefaultValue;                                             // 0x0040(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MinValue;                                                 // 0x0044(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxValue;                                                 // 0x0048(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ThresholdValueToFlash;                                    // 0x004C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        MaxValueStat;                                             // 0x0050(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        TickAmountStat;                                           // 0x0051(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        TickWaitStat;                                             // 0x0052(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        TickPauseScalarStat;                                      // 0x0053(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TickRate;                                                 // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bReplicate;                                               // 0x0058(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bReplicateToOthers;                                       // 0x0059(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPresentOnNonPlayers;                                     // 0x005A(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EScalarConversionCurve>                ScalarConversionCurve;                                    // 0x005B(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x005C(0x0004) MISSED OFFSET
	class UCurveFloat*                                 PveOverrideConversionCurve;                               // 0x0060(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCurveFloat*                                 PvpOverrideConversionCurve;                               // 0x0068(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAmbientStat;                                             // 0x0070(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bThresholdBuffs;                                          // 0x0071(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        AmbientStatDropResist;                                    // 0x0072(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        AmbientStatDropRate;                                      // 0x0073(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        AmbientStatPositiveRecovery;                              // 0x0074(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        AmbientStatRaiseResist;                                   // 0x0075(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        AmbientStatRaiseRate;                                     // 0x0076(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        AmbientStatNegativeRecovery;                              // 0x0077(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ServerInformation
// 0x00D0
struct FServerInformation
{
	struct FString                                     ID;                                                       // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FString                                     Version;                                                  // 0x0010(0x0010) (ZeroConstructor)
	struct FString                                     Ip;                                                       // 0x0020(0x0010) (ZeroConstructor)
	struct FString                                     Shard;                                                    // 0x0030(0x0010) (ZeroConstructor)
	struct FString                                     TicketType;                                               // 0x0040(0x0010) (ZeroConstructor)
	uint16_t                                           Port;                                                     // 0x0050(0x0002) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0052(0x0006) MISSED OFFSET
	uint64_t                                           Registered;                                               // 0x0058(0x0008) (ZeroConstructor, IsPlainOldData)
	uint64_t                                           Updated;                                                  // 0x0060(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                QueueSize;                                                // 0x0068(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
	struct FString                                     Packet;                                                   // 0x0070(0x0010) (ZeroConstructor)
	TMap<struct FString, struct FString>               Properties;                                               // 0x0080(0x0050) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Otherlands.ServerList
// 0x0010
struct FServerList
{
	TArray<struct FServerInformation>                  Servers;                                                  // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ItemSoundData
// 0x0028 (0x0030 - 0x0008)
struct FItemSoundData : public FTableRowBase
{
	class USoundBase*                                  FireSound;                                                // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundBase*                                  EmptySound;                                               // 0x0010(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundBase*                                  ReloadSound;                                              // 0x0018(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HeldFadeIn;                                               // 0x0020(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HeldFadeOut;                                              // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundBase*                                  HeldSound;                                                // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SurfaceImpactKey
// 0x0010
struct FSurfaceImpactKey
{
	unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.ImpactEffectKitData
// 0x0000 (0x0020 - 0x0020)
struct FImpactEffectKitData : public FTableRowSequencedBase
{

};

// ScriptStruct Otherlands.ImpactEffectData
// 0x0060 (0x0080 - 0x0020)
struct FImpactEffectData : public FTableRowSequencedBase
{
	struct FName                                       ImpactEffectKitId;                                        // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EPhysicalSurface>                      SurfaceType;                                              // 0x0028(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	class UParticleSystem*                             ImpactEffect;                                             // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   ImpactSound;                                              // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0040(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ImpactEffectData.DecalMaterial
	struct FVector                                     DecalSize;                                                // 0x0068(0x000C) (Edit, DisableEditOnInstance, IsPlainOldData)
	float                                              DecalLifeSpan;                                            // 0x0074(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DecalFadeDelay;                                           // 0x0078(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x007C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.HitZoneData
// 0x0018 (0x0038 - 0x0020)
struct FHitZoneData : public FTableRowSequencedBase
{
	float                                              DamageMultiplier;                                         // 0x0020(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
	struct FName                                       ImpactEffectKitId;                                        // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        AttackerModifierStat;                                     // 0x0030(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ECharacterStat>                        DefenderModifierStat;                                     // 0x0031(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESecondarySkillStat>                   SkillStatModifier;                                        // 0x0032(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x0033(0x0005) MISSED OFFSET
};

// ScriptStruct Otherlands.DemolishVoteEvent
// 0x0040
struct FDemolishVoteEvent
{
	unsigned char                                      UnknownData00[0x40];                                      // 0x0000(0x0040) MISSED OFFSET
};

// ScriptStruct Otherlands.OutcastVoteEvent
// 0x0040
struct FOutcastVoteEvent
{
	unsigned char                                      UnknownData00[0x40];                                      // 0x0000(0x0040) MISSED OFFSET
};

// ScriptStruct Otherlands.FactionLadderEntry
// 0x0020
struct FFactionLadderEntry
{
	unsigned char                                      UnknownData00[0x20];                                      // 0x0000(0x0020) MISSED OFFSET
};

// ScriptStruct Otherlands.GroupLookupKey
// 0x0010
struct FGroupLookupKey
{
	unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.PermissionLookupKey
// 0x0010
struct FPermissionLookupKey
{
	unsigned char                                      UnknownData00[0x10];                                      // 0x0000(0x0010) MISSED OFFSET
};

// ScriptStruct Otherlands.AuthTicketPair
// 0x0030
struct FAuthTicketPair
{
	bool                                               bValid;                                                   // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FString                                     Ticket;                                                   // 0x0008(0x0010) (ZeroConstructor)
	struct FString                                     EncodedTicket;                                            // 0x0018(0x0010) (ZeroConstructor)
	int                                                Expiration;                                               // 0x0028(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.IncomingAuthTicket
// 0x0050
struct FIncomingAuthTicket
{
	TMap<struct FString, struct FString>               Tickets;                                                  // 0x0000(0x0050) (ZeroConstructor)
};

// ScriptStruct Otherlands.OutgoingAuthTicket
// 0x0040
struct FOutgoingAuthTicket
{
	struct FString                                     Ticket;                                                   // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     Type;                                                     // 0x0010(0x0010) (ZeroConstructor)
	struct FString                                     Platform;                                                 // 0x0020(0x0010) (ZeroConstructor)
	struct FString                                     ID;                                                       // 0x0030(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ServerTicketProperty
// 0x0020
struct FServerTicketProperty
{
	struct FString                                     Key;                                                      // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     Value;                                                    // 0x0010(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ServerCommandResponse
// 0x0028
struct FServerCommandResponse
{
	bool                                               SUCCESS;                                                  // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FString                                     CommandId;                                                // 0x0008(0x0010) (ZeroConstructor)
	struct FString                                     Result;                                                   // 0x0018(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ServerUpdateData
// 0x0090
struct FServerUpdateData
{
	TArray<struct FString>                             Consumed;                                                 // 0x0000(0x0010) (ZeroConstructor)
	TArray<struct FString>                             Rejected;                                                 // 0x0010(0x0010) (ZeroConstructor)
	struct FString                                     Packet;                                                   // 0x0020(0x0010) (ZeroConstructor)
	TMap<struct FString, struct FString>               Properties;                                               // 0x0030(0x0050) (ZeroConstructor)
	TArray<struct FServerCommandResponse>              Responses;                                                // 0x0080(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ServerCommand
// 0x0020
struct FServerCommand
{
	struct FString                                     CommandId;                                                // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     Command;                                                  // 0x0010(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ServerUpdateResponse
// 0x0038
struct FServerUpdateResponse
{
	TArray<struct FString>                             Pending;                                                  // 0x0000(0x0010) (ZeroConstructor)
	TArray<struct FString>                             Queue;                                                    // 0x0010(0x0010) (ZeroConstructor)
	uint64_t                                           Time;                                                     // 0x0020(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<struct FServerCommand>                      Commands;                                                 // 0x0028(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.GoalActorTraitData
// 0x0008 (0x0028 - 0x0020)
struct FGoalActorTraitData : public FTableRowSequencedBase
{
	struct FName                                       Name;                                                     // 0x0020(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemAffixGroupTier
// 0x0008
struct FItemAffixGroupTier
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemAffixGroupFilter
// 0x000C
struct FItemAffixGroupFilter
{
	unsigned char                                      UnknownData00[0xC];                                       // 0x0000(0x000C) MISSED OFFSET
};

// ScriptStruct Otherlands.WarehouseDataTierHash
// 0x0010
struct FWarehouseDataTierHash
{
	struct FName                                       ID;                                                       // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	int                                                Tier;                                                     // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.InventoryGroupMappingData
// 0x0008 (0x0028 - 0x0020)
struct FInventoryGroupMappingData : public FTableRowSequencedBase
{
	TEnumAsByte<EInventoryGroup>                       InventoryGroup;                                           // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemCategory>                         ItemCategory;                                             // 0x0021(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0022(0x0006) MISSED OFFSET
};

// ScriptStruct Otherlands.InventoryGroupData
// 0x0048 (0x0068 - 0x0020)
struct FInventoryGroupData : public FTableRowSequencedBase
{
	TEnumAsByte<EInventoryGroup>                       InventoryGroup;                                           // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	struct FText                                       DisplayName;                                              // 0x0028(0x0018) (Edit, DisableEditOnInstance)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0040(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.InventoryGroupData.Icon
};

// ScriptStruct Otherlands.ItemAffixGroupEntryData
// 0x0008 (0x0028 - 0x0020)
struct FItemAffixGroupEntryData : public FTableRowSequencedBase
{
	TEnumAsByte<EItemCategory>                         AllowedItemCategory;                                      // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemType>                             AllowedItemType;                                          // 0x0021(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EEquipSlot>                            AllowedEquipSlot;                                         // 0x0022(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x0023(0x0001) MISSED OFFSET
	int                                                GroupId;                                                  // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemModificationData
// 0x0090 (0x00B0 - 0x0020)
struct FItemModificationData : public FTableRowSequencedBase
{
	TEnumAsByte<EEquipSlot>                            ModEquipSlot;                                             // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EHeldItemType>                         ModHeldItemType;                                          // 0x0021(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x0022(0x0006) MISSED OFFSET
	unsigned char                                      UnknownData01[0x28];                                      // 0x0022(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemModificationData.ModStaticMesh
	struct FName                                       ModAttachPoint;                                           // 0x0050(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x28];                                      // 0x0058(0x0028) UNKNOWN PROPERTY: SoftClassProperty Otherlands.ItemModificationData.ModPointLight
	unsigned char                                      UnknownData03[0x28];                                      // 0x0080(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemModificationData.ModParticleFX
	struct FName                                       ModBuffId;                                                // 0x00A8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemMontageData
// 0x01E0 (0x0200 - 0x0020)
struct FItemMontageData : public FTableRowSequencedBase
{
	class UAnimMontage*                                FemaleFireMontages[0x5];                                  // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleOffhandFireMontages[0x5];                           // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleAlternateFireMontages[0x5];                         // 0x0070(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleAlternateOffhandFireMontages[0x5];                  // 0x0098(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleEmptyMontages[0x5];                                 // 0x00C0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                FemaleReloadMontages[0x5];                                // 0x00E8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleFireMontages[0x5];                                    // 0x0110(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleOffhandFireMontages[0x5];                             // 0x0138(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleAlternateFireMontages[0x5];                           // 0x0160(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleAlternateOffhandFireMontages[0x5];                    // 0x0188(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleEmptyMontages[0x5];                                   // 0x01B0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleReloadMontages[0x5];                                  // 0x01D8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemEquipData
// 0x00C0 (0x00E0 - 0x0020)
struct FItemEquipData : public FTableRowSequencedBase
{
	TEnumAsByte<EEquipSlot>                            EquipSlot;                                                // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData01[0x28];                                      // 0x0021(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemEquipData.FemaleEquipMesh
	bool                                               bHideUnderlyingMeshFemale;                                // 0x0050(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0051(0x0007) MISSED OFFSET
	unsigned char                                      UnknownData03[0x28];                                      // 0x0051(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemEquipData.MaleEquipMesh
	bool                                               bHideUnderlyingMesh;                                      // 0x0080(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x3];                                       // 0x0081(0x0003) MISSED OFFSET
	int                                                HideHairSections;                                         // 0x0084(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bEquipBuffOnlyWhenHeld;                                   // 0x0088(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x7];                                       // 0x0089(0x0007) MISSED OFFSET
	struct FName                                       EquipBuffId;                                              // 0x0090(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EquipTemperature;                                         // 0x0098(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bEquipStatOnlyWhenHeld;                                   // 0x009C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x3];                                       // 0x009D(0x0003) MISSED OFFSET
	TArray<struct FStatEffectData>                     EquipStat;                                                // 0x00A0(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	unsigned char                                      UnknownData07[0x30];                                      // 0x00B0(0x0030) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemAmmoData
// 0x0168 (0x0188 - 0x0020)
struct FItemAmmoData : public FTableRowSequencedBase
{
	struct FText                                       AmmoShortName;                                            // 0x0020(0x0018) (Edit, DisableEditOnInstance)
	TEnumAsByte<EAmmoType>                             AmmoType;                                                 // 0x0038(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           AmmoDamageType;                                           // 0x0039(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x003A(0x0006) MISSED OFFSET
	TArray<struct FDamageConversion>                   AmmoDamageConversions;                                    // 0x0040(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	float                                              AmmoUnitDamage;                                           // 0x0050(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoUnitPvpDamage;                                        // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoSiegeDamage;                                          // 0x0058(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoTrueDamagePercent;                                    // 0x005C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoPvpTrueDamagePercent;                                 // 0x0060(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoSpreadModifier;                                       // 0x0064(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                AdditionalPierceTargets;                                  // 0x0068(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
	unsigned char                                      UnknownData02[0x28];                                      // 0x006C(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemAmmoData.ProjectileStaticMesh
	unsigned char                                      UnknownData03[0xA0];                                      // 0x0098(0x00A0) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemAmmoData.TracerEffect
	unsigned char                                      UnknownData04[0x28];                                      // 0x0138(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemAmmoData.AmmoDecalMaterial
	struct FVector                                     AmmoDecalSize;                                            // 0x0160(0x000C) (Edit, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoDecalLifeSpan;                                        // 0x016C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AmmoDecalFadeDelay;                                       // 0x0170(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x0174(0x0004) MISSED OFFSET
	struct FName                                       PayloadId;                                                // 0x0178(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bOverridePayload;                                         // 0x0180(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x7];                                       // 0x0181(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.ItemConsumableData
// 0x00A8 (0x00C8 - 0x0020)
struct FItemConsumableData : public FTableRowSequencedBase
{
	int                                                CharacterStatusFlagsPrevent;                              // 0x0020(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
	TArray<struct FStatEffectData>                     InstantStats;                                             // 0x0028(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       ConsumableBuffId;                                         // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ConsumablePlayerAbilityId;                                // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       LearnedRecipeId;                                          // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemResourceType>                     ConsumableItemResource;                                   // 0x0050(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0051(0x0003) MISSED OFFSET
	float                                              ConsumableItemResourceAmount;                             // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bDontConsume;                                             // 0x0058(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x0059(0x0003) MISSED OFFSET
	float                                              Cooldown;                                                 // 0x005C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              GlobalCooldown;                                           // 0x0060(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIgnoreGlobalCooldown;                                    // 0x0064(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0065(0x0003) MISSED OFFSET
	struct FName                                       CooldownGroupId;                                          // 0x0068(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FGeneralFXData                              OnConsumeFX;                                              // 0x0070(0x0048) (Edit, DisableEditOnInstance)
	class UAnimMontage*                                FemaleConsumeMontage;                                     // 0x00B8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAnimMontage*                                MaleConsumeMontage;                                       // 0x00C0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemPlaceableData
// 0x0498 (0x04B8 - 0x0020)
struct FItemPlaceableData : public FTableRowSequencedBase
{
	unsigned char                                      UnknownData00[0x28];                                      // 0x0020(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableMesh
	unsigned char                                      UnknownData01[0x28];                                      // 0x0048(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDiagonalMesh
	unsigned char                                      UnknownData02[0x28];                                      // 0x0070(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableMeshMirror
	unsigned char                                      UnknownData03[0x28];                                      // 0x0098(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDiagonalMeshMirror
	unsigned char                                      UnknownData04[0x28];                                      // 0x00C0(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDestructibleMesh
	unsigned char                                      UnknownData05[0x28];                                      // 0x00E8(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDiagonalDestructibleMesh
	unsigned char                                      UnknownData06[0x28];                                      // 0x0110(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDestructibleMeshMirror
	unsigned char                                      UnknownData07[0x28];                                      // 0x0138(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDiagonalDestructibleMeshMirror
	unsigned char                                      UnknownData08[0x28];                                      // 0x0160(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableSkeletalMesh
	unsigned char                                      UnknownData09[0x28];                                      // 0x0188(0x0028) UNKNOWN PROPERTY: SoftClassProperty Otherlands.ItemPlaceableData.PlaceableAnimBP
	unsigned char                                      UnknownData10[0x28];                                      // 0x01B0(0x0028) UNKNOWN PROPERTY: SoftClassProperty Otherlands.ItemPlaceableData.PlaceableVehicleBP
	bool                                               bNonBlockingCollision;                                    // 0x01D8(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EPlaceableType>                        PlaceableType;                                            // 0x01D9(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EStructureType>                        PlaceableStrucutreType;                                   // 0x01DA(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EPlaceableMaterial>                    BuildModeMaterial;                                        // 0x01DB(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                BuildModeTier;                                            // 0x01DC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       VariantItemId;                                            // 0x01E0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemPlaceableUpgradeId;                                   // 0x01E8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableMaxHealth;                                       // 0x01F0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableArmor;                                           // 0x01F4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlugArmorAddition;                                        // 0x01F8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UnitToSiegeDamageConversionScalar;                        // 0x01FC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableTier;                                            // 0x0200(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              IsolatedExpirationTimeSeconds;                            // 0x0204(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableAuraBuffId;                                      // 0x0208(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableTimedPlayerSpellId;                              // 0x0210(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableOnHitPlayerSpellId;                              // 0x0218(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableOnDamagedPlayerSpellId;                          // 0x0220(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceableOnParentDamagedPlayerSpellId;                    // 0x0228(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableFuseTime;                                        // 0x0230(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsPlayerSleeper;                                         // 0x0234(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsPlayerSpawnPoint;                                      // 0x0235(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData11[0x2];                                       // 0x0236(0x0002) MISSED OFFSET
	float                                              PlayerSpawnRadius;                                        // 0x0238(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxPlaceableDistance;                                     // 0x023C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableGridWidth;                                       // 0x0240(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableGridHeight;                                      // 0x0244(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EBuildingType>                         PlaceableBuildingType;                                    // 0x0248(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData12[0x3];                                       // 0x0249(0x0003) MISSED OFFSET
	struct FIntVector                                  StructureStartSize;                                       // 0x024C(0x000C) (Edit, DisableEditOnInstance, IsPlainOldData)
	int                                                StructureStartPadding;                                    // 0x0258(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlacementRestrictions;                                    // 0x025C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       FirstStructurePieceId;                                    // 0x0260(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanPlaceOutsideBase;                                     // 0x0268(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bAlwaysExpire;                                            // 0x0269(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESpiritRealmState>                     PlacementRestrictSpiritRealm;                             // 0x026A(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlaceableIsPermanent;                                    // 0x026B(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bTransferBeforeDefaults;                                  // 0x026C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSkipPlacementPermissionCheck;                            // 0x026D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData13[0x2];                                       // 0x026E(0x0002) MISSED OFFSET
	struct FName                                       InitialLootId;                                            // 0x0270(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlaceablePlugId;                                          // 0x0278(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FItemPlaceableDefaultData>           PlaceableDefaultPlugs;                                    // 0x0280(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       PlaceableSkeletalAttachSocket;                            // 0x0290(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                InWorldLimitPerPlayer;                                    // 0x0298(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                InWorldLimitPerClan;                                      // 0x029C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bClaimsStructureForPlayer;                                // 0x02A0(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bClaimsStructureForTribe;                                 // 0x02A1(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSpawnsStructure;                                         // 0x02A2(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bStructureOwnedByCreator;                                 // 0x02A3(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EStructureEdge>                        DefaultStructureEdge;                                     // 0x02A4(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData14[0x3];                                       // 0x02A5(0x0003) MISSED OFFSET
	int                                                PlaceableInventorySlots;                                  // 0x02A8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemCategory>                         PlaceableInventoryCategory;                               // 0x02AC(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIgnoreFactionUseScore;                                   // 0x02AD(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData15[0x2];                                       // 0x02AE(0x0002) MISSED OFFSET
	int                                                CraftQueueCount;                                          // 0x02B0(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ETechTreeType>                         PlaceableTechTreeType;                                    // 0x02B4(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData16[0x3];                                       // 0x02B5(0x0003) MISSED OFFSET
	struct FName                                       PlaceableCraftStatsId;                                    // 0x02B8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlaceableIsWeaponModStation;                             // 0x02C0(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemStationFuelType>                  PlaceableStationFuelType;                                 // 0x02C1(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData17[0x2];                                       // 0x02C2(0x0002) MISSED OFFSET
	float                                              PlaceableFuelBurnRate;                                    // 0x02C4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableInventoryFuelSlots;                              // 0x02C8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EItemCategory>                         PlaceableInventoryFuelCategory;                           // 0x02CC(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlaceableAlwaysActive;                                   // 0x02CD(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData18[0x2];                                       // 0x02CE(0x0002) MISSED OFFSET
	float                                              PlaceableWaterStorage;                                    // 0x02D0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableWaterFillRate;                                   // 0x02D4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlaceableWaterInitialValue;                               // 0x02D8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bVehicleAutomatable;                                      // 0x02DC(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData19[0x3];                                       // 0x02DD(0x0003) MISSED OFFSET
	class UBehaviorTree*                               VehicleBehaviorTree;                                      // 0x02E0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       VehicleProjectileSocket;                                  // 0x02E8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       VehicleWeaponItemId;                                      // 0x02F0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PermissionIdRequiredInventory;                            // 0x02F8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PermissionIdRequiredModify;                               // 0x0300(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PermissionIdRequiredInteract;                             // 0x0308(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PermissionIdRequiredOverride;                             // 0x0310(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlaceableStashAccess;                                    // 0x0318(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlaceableWarehouseAccess;                                // 0x0319(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlaceableIsArmory;                                       // 0x031A(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPlaceableIsStable;                                       // 0x031B(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bStructureOwned;                                          // 0x031C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSurvivesPlatformLoss;                                    // 0x031D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData20[0x2];                                       // 0x031E(0x0002) MISSED OFFSET
	struct FName                                       PlaceableFactionBuffId;                                   // 0x0320(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                PlaceableFactionBuffStackCount;                           // 0x0328(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bCanBePickedUp;                                           // 0x032C(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bRenameable;                                              // 0x032D(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData21[0x2];                                       // 0x032E(0x0002) MISSED OFFSET
	TArray<struct FName>                               AllowedInteractions;                                      // 0x0330(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FName                                       LootIdFree;                                               // 0x0340(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CooldownGroupIdInteract;                                  // 0x0348(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData22[0x28];                                      // 0x0350(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableActiveFX
	unsigned char                                      UnknownData23[0x28];                                      // 0x0378(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlacementParticleFX
	unsigned char                                      UnknownData24[0x28];                                      // 0x03A0(0x0028) UNKNOWN PROPERTY: SoftClassProperty Otherlands.ItemPlaceableData.PlaceableActiveLight
	unsigned char                                      UnknownData25[0x28];                                      // 0x03C8(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableSound
	unsigned char                                      UnknownData26[0x28];                                      // 0x03F0(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDestroySound
	unsigned char                                      UnknownData27[0x28];                                      // 0x0418(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableRepairSound
	unsigned char                                      UnknownData28[0x28];                                      // 0x0440(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableActiveSound
	unsigned char                                      UnknownData29[0x28];                                      // 0x0468(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemPlaceableData.PlaceableDeactivateSound
	class UClass*                                      PlaceableActorClass;                                      // 0x0490(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       NoFactionMaterialSwapSetId;                               // 0x0498(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       Faction1MaterialSwapSetId;                                // 0x04A0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       Faction2MaterialSwapSetId;                                // 0x04A8(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       Faction3MaterialSwapSetId;                                // 0x04B0(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemDisplayData
// 0x00C0 (0x00E0 - 0x0020)
struct FItemDisplayData : public FTableRowSequencedBase
{
	unsigned char                                      UnknownData00[0x28];                                      // 0x0020(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemDisplayData.HeldStaticMesh
	unsigned char                                      UnknownData01[0x28];                                      // 0x0048(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemDisplayData.HeldSkeletalMesh
	unsigned char                                      UnknownData02[0x10];                                      // 0x0070(0x0010) UNKNOWN PROPERTY: ArrayProperty Otherlands.ItemDisplayData.HeldMaterialOverrides
	TEnumAsByte<EHeldItemType>                         HeldItemType;                                             // 0x0080(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0081(0x0007) MISSED OFFSET
	class UClass*                                      AnimBP;                                                   // 0x0088(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x28];                                      // 0x0090(0x0028) UNKNOWN PROPERTY: SoftClassProperty Otherlands.ItemDisplayData.PointLight
	unsigned char                                      UnknownData05[0x28];                                      // 0x00B8(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemDisplayData.ParticleFX
};

// ScriptStruct Otherlands.ItemHarvestData
// 0x0010 (0x0030 - 0x0020)
struct FItemHarvestData : public FTableRowSequencedBase
{
	TEnumAsByte<EHarvestType>                          HarvestType;                                              // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EHarvestType>                          HarvestTypeSecondary;                                     // 0x0021(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0022(0x0002) MISSED OFFSET
	float                                              HarvestDamagePerHit;                                      // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestDamageVariation;                                   // 0x0028(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HarvestQuantityMultiplier;                                // 0x002C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemBowScalarData
// 0x00A0 (0x00C0 - 0x0020)
struct FItemBowScalarData : public FTableRowSequencedBase
{
	unsigned char                                      UnknownData00[0x28];                                      // 0x0020(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemBowScalarData.DrawToDamageScalarCurve
	unsigned char                                      UnknownData01[0x28];                                      // 0x0048(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemBowScalarData.DrawToVelocityScalarCurve
	unsigned char                                      UnknownData02[0x28];                                      // 0x0070(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemBowScalarData.DrawToRangeScalarCurve
	unsigned char                                      UnknownData03[0x28];                                      // 0x0098(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemBowScalarData.DrawToAccuracyScalarCurve
};

// ScriptStruct Otherlands.ItemDamageData
// 0x02D0 (0x02F0 - 0x0020)
struct FItemDamageData : public FTableRowSequencedBase
{
	bool                                               bHitScan;                                                 // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSemiAuto;                                                // 0x0021(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EAttackType>                           AttackType;                                               // 0x0022(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EAmmoType>                             RequiredAmmoType;                                         // 0x0023(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EDamageType>                           DamageType;                                               // 0x0024(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
	TArray<struct FDamageConversion>                   DamageConversions;                                        // 0x0028(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	float                                              UnitDamagePerHit;                                         // 0x0038(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SiegeDamagePerHit;                                        // 0x003C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AttackSpeed;                                              // 0x0040(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ClipSize;                                                 // 0x0044(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              LastShotSpeedScalar;                                      // 0x0048(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              EmptyTime;                                                // 0x004C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ReloadTime;                                               // 0x0050(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WeaponSwapTime;                                           // 0x0054(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TrueDamagePercent;                                        // 0x0058(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              PlayerDamageScalar;                                       // 0x005C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MoveSpeedModifier;                                        // 0x0060(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DamageNoiseModifier;                                      // 0x0064(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PayloadId;                                                // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ItemBowScalarDataId;                                      // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSMoveSpeedModifier;                                     // 0x0078(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSMouseSpeedModifier;                                    // 0x007C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSCameraFOV;                                             // 0x0080(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSCameraDistance;                                        // 0x0084(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSCameraShift;                                           // 0x0088(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSCameraLoft;                                            // 0x008C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DefaultCameraFOV;                                         // 0x0090(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DefaultCameraDistance;                                    // 0x0094(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DefaultCameraShift;                                       // 0x0098(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DefaultCameraLoft;                                        // 0x009C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlayerAbilityIdPrimary;                                   // 0x00A0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       PlayerAbilityIdAlternate;                                 // 0x00A8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AlternateUnitDamagePerHit;                                // 0x00B0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AlternateSiegeDamagePerHit;                               // 0x00B4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AlternateAttackSpeed;                                     // 0x00B8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              BurstTime;                                                // 0x00BC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ShotsPerBurst;                                            // 0x00C0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HipSpread;                                                // 0x00C4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSSpread;                                                // 0x00C8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HipSpreadMoving;                                          // 0x00CC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSSpreadMoving;                                          // 0x00D0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HipSpreadPerShot;                                         // 0x00D4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSSpreadPerShot;                                         // 0x00D8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxSpreadDelay;                                           // 0x00DC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpreadDelayPerShotScalar;                                 // 0x00E0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HipSpreadMaxFromFiring;                                   // 0x00E4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSSpreadMaxFromFiring;                                   // 0x00E8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HipSpreadRecoveryRate;                                    // 0x00EC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSSpreadRecoveryRate;                                    // 0x00F0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HipRecoil;                                                // 0x00F4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ADSRecoil;                                                // 0x00F8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CrouchRecoil;                                             // 0x00FC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CrouchADSRecoil;                                          // 0x0100(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              BurstRecoilMultiplier;                                    // 0x0104(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0108(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemDamageData.RecoilPitchCurve
	unsigned char                                      UnknownData02[0x28];                                      // 0x0130(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemDamageData.RecoilYawCurve
	float                                              RecoilNegativeYawChance;                                  // 0x0158(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x015C(0x0004) MISSED OFFSET
	unsigned char                                      UnknownData04[0x28];                                      // 0x015C(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ItemDamageData.RecoilRecoveryCurve
	float                                              RecoilPitchDuration;                                      // 0x0188(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RecoilYawDuration;                                        // 0x018C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RecoilRandomScalarMin;                                    // 0x0190(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RecoilRandomScalarMax;                                    // 0x0194(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bScaleRecoilSpeedWithAttackSpeed;                         // 0x0198(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bShotgun;                                                 // 0x0199(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x2];                                       // 0x019A(0x0002) MISSED OFFSET
	float                                              ShotgunSpread;                                            // 0x019C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ShotgunCircles;                                           // 0x01A0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                ShotgunShotsPerCircle;                                    // 0x01A4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpinUpTime;                                               // 0x01A8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpinDownRate;                                             // 0x01AC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpinDownDelay;                                            // 0x01B0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileVelocity;                                       // 0x01B4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileDistanceBeforeGravity;                          // 0x01B8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileTraceRange;                                     // 0x01BC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileGravityScale;                                   // 0x01C0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DamageFalloffRangeMin;                                    // 0x01C4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DamageFalloffRangeMax;                                    // 0x01C8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x4];                                       // 0x01CC(0x0004) MISSED OFFSET
	class UCurveFloat*                                 DamageFalloffCurve;                                       // 0x01D0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxTargets;                                               // 0x01D8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ProjectileLifeSpanAfterImpact;                            // 0x01DC(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FGeneralFXData                              FireFX;                                                   // 0x01E0(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              ChannelFX;                                                // 0x0228(0x0048) (Edit, DisableEditOnInstance)
	struct FGeneralFXData                              FullyDrawnFX;                                             // 0x0270(0x0048) (Edit, DisableEditOnInstance)
	class UClass*                                      FireCameraShake;                                          // 0x02B8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      FullyDrawnCameraShake;                                    // 0x02C0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       HarvestImpactEffectKitId;                                 // 0x02C8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       MeleeImpactEffectKitId;                                   // 0x02D0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       RepairImpactEffectKitId;                                  // 0x02D8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SalvageImpactEffectKitId;                                 // 0x02E0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RepairAmountPerHit;                                       // 0x02E8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SalvageAmountPerHit;                                      // 0x02EC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ItemServerUniqueData
// 0x0020 (0x0040 - 0x0020)
struct FItemServerUniqueData : public FTableRowSequencedBase
{
	bool                                               bUniquePlaceholder;                                       // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	int                                                MaxSagaCount;                                             // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bDropsOnLogoff;                                           // 0x0028(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0029(0x0003) MISSED OFFSET
	float                                              MaximumLogoffHours;                                       // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                SagaUniquePriority;                                       // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SagaUniqueChance;                                         // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	EItemUniqueRestriction                             SagaRestrictionRule;                                      // 0x0038(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0039(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.ConfusionProbabilityMatrix
// 0x0070
struct FConfusionProbabilityMatrix
{
	double                                             PredictedPositves;                                        // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             PredictedNegatives;                                       // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             ConditionPositives;                                       // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             ConditionNegatives;                                       // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             FalsePositives;                                           // 0x0020(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             FalseNegatives;                                           // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             TruePositives;                                            // 0x0030(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             TrueNegatives;                                            // 0x0038(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             TruePositiveRate;                                         // 0x0040(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             TrueNegativeRate;                                         // 0x0048(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             FalsePositiveRate;                                        // 0x0050(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             FalseNegativeRate;                                        // 0x0058(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             Accuracy;                                                 // 0x0060(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             MCC;                                                      // 0x0068(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.JrkResult
// 0x0020
struct FJrkResult
{
	struct FString                                     UniqueSaveId;                                             // 0x0000(0x0010) (ZeroConstructor)
	double                                             IsChance;                                                 // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
	double                                             NotChance;                                                // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.ResourceDisplayData
// 0x0068 (0x0088 - 0x0020)
struct FResourceDisplayData : public FTableRowSequencedBase
{
	bool                                               bBlockingCollision;                                       // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class UStaticMesh*                                 StaticMesh;                                               // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0030(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.ResourceDisplayData.DestructibleMesh
	class UStaticMesh*                                 StumpMesh;                                                // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UStaticMesh*                                 TrunkMesh;                                                // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   DestructionSound;                                         // 0x0068(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxHarvestDistance;                                       // 0x0070(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x14];                                      // 0x0074(0x0014) MISSED OFFSET
};

// ScriptStruct Otherlands.ResourceSpawnData
// 0x0020 (0x0040 - 0x0020)
struct FResourceSpawnData : public FTableRowSequencedBase
{
	int                                                AbsoluteMinPopulationCount;                               // 0x0020(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MinPopulation;                                            // 0x0024(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              MaxPopulation;                                            // 0x0028(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              StartingPopulation;                                       // 0x002C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              SpawnRateAtMinPopulation;                                 // 0x0030(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              SpawnRateAtMaxPopulation;                                 // 0x0034(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bSpawnDuringNight;                                        // 0x0038(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               bSpawnDuringDay;                                          // 0x0039(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x6];                                       // 0x003A(0x0006) MISSED OFFSET
};

// ScriptStruct Otherlands.ResourceBaseData
// 0x0018 (0x0038 - 0x0020)
struct FResourceBaseData : public FTableRowSequencedBase
{
	struct FName                                       ResourceHarvestId;                                        // 0x0020(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       ResourceSpawnId;                                          // 0x0028(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       ResourceDisplayId;                                        // 0x0030(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PlayerSummary
// 0x0028
struct FPlayerSummary
{
	struct FString                                     UniqueSaveId;                                             // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     CharacterName;                                            // 0x0010(0x0010) (ZeroConstructor)
	int                                                FactionId;                                                // 0x0020(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.GameSummary
// 0x0010
struct FGameSummary
{
	TArray<struct FPlayerSummary>                      Players;                                                  // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.RemoteCommandResponse
// 0x0020
struct FRemoteCommandResponse
{
	struct FString                                     ErrorMessage;                                             // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     SuccessMessage;                                           // 0x0010(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.MainGamePacket
// 0x0001
struct FMainGamePacket
{
	unsigned char                                      UnknownData00[0x1];                                       // 0x0000(0x0001) MISSED OFFSET
};

// ScriptStruct Otherlands.MaterialSwapParameterFactionValue
// 0x0020
struct FMaterialSwapParameterFactionValue
{
	struct FLinearColor                                Vector;                                                   // 0x0000(0x0010) (Edit, DisableEditOnInstance, IsPlainOldData)
	float                                              Scalar;                                                   // 0x0010(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	class UTexture2D*                                  Texture;                                                  // 0x0018(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MaterialSwapParameterFaction
// 0x0068
struct FMaterialSwapParameterFaction
{
	struct FName                                       Parameter;                                                // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FMaterialSwapParameterFactionValue          Revenant;                                                 // 0x0008(0x0020) (Edit, DisableEditOnInstance)
	struct FMaterialSwapParameterFactionValue          Conclave;                                                 // 0x0028(0x0020) (Edit, DisableEditOnInstance)
	struct FMaterialSwapParameterFactionValue          Order;                                                    // 0x0048(0x0020) (Edit, DisableEditOnInstance)
};

// ScriptStruct Otherlands.MaterialSwapParameterCopy
// 0x0010
struct FMaterialSwapParameterCopy
{
	struct FName                                       Parameter;                                                // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SourceParameter;                                          // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MaterialSwapParameterSmart
// 0x0010
struct FMaterialSwapParameterSmart
{
	struct FName                                       Parameter;                                                // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       Pattern;                                                  // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MaterialSwapParameterSkin
// 0x0020
struct FMaterialSwapParameterSkin
{
	struct FName                                       SkinMultParameter;                                        // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SubcolorParameter;                                        // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       OpacityParameter;                                         // 0x0010(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SpecMultParameter;                                        // 0x0018(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MaterialSwapParameterHair
// 0x0050
struct FMaterialSwapParameterHair
{
	struct FName                                       AnisoSpecScalarParameter;                                 // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AnisotropicParameter;                                     // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ContrastParameter;                                        // 0x0010(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       OpacityParameter;                                         // 0x0018(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       RoughnessParameter;                                       // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       StandardSpecParameter;                                    // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AlbedoColorParameter;                                     // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       AnisotropicColorParameter;                                // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       FactionTintParameter;                                     // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SubSurfaceColorParameter;                                 // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MaterialSwapParameterEmissiveHair
// 0x0050
struct FMaterialSwapParameterEmissiveHair
{
	struct FName                                       EmissiveInnerFresnelPower;                                // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       EmissiveInnerFresnelBlendValue;                           // 0x0008(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       EmissiveInnerFresnelLerp;                                 // 0x0010(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       EmissiveInnerFresnelIntensity;                            // 0x0018(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       UVPanningScale;                                           // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       XPanning;                                                 // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       YPanning;                                                 // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       ScrollingScalar;                                          // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       GlowEmissive;                                             // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       TipsScalar;                                               // 0x0048(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.MaterialSwapParameters
// 0x0068 (0x0088 - 0x0020)
struct FMaterialSwapParameters : public FTableRowSequencedBase
{
	class UMaterialInterface*                          Material;                                                 // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<struct FMaterialSwapParameterFaction>       FactionParameters;                                        // 0x0028(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FMaterialSwapParameterCopy>          CopyParameters;                                           // 0x0038(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FMaterialSwapParameterSmart>         SmartParameters;                                          // 0x0048(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FMaterialSwapParameterSkin>          SkinParameters;                                           // 0x0058(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FMaterialSwapParameterHair>          HairParameters;                                           // 0x0068(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FMaterialSwapParameterEmissiveHair>  EmissiveHairParameters;                                   // 0x0078(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.MaterialProperty
// 0x0010 (0x0030 - 0x0020)
struct FMaterialProperty : public FTableRowSequencedBase
{
	struct FName                                       InternalName;                                             // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                EnumValue;                                                // 0x0028(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x002C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.TalentArchetypeInfo
// 0x0004
struct FTalentArchetypeInfo
{
	int                                                PointsSpent;                                              // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.TalentInfo
// 0x0010
struct FTalentInfo
{
	TArray<struct FTalentArchetypeInfo>                ChosenArchetypes;                                         // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Otherlands.PlaceablePlugSocketData
// 0x0008 (0x0028 - 0x0020)
struct FPlaceablePlugSocketData : public FTableRowSequencedBase
{
	int                                                AllowedSocketTypes;                                       // 0x0020(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsRequired;                                              // 0x0024(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.PlaceablePlugData
// 0x0050 (0x0070 - 0x0020)
struct FPlaceablePlugData : public FTableRowSequencedBase
{
	TEnumAsByte<EPlaceablePlugType>                    PlugType;                                                 // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class UClass*                                      PointLight;                                               // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x28];                                      // 0x0030(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.PlaceablePlugData.ForcefieldMesh
	bool                                               bAnimated;                                                // 0x0058(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0059(0x0007) MISSED OFFSET
	class UCurveFloat*                                 AnimationCurve;                                           // 0x0060(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              AnimationLength;                                          // 0x0068(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PlaceableSocketData
// 0x0010 (0x0030 - 0x0020)
struct FPlaceableSocketData : public FTableRowSequencedBase
{
	TEnumAsByte<EPlaceableSocketType>                  SocketType;                                               // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	int                                                AllowedPlugTypes;                                         // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bHasMirror;                                               // 0x0028(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bIsMirror;                                                // 0x0029(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bFactionOnly;                                             // 0x002A(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x5];                                       // 0x002B(0x0005) MISSED OFFSET
};

// ScriptStruct Otherlands.UnusableGridItemData
// 0x0018
struct FUnusableGridItemData
{
	int                                                GridMapId;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                OwnerGridMapId;                                           // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FName                                       ItemId;                                                   // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData)
	EUnusableGridFlags                                 Flags;                                                    // 0x0010(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0010(0x0003) FIX WRONG TYPE SIZE OF PREVIOUS PROPERTY
	unsigned char                                      UnknownData01[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.FrozenResourceSpawnData
// 0x0020
struct FFrozenResourceSpawnData
{
	class AResourceSpawnManager*                       SpawnManager;                                             // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	class UResourceISMC*                               ResourceComp;                                             // 0x0008(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<int>                                        FrozenIndices;                                            // 0x0010(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.PlayerHitTrackingData
// 0x0010
struct FPlayerHitTrackingData
{
	class APlayerCharacter*                            Target;                                                   // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              Timer;                                                    // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.ReckoningStageParameters
// 0x0020 (0x0040 - 0x0020)
struct FReckoningStageParameters : public FTableRowSequencedBase
{
	TEnumAsByte<EReckoningStage>                       Stage;                                                    // 0x0020(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	struct FName                                       WeatherId;                                                // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   Music;                                                    // 0x0030(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundCue*                                   Ambience;                                                 // 0x0038(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpawnBatch
// 0x0020
struct FSpawnBatch
{
	unsigned char                                      UnknownData00[0x20];                                      // 0x0000(0x0020) MISSED OFFSET
};

// ScriptStruct Otherlands.BatchEntry
// 0x000C
struct FBatchEntry
{
	unsigned char                                      UnknownData00[0xC];                                       // 0x0000(0x000C) MISSED OFFSET
};

// ScriptStruct Otherlands.ResourceDelayDespawn
// 0x0008
struct FResourceDelayDespawn
{
	int                                                ClaimedIndex;                                             // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              NotifyTime;                                               // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Otherlands.PerkSetData
// 0x0078
struct FPerkSetData
{
	struct FSecondarySkillPerkSetData                  SSPerkSetData;                                            // 0x0000(0x0068) (Edit, EditConst)
	int                                                TotalRemainingLevels;                                     // 0x0068(0x0004) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x006C(0x0004) MISSED OFFSET
	struct FName                                       PerkSetId;                                                // 0x0070(0x0008) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
};

// ScriptStruct Otherlands.ServerRegistrationResponse
// 0x0038
struct FServerRegistrationResponse
{
	bool                                               SUCCESS;                                                  // 0x0000(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FString                                     ID;                                                       // 0x0008(0x0010) (ZeroConstructor)
	struct FString                                     Shard;                                                    // 0x0018(0x0010) (ZeroConstructor)
	struct FString                                     PublicKey;                                                // 0x0028(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.ServerRegistrationData
// 0x00B0
struct FServerRegistrationData
{
	struct FString                                     ID;                                                       // 0x0000(0x0010) (ZeroConstructor)
	struct FString                                     IpOverride;                                               // 0x0010(0x0010) (ZeroConstructor)
	struct FString                                     Version;                                                  // 0x0020(0x0010) (ZeroConstructor)
	uint16_t                                           Port;                                                     // 0x0030(0x0002) (ZeroConstructor, IsPlainOldData)
	bool                                               AllowQueue;                                               // 0x0032(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x0033(0x0005) MISSED OFFSET
	struct FString                                     Key;                                                      // 0x0038(0x0010) (ZeroConstructor)
	struct FString                                     Packet;                                                   // 0x0048(0x0010) (ZeroConstructor)
	TMap<struct FString, struct FString>               Properties;                                               // 0x0058(0x0050) (ZeroConstructor)
	bool                                               Overwrite;                                                // 0x00A8(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x00A9(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.ServerTicket
// 0x0060
struct FServerTicket
{
	unsigned char                                      UnknownData00[0x60];                                      // 0x0000(0x0060) MISSED OFFSET
};

// ScriptStruct Otherlands.WanderSplineGroupData
// 0x0008 (0x0028 - 0x0020)
struct FWanderSplineGroupData : public FTableRowSequencedBase
{
	struct FName                                       Name;                                                     // 0x0020(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureFamilyReactionData
// 0x0018 (0x0038 - 0x0020)
struct FCreatureFamilyReactionData : public FTableRowSequencedBase
{
	struct FName                                       SourceFamily;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       TargetFamily;                                             // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EAIReaction>                           Reaction;                                                 // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
};

// ScriptStruct Otherlands.TempoEventValue
// 0x0008
struct FTempoEventValue
{
	TEnumAsByte<ETempoEventType>                       TempoEvent;                                               // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              ScoreMultiplier;                                          // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.TempoStateData
// 0x0028 (0x0048 - 0x0020)
struct FTempoStateData : public FTableRowSequencedBase
{
	struct FName                                       TempoChannelId;                                           // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     TempoState;                                               // 0x0028(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     FallbackTempoState;                                       // 0x0029(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ETempoTargetState>                     ThresholdTempoState;                                      // 0x002A(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x1];                                       // 0x002B(0x0001) MISSED OFFSET
	float                                              InitialStateScore;                                        // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              StateThresholdScore;                                      // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bInactivateExistingSpawns;                                // 0x0034(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0035(0x0003) MISSED OFFSET
	TArray<struct FTempoEventValue>                    EventScores;                                              // 0x0038(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

// ScriptStruct Otherlands.TempoChannelData
// 0x0010 (0x0030 - 0x0020)
struct FTempoChannelData : public FTableRowSequencedBase
{
	TEnumAsByte<ETempoChannel_CodeMap>                 TempoChannelCodeMap;                                      // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	class UBehaviorTree*                               ChannelBehavior;                                          // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.ScheduledWaveData
// 0x0010 (0x0030 - 0x0020)
struct FScheduledWaveData : public FTableRowSequencedBase
{
	int                                                MaxStrengthScore;                                         // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
	struct FName                                       SpawnEventId;                                             // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpawnEventBaseData
// 0x0008 (0x0028 - 0x0020)
struct FSpawnEventBaseData : public FTableRowSequencedBase
{
	float                                              ExpirationTime;                                           // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSpawnSpiritPortal;                                       // 0x0024(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EEventType>                            EventType;                                                // 0x0025(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0026(0x0002) MISSED OFFSET
};

// ScriptStruct Otherlands.WaveBaseData
// 0x0020 (0x0040 - 0x0020)
struct FWaveBaseData : public FTableRowSequencedBase
{
	struct FName                                       SpawnEventId;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       TriggerWaveBaseId;                                        // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpawnDelay;                                               // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpawnDelayOnTriggerWaveComplete;                          // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ExpirationTime;                                           // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bClearEventOnDestroy;                                     // 0x003C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x003D(0x0003) MISSED OFFSET
};

// ScriptStruct Otherlands.SpiritBonusData
// 0x0038 (0x0058 - 0x0020)
struct FSpiritBonusData : public FTableRowSequencedBase
{
	TEnumAsByte<ESpiritBonusType>                      SpiritBonusType;                                          // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
	int                                                IntData[0x3];                                             // 0x0024(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                FloatData[0x3];                                           // 0x0030(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FName                                       NameData[0x3];                                            // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpiritTreeData
// 0x0048 (0x0068 - 0x0020)
struct FSpiritTreeData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                RequiredRanks;                                            // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FName                                       SpiritBonusId[0x5];                                       // 0x0040(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpiritEventData
// 0x0058 (0x0078 - 0x0020)
struct FSpiritEventData : public FTableRowSequencedBase
{
	TEnumAsByte<ESpiritEventType>                      SpiritEventType;                                          // 0x0020(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0021(0x0007) MISSED OFFSET
	struct FName                                       SpiritCreatureId;                                         // 0x0028(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSpawnSpiritInSpiritRealm;                                // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bSpawnSpiritPortal;                                       // 0x0031(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x0032(0x0002) MISSED OFFSET
	float                                              SpiritPortalExpirationTime;                               // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxDuration;                                              // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
	struct FName                                       SpawnEventId;                                             // 0x0040(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bUseFactionCredit;                                        // 0x0048(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0049(0x0007) MISSED OFFSET
	struct FName                                       EventDataId;                                              // 0x0050(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       CreatureFamilyId;                                         // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                EventDataCount;                                           // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                VictoryConditionId;                                       // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                VictoryConditionCount;                                    // 0x0068(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<ESpiritEventRewardType>                SpiritRewardType;                                         // 0x006C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x3];                                       // 0x006D(0x0003) MISSED OFFSET
	struct FName                                       SpiritRewardId;                                           // 0x0070(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SpiritBaseData
// 0x0060 (0x0080 - 0x0020)
struct FSpiritBaseData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       FlavorText;                                               // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	int                                                CreatureIdInWild;                                         // 0x0050(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                CreatureIdTame;                                           // 0x0054(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SpiritEventId;                                            // 0x0058(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SpiritTreeId[0x4];                                        // 0x0060(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.CreatureMovementData
// 0x0030 (0x0050 - 0x0020)
struct FCreatureMovementData : public FTableRowSequencedBase
{
	float                                              DesiredHeading;                                           // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              VariationHeading;                                         // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              HeadingWeight;                                            // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DesiredFlank;                                             // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              VariationFlank;                                           // 0x0030(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              FlankWeight;                                              // 0x0034(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              CurrentWeight;                                            // 0x0038(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MinimumFlankDistance;                                     // 0x003C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RevaluateFlankDistance;                                   // 0x0040(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ZigZagRate;                                               // 0x0044(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ZigZagVariation;                                          // 0x0048(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.SpawnGroupId
// 0x0008
struct FSpawnGroupId
{
	struct FName                                       ID;                                                       // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// ScriptStruct Otherlands.SortableDamageTarget
// 0x0010
struct FSortableDamageTarget
{
	class UPrimitiveComponent*                         HitComponent;                                             // 0x0000(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              Distance;                                                 // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.PlayerAbilityDisplayData
// 0x0058 (0x0078 - 0x0020)
struct FPlayerAbilityDisplayData : public FTableRowSequencedBase
{
	struct FText                                       DisplayName;                                              // 0x0020(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0038(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0050(0x0028) UNKNOWN PROPERTY: SoftObjectProperty Otherlands.PlayerAbilityDisplayData.Icon
};

// ScriptStruct Otherlands.StoredPetData
// 0x0010
struct FStoredPetData
{
	TArray<struct FSummonCollectionPersonal>           FavoritePets;                                             // 0x0000(0x0010) (ZeroConstructor)
};

// ScriptStruct Otherlands.TickerItem
// 0x0040
struct FTickerItem
{
	struct FName                                       ItemId;                                                   // 0x0000(0x0008) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	int                                                Count;                                                    // 0x0008(0x0004) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	struct FText                                       Text;                                                     // 0x0010(0x0018) (Edit, EditConst)
	struct FLinearColor                                Color;                                                    // 0x0028(0x0010) (Edit, EditConst, IsPlainOldData)
	float                                              Time;                                                     // 0x0038(0x0004) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x003C(0x0004) MISSED OFFSET
};

// ScriptStruct Otherlands.WanderResult
// 0x0034
struct FWanderResult
{
	struct FVector                                     WanderAnchor;                                             // 0x0000(0x000C) (IsPlainOldData)
	float                                              Radius;                                                   // 0x000C(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                CrossedKey;                                               // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FWanderState                                State;                                                    // 0x0014(0x0020)
};

// ScriptStruct Otherlands.EventLogData
// 0x0040 (0x0060 - 0x0020)
struct FEventLogData : public FTableRowSequencedBase
{
	struct FName                                       EventLogName;                                             // 0x0020(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FText                                       FormatText;                                               // 0x0028(0x0018) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	EEventLogType                                      Type;                                                     // 0x0040(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bChatAnnouncement;                                        // 0x0041(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bPersist;                                                 // 0x0042(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x5];                                       // 0x0043(0x0005) MISSED OFFSET
	struct FName                                       ViewPermissionIdOverride;                                 // 0x0048(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TArray<EEventLogParameterType>                     ParameterTypes;                                           // 0x0050(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
