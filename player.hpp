#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class player : public State
	{
	public:
		player(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _border;
		sf::Text _name_text;
		sf::Font _name_font;
		std::ofstream _name_file;
		std::string _name;
		std::vector<std::string> _name_vector;
	
	};
}

