#include "RE/BSHavok/hkpMaterial.h"


namespace RE
{
	auto hkpMaterial::GetResponseType() const
		-> ResponseType
	{
		return *responseType;
	}


	void hkpMaterial::SetResponseType(ResponseType a_type)
	{
		responseType = a_type;
	}
}
