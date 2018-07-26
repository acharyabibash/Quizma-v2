#include <sstream>
#include "DEFINITIONS.hpp"
#include "player.hpp"
#include "Games.hpp"
#include "Categories.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

namespace Quizma
{
	void armVector(sf::Event);

	player::player(GameDataRef data) : _data(data)
	{

	}

	void player::Init()
	{
		this->_data->assets.LoadTexture("Player Background", PLAYER_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Player Background"));
		std::cout << "The state has been loaded.\n";

		_display_name.setCharacterSize(50);
		_display_name.setFillColor(sf::Color::White);
		_display_name.setPosition(600, 400);

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
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					this->_name_file.close();
					std::cout << "Load new state" << std::endl;
					this->_data->machine.AddState(StateRef(new Categories(_data)), true);
				}
				else if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode >= 33 && event.text.unicode <= 126) 
					{
						_name += (char)event.text.unicode;
						_name_file << _name << std::endl;
						_display_name.setString(_name);
					}
					else if (event.text.unicode == 8) 
					{
						system("cls");
						_name = _name.substr(0, _name.size() - 1);
						_display_name.setString(_name);
					}
					std::cout << _name << std::endl;
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
		this->_data->window.draw(this->_data->text);
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_border);
		this->_data->window.draw(this->_display_name);
		this->_data->window.display();
	}

	void armVector(sf::Event event)
	{
		std::ofstream name_file(PLAYER_RECORD_FILEPATH, std::ios::app);

		//if (name_file.is_open()) 
		//{
		//	if (event.type == sf::Event::TextEntered)
		//	{
		//		a
		//	}
		//}

	}
}