#pragma once

typedef int BOOL;
typedef short SHORT;
typedef unsigned short WORD;

typedef enum DataType
{
	MENU_SCENE_BACKGROUND,
	PLAYER,
	BULLET
} DataType;

typedef enum Layer
{
	BACKGROUND,
	GAMEOBJECT,
	UI
} Layer;