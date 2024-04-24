#include "Car.h"

Car::Car(Rectangle rect, float initialRotation)
{
	mCarRect = rect;
	mPosition = { mCarRect.x, mCarRect.y };
	mSize = { mCarRect.width, mCarRect.height };
	mVelocity = 0;
	mRotationSpeed = 0;
    mRotation = 0;
	mMaxVelocity = 250.0;
    mMaxAngularVelocity = 5.0;
    mAcceleration = 230.0;
    mAngularAcceleration = 5.0;
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
        if (mVelocity > mMaxVelocity)
            mVelocity = mMaxVelocity;
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
        if (mVelocity < -mMaxVelocity)
            mVelocity = -mMaxVelocity;
    }
    else
    {
        if (mVelocity > 0)
            mVelocity -= mAcceleration * GetFrameTime();
        else if (mVelocity < 0)
            mVelocity += mAcceleration * GetFrameTime();

        if (abs(mVelocity) < mAcceleration * GetFrameTime())
            mVelocity = 0;
    }

    if (IsKeyDown(KEY_D) && mVelocity != 0)
    {
        mRotationSpeed += mAngularAcceleration * GetFrameTime() * (mVelocity / 1000);
        if (mRotationSpeed > mMaxAngularVelocity)
            mRotationSpeed = mMaxAngularVelocity;
    }
    else if (IsKeyDown(KEY_A) && mVelocity != 0)
    {
        mRotationSpeed -= mAngularAcceleration * GetFrameTime() * (mVelocity / 1000);
        if (mRotationSpeed < -mMaxAngularVelocity)
            mRotationSpeed = -mMaxAngularVelocity;
    }
    else
    {
        if (mRotationSpeed > 0)
            mRotationSpeed -= mAngularAcceleration * 10 * GetFrameTime();
        else if (mRotationSpeed < 0)
            mRotationSpeed += mAngularAcceleration * 10 * GetFrameTime();

        if (abs(mRotationSpeed) < mAngularAcceleration * 10 * GetFrameTime())
            mRotationSpeed = 0;
    }


    mPosition.x += mVelocity * cos(mRotation) * GetFrameTime();
    mPosition.y += mVelocity * sin(mRotation) * GetFrameTime();
    mRotation += mRotationSpeed * GetFrameTime();
}

void Car::Draw()
{
	DrawRectanglePro(Rectangle{mPosition.x, mPosition.y, mSize.x, mSize.y}, {(mSize.x/3), mSize.y / 2}, mRotation/(PI/180), WHITE);
	DrawCircle(mPosition.x, mPosition.y, 5, RED);
}

void Car::Unload()
{
}
