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
	m_TextManager = new TextManager(m_TextureManager);
	//m_Text = new Text("100", Point2f{ 100,100 }, m_TextureManager);
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	 //Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		std::string text = m_Text->GetText();
		uint64_t number = std::stoi(text);
		number++;
		std::string newText = std::to_string(number);

		m_Text->SetText(newText);
	}
	if ( pStates[SDL_SCANCODE_LEFT] )
	{
		std::string text = m_Text->GetText();
		 uint64_t number = std::stoi(text);
		number--;
		std::string newText = std::to_string(number);
		m_Text->SetText(newText);
	}
	m_TextManager->UpdateMoney();
}

void Game::Draw( ) const
{
	ClearBackground( );
	m_TextManager->Draw();
	//m_Text->Draw();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
	m_TextManager->ProcessKeyDownEvent(e);
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
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
	m_TextManager->ProcessMouseDownEvent(e);
	//std::cout << "MOUSEBUTTONDOWN event: ";
	/*switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		
		break;
	case SDL_BUTTON_RIGHT:
		
		break;
	case SDL_BUTTON_MIDDLE:
		
		break;
	}*/
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

void Game::ClearBackground( ) const
{
	glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
