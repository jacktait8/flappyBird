#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Flappy
{
	class State
	{
	public:
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() {}
		virtual void Resume() {}

        // Initialize exit button
        void InitExitButton(const Font& font, const Vector2f& position)
        {
            // size of the exit button
            _exitButton.setSize(Vector2f(200.0f, 50.0f));

            // color of button
            _exitButton.setFillColor(Color::Red);

            // set pos
            _exitButton.setPosition(position);

            // set font passed
            _exitButtonText.setFont(font);

            // set text may go with X or Exit Game
            _exitButtonText.setString("Exit Game");

            // font size
            _exitButtonText.setCharacterSize(24);

            // white text
            _exitButtonText.setFillColor(Color::White);

            // text offset
            _exitButtonText.setPosition(
                position.x + 10.0f,
                position.y + 10.0f
            );
        }

        // Handle exit button input
        bool HandleExitButtonInput(const Event& event, RenderWindow& window)
        {
            // left click on exit
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                // mose vector
                Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                if (_exitButton.getGlobalBounds().contains(mousePos))
                {
                    // button clicked
                    return true;
                }
            }

            // do nothing
            return false;
        }

        // Draw the button
        void DrawExitButton(RenderWindow& window)
        {
            // draw the exit button
            window.draw(_exitButton);
            //draw text in button
            window.draw(_exitButtonText);
        }

	protected:

        // most state will need a exit option so using a protected method
        RectangleShape _exitButton;
		Text _exitButtonText;

	};



}