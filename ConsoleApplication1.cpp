// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include "Node.h"
#include<Windows.h>
#include "WordStatistics.h"
#include "Indexser.h"

namespace fs = std::experimental::filesystem; 

int main()
{
	//setlocale(LC_ALL, "Russian");
	vector<string>  vs1;
	string st;
		
	Indexser ind = Indexser();
	ind.parseFolder("c:\\Test");
	//map<string, vector<int>> tl;
	//tl = ind.parseSent("1 22 1 444 5555 22 66 5555");
	//for (auto it = tl.begin(); it != tl.end(); ++it)
	//{
	//	//cout << "Word:"<<it->first << endl;
	//	//myvi = it->second;
	//	cout << it->first << endl;
	//ind.
	//ind.parseFile("c:\\Test\\test1.txt");
	//	for (auto& n : it->second) cout << "Sent:" << n<<endl;// .first << "-- Offset:" << endl << n.second.first << "--" << n.second.second << endl;
	//}
	//ind.parseFile("c:\\Test\\t.txt");
	//vector<string> vs = ind.getFileList("c:\\Test");
	//std::cout << "-------------- \n";
	//wchar_t* st1;
	//for (auto& n : vs) 
	//{

	//}
	////	cout << "Sent:" << n << endl;
	////vector<string> sentList = ind.getFileList("c:\\Test");
	//
	//
	//
	//for (string n : vs) {
	//	cout << n.substr(n.find_last_of('\\'),n.npos).erase(0,1)<<endl;
	//	ifstream fin(n);
	//	string temp;
	//	
	//	while ( getline(fin, temp, '.'))
	//	{
	//		//temp.erase(temp.find('\n'), 1);
	//		std::cout << temp << '+' << '\n';
	//		vs1.push_back(temp);
	//	};
	//	fin.close();
	//}

	//
	//char* index = NULL;
	//char* cstr;
	//char* buf;
	//
	//WordStatistics tempWord;
	//map<string, WordStatistics> sMap;
	//pair<int, int> mpair,tpair;
	//typedef vector <pair<string,pair <int, int>>> vi;
	//vi myvi;
	//map<string, vi > mp;
	//int sent=0;
	//int offset;
	//
	//pair<string, pair <int, int>> tempPair;
	//
	//for (string n : vs1)
	//{
	//	cstr= &n[0u];
	//	buf = strtok_s(cstr, " .,!?",&index);
	//	offset = 0;
	//	myvi.clear();
	//	while (buf)
	//	{
	//		if (buf != NULL)
	//		{
	//			
	//			
	//			tempWord.setTitle(buf);
	//			tempWord.setFileName("1");
	//			tpair.first = sent;
	//			tpair.second = offset;
	//			//tempWord.setSentAndOffset(tpair);
	//			tempPair.first = "AF";
	//			tempPair.second.first = sent;
	//			tempPair.second.second = offset++;
	//			





	//			if (mp.find(buf) == mp.end()) 
	//			{
	//				myvi.clear();
	//			}
	//			else
	//			{
	//				myvi = mp.find(buf)->second;
	//			}
	//			myvi.push_back(tempPair);
	//			sMap.insert_or_assign(buf,tempWord);
	//			mp.insert_or_assign(buf, myvi);
	//			
	//		}
	//		buf = strtok_s(NULL, " .,!?",&index);
	//	}
	//	sent++;
	//}
	//cout << "-------------- \n";

	//for (auto it = mp.begin(); it != mp.end(); ++it)
	//{
	//	//cout << "Word:"<<it->first << endl;
	//	myvi = it->second;
	//	for (auto& n : myvi) cout << "Sent:" << n.first << "-- Offset:"<<endl << n.second.first <<"--"<<n.second.second<< endl;
	//}
	//cout << "---------------------------------" << endl;
	//for (auto it = sMap.begin(); it != sMap.end(); ++it)
	//{
	//	cout << it->first << endl;
	//	tempWord = it->second;
	//	for (auto& n : tempWord.getSentAndOffset) cout << "Sent:" << n.first << "-- Offset:" << endl;// << n.second << endl;
	//}

}


	



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
