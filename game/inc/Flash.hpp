#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"



namespace Flappy
{
	class Flash
	{
	public:
		Flash(GameDataRef data);
		~Flash();

		void Show(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		RectangleShape _shape;

		bool _flashOn;

	};


}