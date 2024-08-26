#include "pch.h"
#include "Player.h"
#include "utils.h"
#include "Game.h"

Player::Player(Game* Game) :
	m_Position(375, 100),
	m_Size(50, 50),
	m_Color(255, 0, 0, 1),
	m_Velocity(0),
	m_ShootTimer(0)
{
	m_Game = Game;
	m_MoveSpeedTexture = new Texture("Move Speed : " + std::to_string(m_MoveSpeed), "arial.ttf", 24, Color4f{ 1.f ,0.f,0.f,1.f });
	m_ShootSpeedTexture = new Texture("Shoot Speed : " + std::to_string(m_ShootSpeed), "arial.ttf", 24, Color4f{ 1.f ,0.f,0.f,1.f });
}

Player::~Player()
{
	
}

void Player::Update(float elapsedSec)
{
	//delete textures
	delete m_MoveSpeedTexture;
	delete m_ShootSpeedTexture;

	//update Textures
	m_MoveSpeedTexture = new Texture("Move Speed : " + std::to_string(m_MoveSpeed), "arial.ttf", 24, Color4f{ 1.f ,0.f,0.f,1.f });
	m_ShootSpeedTexture = new Texture("Shoot Speed : " + std::to_string(m_ShootSpeed), "arial.ttf", 24, Color4f{ 1.f ,0.f,0.f,1.f });

	//checks to let it stay in bounds
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

	//shoots the bullets
	if (m_ShootTimer > m_ShootSpeed) {
		if (m_DubbelShot) {
			SpawnBullet();
		}
		SpawnBullet();
		m_ShootTimer = 0;
	} else {
		m_ShootTimer += elapsedSec;
	}

	//updates the bullets
	for (int i = 0; i < 200; i++)
	{
		if (m_Bullets[i].m_IsActive)
		{
			m_Bullets[i].m_Position.y += m_Bullets[i].m_Velocity * elapsedSec;
			m_Bullets[i].m_LifeTime += elapsedSec;
			if (m_Bullets[i].m_LifeTime > 3)
			{
				m_Bullets[i].m_IsActive = false;
			}
		}
	}

	CheckBulletCollision();
}

void Player::Draw()
{
	//draws the textures
	m_MoveSpeedTexture->Draw(Point2f{ 450,10 });
	m_ShootSpeedTexture->Draw(Point2f{ 450,40 });

	//draws the player
	utils::SetColor(m_Color);
	utils::FillRect(m_Position.x, m_Position.y, m_Size.x, m_Size.y);

	//draws the bullets
	for (int i = 0; i < 200; i++)
	{
		if(m_Bullets[i].m_IsActive){
			utils::SetColor(Color4f{ 255,255,0,1 });
			utils::FillRect(m_Bullets[i].m_Position.x, m_Bullets[i].m_Position.y, 5, 10);
		}
	}
}

void Player::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_LEFT:
		m_Velocity = -m_MoveSpeed;
		break;
	case SDLK_RIGHT:
		m_Velocity = m_MoveSpeed;
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

void Player::IncreaseSpeed(float speedIncrease)
{
	m_MoveSpeed += speedIncrease;
}

void Player::IncreaseShootSpeed(float shootSpeedIncrease)
{
	m_ShootSpeed -= m_ShootSpeed / shootSpeedIncrease;
}

void Player::SetDubbelShot(bool dubbelShot)
{
	m_DubbelShot = dubbelShot;
}

void Player::SpawnBullet()
{
	for (int i = 0; i < 200; i++)
	{
		if (m_BulletIndex == i) {
			m_Bullets[i].m_IsActive = true;
			m_Bullets[i].m_Position = m_Position;
			m_Bullets[i].m_Velocity = 500;
			m_Bullets[i].m_LifeTime = 0;
			if(m_DubbelShot && m_Switch){
				m_Bullets[i].m_Position.x += m_Size.x / 2 - 10;
				m_Switch = false;
			}
			else if (m_DubbelShot && !m_Switch)
			{
				m_Bullets[i].m_Position.x += m_Size.x / 2 + 10;
				m_Switch = true;
			}
			else {
				m_Bullets[i].m_Position.x += m_Size.x / 2;
			}
			m_Bullets[i].m_Position.y += 50;
		}
	}
	m_BulletIndex++;
	if(m_BulletIndex >= 200)
	{
		m_BulletIndex = 0;
	}
}

void Player::CheckBulletCollision()
{
	for (int i = 0; i < 200; i++)
	{
		if (m_Bullets[i].m_IsActive)
		{
			for (int f = 0; f < 8; f++)
			{
				if(m_Game->IsEnemyAlive(f)){
					Point2f loc = m_Game->GetEnemyPosition(f);
					if(loc.x <= m_Bullets[i].m_Position.x  && loc.x + 40 >= m_Bullets[i].m_Position.x && loc.y <= m_Bullets[i].m_Position.y + 10 && loc.y + 40 >= m_Bullets[i].m_Position.y)
					{
						m_Bullets[i].m_IsActive = false;
						m_Game->KillEnemy(f);
						m_Game->AddPoints(1);
					}
				}
			}
			
		}
	}
}
