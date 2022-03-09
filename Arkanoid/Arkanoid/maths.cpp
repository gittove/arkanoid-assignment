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