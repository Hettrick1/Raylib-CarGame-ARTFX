#include "raylib.h"
#include <iostream>

using namespace std;

int main() {

    
    cout << "Hello World" << endl;

    InitWindow(300, 300, "My first Raylib window!");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}