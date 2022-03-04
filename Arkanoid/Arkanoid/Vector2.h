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

		~Vector2 ()
		{
			delete this;
		}

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
}