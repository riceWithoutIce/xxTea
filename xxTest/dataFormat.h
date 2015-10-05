#pragma once
#include <vector>
#include "fileReadAndSave.h"

#define FILEINFOSIZE 144
#define FILENAMESIZE 128
#define SIZE 8

//length 144
typedef struct 
{
	char filename[FILENAMESIZE];
	__int64 offset;
	__int64 size;
}fileinfo;

class header
{
public:
#pragma region get set

	__int64 getFileNum()
	{
		return m_fileNum;
	}

	void setFileNum(int num)
	{
		m_fileNum = num;
	}

	void pushVecFileInfo(fileinfo* pInfo)
	{
		m_vecFileInfo.push_back(pInfo);
	}

	__int64 getFileInfoOffset(int index)
	{
		return m_vecFileInfo[index - 1]->offset + m_vecFileInfo[index - 1]->size;
	}
	
	void setFileInfoOffset(int index, __int64 offset)
	{
		m_vecFileInfo[index]->offset = offset;
	}

	__int64 getFileInfoSize(int index)
	{
		return m_vecFileInfo[index]->size;
	}

	void setFileInfoSize(int index, __int64 size)
	{
		m_vecFileInfo[index]->size = size;
	}

	__int64 getHeaderSize()
	{
		return m_headerSize;
	}

	__int64 getSize()
	{
		return m_size;
	}

#pragma endregion

	char* getSingleInfoBuffer(int index);
	char* format();
	void copyTo(const char* srcStr, char* disStr, int index);
	void display();

private:
	__int64 m_fileNum;
	__int64 m_headerSize;
	__int64 m_size;
	std::vector <fileinfo*> m_vecFileInfo;
};

class dataFormat
{
public:
	dataFormat();
	~dataFormat();

public:
	int* getKey()
	{
		return m_pKey;
	}
	void setKey(int* pKey)
	{
		m_pKey = pKey;
	}

	void readFile(int num, std::vector<char*> vecPath);
	void xxTea();
	void format();
	void display();
private:
	header* m_pHeader;
	std::vector <char*> m_vecFileBuff;
	std::vector <char*> m_vecEncodeBuff;
	fileReadAndSave* m_pFile;
	char * m_buffer;
	XXTEA_TYPE* m_pKey;
};