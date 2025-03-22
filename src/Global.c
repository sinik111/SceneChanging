#include "Global.h"

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

int g_quit = 0;

// 다른 파일에서 직접 접근하지 못하게 static으로 선언
static long long g_global_id = 0;

long long GenerateID()
{
	return g_global_id++;
}

#ifdef _DEBUG
void PrintDebugLog(const char* fmt, ...)
{
    char buffer[1024];

    va_list args;

    va_start(args, fmt);

    vsnprintf_s(buffer, sizeof(buffer), _TRUNCATE, fmt, args);

    va_end(args);

    OutputDebugStringA(buffer);
}
#endif