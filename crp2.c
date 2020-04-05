/*
 * Fixed XOR
 * Write a function that takes two equal-length buffers and produces
 * their XOR combination.
 *
 * If your function works properly, then when you feed it the string:
 *
 * 1c0111001f010100061a024b53535009181c
 * ... after hex decoding, and when XOR'd against:
 * 
 * 686974207468652062756c6c277320657965
 * ... should produce:
 *
 * 746865206b696420646f6e277420706c6179
 *
 */

#include <stdio.h>

//int my_strlen(char * str){
//	int i = 0;
//	for (;str[i];i++){}
//	return i;
//}

int bxor(int len, char *a, char *b, char *c){
	int i = 0;
	for (;i<len;i++){
		c[i] = a[i] ^ b[i];
	}
	return i;
}

int hchar_val(char i){
	if (i >= '0' && i <= '9'){return i - '0';}
	else if (i >= 'a' && i <= 'f'){return i - 'a' + 10;}
	else {printf("error in hchar_val"); return -1;}
}

int hstrtob (int n, char *hstr, char *to){
	int i = 0;
	int c = 0;
	//char this = 0;
	for (;i<n;i++){
		char this = hchar_val( hstr[i]) * 16 ;
		++i;
		to[c] = this + hchar_val(hstr[i]);
		++c;
	}
	return c;
}

int my_pprint(int len, char *head, char *str){
	int i;
	printf("%s",head);
	for (i = 0; i < len ; i++)
	{
		if (i > 0) printf(":");
			printf("%02x", str[i]);
	}
	printf("\n");
	return i;
}

int main(){
	char a_str[] = "1c0111001f010100061a024b53535009181c";
	char b_str[] = "686974207468652062756c6c277320657965";
	size_t str_len = sizeof(a_str) / sizeof(char) -1; /// aee hem
	size_t x_size = str_len/2;
	//printf("str_len:%d\n",str_len);
	char a[x_size];
	char b[x_size];
	char c[x_size];

	printf("a_str:%s \n",a_str);
	hstrtob(str_len, a_str, a);

	printf("b_str:%s \n",b_str);
	hstrtob(str_len, b_str, b);

	bxor(x_size,a,b,c);
	
	my_pprint(x_size,"a:",a);
	my_pprint(x_size,"b:",b);
	my_pprint(x_size,"c:",c);

	return 0;
}
