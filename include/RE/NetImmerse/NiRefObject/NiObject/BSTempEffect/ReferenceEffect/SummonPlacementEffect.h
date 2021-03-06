#pragma once

#include "RE/Animation/IAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder/SimpleAnimationGraphManagerHolder.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/NetImmerse/Components/AttachTechniqueInput/RefAttachTechniqueInput.h"
#include "RE/NetImmerse/NiPoint3.h"
#include "RE/NetImmerse/NiRefObject/NiObject/BSTempEffect/ReferenceEffect/ReferenceEffect.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BGSArtObject;
	class BGSArtObjectCloneTask;
	class NiAVObject;
	struct BSAnimationGraphEvent;


	class SummonPlacementEffect :
		public ReferenceEffect,						// 00
		public SimpleAnimationGraphManagerHolder,	// 48
		public BSTEventSink<BSAnimationGraphEvent>	// 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_SummonPlacementEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_SummonPlacementEffect;


		virtual ~SummonPlacementEffect();  // 00

		// override (ReferenceEffect)
		virtual const NiRTTI*	 GetRTTI() const override;							 // 02
		virtual bool			 Update(float a_arg1) override;						 // 28
		virtual TEMP_EFFECT_TYPE GetType() const override;							 // 2C - { return kMagicSummon; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;		 // 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;		 // 2E
		virtual void			 FinishLoadGame(BGSLoadGameBuffer* a_buf) override;	 // 2F
		virtual void			 Unk_36(void) override;								 // 36


		// members
		BGSArtObject*						   effectArt;  // 68
		NiPoint3							   location;   // 70
		std::uint32_t						   pad7C;	   // 7C
		NiPointer<NiAVObject>				   effect3D;   // 80
		std::uint64_t						   unk88;	   // 88
		BSTSmartPointer<BGSArtObjectCloneTask> cloneTask;  // 90
		std::uint8_t						   unk98;	   // 98
	};
	static_assert(sizeof(SummonPlacementEffect) == 0xA0);
}
