#include "LuaMagicCastedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MagicSourceInstance.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		namespace event {
			MagicCastedEvent::MagicCastedEvent(TES3::MagicSourceInstance* magicInstance) :
				GenericEvent("magicCasted"),
				m_MagicSourceInstance(magicInstance)
			{

			}

			sol::table MagicCastedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["caster"] = makeLuaObject(m_MagicSourceInstance->caster);
				eventData["target"] = makeLuaObject(m_MagicSourceInstance->target);
				eventData["source"] = makeLuaObject(m_MagicSourceInstance->sourceCombo.source.asGeneric);
				eventData["sourceInstance"] = makeLuaObject(m_MagicSourceInstance);

				return eventData;
			}

			sol::object MagicCastedEvent::getEventOptions() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table options = state.create_table();

				options["filter"] = makeLuaObject(m_MagicSourceInstance->sourceCombo.source.asGeneric);
				return options;
			}

			bool MagicCastedEvent::m_EventEnabled = false;
		}
	}
}
