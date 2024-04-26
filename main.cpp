#include "raylib.h"
#include "MapManager.h"
#include "Car.h"
#include "Menus.h"
#include <iostream>


Car car = Car(Rectangle{500,600, 60,30}, 0);
MapManager map = MapManager(&car);
Menus menu;

bool justEnteredMap = false;

void Load();
void Start();
void Update();
void Draw();
void Unload();

int main() {
    Load();
    Start();
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    Unload();
    return 0;
}
void Load()
{
    InitWindow(1000, 1000, "Car Game ARTFX");
    SetTargetFPS(60);
    menu.Load();
}

void Start()
{

}

void Update()
{
    if (!menu.GetIsInStartMenu() && !justEnteredMap) {
        map.SetMapIndex(menu.GetMapChosen());
        map.Load();
        justEnteredMap = true;
    }
    if (!menu.GetIsInStartMenu() && justEnteredMap) {
        map.Update();
        car.Update();
    }
    else {
        menu.StartMenuUpdate();
    }
}

void Draw()
{
    BeginDrawing();
    ClearBackground(Color({ 255, 255, 255, 255 }));
    if (!menu.GetIsInStartMenu() && justEnteredMap) {
        map.Draw();
        car.Draw();;
    }
    else {
        menu.StartMenuDraw();
    }

    EndDrawing();
}

void Unload()
{
    menu.Unload();
    CloseWindow();
}