#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::VideoMode videoMode({ 640, 480 }); // 640x480 pixels
	std::string windowName = "GameOne"; // The name of the window

	// Create a window with a default style. The style is the design of the window. Curently we have Titlebar, Close button and the option to resize the window.
	// Window is basic window that handles creation polling etc. It can not draw 2D graphics. I need to do my OpenGL rendering
	// RenderWindow inherits from Window and can draw 2D graphics
	sf::RenderWindow window(videoMode, windowName, sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);

	// Set the position of the window on the screen
	window.setPosition({ 100, 100 });

	// We turn on vertical sync. This means that the game will run at the same speed as the monitor refresh rate.
	// We should call this function once after creating the window
	window.setVerticalSyncEnabled(true);

	// Game loop
	// Every game frame has three stages: Evvent polling, Update and Render
	// While the window is open, the game will run
	while (window.isOpen())
	{
		// Event polling. (Did something happen)
		while (const std::optional event = window.pollEvent()) // Checks if an event occured and stores it in an optional
		{
			// If the event is to close the window, then close the window
			if (event->is<sf::Event::Closed>())
				window.close();
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				// Close the window if the pressed key is escape
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) //Scancode refers to the physical location of the key on the keyboard. For example Z in english and Y in German have the same scancode
					window.close();
			}
		}

		// Update

		// Render
		// Clear old frame
		// Instead of a color constant I can pass 3 ints for rgb
		window.clear(sf::Color::Blue);

		// We will draw the game here

		// Tells the app that the frame is ready to be displayed. (The window is done drawing)

		window.display();
	}

	// End of the game
	return 0;
}