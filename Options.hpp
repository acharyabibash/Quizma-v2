#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class Options : public State
	{
	public:
		Options(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _music;
		sf::Sprite _music1;
		sf::Sprite _music2;
		sf::Sprite _music3;

		sf::Sprite _option_1;
		sf::Sprite _option_2;
		sf::Sprite _option_back;
		sf::Sprite _cursor;
	};
}
