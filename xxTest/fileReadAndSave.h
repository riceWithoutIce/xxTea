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

	int* getKey()
	{
		return m_pKey;
	}
	void setKey(int* pKey)
	{
		m_pKey = pKey;
	}

#pragma endregion

	void readFile();
	char* readFile(const char* fileName, __int64& size);
	void saveFile(bool isEncode);
	char* xxTeaFile(char* buffer, const __int64 size, __int64& outSize, XXTEA_TYPE* pKey);

private:
	XXTEA* m_xxtea;
	char* m_inFileName;
	char* m_outFileName;
	char* m_inBuffer;
	char* m_outBuffer;
	size_t m_inSize;
	size_t m_outSize;
	XXTEA_TYPE* m_pKey;
};