using namespace std;

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "WordStatistics.h"
#include "Indexser.h"
#include <regex>
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
	ind.showAll();

	
	
	ind.saveToFile("c:\\Test\\t25.xml");
	
	
	//ind.searchWord("Minsk");
	DWORD end = GetTickCount();
	cout << endl << (unsigned int)(end - start) << endl;
	int i;
	//cin >> i;
}
