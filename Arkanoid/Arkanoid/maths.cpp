#include "maths.h"

float clamp (float value, float min, float max)
{
	if (value < min)
	{
		return min;
	}

	if (value > max)
	{
		return max;
	}

	return value;
}
int sign (int value)
{
	if (value < 0) 
		return 0;

	return 1;
}

float absvalue (float value)
{
	if (value < 0) 
		return -value;

	return value;
}


float dot(tove::Vector2 a, tove::Vector2 b)
{
	return (a.x * b.x) + (a.y * b.y);
}