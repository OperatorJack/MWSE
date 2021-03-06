#pragma once

#include "TES3WeatherController.h"

#include "LuaGenericEvent.h"
#include "LuaDisableableEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			class CalcSunDamageScalarEvent : public GenericEvent, public DisableableEvent<CalcSunDamageScalarEvent> {
			public:
				CalcSunDamageScalarEvent(float sunDamage);
				sol::table createEventTable();

			protected:
				float m_SunDamage;
			};
		}
	}
}