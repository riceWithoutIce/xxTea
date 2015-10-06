#include "stdafx.h"
#include "fileReadAndSave.h"
#include <fstream>

using namespace std;


fileReadAndSave::fileReadAndSave(void)
{
	m_xxtea = new XXTEA();
}


fileReadAndSave::~fileReadAndSave(void)
{

}

__int64 fileReadAndSave::getxxTeaBufferSize(__int64 size, bool isEncode)
{
	return m_xxtea->XXTEAGetBufferLength(size, isEncode);
}

char* fileReadAndSave::readFile(const char* fileName, __int64& size)
{
	ifstream fin(fileName, ios::in | ios::binary | ios::ate);
	if (!fin)
	{
		printf("File open error!\n");
		return 0;
	}
	char* buffer;
	size = fin.tellg();
	fin.seekg(0, ios::beg);
	buffer = new char[size + 1];
	fin.read(buffer, size);
	buffer[size + 1] = '\0';
	fin.close();
	//size = m_xxtea->XXTEAGetBufferLength(size, true);
	return buffer;
}

void fileReadAndSave::saveFile(char* buffer, __int64 size)
{
	ofstream fout("result.txt", ios::binary);
	fout.write(buffer, size);
	fout.close();
}

void fileReadAndSave::saveFileAtTheEnd(char* buffer, __int64 size)
{
	ofstream fout("result.txt", ios::binary | ios::app);
	fout.write(buffer, size);
	fout.close();
}

char* fileReadAndSave::xxTeaFile(char* inBuffer, const __int64 inSize, __int64& outSize, XXTEA_TYPE* pKey)
{
	outSize = m_xxtea->XXTEAGetBufferLength(inSize, true);
	char* outBuffer = new char[outSize];
	m_xxtea->XXTEAEncode(outBuffer, inBuffer, inSize, pKey);
	return outBuffer;
}