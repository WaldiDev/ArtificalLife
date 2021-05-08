#include "HexagonMap.h"
#include "SFML/Graphics/Image.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"

HexagonMap::HexagonMap(sf::Image& mapInfo, const HexagonShape& hexagon)
	: mHexagon(hexagon)
	, mMapSize(mapInfo.getSize())
	, mMapTexture(new sf::RenderTexture())
	, mMapSprite(new sf::Sprite())
{
	const unsigned int textureWidth = mMapSize.x * static_cast<unsigned int>(mHexagon.GetWidth());
	const unsigned int textureHeight = mMapSize.y * static_cast<unsigned int>(mHexagon.GetHeight());

	sf::ContextSettings textureSettings;
	textureSettings.antialiasingLevel = 8;

	mMapTexture->create(textureWidth, textureHeight, textureSettings);
	mMapTexture->clear(sf::Color::White);
	//mMapTexture->setSmooth()

	for (unsigned int y = 0; y < mMapSize.y; ++y)
	{
		const bool isYEven = !(y % 2u);
		const float xOffset = (mHexagon.GetOrientation() == HexagonOrientation::PointyTopped && isYEven) ? mHexagon.GetHorizontalDistance() * 0.5f : 0.0f;
		
		for (unsigned int x = 0; x < mMapSize.x; ++x)
		{
			const bool isXEven = !(x % 2u);
			const float yOffset = (mHexagon.GetOrientation() == HexagonOrientation::FlatTopped && isXEven) ? mHexagon.GetVerticalDistance() * 0.5f : 0.0f;

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

			sf::Vector2f position((mHexagon.GetHorizontalDistance() * x) + xOffset, (mHexagon.GetVerticalDistance() * y) + yOffset);
			mHexagon.setPosition(position);

			mMapTexture->draw(mHexagon);
		}
	}

	//mHexagon.setFillColor(sf::Color::Blue);
	//mHexagon.setPosition(sf::Vector2f(100.0f, 100.0f));
	//mMapTexture->draw(mHexagon);

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
