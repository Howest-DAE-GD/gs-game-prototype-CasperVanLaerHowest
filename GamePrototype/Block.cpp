#include "pch.h"
#include "Block.h"

Block::Block(Point2f location, uint64_t startValue, TextureManager* textureManager, std::string name, int moneyGained) :
m_Location{ location }, m_Value{ startValue }, m_TextureManager{ textureManager },m_MoneyGained{moneyGained}
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
	utils::SetColor(GetColor());
	utils::FillRect(m_Location.x, m_Location.y, m_WidhtHeight.x, m_WidhtHeight.y);

	//says value
	m_pText->Draw();

	//says cost
	m_pTextCost->Draw();

	//says amount
	m_pAmountText->Draw();

	//says how uch of it you have
	m_pAmount->Draw();

	//says the name of the block
	m_pName->Draw();
}

void Block::updateCost(uint64_t increase)
{
	uint64_t number = std::stoi(m_pText->GetText());
	number += increase;
	//m_Value = number;
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

int Block::getAmount() const
{
	int number = std::stoi(m_pAmount->GetText());
	return number;
}

int Block::GetMoneyGained()
{
	return m_MoneyGained;
}

int Block::GetCost()
{
	return std::stoi(m_pText->GetText());
}

void Block::Updatelocation(bool up)
{
	if (up) {
		m_Location.y += 5;
		m_pText->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 10 });
		m_pTextCost->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 40 });
		m_pAmountText->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 70 });
		m_pAmount->SetLocation(Point2f{ m_Location.x + 170,m_Location.y + 70 });
		m_pName->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 100 });

	}
	else {
		m_Location.y -= 5;
		m_pText->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 10 });
		m_pTextCost->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 40 });
		m_pAmountText->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 70 });
		m_pAmount->SetLocation(Point2f{ m_Location.x + 170,m_Location.y + 70 });
		m_pName->SetLocation(Point2f{ m_Location.x + 10,m_Location.y + 100 });
	}
}

Color4f Block::GetColor() const
{
	if (getAmount() < 5) 
	{
		return Color4f{ 0.5f,0.5f,0.5f,1.0f };
	} else if (getAmount() < 10)
	{
		return Color4f{ 1.f,0.5f,0.5f,1.0f };
	}
	else if (getAmount() < 15) {
		return Color4f{ 0.5f,1.f,0.5f,1.0f };
	}
	else if (getAmount() < 20) {
		return Color4f{ 0.5f,0.5f,1.f,1.0f };
	}
	else if (getAmount() > 19) {
		return Color4f{ 1.f,1.f,0.5f,1.0f };
	}
}
