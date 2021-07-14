
#include"FileRead.h"

int main(int argc, char * argv[])
{

	if( argc < 2 )
	{
		printf("usage : ./add-nbo file1 file2 ...\n");
		exit(0);
	}

	uint32_t* arr = (uint32_t*)malloc(sizeof(uint32_t) * argc-1);
        uint32_t hex = 0;

	//printf("hex : %08x\n", hex);	
	//printf("argc : %d\n", argc);


	for(int i = 1; i < argc; i++)
	{
		uint32_t temp = FileRead(argv[i]);
		arr[i-1] = temp;
		hex += temp;
		
		//printf("hex : %08x\n", hex);
	}
	
	//1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)
	
	for(int i = 1; i < argc; i++)
	{
		printf("%d(%#04x)", arr[i-1], arr[i-1]);
		if( i == argc-1 )
			break;
			
		printf(" + ");
	}
	printf(" = %d(%#04x)\n", hex, hex);
	free(arr);	
	return 0;
}
	
	
	
	

