
#pragma once


namespace TestEngine::Math
{
	struct Vector2
	{
		float x;
		float y;

		Vector2()
			: x(0.f), y(0.f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x), y(_y)
		{

		}

		static Vector2 Zero;
		static Vector2 One;

		Vector2 operator+(Vector2 other) { return Vector2(x + other.x, y + other.y); }
		Vector2 operator-(Vector2 other) { return Vector2(x - other.x, y - other.y); }
		Vector2 operator*(float value) { return Vector2(x * value, y * value); }
		Vector2 operator/(float value) { return Vector2(x / value, y / value); }
	};
}
