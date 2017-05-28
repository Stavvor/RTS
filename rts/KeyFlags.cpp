#include "stdafx.h"
#include "KeyFlags.h"

bool KeyFlags::keystate[256] = { false };
bool KeyFlags::isLeftKeyPressed= false;
bool KeyFlags::isUpKeyPressed = false;
bool KeyFlags::isRightKeyPressed = false;
bool KeyFlags::isDownKeyPressed = false;
bool KeyFlags::mouseTriggerCameraRight = false;
bool KeyFlags::mouseTriggerCameraLeft = false;
bool KeyFlags::mouseTriggerCameraUp = false;
bool KeyFlags::mouseTriggerCameraDown = false;
bool KeyFlags::mouseTriggerCameraUpperLeft = false;
bool KeyFlags::mouseTriggerCameraUpperRight = false;
bool KeyFlags::mouseTriggerCameraLowerLeft = false;
bool KeyFlags::mouseTriggerCameraLowerRight = false;
bool KeyFlags::mouseCameraFloatingMode = false;
bool KeyFlags::isPressedControl = false;
bool KeyFlags::aMove = false;

