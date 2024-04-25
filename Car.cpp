#include "Car.h"

bool isCarStopped;

Car::Car(Rectangle rect, float initialRotation)
{
	mCarRect = rect;
	mPosition = { mCarRect.x, mCarRect.y };
	mSize = { mCarRect.width, mCarRect.height };
	mVelocity = 0;
	mRotationSpeed = 0;
    mRotation = 0;
	mMaxVelocity = 250.0;
    mMaxAngularVelocity = 7.0;
    mAcceleration = 230.0;
    mAngularAcceleration = 7.0;
    mDragCoefficient = 2;
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
    if (IsKeyDown(KEY_W))
    {
        if (mRotationSpeed != 0)
        {
            float dragFactor = mDragCoefficient * abs(mRotationSpeed);
            if (mVelocity > 200 ) {
                mVelocity -= mAcceleration * dragFactor * GetFrameTime();
            }
        }
        mVelocity += mAcceleration * GetFrameTime();
        if (mVelocity > mMaxVelocity) {
            mVelocity = mMaxVelocity;
        }
    }
    else if (IsKeyDown(KEY_S))
    {
        if (mRotationSpeed != 0)
        {
            float dragFactor = mDragCoefficient * abs(mRotationSpeed);
            if (mVelocity < -200)
            {
                mVelocity += mAcceleration * dragFactor * GetFrameTime();
            }
        }
        mVelocity -= mAcceleration * GetFrameTime();
        if (mVelocity < -mMaxVelocity) {
            mVelocity = -mMaxVelocity;
        }
    }
    else
    {
        if (mVelocity > 0) {
            mVelocity -= mAcceleration * GetFrameTime();
        }
        else if (mVelocity < 0) {
            mVelocity += mAcceleration * GetFrameTime();
        }

        if (abs(mVelocity) < mAcceleration * GetFrameTime()) {
            mVelocity = 0;
        }
    }

    if (IsKeyDown(KEY_D) && mVelocity != 0)
    {
        mRotationSpeed += mAngularAcceleration * GetFrameTime() * (mVelocity / 1000);
        if (mRotationSpeed > mMaxAngularVelocity) {
            mRotationSpeed = mMaxAngularVelocity;
        }
    }
    else if (IsKeyDown(KEY_A) && mVelocity != 0)
    {
        mRotationSpeed -= mAngularAcceleration * GetFrameTime() * (mVelocity / 1000);
        if (mRotationSpeed < -mMaxAngularVelocity) {
            mRotationSpeed = -mMaxAngularVelocity;
        }
    }
    else
    {
        if (mRotationSpeed > 0) {
            mRotationSpeed -= mAngularAcceleration * 10 * GetFrameTime();
        }
        else if (mRotationSpeed < 0) {
            mRotationSpeed += mAngularAcceleration * 10 * GetFrameTime();
        }
        if (abs(mRotationSpeed) < mAngularAcceleration * 10 * GetFrameTime()) {
            mRotationSpeed = 0;
        }
    }

    if (isCarStopped) {
        if (mVelocity > 0) {
            mVelocity -= 400 * GetFrameTime();

        }
        else if (mVelocity < 0) {
            mVelocity += 400 * GetFrameTime();

        }
        if (mVelocity == 0) {
            isCarStopped = false;
        }
    }


    mPosition.x += mVelocity * cos(mRotation) * GetFrameTime();
    mPosition.y += mVelocity * sin(mRotation) * GetFrameTime();
    mRotation += mRotationSpeed * GetFrameTime();
}

void Car::Draw()
{
	DrawRectanglePro(Rectangle{mPosition.x, mPosition.y, mSize.x, mSize.y}, {(mSize.x/2), mSize.y / 2}, mRotation/(PI/180), WHITE);
	DrawCircle(mPosition.x, mPosition.y, 5, RED);
}

void Car::Unload()
{
}

void Car::StopCar()
{
    if (!isCarStopped) {
        mVelocity *= -1;
        isCarStopped = true;
    }
}

Rectangle Car::GetCarRect()
{
    return Rectangle{ mPosition.x, mPosition.y, mSize.x, mSize.y };
}

bool Car::CheckCollisionAABB(Rectangle carRect, Rectangle rect2)
{
    if (carRect.x + carRect.width / 2 < rect2.x || rect2.x + rect2.width < carRect.x - carRect.width /2 || carRect.y + carRect.height /2 < rect2.y || rect2.y + rect2.height < carRect.y - carRect.height / 2)
    {
        return false;
    }
    return true;
}

bool Car::IsCollidingWithObject(Tile& tile)
{
    Rectangle carRect = GetCarRect();
    Rectangle tileRect = { tile.GetPosX(), tile.GetPosY(), tile.GetSizeX(), tile.GetSizeY() };

    return CheckCollisionAABB(carRect, tileRect);
}
