#include "Tile.h"

Tile::Tile(int posX, int posY, int sizeX, int sizeY)
{
	mPosX = posX;
	mPosY = posY;
	mSizeX = sizeX;
	mSizeY = sizeY;
	mType = GRASS;
	mColor = GREEN;
}

Tile::~Tile()
{
}

void Tile::Load()
{
}

void Tile::Draw()
{
	DrawRectangle(mPosX, mPosY, mSizeX, mSizeY, mColor);
}

void Tile::Update()
{
}

void Tile::Unload()
{
}

void Tile::ChangeType(TileType type)
{
	mType = type;
	if (mType == GRASS) {
		mColor = GREEN;
	}
	else if (mType == ROAD) {
		mColor = GRAY;
	}
	else if (mType == OBSTACLE) {
		mColor = RED;
	}
	else if (mType == START) {
		mColor = BLACK;
	}
}

TileType Tile::GetTileType()
{
	return mType;
}
