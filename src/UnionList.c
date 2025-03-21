#include "UnionList.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>

List* CreateList(DataType type)
{
	List* list = (List*)malloc(sizeof(List));
	if (list == NULL)
	{
		printf("����Ʈ ���� ����");

		return NULL;
	}

	list->head = NULL;
	list->type = type;

	return list;
}

void DeleteList(List* list)
{
	if (list == NULL)
	{
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
		printf("����Ʈ�� ���Դϴ�.");

		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("�� ��� �Ҵ� ����");

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
		printf("����Ʈ�� ���Դϴ�");

		return NULL;
	}

	Node* prev_node = NULL;
	Node* current_node = list->head;

	while (current_node != NULL)
	{
		// type Ȯ�� �ʿ���� data�� id�� ��
		if (current_node->data.id == id)
		{
			Node* next_node;

			if (prev_node != NULL)
			{
				next_node = prev_node->next = current_node->next;
			}
			else
			{
				next_node = list->head = current_node->next;
			}

			free(current_node);

			return next_node; // ���� �Ŀ� ��ȸ�� �� �ְ� ���� ��� ��ȯ��
		}

		prev_node = current_node;
		current_node = current_node->next;
	}

	return NULL;
}

void ClearList(List* list)
{
	if (list == NULL)
	{
		printf("����Ʈ�� ���Դϴ�");

		return;
	}

	Node* current_node = list->head;

	while (current_node != NULL)
	{
		Node* temp = current_node->next;

		free(current_node);

		current_node = temp;
	}
}