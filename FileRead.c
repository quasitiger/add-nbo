#include "FileRead.h"

uint32_t FileRead(char * _path)
{

	//printf("path : %s\n", _path);
	FILE * file;
	file = fopen(_path, "rb");
	uint32_t hex;
	
	if ( file == NULL)
	{
		fputs("File error", stderr);
    		exit(1);
	}
	
	
	fread(&hex, sizeof(uint32_t), 1, file);
	hex = ntohl(hex);
	//printf("FileRead : %08x\n", hex);
	
	fclose(file);
	
	return hex;
}

