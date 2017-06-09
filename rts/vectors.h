#pragma once
struct vec3 {
	float x, y, z;
};

struct vec2
{
	vec2(float x, float z)
		: x(x),
		  z(z)
	{
	}

	float x, z;
};
