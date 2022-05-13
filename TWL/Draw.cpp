#include "pch.h"
#include "Engine.h"

void Engine::draw()
{
	//clear the previous frame
	m_Window.clear(Color::White);
	
	if (!m_SplitScreen)
	{
		//Switch to the background view
		m_Window.setView(m_BGMainView);

		//draw the background 
		m_Window.draw(m_BackgroundSprite);

		//Switch to the main view
		m_Window.setView(m_MainView);


	}

	else

	{
		//Split screen view is active
		//Draw thomas' side of the screen first
		
		//Switch to the background view
		m_Window.setView(m_BGLeftView);		
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to the left view for Thomas
		m_Window.setView(m_LeftView);

		//Now draw bobs side of the screen

		//Switch to the background view
		m_Window.setView(m_BGRightView);
		//Draw the Background
		m_Window.draw(m_BackgroundSprite);
		//Switch to the right view for Bob
		m_Window.setView(m_RightView);

	}

	//Draw the HUD
	//Switch to the m_HudView
	m_Window.setView(m_HudView);
	//Show everything that has been drawn
	m_Window.display();


}