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
    if (!menu.GetIsInStartMenu() && !justEnteredMap && !menu.GetIsInEndMenu() && !map.GetHasFinished()) { //load map
        map.SetMapIndex(menu.GetMapChosen());
        map.Load();
        car.SetCarPosition(map.GetSpawnPosition());
        car.ResetCar();
        menu.ResetTimer();
        justEnteredMap = true;
    }
    if (!menu.GetIsInStartMenu() && justEnteredMap && !menu.GetIsInEndMenu() && !map.GetHasFinished()) { //update map
        map.Update();
        car.Update();
        menu.TimerUpdate();
    }
    if (menu.GetIsInStartMenu() && !justEnteredMap && !menu.GetIsInEndMenu()){ // menu
        menu.StartMenuUpdate();
        map.SetHasFinished(false);
    }
    if (map.GetHasFinished() && justEnteredMap && !menu.GetIsInStartMenu() && !menu.GetIsInEndMenu()) { //just finished but still not in end menu
        menu.SetIsInEndMenu(true);
        justEnteredMap = false;
    }
    if (map.GetHasFinished() && !justEnteredMap && !menu.GetIsInStartMenu() && menu.GetIsInEndMenu()) {
        menu.EndMenuUpdate();
    }
}

void Draw()
{
    BeginDrawing();
    ClearBackground(Color({ 255, 255, 255, 255 }));
    if (!menu.GetIsInStartMenu() && justEnteredMap) {
        map.Draw();
        car.Draw();
        menu.TimerDraw();
    }
    else if (menu.GetIsInStartMenu() && !justEnteredMap && menu.GetIsInStartMenu() && !menu.GetIsInEndMenu()) {
        menu.StartMenuDraw();
    }
    if (map.GetHasFinished() && !justEnteredMap && !menu.GetIsInStartMenu() && menu.GetIsInEndMenu()) {
        menu.EndMenuDraw();
    }

    EndDrawing();
}

void Unload()
{
    menu.Unload();
    map.Unload();
    CloseWindow();
}