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
	m_pAllTextures[0] = new Texture("font1.png");
	m_pAllTextures[1] = new Texture("guy.png");
	m_pAllTextures[2] = new Texture("guyV2.png");
	m_pAllTextures[3] = new Texture("guyV3.png");
	m_pAllTextures[4] = new Texture("guyV4.png");
	m_pAllTextures[5] = new Texture("guyV5.png");
	m_pAllTextures[6] = new Texture("guyV6.png");
	m_pAllTextures[7] = new Texture("guyV7.png");
	m_pAllTextures[8] = new Texture("guyV8.png");
	m_pAllTextures[9] = new Texture("guyV9.png");
	m_pAllTextures[10] = new Texture("guyV10.png");
}
