#include "Bullet.h"

#include <stdlib.h>
#include <wchar.h>

#include "ConsoleRenderer.h"
#include "Player.h"
#include "Global.h"
#include "MyTime.h"
#include "Vector2.h"

void CreateBullet(Bullet* bullet, Player* player)
{
	bullet->id = GenerateID();
	bullet->position = AddVector2(&player->position, &RightVector);
	bullet->direction = RightVector;
	bullet->speed = 100.0f;
	bullet->timer = 2.0f;
	wmemcpy_s(bullet->shape, 2, L"-", 2);
}

void UpdateBullet(Bullet* bullet)
{
	vec2 transition = ScalarMulVector2Args(&bullet->direction, 2, bullet->speed, DeltaTime());
	bullet->position = AddVector2(&bullet->position, &transition);
	bullet->timer -= DeltaTime(); // �ڵ� ���� �ǵ��� Ÿ�̸� �ð� ����.
}

void RenderBullet(Bullet* bullet)
{
	ScreenDrawString((int)bullet->position.x, (int)bullet->position.y, bullet->shape, FG_WHITE);
}

void DeleteBullet(Bullet* bullet)
{

}