#pragma once
class Enemy
{

public:
	Enemy();

	void Update(float elapsedSec);
	void Draw();

	Point2f GetPosition();
	bool GetIsAlive();
	void SetIsAlive(bool isAlive);
	void Reset();
	void IncreaseSpeed(float speedIncrease);
private:
	float m_Speed;
	Point2f m_Position;
	bool m_IsAlive;
};

