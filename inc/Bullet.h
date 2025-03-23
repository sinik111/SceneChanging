#pragma once

#include <wchar.h>

#include "Vector2.h"

typedef struct Player Player;

typedef struct Bullet
{
	long long id;
	Vector2 position;
	Vector2 direction;
	float speed;
	float timer;
	wchar_t shape[2];
} Bullet;

void CreateBullet(Bullet* bullet, Player* player);

void UpdateBullet(Bullet* bullet);

void RenderBullet(Bullet* bullet);

void DeleteBullet(Bullet* bullet);