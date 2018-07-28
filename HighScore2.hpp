#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "State.hpp"
#include "Games.hpp"


namespace Quizma
{
	class HighScore2 : public State
	{
	public:
		HighScore2(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _backButton;
		sf::Sprite _cursor;
	};
}