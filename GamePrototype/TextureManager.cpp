#include "pch.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
	LoadTextures();
}

TextureManager::~TextureManager()
{
	for (int index = 0; index < M_NR_TEXTURES; index++)
	{
		delete m_pAllTextures[index];
	}
}

void TextureManager::Draw(int id, Rectf srcR) const
{
	m_pAllTextures[id]->Draw(srcR);
}

//void TextureManager::Draw(int id, Rectf srcR, Color4f color) const
//{
//	m_pAllTextures[id]->Draw(srcR, color);
//}

void TextureManager::Draw(int id, Rectf srcR, Rectf desR) const
{
	m_pAllTextures[id]->Draw(desR, srcR);
}

Point2f TextureManager::GetWidthHeight(int id)
{
	return Point2f(m_pAllTextures[id]->GetWidth(), m_pAllTextures[id]->GetHeight());
}

Texture* TextureManager::GetTexturePtr(int id)
{
	return m_pAllTextures[id];
}

void TextureManager::LoadTextures()
{
	m_pAllTextures[0] = new Texture("title.png");
	m_pAllTextures[1] = new Texture("Intro_Scene/foreground_treeline.png");
	m_pAllTextures[2] = new Texture("Intro_Scene/ground.png");
	m_pAllTextures[3] = new Texture("Intro_Scene/midground_treeline_1.png");
	m_pAllTextures[4] = new Texture("Intro_Scene/mountains.png");
	m_pAllTextures[5] = new Texture("Intro_Scene/moon.png");
	m_pAllTextures[6] = new Texture("Intro_Scene/clouds.png");
	m_pAllTextures[7] = new Texture("Intro_Scene/caravan.png");
	m_pAllTextures[8] = new Texture("Intro_Scene/sky.png");
	m_pAllTextures[9] = new Texture("Intro_Scene/MenuItemsNotSelected.png");
	m_pAllTextures[10] = new Texture("Intro_Scene/MenuItemsSelected.png");
	m_pAllTextures[11] = new Texture("Characters/Knight/stand_left.png");
	m_pAllTextures[12] = new Texture("Characters/Knight/stand_right.png");
	m_pAllTextures[13] = new Texture("Characters/Knight/crouch_left.png");
	m_pAllTextures[14] = new Texture("Characters/Knight/crouch_right.png");
	m_pAllTextures[15] = new Texture("Characters/Knight/jump_left.png");
	m_pAllTextures[16] = new Texture("Characters/Knight/jump_right.png");
	m_pAllTextures[17] = new Texture("Characters/Knight/walk_left.png");
	m_pAllTextures[18] = new Texture("Characters/Knight/walk_right.png");
	m_pAllTextures[19] = new Texture("Interactables/chest_small.png");
	m_pAllTextures[20] = new Texture("Interactables/ladder.png");
	m_pAllTextures[21] = new Texture("Characters/Knight/climb.png");
	m_pAllTextures[22] = new Texture("Interactables/sword.png");
	m_pAllTextures[23] = new Texture("Characters/Knight/crawl_Ledge_Left.png");
	m_pAllTextures[24] = new Texture("Characters/Knight/crawl_Ledge_Right.png");
	m_pAllTextures[25] = new Texture("font1.png");
}
