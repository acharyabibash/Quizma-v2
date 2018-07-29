#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "HighScore.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Quizma
{
	int j = 0;
	sf::Vector2i positionText(635, 450);
	HighScore::HighScore(GameDataRef data) : _data(data)
	{

	}

	void HighScore::Init()
	{
		this->_data->window.setMouseCursorVisible(false);

		_name_file.open(PLAYER_RECORD_FILEPATH);
		_font.loadFromFile(PLAYER_FONT_FILEPATH);
		_text.setFont(_font);
		_text.setCharacterSize(50);
		_text.setFillColor(sf::Color::Black);

		this->_data->assets.LoadTexture("High Score Background", HIGH_SCORE_FILEPATH);
		this->_data->assets.LoadTexture("Back", BACK_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("High Score Background"));
		_backButton.setTexture(this->_data->assets.GetTexture("Back"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));
		_cursor.setScale(0.35, 0.35);

		_cursor.setPosition((SCREEN_WIDTH / 2) - (_cursor.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_cursor.getGlobalBounds().height / 2));
		_backButton.setPosition(1300, 950);

		if (_name_file.is_open())
		{
			j = 0;
			std::string line;
			while (std::getline(_name_file, line)) {
				
				if ((line[line.length() - 1] - '0') == this->_data->category) {
					result.push_back(line);
					j++;
				}
			}
			_name_file.close();
		}
		std::sort(result.begin(), result.end());
		for (std::vector<std::string>::iterator it = result.begin(); it != result.end(); ++it) {
			std::cout << ' ' << *it;
			std::cout << '\n';
		}
		
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
			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));


		}
	}

	void HighScore::Update(float dt)
	{

	}

	void HighScore::Draw(float dt)
	{
		
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);

		for (int i = 0; i < j; i++) 
		{
			_text.setPosition(positionText.x,positionText.y);
			_text.setString(result[i]);
			this->_data->window.draw(_text);
			positionText.y += 55;
		}

		
		this->_data->window.draw(this->_backButton);
		this->_data->window.draw(this->_cursor);

		this->_data->window.display();
	}


}