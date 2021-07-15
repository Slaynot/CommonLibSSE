#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSCore/BSTArray.h"


namespace RE
{
	class TESBoundObject;
	class TESFaction;
	class TESForm;


	struct CRIME_TYPES
	{
		enum CRIME_TYPE : std::uint32_t
		{
			kNone = static_cast<std::underlying_type_t<CRIME_TYPE>>(-1),
			kSteal = 0,
			kPickpocket = 1,
			kTrespass = 2,
			kAttack = 3,
			kMurder = 4,
			kEscape = 5,
			kUnused = 6,

			kTotal = 7
		};
	};
	using CRIME_TYPE = CRIME_TYPES::CRIME_TYPE;


	struct Crime
	{
	public:
		bool EvaluateCrime();
		bool IsViolentCrime();
		std::uint32_t GetStolenItemValue();

		// members
		std::uint32_t										   witnessCount;	   // 00
		stl::enumeration<CRIME_TYPE, std::uint32_t>			   crimeType;		   // 04
		RefHandle											   victim;			   // 08
		RefHandle											   criminal;		   // 0C
		bool												   unk10;			   // 10
		std::uint8_t										   pad11;			   // 11
		std::uint16_t										   pad12;			   // 12
		std::uint32_t										   pad14;			   // 14
		TESBoundObject*										   stolenItem;		   // 18
		std::uint32_t										   containerValue;	   // 20
		std::uint32_t										   pad24;			   // 24
		BSTArray<ActorHandle>								   actorsKnowOfCrime;  // 28
		TESForm*											   itemOwner;		   // 40
		std::uint32_t										   crimeId;			   // 48 ProcessLists + 0x18
		bool												   guardsAware;		   // 4C
		std::uint8_t										   pad4D;			   // 4D
		std::uint16_t										   pad4E;			   // 4E
		std::uint32_t										   calendarDate;	   // 50 (day | (month | year << 4) << 9)
		float												   timeStampSec;	   // 54 from 517597
		std::uint32_t										   goldValue;		   // 58
		std::uint32_t										   pad5C;			   // 5C
		TESFaction*											   crimeFaction;	   // 60
		bool												   crimeResolved;	   // 68 Witness timer ran out or player resisted arrest
		std::uint8_t										   unk69;			   // 69
		std::uint16_t										   unk6A;			   // 6A CrimeCommentNumber
		mutable BSReadWriteLock								   lock;			   // 6C
		std::uint32_t										   pad74;			   // 74

	private:
		Crime* Ctor(CRIME_TYPE a_crimeType, RefHandle a_victim, RefHandle a_criminal,
			TESBoundObject* a_stolenItem, std::uint32_t a_containerValue, TESForm* a_itemOwner);
	};
	static_assert(sizeof(Crime) == 0x78);
}
