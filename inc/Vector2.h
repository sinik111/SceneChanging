#pragma once

typedef struct Vector2
{
	float x;
	float y;
} Vector2;

typedef Vector2 vec2;

extern const Vector2 UpVector;
extern const Vector2 DownVector;
extern const Vector2 RightVector;
extern const Vector2 LeftVector;
extern const Vector2 ZeroVector;

float GetVecter2Length(const Vector2* v_in);

void NormalizeVector2(Vector2* v_out);

// v1_in + v2_in
Vector2 AddVector2(const Vector2* v1_in, const Vector2* v2_in);

// v1_in - v2_in
Vector2 SubVector2(const Vector2* v1_in, const Vector2* v2_in);

// count에 가변인자 개수, 가변인자에 float 사용
Vector2 ScalarMulVector2(const Vector2* v_in, int count, ...);

// v1_in <-- v2_in 방향 벡터
Vector2 MakeDirectionVector2(const Vector2* v1_in, const Vector2* v2_in);