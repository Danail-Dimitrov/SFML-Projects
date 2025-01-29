#include <iostream>

#include <SFML/Window.hpp>

int main()
{
	sf::VideoMode videoMode({ 640, 480 }); // 640x480 pixels
	std::string windowName = "GameOne"; // The name of the window

	sf::Window window(videoMode, windowName, sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize); // Create a window with a default style. The style is the design of the window. Curently we have Titlebar, Close button and the option to resize the window.
	
	//Game loop
	//While the window is open, the game will run
	while (window.isOpen()) 
	{
		//Event polling. (Did something happen)
		while (const std::optional event = window.pollEvent()) // Checks if an event occured and stores it in an optional
		{
			//If the event is to close the window, then close the window
			if (event->is<sf::Event::Closed>())
				window.close();
		}
	}

	//End of the game
	return 0;
}