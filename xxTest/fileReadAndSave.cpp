#include "stdafx.h"
#include "fileReadAndSave.h"
#include <fstream>
#include <iostream>

using namespace std;


fileReadAndSave::fileReadAndSave(void)
{
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
	ifstream fin(m_inFileName, ios::in | ios::binary | ios::ate);
	if (!fin)
	{
		cout << "File open error!\n";
		return;
	}
	m_inSize = fin.tellg();
	fin.seekg(0, ios::beg);
	m_inBuffer = new char[m_inSize];
	fin.read(m_inBuffer, m_inSize);
	fin.close();
}

void fileReadAndSave::saveFile(bool isEncode)
{
	ofstream fout(m_outFileName, ios::binary);
	m_outSize = XXTEA::XXTEAGetBufferLength(m_inSize, isEncode);
	m_outBuffer = new char[m_outSize];
	if (fout.is_open())
	{
		if (isEncode)
			XXTEA::XXTEAEncode(m_outBuffer, m_inBuffer, m_inSize, m_pKey);
		else
			XXTEA::XXTEADecode(m_outBuffer, m_inBuffer, m_inSize, m_pKey);
	}

	fout.write(m_outBuffer, m_outSize);
	fout.close();
}