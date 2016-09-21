#include"Background.h"

Background::Background()
{
	vertexArray.clear();

	for (int x = 0; x < WIDTH; x++){
		for (int y = 0; y < HEIGHT; y++){
			sf::Vertex vertex;
			vertex.position = sf::Vector2f(x * xSPACING, y * ySPACING);
			vertex.color = sf::Color::White;
			vertexArray.append(vertex);
		}
	}

	for (int i = 0; i < vertexArray.getVertexCount(); i++){
		int _num = rand() % 6 + 1;
		if (_num == 1)
			vertexArray[i].color = sf::Color::Red;
		else if (_num == 2)
			vertexArray[i].color = sf::Color::Green;
		else if (_num == 3)
			vertexArray[i].color = sf::Color::Blue;
		else if (_num == 4)
			vertexArray[i].color = sf::Color::Yellow;
		else if (_num == 5)
			vertexArray[i].color = sf::Color::Magenta;
		else if (_num == 6)
			vertexArray[i].color = sf::Color::Cyan;
		else
			vertexArray[i].color = sf::Color::White;
	}
}

Background::~Background()
{
	vertexArray.clear();
}

void Background::Update(float frameTime)
{
	/*
	for (int i = 0; i < vertexArray.getVertexCount(); i++){
		int _num = rand() % 100;
		if (_num > 50)
			vertexArray[i].color = sf::Color::White;
		else if (_num < 50)
			vertexArray[i].color = sf::Color::Red;
		
	}
	*/
	/*
	for (int i = 0; i < vertexArray.getVertexCount(); i++){
		int _num = rand() % 6 + 1;
		if (_num == 1)
			vertexArray[i].color = sf::Color::Red;
		else if (_num == 2)
			vertexArray[i].color = sf::Color::Green;
		else if (_num == 3)
			vertexArray[i].color = sf::Color::Blue;
		else if (_num == 4)
			vertexArray[i].color = sf::Color::Yellow;
		else if (_num == 5)
			vertexArray[i].color = sf::Color::Magenta;
		else if (_num == 6)
			vertexArray[i].color = sf::Color::Cyan;
		else
			vertexArray[i].color = sf::Color::White;
	}
	*/
}

