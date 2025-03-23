//RenderingLayer.h
//
//#pragma once
//
//#include <wchar.h>
//
//#include "Vector2.h"
//#include "Types.h"
//
//#define MAX_X 120
//#define MAX_Y 30
//
//typedef struct CharUnit
//{
//	wchar_t shape;
//	WORD attribute;
//} CharUnit;
//
//typedef struct StringUnit
//{
//	wchar_t string[MAX_X + 1];
//	WORD attribute;
//} StringUnit;
//
//void InitializeRenderingLayer();
//
//void FillLayer(const Vector2* position, const wchar_t* c, WORD attribute, Layer layer);
//
//void RenderLayers();
//
//void ResetLayers();
//
//void ReleaseRenderingLayer();
//
//
//
//#include "RenderingLayer.h"
//
//#include <stdlib.h>
//#include <memory.h>
//#include <wchar.h>
//
//#include "Types.h"
//#include "ConsoleRenderer.h"
//
//StringUnit* background_layer = NULL;
//CharUnit* game_object_layer = NULL;
//CharUnit* ui_layer = NULL;
//
//void InitializeRenderingLayer()
//{
//	background_layer = (StringUnit*)malloc(sizeof(StringUnit) * MAX_Y);
//	if (background_layer != NULL)
//	{
//		memset(background_layer, 0, sizeof(StringUnit) * MAX_Y);
//	}
//
//	game_object_layer = (CharUnit*)malloc(sizeof(CharUnit) * MAX_X * MAX_Y);
//	if (game_object_layer != NULL)
//	{
//		memset(game_object_layer, 0, sizeof(CharUnit) * MAX_X * MAX_Y);
//	}
//
//	ui_layer = (CharUnit*)malloc(sizeof(CharUnit) * MAX_X * MAX_Y);
//	if (ui_layer != NULL)
//	{
//		memset(ui_layer, 0, sizeof(CharUnit) * MAX_X * MAX_Y);
//	}
//}
//
//void FillLayer(const Vector2* position, const wchar_t* c, WORD attribute, Layer layer)
//{
//	if (position->x < 0 || position->y < 0 || position->x > MAX_X - 1 || position->y > MAX_Y - 1)
//	{
//		return;
//	}
//
//	int index = 0;
//	switch (layer)
//	{
//	case BACKGROUND:
//		index = (int)position->y;
//		background_layer[index].attribute = attribute;
//		wmemcpy_s(background_layer[index].string, MAX_X, c, MAX_X);
//		break;
//
//	case GAMEOBJECT:
//		index = (int)position->y * MAX_X + (int)position->x;
//		game_object_layer[index].attribute = attribute;
//		game_object_layer[index].shape = *c;
//		break;
//
//	case UI:
//		index = (int)position->y * MAX_X + (int)position->x;
//		ui_layer[index].attribute = attribute;
//		ui_layer[index].shape = *c;
//		break;
//	}
//}
//
//void RenderLayers()
//{
//	for (int i = 0; i < MAX_Y; ++i) // background_layer
//	{
//		ScreenDrawString(0, i, background_layer[i].string, background_layer[i].attribute);
//	}
//
//	for (int i = 0; i < MAX_X * MAX_Y; ++i) // game_object_layer
//	{
//		if (game_object_layer[i].shape != 0)
//		{
//			ScreenDrawChar(i % MAX_X, i / MAX_X, game_object_layer[i].shape, game_object_layer[i].attribute);
//		}
//	}
//
//	for (int i = 0; i < MAX_X * MAX_Y; ++i) // ui_layer
//	{
//		if (ui_layer[i].shape != 0)
//		{
//			ScreenDrawChar(i % MAX_X, i / MAX_X, ui_layer[i].shape, ui_layer[i].attribute);
//		}
//	}
//}
//
//void ResetLayers()
//{
//	memset(background_layer, 0, sizeof(StringUnit) * MAX_Y);
//	memset(game_object_layer, 0, sizeof(CharUnit) * MAX_X * MAX_Y);
//	memset(ui_layer, 0, sizeof(CharUnit) * MAX_X * MAX_Y);
//}
//
//void ReleaseRenderingLayer()
//{
//	if (ui_layer != NULL)
//	{
//		free(ui_layer);
//
//		ui_layer = NULL;
//	}
//
//	if (game_object_layer != NULL)
//	{
//		free(game_object_layer);
//
//		game_object_layer = NULL;
//	}
//
//	if (background_layer != NULL)
//	{
//		free(background_layer);
//
//		background_layer = NULL;
//	}
//}