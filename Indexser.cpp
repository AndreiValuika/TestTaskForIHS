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
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/utility.hpp>
#include <regex>
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
	DWORD start = GetTickCount();
	cout << path;
	vector<std::string> sentList;
	ifstream fin(path);
	string str;
	if (fin.peek() == 239) fin.seekg(3);
	int b = 0;
	char c;
	while (fin.peek() != EOF)
	{
		c = fin.get();
		str += c;
		if (c == '.' or c == '!' or c == '?')
		{
			int wchlen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.size(), NULL, 0);
			if (wchlen > 0 && wchlen != 0xFFFD)
			{
				std::vector<wchar_t> wbuf(wchlen);
				MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.size(), &wbuf[0], wchlen);
				std::vector<char> buf(wchlen);
				WideCharToMultiByte(1251, 0, &wbuf[0], wchlen, &buf[0], wchlen, 0, 0);

				str = string(&buf[0], wchlen);
				sentList.push_back(str);
				b++;
				str.clear();
			}
		}
	}

	fin.close();
	DWORD end = GetTickCount();
	cout << endl << (unsigned int)(end - start) << endl<<"sent="<<b<<endl;
	return sentList;
}

map <string,vector<int>> Indexser::parseSent(std::string line)
{
	DWORD start = GetTickCount();
	cout << line<<'+';
	int  offset=0;
	map<string,vector<int>> tempMap;
	vector<int> tempVector;
	
	cmatch result;
	regex regular("[a-zA-Zà-ÿÀ-ÿ]+|[0-9]+");
	string t;
	const sregex_token_iterator endOfSequence;

	sregex_token_iterator token(line.begin(), line.end(), regular);
	while (token != endOfSequence)
	{
		if (tempMap.find(*token) == tempMap.end())
		{
			tempVector.clear();
		}
		else
		{
			tempVector = tempMap.at(*token);
		}
		tempVector.push_back(offset++);
		tempMap.insert_or_assign(*token++, tempVector);
	}
	DWORD end = GetTickCount();
	cout << endl << "time parse sent:="<<(unsigned int)(end - start) << endl;
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
		DWORD start = GetTickCount();
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
		DWORD end = GetTickCount();
		cout << endl<<"time input:=" << (unsigned int)(end - start) << endl;
	} 
	for (auto & n : tempVector) this->addWordStatistics(n.second);
	return tempVector;
}

void Indexser::searchWord(string word)
{
	/*std::pair <std::multimap<string, WordStatistics>::iterator, std::multimap<string, WordStatistics>::iterator> ret;
	ret = general.equal_range(word);
	for (std::multimap<string, WordStatistics>::iterator it = ret.first; it != ret.second; ++it)
		 it->second.showStatisticst();
	std::cout << '\n';*/
}

void Indexser::parseFolder(string path)
{
	vector<string> fileList = getFileList(path);
	for (string s : fileList) parseFile(s);
}

void Indexser::addWordStatistics(WordStatistics temp)
{
	general.push_back(temp);
}

void Indexser::showAll()
{
	for (auto n : general) n.showStatisticst();
}

void Indexser::saveToFile(string path)
{
	ofstream os(path);
	cereal::XMLOutputArchive archive(os);
	archive(general);
}

void Indexser::loadFromFile(string path)
{
	ifstream is(path);
	cereal::XMLInputArchive archive(is);
	archive(general);
}
	
	
	
	
	
	


Indexser::Indexser()
{
}


Indexser::~Indexser()
{
}
