#pragma once
#include "TextureManager.h"
#include "Block.h"
class TextManager
{
public:
	TextManager(TextureManager* textureManager);
	~TextManager();

	void Draw() const;

	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e) ;
private:
	TextureManager* m_textureManager;
	Block* m_blocks[20];
	void UpdateCostStart();

	void CheckCollision(float x, float y);
};

