#include "Tile.h"

Tile::Tile(int posX, int posY, int sizeX, int sizeY, Texture2D& roadTexture, Texture2D& startTexture, Texture2D& grassTexture, Texture2D& obstacleTexture)
{
	mPosX = posX;
	mPosY = posY;
	mSizeX = sizeX;
	mSizeY = sizeY;
	mType = GRASS;
	mColor = GREEN;
	mRoadTexture = roadTexture;
	mStartTexture = startTexture;
	mGrassTexture = grassTexture;
	mObstacleTexture = obstacleTexture;
	mCurrentTexture = mGrassTexture;
}

Tile::~Tile()
{
}

void Tile::Load()
{
}

void Tile::Draw()
{
	DrawTextureEx(mCurrentTexture, { (float)mPosX, (float)mPosY }, 0, 1, WHITE);
}

void Tile::Update()
{
}

void Tile::Unload()
{
	UnloadTexture(mRoadTexture);
	UnloadTexture(mGrassTexture);
	UnloadTexture(mStartTexture);
	UnloadTexture(mObstacleTexture);
}

void Tile::ChangeType(TileType type)
{
	mType = type;
	if (mType == GRASS) {
		mColor = GREEN;
		mCurrentTexture = mGrassTexture;
	}
	else if (mType == ROAD) {
		mColor = GRAY;
		mCurrentTexture = mRoadTexture;
	}
	else if (mType == OBSTACLE) {
		mColor = RED;
		mCurrentTexture = mObstacleTexture;
	}
	else if (mType == START) {
		mColor = BLACK;
		mCurrentTexture = mStartTexture;
	}
	else if (mType == CHECKPOINT) {
		mColor = GRAY;
		mCurrentTexture = mRoadTexture;
	}
}

TileType Tile::GetTileType()
{
	return mType;
}
