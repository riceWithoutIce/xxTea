#pragma once
#include <vector>
#include "fileReadAndSave.h"

struct  fileinfo
{
	char filename[128];
	__int64 offset;
	__int64 size;
};

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

	void pushVecFileInfo(struct fileinfo* pInfo)
	{
		m_vecFileInfo.push_back(pInfo);
	}

#pragma endregion

	char* getSingleInfoBuffer(int index);
	char* format();

private:
	__int32 m_fileNum;
	std::vector <struct fileinfo*> m_vecFileInfo;
};

class dataFormat
{
public:
	dataFormat();
	~dataFormat();

public:
	void initAllFile();
	void setFileSizeAndOffset();
	char* format();
private:
	header* m_pHeader;
	std::vector <char*> m_vecFile;

};