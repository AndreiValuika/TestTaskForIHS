#include <string>
#include <utility>
#include <vector>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>

using namespace std;
#pragma once
class WordStatistics
{
private:
	string title;
	string fileName;
	vector<pair<int, int>> sentAndOffset;
	friend class cereal::access;
public:
	void setTitle(string);
	void setFileName(string);
	void setSentAndOffset(vector<pair<int, int>>);
	void savetofile(ofstream& os, string);
	
	string getTitle();
	string getFileName();
	vector<pair<int, int>> getSentAndOffset();
	
	void showStatisticst();

	WordStatistics();
	WordStatistics(string title, string fileName, vector<pair<int, int>> sentAndOffset);
	WordStatistics(string, string, pair<int, int>);
	~WordStatistics();
};

