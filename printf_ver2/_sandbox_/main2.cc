#include <stdio.h>

// %|flag: -+# 0|width: number or *|precision: .number|length: h|specifier: cdsux...

int main()
{
	//%|non|5|non|non|d
	printf("%5d\n", 12);
	printf("%6d\n", -24);
	printf("%7d\n\n", 36);
	
	//flag 0 : use 0 as a padding character
	//%|0|5|non|non|d
	printf("%05d\n", 12);
	printf("%06d\n", -24);
	printf("%07d\n\n", 36);
	
	//flag - : left alignment
	//%|-|5|non|non|d
	printf("%-5d\n", 12);
	printf("%-6d\n", -24);
	printf("%-7d\n\n", 36);
	
	//flag + : - for negative or + for positive 
	//%|+|5|non|non|d
	printf("%d\n", 12);
	printf("%+d\n", 12);
	printf("%+05d\n", 12);
	printf("%d\n", -24);
	printf("%+d\n", -24);
	printf("%+0d\n", -24);
	printf("%7d\n", -36);
	printf("%+7d\n", -36);
	printf("%+07d\n\n", -36);
	
	//flag # : o be added to octal or 0x to hexadecimal  
	//%|#|5|non|non|d	
	printf("%o\n", 0xFFFF);
	printf("%#o\n", 0xFFFF);
	printf("%x\n", 0xFFFF);
	printf("%#x\n", 0xFFFF);
	printf("%X\n", 0xFFFF);
	printf("%#X\n\n", 0xFFFF);
		
	//flag  : - for negative or space for positive
	//%| | |non|non|d
	printf("%d\n", 12);
	printf("% d\n", 12);
	printf("%d\n", -24);
	printf("% d\n", -24);
	return 0;
}
