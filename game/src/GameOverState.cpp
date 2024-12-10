#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

namespace Flappy
{
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score), _highScore{ 0 }

	{

	}

	void GameOverState::Init()
	{
		// grab high score from text file
		ifstream readFile;
		readFile.open(HIGH_SCORE_TEXT_FILEPATH);

		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> _highScore;
			}
		}

		readFile.close();
		ofstream writeFile(HIGH_SCORE_TEXT_FILEPATH);
		if (writeFile.is_open())
		{
			if (_score > _highScore)
			{
				_highScore = _score;
			}

			writeFile << _highScore;
		}

		writeFile.close();


		// grab textures
		_data->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
		_data->assets.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
		_data->assets.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
		_data->assets.LoadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);



		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);



		// assign to variables
		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_gameOverBody.setTexture(this->_data->assets.GetTexture("Game Over Body"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		// set positions
		_gameOverBody.setPosition(
			_data->window.getSize().x / 2.f - (_gameOverBody.getGlobalBounds().width / 2),
			_data->window.getSize().y / 2.f - (_gameOverBody.getGlobalBounds().height / 2)
			);

		_gameOverTitle.setPosition(
			_data->window.getSize().x / 2 - (_gameOverTitle.getGlobalBounds().width / 2),
			_gameOverBody.getPosition().y - (_gameOverTitle.getGlobalBounds().height * 1.2)
		);

		_retryButton.setPosition(
			_data->window.getSize().x / 2 - (_retryButton.getGlobalBounds().width / 2),
			_gameOverBody.getPosition().y + (_gameOverBody.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2))
		);

		// _scoreText
		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString(to_string(_score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(Color::White);
		_scoreText.setOrigin(
			_scoreText.getGlobalBounds().width / 2,
			_scoreText.getGlobalBounds().height / 2
			);

		_scoreText.setPosition(
			_data->window.getSize().x / 10 * 7.25,
			_data->window.getSize().y / 2.15
		);

		// _highScoreText
		_highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_highScoreText.setString(to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(Color::White);
		_highScoreText.setOrigin(
			_highScoreText.getGlobalBounds().width / 2,
			_highScoreText.getGlobalBounds().height / 2
		);

		_highScoreText.setPosition(
			_data->window.getSize().x / 10 * 7.25,
			_data->window.getSize().y /  1.78
		);


		if (_score >= PLATINUM_MEDAL_SCORE)
		{
			_medal.setTexture(_data->assets.GetTexture("Platinum Medal"));
		}
		else if (_score >= GOLD_MEDAL_SCORE)
		{
			_medal.setTexture(_data->assets.GetTexture("Gold Medal"));
		}
		else if (_score >= SILVER_MEDAL_SCORE)
		{
			_medal.setTexture(_data->assets.GetTexture("Silver Medal"));
		}
		else
		{
			_medal.setTexture(_data->assets.GetTexture("Bronze Medal"));
		}

		_medal.setPosition(175, 465);


		// load a font
		_data->assets.LoadFont("Exit Font", FLAPPY_FONT_FILEPATH);

		// initilaize the exit button
		InitExitButton(_data->assets.GetFont("Exit Font"), Vector2f(SCREEN_WIDTH - 150.f, 25.0f));


	}

	void GameOverState::HandleInput()
	{
		Event event;
		while (_data->window.pollEvent(event))
		{

			if (Event::Closed == event.type || event.key.code == Keyboard::Escape)
			{
				GameState::CloseApplication(*_data);

			}

			if (_data->input.IsSpriteClicked(_retryButton, Mouse::Left, _data->window))
			{
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

	void GameOverState::Update(float dt)
	{
	}

	void GameOverState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_background);
		_data->window.draw(_gameOverTitle);
		_data->window.draw(_gameOverBody);
		_data->window.draw(_retryButton);

		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);

		_data->window.draw(_medal);

		DrawExitButton(_data->window);


		_data->window.display();
	}



}