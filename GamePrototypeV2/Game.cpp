#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_TextureManager = new TextureManager();
	for (int i = 0; i < 8; i++)
	{
		m_Enemy[i] = new Enemy();
	}
	m_Player = new Player(this);
	
}

void Game::Cleanup( )
{
	delete m_TextureManager;
	delete m_Player;

	for (int i = 0; i < 8; i++)
	{
		delete m_Enemy[i];
	}
	delete m_PointTexture;
	delete m_HealthTexture;
}

void Game::Update( float elapsedSec )
{
	if(m_GameState == GameState::game){
		m_Player->Update(elapsedSec);

		for (int i = 0; i < 8; i++)
		{
			m_Enemy[i]->Update(elapsedSec);
		}
		m_PointTexture = new Texture("Points : " + std::to_string(m_Points), "arial.ttf", 24, Color4f{1.f ,0.f,0.f,1.f});
		m_HealthTexture = new Texture("Health : " + std::to_string(m_Health), "arial.ttf", 24, Color4f{ 1.f ,0.f,0.f,1.f });

		CheckDamage();
		ResetWave();
		CheckGameState();	
	}
	else if (m_GameState == GameState::gameOver) {

		m_PointTexture = new Texture("Final Score : " + std::to_string(m_Points), "arial.ttf", 48, Color4f{ 1.f ,0.f,0.f,1.f });
	}
}

void Game::Draw() const
{
	ClearBackground();
	if (m_GameState == GameState::game) {
		m_TextureManager->Draw(0, Rectf(0, 0, 800, 900));
		m_Player->Draw();

		for (int i = 0; i < 8; i++)
		{
			if (m_Enemy[i]->GetIsAlive() == true) {
				m_Enemy[i]->Draw();
			}
		}

		m_PointTexture->Draw(Point2f{ 40, 10 });
		m_HealthTexture->Draw(Point2f{ 40, 40 });
	}
	else if (m_GameState == GameState::gameOver) {
		m_TextureManager->Draw(1, Rectf(0, 0, 800, 900));
		m_PointTexture->Draw(Point2f{ 225, 425 });
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	m_Player->ProcessKeyDownEvent(e);
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	m_Player->ProcessKeyUpEvent(e);
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

Point2f Game::GetEnemyPosition(int index)
{
	return m_Enemy[index]->GetPosition();
}

void Game::KillEnemy(int index)
{
	m_Enemy[index]->SetIsAlive(false);
}

void Game::AddPoints(int points)
{
	m_Points += points;
}

bool Game::IsEnemyAlive(int index)
{
	return m_Enemy[index]->GetIsAlive();
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::CheckDamage()
{
	for (int i = 0; i < 8; i++)
	{
		if (m_Enemy[i]->GetIsAlive() == true) {
			if (m_Enemy[i]->GetPosition().y < 50)
			{
				m_Health -= 1;
				m_Enemy[i]->SetIsAlive(false);
			}
		}
	}
}

void Game::ResetWave()
{
	int counter = 0;
	for (int i = 0; i < 8; i++)
	{
		if(m_Enemy[i]->GetIsAlive() == false)
		{
			counter++;
		}
	}
	if(counter == 8)
	{
		for (int i = 0; i < 8; i++)
		{
			m_Enemy[i]->Reset();
			m_Enemy[i]->IncreaseSpeed(rand() % 30);
		}
	}
}

void Game::CheckGameState()
{
	if (m_Health <= 0)
	{
		m_GameState = GameState::gameOver;
	}
}
