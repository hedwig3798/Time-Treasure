#pragma once

struct Vector2
{
	float x;
	float y;

public:
	float Length()
	{
		return sqrt(x * x + y * y);
	}

	Vector2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f);

		x /= fLen;
		y /= fLen;

		return *this;
	}

	Vector2& operator=(POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	Vector2 operator+(Vector2 _vc)
	{
		return Vector2(x + _vc.x, y + _vc.y);
	}

	Vector2 operator+=(Vector2 _vOther)
	{
		x += _vOther.x;
		y += _vOther.y;
		return *this;
	}

	Vector2 operator-(Vector2 _vc)
	{
		return Vector2(x - _vc.x, y - _vc.y);
	}

	Vector2 operator*(Vector2 _vc)
	{
		return Vector2(x * _vc.x, y * _vc.y);
	}

	Vector2 operator*(int _i)
	{
		return Vector2(x * (float)_i, y * (float)_i);
	}

	Vector2 operator/(Vector2 _vc)
	{
		assert(!(0.f == _vc.x || 0.f == _vc.y));
		return Vector2(x / _vc.x, y / _vc.y);
	}

public:
	Vector2()
		: x(0.f)
		, y(0.f)
	{}

	Vector2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}

	Vector2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{}

	Vector2(POINT _pt)
		: x((float)_pt.x)
		, y((float)_pt.y)
	{

	}
};