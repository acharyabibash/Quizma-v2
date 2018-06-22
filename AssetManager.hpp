#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Quizma
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		/*void LoadMusic(std::string name, std::string fileName);
		sf::Music &GetMusic(std::string name);*/

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures;
		//std::map<std::string, sf::Music>_musics;
		std::map<std::string, sf::Font> _fonts;
	};
}
