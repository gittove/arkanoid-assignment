#pragma once
namespace tove
{
	struct Vector2
	{
		float x{};
		float y{};

		Vector2 (const float a, const float b) : x{a}, y{b}
		{
		}

		/*~Vector2 ()
		{
			delete this;
		}*/

		Vector2 operator+(const Vector2* r)
		{
			return {
			x += r->x,
			y += r->y };
		}

		Vector2 operator-(const Vector2* r)
		{
			return {
			x -= r->x,
			y -= r->y };
		}

		Vector2 operator=(const Vector2* r)
		{
			return {
			x = r->x,
			y = r->y };
		}

		Vector2 operator*(const Vector2* scalar)
		{
			return {
			x * scalar->x,
			y * scalar->y };
		}

		bool operator==(const Vector2* r)
		{
			if (x == r->x && y == r->y)
				return true;

			return false;
		}
	};
	struct Vector2Int
	{
		int x{};
		int y{};

		Vector2Int (int a, int b)
		{
			x = a;
			y = b;
		}

		/*~Vector2Int ()
		{
			delete this;
		}*/

		Vector2Int operator+(Vector2Int* r)
		{
			return {
			x += r->x,
			y += r->y };
		}

		Vector2Int operator=(Vector2Int* r)
		{
			return {
			x = r->x,
			y = r->y };
		}

		Vector2Int operator*(int scalar)
		{
			return{
			x * scalar,
			y * scalar };
		}

		bool operator==(const Vector2Int* r)
		{
			if (x == r->x && y == r->y)
				return true;

			return false;
		}
	};
}