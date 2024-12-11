#include <sstream>
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

using namespace sf;
using namespace std;

namespace Flappy
{
	GameState::GameState(GameDataRef data) :
		_data(data),
		m_rootDirectory{},
		_gameState{},
		_score{},
		bird{},
		flash{},
		hud{},
		land{},
		pipe{}
	{
		#ifdef _DEBUG
			m_rootDirectory = "../";
		#else
			m_rootDirectory = "../";
		#endif

	}

	void GameState::Init()
	{
		cout << "Game Initilaised" << endl;

		if (!_hitSoundBuffer.loadFromFile(m_rootDirectory + HIT_SOUND_FILEPATH))
		{
			cout << "Error HIT sound file not loaded! " << endl;
		}

		if (!_pointSoundBuffer.loadFromFile(m_rootDirectory + POINT_SOUND_FILEPATH))
		{
			cout << "Error POINT sound file not loaded! " << endl;
		}

		if (!_wingSoundBuffer.loadFromFile(m_rootDirectory + WING_SOUND_FILEPATH))
		{
			cout << "Error WING sound file not loaded! " << endl;
		}

		_hitSound.setBuffer(_hitSoundBuffer);
		_pointSound.setBuffer(_pointSoundBuffer);
		_wingSound.setBuffer(_wingSoundBuffer);




		// grab textures
		_data->level->LoadLevelTextures("Game Background", GAME_BACKGROUND_FILENAME);
		_data->level->LoadLevelTextures("Pipe Up", PIPE_UP_FILENAME);
		_data->level->LoadLevelTextures("Pipe Down", PIPE_DOWN_FILENAME);
		_data->level->LoadLevelTextures("Land", LAND_FILENAME);

		_data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
		// font
		_data->assets.LoadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

		_data->level->LoadLevelTextures("Bird Frame 1", BIRD_FRAME_1_FILENAME);
		_data->level->LoadLevelTextures("Bird Frame 2", BIRD_FRAME_2_FILENAME);
		_data->level->LoadLevelTextures("Bird Frame 3", BIRD_FRAME_3_FILENAME);
		_data->level->LoadLevelTextures("Bird Frame 4", BIRD_FRAME_4_FILENAME);

		pipe = new Pipe( _data );
		land = new Land( _data );
		bird = new Bird( _data );
		hud = new HUD(_data);

		// flash
		flash = new Flash(_data);

		// assign to variables
		_background.setTexture(this->_data->level->GetLevelTexture("Game Background"));

		_score = 0;
		hud->UpdateScore(_score);


		// load a font
		_data->assets.LoadFont("Exit Font", FLAPPY_FONT_FILEPATH);

		// initilaize the exit button
		InitExitButton(_data->assets.GetFont("Exit Font"), Vector2f(SCREEN_WIDTH - 150.f, 25.0f));


		_gameState = GameStates::eReady;

	}

	void GameState::HandleInput()
	{
		sf::View view = this->_data->window.getDefaultView();

		Event event;
		while (_data->window.pollEvent(event))
		{
			if (Event::Closed == event.type || event.key.code == Keyboard::Escape)
			{
				GameState::CloseApplication(*_data);

			}

			/*if (_data->input.IsSpriteClicked(_background, Mouse::Left, _data->window))
			{
				cout << "Go to Game Over screen." << endl;

				// test to click to game over screen
				_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}*/




			//
			if (_data->input.IsSpriteClicked(_background, Mouse::Left, _data->window))
			{
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					bird->Tap();

					_wingSound.play();

				}

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




			if (event.type == sf::Event::Resized) {
				// resize my view
				view.setSize({
						static_cast<float>(event.size.width),
						static_cast<float>(event.size.height)
					});
				this->_data->window.setView(view);
				// and align shape
			}


		}
	}

	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{
			bird->Animate(dt);
			land->MoveLand(dt);

		}

		if (GameStates::ePlaying == _gameState)
		{
			_data->level->CheckLevel(_score);

			pipe->MovePipes(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{
				pipe->RandomizePipeOffset();

				pipe->SpawnTopPipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnInvisiblePipe();
				pipe->SpawnScoringPipe();

				clock.restart();

			}

			bird->Update(dt);

			// collision with ground
			vector<Sprite> landSprites = land->GetSprites();
			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(
					bird->GetSprite(),
					0.75f,
					landSprites.at(i),
					1.0f
					))
				{
					_gameState = GameStates::eGameOver;
					clock.restart();

					_hitSound.play();
				}
			}

			// collision with pipes
			vector<Sprite> pipeSprites = pipe->GetSprites();
			for (int i = 0; i < pipeSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(
					bird->GetSprite(),
					0.625f,
					pipeSprites.at(i),
					1.0f
					))
				{
					_gameState = GameStates::eGameOver;
					clock.restart();
					_hitSound.play();

				}
			}

			// collision with scoring pipes
			if (GameStates::ePlaying == _gameState)
			{
				vector<Sprite> scoringSprites = pipe->GetScoringSprites();
				for (int i = 0; i < scoringSprites.size(); i++)
				{
					if (collision.CheckSpriteCollision(
						bird->GetSprite(),
						0.625f,
						scoringSprites.at(i),
						1.0f
					))
					{
						_score++;

						// Check score and update sprites
						_data->level->CheckLevel(_score);
						_background.setTexture(_data->level->GetLevelTexture("Game Background"));
						land->UpdateSprites();
						bird->UpdateSprites();

						hud->UpdateScore(_score);
						_pointSound.play();

						scoringSprites.erase(scoringSprites.begin() + i);

					}
				}



			}


		}

		if (GameStates::eGameOver == _gameState)
		{
			flash->Show(dt);

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_APPEARS)
			{
				_data->machine.AddState(StateRef(new GameOverState( _data, _score )), true);
			}


		}




	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);

		pipe->DrawPipes();
		land->DrawLand();
		bird->Draw();
		hud->Draw();
		flash->Draw(dt);

		DrawExitButton(_data->window);


		_data->window.display();
	}

	void GameState::CloseApplication(GameData& data)
	{
		data.window.close();
		std::cout << "Game window closed. Exiting application." << std::endl;
	}



}