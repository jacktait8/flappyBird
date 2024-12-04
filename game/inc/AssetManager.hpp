#pragma once

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

namespace Flappy
{
	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager() {}

		void LoadTexture(std::string name, std::string fileName);
		Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		Font &GetFont(std::string name);


	private:
		std::map<std::string, Texture> _textures;
		std::map<std::string, Font> _fonts;

		string m_rootDirectory;


	};

}