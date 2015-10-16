// xxTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <time.h>
#include "dataFormat.h"
#include "getopt.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int isMultiple = 0;
	XXTEA_TYPE key[4] = { 1, 2, 3, 4 };

	static int verbose_flag;
	int c;

	while (1)
	{        
		static struct option long_options[] =
		{
			{_T("delete"),  ARG_REQ,  0, _T('d')},
			{_T("create"),  ARG_REQ,  0, _T('c')},
			{_T("file"),    ARG_REQ, 0 , _T('f')},
			{ ARG_NULL , ARG_NULL , ARG_NULL , ARG_NULL }
		};

		int option_index = 0;
		c = getopt_long(argc, argv, _T("c:"), long_options, &option_index);

		// Check for end of operation or error
		if (c == -1)
			break;

		// Handle options
		switch (c)
		{
		case _T('c'):
			isMultiple = atoi((char*)optarg);
			if (isMultiple)
				printf("multiple thread to XXTEA.\n");
			else
				printf("single thread to XXTEA.\n");
			break;
		case '?':
			/* getopt_long already printed an error message. */
			break;
		default:
			abort();
		}
	}

	if (verbose_flag)
		_tprintf (_T("verbose flag is set\n"));


	if (optind < argc)
	{
		_tprintf (_T("non-option ARGV-elements: "));
		while (optind < argc) _tprintf (_T("%s "), argv[optind++]);
		_tprintf (_T("\n"));
	}

	clock_t start, finish;
	start = clock();
	double duration = 0;
	dataFormat* pDataFormat = new dataFormat();
	std::vector<char*> vecFilePath;
	__int64 fileNum = 20;

	for (int i = 0; i < fileNum; i++)
	{
		char path[128] = "hello.txt";
		vecFilePath.push_back(path);
	}

	pDataFormat->setKey(key);
	pDataFormat->readFile(fileNum, vecFilePath);
	pDataFormat->xxTea(isMultiple);
	pDataFormat->format();
	pDataFormat->display();

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("complete in %d seconds\n", duration);

	system("pause");

	return 0;
}