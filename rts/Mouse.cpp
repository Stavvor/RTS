#include "stdafx.h"
#include "Mouse.h"


Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

vec3 Mouse::destStart;
vec3 Mouse::destEnd;
vec3 Mouse::moveTo;
mousePos Mouse::mouseLeftClickPos_start;
mousePos Mouse::mouseLeftClickPos_end;
mousePos Mouse::mouseLeftUpPos_start;
mousePos Mouse::mouseLeftUpPos_end;