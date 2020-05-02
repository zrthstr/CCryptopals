/*
 *
 * Detect single-character XOR
 * One of the 60-character strings in the file "4.txt" has been encrypted by single-character XOR.
 *
 * Find it.
 *
 *
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "crplib.c"

int main(){
	FILE * fp;
	char FILE_NAME[] = "4.txt";

	fp = fopen(FILE_NAME, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	char * line = NULL;
	size_t len = 0;
	ssize_t line_len;
	int rate = 0;
	int max = 0;

	char *out = malloc(100);
	char *in = malloc(1000);
	int line_counter = 0;

	while ((line_len = getline(&line, &len, fp)) != -1) {
		//line[line_len] = '\0';
		//printf("line: %s\n",line);
		int ret = hstrtob(line_len-1,line,in);
		if ( ret == -1 ){
			printf("error in hstrtob()\n");
			return 0;
		}
		//printf("in: %s\n", in);

		for (int c=0; c<256; c++){
			sbx(line_len,c,in,out);
			rate = human_rate(line_len/2, out);
			if (rate > max){
				max = rate;
				//best = &out;
				printf("[%03d:%03d]->[%06d]",line_counter, c, rate);
				my_pprint3(line_len/2,"",out);
				}
			//printf("[%03d:%03d]->[%06d]",line_counter, c, rate);
			//my_pprint3(line_len/2,"",out);
//		}

		}
	line_counter ++;
	//return 0;
	}
	//printf("MAX:%d:%s",max, best);

	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
