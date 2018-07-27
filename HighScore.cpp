#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "HighScore.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Quizma
{
	HighScore::HighScore(GameDataRef data) : _data(data)
	{

	}

	void HighScore::Init()
	{
		this->_data->window.setMouseCursorVisible(false);

		this->_data->assets.LoadTexture("High Score Background", HIGH_SCORE_FILEPATH);
		this->_data->assets.LoadTexture("Back", BACK_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("High Score Background"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));
	
		_cursor.setPosition((SCREEN_WIDTH / 2) - (_cursor.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_cursor.getGlobalBounds().height / 2));
		_backButton.setPosition(1300, 950);
		_cursor.setScale(0.35, 0.35);
	}

	void HighScore::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			
			if (this->_data->input.IsSpriteClicked(this->_backButton, sf::Mouse::Left, this->_data->window))
			{

				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

				_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
			}		
		}
	}

	void HighScore::Update(float dt)
	{

	}

	void HighScore::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_backButton);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}


}