#pragma once

//GAME SCREEN
#include <sstream>
#include <fstream>
#include "DEFINITIONS.hpp"
#include "GameState2.hpp"
#include "HighScore.hpp"
#include "GameOverState.hpp"
#include <iostream>
#include <chrono>
#include <thread>

namespace Quizma
{
	static std::size_t question_no = 0;

	std::size_t GameState2::getCorrectAnswer()
	{
		for (std::size_t j = 0; j < SIZE_OF_ANS; j++)
		{
			if (this->_data->question_vector.at(question_no).ans[j] == this->_data->question_vector.at(question_no).correct_ans)
			{
				return j;
			}
		}
	}


	GameState2::GameState2(GameDataRef data) : _data(data)
	{

	}

	void GameState2::Init()
	{
		// set the character size
		this->_data->text.setCharacterSize(50);
		this->_data->text.setFillColor(sf::Color::White);
		this->_data->text.setPosition(625, 175);

		for (int i = 0; i < SIZE_OF_TEXTS; i++)
		{
			this->_data->texts[i].setCharacterSize(50);
			this->_data->texts[i].setFillColor(sf::Color::Cyan);
		}

		this->_data->texts[0].setPosition(300, 450);
		this->_data->texts[1].setPosition(300 + 1100, 450);
		this->_data->texts[2].setPosition(300, 450 + 200);
		this->_data->texts[3].setPosition(300 + 1100, 450 + 200);

		this->_data->assets.LoadTexture("Game Background", GAME_SCREEN_1_FILEPATH);
		this->_data->assets.LoadTexture("Next Page Image", NEXT_PAGE_FILEPATH);
		this->_data->assets.LoadTexture("Question Box Image", QUESTION_BOX);
		this->_data->assets.LoadTexture("Option Box 1 Image", OPTION_BOX);
		this->_data->assets.LoadTexture("Option Box 2 Image", OPTION_BOX);
		this->_data->assets.LoadTexture("Option Box 3 Image", OPTION_BOX);
		this->_data->assets.LoadTexture("Option Box 4 Image", OPTION_BOX);
		this->_data->assets.LoadTexture("Sound Icon", SOUND_ICON_FILEPATH);
		this->_data->assets.LoadTexture("Pause Icon", PAUSE_ICON_FILEPATH);
		this->_data->assets.LoadTexture("Quit Icon", QUIT_ICON_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_optionsBox[0].setTexture(this->_data->assets.GetTexture("Option Box 1 Image"));
		_optionsBox[1].setTexture(this->_data->assets.GetTexture("Option Box 2 Image"));
		_optionsBox[2].setTexture(this->_data->assets.GetTexture("Option Box 3 Image"));
		_optionsBox[3].setTexture(this->_data->assets.GetTexture("Option Box 4 Image"));
		_questionBox.setTexture(this->_data->assets.GetTexture("Question Box Image"));
		_sound_icon.setTexture(this->_data->assets.GetTexture("Sound Icon"));
		_pause_icon.setTexture(this->_data->assets.GetTexture("Pause Icon"));
		_quit_icon.setTexture(this->_data->assets.GetTexture("Quit Icon"));

		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));

		_questionBox.setScale(sf::Vector2f(0.20f, 0.15f));

		for (std::size_t i = 0; i < SIZE_OF_ANS; i++)
		{
			_optionsBox[i].setScale(0.75, 0.75);
		}
		_cursor.setScale(0.35, 0.35);
		_sound_icon.setScale(0.2, 0.2);
		_pause_icon.setScale(0.2, 0.2);
		_quit_icon.setScale(0.2, 0.2);

		_questionBox.setPosition((SCREEN_WIDTH / 2) - (_questionBox.getGlobalBounds().width / 2), _questionBox.getGlobalBounds().height / 3);
		_optionsBox[0].setPosition(150, 400);
		_optionsBox[1].setPosition(1250, 400);
		_optionsBox[2].setPosition(150, 600);
		_optionsBox[3].setPosition(1250, 600);
		_sound_icon.setPosition(1400, 0);
		_pause_icon.setPosition(1500, 0);
		_quit_icon.setPosition(1600, 0);

		_quit_icon.setColor(sf::Color::Black);

		_background.setColor(sf::Color::White);

		for (std::size_t i = 0; i < SIZE_OF_ANS; i++)
		{
			_optionsBox[i].setColor(sf::Color::White);
		}

