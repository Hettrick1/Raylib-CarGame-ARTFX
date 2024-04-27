#pragma once
#include "TileType.h"
#include "raylib.h"

#include <iostream>

class Tile
{
private:
	int mPosX;
	int mPosY;
	int mSizeX;
	int mSizeY;
	TileType mType;
	Color mColor;
	Texture2D mRoadTexture;
	Texture2D mStartTexture;
	Texture2D mGrassTexture;
	Texture2D mObstacleTexture;
	Texture2D mCurrentTexture;
public:
	Tile(int posX, int posY, int sizeX, int sizeY, Texture2D& roadTexture, Texture2D& startTexture, Texture2D& grassTexture, Texture2D& obstacleTexture);
	~Tile();
	void Load();
	void Draw();
	void Update();
	void Unload();
	void ChangeType(TileType type);
	TileType GetTileType();
	int GetPosX() const { return mPosX; }
	int GetPosY() const { return mPosY; }
	int GetSizeX() const { return mSizeX; }
	int GetSizeY() const { return mSizeY; }
};

