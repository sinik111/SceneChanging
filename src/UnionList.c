#include "UnionList.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "Types.h"
#include "Global.h"

List* CreateList(DataType type)
{
	List* list = (List*)malloc(sizeof(List));
	if (list == NULL)
	{
		DebugLog("����Ʈ ������ �����߽��ϴ�");

		return NULL;
	}

	list->head = NULL;
	list->tail = NULL;
	list->type = type;

	return list;
}

void DeleteList(List* list)
{
	if (list == NULL)
	{
		DebugLog("DeleteList - ����Ʈ�� NULL�Դϴ�");
		return;
	}

	Node* current_node = list->head;

	while (current_node != NULL)
	{
		Node* temp = current_node->next;

		free(current_node);

		current_node = temp;
	}

	free(list);
}

void Insert(List* list, void* data)
{
	if (list == NULL)
	{
		DebugLog("Insert - ����Ʈ�� NULL�Դϴ�");

		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		DebugLog("Insert - �� ��� �Ҵ翡 �����߽��ϴ�");

		return;
	}

	int data_size = 0;

	switch (list->type)
	{
	case MENU_SCENE_BACKGROUND:
		data_size = sizeof(MenuSceneBackground);
		break;

	case BULLET:
		data_size = sizeof(Bullet);
		break;
	}

	memcpy(&new_node->data, data, data_size);

	if (list->head == NULL)
	{
		list->head = new_node;
	}
	else
	{
		list->tail->next = new_node;
	}

	new_node->next = NULL;

	list->tail = new_node;
}

Node* Remove(List* list, long long id)
{
	if (list == NULL)
	{
		DebugLog("Remove - ����Ʈ�� NULL�Դϴ�");

		return NULL;
	}

	Node* previous_node = NULL;
	Node* current_node = list->head;

	while (current_node != NULL)
	{
		// type Ȯ�� �ʿ���� data�� id�� ��
		if (current_node->data.id == id)
		{
			Node* next_node;

			if (previous_node != NULL)
			{
				next_node = previous_node->next = current_node->next;
			}
			else
			{
				next_node = list->head = current_node->next;
			}

			if (next_node == NULL)
			{
				list->tail = previous_node;
			}

			free(current_node);

			return next_node; // ���� �Ŀ� ��ȸ�� �� �ְ� ���� ��� ��ȯ��
		}

		previous_node = current_node;
		current_node = current_node->next;
	}

	return NULL;
}

Node* RemoveNode(List* list, Node* previous, Node* remove)
{
	if (list == NULL)
	{
		DebugLog("RemoveNode - ����Ʈ�� NULL�Դϴ�");

		return NULL;
	}

	if (remove == NULL)
	{
		DebugLog("RemoveNode - ������� Node�� NULL�Դϴ�");

		return NULL;
	}

	Node* next_node;

	if (previous != NULL)
	{
		next_node = previous->next = remove->next;
	}
	else
	{
		next_node = list->head = remove->next;
	}

	if (next_node == NULL)
	{
		list->tail = previous;
	}

	free(remove);

	return next_node; // ���� �Ŀ� ��ȸ�� �� �ְ� ���� ��� ��ȯ��
}

void ClearList(List* list)
{
	if (list == NULL)
	{
		DebugLog("ClearList - ����Ʈ�� NULL�Դϴ�");

		return;
	}

	Node* current_node = list->head;

	while (current_node != NULL)
	{
		Node* temp = current_node->next;

		free(current_node);

		current_node = temp;
	}

	list->head = NULL;
	list->tail = NULL;
}