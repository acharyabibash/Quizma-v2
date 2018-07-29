#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "Options.hpp"
#include "player.hpp"
#include "Categories.hpp"
#include "HighscoreCategories.hpp"
#include <iostream>

namespace Quizma
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}
	
	void MainMenuState::Init()
	{

		this->_data->window.setMouseCursorVisible(false);

		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Options Button", OPTIONS_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);
		this->_data->assets.LoadTexture("High Score", HIGH_SCORE_BUTTON);
		
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_optionsButton.setTexture(this->_data->assets.GetTexture("Options Button"));
		_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));
		_highScore.setTexture(this->_data->assets.GetTexture("High Score"));				

		_title.setScale(1.5, 1.5);
		_cursor.setPosition((SCREEN_WIDTH / 2) - (_cursor.getGlobalBounds().width / 2), 900);
		_cursor.setScale(0.35, 0.35);

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 7);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), 350);
		_optionsButton.setPosition((SCREEN_WIDTH / 2) - (_optionsButton.getGlobalBounds().width / 2), 500);
		_highScore.setPosition((SCREEN_WIDTH / 2) - (_highScore.getGlobalBounds().width / 2), 650);
		_exitButton.setPosition((SCREEN_WIDTH / 2) - (_exitButton.getGlobalBounds().width / 2), 800);


	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{			
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}			 					

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch to the game screen
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new player(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_optionsButton, sf::Mouse::Left, this->_data->window))
			{
				//Optimize the program
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new Options(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_highScore, sf::Mouse::Left, this->_data->window))
			{
				//Optimize the program
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new HighscoreCategories(_data)), true);
			}

			if (this->_data->input.IsSpriteClicked(this->_exitButton, sf::Mouse::Left, this->_data->window))
			{
				//Close the program
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->window.close();
			}

			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
		}
	}
	
	void MainMenuState::Update(float dt)
	{

	}	

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_optionsButton);
		this->_data->window.draw(this->_exitButton);
		this->_data->window.draw(this->_highScore);
		this->_data->window.draw(this->_cursor);

		this->_data->window.display();
	}
}