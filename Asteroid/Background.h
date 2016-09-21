#include "SFML\Graphics.hpp"

class Background
{
public:
	Background();
	~Background();
	void Update(float frameTime);
	sf::VertexArray getVertexArray();
	sf::VertexArray vertexArray;

private:
	const int WIDTH = 100;
	const int HEIGHT = 100;
	const double xSPACING = 8;
	const double ySPACING = 6;
};