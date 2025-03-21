//#define MEMORY_LEAK_CHECK // �޸� ���� üũ. �ش� �� �ּ� ó���ϸ� üũ ����.
#ifdef MEMORY_LEAK_CHECK
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <stdlib.h>

#include "Game.h"
#include "MyTime.h"
#include "Global.h"

int main()
{
#ifdef MEMORY_LEAK_CHECK
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	InitializeTime(); // �ð� �ʱ�ȭ.
	UpdateTime(); // ó���� �ѹ� UpdateTime ����.

	InitializeGame(); // ���� �ʱ�ȭ.
	
	while (!g_quit) // ���� ����. g_quit�� 1�� ������ ������ �ݺ�.
	{
		UpdateGame();
		RenderGame();
		UpdateTime();
	}

	ReleaseGame(); // �����Ҵ� ���� �� ó��.

#ifdef MEMORY_LEAK_CHECK
	_CrtDumpMemoryLeaks();
#endif
}