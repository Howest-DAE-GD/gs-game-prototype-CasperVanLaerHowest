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
	m_pAllTextures[0] = new Texture("Map1.png");
	m_pAllTextures[1] = new Texture("End.png");
}
