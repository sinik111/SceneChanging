#pragma once

#include <wchar.h>

#include "Vector2.h"

typedef struct UnionList List;

typedef struct Player
{
	long long id;
	Vector2 position;
	float x_speed;
	float y_speed;
	wchar_t shape[2];
} Player;

Player* CreatePlayer();

void UpdatePlayer(Player* player);

void RenderPlayer(Player* player);

void DeletePlayer(Player** player);

void SetBulletList(List* bullet_list);