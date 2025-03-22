#pragma once

#include "Types.h"
#include "MenuSceneBackground.h"
#include "Bullet.h"

// ����Ʈ�� �������� Ÿ�Ե��� ���� �� �ְ� union�� �̿���.
typedef struct UnionNode
{
	union
	{
		// �� Ÿ���� struct�鵵 ù��° ����� long long �� id�� ������ ����
		// union�̶� struct ������ ����Ʈ�� ���� �� �ڵ����� ä����
		// ������ id�� ���� Ư�� ������ �� �� Ÿ���� ���� id�� �� �� ����
		long long id;
		MenuSceneBackground msbg;
		Bullet bullet;
	} data;
	struct UnionNode* next;
} Node;

// ����Ʈ���� Ÿ���� ���� ������ ������
// ���� Ÿ���� ���������� Ȯ��
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