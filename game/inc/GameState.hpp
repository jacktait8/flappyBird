#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "Flash.hpp"
#include "HUD.hpp"

using namespace sf;
using namespace std;

namespace Flappy
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Sprite _background;

		Pipe *pipe;
		Land *land;
		Bird *bird;
		Collision collision;
		Flash *flash;
		HUD *hud;

		Clock clock;

		int _gameState;

		int _score;

		SoundBuffer _hitSoundBuffer;
		SoundBuffer _pointSoundBuffer;
		SoundBuffer _wingSoundBuffer;

		Sound _hitSound;
		Sound _pointSound;
		Sound _wingSound;

	};


}