#include "raylib.h"
#include "MapManager.h"
#include "Car.h"
#include <iostream>

MapManager map;
Car car = Car(Rectangle{100,100, 60,30}, 0);

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
    map.Load();
}

void Start()
{

}

void Update()
{
    map.Update();
    car.Update();
}

void Draw()
{
    BeginDrawing();
    ClearBackground(Color({ 255, 255, 255, 255 }));
    map.Draw();
    car.Draw();
    EndDrawing();
}

void Unload()
{
    CloseWindow();
}