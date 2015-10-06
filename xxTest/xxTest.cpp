// xxTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "fileReadAndSave.h"
#include "dataFormat.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	dataFormat* pDataFormat = new dataFormat();
	std::vector<char*> vecFilePath;
	__int64 fileNum = 3;
	XXTEA_TYPE key[4] = {1, 2, 3, 4};
	for (int i = 0; i < fileNum; i++)
	{
		char path[128] = "hello.txt";
		vecFilePath.push_back(path);
	}

	pDataFormat->setKey(key);
	pDataFormat->readFile(fileNum, vecFilePath);
	pDataFormat->xxTea();
	pDataFormat->format();
	pDataFormat->display();

	printf("complete\n");

	system("pause");

	return 0;
}