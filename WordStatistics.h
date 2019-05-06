#include <string>
#include <utility>
#include <vector>
using namespace std;
#pragma once
class WordStatistics
{
private:
	string title;
	string fileName;
	vector<pair<int, int>> sentAndOffset;
public:
	void setTitle(string);
	void setFileName(string);
	void setSentAndOffset(vector<pair<int, int>>);

	string getTitle();
	string getFileName();
	vector<pair<int, int>> getSentAndOffset();
	
	void showStatisticst();

	WordStatistics();
	WordStatistics(string title, string fileName, vector<pair<int, int>> sentAndOffset);
	WordStatistics(string, string, pair<int, int>);
	~WordStatistics();
};

