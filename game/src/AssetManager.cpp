#include "AssetManager.hpp"
#include "config.in.hpp"


namespace Flappy
{
	AssetManager::AssetManager() : m_rootDirectory{}
	{
		m_rootDirectory = "";

	}


	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
		else
		{
			printf("Failed to load Texture");
		}
	}

	void AssetManager::LoadFont(std::string name, std::string fileName)
	{
		Font font;


		if (font.loadFromFile(fileName))
		{

			this->_fonts[name] = font;
		}
		else
		{
			printf("Failed to load Font");
		}
	}

	Texture& AssetManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}




}