#define MEMORY_LEAK_CHECK
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

	InitializeTime(); // 시간 초기화
	UpdateTime(); // 처음에 한번 UpdateTime 해줌

	InitializeGame();
	
	while (!g_quit)
	{
		UpdateGame();
		RenderGame();
		UpdateTime();
	}

	ReleaseGame();

#ifdef MEMORY_LEAK_CHECK
	_CrtDumpMemoryLeaks();
#endif
}