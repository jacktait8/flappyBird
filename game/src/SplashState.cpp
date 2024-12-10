#include <sstream>
#include "GameState.hpp"
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

using namespace sf;
using namespace std;

namespace Flappy
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));

	}

	void SplashState::HandleInput()
	{
		Event event;
		while (_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type || event.key.code == Keyboard::Escape)
			{
				GameState::CloseApplication(*_data);

			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}



	}

	void SplashState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		_data->window.display();



	}




}