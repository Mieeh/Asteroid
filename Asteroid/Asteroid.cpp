#include"Asteroid.h"

Asteroid::Asteroid(sf::Vector2f _startPos, sf::Vector2f _dir){
	// Create the shape
	shape.setSize(sf::Vector2f(WIDTH, HEIGHT));
	shape.setOutlineThickness(3);
	shape.setOutlineColor(sf::Color::White);
	shape.setFillColor(sf::Color::Black);

	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(2);

	shape.setPosition(sf::Vector2f(_startPos.x, _startPos.y));

	dir.x = _dir.x;
	dir.y = _dir.y;
}

void Asteroid::Update(float frameTime, float speedFactor){
	// Moving the shape according to direction
	shape.move(sf::Vector2f(dir.x * VELOCITY * speedFactor * frameTime, dir.y * VELOCITY * speedFactor * frameTime));

	if (shape.getPosition().x < 0){
		shape.setPosition(sf::Vector2f(0, shape.getPosition().y));
		dir.x *= -1;
		VELOCITY *= speedIncrementFactor;
	}
	else if (shape.getPosition().x > 800 - WIDTH){
		shape.setPosition(sf::Vector2f(800 - WIDTH, shape.getPosition().y));
		dir.x *= -1;
		VELOCITY *= speedIncrementFactor;
	}
	if (shape.getPosition().y < 0){
		shape.setPosition(sf::Vector2f(shape.getPosition().x, 0));
		dir.y *= -1;
		VELOCITY *= speedIncrementFactor;
	}
	else if (shape.getPosition().y > 600 - HEIGHT){
		shape.setPosition(sf::Vector2f(shape.getPosition().x, 600 - HEIGHT));
		dir.y *= -1;
		VELOCITY *= speedIncrementFactor;
	}
}

void Asteroid::onEvent(const sf::Event &event){

}

sf::RectangleShape Asteroid::getShape(){
	return shape;
}