#pragma once

//GAME SCREEN
#include <sstream>
#include <fstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "HighScore.hpp"
#include "GameOverState.hpp"
#include <iostream>

namespace Quizma
{
	static std::size_t question_no = 0;

	std::size_t GameState::getCorrectAnswer()
	{
		//for (std::size_t i = 0; i < this->_data->question_vector.size(); i++)
		//{
			for (std::size_t j = 0; j < SIZE_OF_ANS; j++)
			{
				if (this->_data->question_vector.at(question_no).ans[j] == this->_data->question_vector.at(question_no).correct_ans)
				{
					return j;
				}
			}
		//}
	}

	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
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
		this->_data->assets.LoadTexture("Quit Image", QUIT_FILEPATH);
		this->_data->assets.LoadTexture("Cursor", CURSOR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		//_nextPage.setTexture(this->_data->assets.GetTexture("Next Page Image"));

		_optionsBox[0].setTexture(this->_data->assets.GetTexture("Option Box 1 Image"));
		_optionsBox[1].setTexture(this->_data->assets.GetTexture("Option Box 2 Image"));
		_optionsBox[2].setTexture(this->_data->assets.GetTexture("Option Box 3 Image"));
		_optionsBox[3].setTexture(this->_data->assets.GetTexture("Option Box 4 Image"));
		_questionBox.setTexture(this->_data->assets.GetTexture("Question Box Image"));
		//_Quit.setTexture(this->_data->assets.GetTexture("Quit Image"));
		_cursor.setTexture(this->_data->assets.GetTexture("Cursor"));

		_questionBox.setScale(sf::Vector2f(0.20f, 0.15f));
		for (std::size_t i = 0; i < SIZE_OF_ANS; i++)
		{
			_optionsBox[i].setScale(0.75, 0.75);
		}
		_cursor.setScale(0.35, 0.35);

		_questionBox.setPosition((SCREEN_WIDTH / 2) - (_questionBox.getGlobalBounds().width / 2), _questionBox.getGlobalBounds().height / 3);
		_optionsBox[0].setPosition(150, 400);
		_optionsBox[1].setPosition(1250, 400);
		_optionsBox[2].setPosition(150, 600);
		_optionsBox[3].setPosition(1250, 600);
		//_nextPage.setPosition(1200, 600);
		//_Quit.setPosition(1700, 950);

		_background.setColor(sf::Color::White);
		for (std::size_t i = 0; i < SIZE_OF_ANS; i++)
		{
			_optionsBox[i].setColor(sf::Color::White);
		}

		//static decltype(this->_data->question_vector.size()) question_no = 0;
		for (; question_no < this->_data->question_vector.size(); )
		{
			//if (question_no < this->_data->question_vector.size())
			//{
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
			//}

		}
	}

	void GameState::HandleInput()
	{
		sf::Event event;
		//static decltype(this->_data->question_vector.at(0).ans->size()) question_no = 0;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}


			if (this->_data->input.IsSpriteClicked(this->_nextPage, sf::Mouse::Left, this->_data->window))
			{
				// Go to the next page/question
				this->_data->sound.setBuffer(this->_data->buffer);
				this->_data->sound.play();
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}


			//for option 1 is clicked
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
							std::cout << "Score: " << question_no << std::endl;
							//go to next question
							this->_data->machine.AddState(StateRef(new GameState(_data)), true);
						}
						else
						{
							std::cout << "Correct subscript is: " << getCorrectAnswer() << std::endl;
							_optionsBox[i].setColor(sf::Color::Red);
							_optionsBox[getCorrectAnswer()].setColor(sf::Color::Cyan);
							std::cout << "Score: " << question_no << std::endl;
							question_no = 0;

							this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
						}
					}
				}


				//	//for option 2 is clicked
				//	if (this->_data->input.IsSpriteClicked(this->_optionsBox2, sf::Mouse::Left, this->_data->window))
				//	{
				//		if (this->_data->question_vector.at(question_no).ans[1] == this->_data->question_vector.at(question_no).correct_ans) {
				//			this->_data->sound.setBuffer(this->_data->buffer);
				//			this->_data->sound.play();
				//			_optionsBox2.setColor(sf::Color::Cyan);

				//			question_no++;
				//			std::cout << "Score: " << question_no << std::endl;
				//			//go to next question
				//			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				//		} else {
				//			_optionsBox2.setColor(sf::Color::Red);
				//			std::cout << "Score: " << question_no << std::endl;
				//			question_no = 0;
				//			this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
				//		}
				//	}

				//	//for option 3 is clicked
				//	if (this->_data->input.IsSpriteClicked(this->_optionsBox3, sf::Mouse::Left, this->_data->window))
				//	{
				//		if (this->_data->question_vector.at(question_no).ans[2] == this->_data->question_vector.at(question_no).correct_ans) {
				//			this->_data->sound.setBuffer(this->_data->buffer);
				//			this->_data->sound.play();
				//			_optionsBox3.setColor(sf::Color::Cyan);

				//			question_no++;
				//			std::cout << "Score: " << question_no << std::endl;
				//			//go to next question
				//			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				//		} else {
				//			_optionsBox3.setColor(sf::Color::Red);
				//			std::cout << "Score: " << question_no << std::endl;
				//			question_no = 0;
				//			this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
				//		}
				//	}

				//	//for option 4 is clicked
				//	if (this->_data->input.IsSpriteClicked(this->_optionsBox4, sf::Mouse::Left, this->_data->window))
				//	{
				//		if (this->_data->question_vector.at(question_no).ans[3] == this->_data->question_vector.at(question_no).correct_ans) {
				//			this->_data->sound.setBuffer(this->_data->buffer);
				//			this->_data->sound.play();
				//			_optionsBox4.setColor(sf::Color::Cyan);

				//			question_no++;
				//			std::cout << "Score: " << question_no << std::endl;
				//			//go to next question
				//			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				//		} else {
				//			_optionsBox4.setColor(sf::Color::Red);
				//			std::cout << "Score: " << question_no << std::endl;
				//			question_no = 0;
				//			this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
				//		}
				//	}
				//} else {
				//	std::cout << "Score: " << question_no << std::endl;
				//	question_no = 0;
				//	this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
				//}

				//for exiting 

				_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window)));
			}
		}
	}

	void GameState::Update(float dt)
	{

	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_questionBox);
		this->_data->window.draw(this->_data->text);

		for (int i = 0; i < SIZE_OF_TEXTS; i++)
		{
			this->_data->window.draw(this->_optionsBox[i]);
			this->_data->window.draw(this->_data->texts[i]);
		}

		//this->_data->window.draw(this->_nextPage);
		//this->_data->window.draw(this->_Quit);
		this->_data->window.draw(this->_cursor);
		this->_data->window.display();
	}
}