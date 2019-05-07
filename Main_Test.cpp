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
	
	



	/*string st = "aaÀÀÀaa bb5	5f tt-ur 18-òè ëåòíèé";
	cmatch result;
	regex regular("[a-zA-Zà-ÿÀ-ÿ]+|[0-9]+");
	std::regex r("[Hh][aeo]h[aeo]");
	const sregex_token_iterator endOfSequence;

	sregex_token_iterator token(st.begin(), st.end(), regular);
	while (token != endOfSequence)
	{
		std::cout << *token++ << std::endl;
	}*/
	

	setlocale(LC_ALL, "");
	Indexser ind = Indexser();
	ind.parseFolder("c:\\Test");
	ind.saveToFile("c:\\Test\\t26.bin");

	ind.loadFromFile("C:\\Test\\t26.bin");
	ind.showAll();
}
