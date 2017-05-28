#pragma once

class KeyFlags
{
public:

	static bool keystate[256];
	static bool isLeftKeyPressed;
	static bool isUpKeyPressed;
	static bool isRightKeyPressed;
	static bool isDownKeyPressed;

	static bool mouseTriggerCameraLeft;
	static bool mouseTriggerCameraRight;

	static bool mouseTriggerCameraUp;
	static bool mouseTriggerCameraDown;

	static bool mouseTriggerCameraUpperLeft;
	static bool mouseTriggerCameraUpperRight;

	static bool mouseTriggerCameraLowerLeft;
	static bool mouseTriggerCameraLowerRight;

	//TODO floating camera z mouse 3
	static bool mouseCameraFloatingMode;


	static bool isPressedControl;
	static bool aMove;
};

