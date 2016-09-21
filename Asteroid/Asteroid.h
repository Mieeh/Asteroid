#include"SFML\Graphics.hpp"
//#include"Laser.h"

class Asteroid{
public:
	Asteroid(sf::Vector2f _startPos, sf::Vector2f _dir);

	void Update(float frameTime, float speedFactor);
	void onEvent(const sf::Event& event);

	sf::RectangleShape getShape();

private:
	sf::RectangleShape shape;

	sf::Vector2f dir;
	
	const double speedIncrementFactor = 1.02;
	double VELOCITY = 0.1;
	const int WIDTH = 70;
	const int HEIGHT = 70;
};