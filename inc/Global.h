#pragma once

// 게임 종료 확인에 사용함.
extern int g_quit;

// 각 개체의 고유 아이디 부여에 사용함.
long long GenerateID();

#ifdef _DEBUG
// 비주얼 스튜디오->보기->출력->디버그에 로그 출력 함.
// printf랑 똑같이 사용하면 됨.
#define DebugLog(...) PrintDebugLog(__VA_ARGS__)
void PrintDebugLog(const char* fmt, ...);
#else
#define DebugLog(...) ((void)0)
#endif // _DEBUG