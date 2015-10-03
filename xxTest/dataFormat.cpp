#include "stdafx.h"
#include "dataFormat.h"


char* header::getSingleInfoBuffer(int index)
{
	char buffer[144];
	char chOffset[8];
	char chSize[8];
	int offset = m_vecFileInfo[index]->offset;
	int size = m_vecFileInfo[index]->size;
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
	int size = 8 + (128 + 8 + 8) * m_fileNum;
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
	}
}

dataFormat::dataFormat()
{
}


dataFormat::~dataFormat()
{
}

void dataFormat::initFile(int num, char* path)
{
	m_pHeader = new header();
	m_pHeader->setFileNum(num);
	for (int i = 0; i < num; i++)
	{
		fileinfo* file = new fileinfo();
		strcpy(file->filename, path);
		m_pHeader->pushVecFileInfo(file);
	}
}

void dataFormat::readAllFile()
{

}

void dataFormat::setFileSizeAndOffset()
{

}

void dataFormat::format()
{

}

void dataFormat::display()
{
	m_pHeader->display();
}
