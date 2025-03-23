#include "Game.h"

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