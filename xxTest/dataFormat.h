#pragma once
#include <vector>
#include "fileReadAndSave.h"

//length 144
typedef struct 
{
	char filename[128];
	__int64 offset;
	__int64 size;
}fileinfo;

class header
{
public:
#pragma region get set

	int getFileNum()
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

#pragma endregion

	char* getSingleInfoBuffer(int index);
	char* format();
	void display();

private:
	__int64 m_fileNum;
	std::vector <fileinfo*> m_vecFileInfo;
};

class dataFormat
{
public:
	dataFormat();
	~dataFormat();

public:
	void initFile(int num, char* path);
	void readAllFile();
	void setFileSizeAndOffset();
	void format();
	void display();
private:
	header* m_pHeader;
	std::vector <char*> m_vecFileBuff;

};