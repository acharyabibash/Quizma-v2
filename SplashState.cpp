#pragma once

#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace Quizma
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		//For Cursor
		this->_data->window.setMouseCursorVisible(false);

		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
		
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));
		_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
		
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch To Main Menu
			this->_data->music3.play();
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
	
	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		//this->_data->window.setView(fixed);
		//this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}
}