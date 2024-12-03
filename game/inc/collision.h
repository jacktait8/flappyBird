
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace Flappy
{
	class Collision
	{
	public:
		Collision();
		~Collision();

		bool CheckSpriteCollision(Sprite sprite1, Sprite sprite2);
		bool CheckSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2);

	private:

	};



}
