// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include "Node.h"
#include "WordStatistics.h"
#include "Indexser.h"
#include <cereal/archives/binary.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#include<cereal/types/utility.hpp>
//#include <cereal/archives/json.hpp>

namespace fs = std::experimental::filesystem; 

int main()
{
	setlocale(LC_ALL, "");
		

	{
		std::ofstream os("c:\\Test\\te.bin");
		cereal::BinaryOutputArchive archive(os);


		vector<pair<int, string>> m1;
		pair<int, string> m11,m22;
		//m11.insert(make_pair(1, "a"));
		//m11.insert(make_pair(2, "b"));
		//m1.push_back(make_pair(1, "a"));
		////m22.insert(make_pair(3, "c"));
		//m22.insert(make_pair(4, "d"));
		//m1.push_back(make_pair(2, "b"));
		int someInt = 10;
		double d = 5.234;

		archive(m1,someInt, d); // specify a name of your choosing
	}

	{
		std::ifstream is("c:\\Test\\te.bin");
		cereal::BinaryInputArchive archive(is);

		vector<pair<int, string>> m2;
		int someInt;
		double d;

		//archive(m2, someInt, d);
		cin;
		// NVPs not strictly necessary when loading
		//cout <<m2<< someInt<<"---"<<d;					   // but could be used (even out of order)
	}








	cin;



	Indexser ind = Indexser();
	ind.parseFolder("c:\\Test");
	ind.showAll();
	ind.saveToFile("h");
	/*std::ofstream file("out.bin", std::ios::binary);
	cereal::PortableBinaryOutputArchive archive(file);
	std::map<std::wstring, std::wstring> dict;
	archive(dict);
	file.close();*/
	//ind.saveToFile();
	//Indexser ind1 = Indexser();
	//ind1.loadFromFile();
//	ind1.showAll();
}
