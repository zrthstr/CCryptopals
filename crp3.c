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

int main(){
	char * hexin = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	printf("hexin= %si\n", hexin);
	//size_t size_hexin =sizeof(hexin[0]) / sizeof(char);
	size_t size_hexin = 68 ;
	size_t size_str = size_hexin / 2;
	char *in = malloc(size_str);
	char *out = malloc(size_str);
	hstrtob(size_hexin,hexin,in);

	int space = 256;
	int c = 0;
	int rate = 0;
	int top = 0;
	char top_key = 0;

	for (;c<=space;c++){
		sbx(size_str,c,in,out);
		rate = human_rate(size_str, out);
		if (rate > top){
			top = rate;
			top_key = c;}
		my_pprint3(size_str,"[try]",out);
	}
	printf("Top rate:      %d\n",top);
	printf("Top key:       %d\n", top_key);
	sbx(size_str, top_key, in, out);
	printf("Top plaintext: %s\n", out);
}
