#include "Car.h"

bool isCarStopped;
bool checkFront;
bool checkBack;

Texture2D carTexture;

Car::Car(Rectangle rect, float initialRotation)
{
	mCarRect = rect;
	mPosition = { mCarRect.x, mCarRect.y };
	mSize = { mCarRect.width, mCarRect.height };
	mVelocity = 0;
	mRotationSpeed = 0;
    mRotation = 0;
	mMaxVelocity = 250.0;
    mMaxAngularVelocity = 10.0;
    mAcceleration = 230.0;
    mAngularAcceleration = 10.0;
    mDragCoefficient = 1.5;
    circleRadius = 15.0f;
    Vector2 center = { mPosition.x, mPosition.y};
    frontCircleCenter = { center.x, center.y - mSize.y / 2.0f + circleRadius };
    middleCircleCenter = { center.x, center.y };
    backCircleCenter = { center.x, center.y + mSize.y / 2.0f - circleRadius };
}

Car::~Car()
{
}

void Car::Load()
{
    carTexture = LoadTexture("sprites/car.png");
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
            if (mVelocity > 150 ) {
                mVelocity -= mAcceleration * dragFactor * GetFrameTime();
            }
        }
        mVelocity += mAcceleration * GetFrameTime();
        if (mVelocity > mMaxVelocity) {
            mVelocity = mMaxVelocity;
        }
    }
    else if (IsKeyReleased(KEY_W)) {
        mRotationSpeed = 0;
    }
    else if (IsKeyDown(KEY_S))
    {
        if (mRotationSpeed != 0)
        {
            float dragFactor = mDragCoefficient * abs(mRotationSpeed);
            if (mVelocity < -150)
            {
                mVelocity += mAcceleration * dragFactor * GetFrameTime();
            }
        }
        mVelocity -= mAcceleration * GetFrameTime();
        if (mVelocity < -mMaxVelocity) {
            mVelocity = -mMaxVelocity;
        }
    }
    else if (IsKeyReleased(KEY_S)) {
        mRotationSpeed = 0;
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

    if (IsKeyDown(KEY_D))
    {
        mRotationSpeed += mAngularAcceleration * GetFrameTime() * (mVelocity / 1000);
        if (mRotationSpeed > mMaxAngularVelocity) {
            mRotationSpeed = mMaxAngularVelocity;
        }
    }
    else if (IsKeyDown(KEY_A))
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
            mVelocity -= 500 * GetFrameTime();

        }
        else if (mVelocity < 0) {
            mVelocity += 500 * GetFrameTime();

        }
        if (mVelocity == 0) {
            isCarStopped = false;
        }
    }
    mPosition.x += mVelocity * cos(mRotation) * GetFrameTime();
    mPosition.y += mVelocity * sin(mRotation) * GetFrameTime();
    if (mVelocity != 0) {
        mRotation += mRotationSpeed * GetFrameTime();
        if (mRotation > 359) {
            mRotation = 359;
        }
    }

    Vector2 center = { mPosition.x, mPosition.y};
    float frontDistance = mSize.x / 2.0f - circleRadius;
    float backDistance = mSize.x / 2.0f - circleRadius;

    float frontX = center.x + cos(mRotation) * frontDistance;
    float frontY = center.y + sin(mRotation) * frontDistance;
    float backX = center.x - cos(mRotation) * backDistance;
    float backY = center.y - sin(mRotation) * backDistance;

    frontCircleCenter = { frontX, frontY };
    middleCircleCenter = { center.x, center.y };
    backCircleCenter = { backX, backY };

    checkFront = (mVelocity > 0);
    checkBack = (mVelocity < 0);
}

void Car::Draw()
{
	/*DrawRectanglePro(Rectangle{mPosition.x, mPosition.y, mSize.x, mSize.y}, {(mSize.x/2), mSize.y / 2}, mRotation/(PI/180), BLANK);*/
    DrawTexturePro(carTexture, { 0, 0, (float)carTexture.width, (float)carTexture.height }, { mPosition.x, mPosition.y, (float)carTexture.width, (float)carTexture.height }, { (float)carTexture.width / 2.0f, (float)carTexture.height / 2.0f }, { mRotation / (PI / 180) + 90 }, WHITE);
	/*DrawCircle(mPosition.x, mPosition.y, 5, RED);
    DrawCircleLines(frontCircleCenter.x, frontCircleCenter.y, 15, BLUE);
    DrawCircleLines(backCircleCenter.x, backCircleCenter.y, 15, RED);
    DrawCircleLines(middleCircleCenter.x, middleCircleCenter.y, 15, BLACK);*/

    //Green -> debug
}

void Car::Unload()
{
    UnloadTexture(carTexture);
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

void Car::SetCarPosition(Vector2 pos)
{
    mPosition = pos;
}

bool Car::CheckCollisionAABB(Rectangle carRect, Rectangle rect2)
{
    if (carRect.x + carRect.width / 2 < rect2.x || rect2.x + rect2.width < carRect.x - carRect.width /2 || carRect.y + carRect.height /2 < rect2.y || rect2.y + rect2.height < carRect.y - carRect.height / 2)
    {
        return false;
    }
    return true;
}

void Car::SetMaxVelocity(float velo)
{
    mMaxVelocity = velo;
}

bool Car::IsCollidingWithObject(Tile& tile)
{
    if (checkFront && mVelocity > 0 && CheckCollisionCircleRec({ frontCircleCenter.x, frontCircleCenter.y }, circleRadius, { (float)tile.GetPosX(), (float)tile.GetPosY(), (float)tile.GetSizeX(), (float)tile.GetSizeY() }))
    {
        return true;
    }

    if (checkBack && mVelocity < 0 && CheckCollisionCircleRec({ backCircleCenter.x, backCircleCenter.y }, circleRadius, { (float)tile.GetPosX(), (float)tile.GetPosY(), (float)tile.GetSizeX(), (float)tile.GetSizeY() }))
    {
        return true;
    }

    return false;
}
bool Car::IsHoveringObject(Tile& tile)
{
    if (CheckCollisionCircleRec({ middleCircleCenter.x, middleCircleCenter.y }, circleRadius, { (float)tile.GetPosX(), (float)tile.GetPosY(), (float)tile.GetSizeX(), (float)tile.GetSizeY() }))
    {
        return true;
    }
    return false;
}

bool Car::GetFront()
{
    return checkFront;
}

void Car::ResetCar()
{
    mVelocity = 0;
    mRotation = 0;
    mRotationSpeed = 0;
}
