#include "Car.h"

Car::Car(Rectangle rect, float initialRotation)
{
	mPosition = { rect.x, rect.y };
	mSize = { rect.width, rect.height };
	velocity = 0;
	acceleration = 0;
	rotationSpeed = 0;
	maxVelocity = 0;
	rotation = 0;
}

Car::~Car()
{
}

void Car::Load()
{
}

void Car::Start()
{
}

void Car::Update()
{
}

void Car::Draw()
{
}

void Car::Unload()
{
}
