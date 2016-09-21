#include"Ship.h"

Ship::Ship()
{
	// width 20
	// height 25
	shape.setPointCount(3);
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(20, 0));
	shape.setPoint(2, sf::Vector2f(10, -25));
	

	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(2);
	shape.setPointCount(3);
	shape.setOrigin(sf::Vector2f(10, -12.5f));
	shape.setPosition(sf::Vector2f(800/2, 600/2));
	horizontal_input = 0;
	vertical_input = 0;
}

void Ship::Update(float frameTime)
{
	// If we have pressed either right or left then rotate
	if (horizontal_input != 0)
	{
		shape.rotate(horizontal_input * ROT_FORCE * frameTime);
	}
	if (vertical_input != 0)
	{
		shape.move(vertical_input * 0.4 * sin(3.14159265 * shape.getRotation() / 180.f) * frameTime,
			 vertical_input * 0.4 * cos(3.14159265 * shape.getRotation() / 180.f) * frameTime * -1);
	}
}

void Ship::onEvent(const sf::Event& event)
{
	horizontal_input = 0;
	vertical_input = 0;

	// This controlls up down right and left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		horizontal_input = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		horizontal_input = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		vertical_input = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		vertical_input = -1;
	}
}

int Ship::getVerticalInput(){
	return vertical_input;
}

int Ship::getHorizontalInput(){
	return horizontal_input;
}

sf::ConvexShape Ship::getShape()
{
	return shape;
}