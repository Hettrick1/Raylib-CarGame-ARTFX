#pragma once
#include "Tile.h"
class MapManager
{
private:
	Tile* mMap[20][20];
public:
	MapManager();
	~MapManager();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
};

