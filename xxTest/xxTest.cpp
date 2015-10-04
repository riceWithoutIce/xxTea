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
	/*fileReadAndSave* pFile = new fileReadAndSave();
	char inFileName[512] = "encode.txt";
	char outFileName[512] = "decode.txt";
	XXTEA_TYPE key[4] = {1, 2, 3, 4};
	bool isEncode = false;
	pFile->setInFileName(inFileName);
	pFile->setOutFileName(outFileName);
	pFile->setKey(key);
	pFile->readFile();
	pFile->saveFile(isEncode);*/

	dataFormat* pDataFormat = new dataFormat();
	std::vector<char*> vecFilePath;
	for (int i = 0; i < 3; i++)
	{
		char path[128] = "hello\n";
		vecFilePath.push_back(path);
	}
	
	pDataFormat->initFile(3, vecFilePath);
	pDataFormat->display();

	printf("complete\n");

	system("pause");

	return 0;
}