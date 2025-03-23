#include "PlayScene.h"

#include <wchar.h>
#include <stdlib.h>

#include "UnionList.h"
#include "ConsoleRenderer.h"
#include "Player.h"
#include "Types.h"

Player* player = NULL;
List* bullet_list = NULL;

void InitializePlayScene()
{
	player = CreatePlayer();
	bullet_list = CreateList(BULLET);
	SetBulletList(bullet_list);
}

void UpdatePlayScene()
{
	UpdatePlayer(player);
	
	Node* previous_node = NULL;
	Node* current_node = bullet_list->head;
	while (current_node != NULL)
	{
		UpdateBullet(&current_node->data.bullet);
		if (current_node->data.bullet.timer < 0.0f)
		{
			current_node = RemoveNode(bullet_list, previous_node, current_node);
		}
		else
		{
			previous_node = current_node;
			current_node = current_node->next;
		}
	}
}

void RenderPlayScene()
{
	ScreenDrawString(ScreenWidth() / 2 - 2, ScreenHeight() / 2 - 1, L"play", FG_RED);

	RenderPlayer(player);

	Node* current_node = bullet_list->head;
	while (current_node != NULL)
	{
		RenderBullet(&current_node->data.bullet);

		current_node = current_node->next;
	}

	ScreenDrawString(ScreenWidth() / 2 - 8, ScreenHeight() / 2 + 5, L"press A to fire", FG_WHITE);

	ScreenDrawString(ScreenWidth() / 2 - 12, ScreenHeight() / 2 + 9, L"press space to countinue", FG_PINK);

	//ScreenDrawString(0, 0, L"   ▁▁▁", FG_RED);
	//ScreenDrawString(0, 1, L"    █", FG_RED);
	//ScreenDrawString(0, 2, L"  ▅▅█▅▃▂▁", FG_RED);
	//ScreenDrawString(0, 2, L"▅", FG_SKY);
	//ScreenDrawString(1, 2, L"▅", FG_GRAY);
	//ScreenDrawString(0, 3, L"    █", FG_RED);
	//ScreenDrawString(0, 4, L"   ▔▔▔", FG_RED);
}

void ReleasePlayScene()
{
	if (bullet_list != NULL)
	{
		DeleteList(bullet_list);

		bullet_list = NULL;
	}

	DeletePlayer(&player);
}