#include "Pipe.hpp"


namespace Flappy
{
	Pipe::Pipe(GameDataRef data) : _data( data )
	{
		_landHeight = _data->level->GetLevelTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}


	void Pipe::SpawnBottomPipe()
	{
		Sprite sprite( _data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(
			this->_data->window.getSize().x,
			this->_data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe()
	{
		Sprite sprite(_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(
			this->_data->window.getSize().x,
			- _pipeSpawnYOffset);

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe()
	{
		Sprite sprite(_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(
			this->_data->window.getSize().x,
			this->_data->window.getSize().y - sprite.getGlobalBounds().height);

		sprite.setColor(Color(0,0,0,0));

		pipeSprites.push_back(sprite);
	}


	void Pipe::MovePipes(float dt)
	{
		// normal pipes
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width)
			{
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;

				pipeSprites.at(i).move(-movement, 0);

			}
		}

		// scoring pipes
		for (unsigned short int i = 0; i < scoringPipes.size(); i++)
		{
			if (scoringPipes.at(i).getPosition().x < 0 - scoringPipes.at(i).getGlobalBounds().width)
			{
				scoringPipes.erase(scoringPipes.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;

				scoringPipes.at(i).move(-movement, 0);

			}
		}

		//cout << pipeSprites.size() << endl;
	}

	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			_data->window.draw(pipeSprites.at(i));

		}
	}

	void Pipe::RandomizePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1);

	}

	const vector<Sprite> &Pipe::GetSprites() const
	{
		return pipeSprites;
	}

	void Pipe::SpawnScoringPipe()
	{
		Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
		sprite.setPosition(
			this->_data->window.getSize().x, 0);

		sprite.setColor(Color(0, 0, 0, 0));

		scoringPipes.push_back(sprite);
	}

	vector<Sprite>& Pipe::GetScoringSprites()
	{
		return scoringPipes;
	}

	Pipe::~Pipe()
	{

	}


}