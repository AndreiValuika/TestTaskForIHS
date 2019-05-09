#include <string>
#include "WordStatistics.h"
#include<utility>
#include"Indexser.h"
#pragma once

class Searcher
{
private:
	multimap<string, WordStatistics> body;
public:
	string findWord(string word);
	Searcher();

	Searcher( Indexser&);
	~Searcher();
};

