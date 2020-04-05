#include <stdio.h>

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
