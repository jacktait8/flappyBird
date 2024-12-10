#include <sstream>
#include <iostream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "AssetManager.hpp"

using namespace sf;
using namespace std;

namespace Flappy
{
	Flappy::MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
	}

	void Flappy::MainMenuState::Init()
	{
		// grab textures
		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		// assign to variables
		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		// set positions
		_title.setPosition(
			(SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
			_title.getGlobalBounds().height);

		_playButton.setPosition(
			(SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));


		// load a font
		_data->assets.LoadFont("Exit Font", FLAPPY_FONT_FILEPATH);

		// initilaize the exit button
		InitExitButton(_data->assets.GetFont("Exit Font"), Vector2f(SCREEN_WIDTH - 150.f, 25.0f));
	}

	void Flappy::MainMenuState::HandleInput()
	{
		Event event;
		while (_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_playButton, Mouse::Left, _data->window))
			{
				cout << "Go to game screen." << endl;
				// load game
				_data->machine.AddState(StateRef(new GameState(_data)), true);

			}

			// adding a key to escape application
			if (Event::EventType::KeyPressed == event.type)
			{
				if (event.key.code == Keyboard::Escape)
				{
					cout << "Escape pushed" << endl;
					GameState::CloseApplication(*_data);
				}
			}

			// red exit button
			if (HandleExitButtonInput(event, _data->window)) {
				std::cout << "Exit button clicked!" << std::endl;
				GameState::CloseApplication(*_data);
			}




		}
	}

	void Flappy::MainMenuState::Update(float dt)
	{
	}

	void Flappy::MainMenuState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);

		DrawExitButton(_data->window);


		_data->window.display();
	}





}