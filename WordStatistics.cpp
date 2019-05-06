#include "WordStatistics.h"
#include <string>
#include <iostream>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/utility.hpp>
#include <filesystem>
#include <fstream>

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

void WordStatistics::savetofile(ofstream &os,string)
{
	//std::ofstream os("c:\\Test\\te.bin",std::ios::app);
	cereal::BinaryOutputArchive archive(os);
	WordStatistics temp = WordStatistics();
	archive(temp);

}

string WordStatistics::getTitle()
{
	return title;
}

string WordStatistics::getFileName()
{
	return fileName;
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
