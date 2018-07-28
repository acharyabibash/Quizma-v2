#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		std::ofstream _name_file;
		sf::Clock _clock;
		sf::Sprite _background;
		sf::Sprite _gameOver;
		sf::Sprite _cursor;
		sf::Sprite _quit;
		sf::Sprite _playAgain;
		sf::Sprite _returnToTitle;
	};
}