#include "Player.h"

#include <stdlib.h>

#include "Global.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "MyTime.h"
#include "UnionList.h"
#include "Bullet.h"

List* player_bullet_list = NULL;

void Translate(Player* player);
void Fire(Player* player);

Player* CreatePlayer()
{
	Player* player = (Player*)malloc(sizeof(Player));
	if (player == NULL)
	{
		return NULL;
	}

	player->id = GenerateID();
	vec2 pos = { 0.0f, (float)ScreenHeight() / 2 };
	player->position = pos;
	player->x_speed = 40.0f;
	player->y_speed = 20.0f;
	wmemcpy_s(player->shape, 2, L"▶", 2);
	
	return player;
}

void UpdatePlayer(Player* player)
{
	Translate(player);

	if (IsKeyReleased('A'))
	{
		Fire(player);
	}
}

void RenderPlayer(Player* player)
{
	ScreenDrawString((int)player->position.x, (int)player->position.y, player->shape, FG_RED);
}

void DeletePlayer(Player** player)
{
	player_bullet_list = NULL;

	if (*player != NULL)
	{
		free(*player);

		*player = NULL;
	}
}

void SetBulletList(List* bullet_list)
{
	player_bullet_list = bullet_list;
}


// player 내에서만 쓰는 함수들

void Translate(Player* player)
{
	vec2 direction = ZeroVector;
	if (IsKeyDown(VK_UP))
	{
		direction = AddVector2(&UpVector, &direction);
	}

	if (IsKeyDown(VK_DOWN))
	{
		direction = AddVector2(&DownVector, &direction);
	}

	if (IsKeyDown(VK_RIGHT))
	{
		direction = AddVector2(&RightVector, &direction);
	}

	if (IsKeyDown(VK_LEFT))
	{
		direction = AddVector2(&LeftVector, &direction);
	}

	NormalizeVector2(&direction);

	direction.x *= player->x_speed;
	direction.y *= player->y_speed;

	vec2 transition = ScalarMulVector2(&direction, 1, DeltaTime());

	player->position = AddVector2(&player->position, &transition);
}

void Fire(Player* player)
{
	Bullet bullet;
	CreateBullet(&bullet, player);

	Insert(player_bullet_list, &bullet);
}