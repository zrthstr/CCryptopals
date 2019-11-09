
/*
Convert hex to base64

The string:
49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d

Should produce:
SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t

*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t main(void) {
	const uint8_t *inp = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	const uint8_t *out_test = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

	if (strcmp(inp, out_test))
	{
		printf("Okey..");
	} else {
		printf("Fail..");
	}

	return EXIT_SUCCESS;
}

