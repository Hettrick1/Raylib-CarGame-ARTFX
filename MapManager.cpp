#include "MapManager.h"

MapManager::MapManager(Car* car)
{
	mCar = car;
	mMapImage = Image();
	mMapIndex = 1;
}

MapManager::~MapManager()
{
}

void MapManager::Load()
{
	int index = 0;
	mMapImage = LoadImage(TextFormat("maps/Map%i.png", mMapIndex));
	Color* colors = LoadImageColors(mMapImage);
	int tileSizeX = 50;
	int TileSizeY = 50;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mMap[i][j] = new Tile(j * tileSizeX, i * TileSizeY, tileSizeX, TileSizeY);
			if (colors[index].r > 0) {
				mMap[i][j]->ChangeType(ROAD);
			}
			else if (colors[index].g > 0) {
				mMap[i][j]->ChangeType(GRASS);
			}
			else if (colors[index].b > 0) {
				mMap[i][j]->ChangeType(OBSTACLE);
			}
			index += 1;
		}
	}
	UnloadImageColors(colors);
	UnloadImage(mMapImage);
}

void MapManager::Start()
{
}

void MapManager::Update()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mMap[i][j]->Update();
			if (mCar->IsCollidingWithObject(*mMap[i][j]) && mMap[i][j]->GetTileType() == OBSTACLE) {
				mCar->StopCar();
			}
		}
	}
}

void MapManager::Draw()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mMap[i][j]->Draw();
		}
	}
}

void MapManager::Unload()
{
}

void MapManager::SetMapIndex(int index)
{
	mMapIndex = index;
}
