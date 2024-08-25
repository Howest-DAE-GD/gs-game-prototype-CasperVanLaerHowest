#pragma once
#include "Texture.h"

class Game;

struct Bullet
{
	Point2f m_Position;
	float m_Velocity;
	float m_LifeTime;
	bool m_IsActive;
};

class Player
{
public:
	Player(Game* Game);
	~Player();

	void Update(float elapsedSec);
	void Draw();

	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);

	void IncreaseSpeed(float speedIncrease);
	void IncreaseShootSpeed(float shootSpeedIncrease);

private:
	Game* m_Game;

	//player
	Point2f m_Position;
	Point2f m_Size;
	Color4f m_Color;
	float m_Velocity;
	float m_ShootTimer;

	float m_ShootSpeed = 0.7f;
	float m_MoveSpeed = 250.0f;

	//bullets
	Bullet m_Bullets[50];
	int m_BulletIndex = 0;

	//textures
	Texture* m_MoveSpeedTexture;
	Texture* m_ShootSpeedTexture;

	//functions
	void SpawnBullet();
	void CheckBulletCollision();
};

