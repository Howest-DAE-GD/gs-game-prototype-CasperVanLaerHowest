#include "pch.h"
#include "Enemy.h"
#include "math.h"
#include "utils.h"

Enemy::Enemy() :
	m_IsAlive(true),
	m_Speed(50.0f)
{
	m_Position.y = rand() % 150 + 900;
	m_Position.x = rand() % 650 + 50;
}

void Enemy::Update(float elapsedSec)
{
	if (m_IsAlive)
	{
		m_Position.y -= m_Speed * elapsedSec;
	}
}

void Enemy::Draw()
{
	if (m_IsAlive)
	{
		utils::SetColor(Color4f(0, 255, 0, 1));
		utils::FillRect(m_Position.x, m_Position.y, 40, 40);
	}
}

Point2f Enemy::GetPosition()
{
	return m_Position;
}

bool Enemy::GetIsAlive()
{
	return m_IsAlive;
}

void Enemy::SetIsAlive(bool isAlive)
{
	m_IsAlive = isAlive;
}

void Enemy::Reset()
{
	m_IsAlive = true;
	m_Position.y = rand() % 150 + 900;
	m_Position.x = rand() % 650 + 50;
}

void Enemy::IncreaseSpeed(float speedIncrease)
{
	m_Speed += speedIncrease;
}
