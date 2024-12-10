#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"

#include <iostream>
#include "Game.hpp"

using namespace sf;
using namespace std;



int main()
{
	Flappy::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");

	return EXIT_SUCCESS;
}