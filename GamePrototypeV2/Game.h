#pragma once
#include "BaseGame.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Texture.h"

enum class GameState
{
	game,
	gameOver
};

class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

	Point2f GetEnemyPosition(int index);
	void KillEnemy(int index);
	void AddPoints(int points);
	bool IsEnemyAlive(int index);

private:
	GameState m_GameState{ GameState::game };

	TextureManager* m_TextureManager;
	Player* m_Player;
	Enemy* m_Enemy[8];

	Texture* m_PointTexture;
	int m_Points{ 0 };

	Texture* m_HealthTexture;
	int m_Health{ 1 };

	Texture* m_WaveTexture;
	int m_Wave{ 1 };

	bool m_Paused{ false };
	Texture* m_CardTexture[3];
	int m_Card[3];

	float m_Counter{ 3.f };
	Texture* m_AchievementTexture;

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;

	void CheckDamage();
	void ResetWave();
	void CheckGameState();
	void ShowCards();
	void SetRandomCard();
};