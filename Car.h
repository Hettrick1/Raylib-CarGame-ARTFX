#pragma once
#include "raylib.h"
class Car
{
private:
	Vector2 mPosition;
	Vector2 mSize;
	float velocity;
	float acceleration;
	float rotationSpeed;
	float maxVelocity;
	float rotation;
public:
	Car(Rectangle rect, float initialRotation);
	~Car();
	void Load();
	void Start();
	void Update();
	void Draw();
	void Unload();
};

