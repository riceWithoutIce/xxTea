// xxTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
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
	pDataFormat->initFile(1, "hello");
	pDataFormat->display();

	printf("complete\n");

	system("pause");

	return 0;
}