#pragma once

#include "raylib.h"
#include <vector>
#include <iostream>

class Menus
{
private:
	bool mIsInStartMenu;
	bool mIsInEndMenu;
	int mMapIndex;
	int mMapChosen;
	float mTimer;
	std::vector<Texture2D> mMaps;
public:
	Menus();
	~Menus();
	void Load();
	void StartMenuUpdate();
	void EndMenuUpdate();
	void StartMenuDraw();
	void EndMenuDraw();
	void TimerUpdate();
	void TimerDraw();
	void ResetTimer();
	void Unload();
	bool GetIsInStartMenu();
	bool GetIsInEndMenu();
	void SetIsInEndMenu(bool menu);
	int GetMapChosen();
};

