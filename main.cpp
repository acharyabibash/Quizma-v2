#include "Games.hpp"
#include "DEFINITIONS.hpp"

int main()
{
	Quizma::Games(SCREEN_WIDTH, SCREEN_HEIGHT, "QUIZMA HEROES");

	return EXIT_SUCCESS;
}/*
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <time.h>


int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 992), "Quizma Heroes");
	sf::Clock _clock;

	sf::Vector2i source(0, 0);
	sf::Sprite player;
	sf::Texture playerTexture;

	playerTexture.loadFromFile("Resources/nom.jpg");
	player.setTexture(playerTexture);
	player.setTextureRect(sf::IntRect(source.x, source.y, 32, 65));

	player.setPosition(500, 100);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Escape)
					window.close();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{

					player.setTextureRect(sf::IntRect(source.x - 32, 0, 32, 48));

					source.x -= 32;

					if (source.x <0)
					{
						window.close();
					}
				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					player.setTextureRect(sf::IntRect(source.x + 32, 0, 32, 65));

					source.x += 32;

					if (source.x >= 1200)
					{
						window.close();
						//source.x = 0;
					}

				}
			}
		}

		window.draw(player);
		window.display();
	}
	return 0;


}*/