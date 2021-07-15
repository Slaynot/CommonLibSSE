#pragma once

#include "RE/Scaleform/GMemory/GNewOverrideBase.h"
#include "RE/Scaleform/GStats/GStats.h"
#include "RE/Scaleform/GFxEvent/GFxKey.h"
#include "RE/Scaleform/GFxEvent/GFxSpecialKeysState.h"


namespace RE
{
	class GFxEvent : public GNewOverrideBase<GStatGroups::kGStat_Default_Mem>
	{
	public:
		enum class EventType
		{
			kNone,

			// Informative events sent to the player.
			kMouseMove,
			kMouseDown,
			kMouseUp,
			kMouseWheel,
			kKeyDown,
			kKeyUp,
			kSceneResize,
			kSetFocus,
			kKillFocus,

			// Action events, to be handled by user.
			kDoShowMouse,
			kDoHideMouse,
			kDoSetMouseCursor,

			kCharEvent,
			kIMEEvent
		};


		GFxEvent(EventType a_eventType = EventType::kNone) :
			GNewOverrideBase<GStatGroups::kGStat_Default_Mem>(),
			type(a_eventType)
		{}


		// members
		stl::enumeration<EventType, std::uint32_t> type;  // 0
	};
	static_assert(sizeof(GFxEvent) == 0x4);


	class GFxMouseEvent : public GFxEvent
	{
	public:
		inline GFxMouseEvent() :
			GFxEvent(),
			x(0.0),
			y(0.0),
			scrollDelta(0.0),
			button(0),
			mouseIndex(0)
		{}


		inline GFxMouseEvent(EventType a_eventType, std::uint32_t a_button, float a_x, float a_y, float a_scrollDelta = 0.0, std::uint32_t a_mouseIndex = 0) :
			GFxEvent(a_eventType),
			x(a_x),
			y(a_y),
			scrollDelta(a_scrollDelta),
			button(a_button),
			mouseIndex(a_mouseIndex)
		{}


		inline GFxMouseEvent(EventType a_eventType, std::uint32_t a_mouseIndex) :
			GFxEvent(a_eventType),
			x(0.0),
			y(0.0),
			scrollDelta(0.0),
			button(0),
			mouseIndex(a_mouseIndex)
		{}


		// members
		float		  x;			// 04
		float		  y;			// 08
		float		  scrollDelta;	// 0C
		std::uint32_t button;		// 10
		std::uint32_t mouseIndex;	// 14
	};
	static_assert(sizeof(GFxMouseEvent) == 0x18);

	class GFxKeyEvent : public GFxEvent
	{
	public:
		inline GFxKeyEvent() :
			GFxEvent(),
			keyCode(GFxKey::kVoidSymbol),
			ascii(0),
			specialKeyState(),
			keyboardIndex(0)
		{}


		inline GFxKeyEvent(EventType a_eventType, GFxKey::Code a_keyCode, std::uint32_t a_ascii, GFxSpecialKeysState a_specialKeyState, std::uint8_t a_keyboardIndex = 0) :
			GFxEvent(a_eventType),
			keyCode(a_keyCode),
			ascii(a_ascii),
			specialKeyState(a_specialKeyState),
			keyboardIndex(a_keyboardIndex)
		{}


		// members
		GFxKey::Code        keyCode;			// 04
		std::uint32_t       ascii;				// 08
		std::uint32_t       unk_0c;				// 0C
		GFxSpecialKeysState specialKeyState;	// 10
		std::uint8_t		keyboardIndex;		// 11
		std::uint8_t		pad_0c[2];			// 12
	};
	static_assert(sizeof(GFxKeyEvent) == 0x14);
}
