#pragma once
#include "TileType.h"
#include "raylib.h"

class Tile
{
private:
	int mPosX;
	int mPosY;
	int mSizeX;
	int mSizeY;
	TileType mType;
	Color mColor;
public:
	Tile(int posX, int posY, int sizeX, int sizeY);
	~Tile();
	void Load();
	void Draw();
	void Update();
	void Unload();
	void ChangeType(TileType type);
};

