using namespace std;

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "WordStatistics.h"
#include "Indexser.h"
#include <regex>
#include "Searcher.h"
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/utility.hpp>

template<typename CharT>
basic_string<CharT> replaceString(const CharT* find, const CharT* str, const CharT* repl)
{
	basic_string<CharT> text(str);
	basic_regex<CharT> reg(find);
	return regex_replace(text, reg, repl);
}




int main()
{
	
	
	setlocale(LC_ALL, "");
	Indexser ind,ind1 = Indexser();
	
	
	ind.parseFolder("c:\\Test");//"c:\\Test");E:\C++\Test\test3\TestTaskForIHS\TestFolder
	ind.showAll(std::cout);
	
	cout << "1" << endl;
	ind.saveToFile("c:\\Test\\test.xml");
	cout << "2" << endl;
	ind1.loadFromFile("c:\\Test\\test.xml");
	ind1.showAll(std::cout);
	DWORD start = GetTickCount();
	Searcher sch = Searcher(ind1);
	cout << sch.findWord("Minsk");
	DWORD end = GetTickCount();
	cout << endl << (unsigned int)(end - start)/10 << endl;
	
	system("pause");
}
