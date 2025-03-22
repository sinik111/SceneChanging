#include "Game.h"

#include <stdio.h>
#include <wchar.h>

#include "ConsoleRenderer.h"
#include "Input.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "Global.h"
#include "MyTime.h"

#define CHECK_FPS

#define VK_ESCAPE         0x1B
#define VK_SPACE          0x20

#ifdef CHECK_FPS
int frame_count = 0;
float frame_timer = 0.0f;
wchar_t fps_buffer[10] = { 0 };

void CheckFPS();
#endif

Scene current_scene = NONE;
Scene next_scene = NONE;

void (*UpdateScene)();
void (*RenderScene)();
void (*ReleaseScene)();

void InitializeGame()
{
    ScreenInit();

    next_scene = MENU;

    InitializeMenuScene();

    UpdateScene = &UpdateMenuScene;
    RenderScene = &RenderMenuScene;
    ReleaseScene = &ReleaseMenuScene;

    current_scene = next_scene;
}

void UpdateGame()
{
    if (current_scene != next_scene)
    {
        ReleaseScene();

        switch (next_scene)
        {
        case MENU:
            UpdateScene = &UpdateMenuScene;
            RenderScene = &RenderMenuScene;
            ReleaseScene = &ReleaseMenuScene;

            InitializeMenuScene();
            break;

        case PLAY:
            UpdateScene = &UpdatePlayScene;
            RenderScene = &RenderPlayScene;
            ReleaseScene = &ReleasePlayScene;

            InitializePlayScene();
            break;

        case END:
            UpdateScene = &UpdateEndScene;
            RenderScene = &RenderEndScene;
            ReleaseScene = &ReleaseEndScene;

            InitializeEndScene();
            break;
        }

        current_scene = next_scene;
    }

    UpdateInput();

    if (IsKeyReleased(VK_SPACE))
    {
        if (next_scene < END)
        {
            ++next_scene;
        }
    }

    if (IsKeyReleased(VK_ESCAPE))
    {
        g_quit = 1;
    }

    UpdateScene();
}

void RenderGame()
{
    ScreenClear();

    RenderScene();

#ifdef CHECK_FPS
    CheckFPS();
#endif

    ScreenFlipping();
}

void ReleaseGame()
{
    ReleaseScene();

    ScreenRelease();
}

void ChangeScene(Scene scene)
{
    next_scene = scene;
}

#ifdef CHECK_FPS
void CheckFPS()
{
    ++frame_count;

    frame_timer += DeltaTime();
    if (frame_timer > 1.0f)
    {
        swprintf(fps_buffer, 10, L"%d", frame_count);

        frame_timer -= 1.0f;
        frame_count = 0;
    }

    ScreenDrawString(0, 0, fps_buffer, FG_YELLOW);
}
#endif