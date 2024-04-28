#pragma once
#include "raylib.h"
#include "Tile.h"
#include <cmath>
class Car
{
private:
	Rectangle mCarRect;
	Vector2 mPosition;
	Vector2 mSize;
	float mVelocity;
	float mAcceleration;
	float mAngularAcceleration;
	float mRotationSpeed;
	float mMaxVelocity;
	float mMaxAngularVelocity;
	float mRotation;
	float mDragCoefficient;
	Vector2 frontCircleCenter;
	Vector2 middleCircleCenter;
	Vector2 backCircleCenter;
	float circleRadius;
public:
	Car(Rectangle rect, float initialRotation);
	~Car();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
	void StopCar();
	void SetCarPosition(Vector2 pos);
	void SetMaxVelocity(float velo);
	Rectangle GetCarRect();
	bool CheckCollisionAABB(Rectangle rect1, Rectangle rect2);
	bool IsCollidingWithObject(Tile& tile);
	bool IsHoveringObject(Tile& tile);
	bool GetFront();
};

