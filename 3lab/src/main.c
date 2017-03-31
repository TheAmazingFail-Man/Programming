#include <stdio.h>
#include <inttypes.h>
/*#include <conio.h>*/
#include <stdlib.h>
/*#include "command.h"
#include "coder.h"*/

int main(int argc, char *argv[])
{	
	uint32_t numbers;
	
	FILE *begin = fopen(argv[1], "r");
	FILE *end = fopen(argv[2], "w");
	fscanf(begin, "%x\n", &numbers);
	fprintf(end, "%x", numbers);
	fclose(begin);
	fclose(end);
	
	return 0;
}