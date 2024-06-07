#pragma once
#include <iostream>

class TextureManager;
class Text
{
public:
	Text(std::string text, Point2f location, TextureManager* textureManager);
	~Text();

	void Draw() const;
	void Update(float elapsedSec);

	void SetText(std::string text);
	std::string GetText() const;
	void SetLocation(Point2f location);
private:

	TextureManager* m_TextureManager;
	std::string m_Text;
	Point2f m_Location;
	bool m_Visible{ false };
	int m_LetterCounter{ 0 };
	size_t m_LetterCounterMax{ 0 };
	Point2f m_LetterSize;
	float m_Counter{ 0 };

	Rectf GetRect(char letter) const;

};



