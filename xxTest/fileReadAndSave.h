#pragma once
#include "xxtea.h"
#include <fstream>
#include <iostream>
class fileReadAndSave
{
public:
	fileReadAndSave(void);
	~fileReadAndSave(void);

public:
#pragma region get set

	long getKey()
	{
		return m_key;
	}
	void setKey(long key)
	{
		m_key = key;
		m_lpKey = &m_key;
	}

#pragma endregion

	void readFile()
	{

	}

private:
	char* m_inBuffer;
	char* m_outBuffer;
	long m_inSize;
	long m_outSize;
	long m_key;
	long* m_lpKey;
};

