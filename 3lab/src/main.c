#include <stdio.h>
#include <inttypes.h>
/*#include <conio.h>*/
#include <stdlib.h>
/*#include "command.h"
#include "coder.h"*/

int main(int argc, char *argv[])
{	
	int i, x = 0;
	uint32_t numbers;
	
	FILE *begin = fopen(argv[1], "r");
	FILE *end = fopen(argv[2], "w");
	for (i = 0; i < 3; i++) {
		fscanf(begin, "%x\n", &numbers);
		//fprintf(end, "%x\n", numbers);
		x++;
	}
	printf("%d", x);
	fclose(begin);
	fclose(end);
	
	return 0;
}