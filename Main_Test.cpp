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
	
	ofstream fout("c:\\Test\\SentIndex.txt");
	ind.parseFolder("c:\\Test",fout);
	fout.close();
	ind.showAll(cout);
	
	ind.saveToFile("c:\\Test\\test.xml");
	ind1.loadFromFile("c:\\Test\\test.xml");
	ind1.showAll(cout);
	DWORD start = GetTickCount();
	Searcher sch = Searcher(ind1);
	cout << sch.findWord("Minsk");
	cout << sch.findWord("Minsk1");
	DWORD end = GetTickCount();
	cout << endl << (unsigned int)(end - start) << endl;
	
	system("pause");
}
