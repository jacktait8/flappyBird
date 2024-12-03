#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINTIONS.hpp"
#include "Game.hpp"
#include <vector>
#include <iostream>


using namespace sf;
using namespace std;


namespace Flappy
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);
		~Pipe();

		void SpawnBottomPipe();
		void SpawnTopPipe();
		void SpawnInvisiblePipe();
		void SpawnScoringPipe();
		void MovePipes(float dt);
		void DrawPipes();
		void RandomizePipeOffset();

		const vector<Sprite>& GetSprites() const;
		vector<Sprite>& GetScoringSprites();

	private:
		GameDataRef _data;
		vector<Sprite> pipeSprites;
		vector<Sprite> scoringPipes;

		int _landHeight;
		int _pipeSpawnYOffset;


	};


}