// Buoi2.cpp : Can I do this on C++ :c
// Debug bằng VC++ thì thêm dòng stdafx.h
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	ifstream inf;
	inf.open("datain.txt");
	ofstream ouf;
	ouf.open("dataout.txt");
	string S;
	while (not inf.eof())
	{
		int N=0;
		inf >> S;
		for (int32_t i = 0; i <= S.length() - 1; i++)
		{
			N += (int)S[i];
		}
		ouf << N << endl;
	}
	inf.close(); ouf.close();
}
