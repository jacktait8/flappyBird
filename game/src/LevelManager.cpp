#include "LevelManager.hpp"
#include "DEFINITIONS.HPP"


namespace Flappy
{
	LevelManager::LevelManager(AssetManager& am) : assetManager(am)
	{
		rootDir = "../";
		currentLevel = 1;
		_levelTextures = {};
	}

	void LevelManager::CheckLevel(int score) {
		printf("Checking score\n");
		if (score >= PLATINUM_MEDAL_SCORE) {
			currentLevel = 4;
		}
		else if (score >= GOLD_MEDAL_SCORE) {
			currentLevel = 3;
		}
		else if (score >= SILVER_MEDAL_SCORE) {
			currentLevel = 2;
		}
		else {
			currentLevel = 1;
		}
	}

	void LevelManager::LoadLevelTextures(string name, string fileName) {
		Texture tex;
		for (int i = 1; i < 5; i++) {
			printf("Loading texture name %s at location %s  ||  LoadTexture(%s, %s)", name.c_str(), fileName.c_str(), (getLevelTexturePrefix(i) + name).c_str(), (string(RES_DIR) + "lvl" + to_string(i) + "/" + fileName).c_str());
			assetManager.LoadTexture(getLevelTexturePrefix(i) + name, string(RES_DIR) + "lvl" + to_string(i) + "/" + fileName);
		}


	}

	Texture& LevelManager::GetLevelTexture(string name) {
		string texName = getLevelTexturePrefix(currentLevel) + name;
		return assetManager.GetTexture(texName);
	}

	string LevelManager::getLevelTexturePrefix(int lvl) {
		return "lvl" + to_string(lvl) + "::";
	}
}