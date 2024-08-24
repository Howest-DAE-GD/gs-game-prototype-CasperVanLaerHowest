#pragma once

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

	void Update(float elapsedSec);
	void Draw();

	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);

private:
	Game* m_Game;

	//player
	Point2f m_Position;
	Point2f m_Size;
	Color4f m_Color;
	float m_Velocity;
	float m_ShootTimer;

	//bullets
	Bullet m_Bullets[10];
	int m_BulletIndex = 0;

	//functions
	void SpawnBullet();
	void CheckBulletCollision();
};

