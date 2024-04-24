#include "MapManager.h"

MapManager::MapManager(Car* car)
{
	mCar = car;
}

MapManager::~MapManager()
{
}

void MapManager::Load()
{
	int tileSizeX = 50;
	int TileSizeY = 50;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mMap[i][j] = new Tile(j * tileSizeX, i * TileSizeY, tileSizeX, TileSizeY);
		}
	}
	mMap[10][10]->ChangeType(OBSTACLE);
	mMap[10][11]->ChangeType(OBSTACLE);
	mMap[10][12]->ChangeType(OBSTACLE);
	mMap[10][13]->ChangeType(OBSTACLE);
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
