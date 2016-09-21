#include"SFML\Graphics.hpp"

class Ship{
public:
	Ship();

	sf::ConvexShape getShape();

	void Update(float frameTime);
	void onEvent(const sf::Event& event);

	int getVerticalInput();
	int getHorizontalInput();

private:
	sf::ConvexShape shape;

	const float ROT_FORCE = 0.2f;
	float SPEED = 0.2f;

	int horizontal_input, vertical_input;
};