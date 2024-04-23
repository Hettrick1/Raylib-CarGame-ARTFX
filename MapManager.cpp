#include "MapManager.h"

MapManager::MapManager()
{
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
}

void MapManager::Start()
{
}

void MapManager::Update()
{
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
