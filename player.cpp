#include <sstream>
#include "DEFINITIONS.hpp"
#include "player.hpp"
#include "Games.hpp"
#include "GameState.hpp"
#include <SFML/Window.hpp>

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

		_name_file.open(PLAYER_RECORD_FILEPATH,std::ios::app);

		this->_data->font.loadFromFile("Resources/CHILLER.ttf");
		this->_data->text.setFont(this->_data->font);
		this->_data->text.setCharacterSize(50);
		this->_data->text.setFillColor(sf::Color::White);
		this->_data->text.setPosition(850, 525);
		this->_data->text.scale(2.0f , 1.0f);

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
					_name_file << _name << std::endl;
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					this->_name_file.close();
					std::cout << "Load new state" << std::endl;
					this->_data->machine.AddState(StateRef(new GameState(_data)), true);
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
					this->_data->text.setString(_name);
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
		this->_data->window.draw(this->_data->text);
		this->_data->window.display();
	}


}