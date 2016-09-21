#include"SFML\Graphics.hpp"

class Laser{
public:
	Laser(sf::Vector2f startPos, float rotation);
	~Laser();

	void Update(float frameTime, float speedFactor);
	void kill();
	bool getState();
	void Show(sf::RenderTarget &target);
	sf::RectangleShape getShape();

private:
	sf::RectangleShape shape;
	bool isAlive;

	const float VELOCITY = 0.5f;
};