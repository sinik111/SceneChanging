#pragma once

// ���� ���� Ȯ�ο� �����.
extern int g_quit;

// �� ��ü�� ���� ���̵� �ο��� �����.
long long GenerateID();

#ifdef _DEBUG
// ���־� ��Ʃ���->����->���->����׿� �α� ��� ��.
// printf�� �Ȱ��� ����ϸ� ��.
#define DebugLog(...) PrintDebugLog(__VA_ARGS__)
void PrintDebugLog(const char* fmt, ...);
#else
#define DebugLog(...) ((void)0)
#endif // _DEBUG