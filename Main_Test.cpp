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
	//ind.parseFolder("c:\\Test");
	DWORD start = GetTickCount();
	ind.parseFolder("c:\\Test");
	//ind.showAll();
	ind.saveToFile("c:\\Test\\t277.bin");
	ind1.loadFromFile("c:\\Test\\t277.bin");
	Searcher sr = Indexser(ind1);
	//ind1.showAll();
	cout << sr.findWord("Minsk");
	cout << "***************" << endl;
	cout << sr.findWord("Minskghj");
	cout << "***************" << endl;
	*/
	ind->loadFromFile("c:\\Test\\t277.bin");
	
	ind.saveToFile("c:\\Test\\t277.bin");
	cout << "-----------------------------";
	
	//ind.searchWord("Minsk");
	DWORD end = GetTickCount();
	cout << endl << (unsigned int)(end - start) << endl;
	int i;
	//cin >> i;
}
