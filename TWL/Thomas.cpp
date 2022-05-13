#include "pch.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	//Link a texture to the Thomas Sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/thomas.png"));

	m_JumpDuration = .45;

}

//another virtual function
bool Thomas::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		//Thomas will jump as long as he isnt already
		//he must also be on a block and not falling
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

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			m_LeftPressed = true;
		}
		else
		{
			m_LeftPressed = false;
		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			m_RightPressed = true;
		}
		else
		{
			m_RightPressed = false;
		}

		return m_JustJumped;

	}




}