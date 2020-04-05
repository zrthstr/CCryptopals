/*
 *
 * Single-byte XOR cipher
 * The hex encoded string:
 *
 * 1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
 * ... has been XOR'd against a single character. Find the key, decrypt the message.
 *
 * You can do this by hand. But don't: write code to do it for you.
 *
 * How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include "crplib.c"

int sbx(int len, char key, char * a, char * out){
	int i = 0;
	for (;i<len;i++){
		out[i] = a[i] ^ key;
	}
	return i;
}

int main(){
	char * hexin = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	printf("hexin= %si\n", hexin);
	//size_t size_hexin =sizeof(hexin[0]) / sizeof(char);
	size_t size_hexin = 40 ; //sizeof(hexin[0]) / sizeof(char);
	char *in = malloc(size_hexin);
	char *out = malloc(size_hexin);
	printf("::xx::%ld\n",size_hexin);
	hstrtob(size_hexin,hexin,in);

	//my_pprint(size_hexin/2,"in:",in);

	int space = 128; // unsure if 128 or 256
	//int space = 256; // unsure if 128 or 256
	int c = -120;
	int rate = 0;

	for (;c<=space;c++){
		//printf("[c(%d)]\n",c);
		sbx(size_hexin,c,in,out);
		//printf("::%s",out);
		//my_pprint(size_hexin/2," [0]",out);
		//my_pprint2(size_hexin/2," [2]",out);
		rate = human_rate(size_hexin, out);
		printf("rate: %d", rate);
		my_pprint3(size_hexin," [2]",out);
	}
}
