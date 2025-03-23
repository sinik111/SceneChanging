#include "MenuScene.h"

#include <stdlib.h>
#include <wchar.h>

#include "ConsoleRenderer.h"
#include "MenuSceneBackground.h"
#include "UnionList.h"
#include "MyTime.h"

static wchar_t menu_data[5][25];
static List* msbg_list = NULL; // menu_scene_background_list
static float star_timer;

void InitializeMenuScene()
{
	for (int i = 0; i < 4; ++i)
	{
		wmemcpy_s(menu_data[i], 25, L"menu menu menu menu menu", 25);
	}

	wmemcpy_s(menu_data[4], 25, L"press space to countinue", 25);
	
	msbg_list = CreateList(MENU_SCENE_BACKGROUND);
	star_timer = 0.0f;
}

void UpdateMenuScene()
{
	star_timer += DeltaTime();

	if (star_timer > 0.2f)
	{
		star_timer -= 0.2f;

		MenuSceneBackground msbg;
		CreateMenuSceneBackground(&msbg);

		Insert(msbg_list, &msbg);
	}

	Node* previous_node = NULL;
	Node* current_node = msbg_list->head;
	while (current_node != NULL)
	{
		MSBGState state = UpdateMenuSceneBackground(&current_node->data.msbg);
		if (REMOVE_MSBG == state)
		{
			current_node = RemoveNode(msbg_list, previous_node, current_node);
		}
		else
		{
			previous_node = current_node;
			current_node = current_node->next;
		}
	}
}

void RenderMenuScene()
{
	Node* current_node = msbg_list->head;
	while (current_node != NULL)
	{
		RenderMenuSceneBackground(&current_node->data.msbg);
		current_node = current_node->next;
	}

	for (int i = 0; i < 4; ++i)
	{
		ScreenDrawString(ScreenWidth() / 2 - 12, ScreenHeight() / 2 - 3 + i, menu_data[i], FG_BLUE);
	}

	ScreenDrawString(ScreenWidth() / 2 - 12, ScreenHeight() / 2 + 9, menu_data[4], FG_YELLOW);
}

void ReleaseMenuScene()
{
	if (msbg_list != NULL)
	{
		DeleteList(msbg_list);

		msbg_list = NULL;
	}
}