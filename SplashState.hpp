#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;
		sf::Sprite _cursor;
		sf::Sprite _background;
	};
}