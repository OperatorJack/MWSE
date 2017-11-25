/************************************************************************
	
	xLongToFloats.cpp - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
	
**************************************************************************/

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xLongToFloats : mwse::InstructionInterface_t
	{
	public:
		xLongToFloats();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xLongToFloatsOpcode = 0x3923;
	static xLongToFloats xLongToFloatsInstance;

	xLongToFloats::xLongToFloats() : mwse::InstructionInterface_t(xLongToFloatsOpcode) {}

	void xLongToFloats::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xLongToFloats::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() != 1) {
			return 0;
		}

		mwLong_t param = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushFloat((param >> 16) + 0x10000);
		mwse::Stack::getInstance().pushFloat(param & 0xFFFF);

		return 0.0;
	}
}