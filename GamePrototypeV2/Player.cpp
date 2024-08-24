#include "pch.h"
#include "Player.h"
#include "utils.h"
#include <iostream>


Player::Player() :
	m_Position(375, 100),
	m_Size(50, 50),
	m_Color(255, 0, 0, 1),
	m_Velocity(0)
{
}

void Player::Update(float elapsedSec)
{
	if (m_Position.x < 50)
	{
		m_Position.x = 51;
	}
	else if (m_Position.x + m_Size.x > 750)
	{
		m_Position.x = 750 - m_Size.x;
	}
	else {
		m_Position.x += m_Velocity * elapsedSec;
	}
}

void Player::Draw()
{
	std::cout << m_Position.x << std::endl;
	utils::SetColor(m_Color);
	utils::FillRect(m_Position.x, m_Position.y, m_Size.x, m_Size.y);
}

void Player::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_LEFT:
		m_Velocity = -150;
		break;
	case SDLK_RIGHT:
		break;
	}
}

void Player::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_LEFT:
		m_Velocity = 0;
		break;
	case SDLK_RIGHT:
		m_Velocity = 0;
		break;
	}
}
