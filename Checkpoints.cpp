#include "Checkpoints.h"

Checkpoints::Checkpoints(Texture2D& checkpointTexture, int posX, int posY, int sizeX, int sizeY)
{
	mCheckpointTexture = checkpointTexture;
	mPosX = posX;
	mPosY = posY;
	mSizeX = sizeX;
	mSizeY = sizeY;
}

Checkpoints::~Checkpoints()
{
}

void Checkpoints::Update()
{
}

void Checkpoints::Draw()
{
	if (mIsActive) {
		DrawTextureEx(mCheckpointTexture, { (float)mPosX, (float)mPosY }, 0, 1, WHITE);
	}
}

void Checkpoints::Unload()
{
	UnloadTexture(mCheckpointTexture);
}

int Checkpoints::GetPosX()
{
	return mPosX;
}

int Checkpoints::GetPosY()
{
	return mPosY;
}

void Checkpoints::SetActive(bool active)
{
	mIsActive = active;
}
