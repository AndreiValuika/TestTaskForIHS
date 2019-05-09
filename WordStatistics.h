#include <string>
#include <utility>
#include <vector>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/utility.hpp>

using namespace std;
#pragma once
class WordStatistics
{
private:
	string title;
	string fileName;
	vector<pair<int, int>> sentAndOffset;
	

	friend class cereal::access;
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(title, fileName, sentAndOffset); // serialize things by passing them to the archive
	}
public:
	void setTitle(string);
	void setFileName(string);
	void setSentAndOffset(vector<pair<int, int>>);
	
	string getTitle();
	string getFileName();
	vector<pair<int, int>> getSentAndOffset();
	
	void showStatisticst(ostream&);

	WordStatistics();
	~WordStatistics();
};

