#include"SFML\Graphics.hpp"

#include<fstream>
#include<iostream>
#include<direct.h>

#pragma once

// This class will provide basic funtionality to reading from the text file
class FileManager{
public:
	void CreateTextFile();
	int GetHighscore();
	void WriteToTextFile(std::string _newHighscore);
};

// This class will controll setting text and checking if the player beat the last highscore
class Highscore : public FileManager{
public:
	void GameEnd(int _highscore, sf::Text &highscoreText);

};