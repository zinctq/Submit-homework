// Buoi2.cpp : Can I do this on C++ :c
//
#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	ifstream inf;
	inf.open("datain.txt");
	int s = 0; int i;
	while (not inf.eof())
	{
		inf >> i;
		s += i;
	}
	ofstream ouf;
	ouf.open("dataout.txt");
	ouf << s;
	inf.close(); ouf.close();
}
