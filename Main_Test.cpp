using namespace std;

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "WordStatistics.h"
#include "Indexser.h"


int main()
{
	setlocale(LC_ALL, "");
	
	Indexser ind = Indexser();
	ind.parseFolder("c:\\Test");
	ind.saveToFile("c:\\Test\\t26.bin");

	ind.loadFromFile("C:\\Test\\t26.bin");
	ind.showAll();
}
