#include "stdafx.h"
#include "dataFormat.h"


char* header::getSingleInfoBuffer(int index)
{
	char buffer[FILEINFOSIZE] = {0};
	char chOffset[SIZE] = {0};
	char chSize[SIZE] = {0};
	__int64 offset = m_vecFileInfo[index]->offset;
	__int64 size = m_vecFileInfo[index]->size;
	itoa(offset, chOffset, 10);
	itoa(size, chSize, 10);
	copyTo(m_vecFileInfo[index]->filename, buffer, 0);
	copyTo(chOffset, buffer, FILENAMESIZE);
	copyTo(chSize, buffer, FILENAMESIZE + SIZE);
	return buffer;
}

char* header::format()
{
	char* buffer;
	char chNum[SIZE] = {0};
	m_headerSize = SIZE + FILEINFOSIZE* m_fileNum;
	int index = SIZE;
	m_size = 0;
	buffer = new char[m_headerSize];
	for (int i = 0; i < m_headerSize; i++)
		buffer[i] = '\0';
	itoa(m_fileNum, chNum, 10);
	copyTo(chNum, buffer, 0);
	for (int i = 0; i < m_fileNum; i++)
	{
		char* ch = getSingleInfoBuffer(i);
		strcat(buffer + index, ch);
		strcat(buffer + index + FILENAMESIZE, ch + FILENAMESIZE);
		strcat(buffer + index + FILENAMESIZE + SIZE, ch + FILENAMESIZE + SIZE);
		index += FILEINFOSIZE;
		m_size += getFileInfoSize(i);
	}
	return buffer;
}

void header::copyTo(const char* srcStr, char* disStr, int index)
{
	strcat(disStr + index, srcStr);
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
	__int64 fileNum = m_pHeader->getFileNum();
	for (int i = 0; i < fileNum; i++)
	{
		__int64 intSize = m_pHeader->getFileInfoSize(i);
		__int64 outSize = 0;
		m_vecEncodeBuff.push_back(m_pFile->xxTeaFile(m_vecFileBuff[i], intSize, outSize, m_pKey));
		m_pHeader->setFileInfoSize(i, outSize);
		if (i == 0)
		{
			m_pHeader->setFileInfoOffset(i, SIZE + FILEINFOSIZE * fileNum);
		}
		else
		{
			m_pHeader->setFileInfoOffset(i, m_pHeader->getFileInfoOffset(i));
		}
	}
}

void dataFormat::format()
{
	char* headBuff = m_pHeader->format();
	__int64 headerSize = m_pHeader->getHeaderSize();
	__int64 size = m_pHeader->getSize() + 1;
	__int64 fileNum = m_pHeader->getFileNum();
	m_pFile->saveFile(headBuff, headerSize);
	for (int i = 0; i < fileNum; i++)
	{
		__int64 fileSize = m_pHeader->getFileInfoSize(i);
		m_pFile->saveFileAtTheEnd(m_vecEncodeBuff[i], fileSize);
	}
}

void dataFormat::display()
{
	m_pHeader->display();
}
