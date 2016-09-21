#include"Scene.h"
#include <iostream>

Scene::Scene(){
}

Scene::~Scene()
{
	return;
}

void Scene::Start()
{
	// Clear the laser vector on start of the game
	laserList.clear();
	asteroidList.clear();

	// Fil the asteroids list
	Asteroid _asteroid1(sf::Vector2f(5, 5), sf::Vector2f(1, 2));
	Asteroid _asteroid2(sf::Vector2f(800 - 75, 5), sf::Vector2f(-1, 1));
	Asteroid _asteroid3(sf::Vector2f(800 - 75, 600 - 75), sf::Vector2f(-2, -2));
	Asteroid _asteroid4(sf::Vector2f(5, 600 - 75), sf::Vector2f(2, -1));

	asteroidList.push_back(_asteroid1);
	asteroidList.push_back(_asteroid2);
	asteroidList.push_back(_asteroid3);
	asteroidList.push_back(_asteroid4);

	// Setting up the score
	score = 0;
	if (!scoreTextFont.loadFromFile("AGENCYR.ttf"))
		sf::err();
	scoreText.setFont(scoreTextFont);
	scoreText.setCharacterSize(50);
	scoreText.setColor(sf::Color::White);
	scoreText.setPosition(sf::Vector2f((800/2)-92.5, 3));
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setStyle(sf::Text::Underlined);

	// Game over text 
	gameOverText_1.setFont(scoreTextFont);
	gameOverText_1.setCharacterSize(60);
	gameOverText_1.setColor(sf::Color::White);
	gameOverText_1.setPosition(425/ 2, 310 / 2);

	// High score text
	highscoreText.setFont(scoreTextFont);
	highscoreText.setCharacterSize(60);
	highscoreText.setColor(sf::Color::White);
	highscoreText.setPosition(425 / 2, 100 / 2);
	highscoreText.setString("");

	// Fire rate values will be set to zero at the start
	canShoot = true;
	timeSinceShot = 0;

	// Set the players position and rotation to init values
	ship.getShape().setPosition(sf::Vector2f((800 / 2) - 10, (600 / 2) - 12.5));
	ship.getShape().setRotation(0);
}

void Scene::onEvent(const sf::Event& event)
{
	// The ship on event which takes input for movement
	ship.onEvent(event);

	//If the player pressed SPACE instantiate a laser and add it to the laser vector
	if (event.type == sf::Event::KeyPressed){
		if (event.key.code == sf::Keyboard::Space && canShoot){
			canShoot = false;
			timeSinceShot = 0;
			Laser laser(ship.getShape().getPosition(), ship.getShape().getRotation());
			laserList.push_back(laser);
		}
	}
}

void Scene::GameOverUpdate(float frameTimem, sf::RenderTarget& target){
	// If the player pressed R restart the scene with the Start() method
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
		gameOver = false;
		Start();
	}

	// Draw some stuff
	// LAYER 0 - Background vertex array
	target.draw(background.vertexArray);

	// LAYER 1 - Background objects

	// Layer 2 - Info text
	target.draw(gameOverText_1);
	target.draw(highscoreText);
}

