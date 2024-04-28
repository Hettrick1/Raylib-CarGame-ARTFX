#pragma once

#include "raylib.h"
class Checkpoints
{
private:
	Texture2D mCheckpointTexture;
	int mPosX;
	int mPosY;
	int mSizeX;
	int mSizeY;
	int mIsActive;
public:
	Checkpoints(Texture2D& checkpointTexture, int posX, int posY, int sizeX, int sizeY);
	~Checkpoints();
	void Update();
	void Draw();
	void Unload();
	int GetPosX();
	int GetPosY();
	void SetActive(bool active);
};

