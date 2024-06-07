#include "pch.h"
#include "Text.h"
#include "TextureManager.h"

Text::Text(std::string text, Point2f location, TextureManager* textureManager) :
	m_Text{ text },
	m_Location{ location },
	m_TextureManager{ textureManager }
{
	m_LetterCounterMax = m_Text.size();
	m_LetterSize = m_TextureManager->GetWidthHeight(0);
	m_LetterSize.x /= 26;
	m_LetterSize.y /= 6;
}

Text::~Text()
{

}

void Text::Draw() const
{
	for (int index = 0; index < m_LetterCounterMax; index++)
	{
		char letter = m_Text.at(index);
		m_TextureManager->Draw(0, GetRect(letter), Rectf{ m_Location.x + (m_LetterSize.x * 3.f * index),m_Location.y ,m_LetterSize.x * 3.f,m_LetterSize.y * 3.f });
	}
}

void Text::Update(float elapsedSec)
{
	
}

void Text::SetText(std::string text)
{
	m_Text = text;
	m_LetterCounterMax = m_Text.size();
}

std::string Text::GetText() const
{
	return m_Text;
}

void Text::SetLocation(Point2f location)
{
	m_Location = location;
}

Rectf Text::GetRect(char letter) const
{
	switch (letter)
	{
	case 'A':
		return Rectf{ (m_LetterSize.x * 0),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'B':
		return Rectf{ (m_LetterSize.x * 1),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'C':
		return Rectf{ (m_LetterSize.x * 2),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'D':
		return Rectf{ (m_LetterSize.x * 3),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'E':
		return Rectf{ (m_LetterSize.x * 4),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'F':
		return Rectf{ (m_LetterSize.x * 5),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'G':
		return Rectf{ (m_LetterSize.x * 6),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'H':
		return Rectf{ (m_LetterSize.x * 7),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'I':
		return Rectf{ (m_LetterSize.x * 8),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'J':
		return Rectf{ (m_LetterSize.x * 9),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'K':
		return Rectf{ (m_LetterSize.x * 10),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'L':
		return Rectf{ (m_LetterSize.x * 11),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'M':
		return Rectf{ (m_LetterSize.x * 12),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'N':
		return Rectf{ (m_LetterSize.x * 13),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'O':
		return Rectf{ (m_LetterSize.x * 14),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'P':
		return Rectf{ (m_LetterSize.x * 15),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'Q':
		return Rectf{ (m_LetterSize.x * 16),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'R':
		return Rectf{ (m_LetterSize.x * 17),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'S':
		return Rectf{ (m_LetterSize.x * 18),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'T':
		return Rectf{ (m_LetterSize.x * 19),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'U':
		return Rectf{ (m_LetterSize.x * 20),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'V':
		return Rectf{ (m_LetterSize.x * 21),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'W':
		return Rectf{ (m_LetterSize.x * 22),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'X':
		return Rectf{ (m_LetterSize.x * 23),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'Y':
		return Rectf{ (m_LetterSize.x * 24),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'Z':
		return Rectf{ (m_LetterSize.x * 25),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'a':
		return Rectf{ (m_LetterSize.x * 0),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'b':
		return Rectf{ (m_LetterSize.x * 1),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'c':
		return Rectf{ (m_LetterSize.x * 2),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'd':
		return Rectf{ (m_LetterSize.x * 3),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'e':
		return Rectf{ (m_LetterSize.x * 4),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'f':
		return Rectf{ (m_LetterSize.x * 5),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'g':
		return Rectf{ (m_LetterSize.x * 6),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'h':
		return Rectf{ (m_LetterSize.x * 7),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'i':
		return Rectf{ (m_LetterSize.x * 8),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'j':
		return Rectf{ (m_LetterSize.x * 9),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'k':
		return Rectf{ (m_LetterSize.x * 10),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'l':
		return Rectf{ (m_LetterSize.x * 11),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'm':
		return Rectf{ (m_LetterSize.x * 12),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'n':
		return Rectf{ (m_LetterSize.x * 13),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'o':
		return Rectf{ (m_LetterSize.x * 14),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'p':
		return Rectf{ (m_LetterSize.x * 15),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'q':
		return Rectf{ (m_LetterSize.x * 16),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'r':
		return Rectf{ (m_LetterSize.x * 17),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 's':
		return Rectf{ (m_LetterSize.x * 18),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 't':
		return Rectf{ (m_LetterSize.x * 19),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'u':
		return Rectf{ (m_LetterSize.x * 20),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'v':
		return Rectf{ (m_LetterSize.x * 21),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'w':
		return Rectf{ (m_LetterSize.x * 22),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'x':
		return Rectf{ (m_LetterSize.x * 23),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'y':
		return Rectf{ (m_LetterSize.x * 24),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case 'z':
		return Rectf{ (m_LetterSize.x * 25),(m_LetterSize.y * 5),m_LetterSize.x,m_LetterSize.y };
		break;
	case ' ':
		return Rectf{ (m_LetterSize.x * 25),(m_LetterSize.y * 4),m_LetterSize.x,m_LetterSize.y };
		break;
	case '0':
		return Rectf{ (m_LetterSize.x * 0),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '1':
		return Rectf{ (m_LetterSize.x * 1),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '2':
		return Rectf{ (m_LetterSize.x * 2),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '3':
		return Rectf{ (m_LetterSize.x * 3),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '4':
		return Rectf{ (m_LetterSize.x * 4),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '5':
		return Rectf{ (m_LetterSize.x * 5),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '6':
		return Rectf{ (m_LetterSize.x * 6),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '7':
		return Rectf{ (m_LetterSize.x * 7),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '8':
		return Rectf{ (m_LetterSize.x * 8),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	case '9':
		return Rectf{ (m_LetterSize.x * 9),(m_LetterSize.y * 1),m_LetterSize.x,m_LetterSize.y };
		break;
	default:
		return Rectf{ (m_LetterSize.x * 25),(m_LetterSize.y * 3),m_LetterSize.x,m_LetterSize.y };
		break;
	}
}

