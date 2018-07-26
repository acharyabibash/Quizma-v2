#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:
		GameDataRef _data;

		sf::Clock _clock;
		sf::Sprite _background;
		sf::Sprite _questionBox;
		sf::Sprite _optionsBox[4];
		//sf::Sprite _optionsBox2;
		//sf::Sprite _optionsBox3;
		//sf::Sprite _optionsBox4;
		sf::Sprite _nextPage;
		sf::Sprite _Quit;
		sf::Sprite _cursor;

	public: 
		std::size_t getCorrectAnswer();
	};
}