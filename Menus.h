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
	std::vector<Texture2D> mMaps;
public:
	Menus();
	~Menus();
	void Load();
	void StartMenuUpdate();
	void EndMenuUpdate();
	void StartMenuDraw();
	void EndMenuDraw();
	void Unload();
	bool GetIsInStartMenu();
	int GetMapChosen();
};

