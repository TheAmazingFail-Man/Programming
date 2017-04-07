#include <stdio.h>
#include <stdlib.h>

int encode_file(const char *in_file_name, const char *out_file_name)
{
	char x[5];
	FILE *begin = fopen(in_file_name, "r");
	FILE *end = fopen(out_file_name, "w");
	fgets(x, 5, begin);
	puts(x);
	fclose(begin);
	fclose(end);
	
	return 0;
}


int decode_file(const char *in_file_name, const char *out_file_name)
{
	FILE *begin = fopen(in_file_name, "r");
	FILE *end = fopen(out_file_name, "w");
	
	
	fclose(begin);
	fclose(end);
	
	return 0;
}