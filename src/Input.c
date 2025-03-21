#include "Input.h"

#include <memory.h>

SHORT key_state[256] = { 0 };
SHORT prev_key_state[256] = { 0 };

void UpdateInput()
{
    memcpy_s(prev_key_state, sizeof(prev_key_state), key_state, sizeof(key_state));

    for (int i = 0; i < 256; ++i)
    {
        key_state[i] = GetAsyncKeyState(i);
    }
}

BOOL IsKeyDown(int vKey)
{
    return (key_state[vKey] & 0x8000) != 0;
}

BOOL IsKeyPressed(int vKey)
{
    return (!(prev_key_state[vKey] & 0x8000) && (key_state[vKey] & 0x8000));
}

BOOL IsKeyReleased(int vKey)
{
    return ((prev_key_state[vKey] & 0x8000) && !(key_state[vKey] & 0x8000));
}