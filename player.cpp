#include <sstream>
#include "DEFINITIONS.hpp"
#include "player.hpp"
#include "Games.hpp"
#include "GameState.hpp"
#include <SFML/Window.hpp>
#include "Categories.hpp"

#include <iostream>
#include<string>

namespace Quizma
{
	

	player::player(GameDataRef data) : _data(data)
	{

	}

	void player::Init()
	{
		this->_data->assets.LoadTexture("Player Background", PLAYER_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Player Background"));
		std::cout << "The state has been loaded.\n";

		_name_font.loadFromFile(PLAYER_FONT_FILEPATH);
		_name_text.setFont(_name_font);
		_name_text.setCharacterSize(50);
		_name_text.setFillColor(sf::Color::Black);
		_name_text.setPosition(1005, 665);
		_name_text.setOrigin(_name_text.getLocalBounds().width / 2, _name_text.getLocalBounds().height / 2);
		_name_text.scale(1.0f , 1.0f);

	}

	void player::HandleInput()
	{
		sf::Event event;
		
		while (/*_name_file.is_open() && */this->_data->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				this->_data->window.close();
			}
			else if (sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					this->_data->name = _name;
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					std::cout << "Load new state" << std::endl;
					this->_data->machine.AddState(StateRef(new Categories(_data)), true);
				}
				else if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode >= 33 && event.text.unicode <= 126) 
					{
						_name += (char)event.text.unicode;
					}
					else if (event.text.unicode == 8) 
					{
						_name = _name.substr(0, _name.length() - 1);
					
					}
					_name_text.setString(_name);
					_name_text.setOrigin(_name_text.getLocalBounds().width / 2, _name_text.getLocalBounds().height / 2);
				}
				
			}
		}
	}
	
	void player::Update(float dt)
	{

	}

	void player::Draw(float dt)
	{
		this->_data->window.clear();
		
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_border);
		this->_data->window.draw(_name_text);
		this->_data->window.display();
	}


}