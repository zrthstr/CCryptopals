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
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
				line[read]='\0';
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
