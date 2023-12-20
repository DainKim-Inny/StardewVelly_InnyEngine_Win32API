#pragma once
#include <cmath>

namespace in
{
#define PI 3.141592f

	class SetVector
	{
	public:
		static SetVector One;
		static SetVector Zero;
		static SetVector Right;
		static SetVector Left;
		static SetVector Up;
		static SetVector Down;

		float x;
		float y;

		SetVector()
			: x(0.0f)
			, y(0.0f)
		{

		}

		SetVector(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}

		SetVector operator+(SetVector other)
		{
			return SetVector(x + other.x, y + other.y);
		}

		SetVector operator-(SetVector other)
		{
			return SetVector(x - other.x, y - other.y);
		}

		SetVector operator/(float value)
		{
			return SetVector(x / value, y / value);
		}

		SetVector operator*(SetVector other)
		{
			return SetVector(x * other.x, y * other.y);
		}

		SetVector operator*(float value)
		{
			return SetVector(x * value, y * value);
		}

		SetVector operator+=(SetVector other)
		{
			x += other.x;
			y += other.y;
		}

		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()  // 피타고라스 정리에 따른 길이 구하기
		{
			return sqrtf((x * x) + (y * y));
		}

		SetVector normalize()
		{
			float len = length();
			x /= len;
			y /= len;

			return *this;
		}

		SetVector Rotate(SetVector vector, float degree)
		{
			float radian = (degree / 100.f) * PI;
			vector.normalize();
			float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
			float y = cosf(radian) * vector.x + sinf(radian) * vector.y;

			return SetVector(x, y);
		}

		float Dot(SetVector& v1, SetVector v2)
		{
			return (v1.x * v2.x) + (v1.y * v2.y);
		}

		float Cross(SetVector v1, SetVector v2)
		{
			return (v1.x * v2.y) - (v1.y * v2.x);
		}
	};
}