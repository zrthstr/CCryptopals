#include <stdio.h>
#include <ctype.h>


int sbx(int len, char key, char * a, char * out){
	int i = 0;
	for (;i<len;i++)
		out[i] = a[i] ^ key;
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
		char this;
		this = hchar_val( hstr[i]) * 16 ;
		++i;
		to[c] = this + hchar_val(hstr[i]);
		++c;
	}
	return c;
}


/*
h	6.094%	
r	5.987%	
d	4.253%	
l	4.025%	
u	2.758%	
w	2.560%	
m	2.406%	
f	2.228%	
c	2.202%	
g	2.015%	
y	1.994%	
p	1.929%	
b	1.492%	
k	1.292%	
v	0.978%	
j	0.153%	
x	0.150%	
q	0.095%	
z	0.077%	
*/


int human_rate_c(char c){
	//printf("looking at %c",c);
	switch (c){
		case ' ':
			return 1300;
		case 'e':
			return 1270;
		case 't':
			return  935;
		case 'a':
			return 810;
		case 'o':
			return 750;
		case 'i':
			return 690;
		case 'n':
			return 670;
		case 's':
			return 630;
		case 'h':
			return 609;
		case 'r':
			return 598;
		default :
			return 1;
	}
}

int human_rate(int len, char * str){
	int score = 0;
	for (int i=0; i<len; i++)
		score = score + human_rate_c(str[i]);
	//printf("[scoring] %d",score);
	return score;
	//return score / len;
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

int my_pprint2(int len, char *head, char *str){
	printf("%s:",head);
	int c; c = 0;
	for (; c<len; c++){
		char this; this = str[c];
		if(isprint(this))
			printf("%c",this);
		else
			switch (this){
			case '\n':
				printf("\\n");
				break;
			default:
				printf("\\x%02x", this);
				break;
		}
	}
	printf("\n");
	return c;
}

int my_pprint3(int len, char *head, char *str){
	printf("%s:",head);
	int c; c = 0;
	for (; c<len; c++){
		char this; this = str[c];
		if(isprint(this))
			printf("%c",this);
		else
			switch (this){
			case '\n':
				printf("\\n");
				break;
			default:
				printf("?");
				break;
		}
	}
	printf("\n");
	return c;
}
