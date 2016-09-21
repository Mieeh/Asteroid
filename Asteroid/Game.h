#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	~Game();
	int run();

private:
	void createWindow();
	sf::RenderWindow window;
	bool running;
};