#pragma once
#include "Tile.h"
#include "Car.h"
class MapManager
{
private:
	Tile* mMap[20][20];
	Car* mCar;
	Image mMapImage;
	int mMapIndex;
public:
	MapManager(Car* car);
	~MapManager();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
};

