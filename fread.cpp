/**
 * ftell example : getting size of a file
 */
#include <stdio.h>

int main()
{
	FILE* pFile;
	long size;
	
	// fopen can tell the encode format, ansi, unicode, or utf8
	pFile = fopen("1.txt", "rb");
	if (pFile == nullptr)
		perror ("Error opening file");
	else
	{
		fseek(pFile, 0, SEEK_END);	// not-portable
		size = ftell(pFile);
		fclose(pFile);
		printf("Size of 1.txt is : %d bytes.\n", size);
	}
	
	return 0;
}