#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include "Node.h"
#include<Windows.h>
#include "WordStatistics.h"
#pragma once
class Indexser
{
private:
	multimap < string, WordStatistics> general;
	friend class cereal::access;
public:
	std::vector<std::string> getFileList(std::string path);
	std::vector<std::string> getSentFromFile(std::string path);
	map<string,vector<int>> parseSent(std::string line);
	map<string,WordStatistics> parseFile(string path);
	void parseFolder(string path);
	void addWordStatistics(WordStatistics);
	void showAll();
	void saveToFile(string path);
	//void saveToFile(string);
	void loadFromFile();
	Indexser();
	~Indexser();
};

