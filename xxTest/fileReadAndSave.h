#pragma once
#include "xxtea.h"

class fileReadAndSave
{
public:
	fileReadAndSave(void);
	~fileReadAndSave(void);

public:
#pragma region get set
	char* getInFileName()
	{
		return m_inFileName;
	}

	void setInFileName(char* ch)
	{
		m_inFileName = new char[strlen(ch)];
		sprintf(m_inFileName, "%s", ch);
	}

	char* getOutFileName()
	{
		return m_outFileName;
	}

	void setOutFileName(char* ch)
	{
		m_outFileName = new char[strlen(ch)];
		sprintf(m_outFileName, "%s", ch);
	}

	int getKey()
	{
		return m_key;
	}
	void setKey(int key)
	{
		m_key = key;
		m_pKey = &m_key;
	}

#pragma endregion

	void readFile();
	void saveFile(bool isEncode);

private:
	char* m_inFileName;
	char* m_outFileName;
	char* m_inBuffer;
	char* m_outBuffer;
	long m_inSize;
	long m_outSize;
	int m_key;
	int* m_pKey;
};

