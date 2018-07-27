#include "Games.hpp"
#include "SplashState.hpp"
#include <fstream>
#include "DEFINITIONS.hpp"

namespace Quizma
{
	Games::Games(int width, int height, std::string title)
	{
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));
		//_data->music.openFromFile("Resources/glasgowkiss.wav");
		_data->music1.openFromFile("Resources/song1.wav");
		_data->music2.openFromFile("Resources/L Theme.wav");
		_data->music3.openFromFile("Resources/song2.wav");
		_data->buffer.loadFromFile("Resources/Choose.wav");

		_data->font.loadFromFile("Resources/CENTAUR.ttf");
		_data->text.setFont(this->_data->font);
		for (int i = 0; i < 4; i++) {
			_data->texts[i].setFont(this->_data->font);
		}

		//_data->question_vector = _data->qa_vector.passQuestion();

		this->Run();
	}


	void Games::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) //main game loop
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.05f)
			{
				frameTime = 0.05f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}
	
}
