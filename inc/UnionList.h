#pragma once

#include "Types.h"
#include "MenuSceneBackground.h"
#include "Bullet.h"

typedef struct UnionNode
{
	union
	{
		long long id;
		MenuSceneBackground msbg;
		Bullet bullet;
	} data;
	struct UnionNode* next;
} Node;

typedef struct UnionList
{
	Node* head;
	Node* tail;
	DataType type;
} List;

List* CreateList(DataType type);

void DeleteList(List* list);

void Insert(List* list, void* data);

Node* Remove(List* list, long long id);

void ClearList(List* list);