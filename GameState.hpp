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
		std::size_t getCorrectAnswer();

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _questionBox;
		sf::Sprite _optionsBox[4];
		bool is_wrong_sprite_clicked = false;

		sf::Sprite _cursor;
		sf::Sprite _sound_icon;
		sf::Sprite _pause_icon;
		sf::Sprite _quit_icon;
		sf::Clock _clock_prime;

		//for timer countdown
		sf::Clock _clock;
		int _countdown = 30;
		std::string _countdownString;
		std::ostringstream _convert;
		sf::Text _timerText;
	};
}