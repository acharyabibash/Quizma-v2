#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "Games.hpp"
#include "Categories.hpp"

#include <iostream>

namespace Quizma
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init()
	{
		_name_file.open(PLAYER_RECORD_FILEPATH, std::ios::app);
		

		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Over", GAME_OVER_IMAGE);
		this->_data->assets.LoadTexture("Quit Image", QUIT_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);
		this->_data->assets.LoadTexture("Play Again", PLAY_AGAIN_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Return To Title", RETURN_TO_TITLE_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_playAgain.setTexture(this->_data->assets.GetTexture("Play Again"));
		_gameOver.setTexture(this->_data->assets.GetTexture("Game Over"));
		_quit.setTexture(this->_data->assets.GetTexture("Quit Image"));
		_returnToTitle.setTexture(this->_data->assets.GetTexture("Return To Title"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));

		_cursor.setScale(0.35, 0.35);
	
		_gameOver.setPosition((SCREEN_WIDTH / 2) - (_gameOver.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_gameOver.getGlobalBounds().height / 2));
		_cursor.setPosition((SCREEN_WIDTH / 2) - (_cursor.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_cursor.getGlobalBounds().height / 2));
		_playAgain.setPosition(800, 950);
		_returnToTitle.setPosition(1200, 950);
		_quit.setPosition(1700, 950);

	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			// For moving to the categories selection(for the same player)
			if (this->_data->input.IsSpriteClicked(this->_playAgain, sf::Mouse::Left, this->_data->window))
			{
				// Go to the next page/question

				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new Categories(_data)), true);
			}
			if ((this->_data->input.IsSpriteClicked(this->_returnToTitle, sf::Mouse::Left, this->_data->window)) || (this->_data->input.IsSpriteClicked(this->_quit, sf::Mouse::Left, this->_data->window)) )
			{
				_name_file << this->_data->score << ":";
				if (this->_data->category == 0)
					_name_file << "Math" << std::endl;
				if (this->_data->category == 1)
					_name_file << "Sport" << std::endl;

				//for returning to the main screen title
				if (this->_data->input.IsSpriteClicked(this->_returnToTitle, sf::Mouse::Left, this->_data->window))
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
				}

				//for exiting 
				if (this->_data->input.IsSpriteClicked(this->_quit, sf::Mouse::Left, this->_data->window))
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					_data->window.close();
				}
			}
		
			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));

		}
	}

	void GameOverState::Update(float dt)
	{
		
	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_gameOver);
		this->_data->window.draw(this->_playAgain);
		this->_data->window.draw(this->_quit);
		this->_data->window.draw(this->_returnToTitle);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}
}