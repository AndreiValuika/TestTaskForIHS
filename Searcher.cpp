#include "Searcher.h"



string Searcher::findWord(string word)
{
	std::stringstream ss;
	ss<< " - Word\""<< word << "\"\n";
	std::pair <std::multimap<string, WordStatistics>::iterator, std::multimap<string, WordStatistics>::iterator> ret;
	ret = body.equal_range(word);
	if (ret.first==ret.second)
	{
		ss<<"Not found;";
	}
	else
	{
		for (std::multimap<string, WordStatistics>::iterator it = ret.first; it != ret.second; ++it)
		{
			ss << "\n\tFile \"" + it->second.getFileName() + "\"\n";
			for (auto& n : it->second.getSentAndOffset())
			{
				ss << "\t\t(Sent# " << n.first << ",offset = " << n.second << ")\n";
			}
		}
	}
	return ss.str();
}

Searcher::Searcher()
{
}


Searcher::Searcher( Indexser& ind)
{
	for (auto temp : ind.general) body.insert(make_pair(temp.getTitle(), temp));
}

Searcher::~Searcher()
{
}
