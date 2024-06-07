#include "pch.h"
#include "TextManager.h"



TextManager::TextManager(TextureManager* textureManager) : 
	m_textureManager(textureManager)
{
	m_money = new Text{ "0",Point2f{20,700},m_textureManager };
	for(int i = 0; i < 20; i++)
	{
		m_blocks[i] = new Block{ Point2f{700,650.f - (150 * i)},100,m_textureManager, "gold", 3 + (5 * i * i * i ) };
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
	
	DrawCorrectTexture();
	for (int i = 0; i < 20; i++)
	{
		m_blocks[i]->Draw();
	}
	m_money->Draw();

	
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
			if (m_blocks[i]->GetCost() <= m_allMoney) {
				m_allMoney -= m_blocks[i]->GetCost();
				m_blocks[i]->updateAmount();
				m_blocks[i]->updateCost(m_blocks[i]->getValue() * (1.005 * (float)m_blocks[i]->getAmount()));
			}
		}
	}
}

void TextManager::addMoney()
{
	m_allMoney += 100.f;
}

void TextManager::SetSize()
{
	m_size = m_allMoney / 10.f;
}

int TextManager::GetCorrectTexture() const
{
	if (m_allMoney < 1000)
	{
		return 1;
	}
	else if (m_allMoney < 10000)
	{
		return 2;
	}
	else if (m_allMoney < 100000)
	{
		return 3;
	}
	else if (m_allMoney < 1000000)
	{
		return 4;
	}
	else if (m_allMoney < 10000000)
	{
		return 5;
	}
	else if (m_allMoney < 100000000)
	{
		return 6;
	}
	else if (m_allMoney < 1000000000)
	{
		return 7;
	}
	else if (m_allMoney < 10000000000)
	{
		return 8;
	}
	else if (m_allMoney < 100000000000)
	{
		return 9;
	}
	else 
	{
		return 10;
	}
	
}

void TextManager::DrawCorrectTexture() const
{
	int divide = 1;
	if (GetCorrectTexture() == 1) {
		divide = 1;
	}
	else if (GetCorrectTexture() == 2) {
		divide = 7;
	}
	else if (GetCorrectTexture() == 3) {
		divide = 70;
	}
	else if (GetCorrectTexture() == 4) {
		divide = 700;
	}
	else if (GetCorrectTexture() == 5) {
		divide = 7000;
	}
	else if (GetCorrectTexture() == 6) {
		divide = 70000;
	}
	else if (GetCorrectTexture() == 7) {
		divide = 700000;
	}
	else if (GetCorrectTexture() == 8) {
		divide = 7000000;
	}
	else if (GetCorrectTexture() == 9) {
		divide = 70000000;
	}
	else if (GetCorrectTexture() == 10) {
		divide = 700000000;
	}
	m_textureManager->Draw(GetCorrectTexture(), Rectf{ 300 - m_size / divide,350 - m_size / divide,100 + (m_size / divide * 2) ,100 + (m_size / divide * 2) });
}

void TextManager::UpdateMoney()
{
	float total = 0;
	for (int i = 0; i < 20; i++)
	{
		total += m_blocks[i]->GetMoneyGained() * m_blocks[i]->getAmount();
	}
	m_allMoney  += ((float)((float)total / 15.f));
	m_money->SetText(std::to_string((int)m_allMoney));
	SetSize();
}

void TextManager::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		CheckCollision(e.x, e.y);
		addMoney();
		break;
	case SDL_BUTTON_RIGHT:

		break;
	case SDL_BUTTON_MIDDLE:

		break;
	}
}

void TextManager::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	switch ( e.keysym.sym )
	{
	case SDLK_UP:
		for (int i = 0; i < 20; i++)
		{
			m_blocks[i]->Updatelocation(true);
		}
		break;
	case SDLK_DOWN:
		for (int i = 0; i < 20; i++)
		{
			m_blocks[i]->Updatelocation(false);
		}
		break;
	}
}
