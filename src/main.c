//#define MEMORY_LEAK_CHECK // 메모리 누수 체크. 해당 줄 주석 처리하면 체크 안함.
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

	InitializeTime(); // 시간 초기화.
	UpdateTime(); // 처음에 한번 UpdateTime 해줌.

	InitializeGame(); // 게임 초기화.
	
	while (!g_quit) // 게임 루프. g_quit에 1이 들어오기 전까지 반복.
	{
		UpdateGame();
		RenderGame();
		UpdateTime();
	}

	ReleaseGame(); // 동적할당 해제 등 처리.

#ifdef MEMORY_LEAK_CHECK
	_CrtDumpMemoryLeaks();
#endif
}