void Scene::Update(float frameTime)
{
	// Call the ship update method, moves the ship
	ship.Update(frameTime);

	background.Update(frameTime);

	/*
	// Updating all the lasers
	if (ship.getVerticalInput() > 0){
		for (int i = 0; i < laserList.size(); i++)
		{
			laserList[i].Update(frameTime, 1);
		}

		// Updating all the asteroids
		for (int i = 0; i < asteroidList.size(); i++)
		{
			asteroidList[i].Update(frameTime, 1);
		}

		// Fire rate logic
		if (!canShoot){
			timeSinceShot += 0.1 * frameTime;
			if (timeSinceShot >= 5)
				canShoot = true;
		}
	}
	else if (ship.getVerticalInput() < 0){
		for (int i = 0; i < laserList.size(); i++)
		{
			laserList[i].Update(frameTime, -1);
		}

		// Updating all the asteroids
		for (int i = 0; i < asteroidList.size(); i++)
		{
			asteroidList[i].Update(frameTime, -1);
		}

		// Fire rate logic
		if (!canShoot){
			timeSinceShot += 0.1 * frameTime;
			if (timeSinceShot >= 5)
				canShoot = true;
		}
	}
	else{
		// Updating all the asteroids
		for (int i = 0; i < asteroidList.size(); i++)
		{
			asteroidList[i].Update(frameTime, 0.15);
		}
		for (int i = 0; i < laserList.size(); i++)
		{
			laserList[i].Update(frameTime, 0.15);
		}
	}
	*/

	if (ship.getVerticalInput() != -1){
		for (int i = 0; i < laserList.size(); i++)
		{
			laserList[i].Update(frameTime, 1);
		}

		// Updating all the asteroids
		for (int i = 0; i < asteroidList.size(); i++)
		{
			asteroidList[i].Update(frameTime, 1);
		}
	}
	else{
		for (int i = 0; i < laserList.size(); i++)
		{
			laserList[i].Update(frameTime, -1);
		}

		// Updating all the asteroids
		for (int i = 0; i < asteroidList.size(); i++)
		{
			asteroidList[i].Update(frameTime, -1);
		}
	}

	// Fire rate logic
	if (!canShoot){
		timeSinceShot += 0.1 * frameTime;
		if (timeSinceShot >= 5)
			canShoot = true;
	}

	// Checking for if any laser is outside the screen
	for (int i = 0; i < laserList.size(); i++){
		if (isOutsideScreen(laserList[i].getShape().getPosition())){
			laserList[i].kill();
		}
	}

	// Collision between the player and any asteroid
	asteroids_shipCollider();
	// Collision between laserlist and asteroids list
	laser_asteroidsCollider();

	scoreText.setString("Score: " + std::to_string(score));
}

void Scene::Show(sf::RenderTarget& target)
{
	//LAYER 0
	//The background is rendered first, the rest is rendered on top of the background
	target.draw(background.vertexArray);

	//LAYER 1
	//Rendering all the lasers from the Ships laserList
	for (int i = 0; i < laserList.size(); i++){
		if (laserList[i].getState() == true)
			target.draw(laserList[i].getShape());
	}

	//LAYER 2
	// This is rendered last because we want it to be on top
	target.draw(ship.getShape());

	// Drawing all the asteroids from the asteroids list
	for (int i = 0; i < asteroidList.size(); i++)
	{
		target.draw(asteroidList[i].getShape());
	}

	target.draw(scoreText);
}

void Scene::asteroids_shipCollider(){
	// This function checks for any collision the player might have with any shape from the asteroids list
	// This function returns true if the player collided with any if not then its a return false

	for (int i = 0; i < 4; i++){
		if (ship.getShape().getGlobalBounds().intersects(asteroidList[i].getShape().getGlobalBounds()))	{
			gameOverText_1.setString("Game Over! \nFinal Score: " + std::to_string(score) + "\nPress R");
			gameOver = true;
			Highscore highscore;
			highscore.GameEnd(score, highscoreText);
		}
	}
}

void Scene::laser_asteroidsCollider(){
	// This function checks for any collision between the laser list and the asteroids list
	for (int i = 0; i < asteroidList.size(); i++){
		for (int j = 0; j < laserList.size(); j++){
			if (asteroidList[i].getShape().getGlobalBounds().intersects(laserList[j].getShape().getGlobalBounds()) && laserList[j].getState()){
				laserList[j].kill();
				score += 10;
				scoreText.setString("Score: " + std::to_string(score));
			}
		}
	}
}

bool Scene::isOutsideScreen(sf::Vector2f _pos){
	// This function takes a vector position and returns true if it's outside the screen(800x600)
	if (_pos.x > 900)
		return true;
	else if (_pos.x < -100)
		return true;
	else if (_pos.y > 700)
		return true;
	else if (_pos.y < -100)
		return true;
	else
		return false;
}