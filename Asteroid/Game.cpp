#include "Game.h"
#include "Scene.h"

Game::Game() {
	running = true;
}

Game::~Game() {
	window.close();
}

int Game::run() {

	// This function will create a window and also delete if there's already an existing one
	createWindow();

	// Creating the scene object from the Scene class
	Scene scene;

	// The clock to use as frame time
	sf::Clock clock;

	// This will initialize the game reseting score etc
	scene.Start();

	srand(time(NULL));

	// Run the game as long as the Game running bool is true
	while (running) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
				return 1;
			}
			// The event handler for the scene
			scene.onEvent(event);
		}
		window.clear();
		if (!scene.gameOver){
			scene.Update(clock.restart().asMilliseconds()); // This handles game logic as well as input
			scene.Show(window); // This renders the objects from the game
		}
		else{
			// Game over logic
			scene.GameOverUpdate(clock.restart().asMilliseconds(), window);
		}

		window.display();
	}
	return 1;
}

void Game::createWindow() {
	if (window.isOpen())
		window.close();

	window.create(sf::VideoMode(800, 600), "Ass-teroids");
	window.setFramerateLimit(120); 
}