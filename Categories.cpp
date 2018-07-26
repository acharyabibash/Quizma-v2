#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "Categories.hpp"
#include "GameState.hpp"
#include "GameState2.hpp"
#include <iostream>

namespace Quizma
{
	Categories::Categories(GameDataRef data) : _data(data)
	{

	}


	void Categories::Init()
	{

		this->_data->window.setMouseCursorVisible(false);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);
		this->_data->assets.LoadTexture("Background", CATEGORY_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Maths and Logics",CATEGORY_1);
		this->_data->assets.LoadTexture("Sports", CATEGORY_2);

		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));
		_maths_and_logic.setTexture(this->_data->assets.GetTexture("Maths and Logics"));
		_sports.setTexture(this->_data->assets.GetTexture("Sports"));

		_maths_and_logic.setPosition(100, 100);
		_sports.setPosition(100, 300);

		_cursor.setScale(0.35, 0.35);

	}

	void Categories::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			/*if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}*/

			if (sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->_data->window.close();
				}
			}

			if (this->_data->input.IsSpriteClicked(this->_maths_and_logic, sf::Mouse::Left, this->_data->window))
			{
				// Switch to the maths and logic section
				//this->_data->music.pause();
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);

				// For random questions per execution
				this->_data->qa_vector.shuffleQuestions();
				this->_data->question_vector = this->_data->qa_vector.passQuestion();
			}

			if (this->_data->input.IsSpriteClicked(this->_sports, sf::Mouse::Left, this->_data->window))
			{
				//Switch to the sports section
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new GameState2(_data)), true);

				// For random questions per execution
				this->_data->qa_vector.shuffleQuestions();
				this->_data->question_vector = this->_data->qa_vector.passQuestion();
			}

			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
		}
	}

	void Categories::Update(float dt)
	{

	}

	void Categories::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_maths_and_logic);

		this->_data->window.draw(this->_sports);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}
}