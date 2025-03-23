#pragma once

#include <wchar.h>

#include "Vector2.h"

typedef enum MenuSceneBackgroundState
{
	OK_MSBG,
	REMOVE_MSBG
} MSBGState;

typedef struct MenuSceneBackground
{
	long long id;
	Vector2 position;
	Vector2 direction;
	float speed;
	float acceleration;
	float indicator;
	wchar_t shape[2];
} MenuSceneBackground;

void CreateMenuSceneBackground(MenuSceneBackground* msbg);

int UpdateMenuSceneBackground(MenuSceneBackground* msbg);

void RenderMenuSceneBackground(MenuSceneBackground* msbg);