#include "RE/Scaleform/GFxResource/GFxResource.h"


namespace RE
{
	GFxResource::GFxResource() :
		_refCount(1),
		_pad14(0),
		_lib(nullptr)
	{}


	GFxResource::~GFxResource()
	{}


	GFxResourceKey GFxResource::GetKey()
	{
		return GFxResourceKey();
	}


	std::uint32_t GFxResource::GetResourceTypeCode() const
	{
		return MakeTypeCode(ResourceType::kNone);
	}


	GFxResourceReport* GFxResource::GetResourceReport()
	{
		return nullptr;
	}


	void GFxResource::AddRef()
	{
		++_refCount;
	}


	bool GFxResource::AddRef_NotZero()
	{
		if (_refCount != 0) {
			++_refCount;
			return true;
		} else {
			return false;
		}
	}


	std::int32_t GFxResource::GetRefCount() const
	{
		return _refCount.value;
	}


	void GFxResource::SetOwnerResourceLib(GFxResourceLibBase* a_lib)
	{
		assert((_lib == nullptr) || (a_lib == nullptr));
		_lib = a_lib;
	}


	GFxResource::ResourceType GFxResource::GetResourceType() const
	{
		return (static_cast<ResourceType>(GetResourceTypeCode()) & ResourceType::kTypeCode_Mask) >> ResourceType::kTypeCode_Shift;
	}


	GFxResource::ResourceUse GFxResource::GetResourceUse() const
	{
		return static_cast<ResourceUse>(GetResourceTypeCode()) & ResourceUse::kTypeCode_Mask;
	}


	std::uint32_t GFxResource::MakeTypeCode(ResourceType a_resourceType, ResourceUse a_resourceUse)
	{
		return to_underlying(static_cast<ResourceUse>(a_resourceType << ResourceType::kTypeCode_Shift) | a_resourceUse);
	}
}
