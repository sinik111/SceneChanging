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
		DebugLog("리스트 생성에 실패했습니다");

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
		DebugLog("DeleteList - 리스트가 NULL입니다");
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
		DebugLog("Insert - 리스트가 NULL입니다");

		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		DebugLog("Insert - 새 노드 할당에 실패했습니다");

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
		DebugLog("Remove - 리스트가 NULL입니다");

		return NULL;
	}

	Node* previous_node = NULL;
	Node* current_node = list->head;

	while (current_node != NULL)
	{
		// type 확인 필요없이 data의 id만 비교
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

			return next_node; // 삭제 후에 순회할 수 있게 다음 노드 반환함
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
		DebugLog("RemoveNode - 리스트가 NULL입니다");

		return NULL;
	}

	if (remove == NULL)
	{
		DebugLog("RemoveNode - 지우려는 Node가 NULL입니다");

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

	return next_node; // 삭제 후에 순회할 수 있게 다음 노드 반환함
}

void ClearList(List* list)
{
	if (list == NULL)
	{
		DebugLog("ClearList - 리스트가 NULL입니다");

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