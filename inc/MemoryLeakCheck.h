#pragma once

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define ENABLE_LEAK_CHECK() _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF)
#define DUMP_LEAKS() _CrtDumpMemoryLeaks()

#else // !_DEBUG

#define ENABLE_LEAK_CHECK()
#define DUMP_LEAKS()

#endif // _DEBUG