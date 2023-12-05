#pragma once

namespace in
{
	class SetVector
	{
	public:
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

		static SetVector One;
		static SetVector Zero;

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
	};
}