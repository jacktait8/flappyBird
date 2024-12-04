#include "AssetManager.hpp"
#include "config.in.hpp"


namespace Flappy
{
	AssetManager::AssetManager() : m_rootDirectory{}
	{
		#ifdef _DEBUG
			m_rootDirectory = "../";
		#else
			m_rootDirectory = "../";
		#endif

	}


	void AssetManager::LoadTexture(std::string name, std::string fileName)
	{
		Texture tex;

		//printf("Root: %s", m_rootDirectory + fileName);

		if (tex.loadFromFile(m_rootDirectory + fileName))
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


		if (font.loadFromFile(m_rootDirectory + fileName))
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