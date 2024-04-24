#pragma once
#include "Tile.h"
class MapManager
{
private:
	Tile* mMap[20][20];
	Car* mCar;
public:
	MapManager(Car* car);
	~MapManager();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
};

