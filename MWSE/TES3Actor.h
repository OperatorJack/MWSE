#pragma once

#include "TES3Object.h"
#include "TES3Collections.h"
#include "TES3Inventory.h"

namespace TES3 {
	namespace ActorFlag {
		enum ActorFlag {
			ActiveAI = 0x4,
			Werewolf = 0x400,
			Underwater = 0x800,
			WeaponDrawn = 0x2000,
			SpellReadied = 0x4000,
			InCombat = 0x10000,
			Attacked = 0x20000,
			IsCrittable = 0x8000000,
			IdleAnim = 0x10000000
		};

		enum ActorFlagBit {
			ActiveAIBit = 2,
			WerewolfBit = 10,
			UnderwaterBit = 11,
			WeaponDrawnBit = 13,
			SpellReadiedBit = 14,
			InCombatBit = 16,
			AttackedBit = 17,
			IsCrittableBit = 27,
			IdleAnimBit = 28
		};
	}

	namespace ActorMovement {
		enum ActorMovement {
			Foreward = 0x1,
			Back = 0x2,
			Left = 0x4,
			Right = 0x8,
			TurnLeft = 0x10,
			TurnRight = 0x20,
			Walking = 0x100,
			Running = 0x200,
			Crouching = 0x400,
			Swimming = 0x800,
			Jumping = 0x1000,
			Flying = 0x2000,
			Jumped = 0x4000
		};

		enum ActorMovementBit {
			ForewardBit = 0,
			BackBit = 1,
			LeftBit = 2,
			RightBit = 3,
			TurnLeftBit = 4,
			TurnRightBit = 5,
			WalkingBit = 8,
			RunningBit = 9,
			CrouchingBit = 10,
			SwimmingBit = 11,
			JumpingBit = 12,
			FlyingBit = 13,
			JumpedBit = 14
		};
	}

	struct Actor : PhysicalObject {
		void * animationData; // 0x30
		unsigned int actorFlags; // 0x34 // See ActorFlag above.
		int cloneCount; // 0x38
		Inventory inventory; // 0x3C
		Iterator<Item> equipment; // 0x58
	};
	static_assert(sizeof(Actor) == 0x6C, "TES3::Actor failed size validation");
}