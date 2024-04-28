#pragma once
#include "Tile.h"
#include "Car.h"
#include "Checkpoints.h"
#include <vector>
class MapManager
{
private:
	Tile* mMap[20][20];
	Car* mCar;
	Image mMapImage;
	int mMapIndex;
	Vector2 mSpawnPos;
	std::vector<Checkpoints> mCheckpoints;
	int mCheckpointCount;
	bool mCanFinish;
	bool mHasFinished;
public:
	MapManager(Car* car);
	~MapManager();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
	void SetMapIndex(int index);
	Vector2 GetSpawnPosition();
	bool GetHasFinished();
	void SetHasFinished(bool finished);
};

