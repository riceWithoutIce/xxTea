// xxTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "xxtea.h"
#include <fstream>
#include <iostream>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	char* buffer;
	char* codeBuff;
	long size;
	long encodeSize;
	long key = 123124;
	long* lpKey = &key;
	ifstream fin("hello.txt", ios::in | ios::binary | ios::ate);
	if (!fin)
	{
		cout << "File open error!\n";
		return 0;
	}
	size = fin.tellg();
	fin.seekg(0, ios::beg);
	buffer = new char[size];
	fin.read(buffer, size);

	ofstream fout("encode.txt", ios::binary);

	if (fout.is_open())
	{
		encodeSize = XXTEA::XXTEAGetBufferLength(size, true);
		codeBuff = new char[encodeSize];
		printf("%d, %d", size, encodeSize);
		XXTEA::XXTEAEncode(codeBuff, buffer, size, lpKey);
		fout.write(codeBuff, encodeSize);
	}

	if (buffer)
	{
		delete[] buffer;
		buffer = nullptr;
	}
	if (codeBuff)
	{
		delete[] codeBuff;
		codeBuff = nullptr;
	}
	
	fin.close();
	fout.close();
	cout << "complete";

	system("pause");

	return 0;
}

