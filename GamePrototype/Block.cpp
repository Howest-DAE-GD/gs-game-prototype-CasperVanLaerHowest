#include "pch.h"
#include "Block.h"

Block::Block(Point2f location, uint64_t startValue, TextureManager* textureManager, std::string name) :
m_Location{ location }, m_Value{ startValue }, m_TextureManager{ textureManager }
{
	std::string newText = std::to_string(m_Value);
	std::string amount = std::to_string(m_Amount);
	m_pText = new Text{ newText,Point2f{m_Location.x + 10,m_Location.y + 10},m_TextureManager};
	m_pTextCost = new Text{ "cost",Point2f{m_Location.x + 10,m_Location.y + 40},m_TextureManager};
	m_pAmountText = new Text{ "amount",Point2f{m_Location.x + 10,m_Location.y + 70},m_TextureManager};
	m_pAmount = new Text{ amount,Point2f{m_Location.x + 170,m_Location.y + 70},m_TextureManager};
	m_pName = new Text{ name,Point2f{m_Location.x + 10,m_Location.y + 100},m_TextureManager};
}

Block::~Block()
{
	delete m_pText;
	delete m_pTextCost;
	delete m_pAmountText;
	delete m_pAmount;
	delete m_pName;
}

void Block::Draw() const
{
	utils::SetColor(Color4f{ 0.5f,0.5f,0.5f,1.0f });
	utils::FillRect(m_Location.x, m_Location.y, m_WidhtHeight.x, m_WidhtHeight.y);
	m_pText->Draw();
	m_pTextCost->Draw();
	m_pAmountText->Draw();
	m_pAmount->Draw();
	m_pName->Draw();
}

void Block::updateCost(uint64_t increase)
{
	uint64_t number = std::stoi(m_pText->GetText());
	number += increase;
	m_pText->SetText(std::to_string(number));
}

void Block::updateAmount()
{
	int number = std::stoi(m_pAmount->GetText());
	number++;
	m_pAmount->SetText(std::to_string(number));
}

Rectf Block::getcolision()
{
	return Rectf(m_Location.x,m_Location.y,m_WidhtHeight.x,m_WidhtHeight.y);
}

uint64_t Block::getValue()
{
	return m_Value;
}
