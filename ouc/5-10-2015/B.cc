#include <cstdio>

int main(int argc, char const *argv[])
{
	int p = 0;
	char s[100];
	gets(s);
	if(*s=='h'){
		printf("http://");
		p = 4;
	} else {
		printf("ftp://");
		p = 3;
	}
	do {
		putchar(s[p++]);
	} while(!(s[p]=='r'&&s[p+1]=='u'));
	printf(".%c%c", s[p], s[p+1]);
	if(s[p+=2]!='\0') {
		printf("/%s", s+p);
	}
	return 0;
}