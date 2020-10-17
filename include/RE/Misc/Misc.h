#pragma once
#include "RE/BSCore/BSTArray.h"

namespace RE
{
	class Actor;
	template <class T>
	class NiPointer;
	class Setting;
	class TESObjectREFR;
	class TESForm;
	class InventoryEntryData;
	class PotionCreationData;
	class EffectSetting;

	void     ApplyPerkEntries(std::uint8_t a_perkEntryCode, Actor* a_perkOwner, TESForm *a_item, float *a_value);
	void	 CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refrTo);
	void	 DebugNotification(const char* a_notification, const char* a_soundToPlay = 0, bool a_cancelIfAlreadyQueued = true);
	float    GetArmorFinalRating(InventoryEntryData *a_entryData, float a_armorPerks, float a_skillMultiplier);
	void	 GetCompatibleEffects(PotionCreationData* a_potionCreationData, BSTArray<EffectSetting*>* a_compatibleEffects, bool a_unk, bool HasPurityPerk);
	Setting* GetINISetting(const char* a_name);
	bool	 LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<Actor>& a_refrOut);
	bool	 LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
	void	 PlaySound(const char* a_editorID);
}