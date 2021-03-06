#include "TES3InputController.h"

#define TES3_InputController_readKeyState 0x4065E0
#define TES3_InputController_keybindTest 0x406F40

namespace TES3 {
	void InputController::readKeyState() {
		reinterpret_cast<void(__thiscall *)(InputController*)>(TES3_InputController_readKeyState)(this);
	}

	bool InputController::keybindTest(unsigned int keyBind, unsigned int transition) {
		return reinterpret_cast<int(__thiscall *)(InputController*, unsigned int, unsigned int)>(TES3_InputController_keybindTest)(this, keyBind, transition) == 1;
	}

	bool InputController::isKeyDown(unsigned char keyCode) {
		return keyboardState[keyCode] & 0x80;
	}

	bool InputController::isKeyPressedThisFrame(unsigned char keyCode) {
		return (keyboardState[keyCode] & 0x80) && !(previousKeyboardState[keyCode] & 0x80);
	}

	bool InputController::isKeyReleasedThisFrame(unsigned char keyCode) {
		return !(keyboardState[keyCode] & 0x80) && (previousKeyboardState[keyCode] & 0x80);
	}

	bool InputController::isMouseButtonDown(unsigned char button) {
		return mouseState.rgbButtons[button] & 0x80;
	}

	bool InputController::isMouseButtonPressedThisFrame(unsigned char button) {
		return (mouseState.rgbButtons[button] & 0x80) && !(previousMouseState.rgbButtons[button] & 0x80);
	}

	bool InputController::isMouseButtonReleasedThisFrame(unsigned char button) {
		return !(mouseState.rgbButtons[button] & 0x80) && (previousMouseState.rgbButtons[button] & 0x80);
	}
}
