#include <string>
#include "WordStatistics.h"
#include<utility>
#include"Indexser.h"
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/utility.hpp>

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

