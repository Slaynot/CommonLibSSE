#include "RE/BSDevices/PlayerControls.h"

#include "RE/BSDevices/PlayerInputHandler/HeldStateHandler/ActivateHandler.h"
#include "RE/BSDevices/PlayerInputHandler/PlayerInputHandler.h"


namespace RE
{
	PlayerControls::PlayerControls()
	{
		Ctor();
	}


	PlayerControls* PlayerControls::GetSingleton()
	{
		REL::Relocation<PlayerControls**> singleton{ Offset::PlayerControls::Singleton };
		return *singleton;
	}


	PlayerControls* PlayerControls::Ctor()
	{
		using func_t = decltype(&PlayerControls::Ctor);
		REL::Relocation<func_t> func{ Offset::PlayerControls::Ctor };
		return func(this);
	}
}
