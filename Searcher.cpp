#include "Searcher.h"



string Searcher::findWord(string word)
{
	std::stringstream ss;
	ss<< " - \""<< word << "\"\n";
	std::pair <std::multimap<string, WordStatistics>::iterator, std::multimap<string, WordStatistics>::iterator> ret;
	ret = body.equal_range(word);
	for (std::multimap<string, WordStatistics>::iterator it = ret.first; it != ret.second; ++it) 
	{
		ss<< "\tFile \""+it->second.getFileName()+"\"\n\t";
		for (auto & n : it->second.getSentAndOffset()) 
		{
			ss<<"(Sent# " <<n.first<< ",offset = "<< n.second<< ")\n";
		}
		ss << "\t";
	}
		

	return ss.str();
}

Searcher::Searcher()
{
}


Searcher::Searcher(Indexser ind)
{
	for (auto temp : ind.general) body.insert(make_pair(temp.getTitle(), temp));
}

Searcher::~Searcher()
{
}
