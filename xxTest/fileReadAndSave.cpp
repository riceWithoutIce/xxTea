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
	delete[] m_inBuffer;
	m_inBuffer = nullptr;
	delete[] m_outBuffer;
	m_outBuffer = nullptr;
}

void fileReadAndSave::readFile()
{
	if (!m_inFileName)
	{
		printf("no in file name");
		return;
	}
	ifstream fin(m_inFileName, ios::in | ios::binary | ios::ate);
	if (!fin)
	{
		printf("File open error!\n");
		return;
	}
	m_inSize = fin.tellg();
	fin.seekg(0, ios::beg);
	m_inBuffer = new char[m_inSize + 1];
	fin.read(m_inBuffer, m_inSize);
	m_inBuffer[m_inSize + 1] = '\0';
	printf(m_inBuffer);
	fin.close();
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

void fileReadAndSave::saveFile(bool isEncode)
{
	if (!m_outFileName)
	{
		printf("no out file name");
		return;
	}
	if (!m_pKey)
	{
		printf("no key");
		return;
	}
	ofstream fout(m_outFileName, ios::binary);
	m_outSize = m_xxtea->XXTEAGetBufferLength(m_inSize, isEncode);
	m_outBuffer = new char[m_outSize + 1];
	if (fout.is_open())
	{
		if (isEncode)
			m_xxtea->XXTEAEncode(m_outBuffer, m_inBuffer, m_inSize, m_pKey);
		else
			m_xxtea->XXTEADecode(m_outBuffer, m_inBuffer, m_inSize, m_pKey);
	}
	m_outBuffer[m_outSize + 1] = '\0';
	fout.write(m_outBuffer, m_outSize);
	fout.close();
}

char* fileReadAndSave::xxTeaFile(char* inBuffer, const __int64 inSize, __int64& outSize, XXTEA_TYPE* pKey)
{
	outSize = m_xxtea->XXTEAGetBufferLength(inSize, true);
	char* outBuffer = new char[outSize];
	m_xxtea->XXTEAEncode(outBuffer, inBuffer, inSize, pKey);
	return outBuffer;
}