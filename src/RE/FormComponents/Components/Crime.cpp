#include "RE/FormComponents/Components/Crime.h"


namespace RE
{
	Crime* Crime::Ctor(CRIME_TYPE a_crimeType, RefHandle a_victim, RefHandle a_criminal,
		TESBoundObject* a_stolenItem, std::uint32_t a_containerValue, TESForm* a_itemOwner)
	{
		using func_t = decltype(&Crime::Ctor);
		REL::Relocation<func_t> func{ REL::ID(41434) };
		return func(this, a_crimeType, a_victim, a_criminal, a_stolenItem, a_containerValue, a_itemOwner);
	}

	// Returns true if all witnesses are removed within time limit
	bool Crime::EvaluateCrime()
	{
		using func_t = decltype(&Crime::EvaluateCrime);
		REL::Relocation<func_t> func{ REL::ID(41440) };
		return func(this);
	}

	bool Crime::IsViolentCrime()
	{
		return (this->crimeType == CRIME_TYPE::kAttack || this->crimeType == CRIME_TYPE::kMurder);
	}

	std::uint32_t Crime::GetStolenItemValue()
	{
		using func_t = decltype(&Crime::GetStolenItemValue);
		REL::Relocation<func_t> func{ REL::ID(41444) };
		return func(this);
	}

}
