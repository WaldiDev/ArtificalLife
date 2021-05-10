#include "HexagonMap.h"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"

namespace
{
	float GetMapWidth(unsigned int tileCountX, const HexagonShape& hexagon)
	{
		return (hexagon.GetOrientation() == FlatTopped)
			? ((tileCountX - 1) * hexagon.GetHorizontalDistance()) + hexagon.GetWidth()
			: (tileCountX * hexagon.GetHorizontalDistance()) + (hexagon.GetHorizontalDistance() * 0.5f);
	}

	float GetMapHeight(unsigned int tileCountY, const HexagonShape& hexagon)
	{
		return (hexagon.GetOrientation() == PointyTopped)
			? ((tileCountY - 1) * hexagon.GetVerticalDistance()) + hexagon.GetHeight()
			: (tileCountY * hexagon.GetVerticalDistance()) + (hexagon.GetVerticalDistance() * 0.5f);
	}
}

HexagonMap::HexagonMap(sf::Image& mapInfo, const HexagonShape& hexagon)
	: mHexagon(hexagon)
	, mMapSize(mapInfo.getSize())
	, mMapTexture(new sf::RenderTexture())
	, mMapSprite(new sf::Sprite())
{
	sf::ContextSettings textureSettings;
	textureSettings.antialiasingLevel = 8;

	const float halfHorizontalDistance = mHexagon.GetHorizontalDistance() * 0.5f;
	const float halfVerticalDistance = mHexagon.GetVerticalDistance() * 0.5f;

	const float startOffsetX = mHexagon.GetWidth() * 0.5f;
	const float startOffsetY = mHexagon.GetHeight() * 0.5f;

	const float textureWidth = GetMapWidth(mMapSize.x, mHexagon);
	const float textureHeight = GetMapHeight(mMapSize.y, mHexagon);
	
	mMapTexture->create(static_cast<unsigned int>(textureWidth), static_cast<unsigned int>(textureHeight), textureSettings);
	mMapTexture->clear(sf::Color::Black);
	//mMapTexture->setSmooth()

	for (unsigned int y = 0; y < mMapSize.y; ++y)
	{
		const bool isYEven = !(y % 2u);
		const float offsetX = (mHexagon.GetOrientation() == HexagonOrientation::PointyTopped && isYEven) ? halfHorizontalDistance : 0.0f;
		
		for (unsigned int x = 0; x < mMapSize.x; ++x)
		{
			const bool isXEven = !(x % 2u);
			const float offsetY = (mHexagon.GetOrientation() == HexagonOrientation::FlatTopped && isXEven) ? halfVerticalDistance : 0.0f;

			sf::Color Color(255, 255, 255);
			int foo = (y + x) % 3;
			
			if (foo == 0)
			{
				Color = sf::Color::Red;
			}
			if (foo == 1)
			{
				Color = sf::Color::Blue;
			}
			if (foo == 2)
			{
				Color = sf::Color::Green;
			}

			mHexagon.setFillColor(Color);

			const float hexagonPositionX = (mHexagon.GetHorizontalDistance() * x) + startOffsetX + offsetX;
			const float hexagonPositionY = (mHexagon.GetVerticalDistance() * y) + startOffsetY + offsetY;
			sf::Vector2f position(hexagonPositionX, hexagonPositionY);

			mHexagon.setPosition(position);

			mMapTexture->draw(mHexagon);
		}
	}

	mMapTexture->display();
	mMapSprite->setTexture(mMapTexture->getTexture());
}

HexagonMap::~HexagonMap()
{
	delete mMapTexture;
}

void HexagonMap::Render(sf::RenderWindow& window) const
{
	window.draw(*mMapSprite);
}