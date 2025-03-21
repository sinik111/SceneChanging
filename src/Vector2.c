#include "Vector2.h"

#include <math.h>
#include <stdarg.h>

const Vector2 UpVector = { 0.0f, -1.0f };
const Vector2 DownVector = { 0.0f, 1.0f };
const Vector2 RightVector = { 1.0f, 0.0f };
const Vector2 LeftVector = { -1.0f, 0.0f };
const Vector2 ZeroVector = { 0.0f, 0.0f };

float GetVecter2Length(const Vector2* v_in)
{
	if (v_in != NULL)
	{
		return sqrtf(v_in->x * v_in->x + v_in->y * v_in->y);
	}

	return 0.0f;
}

void NormalizeVector2(Vector2* v_out)
{
	if (v_out != NULL)
	{
		float length = GetVecter2Length(v_out);
		if (length > 0.0f)
		{
			v_out->x /= length;
			v_out->y /= length;
		}
	}
}

// v1_in + v2_in
Vector2 AddVector2(const Vector2* v1_in, const Vector2* v2_in)
{
	Vector2 v = { v1_in->x + v2_in->x, v1_in->y + v2_in->y };

	return v;
}

// v1_in - v2_in
Vector2 SubVector2(const Vector2* v1_in, const Vector2* v2_in)
{
	Vector2 v = { v1_in->x - v2_in->x, v1_in->y - v2_in->y };

	return v;
}

// count에 가변인자 개수, 가변인자에 float 사용
Vector2 ScalarMulVector2(const Vector2* v_in, int count, ...)
{
	Vector2 v = { v_in->x, v_in->y };

	va_list args;

	va_start(args, count);

	for (int i = 0; i < count; ++i)
	{
		// 가변인자는 float도 double로 받기 때문에
		// double로 뽑고 float로 캐스팅해서 사용함
		float scalar = (float)va_arg(args, double); 
		v.x *= scalar;
		v.y *= scalar;
	}

	va_end(args);

	return v;
}

// v1_in <-- v2_in 방향 벡터
Vector2 MakeDirectionVector2(const Vector2* v1_in, const Vector2* v2_in)
{
	Vector2 direction = SubVector2(v1_in, v2_in);

	NormalizeVector2(&direction);

	return direction;
}

