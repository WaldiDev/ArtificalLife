#include <SFML/Graphics.hpp>
#include "SFML/Graphics/RenderWindow.hpp"

#include "HexagonMap.h"

int main(int arc, char* argv[])
{
	sf::RenderWindow Window(sf::VideoMode(1000, 1000), "Hello World!");
	
	sf::Image mapInfo;
	if (!mapInfo.loadFromFile("Map.png"))
	{
		return -1;
	}

	HexagonShape hexagon(10.0f, HexagonOrientation::FlatTopped);
	HexagonMap hexagonMap(mapInfo, hexagon);

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
		hexagonMap.Render(Window);

		Window.display();
	}

	return 0;
}