#pragma once
#include "SFML/System/Vector2.hpp"
#include "HexagonShape.h"
#include <vector>
#include "SFML/Graphics/Vertex.hpp"

namespace sf 
{ 
	class RenderTexture;
	class RenderWindow;
	class Image;
	class Sprite;
}

class HexagonMap
{
public:

	HexagonMap(sf::Image& mapInfo, const HexagonShape& hexagon);
	~HexagonMap();

	void Render(sf::RenderWindow& window) const;

protected:
	HexagonShape mHexagon;

	std::vector<sf::Vertex> mGridVertexArray;

	sf::Vector2u mMapSize;

	sf::RenderTexture* mMapTexture;
	sf::Sprite* mMapSprite;
};
