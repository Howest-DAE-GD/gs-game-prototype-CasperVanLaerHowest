#pragma once
class Player
{
public:
	Player();

	void Update(float elapsedSec);
	void Draw();

	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);

private:
	Point2f m_Position;
	Point2f m_Size;
	Color4f m_Color;
	
	float m_Velocity;
};

