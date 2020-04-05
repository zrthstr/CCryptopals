#include <stdio.h>
#include <ctype.h>

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


int human_rate_c(char c){
	//printf("looking at %c",c);
	switch (c){
		case ' ':
			return 1200;
		case 'e':
			return  800;
		case 'a':
			return 700;
		case 't':
			return 600;
		case 'o':
			return 500;
		case 'n':
			return 450;
		case 'm':
			return 430;
		default :
			return 100;
	}
}

int human_rate(int len, char * str){
	int score = 0;
	for (int i=0; i<len; i++)
		score = score + human_rate_c(str[i]);
	printf("[SCORING] Found:%d",score);
	return score / len;
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
				printf(".");
				break;
		}
	}
	printf("\n");
	return c;
}
