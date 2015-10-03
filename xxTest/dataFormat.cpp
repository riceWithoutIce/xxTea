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
	int size = 4 + (128 + 8 + 8) * m_fileNum;
	buffer = new char[size];
	for (int i = 0; i < m_fileNum; i++)
	{
		strcat(buffer, getSingleInfoBuffer(i));
	}
	return buffer;
}

dataFormat::dataFormat()
{
}


dataFormat::~dataFormat()
{
}

void dataFormat::initAllFile()
{

}

void dataFormat::setFileSizeAndOffset()
{

}

char* dataFormat::format()
{

}
