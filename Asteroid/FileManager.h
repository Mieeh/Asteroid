#include<fstream>
#include<Windows.h>
#include<iostream>

// This class will provide basic funtionality to reading from the text file
class FileManager{
public:
	void OpenTextFile();
	int GetHighscore();
	void WriteToTextFile(std::string _newHighscore);