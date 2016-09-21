#include"SFML\Graphics.hpp"

#include"Ship.h"
#include"Background.h"
#include"Laser.h"
#include"Asteroid.h"
#include"Highscore.h"

class Scene
{
public:
	Scene(); // Constructor 
	~Scene(); // Destructor

	void onEvent(const sf::Event& event);
	void Update(float frameTime);
	void GameOverUpdate(float frameTime, sf::RenderTarget& target);
	void Show(sf::RenderTarget& target);
	void Start();
	bool isOutsideScreen(sf::Vector2f _pos);

	void asteroids_shipCollider();
	void laser_asteroidsCollider();

	bool gameOver = false;

private:
	// This is probably where the spaceship, asteroids etc will be stored and then used in the .cpp file
	Ship ship;
	Background background;
	std::vector<Laser> laserList;
	std::vector<Asteroid> asteroidList;
	int score;

	sf::Text scoreText;
	sf::Font scoreTextFont;
	sf::Text gameOverText_1;
	sf::Text highscoreText;

	bool canShoot;
	double timeSinceShot;
};