#include <filesystem>
//#include "Indexser.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include<Windows.h>
#include "WordStatistics.h"
//#include "Indexser.h"
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/utility.hpp>
#include <regex>

#pragma once
class Indexser
{
private:
	vector<WordStatistics> general;
	
	friend class Searcher;
	friend class cereal::access;
	
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(general); 
	}
public:
	vector<string> getFileList(string path);
	vector<string> getSentFromFile(const string& path);
	map<string,vector<int>> parseSent(string line);
	void parseFile(string path, ostream& stream);
	void parseFile(string path);
	void parseFolder(string path, ostream& stream);
	void parseFolder(string path);
	void addWordStatistics(WordStatistics);
	void showAll(ostream&);
	void saveToFile(string path);
	void loadFromFile(string path);
	Indexser();
	~Indexser();
};

