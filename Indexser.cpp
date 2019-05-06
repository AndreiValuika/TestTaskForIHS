#include <filesystem>
#include "Indexser.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include<Windows.h>
#include "WordStatistics.h"
#include "Indexser.h"
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>

using namespace std;
namespace fs = std::experimental::filesystem;


std::vector<std::string> Indexser::getFileList(std::string path)
{
	std::vector<std::string> fileList;
	for (auto p : fs::directory_iterator(path))
	{
		if (!fs::is_regular_file(p.status()))
			continue;
		if (p.path().filename().extension().string()._Equal(".txt"))
			fileList.push_back(p.path().string());
	}
	
	return fileList;
}

std::vector<std::string> Indexser::getSentFromFile(std::string path)
{
	vector<std::string> sentList;

	ifstream fin(path);
	string temp;
	while (getline(fin, temp, '.'))
	{
		sentList.push_back(temp);
	}
	fin.close();
	return sentList;
}

map <string,vector<int>> Indexser::parseSent(std::string line)
{
	int  offset=0;
	char* cstr = &line[0u];
	char* index = NULL;
	char* buf;
	map<string,vector<int>> tempMap;
	vector<int> tempVector;
	buf = strtok_s(cstr, " .,!?", &index);
	while (buf)
	{
		if (buf != NULL)
		{
			if (tempMap.find(buf) == tempMap.end())
			{
				tempVector.clear();
			}
			else
			{
				tempVector=tempMap.at(buf);
			}
			tempVector.push_back(offset++);
			tempMap.insert_or_assign(buf, tempVector);
		}
		buf = strtok_s(NULL, " .,!?", &index);
	}
	return tempMap;
}

map <string,WordStatistics> Indexser::parseFile(string path)
{
	string word;
	string fileName = path.substr(path.find_last_of('\\'), path.npos).erase(0,1);
	map<string,WordStatistics> tempVector;
	WordStatistics tempWord;
	vector<pair<int, int>> temp,temp1;
	tempWord.setFileName(fileName);
	vector<string> sentList = getSentFromFile(path);
	int sent = 0;
	for (auto n = sentList.begin(); n != sentList.end(); ++n)
	{
		map<string, vector<int>> sentWordIndex = parseSent(*n);
		for (auto it = sentWordIndex.begin(); it != sentWordIndex.end(); ++it)
		{
			temp.clear();
			word = it->first;
			tempWord.setTitle(word);
			for (auto& n : it->second) temp.push_back(make_pair(sent, n));
			if (tempVector.find(word) == tempVector.end()) 
			{
				tempWord.setSentAndOffset(temp);
			}
			else
			{
				temp1 = tempVector.at(word).getSentAndOffset();
				temp1.insert(temp1.end(), temp.begin(), temp.end());
				tempWord.setSentAndOffset(temp1);
			}
			tempVector.insert_or_assign(word, tempWord);
		}
		sent++;
	} 
	std::cout << std::endl;
	for (auto & n : tempVector) this->addWordStatistics(n.second);
	return tempVector;
}

void Indexser::parseFolder(string path)
{
	vector<string> fileList = getFileList(path);
	for (string s : fileList) parseFile(s);
}

void Indexser::addWordStatistics(WordStatistics temp)
{
	general.insert(make_pair(temp.getTitle(),temp));
}

void Indexser::showAll()
{
	for (auto n : general) n.second.showStatisticst();
}

void Indexser::saveToFile(string path)
{
	ofstream os("c:\\Test\\te1.bin");
	for (auto n : general) n.second.savetofile(os , "g");
	os.close();
}

void Indexser::loadFromFile()
{
	ifstream is("c:\\Test\\te1.bin");
	
}
	
	
	
	
	
	


Indexser::Indexser()
{
}


Indexser::~Indexser()
{
}
