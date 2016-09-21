#include"Laser.h"

Laser::Laser(sf::Vector2f startPos, float rotation)
{
	// Setting values for my shape
	shape.setFillColor(sf::Color::White);
	shape.setSize(sf::Vector2f(5, 5));

	// Setting initial screen values
	shape.setPosition(startPos);
	shape.setRotation(rotation);

	shape.setOrigin(sf::Vector2f(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2));

	isAlive = true;
}

Laser::~Laser()
{

}

void Laser::Update(float frameTime, float speedFactor)
{
	shape.move(sin(3.14159265 * shape.getRotation() / 180.f) * VELOCITY * speedFactor * frameTime,
		cos(3.14159265 * shape.getRotation() / 180.f) * VELOCITY * speedFactor * frameTime * -1);
}

sf::RectangleShape Laser::getShape()
{
	return shape;
}

void Laser::kill(){
	isAlive = false;
}

bool Laser::getState(){
	return isAlive;
}