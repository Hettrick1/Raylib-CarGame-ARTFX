#include "MapManager.h"

Texture2D roadTexture;
Texture2D startTexture;
Texture2D grassTexture;
Texture2D obstacleTexture;
Texture2D checkpointTexture;



MapManager::MapManager(Car* car)
{
	mCar = car;
	mMapImage = Image();
	mMapIndex = 1;
	mSpawnPos = { 500, 500 };
	mCheckpoints = {};
	mCheckpointCount = 0;
	mCanFinish = false;
	mHasFinished = false;
}

MapManager::~MapManager()
{
}

void MapManager::Load()
{
	mCanFinish = false;
	mHasFinished = false;
	mCheckpointCount = 0;
	int index = 0;
	mMapImage = LoadImage(TextFormat("maps/Map%i.png", mMapIndex));
	roadTexture = LoadTexture("sprites/road.png");
	startTexture = LoadTexture("sprites/start.png");
	grassTexture = LoadTexture("sprites/grass.png");
	obstacleTexture = LoadTexture("sprites/obstacle.png");
	checkpointTexture = LoadTexture("sprites/checkpoint.png");
	mCar->Load();
	Color* colors = LoadImageColors(mMapImage);
	int tileSizeX = 50;
	int TileSizeY = 50;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mMap[i][j] = new Tile(j * tileSizeX, i * TileSizeY, tileSizeX, TileSizeY, roadTexture, startTexture, grassTexture, obstacleTexture);
			if (colors[index].r > 0 && colors[index].g == 0 && colors[index].b == 0) {
				mMap[i][j]->ChangeType(ROAD);
			}
			else if (colors[index].g > 0 && colors[index].r == 0 && colors[index].b == 0) {
				mMap[i][j]->ChangeType(GRASS);
			}
			else if (colors[index].b > 0 && colors[index].r == 0 && colors[index].g == 0) {
				mMap[i][j]->ChangeType(OBSTACLE);
			}
			else if (colors[index].r == 0 && colors[index].g == 0 && colors[index].b == 0) {
				mMap[i][j]->ChangeType(START);
				mSpawnPos = { (float)mMap[i][j]->GetPosX(), (float)mMap[i][j]->GetPosY() };
			}
			else if (colors[index].r == 255 && colors[index].g == 255 && colors[index].b == 255) {
				mMap[i][j]->ChangeType(CHECKPOINT);
				Checkpoints checkpoint = Checkpoints(checkpointTexture, mMap[i][j]->GetPosX(), mMap[i][j]->GetPosY(), 50, 50);
				mCheckpoints.push_back(checkpoint);
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
			else if (mCar->IsHoveringObject(*mMap[i][j]) && mMap[i][j]->GetTileType() == GRASS) {
				mCar->SetMaxVelocity(125);
			}
			else if (mCar->IsHoveringObject(*mMap[i][j]) && mMap[i][j]->GetTileType() == ROAD)
			{
				mCar->SetMaxVelocity(250);
			}
			else if (mCar->IsHoveringObject(*mMap[i][j]) && mMap[i][j]->GetTileType() == CHECKPOINT) {
				for (Checkpoints& checkpoint : mCheckpoints) {
					if (checkpoint.GetPosX() == mMap[i][j]->GetPosX() && checkpoint.GetPosY() == mMap[i][j]->GetPosY()) {
						checkpoint.SetActive(false);
						mCheckpointCount += 1;
					}
				}
			}
			else if (mCar->IsHoveringObject(*mMap[i][j]) && mMap[i][j]->GetTileType() == START && mCanFinish)
			{
				mHasFinished = true;
			}
		}
	}
	if (mCheckpointCount == mCheckpoints.size()) {
		mCanFinish = true;
	}
}

void MapManager::Draw()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mMap[i][j]->Draw();
		}
	}
	for (Checkpoints& checkpoint : mCheckpoints) {
		checkpoint.Draw();
	}
}

void MapManager::Unload()
{
	UnloadTexture(roadTexture);
	UnloadTexture(grassTexture);
	UnloadTexture(startTexture);
	UnloadTexture(obstacleTexture);
	UnloadTexture(checkpointTexture);
	mCar->Unload();
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mMap[i][j]->Unload();
		}
	}
}

void MapManager::SetMapIndex(int index)
{
	mMapIndex = index;
}

Vector2 MapManager::GetSpawnPosition()
{
	return mSpawnPos;
}

bool MapManager::GetHasFinished()
{
	return mHasFinished;
}
