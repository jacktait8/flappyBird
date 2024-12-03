#include "game.h"
#include "SplashState.hpp"

#include <stdlib.h>
#include <time.h>

namespace Flappy
{
	Game::Game(int width, int height, string title)
	{
		srand(time(NULL));

		_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar | Style::Resize | Style::Default);

		_data->machine.AddState(StateRef(new SplashState(this->_data)), false);

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);

		}

	}

}