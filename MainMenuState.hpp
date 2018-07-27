#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		sf::Sprite _exitButton;		
		sf::Sprite _optionsButton;
		sf::Sprite _cursor;
		sf::Sprite _highScore;	
	};
}