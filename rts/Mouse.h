#pragma once
class Mouse
{

public:

	Mouse();
	~Mouse();

	static vec3 destStart;
	static vec3 destEnd;
	static vec3 moveTo;
	static mousePos mouseLeftClickPos_start;
	static mousePos mouseLeftClickPos_end;
	static mousePos mouseLeftUpPos_start;
	static mousePos mouseLeftUpPos_end;
};

