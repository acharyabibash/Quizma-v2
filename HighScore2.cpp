#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "HighScore2.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Quizma
{
	HighScore2::HighScore2(GameDataRef data) : _data(data)
	{

	}

	void HighScore2::Init()
	{
		this->_data->assets.LoadTexture("HighScore Background", OPTONS_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Back Button Image", BACK_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("HighScore Background"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button Image"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));	

		_cursor.setScale(0.35, 0.35);
	}

	void HighScore2::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}
			}

			if (this->_data->input.IsSpriteClicked(this->_backButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			_backButton.setPosition(1700, 950);
			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
		}
	}

	void HighScore2::Update(float dt)
	{

	}

	void HighScore2::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_backButton);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}

}