#pragma once

#include "AssetManager.hpp"
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

namespace Flappy
{
	class LevelManager
	{
	public:
		LevelManager(AssetManager& am);
		~LevelManager() {}

		void CheckLevel(int score);
		void LoadLevelTextures(std::string name, std::string fileName);
		Texture& GetLevelTexture(std::string name);

	private:
		AssetManager& assetManager;
		string rootDir; 
		int currentLevel;
		map<string, map<int, Texture>> _levelTextures;

		std::string getLevelTexturePrefix(int lvl);
	};
}