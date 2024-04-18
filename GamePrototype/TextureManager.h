#pragma once
#pragma once
#include "texture.h"
class TextureManager
{
public:

	TextureManager();
	~TextureManager();

	void Draw(int id, Rectf srcR) const;
	/*void Draw(int id, Rectf srcR, Color4f color) const;*/
	void Draw(int id, Rectf srcR, Rectf desR) const;

	Point2f GetWidthHeight(int id);
	Texture* GetTexturePtr(int id);

private:

	static const int M_NR_TEXTURES{ 26 };
	Texture* m_pAllTextures[M_NR_TEXTURES];

	void LoadTextures();

};


