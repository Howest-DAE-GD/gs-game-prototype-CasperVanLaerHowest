#pragma once
#include "Text.h"
#include "TextureManager.h"
#include "utils.h"
class Block
{
public:
	Block(Point2f location, uint64_t startValue,TextureManager* textureManager, std::string name);
	~Block();

	void Draw() const;

	void updateCost(uint64_t increase);
	void updateAmount();

	Rectf getcolision();
	uint64_t getValue();
private:
	Point2f m_Location{};
	Point2f m_WidhtHeight{ 250,140 };
	Text* m_pText;
	Text* m_pTextCost;
	Text* m_pAmount;
	Text* m_pAmountText;
	Text* m_pName;
	uint64_t m_Value;
	int m_Amount{ 0 };
	TextureManager* m_TextureManager{};
	
};

