#include "pch.h"
#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{
	//Link a texture to the bob sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/bob.png"));

	m_JumpDuration = .25;

}

bool Bob::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{

		//Start a jump if bob is not jumping
		//and is stood on a block (not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;

		}
		else
		{
			m_IsJumping = false;
			m_IsFalling = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			m_LeftPressed = true;
		}
		else
		{
			m_LeftPressed = false;
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			m_RightPressed = true;
		}
		else
		{
			m_RightPressed = false;
		}

	}

	return m_JustJumped;

}