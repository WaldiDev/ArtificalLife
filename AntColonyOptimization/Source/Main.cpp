#include <SFML/Graphics.hpp>
#include "SFML/Graphics/RenderWindow.hpp"

int main(int arc, char* argv[])
{
	sf::RenderWindow Window(sf::VideoMode(200, 200), "Hello World!");
	sf::CircleShape Shape(100.f);
	Shape.setFillColor(sf::Color::Green);

	while (Window.isOpen())
	{
		sf::Event Event;
		while (Window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				Window.close();
			}
		}

		Window.clear();
		Window.draw(Shape);
		Window.display();
	}

	return 0;
}