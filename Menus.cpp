#include "Menus.h"

Menus::Menus()
{
	mIsInStartMenu = true;
	mIsInEndMenu = false;
	mMapIndex = 0;
	mTimer = 0;
}

Menus::~Menus()
{
}

void Menus::Load()
{
	for (int i = 1; i < 5; i++) {
		Texture2D texture = LoadTexture(TextFormat("maps/Map%i.png", i));
		if (texture.id != 0) {
			mMaps.push_back(texture);
			mMapIndex += 1;
			std::cout << mMapIndex;
		}
	}
}

void Menus::StartMenuUpdate()
{
	switch (mMapIndex)
	{
	case 1:
		if (IsKeyPressed(KEY_KP_1)) {
			mMapChosen = 1;
			mIsInStartMenu = false;
			break;
		}
	case 2:
		if (IsKeyPressed(KEY_KP_1)) {
			mMapChosen = 1;
			mIsInStartMenu = false;
			break;
		}
		if (IsKeyPressed(KEY_KP_2)) {
			mMapChosen = 2;
			mIsInStartMenu = false;
			break;
		}
	case 3 :
		if (IsKeyPressed(KEY_KP_1)) {
			mMapChosen = 1;
			mIsInStartMenu = false;
			break;
		}
		if (IsKeyPressed(KEY_KP_2)) {
			mMapChosen = 2;
			mIsInStartMenu = false;
			break;
		}
		if (IsKeyPressed(KEY_KP_3)) {
			mMapChosen = 3;
			mIsInStartMenu = false;
			break;
		}
	case 4 :
		if (IsKeyPressed(KEY_KP_1)) {
			mMapChosen = 1;
			mIsInStartMenu = false;
			break;
		}
		if (IsKeyPressed(KEY_KP_2)) {
			mMapChosen = 2;
			mIsInStartMenu = false;
			break;
		}
		if (IsKeyPressed(KEY_KP_3)) {
			mMapChosen = 3;
			mIsInStartMenu = false;
			break;
		}
		if (IsKeyPressed(KEY_KP_4)) {
			mMapChosen = 4;
			mIsInStartMenu = false;
			break;
		}
	}
}

void Menus::EndMenuUpdate()
{
	ClearBackground(BLACK);
	if (IsKeyPressed(KEY_ENTER)) {
		mIsInStartMenu = true;
		mIsInEndMenu = false;
	}
}

void Menus::StartMenuDraw()
{
	ClearBackground(BLACK);
	DrawText("WELCOME !", 500 - MeasureText("WELCOME !", 100)/2, 200, 100, WHITE);
	DrawText("Choose your track", 500 - MeasureText("Choose your track", 50)/2, 300, 50, WHITE);
	int totalWidth = mMapIndex * 120 + (mMapIndex - 1) * 60;
	int startX = 500 - totalWidth / 2;

	for (int i = 0; i < mMapIndex; i++) {
		DrawTextureEx(mMaps[i], { (float)startX + i * (120 + 60), 500}, 0, 6, WHITE);
		DrawText(TextFormat("%i", i + 1), startX + 55 + i * (120 + 60), 650, 40, WHITE);
	}
	DrawText(TextFormat("Use Numpad between 1 - %i", mMapIndex), 500 - MeasureText(TextFormat("Use Numpad between 1 - %i", mMapIndex), 30) / 2, 750, 30, WHITE);
}

void Menus::EndMenuDraw()
{
	ClearBackground(BLACK);
	DrawText("WELL DONE !", 500 - MeasureText("WELL DONE !", 100) / 2, 200, 100, WHITE);
	DrawText(TextFormat("You finished your lap in only : %02.02f secondes", mTimer), 500 - MeasureText(TextFormat("You finished your lap in only : %02.02f secondes", mTimer), 30) / 2, 300, 30, WHITE);
	DrawText("Press enter to continue....", 500 - MeasureText("Press enter to continue....", 30) / 2, 700, 30, WHITE);
}

void Menus::TimerUpdate()
{
	mTimer += GetFrameTime();
}

void Menus::TimerDraw()
{
	DrawText(TextFormat("%02i", (int)mTimer), 500 - MeasureText(TextFormat("%02i", (int)mTimer), 30), 25, 30, BLACK);
}

void Menus::ResetTimer()
{
	mTimer = 0;
}

void Menus::Unload()
{
	for (Texture2D& texture : mMaps) {
		UnloadTexture(texture);
	}
}

bool Menus::GetIsInStartMenu()
{
	return mIsInStartMenu;
}

bool Menus::GetIsInEndMenu()
{
	return mIsInEndMenu;
}

void Menus::SetIsInEndMenu(bool menu)
{
	mIsInEndMenu = menu;
}

int Menus::GetMapChosen()
{
	return mMapChosen;
}
