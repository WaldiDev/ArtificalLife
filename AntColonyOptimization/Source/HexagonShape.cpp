#include "HexagonShape.h"

namespace
{
	float GetHexagonWith(float size, HexagonOrientation orientation)
	{
		return (orientation == HexagonOrientation::PointyTopped) ? 1.732050807568877f * size : 2.0f * size;
	}

	float GetHexagonHeight(float size, HexagonOrientation orientation)
	{
		return (orientation == HexagonOrientation::FlatTopped) ? 1.732050807568877f * size : 2.0f * size;
	}

	float GetHexagonHorizontalDistance(float width, HexagonOrientation orientation)
	{
		return (orientation == HexagonOrientation::PointyTopped) ? width : width * 0.75f;
	}

	float GetHexagonVerticalDistance(float height, HexagonOrientation orientation)
	{
		return (orientation == HexagonOrientation::FlatTopped) ? height : height * 0.75f;
	}

	sf::Vector2f CreatePoint(float size, size_t index, HexagonOrientation orientation)
	{
		static const float pi = 3.14159265358979323846f;

		const float offset = (orientation == HexagonOrientation::PointyTopped) ? 30.0f : 0.0f;

		const float degree = (60.0f * index) + offset;
		const float radians = pi / 180.0f * degree;

		const float x = size * cosf(radians);
		const float y = size * sinf(radians);

		return sf::Vector2f(x, y);
	}
}

HexagonShape::HexagonShape(float size, HexagonOrientation orientation)
	: mSize(size)
	, mOrientation(orientation)
	, mWidth(GetHexagonWith(mSize, orientation))
	, mHeight(GetHexagonHeight(mSize, orientation))
	, mHorizontalDistance(GetHexagonHorizontalDistance(mWidth, orientation))
	, mVerticalDistance(GetHexagonVerticalDistance(mHeight, orientation))
{
	const float outlineThickness = 1.0f;
	sf::Vector2f points[6];
	for (size_t index = 0u; index < HexagonPointCount; ++index)
	{
		mPoints[index] = CreatePoint(mSize - outlineThickness, index, mOrientation);
	}

	update();
}

std::size_t HexagonShape::getPointCount() const
{
	return HexagonPointCount;
}

sf::Vector2f HexagonShape::getPoint(std::size_t index) const
{
	return mPoints[index];
}
