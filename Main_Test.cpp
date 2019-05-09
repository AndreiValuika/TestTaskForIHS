using namespace std;

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "WordStatistics.h"
#include "Indexser.h"
#include <regex>
#include "Searcher.h"
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
	Indexser* ind =new  Indexser();
	//ind.parseFolder("c:\\Test");
	
	//ind.parseFolder("c:\\Test");
	//ind.showAll();
	//ind.saveToFile("c:\\Test\\t277.bin");
	//ind1.loadFromFile("c:\\Test\\t277.bin");
	//Searcher sr = Indexser(ind);
	//ind1.showAll();
	/*cout << "***************" << endl;
	cout << sr.findWord("Minsk");
	cout << "***************" << endl;
	cout << sr.findWord("Minskghj");
	cout << "***************" << endl;
	*/
	ind->loadFromFile("c:\\Test\\t277.bin");
	
	cout << "-----------------------------";
	DWORD start = GetTickCount();
	for (size_t i = 0; i < 10; i++)
	{
		Searcher* sr = new Searcher(*ind);
	} //Searcher sr = Searcher(ind);
	//ind.searchWord("Minsk");
	DWORD end = GetTickCount();
	cout << endl << (unsigned int)(end - start)/10 << endl;
	/*int i;
	cin >> i;*/
	system("pause");
}
