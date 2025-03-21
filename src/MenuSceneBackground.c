#include "MenuSceneBackground.h"

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "MyTime.h"
#include "ConsoleRenderer.h"
#include "UnionList.h"
#include "Global.h"
#include "Vector2.h"

void CreateMenuSceneBackground(MenuSceneBackground* msbg)
{
	msbg->id = GenerateID();
	msbg->position.x = (float)ScreenWidth();
	msbg->position.y = (float)(rand() % (ScreenHeight() + 1));
	msbg->direction.x = -1.0f;
	msbg->direction.y = 0.0f;
	msbg->speed = 20.0f;
	msbg->acceleration = 0.0f;
	msbg->indicator = 0.0f;
	wmemcpy_s(msbg->shape, 2, L"¡Ú", 2);
}

int UpdateMenuSceneBackground(MenuSceneBackground* msbg)
{
	msbg->acceleration = 4 * (msbg->indicator) * (msbg->indicator) + 1;
	Vector2 r = ScalarMulVector2(&msbg->direction, 3, msbg->speed, msbg->acceleration, DeltaTime());

	/*Vector2 r = ScalarMulVector2S(&msbg->direction, msbg->speed);
	r = ScalarMulVector2S(&r, msbg->acceleration);
	r = ScalarMulVector2S(&r, DeltaTime());*/

	msbg->position = AddVector2(&msbg->position, &r);
	if (msbg->indicator < 1)
	{
		msbg->indicator += DeltaTime();
	}

	if (msbg->position.x < 0)
	{
		return REMOVE_MSBG;
	}

	return OK_MSBG;
}

void RenderMenuSceneBackground(MenuSceneBackground* msbg)
{
	ScreenDrawString((int)msbg->position.x, (int)msbg->position.y, msbg->shape, FG_WHITE);
}