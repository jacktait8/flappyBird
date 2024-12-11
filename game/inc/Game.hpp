#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <iostream>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "LevelManager.hpp"
#include "InputManager.hpp"

using namespace sf;
using namespace std;

namespace Flappy
{
	struct GameData
	{
		StateMachine machine;
		RenderWindow window;
		AssetManager assets;
		LevelManager* level;
		InputManager input;
	};


	typedef shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, string title);
		~Game();


	private:
		const float dt = 1.0f / 60.0f;
		Clock _clock;

		GameDataRef _data = make_shared<GameData>();

		void Run();

	};





}