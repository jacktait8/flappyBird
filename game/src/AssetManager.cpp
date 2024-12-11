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

		printf("Root: %s\n", (m_rootDirectory + fileName).c_str());

		if (tex.loadFromFile(m_rootDirectory + fileName))
		{
			this->_textures[name] = tex;
		}
		else
		{
			printf("Failed to load Texture name %s at location %s\n", name.c_str(), fileName.c_str());
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
			printf("Failed to load Font\n");
		}
	}

	Texture& AssetManager::GetTexture(std::string name)
	{
		printf("Getting texture %s\n", name.c_str());
		return this->_textures.at(name);
	}

	Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}




}