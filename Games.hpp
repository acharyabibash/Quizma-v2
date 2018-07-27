#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "QuestionManager.hpp"
#include "QuestionVector.hpp"

#define SIZE_OF_TEXTS 4

namespace Quizma
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
		QuestionManager questions;


		sf::Music music;
		sf::Music music1;
		sf::Music music2;
		sf::Music music3;
		sf::SoundBuffer buffer;
		sf::Sound sound;
		sf::Font font;
		sf::Text text;
		sf::Text texts[SIZE_OF_TEXTS];

		std::vector<QuestionManager> question_vector;
		QuestionVector qa_vector;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Games
	{
	public:
		Games(int width, int height, std::string title);

	private:

		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}