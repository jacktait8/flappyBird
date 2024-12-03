#include "Flash.hpp"
#include <iostream>

using namespace sf;
using namespace std;

namespace Flappy
{
	Flash::Flash(GameDataRef data) : _data( data )
	{
		_shape = RectangleShape(Vector2f(_data->window.getSize()));
		_shape.setFillColor(Color(255,255,255,0));

		_flashOn = true;
	}

	void Flash::Show(float dt)
	{
		if (_flashOn)
		{
			int alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);
			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				_flashOn = false;
			}

			_shape.setFillColor(Color(255, 255, 255, alpha));
		}
		else
		{
			int alpha = (int)_shape.getFillColor().a -(FLASH_SPEED * dt);
			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
				_flashOn = false;
			}

			_shape.setFillColor(Color(255, 255, 255, alpha));
		}
	}

	void Flash::Draw(float dt)
	{
		_data->window.draw(_shape);
	}


	Flash::~Flash()
	{
	}
}