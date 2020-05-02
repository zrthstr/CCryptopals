#include <stdio.h>
#include <ctype.h>


int sbx(int len, char key, char * a, char * out){
	int i = 0;
	for (;i<len;i++)
		out[i] = a[i] ^ key;
	return i;
}


/// TODO: rewirte as case with range
int hchar_val(char i){
	if (i >= '0' && i <= '9'){return i - '0';}
	else if (i >= 'a' && i <= 'f'){return i - 'a' + 10;}
	else {printf("error in hchar_val\n"); return -1;}
}

int hstrtob (int n, char *hstr, char *to){
	int i = 0;
	int c = 0;
	for (;i<n;i++){
		char this;
		this = hchar_val( hstr[i]) * 16 ;
		if (this == -1){
			printf("error in hchar_val\n");
			return -1;
			}
		++i;
		int hchar = hchar_val(hstr[i]);
		if (hchar == -1){
			printf("error in hchar_val\n");
			return -1;
		}
		to[c] = this + hchar;
		++c;
	}
	return c;
}



int human_rate_c(char c){
	//printf("looking at %c",c);
	//printf("looking at %c, %d",c,c);
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
		case 'd':
			return 425;
		case 'l':
			return 492;
		case 'u':
			return 275;
		case 'w':
			return 256;
		case 'm':
			return 240;
		case 'f':
			return 222;
		case 'c':
			return 220;
		case 'g':
			return 201;
		case 'y':
			return 199;
		case 'p':
			return 192;
		case 'b':
			return 149;
		case 'k':
			return 129;
		case 'v':
			return 97;
		//case   0 ...  30:
		//	return -1000;
		case -127 ... 30:
			return -300;
		default :
			return 0;
	}
}

/*
j	0.153%	
x	0.150%	
q	0.095%	
z	0.077%	
*/

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
