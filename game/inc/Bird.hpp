#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <iostream>
#include <vector>
#include "Game.hpp"


using namespace sf;
using namespace std;


namespace Flappy
{
	class Bird
	{
	public:
		Bird(GameDataRef data);
		~Bird();

		void Draw();
		void Animate(float dt);
		void Update(float dt);
		void Tap();

		const Sprite& GetSprite() const;
		void UpdateSprites();


	private:
		GameDataRef _data;

		Sprite _birdSprite;
		vector<Texture> _animationFrames;

		unsigned int _animationIterator;

		Clock _clock;
		Clock _movementClock;

		int _birdState;

		float _rotation;


	};




}