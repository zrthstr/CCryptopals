/*
 * Convert hex to base64
 * The string:
 *
 * 49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
 * Should produce:
 *
 * SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
 * So go ahead and make that happen. You'll need to use this code for the rest of the exercises.
 *
 * Cryptopals Rule
 * Always operate on raw bytes, never on encoded strings. Only use hex and base64 for pretty-printing.
 *
*/

#include <stdio.h>

char blookup(int i){
	char * alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyx0123456789+/";
	return alph[i];
}

void dtobase64(int i, char *to){
	if ( i < 0 && i > 64 * 64){printf("errrror in fbaseto64\n");}
	int a = i / 64;
	int b = i - a * 64;
	to[0] = blookup(a);
	to[1] = blookup(b);
}


int main(){
	char *hexin = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	printf("hexin: %s\n", hexin);

	char c = 0;
	int count = 0;
	int this = 0;
	int total = 0;

	printf("Product: ");
	for (;hexin[count];count++){
		int mod = count % 3;
		c = hexin[count];
		//printf("c:%d",c);
		//break;
		if ( c >= 'a' && c <= 'f' ){ this = c - 'a' + 10;}
		else if ( c >= '0' && c <= '9'){ this = c - '0';}
		else { printf("Errorrrrrr");}

		//printf("mod:%d this:%d total:%d",mod,this,total);
		if (mod == 0) {total = this;}
		if (mod == 1) {total = total * 16 + this;}
		if (mod == 2) {
			total = total * 16 + this;
			// print as base
		char bc[2];
		dtobase64(total, bc);
		//printf("bc:%s",bc);
		printf("%s",bc);
		}
	}
	printf("\n");

	return 0;
}
