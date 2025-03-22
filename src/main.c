#include "MemoryLeakCheck.h"
#include "Game.h"
#include "MyTime.h"
#include "Global.h"

int main()
{
	ENABLE_LEAK_CHECK();

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

	DUMP_LEAKS();
}