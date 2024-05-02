#include "pch.h"
#include "TextManager.h"

TextManager::TextManager(TextureManager* textureManager) : 
	m_textureManager(textureManager)
{
	for(int i = 0; i < 20; i++)
	{
		m_blocks[i] = new Block{ Point2f{700,650.f - (150 * i)},100,m_textureManager, "gold"};
	}
	UpdateCostStart();
}

TextManager::~TextManager()
{
	for (int i = 0; i < 20; i++)
	{
		delete m_blocks[i];
		m_blocks[i] = nullptr;
	}
}

void TextManager::Draw() const
{
	for (int i = 0; i < 20; i++)
	{
		m_blocks[i]->Draw();
	}
}

void TextManager::UpdateCostStart()
{
	for(int i = 0; i < 20; i++)
	{
		m_blocks[i]->updateCost(0 + (1000 * i * (1.6 * i)));
	}
}

void TextManager::CheckCollision(float x, float y)
{
	for (int i = 0; i < 20; i++)
	{
		float s_y = m_blocks[i]->getcolision().bottom;
		float s_x = m_blocks[i]->getcolision().left;
		float s_w = m_blocks[i]->getcolision().width;
		float s_h = m_blocks[i]->getcolision().height;
		if (x >= s_x && x <= s_x + s_w && y >= s_y && y <= s_y + s_h) {
			m_blocks[i]->updateAmount();
		}
	}
}

void TextManager::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		CheckCollision(e.x, e.y);
		break;
	case SDL_BUTTON_RIGHT:

		break;
	case SDL_BUTTON_MIDDLE:

		break;
	}
}
