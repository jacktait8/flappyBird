#include <SFML/Graphics.hpp>
#include "DEFINTIONS.hpp"

#include <iostream>
#include "Game.hpp"

using namespace sf;
using namespace std;



int main()
{
	Flappy::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bord");

	return EXIT_SUCCESS;
}