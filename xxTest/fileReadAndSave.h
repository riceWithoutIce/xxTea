#pragma once
#include "xxtea.h"

class fileReadAndSave
{
public:
	fileReadAndSave(void);
	~fileReadAndSave(void);

public:

	__int64 getxxTeaBufferSize(__int64 size, bool isEncode);
	char* readFile(const char* fileName, __int64& size);
	void saveFile(char* buffer, __int64 size);
	void saveFileAtTheEnd(char* buffer, __int64 size);
	char* xxTeaFile(char* buffer, const __int64 size, __int64& outSize, XXTEA_TYPE* pKey);

private:
	XXTEA* m_xxtea;
};