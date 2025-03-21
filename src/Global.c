#include "Global.h"

int g_quit = 0;
long long g_global_id = 0;

long long GenerateID()
{
	return g_global_id++;
}