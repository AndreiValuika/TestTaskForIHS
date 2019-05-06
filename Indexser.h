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
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(general); 
	}
public:
	vector<string> getFileList(string path);
	vector<string> getSentFromFile(string path);
	map<string,vector<int>> parseSent(string line);
	map<string,WordStatistics> parseFile(string path);
	void parseFolder(string path);
	void addWordStatistics(WordStatistics);
	void showAll();
	void saveToFile(string path);
	void loadFromFile(string path);
	Indexser();
	~Indexser();
};

