#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
//#include "GameState.hpp"
//#include "GameState2.hpp"
#include "Options.hpp"
#include "player.hpp"
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
		this->_data->assets.LoadTexture("Bulb", BULB_FILEPATH);
		
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_optionsButton.setTexture(this->_data->assets.GetTexture("Options Button"));
		_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));
		_bulb.setTexture(this->_data->assets.GetTexture("Bulb"));

				

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2.5) - (_playButton.getGlobalBounds().height / 2));
		_optionsButton.setPosition((SCREEN_WIDTH / 2) - (_optionsButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 1.75) - (_optionsButton.getGlobalBounds().height / 2));
		_exitButton.setPosition((SCREEN_WIDTH / 2) - (_exitButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT/1.35) - (_exitButton.getGlobalBounds().height / 2));
		_bulb.setPosition(375, 75);
		_cursor.setPosition((SCREEN_WIDTH / 2) - (_cursor.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_cursor.getGlobalBounds().height / 2));

		_cursor.setScale(0.35, 0.35);
		_bulb.setScale(0.5, 0.5);
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

			if (sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->_data->window.close();
				}
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch to the game screen
				//this->_data->music.pause();
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new player(_data)), true);

				/*// For random questions per execution
				this->_data->qa_vector.shuffleQuestions();
				this->_data->question_vector = this->_data->qa_vector.passQuestion();*/
			}

			if (this->_data->input.IsSpriteClicked(this->_optionsButton, sf::Mouse::Left, this->_data->window))
			{
				//Optimize the program
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new Options(_data)), true);
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
		this->_data->window.draw(this->_bulb);

	

		this->_data->window.draw(this->_cursor);
		
		this->_data->window.display();
	}
}