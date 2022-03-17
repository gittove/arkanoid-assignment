#pragma once
#include "Vector2.h"
const float PI = 3.1415f;
const float TAU = 6.28318f;

float clamp (float value, float min, float max);
int sign (int value);
float absvalue (float value);
float dot(tove::Vector2 a, tove::Vector2 b);
tove::Vector2 reflect_v2 (tove::Vector2 in_dir, tove::Vector2 in_norm);