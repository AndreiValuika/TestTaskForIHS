#include "WordStatistics.h"
#include <string>
#include <iostream>


void WordStatistics::setTitle(string title)
{
	this->title = title;
}

void WordStatistics::setFileName(string fileName)
{
	this->fileName = fileName;
}

void WordStatistics::setSentAndOffset(vector<pair<int, int>> temp)
{
	this->sentAndOffset = temp;
}

string WordStatistics::getTitle()
{
	return string();
}

string WordStatistics::getFileName()
{
	return string();
}

vector<pair<int, int>> WordStatistics::getSentAndOffset()
{
	return this->sentAndOffset;
}

void WordStatistics::showStatisticst()
{
	cout << "Word: \"" << title << "\" : {file:\"" << fileName << "\",(";
	for(auto n : sentAndOffset) 
	{
		cout << "(Sent#" << n.first << " ,offset=" << n.second << ")" ;

	}
	cout << ")}" << endl;
}



WordStatistics::WordStatistics()
{
}

WordStatistics::WordStatistics(string title, string fileName, vector<pair<int, int>> sentAndOffset)
{
	this->title = title;
	this->fileName = fileName;
	this->sentAndOffset=sentAndOffset;
}


WordStatistics::~WordStatistics()
{
}
