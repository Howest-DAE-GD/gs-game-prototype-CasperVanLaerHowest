#pragma once
#include "TextureManager.h"
#include "Block.h"
#include "Text.h"
#include "utils.h"
class TextManager
{
public:
	TextManager(TextureManager* textureManager);
	~TextManager();

	void Draw() const;

	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e);
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);

	void UpdateMoney();
private:
	TextureManager* m_textureManager;
	Block* m_blocks[20];

	Text* m_money;

	float m_allMoney{ 100.f };

	float m_size{ 0.f };

	void UpdateCostStart();
	void CheckCollision(float x, float y);
	void addMoney();
	void SetSize();
	int GetCorrectTexture() const;
	void DrawCorrectTexture() const;
};

