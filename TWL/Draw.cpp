#include "pch.h"
#include "Engine.h"

void Engine::draw()
{
	//clear the previous frame
	m_Window.clear(Color::White);

	//update shader parameters
	m_RippleShader.setUniform("uTime", m_GameTimeTotal.asSeconds());
	
	if (!m_SplitScreen)
	{
		//Switch to the background view
		m_Window.setView(m_BGMainView);

		//draw the background with shaders
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		//Switch to the main view
		m_Window.setView(m_MainView);

		//Draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//Draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		//Draw Bob
		m_Window.draw(m_Bob.getSprite());

		//draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}


	}

	else

	{
		//Split screen view is active
		//Draw thomas' side of the screen first
		
		//Switch to the background view
		m_Window.setView(m_BGLeftView);		

		//Draw the background with shaders
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		//Switch to the left view for Thomas
		m_Window.setView(m_LeftView);

		//draw the level
		m_Window.draw(m_VALevel, &m_TextureTiles);

		//draw Bob
		m_Window.draw(m_Bob.getSprite());

		//draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		//draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

		//Now draw bobs side of the screen

		//Switch to the background view
		m_Window.setView(m_BGRightView);

		//Draw the Background with shaders
		m_Window.draw(m_BackgroundSprite, &m_RippleShader);

		//Switch to the right view for Bob
		m_Window.setView(m_RightView);

		//draw the level 
		m_Window.draw(m_VALevel, &m_TextureTiles);


		//draw Thomas
		m_Window.draw(m_Thomas.getSprite());

		//draw Bob
		m_Window.draw(m_Bob.getSprite());

		//draw the particle system
		if (m_PS.running())
		{
			m_Window.draw(m_PS);
		}

	}

	//Draw the HUD
	//Switch to the m_HudView
	m_Window.setView(m_HudView);
	m_Window.draw(m_Hud.getLevel());
	m_Window.draw(m_Hud.getTime());
	if (!m_Playing)
	{
		m_Window.draw(m_Hud.getMessage());
	}

	//Show everything that has been drawn
	m_Window.display();


}