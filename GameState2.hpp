#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class GameState2 : public State
	{
	public:
		GameState2(GameDataRef data);

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
		sf::Clock _clock_prime2;

		//for timer countdown
		sf::Clock _clock2;
		int _countdown = 30;
		std::string _countdownString;
		std::ostringstream _convert;
		sf::Text _timerText;
	};
}