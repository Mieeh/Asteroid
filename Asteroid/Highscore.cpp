#include"Highscore.h"

int FileManager::GetHighscore(){
	std::ifstream file;
	file.open("C:\\asteroids_save\\highscore.txt");

	// This gets the string from the text file then returns it as a integer
	std::string highscore;
	std::getline(file, highscore);
	return std::stoi(highscore);
}

void FileManager::WriteToTextFile(std::string _newHighscore){
	// This method just writes whatever parameter we want into our highscore text file
	std::ofstream file;
	file.open("C:\\asteroids_save\\highscore.txt");
	file << _newHighscore;
}

void FileManager::CreateTextFile(){
	_mkdir("C:\\asteroids_save");
	std::fstream file;

	file.open("C:\\asteroids_save\\highscore.txt");

	// This logic checks if the highscore is set to nothing if it is then set it to zero by default
	if (!file.is_open()){
		std::ofstream _file;
		_file.open("C:\\asteroids_save\\highscore.txt");
		_file << "0";
	}
}

void Highscore::GameEnd(int _highscore, sf::Text &highscoreText){
	// Opens and gets the highscore
	CreateTextFile();
	int highscore = GetHighscore();

	// Checks if we set a new highscore or not
	if (_highscore >= highscore){
		WriteToTextFile(std::to_string(_highscore));
		highscoreText.setString("New HIGHSCORE! " + std::to_string(_highscore));
	}
}