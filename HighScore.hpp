#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class HighScore : public State
	{
	public:
		HighScore(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		std::vector <std::string> result;
		std::ifstream _name_file;
		sf::Vector2i positionText;
		int result_no;
		std::string category;
		sf::Font _font;
		sf::Text _text;
		sf::Sprite _background;
		sf::Sprite _backButton;
		sf::Sprite _cursor;
	};
}
