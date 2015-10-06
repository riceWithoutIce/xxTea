// xxTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include "dataFormat.h"
#include <time.h>

int _tmain(int argc, _TCHAR* argv[])
{
	clock_t start, finish;
	start = clock();
	double duration = 0;
	dataFormat* pDataFormat = new dataFormat();
	std::vector<char*> vecFilePath;
	__int64 fileNum = 20;
	XXTEA_TYPE key[4] = {1, 2, 3, 4};

	for (int i = 0; i < fileNum; i++)
	{
		char path[128] = "hello.txt";
		vecFilePath.push_back(path);
	}

	pDataFormat->setKey(key);
	pDataFormat->readFile(fileNum, vecFilePath);
	pDataFormat->xxTea(false);
	pDataFormat->format();
	pDataFormat->display();

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("complete in %d seconds\n", duration);

	system("pause");

	return 0;
}