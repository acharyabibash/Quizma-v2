#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class Categories : public State
	{
	public:
		Categories(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		

	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _maths_and_logic;
		sf::Sprite _sports;
		sf::Sprite _cursor;
	};
}