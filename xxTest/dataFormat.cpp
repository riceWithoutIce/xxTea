#include "stdafx.h"
#include "dataFormat.h"


char* header::getSingleInfoBuffer(int index)
{
	char buffer[144];
	char chOffset[8];
	char chSize[8];
	__int64 offset = m_vecFileInfo[index]->offset;
	__int64 size = m_vecFileInfo[index]->size;
	sprintf(chOffset, "%ll", offset);
	sprintf(chSize, "%ll", size);
	strcat(buffer, m_vecFileInfo[index]->filename);
	strcat(buffer, chOffset);
	strcat(buffer, chSize);

	return buffer;
}

char* header::format()
{
	char* buffer;
	__int64 size = 8 + (128 + 8 + 8) * m_fileNum;
	buffer = new char[size];
	for (int i = 0; i < m_fileNum; i++)
	{
		strcat(buffer, getSingleInfoBuffer(i));
	}
	return buffer;
}

void header::display()
{
	std::vector <fileinfo*>::iterator iter;
	for (iter = m_vecFileInfo.begin(); iter != m_vecFileInfo.end(); iter++)
	{
		printf((*iter)->filename);
		printf(", size: %d", (*iter)->size);
		printf(", offset: %d\n", (*iter)->offset);
	}
}

dataFormat::dataFormat()
{
	m_pFile = new fileReadAndSave();
}


dataFormat::~dataFormat()
{
}

void dataFormat::readFile(int num, std::vector<char*> vecPath)
{
	m_pHeader = new header();
	m_pHeader->setFileNum(num);
	for (int i = 0; i < num; i++)
	{
		fileinfo* file = new fileinfo();
		strcpy(file->filename, vecPath[i]);
		m_vecFileBuff.push_back(m_pFile->readFile(vecPath[i], file->size));
		m_pHeader->pushVecFileInfo(file);
	}
}

void dataFormat::xxTea()
{
	int fileNum = m_pHeader->getFileNum();
	for (int i = 0; i < fileNum; i++)
	{
		__int64 intSize = m_pHeader->getSize(i);
		__int64 outSize = 0;
		m_vecEncodeBuff.push_back(m_pFile->xxTeaFile(m_vecFileBuff[i], intSize, outSize, m_pKey));
		m_pHeader->setSize(i, outSize);
		if (i == 0)
		{
			m_pHeader->setOffset(i, 8 + 144 * fileNum);
		}
		else
		{
			m_pHeader->setOffset(i, m_pHeader->getOffset(i));
		}
	}
}

void dataFormat::format()
{
	
}

void dataFormat::display()
{
	m_pHeader->display();
}
