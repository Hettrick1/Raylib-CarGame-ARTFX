#include "raylib.h"
#include "MapManager.h"
#include "Car.h"
#include "Menus.h"
#include <iostream>


Car car = Car(Rectangle{100,100, 60,30}, 0);
MapManager map = MapManager(&car);
Menus menu;

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
    if (!menu.GetIsInStartMenu()) {
        map.Load();
    }
}

void Start()
{

}

void Update()
{
    if (!menu.GetIsInStartMenu()) {
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
    if (!menu.GetIsInStartMenu()) {
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