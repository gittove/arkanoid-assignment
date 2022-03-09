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

		Vector2 operator=(const Vector2* r)
		{
			return {
			x = r->x,
			y = r->y };
		}

		Vector2 operator*(const float scalar)
		{
			return {
			x * scalar,
			y * scalar };
		}

		bool operator==(const Vector2* r)
		{
			if (x == r->x && y == r->y)
				return true;

			return false;
		}

		/*float dot (Vector2* l, Vector2* r)
		{
			return (l->x * r->x) + (l->y * r->y);
		}

		Vector2 normalized ()
		{
			float m = sqrt (x * x + y * y);
			float tempx = abs (x) / m;
			float tempy = abs (y) / m;

			return {tempx, tempy};
		}*/
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

		/*float dot (Vector2Int* r)
		{
			return (x * r->x) + (y * r->y);
		}
		Vector2Int normalized ()
		{
			float m = sqrt (x * x + y * y);
			int tempx = abs (x) / m;
			int tempy = abs (y) / m;
			return Vector2Int (tempx, tempy);
		}*/
	};
}