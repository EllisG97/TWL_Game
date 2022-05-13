#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
protected:
	//A sprite for the character
	Sprite m_Sprite;
	
	//How long can they jump?
	float m_JumpDuration;

	//Is the character currently jumping or falling?
	bool m_IsJumping;
	bool m_IsFalling;

	//Direction the character is moving
	bool m_LeftPressed;
	bool m_RightPressed;

	//How long have they jumped for?
	float m_TimeThisJump;

	//Has the player pressed the jump button?
	bool m_JustJumped = false;


private:
	//current gravity
	float m_Gravity;

	//How fast is the current character
	float m_Speed = 400;

	//Where is the player located?
	Vector2f m_Position;

	//Characters body part locations
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;
	FloatRect m_Feet;

	//character texture
	Texture m_Texture;



public:




};