		for (; question_no < this->_data->question_vector.size(); )
		{
			this->_data->text.setString(this->_data->question_vector.at(question_no).quest);

			this->_data->texts[0].setString(this->_data->question_vector.at(question_no).ans[0]);
			this->_data->texts[1].setString(this->_data->question_vector.at(question_no).ans[1]);
			this->_data->texts[2].setString(this->_data->question_vector.at(question_no).ans[2]);
			this->_data->texts[3].setString(this->_data->question_vector.at(question_no).ans[3]);

			std::cout << this->_data->question_vector.at(question_no).quest << std::endl;
			std::cout << this->_data->question_vector.at(question_no).ans[0] << std::endl;
			std::cout << this->_data->question_vector.at(question_no).ans[1] << std::endl;
			std::cout << this->_data->question_vector.at(question_no).ans[2] << std::endl;
			std::cout << this->_data->question_vector.at(question_no).ans[3] << std::endl;

			//question_no++;
			std::cout << "Question number = " << question_no << std::endl;
			std::cout << this->_data->question_vector.at(question_no).ans[4] << std::endl;

			break;

		}
	}

	void GameState2::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			//for options are clicked
			if (question_no < this->_data->question_vector.size()) {
				for (std::size_t i = 0; i < SIZE_OF_ANS; i++)
				{
					if (this->_data->input.IsSpriteClicked(this->_optionsBox[i], sf::Mouse::Left, this->_data->window))
					{
						if (this->_data->question_vector.at(question_no).ans[i] == this->_data->question_vector.at(question_no).correct_ans) {
							std::cout << "Correct subscript is: " << getCorrectAnswer() << std::endl;
							this->_data->sound.setBuffer(this->_data->buffer);
							this->_data->sound.play();
							_optionsBox[i].setColor(sf::Color::Cyan);

							question_no++;
							std::cout << "Score: " << question_no * 10 << std::endl;
							//go to next question
							this->_data->machine.AddState(StateRef(new GameState2(_data)), true);
						}
						else
						{
							std::cout << "Correct subscript is: " << getCorrectAnswer() << std::endl;
							_optionsBox[i].setColor(sf::Color::Red);
							_optionsBox[getCorrectAnswer()].setColor(sf::Color::Cyan);
							std::cout << "Score: " << question_no * 10 << std::endl;
							question_no = 0;

							for (int i = 0; i < SIZE_OF_TEXTS; i++)
							{
								this->_data->window.draw(this->_optionsBox[i]);
							}
							this->_data->window.draw(this->_cursor);
							this->_data->window.display();

							std::this_thread::sleep_for(std::chrono::milliseconds(2500));

							this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
						}
					}
				}

				if (this->_data->input.IsSpriteClicked(this->_sound_icon, sf::Mouse::Left, this->_data->window))
				{
					this->_data->music1.play();
				}

				if (this->_data->input.IsSpriteClicked(this->_pause_icon, sf::Mouse::Left, this->_data->window))
				{
					this->_data->music1.pause();
				}

				if (this->_data->input.IsSpriteClicked(this->_quit_icon, sf::Mouse::Left, this->_data->window))
				{
					this->_data->window.close();
				}

				//for exiting 

				_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
			}
			else
			{
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}
	}



	void GameState2::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_questionBox);
		this->_data->window.draw(this->_data->text);
		this->_data->window.draw(this->_sound_icon);
		this->_data->window.draw(this->_pause_icon);
		this->_data->window.draw(this->_quit_icon);

		for (int i = 0; i < SIZE_OF_TEXTS; i++)
		{
			this->_data->window.draw(this->_optionsBox[i]);
			this->_data->window.draw(this->_data->texts[i]);
		}

		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}


	void GameState2::Update(float dt)
	{/*
	 while ( this->_clock.getElapsedTime().asSeconds() <= 5)
	 {
	 static int a = 30;
	 ss << a;
	 std::cout << ss.str() << std::endl;
	 numbers.setString(ss.str());
	 this->_data->window.draw(numbers);
	 std::cout << this->_clock.getElapsedTime().asSeconds() << std::endl;

	 }*/
		if (this->_clock.getElapsedTime().asSeconds() > 5)
		{
			this->_data->machine.AddState(StateRef(new GameState2(_data)), true);
		}
	}
}