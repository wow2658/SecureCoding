#include <stdio.h>

int main(void)
{
	int nData = 300; // (0x12c)
	char szBuffer[12] = { 0 };

	gets(szBuffer);						 // e2 fd 8b 59 1e 10 31 00 f4 fc 8f 00 "2c" 01 00 00 (0000012c)
										 // 00 00 00 00 00 00 00 00 00 00 00 00 "2c" 01 00 00
										 // 48 6f 6e 67 20 67 69 6c 64 6f 6e 67 "00" 01 00 00 (00000100)
	printf("%s, %d\n", szBuffer, nData); // Hong gildong, 256 (0x100)
	return 0;
}