#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "Instruction.hpp"
#include "MainMenuState.hpp"
#include <iostream>

namespace Quizma
{
	Instruction::Instruction(GameDataRef data) : _data(data)
	{

	}

	void Instruction::Init()
	{
		this->_data->assets.LoadTexture("Instruction Background", INSTRUCTION_SCREEN_FILEPATH);
		this->_data->assets.LoadTexture("Next Button Image", NEXT_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Instruction Background"));
		_nextButton.setTexture(this->_data->assets.GetTexture("Next Button Image"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));

		_nextButton.setPosition(1700, 950);

		_cursor.setScale(0.35, 0.35);
	}

	void Instruction::HandleInput()
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

			if (this->_data->input.IsSpriteClicked(this->_nextButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->music3.play();
				this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
			_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
		}
	}

	void Instruction::Update(float dt)
	{

	}

	void Instruction::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_nextButton);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}

}