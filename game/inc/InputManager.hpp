#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace Flappy
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		bool IsSpriteClicked(Sprite object, Mouse::Button button, RenderWindow& window);

		Vector2i GetMousePosition(RenderWindow &window);

	};

}