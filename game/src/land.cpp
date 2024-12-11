#include "Land.hpp"


namespace Flappy
{

	Land::Land(GameDataRef data) : _data( data)
	{
		//Sprite sprite1(_data->assets.GetTexture("Land"));
		//Sprite sprite2(_data->assets.GetTexture("Land"));
		Sprite sprite1(_data->level->GetLevelTexture("Land"));
		Sprite sprite2(_data->level->GetLevelTexture("Land"));

		sprite1.setPosition(0, _data->window.getSize().y - sprite1.getGlobalBounds().height);
		sprite2.setPosition(sprite1.getGlobalBounds().width, _data->window.getSize().y - sprite2.getGlobalBounds().height);

		_landSprites.push_back(sprite1);
		_landSprites.push_back(sprite2);
	}


	void Land::MoveLand(float dt)
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			float movement = PIPE_MOVEMENT_SPEED * dt;
			_landSprites.at(i).move(-movement, 0.0f);

			if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width)
			{

				Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);

				_landSprites.at(i).setPosition(position);
			}
		}
	}

	void Land::DrawLand()
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			_data->window.draw(_landSprites.at(i));
		}
	}

	const vector<Sprite>& Land::GetSprites() const
	{
		return _landSprites;

	}

	void Land::UpdateSprites() {
		for (unsigned short int i = 0; i < _landSprites.size(); i++) {
			_landSprites.at(i).setTexture(_data->level->GetLevelTexture("Land"));
		}
	}

	Land::~Land()
	{

	}
}