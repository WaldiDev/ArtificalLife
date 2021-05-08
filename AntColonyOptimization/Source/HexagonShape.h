#pragma once
#include "SFML/Graphics/Shape.hpp"
#include "SFML/System/Vector2.hpp"

enum  HexagonOrientation
{
	FlatTopped,
	PointyTopped
};

constexpr size_t HexagonPointCount = 6u;

class HexagonShape : public sf::Shape
{
public:
	HexagonShape(float size, HexagonOrientation orientation);

	float GetSize() const { return mSize; }
	HexagonOrientation GetOrientation() const { return mOrientation; }

	float GetWidth() const { return mWidth; }
	float GetHeight() const { return mHeight; }

	float GetHorizontalDistance() const { return mHorizontalDistance; }
	float GetVerticalDistance() const { return mVerticalDistance; }

	virtual std::size_t getPointCount() const override;

	virtual sf::Vector2f getPoint(std::size_t index) const override;

protected:
	float mSize;
	HexagonOrientation mOrientation;

	float mWidth;
	float mHeight;

	float mHorizontalDistance;
	float mVerticalDistance;

	sf::Vector2f mPoints[HexagonPointCount];
};
